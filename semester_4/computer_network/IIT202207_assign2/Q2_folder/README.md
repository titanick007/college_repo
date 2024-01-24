# Simple server-client communication in C

This repository contains basic server and client programs written in C for establishing a TCP connection and exchanging messages.


#Files

This repository contains basic server and client programs written in C for establishing a TCP connection and exchanging messages.

## Files

- **server.c**: Implements a simple server that listens for incoming connections, receives a message from the client, and sends a response.

- **client.c**: Implements a simple client that connects to the server, sends a message, and prints the server's response.

## How to Compile and Run

### Server

1. Open a terminal in the project directory.

2. Compile the server using the following command:

    ```bash
    gcc server.c -o server
    ```

3. Run the compiled server:

    ```bash
    ./server
    ```

    The server will start listening on port 12345.

### Client

1. Open another terminal in the project directory.

2. Compile the client using the following command:

    ```bash
    gcc client.c -o client
    ```

3. Run the compiled server:
    ```bash
    ./server
    ```
4. Run the compiled client:

    ```bash
    ./client
    ```

    The client will connect to the server and exchange messages.

**Note**: Make sure you run the server and client run in different terminal windows.Ensure that you run the server before the client to establish a successful connection.
