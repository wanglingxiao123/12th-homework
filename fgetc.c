#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;//����һ��¥ 
	int ch;
	
	if((fp = fopen("hello.txt", "r")) == NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(EXIT_SUCCESS);
	}
	
	while ((ch = fgetc(fp)) != EOF)//¥�о��� 
	{
		putchar(ch);
	}
	
	fclose(fp);
	
	return 0;
}
 
