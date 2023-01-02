// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: protos/sample/v1/sample.proto

#include "protos/sample/v1/sample.pb.h"
#include "protos/sample/v1/sample.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace sample {
namespace v1 {

static const char* SampleService_method_names[] = {
  "/sample.v1.SampleService/Sample",
};

std::unique_ptr< SampleService::Stub> SampleService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SampleService::Stub> stub(new SampleService::Stub(channel, options));
  return stub;
}

SampleService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Sample_(SampleService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status SampleService::Stub::Sample(::grpc::ClientContext* context, const ::sample::v1::SampleRequest& request, ::sample::v1::SampleResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::sample::v1::SampleRequest, ::sample::v1::SampleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Sample_, context, request, response);
}

void SampleService::Stub::async::Sample(::grpc::ClientContext* context, const ::sample::v1::SampleRequest* request, ::sample::v1::SampleResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::sample::v1::SampleRequest, ::sample::v1::SampleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Sample_, context, request, response, std::move(f));
}

void SampleService::Stub::async::Sample(::grpc::ClientContext* context, const ::sample::v1::SampleRequest* request, ::sample::v1::SampleResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Sample_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::sample::v1::SampleResponse>* SampleService::Stub::PrepareAsyncSampleRaw(::grpc::ClientContext* context, const ::sample::v1::SampleRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::sample::v1::SampleResponse, ::sample::v1::SampleRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Sample_, context, request);
}

::grpc::ClientAsyncResponseReader< ::sample::v1::SampleResponse>* SampleService::Stub::AsyncSampleRaw(::grpc::ClientContext* context, const ::sample::v1::SampleRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSampleRaw(context, request, cq);
  result->StartCall();
  return result;
}

SampleService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SampleService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SampleService::Service, ::sample::v1::SampleRequest, ::sample::v1::SampleResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SampleService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::sample::v1::SampleRequest* req,
             ::sample::v1::SampleResponse* resp) {
               return service->Sample(ctx, req, resp);
             }, this)));
}

SampleService::Service::~Service() {
}

::grpc::Status SampleService::Service::Sample(::grpc::ServerContext* context, const ::sample::v1::SampleRequest* request, ::sample::v1::SampleResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace sample
}  // namespace v1

