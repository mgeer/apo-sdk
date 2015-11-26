//
// Created by jiangqingsong on 15/11/24.
//

#ifndef APOLLO_SDK_APOLLO_MAIN_H
#define APOLLO_SDK_APOLLO_MAIN_H

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include "apollo_log.h"
#include "apollo_toggle.h"
#include "apollo_types.h"
#include "apollo_service.h"


namespace apollo {

class LogWriter;
class ApolloUser;
class ServiceProvider;
class FeatureToggle;

class Apollo {
private:
    static std::unique_ptr<ServiceProvider> provider;
    static const LogWriter* logger;
public:
    static void featureToggle(const std::string& name, const ApolloUser& user, std::unique_ptr<FeatureToggle>& toggle);
    static int init(const std::string& service, int connTimeout, int socketTimeout, const LogWriter* logger);
    static void close();
};

}


#endif //APOLLO_SDK_APOLLO_MAIN_H
