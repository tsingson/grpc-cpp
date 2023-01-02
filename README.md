# gRPC C++ with bufbuild
## Installing

### 1. install vcpkg



### 2. install gRPC

To install **gRPC**, check out [https://github.com/grpc/grpc/tree/master/src/cpp](https://github.com/grpc/grpc/tree/master/src/cpp)

or,  run the following commands:

```bash
$ export INSTALL_DIR=$HOME/go/src
$ mkdir -p $INSTALL_DIR
$ export PATH="$INSTALL_DIR/bin:$PATH"
$ git clone --recurse-submodules https://github.com/grpc/grpc
$ cd grpc
$ mkdir -p cmake/build
$ pushd cmake/build
$ cmake -DgRPC_INSTALL=ON -DgRPC_BUILD_TESTS=OFF -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR ../..
$ make -j
$ make install
```

## 3. install protobuf

check out [https://github.com/protocolbuffers/protobuf/blob/main/src/README.md](https://github.com/protocolbuffers/protobuf/blob/main/src/README.md)

### 4. install spdlog



### 5. install bufbuild cli

in macOS

```
brew install bufbuild/buf/buf
```

build from source

```
git clone https://github.com/bufbuild/buf
cd buf
go install -a -trimpath -gcflags=-trimpath=OPATH -asmflags=-trimpath=OPATH -ldflags "-w -s " ./cmd/...
```





## Working with gRPC

### How to define a service

#### Instruction
Define a service in a `.proto` file using the **Interface Definition Language (IDL)** from **Protocol Buffers**.

#### Example: [Sample service](protos/sample/v1/sample.proto)

```protobuf
syntax = "proto3";

option java_package = "sample.v1.grpc";
package sample.v1;

service SampleService {
    rpc Sample (SampleRequest) returns (SampleResponse) {}
}

message SampleRequest {
    string request_sample_field = 1;
}

message SampleResponse {
    string response_sample_field = 1;
}
```

#### Example: [Calculator service](protos/calculator/v1/calculator.proto)

#### 

### How to generate gRPC code

 ```
 buf generate
 ```



check out [buf.gen.yaml](buf.gen.yaml) for buf cli generate configuration



---

### How to write a client

#### Instruction
1. Create a channel.
2. Create a stub.
3. Make a unary RPC.
4. Check returned status and response.

#### Example: [Sample client](sample/sample_client.cc)
#### Example: [Calculator client](calculator/calculator_client.cc)

#### Note

### How to write a server

#### Instruction
1. Implement the service interface.
2. Build a server exporting the service.

#### Example: [Sample server](sample/sample_server.cc)
#### Example: [Calculator server](calculator/calculator_server.cc)

#### Note

### How to write an async client

#### Instruction

1. Create a channel.
2. Create a stub.
3. Initiate the RPC and bind it to a `CompletionQueue`.
4. Request to update the response and the call status upon completion of the RPC with a unique tag.
5. Wait for the completion queue to return the next tag.

#### Example: [Sample async client](sample/sample_async_client.cc)

#### Example: [Calculator async client](calculator/calculator_async_client.cc)

#### Note

### How to write an async server

#### Instruction

1. Build a server exporting the async service.
2. Request an RPC with a unique tag.
3. Wait for the completion queue to return the next tag.

#### Example: [Sample async server](sample/sample_async_server.cc)

#### Example: [Calculator async server](calculator/calculator_async_server.cc)

#### Note
