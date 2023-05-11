#include "hello.h"


using grpc::ServerContext;
using grpc::Status;
using HelloProto::HelloRequest;
using HelloProto::HelloReply;
using HelloProto::Greeter;

Status GreeterImpl::SayHello(ServerContext* context,
  const HelloRequest* request, HelloReply* reply) {
  std::string helloPreffix("Hello ");
  reply->set_message(helloPreffix + request->name());
  return Status::OK;
}
