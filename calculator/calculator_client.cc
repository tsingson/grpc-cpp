#include <protos/calculator/v1/calculator.grpc.pb.h>
#include <grpc++/grpc++.h>
#include <memory>
#include <iostream>

using namespace grpc;
using namespace calculator::v1;

class CalculatorClient {
 public:
  CalculatorClient(std::shared_ptr<Channel> channel) : _stub{Calculator::NewStub(channel)} {}

  int64_t Add(int32_t addend_1, int32_t addend_2) {
    // Prepare request
    AddRequest request;
    request.set_addend_1(addend_1);
    request.set_addend_2(addend_2);

    // Send request
    AddResponse response;
    ClientContext context;
    Status status;
    status = _stub->Add(&context, request, &response);

    // Handle response
    if (status.ok()) {
      return response.sum();
    } else {
      throw std::runtime_error(std::to_string(status.error_code()) + ": " + status.error_message());
    }
  }

  int64_t Sub(int32_t minuend, int32_t subtrahend) {
    // Prepare request
    SubRequest request;
    request.set_minuend(minuend);
    request.set_subtrahend(subtrahend);

    // Send request
    SubResponse response;
    ClientContext context;
    Status status;
    status = _stub->Sub(&context, request, &response);

    // Handle repsonse
    if (status.ok()) {
      return response.difference();
    } else {
      throw std::runtime_error(std::to_string(status.error_code()) + ": " + status.error_message());
    }
  }

  int64_t Mul(int32_t multiplicand, int32_t multiplier) {
    // Prepare request
    MulRequest request;
    request.set_multiplicand(multiplicand);
    request.set_multiplier(multiplier);

    // Send request
    MulResponse response;
    ClientContext context;
    Status status;
    status = _stub->Mul(&context, request, &response);

    // Handle response
    if (status.ok()) {
      return response.product();
    } else {
      throw std::runtime_error(std::to_string(status.error_code()) + ": " + status.error_message());
    }
  }

  int64_t Div(int32_t dividend, int32_t divisor) {
    // Prepare request
    DivRequest request;
    request.set_dividend(dividend);
    request.set_divisor(divisor);

    // Send request
    DivResponse response;
    ClientContext context;
    Status status;
    status = _stub->Div(&context, request, &response);

    // Handle response
    if (status.ok()) {
      return response.quotient();
    } else {
      throw std::runtime_error(std::to_string(status.error_code()) + ": " + status.error_message());
    }
  }

  int64_t Mod(int32_t dividend, int32_t divisor) {
    // Prepare request
    ModRequest request;
    request.set_dividend(dividend);
    request.set_divisor(divisor);

    // Send request
    ModResponse response;
    ClientContext context;
    Status status;
    status = _stub->Mod(&context, request, &response);

    // Handle response
    if (status.ok()) {
      return response.result();
    } else {
      throw std::runtime_error(std::to_string(status.error_code()) + ": " + status.error_message());
    }
  }

 private:
  std::unique_ptr<Calculator::Stub> _stub;
};

int main(int argc, char **argv) {
  std::string server_address{"localhost:2510"};
  CalculatorClient client{grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials())};
  int32_t var_1 = 25, var_2 = 10;
  std::cout << var_1 << " + " << var_2 << " = " << client.Add(var_1, var_2) << std::endl;
  std::cout << var_1 << " - " << var_2 << " = " << client.Sub(var_1, var_2) << std::endl;
  std::cout << var_1 << " * " << var_2 << " = " << client.Mul(var_1, var_2) << std::endl;
  std::cout << var_1 << " / " << var_2 << " = " << client.Div(var_1, var_2) << std::endl;
  std::cout << var_1 << " % " << var_2 << " = " << client.Mod(var_1, var_2) << std::endl;
  return 0;
}