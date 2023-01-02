#include "protos/sample/v1/sample.grpc.pb.h"
#include <grpc++/grpc++.h>
#include <memory>
#include <iostream>
#include "spdlog/spdlog.h"
#include <iostream>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using namespace sample::v1;

class SampleClient {
 private:
  std::shared_ptr<spdlog::logger> _logger;
 public:
  SampleClient(std::shared_ptr<Channel> channel) : _stub{SampleService::NewStub(channel)} {
    _logger = spdlog::get("console");
  }

  std::string Sample(const std::string &request_sample_field) {

    // Prepare request
    SampleRequest request;
    request.set_request_sample_field(request_sample_field);
    // log
    _logger->debug("send request");
    // Send request
    SampleResponse response;
    ClientContext context;
    Status status;
    status = _stub->Sample(&context, request, &response);
    _logger->debug("get response");
    // Handle response
    if (status.ok()) {
      _logger->debug("response ok >> ", response.response_sample_field());
      return response.response_sample_field();
    } else {
      _logger->debug("response fail >> ", status.error_code(), ":", status.error_message());
      std::cerr << status.error_code() << ": " << status.error_message() << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<SampleService::Stub> _stub;
};

int main(int argc, char **argv) {

  auto stlog = spdlog::stdout_color_mt("console");
//    auto err_logger = spdlog::stderr_color_mt("stderr");
//    auto filelogger = spdlog::rotating_logger_mt<spdlog::async_factory>("file_logger", "logs/log", 1024 * 1024 * 5, 3);
//    filelogger->enable_backtrace(20);
//    filelogger->set_level(spdlog::level::debug);
  spdlog::register_logger(stlog);

//    auto async_log = spdlog::daily_logger_mt<spdlog::async_factory>("async_file_logger", "logs/daily.txt", 2, 30);
  spdlog::info("Welcome to spdlog!");

  std::string server_address{"localhost:2510"};
  SampleClient client{grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials())};
  std::string request_sample_field{"world"};
  std::string response_sample_field = client.Sample(request_sample_field);
  std::cout << "Client received: " << response_sample_field << std::endl;
  return 0;
}
