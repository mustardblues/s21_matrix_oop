#!/bin/bash

cd ./../../

docker build . -t leak_tests:1 -f ./tests/leak_tests/Dockerfile
docker run --rm -it leak_tests:1
docker rmi -f leak_tests:1

# docker builder prune