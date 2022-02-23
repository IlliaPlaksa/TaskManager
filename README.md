# TaskManager

## Description
Client-server application for managing your tasks that need to be completed.
### Used libraries
- [Protobuf](https://github.com/protocolbuffers/protobuf)
- [GRPC](https://grpc.io)
- [Boost](https://www.boost.org)
### Features
- Tasks priority
- Subtasks
- Labels
- Client-server
## How to install
### Linux and MacOS using CMake
#### 1. Install [CMake](https://cmake.org) the latest version you can. 
#### 2. Install libraries:
- [Protobuf](https://github.com/protocolbuffers/protobuf)
- [GRPC](https://github.com/grpc/grpc)
- [Boost](https://www.boost.org)
- [GoogleTest](https://github.com/google/googletest) with GMock (to run tests)

#### 3. Building from source:
```bash
git clone https://github.com/IlliaPlaksa/TaskManager.git
cd TaskManager
mkdir build
cd build
cmake ..
cmake --build .
```
#### 4. Start `server`:
```bash
cd build
./server
```
For starting `server` with custom options use
```bash
./server --help
```
to show available start options of server.
#### 5. Start `client`:
```bash
cd build
./client
```
For starting `client` with custom options use
```bash
./client --help
```
to show available start options of client.

### Server deployment in Docker
Repository contains `Dockerfile` to compile `Docker image` for server deployment.
See [Docker](https://www.docker.com/) for details.