#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_file.h"
#include "get_opt.h"

#ifndef SORT
#define SORT



 void sort_r(myfile file[],int number){
     int i=0;
     int j=number-1;
     myfile temp;
     for(;i<j;i++,j--){
         temp=file[i];
         file[i]=file[j];
         file[j]=temp;
     }
     return;
 }//reverse

 void sort_GroupDirectoriesFirst(myfile file[],int number){
     int i=0;
     int j=0;
     myfile temp;
     for(;i<number;i++){
         if(file[i].mode[0]=='d'){
             temp=file[i];
             for(int x=i;x>j;x--)file[x]=file[x-1];//将i与j之间的文件依次后移
             file[j]=temp;
             j++;
         }
     }
     return;
 }//GroupDirectoriesFirst
 
 void sort_t(myfile file[],int number){
    myfile temp;
    int i,j;
    for(i=0;i<number;++i){
    for(j=i+1;j<number;++j){
        if(file[i].sec<file[j].sec){
        temp=file[i];
        file[i]=file[j];
        file[j]=temp;}
        }
    }
 }//sort by modification time ,newest first
 
 void sort_c(myfile file[],int number){
    myfile temp;
    int i,j;
    if(l_flag==1&&t_flag==0){
         for(i=0;i<number;++i){
            for(j=i+1;j<number;++j){
                if(strcasecmp(file[i].name,file[j].name) > 0){
                temp=file[i];
                file[i]=file[j];
                file[j]=temp;
                }
            }
        } //sort by name
    }
    else{
        for(i=0;i<number;++i){
            for(j=i+1;j<number;++j){
                if(file[i].last_changed<file[j].last_changed){
                temp=file[i];
                file[i]=file[j];
                file[j]=temp;
                }
            }
        }
    }
 }//sort by ctime
 
 void sort_X(myfile file[],int number){
    int i,j,x;
    myfile temp;
    char EntryExtension[count][256];
    for(i=0;i<number;i++){
        for(j=0;file[i].name[j]!='.';j++)
            ;
        for(x=0;file[i].name[j]!='\0';x++,j++){
            EntryExtension[i][x]=file[i].name[j];
            printf("%c",EntryExtension[i][x]);
        }
        printf("\n");
    }
    for(i=0;i<number;++i){
        for(j=i+1;j<number;j++){
         if(EntryExtension[i][1]>EntryExtension[j][1]){
             temp=file[i];
             file[i]=file[j];
             file[j]=temp;}
         }
        printf("%s\n",file[i].name);
    }
}//sort by entry extension(扩展名）

void sort_U(myfile file[],int number){}//按原始顺序排列

void sort_u(myfile file[],int number){
    myfile temp;
    if(l_flag==1&&t_flag==0){
    for(int i=0;i<number;++i){
            for(int j=i+1;j<number;++j){
                if(file[i].name[0]<file[j].name[0]){
                temp=file[i];
                file[i]=file[j];
                file[j]=temp;
                }
            }
        } 
    }
    else{sort_t(file,number);}
}//sort by acess time

void sort_S(myfile file[],int number){
    myfile temp;
    for(int i=0;i<number;++i){
            for(int j=i+1;j<number;++j){
                if(file[i].size<file[j].size){
                temp=file[i];
                file[i]=file[j];
                file[j]=temp;
                }
            }
        } 
}// sort by size 

void sort_v(myfile file[],int number){
    myfile temp;
    for(int i=0;i<number;++i){
            for(int j=i+1;j<number;++j){
                if(file[i].size>file[j].size){
                temp=file[i];
                file[i]=file[j];
                file[j]=temp;
                }
            }
        }
}//natural sort of size




void sort(myfile file[]){

    if(r_flag){sort_r(file,count);}
   
    if(t_flag){sort_t(file,count);}
   
    if(c_flag){sort_c(file,count);}
   
    if(X_flag){sort_X(file,count);}
   
    if(GroupDirectoriesFirst_flag){sort_GroupDirectoriesFirst(file,count);}
   
    if(U_flag){sort_U(file,count);}
   
    if(u_flag){sort_u(file,count);}
   
    if(S_flag){sort_S(file,count);}
   
    if(v_flag){sort_v(file,count);}
}
#endif
