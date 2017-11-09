#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc ,char*argv[]){
    struct option opts[]={
        {"version",0,NULL,'v'},
        {"help",0,NULL,'h'},
        {"mode",1,NULL,'m'}
    };
    int test;
    while((test=getopt_long(argc,argv,"abc",opts,NULL))!=-1)
    {
        //printf("optind %d \t optarg %s \t ch %c \n",optind,optarg,test);
        switch (test){
            case 'a' : printf("using mode a\n");
                    break;
            case 'b' : printf("using mode b\n");
                    break;
            case 'c' : printf("using mode c\n");
                    break;
            case 'v' :printf("verion:0.009\n");
                    break;
            case 'h' :printf("No help\n");
                    break;
            case 'm' :printf("using mode %s\n",optarg);
                    break;
                           
            default: break;
        }
    }


    return 0;
}