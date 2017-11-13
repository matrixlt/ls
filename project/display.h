#include <stdio.h>
#include <time.h>
#include <string.h>
#include "get_file.h"

#ifndef DISPLAY
#define DISPLAY

void display(myfile file[])
{
    if(version_flag)//show version and return
        {
            printf("0.001\n");
            return ;
        }

    
    
    if(G_flag && l_flag)//-Gl == -o
    o_flag=1;


    if(l_flag || g_flag || n_flag || o_flag)
    {
        for(int i=0;i<count;i++)//long format
    {

            
        if(R_flag && (file[i].mode[0] == 'd')//-R unfinished
                  && ( strcmp(file[i].name ,".") != 0  )
                  && ( strcmp(file[i].name ,"..") != 0)
          )
        
        {
            //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            myfile *filedir = (myfile*)malloc(INISIZE*sizeof(myfile));
            char *temp = strcat(file[i].inwhat,file[i].name);
            //printf("%s  %d\n",temp,strlen(temp));
            printf("%s:\n",temp);
            int save=count;
            get_file(temp,&filedir);

            //printf("%d %d\n",filedir[0].uid,filedir[1].uid);
            display(filedir);
            count=save;
            printf("\n");
        }

        





        if(i_flag)//show the inode of the file
        printf("%d ",file[i].inode);

        if(s_flag)//show the size of the file
        printf("%5ld ",file[i].size);


        //printf("%s ",file[i].mode);
        int len=strlen(file[i].mode);//show mode of the file
        for(int j=0;j<len;j++){
            if(file[i].mode[j]=='-' || file[i].mode[j]=='d'
            ||file[i].mode[j]=='r'||file[i].mode[j]=='w'
            ||file[i].mode[j]=='x')
            printf("%c",file[i].mode[j]);
        }
        printf("  ");
        //printf("  %d",len);


        printf("%d ",file[i].hlink);//show the number of hard links

        //printf("uid:%d  ",file[i].uid);
        if(!g_flag)//show the name or number of the owner
        {
            if(!n_flag)
            printf("%s ",file[i].u_name);
            else printf("%d ",file[i].uid);
        }
        
        //printf("gid:%u  ",file[i].gid);
        if(!o_flag){////show the name or number of the group
            if(!n_flag)
            printf("%s ",file[i].g_name);
            else printf("%u ",file[i].gid);
    
        }
        
        printf("%5ld ",file[i].size);//show the size of the file
        printf("%2d月 %2d %02d:%02d ",file[i].time.tm_mon+1,file[i].time.tm_mday,file[i].time.tm_hour,file[i].time.tm_min);
        //show time of the file
        
        
        
        
        if(flag_2){//show name of the file
            if(file[i].isSLink == 1){
                printf("\x1b[0m\x1b[01;36m%s\x1b[0m\n", file[i].name);
            }
            else if(file[i].mode[0] == 'd'){
                printf("\x1b[0m\x1b[01;34m%s\x1b[0m\n", file[i].name);
            }
            else if(file[i].mode[3] == 'x'){
                printf("\x1b[0m\x1b[01;32m%s\x1b[0m\n", file[i].name);
            }
            else{
                printf("%s\n",file[i].name);
            }
            
        }

        else printf("%s\n",file[i].name);
            


    }
    }
    else {// short format
        for(int i=0;i<count;i++)
    {   

       
        if(R_flag && (file[i].mode[0] == 'd')
                  && ( strcmp(file[i].name ,".") != 0  )
                  && ( strcmp(file[i].name ,"..") != 0)
          )
        
        {
            //printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            myfile *filedir = (myfile*)malloc(INISIZE*sizeof(myfile));
            char *temp = strcat(file[i].inwhat,file[i].name);
            //printf("%s  %d\n",temp,strlen(temp));
            printf("%s:\n",temp);
            int save=count;
            get_file(temp,&filedir);

            //printf("%d %d\n",filedir[0].uid,filedir[1].uid);
            display(filedir);
            count=save;
            printf("\n");
        }



        if(i_flag)
        printf("%d ",file[i].inode);



        if(s_flag)
        printf("%5ld ",file[i].size);



        if(flag_2){
            if(file[i].isSLink == 1){
                printf("\x1b[0m\x1b[01;36m%s\x1b[0m  ", file[i].name);
            }
            else if(file[i].mode[0] == 'd'){
                printf("\x1b[0m\x1b[01;34m%s\x1b[0m  ", file[i].name);
            }
            else if(file[i].mode[3] == 'x'){
                printf("\x1b[0m\x1b[01;32m%s\x1b[0m  ", file[i].name);
            }
            else{
                printf("%s  ",file[i].name);
            }
            
        }
   
        else     printf("%s  ",file[i].name);

    }
       printf("\n");
       
    }    

}

#endif