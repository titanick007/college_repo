First compile server, client1 and client2 in different terminal windows
	gcc server.c -o server
	gcc client1.c -o client1
	gcc client2.c -o client2	

Then run the programs in the following order:
	client2.c : ./client2
	server.c : ./server
	client1.c : ./client1

