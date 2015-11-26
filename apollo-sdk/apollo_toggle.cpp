#include "apollo_log.h"
#include "apollo_toggle.h"

namespace apollo {

FeatureToggle::FeatureToggle(bool allow, std::unique_ptr<Experiment>& experiment, const LogWriter* logger,
                             const ApolloUser& user)
        : allow(allow), logger(logger), log("") {
    if (allow && logger != NULL) {
        log.append("testKey:").append(experiment->getTestKey()).append("||")
                .append("allow:").append("true").append("||")
                .append("user:").append(user.getKey()).append("||");
        for (std::map<std::string, std::string>::const_iterator it = user.getProperties().begin();
             it != user.getProperties().end(); ++it)
            log.append(it->first).append(":").append(it->second).append("||");
    }
    this->experiment.reset(experiment.release());
}

bool FeatureToggle::isAllow() {
    if (allow && logger != NULL && logger->isInfoEnabled()) {
        logger->info(log);
    }
    return allow;
}

}