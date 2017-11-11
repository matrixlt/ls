#include <stdio.h>
#include <time.h>
#include "get_file.h"

#ifndef DISPLAY
#define DISPLAY

void display(myfile file[])
{
if(v_flag)
    {
        printf("0.001\n");
        return ;
    }

    
    //printf("%d\n",l_flag);
    if(G_flag && l_flag)
    o_flag=1;


    





    if(l_flag || g_flag || n_flag || o_flag)
{
    for(int i=0;i<count;i++){

        // if(R_flag && (file[count].mode[0] == 'd')
        //           && (file[count].name !=  ".")
        //           && (file[count].name != "..")
        //   )
    
        // {
        //     myfile filedir[100];
        //     get_file(file[count].name,filedir);
        //     display(filedir);
        // }


        if(i_flag)
        printf("%d ",file[i].inode);

        if(s_flag)
        printf("%5ld ",file[i].size);


        printf("%s ",file[i].mode);
        printf("%d ",file[i].hlink);

        //printf("uid:%d  ",file[i].uid);
        if(!g_flag)
        {
            if(!n_flag)
            printf("%s ",file[i].u_name);
            else printf("%d ",file[i].uid);
        }
        
        //printf("gid:%u  ",file[i].gid);
        if(!o_flag){
            if(!n_flag)
            printf("%s ",file[i].g_name);
            else printf("%u ",file[i].gid);
    
        }
        
        printf("%5ld ",file[i].size);
        printf("%d月 %d %d:%d ",file[i].time.tm_mon+1,file[i].time.tm_mday,file[i].time.tm_hour,file[i].time.tm_min);
        printf("%s\n",file[i].name);
    }
}
else {
    for(int i=0;i<count;i++)
    {
    if(i_flag)
    printf("%d ",file[i].inode);



    if(s_flag)
    printf("%5ld ",file[i].size);

    printf("%s  ",file[i].name);
    }
    printf("\n");
}    


}

#endif