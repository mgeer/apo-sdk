//
// Created by jiangqingsong on 15/11/24.
//
#include "apollo_main.h"

using namespace ::apollo::rpc::api;

namespace apollo {

static void debug(const LogWriter* logger, const std::string& log) {
    if (logger != NULL && logger->isDebugEnabled()) {
        logger->debug(log);
    }
}

int Apollo::init(const std::string& service, int connTimeout, int socketTimeout, const LogWriter* logger) {
    std::unique_ptr<ServiceFactory> factory(new ServiceFactory(connTimeout, socketTimeout, logger));
    //todo: one or multiple server?
    std::vector<std::string> serverList;
    serverList.push_back(service);
    if (factory->setServers(serverList) != 0) {
        debug(logger, "failed to set servers.");
        return -1;
    }
    provider.reset(new ThreadLocalServiceProvider(factory, logger));
    Apollo::logger = logger;
    return 0;
}

void Apollo::close() {

}

void Apollo::featureToggle(const std::string& name, const ApolloUser& user, FeatureToggle::UPTR& toggle) {
    toggle.reset(new DefaultFeatureToggle());

    FeatureResponse response;
    FeatureRequest request;
    request.__set_ns("service");
    std::vector<std::string> names;
    names.push_back(name);
    request.__set_names(names);
    request.__set_logId(0);
    UserToIdentity identity;
    identity.__set_key(user.getKey());
    identity.__set_properties(user.getProperties());
    request.__set_user(identity);
    ServiceStub* stub = provider->borrowObject();
    if (NULL == stub) {
        return;
    }
    using ::apache::thrift::transport::TTransportException;
    try {
        stub->getClient()->feature(response, request);
        provider->returnObject(stub);
    } catch (TTransportException exception) {
        debug(logger, "Got exception when get feature toggle:");
        debug(logger, exception.what());
        provider->invalidateObject(stub);
        stub = NULL;
        return;
    }

    if (response.code != 0) {
        return;
    }
    FeatureResult& result = response.results[0];
    std::unique_ptr<Experiment> experiment(new Experiment(result.experiment.testKey, result.experiment.arguments));
    toggle.reset(new FeatureToggle(result.allow, experiment, Apollo::logger, user));
}

std::unique_ptr<ServiceProvider> Apollo::provider;
const LogWriter* Apollo::logger;
}