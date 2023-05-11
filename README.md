# ring around the rosie (RATheR)

This project demonstrates a robust and efficient workspace for maintaining
multiple microservices from a mix of languages.

## abstract

We demonstrate a simple ["Ring around the
Rosie"](https://en.wikipedia.org/wiki/Ring_a_Ring_o'_Roses) system comprised of
microservices representing one of several major programming languages. The
services communicate via a gRPC message bus.

Languages implemented:

- Typescript/Javascript
- Python
- Java
- C#
- PHP
- C/C++
- Golang
- Rust

The microservices arrange themselves in a circle and pass a message to their
right. When a message is received, it is forwarded to the right again.

## building

Meson and Bazel are up-and-coming next generation build systems. We implement
both for demonstration purposes.
