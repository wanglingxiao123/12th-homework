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

        // Ϊ�ṹ�������ڴ�ռ�
        p1 = (struct Player *)malloc(sizeof (struct Player));

        if (p1 == NULL)
        {
                printf("�ڴ����ʧ�ܣ�\n");
                exit(EXIT_FAILURE);
        }

        // ���ṹ������
        p1->no = 1;
        strcpy(p1->name, "Mike");
        p1->magic = 'a';
        p1->health = 10.5;
        

        if ((fp = fopen("file.txt", "w")) == NULL)
        {
                printf("���ļ�ʧ�ܣ�\n");
                exit(EXIT_SUCCESS);
        }

        // �������ṹ��д���ļ���
        fwrite(p1, sizeof(struct Player), 1, fp);

        // д����ɣ��رձ����ļ�
        fclose(fp);

        // ���´��ļ�������Ƿ�ɹ�д������
        if ((fp = fopen("file.txt", "r")) == NULL)
        {
                printf("���ļ�ʧ�ܣ�\n");
                exit(EXIT_SUCCESS);
        }

        // ���ļ��ж�ȡ�ṹ�岢��ӡ����Ļ��
        fread(p1, sizeof(struct Player), 1, fp);

		printf("��ţ�%d\n", p1->no);
        printf("�û�����%s\n", p1->name);
	    printf("ħ��ֵ��%c\n", p1->magic);
		printf("����ֵ:%.2f\n", p1->health);
	

        fclose(fp);

        return 0;
}                           
