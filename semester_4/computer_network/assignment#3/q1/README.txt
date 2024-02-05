The client takes an integer input and sends it to the server.
The server then finds the matching integer and its corresponding name.
Its send the name as a string back to the client and the client displays it.
If the integer doesn't exist, the client displays "Address not found".

Compile server.c and client.c
	gcc server.c -o server
	gcc client.c -o client

Run server.c and then client.c
	./server
	./client
