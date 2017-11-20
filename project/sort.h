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
 
//  void sort_t(myfile file[],int number){
//     myfile temp;
//     int i,j;
//     for(i=0;i<number;++i){
//     for(j=i+1;j<number;++j){
//         if(file[i].sec<file[j].sec){
//         temp=file[i];
//         file[i]=file[j];
//         file[j]=temp;}
//         }
//     }
//  }//sort by modification time ,newest first
 
//  void sort_c(myfile file[],int number){
//     myfile temp;
//     int i,j;
//     if(l_flag==1&&t_flag==0){
//          for(i=0;i<number;++i){
//             for(j=i+1;j<number;++j){
//                 if(strcasecmp(file[i].name,file[j].name) > 0){
//                 temp=file[i];
//                 file[i]=file[j];
//                 file[j]=temp;
//                 }
//             }
//         } //sort by name
//     }
//     else{
//         for(i=0;i<number;++i){
//             for(j=i+1;j<number;++j){
//                 if(file[i].last_changed<file[j].last_changed){
//                 temp=file[i];
//                 file[i]=file[j];
//                 file[j]=temp;
//                 }
//             }
//         }
//     }
//  }//sort by ctime

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
        // if(x==0){
        //     EntryExtension[i][x]=' ';
        //     EntryExtension[i][x+1]='\0';
        // }else EntryExtension[i][x]='\0';
        
        
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
           
            // for(int f=0;f<count ;f++)
            // {printf("%s    ",file[f].name );}
        
            //printf("\n %d %d %d",why,j,number);

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

//void sort_U(myfile file[],int number){}//按原始顺序排列

// void sort_u(myfile file[],int number){
//     myfile temp;
//     if(l_flag==1&&t_flag==0){
//     for(int i=0;i<number;++i){
//             for(int j=i+1;j<number;++j){
//                 if(file[i].name[0]<file[j].name[0]){
//                 temp=file[i];
//                 file[i]=file[j];
//                 file[j]=temp;
//                 }
//             }
//         } 
//     }
//     else{sort_t(file,number);}
//}//sort by acess time

// void sort_S(myfile file[],int number){
//     myfile temp;
//     for(int i=0;i<number;++i){
//             for(int j=i+1;j<number;++j){
//                 if(file[i].size<file[j].size){
//                 temp=file[i];
//                 file[i]=file[j];
//                 file[j]=temp;
//                 }
//             }
//         } 
// }// sort by size 

// void sort_v(myfile file[],int number){
//     myfile temp;
//     for(int i=0;i<number;++i){
//             for(int j=i+1;j<number;++j){
//                 if(file[i].size>file[j].size){
//                 temp=file[i];
//                 file[i]=file[j];
//                 file[j]=temp;
//                 }
//             }
//         }
// }//natural sort of size

// void default_sort(myfile file[],int count){
//     myfile temp;
//     int i,j;
    
//     for(i=0;i<count;++i){
//         for(j=i+1;j<count;++j){
//             if(strcasecmp(file[i].name,file[j].name) > 0){
//                 temp=file[i];
//                 file[i]=file[j];
//                 file[j]=temp;
//             }
//         }
//     } //sort by name
    
// }


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


//    default_sort(file,count);
   
   
//    if(t_flag){sort_t(file,count);}
   
//    if(c_flag){sort_c(file,count);}
   
    if(X_flag){sort_X(file,count);}
   
    if(GroupDirectoriesFirst_flag){sort_GroupDirectoriesFirst(file,count);}
   
//    if(U_flag){sort_U(file,count);}
   
//    if(u_flag){sort_u(file,count);} //wrong function 
   
//    if(S_flag){sort_S(file,count);}
   
//    if(v_flag){sort_v(file,count);} //wrong function

    if(r_flag){sort_r(file,count);}
}
#endif
