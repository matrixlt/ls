#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_file.h"
#include "flags.h"

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
 


 void sort_X(myfile file[],int number){
    
    char EntryExtension[number][256];
        for(int i=0;i<number;i++)
    {
        int j=strlen(file[i].name);
        int tag=0;
        while(tag != strlen(file[i].name)){
            if(file[i].name[tag] != '.')
            tag++;
            else{
                j=tag+1;
                tag++;
            }
        }

        int x;
        for(x = 0;file[i].name[j]!='\0';x++,j++)
        {
            EntryExtension[i][x]=file[i].name[j];
        }
        
        
        EntryExtension[i][x]='\0';

        //printf("%s |%s| %ld\n",file[i].name, EntryExtension[i], strlen(EntryExtension[i]));
    }
    
    myfile temp;
    for(int why=0;why<number;why++)
    {
        for(int j=why+1;j<number;j++)
        {//printf("\n%d\n",strcasecmp(EntryExtension[why],EntryExtension[j]));
         if( strcasecmp(EntryExtension[why],EntryExtension[j]) > 0 )
            {
           

            temp=file[why];
            file[why]=file[j];
            file[j]=temp;

            char tempstr[256];
            strcpy(tempstr,EntryExtension[why]);
            strcpy(EntryExtension[why],EntryExtension[j]);
            strcpy(EntryExtension[j],tempstr);

            }
         }
    }
}//sort by entry extension(扩展名）



void sort(myfile file[],int count)
{

int by_name (myfile file1 , myfile file2){
        if(strcasecmp(file1.name,file2.name)>0)
        return 1;
        else return 0;
}

int by_size (myfile file1, myfile file2){
    if(file1.size<file2.size)
    return 1;
    else return 0;
}

int by_time(myfile file1, myfile file2){
    if(file1.sec<file2.sec)
    return 1;
    else return 0;
}

int by_ctime(myfile file1, myfile file2){
    if(file1.last_changed<file2.last_changed)
    return 1;
    else return 0;
}

int by_atime(myfile file1, myfile file2){
    if(file1.access_time<file2.access_time)
    return 1;
    else return 0;
}

int by_default(myfile file1, myfile file2){
    return 0;
}


int (*p) (myfile file1, myfile file2);

p = &by_default;

if(!U_flag) p = &by_name;

if(c_flag && l_flag && t_flag) p = &by_ctime;
if(c_flag && !l_flag) p = &by_ctime;

if(u_flag && l_flag && t_flag) p = &by_atime;
if(u_flag && !l_flag) p = &by_atime;
if(S_flag) p = &by_size;
if(t_flag) p = &by_time;

myfile temp;
for(int i=0;i<count;++i){
    for(int j=i+1;j<count;++j){
        if( (*p)(file[i],file[j]) ){
            temp=file[i];
            file[i]=file[j];
            file[j]=temp;
        }
    }
}

   
    if(X_flag){sort_X(file,count);}
   
    if(GroupDirectoriesFirst_flag){sort_GroupDirectoriesFirst(file,count);}
   
    if(r_flag){sort_r(file,count);}
}
#endif
