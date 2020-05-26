#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Player
{
    int no;
	char name[16];
	float health;
	char magic; 
};


int main(void)
{
        FILE *fp;
        struct Player *p1;

        // 为结构体分配堆内存空间
        p1 = (struct Player *)malloc(sizeof (struct Player));

        if (p1 == NULL)
        {
                printf("内存分配失败！\n");
                exit(EXIT_FAILURE);
        }

        // 填充结构体数据
        p1->no = 1;
        strcpy(p1->name, "Mike");
        p1->magic = 'a';
        p1->health = 10.5;
        

        if ((fp = fopen("file.txt", "w")) == NULL)
        {
                printf("打开文件失败！\n");
                exit(EXIT_SUCCESS);
        }

        // 将整个结构体写入文件中
        fwrite(p1, sizeof(struct Player), 1, fp);

        // 写入完成，关闭保存文件
        fclose(fp);

        // 重新打开文件，检测是否成功写入数据
        if ((fp = fopen("file.txt", "r")) == NULL)
        {
                printf("打开文件失败！\n");
                exit(EXIT_SUCCESS);
        }

        // 在文件中读取结构体并打印到屏幕上
        fread(p1, sizeof(struct Player), 1, fp);

		printf("编号：%d\n", p1->no);
        printf("用户名：%s\n", p1->name);
	    printf("魔力值：%c\n", p1->magic);
		printf("生命值:%.2f\n", p1->health);
	

        fclose(fp);

        return 0;
}                           
