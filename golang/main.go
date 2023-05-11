package rather

import (
	"context"
	"flag"
	"fmt"
	"log"
	"net"

	pb "github.com/Maxattax97/rather/protobufs/rather"
	"google.golang.org/grpc"
)

var (
	port = flag.Int("port", 50011, "The server port")
)

// server is used to implement rather.GreeterServer.
type server struct {
	pb.UnimplementedRatherServer
}

// SayHello implements helloworld.GreeterServer
func (s *server) GetRose(ctx context.Context, in *pb.RoseRequest) (*pb.RoseResponse, error) {
	log.Printf("Received: %v", in.GetName())
	return &pb.RoseResponse{Message: "Hello " + in.GetName()}, nil
}

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", fmt.Sprintf(":%d", *port))
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterRatherServer(s, &server{})
	log.Printf("server listening at %v", lis.Addr())
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
