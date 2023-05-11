"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
const grpc = __importStar(require("@grpc/grpc-js"));
const rather_1 = require("./rather");
class Rather extends rather_1.rather.UnimplementedRatherService {
    GetRose(call, callback) {
        console.log(call.request.name);
        callback(null, new rather_1.rather.RoseResponse({ message: call.request.name }));
    }
}
const server = new grpc.Server();
server.addService(rather_1.rather.UnimplementedRatherService.definition, new Rather());
server.bindAsync("0.0.0.0:50011", grpc.ServerCredentials.createInsecure(), () => {
    console.log("Starting ...");
    server.start();
    console.log("Listening to 0.0.0.0:50011 ...");
});
