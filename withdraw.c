#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dirent.h"

#define MAX_LIMIT 128


int main()
{
    #if 1
    unsigned char *FilePath = (unsigned char *)malloc(MAX_LIMIT),
        *srcfile = (unsigned char *)malloc(MAX_LIMIT),
        *desfile = (unsigned char *)malloc(MAX_LIMIT);
    DIR *dir = NULL;
    struct dirent *entry;
    volatile int len_temp1, len_temp2; 
    FILE * file_pointer;
    FILE * fptr;
    unsigned char *buffer = (unsigned char *)malloc(1280*962*10);
    int number, i,numread, numwritten;

    printf("input DIR:");
    scanf("%s", FilePath);

    printf("Enter the bytes num you need: ");
    scanf("%d", &number);

    printf("FilePath length = %ld\n", strlen(FilePath));

    if((dir = opendir(FilePath))==NULL)  
    {  
        printf("opendir failed!");  
        return -1;  
    }
	else  
    {  
        while(entry=readdir(dir))  
        {
            //利于显示
            printf("\n");

            //文件夹或者系统隐藏文件跳过  
            if(entry->d_name[0] == '.')
            {
                continue;
            }
            if(entry->d_type == 4)
            {
                continue;
            }
            //printf("filename = %s, ",entry->d_name);  //输出文件或者目录的名称
            //printf("filetype = %d\n",entry->d_type);  //输出文件类型

            len_temp1 = strlen(FilePath);
            len_temp2 = strlen(entry->d_name);

            //合成源文件名
            memcpy(srcfile,FilePath,len_temp1);
            srcfile[len_temp1] = '/';
            memcpy(srcfile+len_temp1+1,entry->d_name,len_temp2);
            srcfile[len_temp1+1+len_temp2] = '\0';
            printf("the srcfilename is %s\n", srcfile);

            //合成目的文件名
            memcpy(desfile,FilePath,len_temp1);
            desfile[len_temp1] = '/';
            desfile[len_temp1+1] = 'd';
            desfile[len_temp1+2] = '_';
            memcpy(desfile+len_temp1+3,entry->d_name,len_temp2);
            desfile[len_temp1+3+len_temp2] = '\0';
            printf("the desfilename is %s\n", desfile);

            //文件操作
            file_pointer = fopen(srcfile, "r");
            if(file_pointer==NULL)
            {
                printf("srcfile open failed, check if there is the file.\n");
                printf("app terminate.\n");
                break;
            }
            printf("----read----\n");
            numread = fread( buffer, number, sizeof( unsigned char ), file_pointer );
            printf( "Number of items read = %d\n", numread );
            printf("buffer has been filled\n");
            // printf("print some data to be compared with srcfile:\n");
            // for(i=0; i<32; i++)
            // {
            //     printf("%x ", buffer[i]);
            // }

            printf("create desfile and open it\n");
            fptr = fopen(desfile, "w"); // "w" defines "writing mode"
            printf("start to copy data from srcfile to desfile\n");
            numwritten = fwrite( buffer, number, sizeof( unsigned char ), fptr );
            printf( "Wrote %d items\n", numwritten );
            printf("copy done.\n");

            fclose(file_pointer);
            fclose(fptr);
        }  
    
        closedir(dir);    
    }  
    return 0;
    #endif
     
    #if 0    
    FILE * file_pointer;
    FILE * fptr;
    unsigned char *buffer = (unsigned char *)malloc(1280*962*10);
    unsigned char srcfile[MAX_LIMIT],
         desfile[MAX_LIMIT];
    unsigned char c;
    int number, i,numread, numwritten;
    printf("Enter the bytes num you need: ");
    scanf("%d", &number);
    while(1)
    {
    printf("input srcfilename:");
    scanf("%s", srcfile);
    printf("input desfilename:");
    scanf("%s", desfile);
    printf("the srcfilename is %s\n", srcfile);
    printf("the desfilename is %s\n", desfile);

    file_pointer = fopen(srcfile, "r");
    if(file_pointer==NULL)
    {
        printf("srcfile open failed, check if there is the file.\n");
	printf("app terminate.\n");
	break;
    }
    printf("----read----\n");
    numread = fread( buffer, number, sizeof( unsigned char ), file_pointer );
    printf( "Number of items read = %d\n", numread );
    printf("buffer has been filled\n");
    printf("print some data to be compared with srcfile:\n");
    for(i=0; i<32; i++)
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
   
    }

    return 0;
    #endif

}


