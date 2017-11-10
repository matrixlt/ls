#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "get_opt.h"
#include "get_file.h"


void get_file(char file_path[],myfile file[]); 
void get_opt(int argc,char*argv[]);

int main(int argc ,char*argv[]){

    myfile file[100];
    get_file(argv[1],file);
    get_opt(argc,argv);
    
    if(v_flag)
    {
        printf("0.001\n");
        return 0;
    }

    
    //printf("%d\n",l_flag);

    if(l_flag)
{
    for(int i=0;i<count;i++){
        printf("%s  ",file[i].mode);
        printf("%d ",file[i].hlink);
        printf("uid:%d  ",file[i].uid);
        printf("gid:%u  ",file[i].gid);
        printf("size:%ld  ",file[i].size);
        printf("%d %d %d:%d ",file[i].time->tm_mon+1,file[i].time->tm_mday,file[i].time->tm_hour,file[i].time->tm_min);
        printf("%s\n",file[i].name);
    }
}
else {
    for(int i=0;i<count;i++)
    printf("%s,\t",file[i].name);
    printf("\n");
}    
    return 0;
}