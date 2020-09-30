#include"main.h"
int least_time()
{
	int i, k, temptime = 0, mintime, optimal_num;
	for (i = 0;i<conflict_product_subscript;i++)
	{
		for (k = 0;k<(product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation;k++)
		{
			temptime = temptime + (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[k].time;
		}
		if (i == 0)
		{
			mintime = temptime;
			optimal_num = i;
			temptime = 0;
		}
		else
		{
			if (temptime<mintime)
			{
				mintime = temptime;
				optimal_num = i;
				temptime = 0;
			}
		}
	}
	return optimal_num;
}

int most_time()
{
	int i, k, temptime = 0, maxtime, optimal_num;
	for (i = 0;i<conflict_product_subscript;i++)
	{
		for (k = 0;k<(product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation;k++)
		{
			temptime = temptime + (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->operations[k].time;
		}
		if (i == 0)
		{
			maxtime = temptime;
			optimal_num = i;
			temptime = 0;
		}
		else
		{
			if (temptime>maxtime)
			{
				maxtime = temptime;
				optimal_num = i;
				temptime = 0;
			}
		}
	}
	return optimal_num;
}

int least_operation()
{
	int i, k, tempoperation = 0, minoperation, optimal_num;
	for (i = 0;i<conflict_product_subscript;i++)
	{
		tempoperation = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation;
		if (i == 0)
		{
			minoperation = tempoperation;
			optimal_num = i;
			tempoperation = 0;
		}
		else
		{
			if (minoperation>tempoperation)
			{
				minoperation = tempoperation;
				optimal_num = i;
				tempoperation = 0;
			}
		}
	}
	return optimal_num;
}

int most_operation()
{
	int i, k, tempoperation = 0, maxoperation, optimal_num;
	for (i = 0;i<conflict_product_subscript;i++)
	{
		tempoperation = (product_ptr + ((conflict_product_ptr + i)->shopnum) - 1)->sum_operation;
		if (i == 0)
		{
			maxoperation = tempoperation;
			optimal_num = i;
			tempoperation = 0;
		}
		else
		{
			if (maxoperation<tempoperation)
			{
				maxoperation = tempoperation;
				optimal_num = i;
				tempoperation = 0;
			}
		}
	}
	return optimal_num;
}

int FCFS()
{
	int i, firsttime, temptime = 0, optimal;
	for (i = 0;i<conflict_product_subscript;i++)
	{
		if ((conflict_product_ptr + i)->procedure - 1 == 1)
		{
			temptime = (product_ptr + (conflict_product_ptr + i)->shopnum - 1)->operations[(conflict_product_ptr + i)->procedure - 1].end_time;
		}
		else
		{
			temptime = (product_ptr + (conflict_product_ptr + i)->shopnum - 1)->operations[(conflict_product_ptr + i)->procedure - 2].end_time;
		}
		if (i == 0)
		{
			firsttime = temptime;
			optimal = i;
		}
		else
		{
			if (temptime<firsttime)
			{
				firsttime = temptime;
				optimal = i;
			}
		}
	}
	return optimal;
}
//
//int RANDOM_rule1()
//{
//	int i,k=0;
//	float *a,min=1;
//	a=malloc(sizeof(float)*conflict_product_subscript);
//	srand(time(NULL));
//	for(i=0;i<conflict_product_subscript;i++)
//	{
//		a[i]=(float)rand()/RAND_MAX;
//	}
//	for(i=0;i<conflict_product_subscript;i++)
//	{
//		if(a[i]<=min)
//		{
//			min=a[i];
//			k=i;
//		}
//	}
//	return k; 
//}
