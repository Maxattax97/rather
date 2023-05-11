// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: rather.proto

#include "rather.pb.h"
#include "rather.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace rather {

static const char* Rather_method_names[] = {
  "/rather.Rather/GetRose",
};

std::unique_ptr< Rather::Stub> Rather::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Rather::Stub> stub(new Rather::Stub(channel, options));
  return stub;
}

Rather::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetRose_(Rather_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status Rather::Stub::GetRose(::grpc::ClientContext* context, const ::rather::RoseRequest& request, ::rather::RoseResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::rather::RoseRequest, ::rather::RoseResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetRose_, context, request, response);
}

void Rather::Stub::async::GetRose(::grpc::ClientContext* context, const ::rather::RoseRequest* request, ::rather::RoseResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::rather::RoseRequest, ::rather::RoseResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRose_, context, request, response, std::move(f));
}

void Rather::Stub::async::GetRose(::grpc::ClientContext* context, const ::rather::RoseRequest* request, ::rather::RoseResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRose_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::rather::RoseResponse>* Rather::Stub::PrepareAsyncGetRoseRaw(::grpc::ClientContext* context, const ::rather::RoseRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::rather::RoseResponse, ::rather::RoseRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetRose_, context, request);
}

::grpc::ClientAsyncResponseReader< ::rather::RoseResponse>* Rather::Stub::AsyncGetRoseRaw(::grpc::ClientContext* context, const ::rather::RoseRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRoseRaw(context, request, cq);
  result->StartCall();
  return result;
}

Rather::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Rather_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< Rather::Service, ::rather::RoseRequest, ::rather::RoseResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](Rather::Service* service,
             ::grpc::ServerContext* ctx,
             const ::rather::RoseRequest* req,
             ::rather::RoseResponse* resp) {
               return service->GetRose(ctx, req, resp);
             }, this)));
}

Rather::Service::~Service() {
}

::grpc::Status Rather::Service::GetRose(::grpc::ServerContext* context, const ::rather::RoseRequest* request, ::rather::RoseResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace rather

