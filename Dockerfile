FROM alpine:3.6

RUN apk add --no-cache \
    g++ \
    gdb \
    make

COPY examples /examples/

WORKDIR /examples

RUN make
