#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#include "get_file.h"
#include "help.h"

#ifndef DISPLAY
#define DISPLAY

void display(myfile file[], int count)
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
        printf("%5ld ",file[i].size/1024);

        //show mode of the file       
        printf("%s ",file[i].mode);
        

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


        //show the author of the file
        if(author_flag)
        printf("%s ",file[i].u_name);
        
        //show the size of the file
        if(human_readable){
            printf("%4.1fk ",file[i].size/1024.0);
        }else if(si_flag){
            printf("%4.1fk ",file[i].size/1000.0);
        }else if(kibibytes){
            printf("%4.1fk ",file[i].size/1024.0);
        }else 
        printf("%5ld ",file[i].size);

        //show time of the file
        struct tm printime;
        if(time_flag == 1 || u_flag == 1)
        {
            printime = file[i].a_time;
        }
        else if(time_flag == 2 || c_flag == 1)
        {
            printime = file[i].c_time;
        }
        else printime = file[i].time;
        

        // printf("%ld %ld %ld \n",file[i].sec,file[i].access_time,file[i].last_changed);
        // printf("%d %d %d \n",file[i].time.tm_min,file[i].a_time.tm_min,file[i].c_time.tm_min);


        if(time_style == 1 )
        {
            printf("%2d-%2d %02d:%02d ",printime.tm_mon+1,printime.tm_mday,printime.tm_hour,printime.tm_min);
        }else if(time_style == 2){
            printf("%4d-%2d-%2d %02d:%02d ",printime.tm_year+1900,printime.tm_mon+1,printime.tm_mday,printime.tm_hour,printime.tm_min);
        }else 
        printf("%2d月 %2d %02d:%02d ",printime.tm_mon+1,printime.tm_mday,printime.tm_hour,printime.tm_min);
        
        
        //show the name of the file
        printf("%s\n",file[i].name);



        if(slow != 0)  
        {
        //printf("%d\n",slow);  
            usleep(1000*slow);
        }

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
        if(human_readable){
            printf("%4.1fk ",file[i].size/1024.0);
        }else if(si_flag){
            printf("%4.1fk ",file[i].size/1000.0);
        }else if(kibibytes){
            printf("%4.1fk ",file[i].size/1024.0);
        }else 
        printf("%5ld ",file[i].size);


        //show the name of the file
        printf("%s  ",file[i].name);

        
        if(slow != 0)  
        {
        //printf("%d\n",slow);  
            usleep(1000*slow);
        }
    }
       printf("\n");
       
    }    

}

#endif