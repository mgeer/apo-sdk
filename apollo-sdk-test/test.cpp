#include <iostream>
#include <map>
#include "apollo_main.h"

using namespace std;
using namespace apollo;

void show(const std::string& msg) {
    cout << msg << endl;
}

class DummyLogger : public LogWriter {
public:
    virtual const bool isDebugEnabled() const {
        return true;
    }

    virtual const bool isInfoEnabled() const {
        return true;
    };

    virtual void debug(const std::string& log) const {
        cout << log << endl;
    };

    virtual void info(const std::string& log) const {
        cout << log << endl;
    };
};

DummyLogger logger;

void getToggle(std::unique_ptr<FeatureToggle>& toggle, const char* name) {
    ApolloUser user("789");
    user.put("city", "1").put("phone", "13333333");
    Apollo::featureToggle(name, user, toggle);
}

void test_OK_if_server_is_not_available() {
    show("run 'test_OK_if_server_is_not_available'");
    Apollo::init("111.111.111.111:8890", 5, 100, &logger);
    std::unique_ptr<FeatureToggle> toggle;
    getToggle(toggle, "s_name");
    if (NULL == toggle) {
        show("Error, get NULL toggle");
    }
    if (toggle->isAllow()) {
        show("Error, expect false");
    }
    const std::unique_ptr<Experiment>& experiment = toggle->getExperiment();
    if ("NULL" != experiment->getTestKey()) {
        show("Error, expect 'NULL'");
    }
    if (experiment->getParameter("any") != "") {
        show("Error, expect ''");
    }
}

void test_get_feature_toggle() {
    if (0 != Apollo::init("127.0.0.1:8890", 5, 100, &logger)) {
        show("Fail, init apollo failed!");
    }
    while (true) {
        show("run 'test_feature_toggle'");
        std::unique_ptr<FeatureToggle> toggle;
        getToggle(toggle, "t1");
        if (!toggle->isAllow()) {
            show("Fail, should be allow!");
        }
        const std::unique_ptr<Experiment>& experiment = toggle->getExperiment();
        if ("t1:1:group_1" != experiment->getTestKey()) {
            show("Error, get testkey failed.");
        }
        const std::string& size = experiment->getParameter("btn_size");
        if ("40" != size) {
            show("Error, get parameter failed.");
        }
    }
}

void test_open_connection_using_conn_timeout() {
    show("run 'test_open_connection_using_conn_timeout'");
    int connTimeout = 1;
    Apollo::init("111.111.111.111:8890", connTimeout, 100, &logger);
    for (int i = 0; i < 1000; ++i) {
        std::unique_ptr<FeatureToggle> toggle;
        getToggle(toggle, "any");
    }
}

int main() {
    test_OK_if_server_is_not_available();
    test_get_feature_toggle();
    test_open_connection_using_conn_timeout();
    return 0;
}
