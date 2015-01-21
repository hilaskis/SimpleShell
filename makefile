CC= gcc
CFLAGS= -Wall -g -std=c99

default: sshell

sshell: main.o sshell.o
	$(CC) $(CFLAGS) main.c sshell.c -o sshell

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

sshell.o: sshell.c sshell.h
	$(CC) $(CFLAGS) -c sshell.c

clean:
	$(RM) sshell *.o *~
