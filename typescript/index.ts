import * as grpc from "@grpc/grpc-js";
import { rather } from "./rather";

class Rather extends rather.UnimplementedRatherService {
  GetRose(
    call: grpc.ServerUnaryCall<rather.RoseRequest, rather.RoseResponse>,
    callback: grpc.requestCallback<rather.RoseResponse>
  ): void {
    console.log(call.request.name);
    callback(null, new rather.RoseResponse({ message: call.request.name }));
  }
}

const server = new grpc.Server();

server.addService(rather.UnimplementedRatherService.definition, new Rather());

server.bindAsync(
  "0.0.0.0:50011",
  grpc.ServerCredentials.createInsecure(),
  () => {
    server.start();
    console.log("Listening to 0.0.0.0:50011 ...");
  }
);
