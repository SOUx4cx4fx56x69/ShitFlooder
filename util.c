#include"main.h"

void
randString(char*array,int size)
{
static char * alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ";
srand(time(NULL));
for(int i = size; i--; )
 *array++ = ( *alphabet + ( rand()%51 ) );
*array++='\0';


}

int error(char*msg)
{
printf("ERROR: %s\n",msg);
exit(1);
}
