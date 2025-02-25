Interprocess Communication (IPC) using Sockets
Interprocess Communication (IPC) allows processes to exchange data and synchronize their execution. IPC sockets facilitate communication between processes running on the same or different machines. There are two main types of IPC sockets:

Unix Domain Sockets (UDS) – Used for communication between processes on the same system. They provide faster and more efficient communication than network sockets as they avoid the overhead of networking protocols.
Internet Domain Sockets – Used for communication between processes over a network, using TCP/IP protocols.
Chat Application using IPC Sockets
This repository contains implementations of a simple chat application using both Unix Domain Sockets (UDS) and Internet Domain Sockets.

1. Unix Domain Socket Chat Application
Uses AF_UNIX socket family.
Communicates between two processes on the same machine using a socket file.
Faster and more efficient as it bypasses networking layers.
3. Internet Domain Socket Chat Application
Uses AF_INET socket family.
Supports communication over a network using TCP/IP.
Suitable for remote communication between different systems.
How to Run the Chat Applications
Unix Domain Socket Chat
Compile the server and client:
sh
Copy
Edit
gcc uds_server.c -o uds_server
gcc uds_client.c -o uds_client
Run the server in one terminal:
sh
Copy
Edit
./uds_server
Run the client in another terminal:
sh
Copy
Edit
./uds_client
Internet Domain Socket Chat
Compile the server and client:
sh
Copy
Edit
gcc inet_server.c -o inet_server
gcc inet_client.c -o inet_client
Run the server on a machine:
sh
Copy
Edit
./inet_server
Run the client on another machine or the same machine (providing the server’s IP address):
sh
Copy
Edit
./inet_client <server_ip_address>
