#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_opt.h"
#include "get_file.h"

#ifndef FILENAME
#define FILENAME

void filename_F(myfile file[],int count){
    int i,j,x;
    char EntryExtension[count][256];
    for(i=0;i<count;i++){
        for(j=0;file[i].name[j]!='.';j++);
        for(x=0;file[i].name[j]!='\0';x++,j++){
            EntryExtension[i][x]=file[i].name[j];
        }
    }//get entryExtension
    for(i=0;i<count;i++){
        if(file[i].mode[0]=='d')
            strcat(file[i].name,"/");
        else if(EntryExtension[i][1]=='\0')
            strcat(file[i].name,"*");
        if(file[i].isSLink==1)
            strcat(file[i].name,"@");
    }
}//append indicator to entries

void filename_filetype(myfile file[],int count){
for(int i=0;i<count;i++){
        if(file[i].mode[0]=='d')
            strcat(file[i].name,"/");
        if(file[i].isSLink==1)
            strcat(file[i].name,"@");
    }    
}

void filename_N(myfile file[],int count){}

void filename_p(myfile file[],int count){
    for(int i=0;i<count;i++){
        if(file[i].mode[0]=='d')
            strcat(file[i].name,"/");
    }
}

void filename_Q(myfile file[],int count){
    for(int i=0;i<count;i++){
        char temp[256];
        strcpy(temp,file[i].name);
        strcpy(file[i].name,"\"");
        strcat(file[i].name,temp);
        strcat(file[i].name,"\"");
    }
}

void filename(myfile file[],int count){
	if(filetype_flag)filename_filetype(file,count);
	if(Q_flag)filename_Q(file,count);
	if(F_flag)filename_F(file,count);
	if(N_flag)filename_N(file,count);
	if(p_flag)filename_p(file,count);
}
#endif
