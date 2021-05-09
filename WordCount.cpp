#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define in 1
#define out 0
int main(int argc,char *argv[]){
	FILE *opfile;
	int i,danci=0,space=0,cchar=0,line=0,word=out,length;
	opfile=fopen("test.txt","r");
	
	if(opfile==NULL)
	{
		printf("该文件不存在！");
		exit(0);
	}
	fseek(opfile,00,SEEK_END);
	length=ftell(opfile);
	rewind(opfile);
	char str[10000],c;
	fread(str,sizeof(char),length,opfile);
	
	for(i=0;(c=str[i])!='\0';i++)
	{
		if(c==' '){
			space++;
			word=out;
		}else if(word==out){
				word=in;
				danci++;
			}		
		if((c=str[i])=='\n'){
			line++;
		}
	}
	cchar=length-space-line*2;
	line++;
	fclose(opfile);
	if(strcmp(argv[1],"-c")==0)
		printf("The number of characters is %d",cchar);
	else if(strcmp(argv[1],"-w")==0)
		printf("The number of words is %d",danci);
	else{	
			printf("Parameter input error!"); 
	}
}
