#include"main.h"
void refresh_active_product(product *product_ptr, OP* conflict_product_ptr, OP *active_product_ptr, int optimal_num)
{
	int i/*计数器*/;
	int machine = (conflict_product_ptr + optimal_num)->machine, shopnum = (conflict_product_ptr + optimal_num)->shopnum, procedure = (conflict_product_ptr + optimal_num)->procedure, end_time = (conflict_product_ptr + optimal_num)->end_time;
	/*最优解的机器号，产品号，操作步骤号，结束时间*/
	for (i = 0; i <product_num; i++)
	{
		if ((active_product_ptr + i)->flag == 1)
		{
			if ((active_product_ptr + i)->shopnum != shopnum)
			{
				if ((active_product_ptr + i)->machine == machine && (active_product_ptr + i)->start_time<end_time)
				{
					(active_product_ptr + i)->start_time = end_time;
					(active_product_ptr + i)->end_time = (active_product_ptr + i)->time + end_time;
				}
			}
			else
			{
				if (procedure < (product_ptr + shopnum - 1)->sum_operation)
				{
					((active_product_ptr + i)->procedure)++;
					(active_product_ptr + i)->machine = (product_ptr + shopnum - 1)->operations[procedure].machine;
					(active_product_ptr + i)->time = (product_ptr + shopnum - 1)->operations[procedure].time;
					(active_product_ptr + i)->start_time = (product_ptr + shopnum - 1)->operations[procedure - 1].end_time;
					(active_product_ptr + i)->end_time = (active_product_ptr + i)->start_time + (active_product_ptr + i)->time;
				}
				else
				{
					(active_product_ptr + i)->flag = 0;
					(product_ptr + i)->operations[((conflict_product_ptr + optimal_num)->procedure) - 1].start_time = (active_product_ptr + i)->start_time;
					(product_ptr + i)->operations[((conflict_product_ptr + optimal_num)->procedure) - 1].end_time = (active_product_ptr + i)->end_time;
				}
			}
		}
	}
}
int refresh_product(product *product_ptr, int optimal_num, OP *conflict_product_ptr, OP *active_product_ptr)
{
	int i, j, k = 0, l, max_start_time = (conflict_product_ptr + optimal_num)->end_time, time = (conflict_product_ptr + optimal_num)->time, machine = (conflict_product_ptr + optimal_num)->machine;
	(product_ptr + ((conflict_product_ptr + optimal_num)->shopnum) - 1)->operations[((conflict_product_ptr + optimal_num)->procedure) - 1].flag = 0;
	if (((conflict_product_ptr + optimal_num)->procedure) == (product_ptr + ((conflict_product_ptr + optimal_num)->shopnum) - 1)->sum_operation)
	{
		(product_ptr + ((conflict_product_ptr + optimal_num)->shopnum) - 1)->flag = 0;
	}
	for (i = 0; i < product_num; i++)
	{
		if ((product_ptr + i)->flag == 1)
		{
			(product_ptr + i)->operations[((active_product_ptr + i)->procedure) - 1].flag = (active_product_ptr + i)->flag;
			(product_ptr + i)->operations[((active_product_ptr + i)->procedure) - 1].start_time = (active_product_ptr + i)->start_time;
			(product_ptr + i)->operations[((active_product_ptr + i)->procedure) - 1].end_time = (active_product_ptr + i)->end_time;
		}
	}
	for (i = 0; i < product_num; i++)
	{
		if ((product_ptr + i)->flag != 0)
		{
			k = 1;
		}
	}
	return k;
}