//
// Created by jiangqingsong on 15/11/24.
//

#ifndef APOLLO_SDK_CPP_APOLLO_TOGGLE_H
#define APOLLO_SDK_CPP_APOLLO_TOGGLE_H

#include <map>
#include <string>
#include <memory>

namespace apollo {

class Experiment;
class LogWriter;
class ApolloUser;

class FeatureToggle {
protected:
    bool allow;
    std::unique_ptr<Experiment> experiment;
    const LogWriter* logger;
    std::string log;
public:
    typedef std::unique_ptr<FeatureToggle> UPTR;

    FeatureToggle() : allow(false) {
        experiment.reset(NULL);
    }

    FeatureToggle(bool allow, std::unique_ptr<Experiment>& experiment, const LogWriter* logger, const ApolloUser& user);
    virtual bool isAllow();
    virtual const std::unique_ptr<Experiment>& getExperiment() const {
        return experiment;
    }
};

class Experiment {
private:
    std::string testKey;
    std::map<std::string, std::string> map;
    std::string defaultString;

public:
    Experiment(const std::string testKey, const std::map<std::string, std::string> map)
            : testKey(testKey), map(map), defaultString("") {
    }

public:
    virtual const std::string& getTestKey() const {
        return testKey;
    }

    virtual const std::string& getParameter(const std::string& key) const {
        if (map.size() == 0) {
            return defaultString;
        }
        auto it = map.find(key);
        if (it == map.end()) {
            return defaultString;
        }
        return it->second;
    };
};

class DefaultExperiment : public Experiment {
public:
    DefaultExperiment() : Experiment("NULL", std::map<std::string, std::string>()) {

    }
};

class DefaultFeatureToggle : public FeatureToggle {
public:
    DefaultFeatureToggle() {
        this->experiment.reset(new DefaultExperiment());
    }
};

class ApolloUser {
private:
    const std::string key;
    std::map<std::string, std::string> properties;

public:
    ApolloUser(const std::string id) : key(id) {

    }

    ApolloUser& put(const std::string key, const std::string value) {
        properties[key] = value;
        return *this;
    }

    const std::string& getKey() const {
        return key;
    }

    const std::map<std::string, std::string>& getProperties() const {
        return properties;
    };
};

}

#endif //APOLLO_SDK_CPP_APOLLO_TOGGLE_H
