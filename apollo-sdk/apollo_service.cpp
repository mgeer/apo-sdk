#include <cstdlib>
#include <boost/algorithm/string.hpp>
#include <boost/thread.hpp>
#include "apollo_service.h"
#include "apollo_log.h"

namespace apollo {

static void debug(const LogWriter* logger, const std::string& log) {
    if (logger != NULL && logger->isDebugEnabled()) {
        logger->debug(log);
    }
}

int ServiceFactory::setServers(std::vector<std::string> serverList) {
    if (serverList.size() == 0) {
        return -1;
    }
    std::string serverText = serverList[0];
    std::vector<std::string> ipPort;
    boost::split(ipPort, serverText, boost::is_any_of(":"));
    servers.push_back(Server(ipPort[0], atoi(ipPort[1].c_str())));
    return 0;
}


ServiceStub* ServiceFactory::create() {
    if (servers.size() == 0) {
        return NULL;
    }
    Server& server = servers[0];
    boost::shared_ptr<apt::transport::TSocket> socket(
            new apt::transport::TSocket(server.getAddress(), server.getPort()));
    socket->setConnTimeout(connTimeout);
    socket->setRecvTimeout(readTimeout);

    boost::shared_ptr<apt::transport::TTransport> transport(
            new apt::transport::TFramedTransport(socket));

    boost::shared_ptr<apt::protocol::TProtocol> protocol(
            new apt::protocol::TBinaryProtocol(transport));

    try {
        transport->open();
    } catch (apt::transport::TTransportException e) {
        if (logger != NULL && logger->isDebugEnabled()) {
            logger->debug(e.what());
        }
        return NULL;
    }

    return new ServiceStub(transport, boost::shared_ptr<api::ApolloServiceClient>(
            new api::ApolloServiceClient(protocol)));
}

#ifdef __linux__
#define STUB_HOLDER boost::thread_specific_ptr<ServiceStub>
#else
#define STUB_HOLDER std::unique_ptr<ServiceStub>
#endif

static STUB_HOLDER t_stub;
ServiceStub* ThreadLocalServiceProvider::borrowObject() {
    if (!t_stub.get()) {
        debug(logger, "stub is empty, going to create it.");
        ServiceStub* stub = factory->create();
        if (stub != NULL) {
            t_stub.reset(factory->create());
        } else {
            return NULL;
        }
    }
    return t_stub.get();
}

void ThreadLocalServiceProvider::returnObject(ServiceStub* obj){
    debug(logger, "Return stub");
    //do nothing.
}

void ThreadLocalServiceProvider::invalidateObject(ServiceStub* obj) {
    debug(logger, "Invalidate stub...");
    if (obj == NULL) {
        debug(logger, "Failed to invalidate NULL stub");
        return;
    }
    if (t_stub.get() != obj) {
        debug(logger, "unkonw stub, failed to invalidate.");
        return;
    }
    std::unique_ptr<ServiceStub> guard(t_stub.release());
    guard->getTransport()->close();
}

}
