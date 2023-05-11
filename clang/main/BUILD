# load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library", "cpp_proto_library")


cc_library(
    name = "hello_lib",
    srcs = ["hello.cc"],
    hdrs = ["hello.h"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        ":hello_proto_library"
    ]
)

cc_binary(
    name = "hello_project",
    srcs = ["main.cc"],
    deps = [":hello_lib"],
)

cpp_grpc_library(
    name = "hello_proto_library",
    protos = [":hello_proto"],
    deps = [":hello_proto_cc"]
)

cpp_proto_library(
    name = "hello_proto_cc",
    protos = [":hello_proto"],
)

proto_library(
    name = "hello_proto",
    srcs = [
        "HelloProto.proto"
    ],
)
