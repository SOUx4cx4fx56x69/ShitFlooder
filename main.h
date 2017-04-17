int initSocket(int protocol,char*host,int port);
int error(char*msg);
int writeTo(int socket,char*msg);
int readFrom(int socket,char*buffer);
void randString(char*array,int size);
#define SIZEBUFFER 1024

#ifdef WIN32
   #include <winsock.h>
   #include <winsock2.h>
   #include <ws2tcpip.h>
   #define MSG_NOSIGNAL 0
   #pragma comment(lib, "ws2_32.lib")
#else
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netdb.h>
#endif

#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
