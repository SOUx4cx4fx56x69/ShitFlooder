#include"main.h"

int 
initSocket(int protocol, char*host,int port)
{
#ifdef WIN32
     WSADATA wsaData;
     DWORD dwError;
    // Initialize Winsock
    if ( (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) )
        error("WSAStartup failed\n");
#endif

int sockfd;
if(protocol) 
 sockfd = socket(AF_INET,SOCK_DGRAM,0);
else
  sockfd = socket(AF_INET,SOCK_STREAM,0);
if(sockfd == -1) return error("Socket create error");
struct sockaddr_in serv_addr;
struct hostent *server;
server = gethostbyname(host);
if (server == 0) return error("No such host");
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
//       void bcopy(const void *src, void *dest, size_t n);
bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
serv_addr.sin_port = htons(port);
if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
 return error("Connect refused");
return sockfd;
}

int 
writeTo(int socket,char*msg)
{
if(send(socket,msg,strlen(msg),MSG_NOSIGNAL) == -1)return 0;
if(send(socket,"\n",1,MSG_NOSIGNAL) == -1)return 0;
}

int 
readFrom(int socket,char*buffer)
{
memset(buffer,0,SIZEBUFFER);
#ifdef WIN32
if((recv(socket, buffer, SIZEBUFFER-1, 0)) <=0 )return 0;
#else
if(read(socket,buffer,SIZEBUFFER-1) == -1)return 0;
#endif
}

