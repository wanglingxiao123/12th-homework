#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;//先修一栋楼 
	int ch;
	
	if((fp = fopen("hello.txt", "r")) == NULL)
	{
		printf("打开文件失败!\n");
		exit(EXIT_SUCCESS);
	}
	
	while ((ch = fgetc(fp)) != EOF)//楼中居民 
	{
		putchar(ch);
	}
	
	fclose(fp);
	
	return 0;
}
 
