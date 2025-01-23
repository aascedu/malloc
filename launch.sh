#! /bin/bash
docker build -t malloc-dev .
docker run -it --rm -v "$(pwd):/workdir" malloc-dev bash
