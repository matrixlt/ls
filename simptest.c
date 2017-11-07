#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
//#include <sys/types.h>


int main(){
    DIR* dir;
    char str[100];
    struct dirent* rent;
    dir=opendir(".");

    while((rent=readdir(dir))){
        strcpy(str,rent->d_name);
        printf("%s\n",str);
    }
    closedir(".");
    return 0;
}