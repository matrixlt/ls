#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int INISIZE = 100;

#include "get_opt.h"
#include "get_file.h"
#include "display.h"
#include "sort.h"
#include "filename.h"
#include "get_dir_R.h"
// int get_file(char file_path[],myfile file[]); 
// void get_opt(int argc,char*argv[]);
//void display(myfile file[]);

int main(int argc ,char*argv[]){

    myfile *file = (myfile*)malloc(INISIZE*sizeof(myfile));
    get_opt(argc,argv);

    



    if(optind == argc)//default
        {
            get_file(".",&file);

            if(R_flag)
            R_fun(file);
            else
            {    
                sort(file);
                filename(file);
                display(file);    
            }
        }

    for(int i = optind; i<argc; i++){
        
        if(argc - optind != 1)//more than one arguement
        {
            if(get_file(argv[i],&file) == 0)
            {   if(R_flag)
                R_fun(file);
                else
                {
                    printf("%s:\n",argv[i]);
                    sort(file);
                    filename(file);
                    display(file);
                    printf("\n");
                }
            }
            else printf("%s is invalid\n",argv[i]);
        }
        else {//only one arguement
            if(get_file(argv[i],&file) == 0)
            {   
                if(R_flag)
                R_fun(file);
                else
                {
                    sort(file);
                    filename(file);
                    display(file);
                }
            }
            else printf("%s is invalid\n",argv[i]);
        }
    }



    



    return 0;
}