FROM golang:1.18 AS builder
WORKDIR /usr/local/src/rather/
COPY ./ ./
RUN  CGO_ENABLED=0 go build -a -installsuffix cgo -o rather .

FROM alpine:latest
WORKDIR /usr/local/bin/
COPY --from=builder /usr/local/src/rather/rather ./
CMD ["./rather"]
