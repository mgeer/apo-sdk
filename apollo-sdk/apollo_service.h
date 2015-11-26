//
// Created by jiangqingsong on 15/11/24.
//

#ifndef APOLLO_SDK_CPP_APOLLO_SERVICE_H
#define APOLLO_SDK_CPP_APOLLO_SERVICE_H

#include <memory>
#include <vector>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include "ApolloService.h"

namespace apollo {

namespace apt = ::apache::thrift;
namespace api = ::apollo::rpc::api;

class Server;

class ServiceStub;

class ServiceFactory;

class ServiceProvider;

class LogWriter;


class Server {
private:
    std::string address;
    int port;

public:
    Server(const std::string address, int port) : address(address), port(port) {
    }

    const std::string& getAddress() const {
        return address;
    }

    const int getPort() const {
        return port;
    }
};


class ServiceStub {
private:
    boost::shared_ptr<apt::protocol::TTransport> transport;
    boost::shared_ptr<api::ApolloServiceClient> client;

public:
    ServiceStub(boost::shared_ptr<apt::protocol::TTransport> transport,
                boost::shared_ptr<api::ApolloServiceClient> client) {
        this->transport = transport;
        this->client = client;
    }

    ~ServiceStub() {
        transport->close();
    }

    const boost::shared_ptr<apt::protocol::TTransport>& getTransport() const {
        return transport;
    }

    const boost::shared_ptr<api::ApolloServiceClient>& getClient() const {
        return client;
    }

};


class ServiceProvider {
public:
    virtual ~ServiceProvider() { }

    virtual ServiceStub* borrowObject() = 0;

    virtual void returnObject(ServiceStub* stub) = 0;

    virtual void invalidateObject(ServiceStub* stub) = 0;
};


class ThreadLocalServiceProvider : public ServiceProvider {
private:
    std::unique_ptr<ServiceFactory> factory;
    const LogWriter* logger;

public:
    ThreadLocalServiceProvider(std::unique_ptr<ServiceFactory>& factory, const LogWriter* logger) {
        this->logger = logger;
        this->factory.reset(factory.release());
    }

public:
    virtual ServiceStub* borrowObject();

    virtual void returnObject(ServiceStub* stub);

    virtual void invalidateObject(ServiceStub* stub);
};


class ServiceFactory {
private:
    std::vector<Server> servers;
    int connTimeout;
    int readTimeout;
    const LogWriter* logger;
public:
    int setServers(std::vector<std::string> serverList);

    ServiceStub* create();

    ServiceFactory(int connTimeout, int readTimeout, const LogWriter* logger)
            : connTimeout(connTimeout), readTimeout(readTimeout), logger(logger){

    }
};



}

#endif //APOLLO_SDK_CPP_APOLLO_SERVICE_H
