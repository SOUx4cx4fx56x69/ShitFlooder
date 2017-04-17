int initSocket(int protocol,char*host,int port);
int error(char*msg);
int writeTo(int socket,char*msg);
int readFrom(int socket,char*buffer);
void randString(char*array,int size);
#define SIZEBUFFER 1024
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
