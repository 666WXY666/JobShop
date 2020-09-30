#include"main.h"
void initialize_product()
{
	int i, j;
	product_ptr = (product*)malloc(sizeof(product)*product_num);
	for (i = 0; i < product_num; i++)
	{
		(product_ptr + i)->flag = (original_ptr + i)->flag;
		(product_ptr + i)->sum_operation = (original_ptr + i)->sum_operation;
		for (j = 0; j < (product_ptr + i)->sum_operation; j++)
		{
			(product_ptr + i)->operations[j].end_time = (original_ptr + i)->operations[j].end_time;
			(product_ptr + i)->operations[j].flag = (original_ptr + i)->operations[j].flag;
			(product_ptr + i)->operations[j].machine = (original_ptr + i)->operations[j].machine;
			(product_ptr + i)->operations[j].procedure = (original_ptr + i)->operations[j].procedure;
			(product_ptr + i)->operations[j].shopnum = (original_ptr + i)->operations[j].shopnum;
			(product_ptr + i)->operations[j].start_time = (original_ptr + i)->operations[j].start_time;
			(product_ptr + i)->operations[j].time = (original_ptr + i)->operations[j].time;
		}
	}
}
void initialize_completed_product()
{
	int i, j;
	completed_ptr = (product*)malloc(sizeof(product)*product_num);
	for (i = 0; i < product_num; i++)
	{
		(completed_ptr + i)->flag = (product_ptr + i)->flag;
		(completed_ptr + i)->sum_operation = (product_ptr + i)->sum_operation;
		for (j = 0; j < (completed_ptr + i)->sum_operation; j++)
		{
			(completed_ptr + i)->operations[j].end_time = (product_ptr + i)->operations[j].end_time;
			(completed_ptr + i)->operations[j].flag = (product_ptr + i)->operations[j].flag;
			(completed_ptr + i)->operations[j].machine = (product_ptr + i)->operations[j].machine;
			(completed_ptr + i)->operations[j].procedure = (product_ptr + i)->operations[j].procedure;
			(completed_ptr + i)->operations[j].shopnum = (product_ptr + i)->operations[j].shopnum;
			(completed_ptr + i)->operations[j].start_time = (product_ptr + i)->operations[j].start_time;
			(completed_ptr + i)->operations[j].time = (product_ptr + i)->operations[j].time;
		}
	}
}
OP *initialize_active_product()
{
	int i;/*计数器*/
	active_product_ptr = (OP*)malloc(sizeof(OP)* product_num);
	return active_product_ptr;
}
void create_active_product(product *product_ptr, OP *active_product_ptr)
{
	int i;/*计数器和计录上一次可以的操作在结构体数组中的位置*/
	for (i = 0; i < product_num; i++)
	{
		(active_product_ptr + i)->flag = 1;
		(active_product_ptr + i)->end_time = (product_ptr + i)->operations[0].end_time;
		(active_product_ptr + i)->machine = (product_ptr + i)->operations[0].machine;
		(active_product_ptr + i)->procedure = (product_ptr + i)->operations[0].procedure;
		(active_product_ptr + i)->shopnum = (product_ptr + i)->operations[0].shopnum;
		(active_product_ptr + i)->start_time = (product_ptr + i)->operations[0].start_time;
		(active_product_ptr + i)->time = (product_ptr + i)->operations[0].time;
	}
}
OP *initialize_conflict_product()
{
	int i;/*计数器*/
	conflict_product_ptr = (OP*)malloc(sizeof(OP)*product_num);
	for (i = 0; i < product_num; i++)
	{
		(conflict_product_ptr + i)->flag = 1;
	}
	return conflict_product_ptr;
}
void create_conflict_product(OP *active_product_ptr, OP *conflict_product_ptr, int *conflict_product_subscript_address)
{
	int i/*计数器*/, j = 0/*计数器和计录上一次冲突的操作的结构体数组的下标*/, min_time = 0/*操作能最先完成的时间*/, machine = 0/*能最先完成的操作的机器*/, k = 1;
	*conflict_product_subscript_address = 0;
	for (i = 0; k&&i < product_num; i++)
	{
		if ((active_product_ptr + i)->flag == 1)
		{
			min_time = (active_product_ptr + i)->end_time;
			machine = (active_product_ptr + i)->machine;
			k = 0;
		}
	}
	for (; i < product_num; i++)
	{
		if ((active_product_ptr + i)->end_time < min_time && (active_product_ptr + i)->flag == 1)
		{
			machine = (active_product_ptr + i)->machine;
			min_time = (active_product_ptr + i)->end_time;
		}
	}
	for (i = 0; i < product_num; i++)
	{
		if ((active_product_ptr + i)->machine == machine && (active_product_ptr + i)->flag == 1)
		{
			(conflict_product_ptr + j)->end_time = (active_product_ptr + i)->end_time;
			(conflict_product_ptr + j)->machine = (active_product_ptr + i)->machine;
			(conflict_product_ptr + j)->procedure = (active_product_ptr + i)->procedure;
			(conflict_product_ptr + j)->shopnum = (active_product_ptr + i)->shopnum;
			(conflict_product_ptr + j)->start_time = (active_product_ptr + i)->start_time;
			(conflict_product_ptr + j)->time = (active_product_ptr + i)->time;
			j++;
		}
	}
	*(conflict_product_subscript_address) = j;
}