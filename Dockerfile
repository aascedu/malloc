FROM    ubuntu:latest

RUN     apt update && apt install -y gcc make valgrind

WORKDIR /workdir

COPY    . .

ENV     LD_LIBRARY_PATH=/workdir/lib

CMD ["make"]