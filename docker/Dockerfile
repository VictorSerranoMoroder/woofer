FROM ubuntu:25.04

# Avoid prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Install basic build tools and dependencies
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget

# Install gcc and g++
RUN apt-get install -y gcc g++ 

# Install Qt libraries
RUN apt-get update && apt-get -y --no-install-recommends install \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-declarative-dev \
    qt6-wayland-dev 

# Install Boost libraries
RUN apt-get install -y libboost-all-dev

# Install doxygen and graphviz
RUN apt-get install -y doxygen graphviz 

WORKDIR /workarea