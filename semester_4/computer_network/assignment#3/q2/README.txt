Compile server.c and client.c
	gcc server.c -o server
	gcc client.c -o client

Run server.c and then client.c
	./server
	./client

This program is implemented using protocols
Request protocol structure:

Byte 0:
	00001001 is number request    
	00000001 is name request

Bytes 1 - n :
	used to store corresponding data (name or number)

Byte n+1 :
	used for terminating character (ETX)


Reply protocol structure:

Bytes 0- n :
	used to store corresponding data (name or number)

Byte n+1 :
	used for terminating character (ETX)

