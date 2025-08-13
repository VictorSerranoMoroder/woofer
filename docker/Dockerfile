FROM ubuntu:25.04

# Avoid prompts during installation
ENV DEBIAN_FRONTEND=noninteractive


# Install basic build tools and dependencies
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    locales \
    wget

# Make sure that libs needed for x11 displays are also included for debug reasons
RUN apt-get update && apt-get -y --no-install-recommends install \
    libx11-6 \
    libxext6 \
    libxrender1 \ 
    libxkbcommon-x11-0
    
# Install gcc and g++
RUN apt-get install -y gcc g++ 

# Configure locales
RUN locale-gen en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Install Qt libraries
RUN apt-get update && apt-get -y --no-install-recommends install \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-declarative-dev \
    qt6-wayland-dev \ 
    qt6-wayland 

# Install Boost libraries
RUN apt-get install -y libboost-all-dev

# Install doxygen and graphviz
RUN apt-get install -y doxygen graphviz 

WORKDIR /workarea