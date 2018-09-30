#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void GetNum(char infile[],int *str)  /*��ȡѧ���𰸵ĺ���*/ 
{
	FILE *in;
	char a;
	int i=0;
if((in=fopen(infile,"r"))==NULL)
	{
	   printf("read file failed��\n"); 
	   exit(0);
	} 
	while(!feof(in))
	{
		*(str+i)=0;
		a=fgetc(in);		
		if(a!='=') 
		continue;
		while(1)
		{
			a=fgetc(in);
			if(a=='\n')break;
			*(str+i)*=10;	
			*(str+i)+=(a-48);
	    }
			printf("%d ",*(str+i));
			i++;
	}
	printf("\n");
	fclose(in);
}
void PutResult(int *str1,int *str2,int n) /* ���ж϶Դ���*/ 
{
	int i,j;
	FILE *out;
	out=fopen("Grade.txt","w");
	for(i=0,j=0;i<n;i++)     /*�Եĸ���*/ 
		if(*(str1+i)==*(str2+i))
		j++;	
	fprintf(out,"Correct:%d (",j);
	for(i=0;i<n;i++)     /*�Ե����*/ 
	{
		if(*(str1+i)==*(str2+i))
		fprintf(out," %d ",(i+1));
	}
	fprintf(out,")\n");
 	fprintf(out,"Wrong:%d (",(n-j));
	for(i=0;i<n;i++)  /*������*/ 
	{
		if(*(str1+i)!=*(str2+i))
		fprintf(out," %d ",(i+1));
	}
	fprintf(out,")\n");
	fclose(out);
	printf("OK");
}
int count(char file[])  /*�������Ŀ����*/ 
{
    FILE *fp;
    char a;
    int x=0;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("read file failed��\n");
        exit(0);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);
        if(a=='\n')
            x++;
    }      
    fclose(fp);
    return x;
}
int main()
{
	char file1[10],file2[10],s[3];
	int *exe;
	int *an;
	printf("�������-a��-e\n");
	scanf("%s",s);
	if(!strcmp(s,"-e"))
	{
	printf("��������ϰ�ı���\n"); 
	scanf("%s",file1);
    }
    else if(!strcmp(s,"-a"))
    {
	printf("��������ı���\n"); 
	scanf("%s",file2);
	}
	else
	printf("ERROR!");
	printf("�������-a��-e\n");
	scanf("%s",s);
	if(!strcmp(s,"-e"))
	{
	printf("��������ϰ�ı���\n"); 
	scanf("%s",file1);
    }
    else if(!strcmp(s,"-a"))
    {
	printf("��������ı���\n"); 
	scanf("%s",file2);
	}
	else
	printf("ERROR!");
	int n;
	n=count(file1);
	exe=(int*)malloc(n*sizeof(int));
	an=(int*)malloc(n*sizeof(int));
	GetNum(file1,exe);
	GetNum(file2,an);
	PutResult(exe,an,n);
	return 0;
}
