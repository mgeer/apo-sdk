// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ApolloService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::apollo::rpc::api;

class ApolloServiceHandler : virtual public ApolloServiceIf {
 public:
  ApolloServiceHandler() {
    // Your initialization goes here
  }

  void feature(FeatureResponse& _return, const FeatureRequest& request) {
    // Your implementation goes here
    printf("feature\n");
  }

  void select(SelectResponse& _return, const SelectRequest& request) {
    // Your implementation goes here
    printf("select\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<ApolloServiceHandler> handler(new ApolloServiceHandler());
  shared_ptr<TProcessor> processor(new ApolloServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

