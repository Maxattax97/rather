all: go cpp

go:
	protoc \
	--go_out=../golang/ --go_opt=paths=source_relative \
	--go-grpc_out=../golang/ --go-grpc_opt=paths=source_relative \
	rather.proto

cpp:
	protoc -I . --grpc_out=../clang/main/ --plugin=protoc-gen-grpc=/sbin/grpc_cpp_plugin rather.proto
	protoc -I . --cpp_out=../clang/main/ rather.proto
