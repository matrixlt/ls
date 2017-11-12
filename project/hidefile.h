#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_opt.h"
#include "get_file.h"


#ifndef HIDEFILE
#define HIDEFILE
void hidefile_a(myfile file[]){
}//print inclding start with '.'

void hidefile_A(myfile file[]){
    int i,x;
    for(i=0;i<count;i++){
        if(strcmp(file[i].name,"..")==0||strcmp(file[i].name,".")==0)
            {for(x=i;x<count-1;x++)file[x]=file[x+1];
                count --;}
    }
}//hide '.' and '..'

void hidefile_B(myfile file[]){
    int i,j,x;
    for(i=0;i<count;i++){
        for(j=0;file[i].name[j]!='\0';j++);
        if(file[i].name[j-1]=='~'){
            for(x=i;x<count;x++)file[x]=file[x+1];
            count--;
        }
    }
}//hide end with '~'

void hidefile(myfile file[]){
	if(a_flag)hidefile_a(file);
	if(A_flag)hidefile_A(file);
	if(B_flag)hidefile_B(file);
}
#endif