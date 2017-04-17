int initSocket(int protocol,char*host,int port);
int error(char*msg);
int writeTo(int socket,char*msg);
int readFrom(int socket,char*buffer);
void randString(char*array,int size);
#define SIZEBUFFER 1024
