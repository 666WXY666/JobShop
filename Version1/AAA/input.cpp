#include"main.h"
void input()
{
	int i, j = 0, k;/*iΪ��Ʒ�Ĳ�Ʒ��ţ��ԡ�-1��������jΪ�����ļ�����*/
	//char flag = '0';/*��¼�����Ƿ���������ɣ���ɵı�־�ǡ�\n��*/
	original_ptr = (product*)malloc(sizeof(product)*product_num);
	operation_num = 0;
	for (i = 0; i < product_num; i++)
	{
		//��ע�͵��ĸò�����Ϊ�˷�ֹ��������������������������ļ�����ʱ���������һ���س�
		/*while (flag != '\n')
		{
		scanf("%d %d", &((original_ptr + i)->operations[j].machine), &((original_ptr + i)->operations[j].time));
		(original_ptr + i)->operations[j].shopnum = i + 1;
		(original_ptr + i)->operations[j].procedure = j + 1;
		(original_ptr + i)->operations[j].start_time = 0;
		(original_ptr + i)->operations[j].end_time = (original_ptr + i)->operations[j].time;
		(original_ptr + i)->operations[j].flag = 1;
		flag = getchar();
		j++;
		}*/
		//����Ĳ�����Ĭ�ϵĲ�����=�����������
		for (k = 0; k < machine_num; k++)
		{
			fscanf(input_ptr, "%d %d", &((original_ptr + i)->operations[j].machine), &((original_ptr + i)->operations[j].time));
			fgetc(input_ptr);
			/*scanf("%d %d", &((original_ptr + i)->operations[j].machine), &((original_ptr + i)->operations[j].time));*/
			(original_ptr + i)->operations[j].shopnum = i + 1;
			(original_ptr + i)->operations[j].procedure = j + 1;
			(original_ptr + i)->operations[j].start_time = 0;
			(original_ptr + i)->operations[j].end_time = (original_ptr + i)->operations[j].time;
			(original_ptr + i)->operations[j].flag = 1;
			/*flag = getchar();*/
			j++;
		}
		(original_ptr + i)->sum_operation = j;
		(original_ptr + i)->flag = 1;
		operation_num = operation_num + j;
		j = 0;
		/*flag = '0';*/
	}
}