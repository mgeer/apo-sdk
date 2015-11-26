//
// Created by jiangqingsong on 15/11/25.
//

#ifndef APOLLO_SDK_CPP_APOLLO_LOG_H
#define APOLLO_SDK_CPP_APOLLO_LOG_H
#include <string>

namespace apollo {

class LogWriter {
public:
    virtual const bool isDebugEnabled() const = 0;

    virtual const bool isInfoEnabled() const = 0;

    virtual void debug(const std::string& log) const = 0;

    virtual void info(const std::string& log) const = 0;

};

}


#endif //APOLLO_SDK_CPP_APOLLO_LOG_H
