#include "stdio.h"
#include "string.h"
#include "stdlib.h"
 
int zifu=0;
 
int danci=0;
 
int juzi=0;
 
void stat(char * file)
{
    FILE * fp;
    int b=0;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("Can't open file -");
        exit(-1);
    }
        a=fgetc(fp);		
	while(a!=EOF)
	{
		
	 if(a==' ' || a==','||a=='.')
		{
			
			danci++;}
			if(a=='.'||a=='!'||a=='?')
			{
				juzi++;
			}
			if(a!=' '&&a!=','&&a!='.'&&a!='?'&&a!='!'){
			zifu++;
			}
	
	}
	
    fclose(fp);
}
 
int main(int argc, char* argv[])             
{
    FILE *fp;
 
	stat(argv[2]);
    if((fp=fopen(argv[2],"r"))==NULL)
    {  
    printf("FileNull\n\n\n");
    scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    else if(!strcmp(argv[1],"-c"))                 
        printf("zifu:%s%d\n",argv[2],zifu);
    else if(!strcmp(argv[1],"-w"))                  
        printf("danci:%s%d\n",argv[2],danci);
    else if(!strcmp(argv[1],"-l"))                
        printf("juzi:%s%d\n",argv[2],juzi);
    else if(!strcmp(argv[1],"exit"))
    {
        printf("Exit!\n");
    }
    else
        printf("NullPoint\n");  
    return 0;
     
}
