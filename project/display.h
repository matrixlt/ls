#include <stdio.h>
#include <time.h>
#include <string.h>

#include "get_file.h"
#include "help.h"

#ifndef DISPLAY
#define DISPLAY

void display(myfile file[])
{
    //show version and return
    if(version_flag)
        {
            printf("0.001\n");
            return ;
        }


    //show help and return
    if(help_flag){
        help();
        return;
    }
    
    //-Gl == -o
    if(G_flag && l_flag)
    o_flag=1;


    if(l_flag || g_flag || n_flag || o_flag)
    {
        for(int i=0;i<count;i++)//long format
    {
        

        //show the inode of the file
        if(i_flag)
        printf("%d ",file[i].inode);
        
        //show the size of the file
        if(s_flag)
        printf("%5ld ",file[i].size);

        //show mode of the file       
        //printf("%s ",file[i].mode);
        int len=strlen(file[i].mode);
        for(int j=0;j<len;j++){
            if(file[i].mode[j]=='-' || file[i].mode[j]=='d'
            ||file[i].mode[j]=='r'||file[i].mode[j]=='w'
            ||file[i].mode[j]=='x')
            printf("%c",file[i].mode[j]);
        }
        printf("  ");
        

        //show the number of hard links
        printf("%d ",file[i].hlink);


        //show the name or number of the owner
        //printf("uid:%d  ",file[i].uid);
        if(!g_flag)
        {
            if(!n_flag)
            printf("%s ",file[i].u_name);
            else printf("%d ",file[i].uid);
        }
        

        //show the name or number of the group
        //printf("gid:%u  ",file[i].gid);
        if(!o_flag){
            if(!n_flag)
            printf("%s ",file[i].g_name);
            else printf("%u ",file[i].gid);
    
        }

        //show the size of the file
        if(R_flag==0)
        printf("%5ld ",file[i].size);

        //show time of the file
        printf("%2d月 %2d %02d:%02d ",file[i].time.tm_mon+1,file[i].time.tm_mday,file[i].time.tm_hour,file[i].time.tm_min);
        
        
        //show the name of the file
        printf("%s\n",file[i].name);
            


    }
    }
    else {// short format
        for(int i=0;i<count;i++)
    {   

        //show the inode of the file
        if(i_flag)
        printf("%d ",file[i].inode);


        //show the size of the file
        if(s_flag)
        printf("%5ld ",file[i].size);


        //show the name of the file
        printf("%s  ",file[i].name);

    }
       printf("\n");
       
    }    

}

#endif