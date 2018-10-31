.PHONY:all
all:client server 
client:comm.c client.c
	gcc -o $@ $^
server:comm.c server.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f server client 

