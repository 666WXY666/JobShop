#include"main.h"
void input()
{
	int i, j = 0, k;/*i为产品的产品序号，以‘-1’结束，j为操作的计数器*/
	//char flag = '0';/*记录该行是否已输入完成，完成的标志是‘\n’*/
	original_ptr = (product*)malloc(sizeof(product)*product_num);
	operation_num = 0;
	for (i = 0; i < product_num; i++)
	{
		//已注释掉的该部分是为了防止操作数不满机器数的情况，但文件输入时，需在最后补一个回车
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
		//下面的部分是默认的操作数=机器数的情况
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