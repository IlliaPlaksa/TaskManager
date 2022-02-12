FROM archlinux:latest

RUN	pacman -Syyu --noconfirm pkgconf make git cmake clang grpc boost gtest protobuf

RUN git clone https://github.com/IlliaPlaksa/TaskManager.git

WORKDIR "/TaskManager"

RUN git checkout linux_date_fix

RUN mkdir build
RUN cmake .

RUN cmake --build . -- -j 3

EXPOSE 50051

CMD ["./build/server", "--verbosity", "debug"]