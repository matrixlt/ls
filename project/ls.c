#include <stdio.h>
#include <stdlib.h>


#include "get_opt.h"
#include "get_file.h"
#include "display.h"
#include "sort.h"
#include "filename.h"
#include "get_dir_R.h"


int main(int argc ,char*argv[]){

    myfile *file = (myfile*)malloc(INISIZE*sizeof(myfile));
    get_opt(argc,argv);

    if(optind == argc)//default
        {
            get_file(".",&file);

            if(R_flag){
                char** testdir = (char**)malloc(INISIZE_DIR*sizeof(char*));
                for(int i=0; i<INISIZE_DIR; i++)
                {
                    testdir[i] = (char*)malloc(4096*sizeof(char));
                }
                    R_fun(file,&testdir);
                }
            else
            {    
                sort(file,count);
                filename(file,count);
                display(file);    
            }
        }

    for(int i = optind; i<argc; i++){
        
        if(argc - optind != 1)//more than one arguement
        {
            if(get_file(argv[i],&file) == 0)
            {   if(R_flag){
                char** testdir = (char**)malloc(INISIZE_DIR*sizeof(char*));
                for(int i=0; i<INISIZE_DIR; i++)
                {
                    testdir[i] = (char*)malloc(4096*sizeof(char));
                }
                    R_fun(file,&testdir);
                }
                else
                {
                    printf("%s:\n",argv[i]);
                    sort(file,count);
                    filename(file,count);
                    display(file);
                    printf("\n");
                }
            }
            else printf("%s is invalid\n",argv[i]);
        }
        else {//only one arguement
            if(get_file(argv[i],&file) == 0)
            {   
                if(R_flag){
                char** testdir = (char**)malloc(INISIZE_DIR*sizeof(char*));
                for(int i=0; i<INISIZE_DIR; i++)
                {
                    testdir[i] = (char*)malloc(4096*sizeof(char));
                }
                    R_fun(file,&testdir);
                }
                else
                {
                    sort(file,count);
                    filename(file,count);
                    display(file);
                }
            }
            else printf("%s is invalid\n",argv[i]);
        }
    }


    return 0;
}