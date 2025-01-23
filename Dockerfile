FROM    ubuntu:latest

RUN     apt update && apt install -y gcc make valgrind

WORKDIR /workdir

COPY    . .

CMD ["make"]