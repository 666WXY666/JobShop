#include"main.h"
#include"main.h"
int end_time_min_rule()
{
	int i, min_time = conflict_product_ptr->time, min_time_optimal_num = 0;
	for (i = 1; i < conflict_product_subscript; i++)
	{
		if (min_time>(conflict_product_ptr + i)->end_time)
		{
			min_time = (conflict_product_ptr + i)->end_time;
			min_time_optimal_num = i;
		}
	}
	return min_time_optimal_num;
}
int end_time_min_rule1()
{
	int i, min_time = conflict_product_ptr->time, min_time_optimal_num = 0;
	for (i = 1; i < conflict_product_subscript; i++)
	{
		if (min_time >= (conflict_product_ptr + i)->end_time)
		{
			min_time = (conflict_product_ptr + i)->end_time;
			min_time_optimal_num = i;
		}
	}
	return min_time_optimal_num;
}

int time_min_rule()
{
	int i, min_time = conflict_product_ptr->time, min_time_optimal_num = 0;
	for (i = 1; i < conflict_product_subscript; i++)
	{
		if (min_time>(conflict_product_ptr + i)->time)
		{
			min_time = (conflict_product_ptr + i)->time;
			min_time_optimal_num = i;
		}
	}
	return min_time_optimal_num;
}
int time_min_rule1()
{
	int i, min_time = conflict_product_ptr->time, min_time_optimal_num = 0;
	for (i = 1; i < conflict_product_subscript; i++)
	{
		if (min_time >= (conflict_product_ptr + i)->time)
		{
			min_time = (conflict_product_ptr + i)->time;
			min_time_optimal_num = i;
		}
	}
	return min_time_optimal_num;
}
int time_max_rule()
{
	int i, max_time = conflict_product_ptr->time, max_time_optimal_num = 0;
	for (i = 1; i < conflict_product_subscript; i++)
	{
		if (max_time<(conflict_product_ptr + i)->time)
		{
			max_time = (conflict_product_ptr + i)->time;
			max_time_optimal_num = i;
		}
	}
	return max_time_optimal_num;
}
int time_max_rule2()
{
	int i, max_time = conflict_product_ptr->time, max_time_optimal_num = 0;
	for (i = 1; i < conflict_product_subscript; i++)
	{
		if (max_time <= (conflict_product_ptr + i)->time)
		{
			max_time = (conflict_product_ptr + i)->time;
			max_time_optimal_num = i;
		}
	}
	return max_time_optimal_num;
}
int least_work_remaining()
{
	int i, j, k, sumtime1 = 0, sumtime2 = 0, optimal_num1 = 0;
	j = (conflict_product_ptr)->shopnum;
	for (k = (conflict_product_ptr)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
	{
		sumtime1 = sumtime1 + (product_ptr + j - 1)->operations[k].time;
	}
	for (i = 1;i < conflict_product_subscript; i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		for (k = (conflict_product_ptr + i)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
		{
			sumtime2 = sumtime2 + (product_ptr + j - 1)->operations[k].time;
		}
		if (sumtime1 > sumtime2)
		{
			sumtime1 = sumtime2;
			optimal_num1 = i;
		}
		sumtime2 = 0;
	}
	return optimal_num1;
}
int least_work_remaining2()
{
	int i, j, k, sumtime1 = 0, sumtime2 = 0, optimal_num1 = 0;
	j = (conflict_product_ptr)->shopnum;
	for (k = (conflict_product_ptr)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
	{
		sumtime1 = sumtime1 + (product_ptr + j - 1)->operations[k].time;
	}
	for (i = 1;i < conflict_product_subscript; i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		for (k = (conflict_product_ptr + i)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
		{
			sumtime2 = sumtime2 + (product_ptr + j - 1)->operations[k].time;
		}
		if (sumtime1 >= sumtime2)
		{
			sumtime1 = sumtime2;
			optimal_num1 = i;
		}
		sumtime2 = 0;
	}
	return optimal_num1;
}
int most_work_remaining()
{
	int i, j, k, sumtime1 = 0, sumtime2 = 0, optimal_num2 = 0;
	j = (conflict_product_ptr)->shopnum;
	for (k = (conflict_product_ptr)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
	{
		sumtime1 = sumtime1 + (product_ptr + j - 1)->operations[k].time;
	}
	for (i = 1;i < conflict_product_subscript; i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		for (k = (conflict_product_ptr + i)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
		{
			sumtime2 = sumtime2 + (product_ptr + j - 1)->operations[k].time;
		}
		if (sumtime1 < sumtime2)
		{
			sumtime1 = sumtime2;
			optimal_num2 = i;
		}
		sumtime2 = 0;
	}
	return optimal_num2;
}
int most_work_remaining2()
{
	int i, j, k, sumtime1 = 0, sumtime2 = 0, optimal_num2 = 0;
	j = (conflict_product_ptr)->shopnum;
	for (k = (conflict_product_ptr)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
	{
		sumtime1 = sumtime1 + (product_ptr + j - 1)->operations[k].time;
	}
	for (i = 1;i < conflict_product_subscript; i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		for (k = (conflict_product_ptr + i)->procedure + 1;k <= (product_ptr + j - 1)->sum_operation;k++)
		{
			sumtime2 = sumtime2 + (product_ptr + j - 1)->operations[k].time;
		}
		if (sumtime1 <= sumtime2)
		{
			sumtime1 = sumtime2;
			optimal_num2 = i;
		}
		sumtime2 = 0;
	}
	return optimal_num2;
}
int fewest_number_of_operations_remaining()
{
	int i, j, k, optimal_num3 = 0, sumoperations1, sumoperations2;
	j = (conflict_product_ptr)->shopnum;
	sumoperations1 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr)->procedure;
	for (i = 1; i < conflict_product_subscript;i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		sumoperations2 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr + i)->procedure;
		if (sumoperations1 > sumoperations2)
		{
			sumoperations1 = sumoperations2;
			optimal_num3 = i;
		}
	}
	return optimal_num3;
}
int fewest_number_of_operations_remaining2()
{
	int i, j, k, optimal_num3 = 0, sumoperations1, sumoperations2;
	j = (conflict_product_ptr)->shopnum;
	sumoperations1 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr)->procedure;
	for (i = 1; i < conflict_product_subscript;i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		sumoperations2 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr + i)->procedure;
		if (sumoperations1 >= sumoperations2)
		{
			sumoperations1 = sumoperations2;
			optimal_num3 = i;
		}
	}
	return optimal_num3;
}
int most_number_of_operations_remaining()
{
	int i, j, k, optimal_num4 = 0, sumoperations1, sumoperations2;
	j = (conflict_product_ptr)->shopnum;
	sumoperations1 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr)->procedure;
	for (i = 1; i < conflict_product_subscript;i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		sumoperations2 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr + i)->procedure;
		if (sumoperations1 < sumoperations2)
		{
			sumoperations1 = sumoperations2;
			optimal_num4 = i;
		}
	}
	return optimal_num4;
}
int most_number_of_operations_remaining2()
{
	int i, j, k, optimal_num4 = 0, sumoperations1, sumoperations2;
	j = (conflict_product_ptr)->shopnum;
	sumoperations1 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr)->procedure;
	for (i = 1; i < conflict_product_subscript;i++)
	{
		j = (conflict_product_ptr + i)->shopnum;
		sumoperations2 = (product_ptr + j - 1)->sum_operation - (conflict_product_ptr + i)->procedure;
		if (sumoperations1 <= sumoperations2)
		{
			sumoperations1 = sumoperations2;
			optimal_num4 = i;
		}
	}
	return optimal_num4;
}



