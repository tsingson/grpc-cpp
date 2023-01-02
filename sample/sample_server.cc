#include "protos/sample/v1/sample.grpc.pb.h"
#include <grpc++/grpc++.h>
#include <memory>
#include <iostream>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using namespace sample::v1;

class SampleServiceImpl final : public SampleService::Service {
  Status Sample(ServerContext *context, const SampleRequest *request, SampleResponse *response) override {
    response->set_response_sample_field("Hello " + request->request_sample_field());
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address{"localhost:2510"};
  SampleServiceImpl service;

  // Build server
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server{builder.BuildAndStart()};

  // Run server
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char **argv) {
  RunServer();
  return 0;
}