#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int l_flag=0;
int v_flag=0;

struct option opts[]={
{"version",0,NULL,'v'}
};


void get_opt(int argc,char*argv[]){
    int c;
    while((c = getopt_long(argc,argv,"l",opts,NULL) ) !=-1){
        switch(c){
            case 'l': l_flag=1;
            break;
            case 'v': v_flag=1;
            break;
            default : break; 
        }
    }   
}