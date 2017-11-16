#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int INISIZE_DIR = 100;


void get_dir(myfile file[] ,int *count_2,char*** testdir){
    for(int i=0;i<count;i++)
{
        if(R_flag && (file[i].mode[0] == 'd')//-R now is finished
                  && ( strcmp(file[i].name ,".") != 0  )
                  && ( strcmp(file[i].name ,"..") != 0)
          )
        
        {
            //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            myfile *filedir = (myfile*)malloc(INISIZE*sizeof(myfile));
            char *temp = strcat(file[i].inwhat,file[i].name);
            //printf("%s  %d\n",temp,strlen(temp));
             //printf("%s??????????????????:\n",temp);

            strcpy((*testdir)[*count_2],temp);
            (*count_2)++;
            if(*count_2 >= INISIZE_DIR)
            {
                INISIZE_DIR = INISIZE_DIR*2;
                *testdir = (char**)realloc(*testdir,INISIZE_DIR*sizeof(char*));
                for(int i=INISIZE_DIR/2;i<INISIZE_DIR;i++)
                {
                (*testdir)[i] = (char*)malloc(4096*sizeof(char));
                }
            }

            int save=count;
            get_file(temp,&filedir);
            get_dir(filedir,count_2,testdir);
            count=save;
            
        }
    }
}

void R_fun(myfile file[],char*** testdir){
    printf("%s:\n",file[0].inwhat);
    display(file);
    if(R_flag){
        
        int count_2=0;
        //get_file(".",&file);
        get_dir(file,&count_2,testdir); 
        //printf("  %d !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n",count_2);
    
        //printf("!!!!!!!!%d!!!!!!\n\n\n\n\n",R_flag);
        for(int i=0;i<count_2;i++){
        printf("\n%s:\n",(*testdir)[i]);
        myfile *file_R = (myfile*)malloc(INISIZE*sizeof(myfile));
        get_file((*testdir)[i],&file_R);
        sort(file_R, count);
        filename(file_R,count);
        display(file_R);
        }
        
    }
    }