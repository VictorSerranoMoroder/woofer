#!/bin/bash

# Check number of arguments 
if [ "$#" -ne 2 ]; then
  echo "Usage: $0 <container_name> <version>"
  exit 1
fi

VERSION=${2:-latest}
IMAGE_NAME="$1"

# If a version is provided, check if it's a number
if [ "$VERSION" != "latest" ]; then
  if ! [[ "$VERSION" =~ ^[0-9]+(\.[0-9]+)*$ ]]; then
    echo "Error: Version must be a number {1.0} or 'latest'."
    exit 2
  fi
fi

echo "Trying to build docker image '${IMAGE_NAME}:${VERSION}'..."
if docker build -t ${IMAGE_NAME}:${VERSION} .; then
    echo "Image created succesfully"
fi