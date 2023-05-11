#include "hello.h"
#include <iostream>
#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "main/HelloProto.grpc.pb.h"
#else
#include "main/HelloProto.grpc.pb.h"
#endif

using grpc::ServerBuilder;
using grpc::Server;

void runServer() {
    std::string serverAddress("0.0.0.0:13000");
    GreeterImpl service;

    ServerBuilder builder;

   builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
   std::unique_ptr<Server> server(builder.BuildAndStart());
   std::cout << "Server listening on " << serverAddress << std::endl;

   server->Wait();
}

int main() {
    // HelloProject h;
    // h.sayHi("Juan");
    runServer();
    return 0;
}
