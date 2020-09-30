#include"main.h"
int RANDOM_rule()
{
	srand(time(NULL));
	return (rand() / RAND_MAX)*(conflict_product_subscript - 1);
}
int NINQ_rule()
{
	int NINQ_optimal_num = 0, sum_num = 0, min_num = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_num++;
		}
	}
	min_num = sum_num;
	sum_num = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_num++;
			}
		}
		if (min_num>sum_num)
		{
			min_num = sum_num;
			NINQ_optimal_num = i;
		}
		sum_num = 0;
	}
	return NINQ_optimal_num;
}
int NINQ_rule1()
{
	int NINQ_optimal_num = 0, sum_num = 0, min_num = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_num++;
		}
	}
	min_num = sum_num;
	sum_num = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_num++;
			}
		}
		if (min_num >= sum_num)
		{
			min_num = sum_num;
			NINQ_optimal_num = i;
		}
		sum_num = 0;
	}
	return NINQ_optimal_num;
}
int NINQ_rule2()
{
	int NINQ_optimal_num = 0, sum_num = 0, min_num = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_num++;
		}
	}
	min_num = sum_num;
	sum_num = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_num++;
			}
		}
		if (min_num<sum_num)
		{
			min_num = sum_num;
			NINQ_optimal_num = i;
		}
		sum_num = 0;
	}
	return NINQ_optimal_num;
}
int NINQ_rule3()
{
	int NINQ_optimal_num = 0, sum_num = 0, min_num = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_num++;
		}
	}
	min_num = sum_num;
	sum_num = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_num++;
			}
		}
		if (min_num <= sum_num)
		{
			min_num = sum_num;
			NINQ_optimal_num = i;
		}
		sum_num = 0;
	}
	return NINQ_optimal_num;
}
int WINQ_rule()
{
	int WINQ_optimal_num = 0, sum_time = 0, min_time = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_time = sum_time + (active_product_ptr + j)->time;
		}
	}
	min_time = sum_time;
	sum_time = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_time = sum_time + (active_product_ptr + j)->time;
			}
		}
		if (min_time>sum_time)
		{
			min_time = sum_time;
			WINQ_optimal_num = i;
		}
		sum_time = 0;
	}
	return WINQ_optimal_num;
}
int WINQ_rule1()
{
	int WINQ_optimal_num = 0, sum_time = 0, min_time = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_time = sum_time + (active_product_ptr + j)->time;
		}
	}
	min_time = sum_time;
	sum_time = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_time = sum_time + (active_product_ptr + j)->time;
			}
		}
		if (min_time >= sum_time)
		{
			min_time = sum_time;
			WINQ_optimal_num = i;
		}
		sum_time = 0;
	}
	return WINQ_optimal_num;
}
int WINQ_rule2()
{
	int WINQ_optimal_num = 0, sum_time = 0, min_time = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_time = sum_time + (active_product_ptr + j)->time;
		}
	}
	min_time = sum_time;
	sum_time = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_time = sum_time + (active_product_ptr + j)->time;
			}
		}
		if (min_time<sum_time)
		{
			min_time = sum_time;
			WINQ_optimal_num = i;
		}
		sum_time = 0;
	}
	return WINQ_optimal_num;
}
int WINQ_rule3()
{
	int WINQ_optimal_num = 0, sum_time = 0, min_time = 0, machine = 0, i, j, k = 1;
	for (i = 0; k&&i < conflict_product_subscript; i++)
	{
		if (((conflict_product_ptr + i)->procedure) != (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation)
		{
			machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure)].machine;
			k = 0;
		}
	}
	for (j = 0; j < product_num; j++)
	{
		if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i - 1)->shopnum)
		{
			sum_time = sum_time + (active_product_ptr + j)->time;
		}
	}
	min_time = sum_time;
	sum_time = 0;
	for (; i < conflict_product_subscript; i++)
	{
		machine = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[((conflict_product_ptr + i)->procedure - 1)].machine;
		for (j = 0; j < product_num; j++)
		{
			if ((active_product_ptr + j)->machine == machine && (active_product_ptr + j)->flag == 1 && (active_product_ptr + j)->shopnum != (conflict_product_ptr + i)->shopnum)
			{
				sum_time = sum_time + (active_product_ptr + j)->time;
			}
		}
		if (min_time <= sum_time)
		{
			min_time = sum_time;
			WINQ_optimal_num = i;
		}
		sum_time = 0;
	}
	return WINQ_optimal_num;
}