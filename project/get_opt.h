#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#ifndef GET_OPT
#define GET_OPT

int version_flag=0;
int help_flag=0;
//-l in different type
int l_flag=0;
int g_flag=0;
int G_flag=0;
int n_flag=0;
int o_flag=0;
int i_flag=0;
int s_flag=0;
int R_flag=0;
int flag_2=1;

//sort 
int r_flag=0;
int GroupDirectoriesFirst_flag=0;
int t_flag=0;
int c_flag=0;
int X_flag=0;
int U_flag=0;
int u_flag=0;
int S_flag=0;
int v_flag=0;

//hidefile
int a_flag=0;
int A_flag=0;
int B_flag=0;



//filename
int F_flag=0;
int p_flag=0;
int N_flag=0;
int Q_flag=0;
int filetype_flag=0;

struct option opts[]={
{"version",0,NULL,'9'},
{"no-group",0,NULL,'G'},
{"numeric-uid-gid",0,NULL,'n'},
{"inode",0,NULL,'i'},
{"size",0,NULL,'s'},
{"color", required_argument, NULL, '2'},
{"grout-directories-first",0,&GroupDirectoriesFirst_flag,1},
{"sort",1,NULL,'8'},
{"file-type",0,&filetype_flag,1},
{"indicator-style",1,NULL,'7'},
{"hide",1,NULL,'6'},
{"help",0,&help_flag,1}
};


void get_opt(int argc,char*argv[]){
    int c;
    while((c = getopt_long(argc,argv,"lgGnoisRrtcXUuSvaABFpQN",opts,NULL) ) !=-1){
        switch(c){
            case 'l': l_flag=1;
            break;
            case '9': version_flag=1;
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
            case '2': 
                if(strcmp(optarg, "never") == 0) {
                    flag_2 = 0;
                }
            break;

            //sort
            case 'r':r_flag=1;
            break;
            case 't':t_flag=1;
            break;
            case 'c':c_flag=1;
            break;
            case 'X':X_flag=1;
            break;
            case 'U':U_flag=1;
            break;
            case 'u':u_flag=1;
            break;
            case 'S':S_flag=1;
            break;
            case 'v':v_flag=1;
            break;
            case '8':{
                if(*optarg=='t')t_flag=1;
                else if(*optarg=='S')S_flag=1;
                else if(*optarg='v')v_flag=1;
            }

            //hidefile
            case 'a': a_flag=1;
            break;
            case 'A':A_flag=1;
            break;
            case 'B':B_flag=1;
            break;
            case '6':{
                if(*optarg='a')a_flag=1;
                else if(*optarg='A')A_flag=1;
            }
            break;

            //filename
            case 'p':p_flag=1;
            break;
            case 'Q':Q_flag=1;
            break;
            case 'F':F_flag=1;
            break;
            case 'N':N_flag=1;
            break;
            case '7':{
                if(*optarg='p')p_flag=1;
                else if(*optarg='F')F_flag=1;
                else if(!strcmp(optarg, "file-type"))filetype_flag=1;
            }
            break;
            default : break; 
        }
    }   
}

#endif