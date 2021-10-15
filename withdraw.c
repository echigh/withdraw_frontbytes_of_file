#include <stdlib.h>
#include <stdio.h>
#define MAX_LIMIT 40 
int main()
{
    FILE * file_pointer;
    FILE * fptr;
    unsigned char *buffer = (unsigned char *)malloc(1280*962*10);
    unsigned char srcfile[MAX_LIMIT],
         desfile[MAX_LIMIT];
    int number, i,numread, numwritten;
    printf("input srcfilename:");
    scanf("%s", srcfile);
    printf("input desfilename:");
    scanf("%s", desfile);
    printf("the srcfilename is %s\n", srcfile);
    printf("the desfilename is %s\n", desfile);

    printf("Enter the bytes num you need: ");
    scanf("%d", &number);

    file_pointer = fopen(srcfile, "r");
    printf("----read----\n");
    numread = fread( buffer, number, sizeof( unsigned char ), file_pointer );
    printf( "Number of items read = %d\n", numread );
    printf("buffer has been filled\n");
    printf("print a line data to be compared with srcfile:\n");
    for(i=0; i<1280; i++)
    {
        printf("%x ", buffer[i]);
    }

    printf("create desfile and open it\n");
    fptr = fopen(desfile, "w"); // "w" defines "writing mode"
    printf("start to copy data from srcfile to desfile\n");
    numwritten = fwrite( buffer, number, sizeof( unsigned char ), fptr );
    printf( "Wrote %d items\n", numwritten );
    printf("copy done.\n");

    fclose(file_pointer);
    fclose(fptr);
    return 0;
}
