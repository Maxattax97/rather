package ringaroundtherosie

import (
	"context"
	"flag"
	"fmt"
	"log"
	"net"

	pb "github.com/Maxattax97/ring-around-the-rosie/protobufs/ringaroundtherosie"
	"google.golang.org/grpc"
)

var (
	port = flag.Int("port", 50011, "The server port")
)

// server is used to implement ringaroundtherosie.GreeterServer.
type server struct {
	pb.UnimplementedRingAroundTheRosieServer
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
	pb.RegisterRingAroundTheRosieServer(s, &server{})
	log.Printf("server listening at %v", lis.Addr())
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
