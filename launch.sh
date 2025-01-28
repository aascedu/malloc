#! /bin/bash
docker build -t malloc-dev .
docker run -it -u 0 --rm -v "$(pwd):/workdir" malloc-dev bash