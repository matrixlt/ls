#include <getopt.h>
#include <string.h>
#include <stdlib.h>

#include "flags.h"

#ifndef GET_OPT
#define GET_OPT


struct option opts[]={
{"version",0,&version_flag,1},
{"no-group",0,NULL,'G'},
{"numeric-uid-gid",0,NULL,'n'},
{"inode",0,NULL,'i'},
{"size",0,NULL,'s'},
{"color", required_argument, NULL, '2'},
{"group-directories-first",0,&GroupDirectoriesFirst_flag,1},
{"sort",1,NULL,'8'},
{"file-type",0,&filetype_flag,1},
{"indicator-style",1,NULL,'7'},
{"hide",1,NULL,'6'},
{"help",0,&help_flag,1},
{"author",0,&author_flag,1},

{"time",1,NULL,'9'},
{"time-style",1,NULL,'5'},

{"human-readable",0,&human_readable,1},
{"si",0,&si_flag,1},
{"kibibytes",0,&kibibytes,1},

{"slow",1,NULL,'4'}
};


void get_opt(int argc,char*argv[]){
    int c;
    while((c = getopt_long(argc,argv,"lgGnoisRrtcXUuSvaABFpQNhkf",opts,NULL) ) !=-1){
        switch(c){
            //-l in different type
            case 'l': l_flag=1;
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
            case '2': //color
                if(strcmp(optarg, "never") == 0) {
                    color_flag = 0;
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

            //time
            case '9':{
                if(strcmp(optarg,"atime")==0)
                time_flag=1;
                if(strcmp(optarg,"ctime")==0)
                time_flag=2;
            }
            break;

            //time-style
            case '5' :{
                if(strcmp(optarg,"iso") == 0)
                time_style =1;
                if(strcmp(optarg, "long-iso") == 0)
                time_style =2;
            }
            break;

            //size
            case 'h':human_readable=1;
            break;
            case 'k':kibibytes=1;
            break;


            case '4':slow = atoi(optarg);
            break;

            case 'f':f_flag = 1;
            break;


            
            default : break; 
        }
    }
        if(f_flag){
        a_flag = 1;
        U_flag =1;
        color_flag = 0;
        l_flag = 0;
        s_flag = 0;

    }   
}

#endif