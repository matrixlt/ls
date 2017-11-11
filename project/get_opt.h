#include <stdio.h>
#include <unistd.h>
#include <getopt.h>



#ifndef GET_OPT
#define GET_OPT
int l_flag=0;
int v_flag=0;
int g_flag=0;
int G_flag=0;
int n_flag=0;
int o_flag=0;
int i_flag=0;
int s_flag=0;
int R_flag=0;
struct option opts[]={
{"version",0,NULL,'v'},
{"no-group",0,NULL,'G'},
{"numeric-uid-gid",0,NULL,'n'},
{"inode",0,NULL,'i'},
{"size",0,NULL,'s'}
};


void get_opt(int argc,char*argv[]){
    int c;
    while((c = getopt_long(argc,argv,"lgGnoisR",opts,NULL) ) !=-1){
        switch(c){
            case 'l': l_flag=1;
            break;
            case 'v': v_flag=1;
            break;
            case 'g': g_flag=1;
            break;
            case 'G': G_flag=1;
            break;
            case 'o': o_flag=1;
            break;
            case 'n': n_flag=1;
            break;
            case 'i': i_flag=1;
            break;
            case 's': s_flag=1;
            break;
            case 'R': R_flag=1;
            break;
            default : break; 
        }
    }   
}

#endif