#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include "get_opt.h"
#include "get_file.h"
#include "display.h"

// int get_file(char file_path[],myfile file[]); 
// void get_opt(int argc,char*argv[]);
//void display(myfile file[]);

int main(int argc ,char*argv[]){

    myfile file[100];
    get_opt(argc,argv);
    //printf("%d  %d  \n",optind , argc);
    if(optind == argc)//default
        {
            get_file(".",file);
            display(file);
            
        }

    for(int i = optind; i<argc; i++){
        
        if(argc - optind != 1)//more than one arguement
        {
            if(get_file(argv[i],file) == 0)
            {
                printf("%s:\n",argv[i]);
                display(file);
                printf("\n");
            }
            else printf("%s is invalid\n",argv[i]);
        }
        else {//only one arguement
            if(get_file(argv[i],file) == 0)
            display(file);
            else printf("%s is invalid\n",argv[i]);
        }
    }
    
    return 0;
}