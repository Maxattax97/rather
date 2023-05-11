#include <string>
#include <grpcpp/grpcpp.h>


#ifdef BAZEL_BUILD
#include "main/Rather.grpc.pb.h"
#else
#include "main/Rather.grpc.pb.h"
#endif

using grpc::ServerContext;
using Rather::Greeter;
using grpc::Status;
using HelloProto::HelloRequest;
using HelloProto::HelloReply;

class GreeterImpl final : Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) override;
};
