#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
typedef struct {
    char name[256];

    int   inode;
    int   uid;
    int   gid;
    int   hlink;

    char  mode[10];
    int   isSLink;
    long  int sec;
    long  int size;
    struct tm *time;

}myfile;
int count = 0;
//myfile   file[100];


void get_file( char file_path[],myfile file[]){
    
    
    DIR* dir;
    char str[256];
    char path[4096];
    struct dirent* rent;
    dir=opendir(file_path);
    
    if(dir==NULL)
    return;
    
    struct stat file1;
    int test;

    while((rent=readdir(dir))){
        strcpy(path,file_path);
        strcpy(str,rent->d_name);
        strcat(path,"/");
        strcat(path,str);
        
        test=stat(path,&file1);
        //printf("%d%s\n",test,path);

        char str1[10];
        if(S_ISDIR(file1.st_mode))
        str1[0] = 'd';
        else str1[0] = '-';

        mode_t mode =file1.st_mode; 
      
        if(mode & S_IRUSR) str1[1] = 'r';
        else str1[1]='-';

        if(mode & S_IWUSR) str1[2] = 'w';
        else str1[2]='-';

        if(mode & S_IXUSR) str1[3] = 'x';
        else str1[3]='-';  
      
        if(mode & S_IRGRP) str1[4] = 'r';
        else str1[4]='-';

        if(mode & S_IWGRP) str1[5] = 'w';
        else str1[5]='-';  

        if(mode & S_IXGRP) str1[6] = 'x';
        else str1[6]='-';  
      
        if(mode & S_IROTH) str1[7] = 'r';
        else str1[7]='-';

        if(mode & S_IWOTH) str1[8] = 'w';
        else str1[8]='-';

        if(mode & S_IXOTH) str1[9] = 'x';
        else str1[9]='-';  
        struct tm *time1 = localtime(&file1.st_mtime);

        strcpy(file[count].name,str);
        strcpy(file[count].mode,str1);
        file[count].uid=file1.st_uid;
        file[count].gid=file1.st_gid;
        file[count].size=file1.st_size;
        file[count].hlink=file1.st_nlink;
        file[count].time=time1;
        file[count].inode=file1.st_ino;
        file[count].isSLink=S_ISLNK(file1.st_mode);
        file[count].sec=file1.st_mtime;
        
        //count is not finished
        count++;    
    }
    closedir(dir);
}