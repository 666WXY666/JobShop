#include"main.h"
#include"create.h"
#include"input.h"
#include"output.h"
#include"refresh.h"
#include"visual interface.h"
#include"schedule1.h"
#include"schedule2.h"
#include"schedule3.h"
/////////////////////////////////////////////////////////////////
int machine_num;/*机器数*/
int product_num;/*产品数*/
int operation_num;/*所有产品的总操作数*/
int optimal_num;/*最优操作解的下标*/
int conflict_product_subscript;/*记录冲突的操作结构体的最大下标*/
int max_time;/*所有产品都加工完成的总时间*/
int used_time;/*程序运行时间*/
int sum_repair_add_time = 0;

product* product_ptr;/*产品结构体指针*/
product* original_ptr;/*存放原始产品结构体指针*/
product* completed_ptr;/*最终完成产品结构体指针*/
OP *active_product_ptr;/*可进行的操作结构体指针*/
OP *conflict_product_ptr;/*冲突的操作结构体指针*/
OP *completed_operations;/*输出时完成的操作*/
OP temp_completed_operations;/*临时变量*/
machine_product *machine_product_ptr;
FILE *input_ptr, *output_ptr, *repaired_output_ptr;
////////////////////////////////////////////////////////////////
int main()
{
	//////////////////////定义和初始化///////////////////////
	int k, i, n = 27, m, j, algorithm_time;
	input_ptr = fopen("input.txt", "r");
	output_ptr = fopen("output1.txt", "w");
	repaired_output_ptr = fopen("output2.txt", "w");
	time_t start_t, end_t;
	used_time = 0;
	max_time = 0;
	fscanf(input_ptr, "%d %d", &product_num, &machine_num);
	fgetc(input_ptr);
	//scanf("%d %d", &product_num, &machine_num);
	/////////////////////////////////////////////////////
	//////////////////////操作集合初始化////////////////////
	conflict_product_ptr = initialize_conflict_product();
	active_product_ptr = initialize_active_product();
	/////////////////////////////////////////////////////
	///////////////////////输入///////////////////////////
	input();
	/////////////////////////////////////////////////////
	//////////////////////第一个规则///////////////////////
	start_t = clock();
	k = 1;
	initialize_product();
	create_active_product(product_ptr, active_product_ptr);
	while (k == 1)
	{
		create_conflict_product(active_product_ptr, conflict_product_ptr, &conflict_product_subscript);
		optimal_num = end_time_min_rule();
		refresh_active_product(product_ptr, conflict_product_ptr, active_product_ptr, optimal_num);
		k = refresh_product(product_ptr, optimal_num, conflict_product_ptr, active_product_ptr);
	}
	for (m = 0; m < product_num; m++)
	{
		if ((product_ptr + m)->operations[((product_ptr + m)->sum_operation) - 1].end_time>max_time)
		{
			max_time = (product_ptr + m)->operations[((product_ptr + m)->sum_operation) - 1].end_time;
		}
	}
	initialize_completed_product();
	///////////////////////////////////////////////////////
	///////////////////////其他的规则////////////////////////
	for (i = 1; i < n; i++)/*n为算法规则数*/
	{
		k = 1;
		algorithm_time = 0;
		free(product_ptr);
		initialize_product();
		create_active_product(product_ptr, active_product_ptr);
		while (k == 1)
		{
			create_conflict_product(active_product_ptr, conflict_product_ptr, &conflict_product_subscript);
			switch (i)
			{
			case 1:optimal_num = time_min_rule1();break;
			case 2:optimal_num = time_max_rule();break;
			case 3:optimal_num = time_max_rule2();break;
			case 4:optimal_num = least_work_remaining();break;
			case 5:optimal_num = least_work_remaining2();break;
			case 6:optimal_num = most_work_remaining();break;
			case 7:optimal_num = most_work_remaining2();break;
			case 8:optimal_num = fewest_number_of_operations_remaining();break;
			case 9:optimal_num = fewest_number_of_operations_remaining2();break;
			case 10:optimal_num = most_number_of_operations_remaining();break;
			case 11:optimal_num = most_number_of_operations_remaining2();break;
			case 12:optimal_num = time_min_rule();break;
			case 13:optimal_num = end_time_min_rule1();break;
			case 14:optimal_num = NINQ_rule();break;
			case 15:optimal_num = NINQ_rule1();break;
			case 16:optimal_num = NINQ_rule2();break;
			case 17:optimal_num = NINQ_rule3();break;
			case 18:optimal_num = WINQ_rule();break;
			case 19:optimal_num = WINQ_rule1();break;
			case 20:optimal_num = WINQ_rule2();break;
			case 21:optimal_num = WINQ_rule3();break;
			case 22:optimal_num = least_time();break;
			case 23:optimal_num = most_time();break;
			case 24:optimal_num = least_operation();break;
			case 25:optimal_num = most_operation();break;
			case 26:optimal_num = FCFS();break;
			}
			refresh_active_product(product_ptr, conflict_product_ptr, active_product_ptr, optimal_num);
			k = refresh_product(product_ptr, optimal_num, conflict_product_ptr, active_product_ptr);
		}
		for (m = 0; m < product_num; m++)
		{
			if ((product_ptr + m)->operations[((product_ptr + m)->sum_operation) - 1].end_time>algorithm_time)
			{
				algorithm_time = (product_ptr + m)->operations[((product_ptr + m)->sum_operation) - 1].end_time;
			}
		}
		if (max_time>algorithm_time)
		{
			max_time = algorithm_time;
			initialize_completed_product();
		}
	}
	//////////////////////////////////////////////////////
	//////////////////////随机规则//////////////////////////
	while ((clock() - start_t)<LIMIT)/*限制运行时间在LIMIT毫秒内*/
	{
		k = 1;
		algorithm_time = 0;
		free(product_ptr);
		initialize_product();
		create_active_product(product_ptr, active_product_ptr);
		while (k == 1)
		{
			create_conflict_product(active_product_ptr, conflict_product_ptr, &conflict_product_subscript);
			optimal_num = RANDOM_rule();/*随机规则*/
										/*optimal_num = RANDOM_rule1();*//*另一个随机规则*/
			refresh_active_product(product_ptr, conflict_product_ptr, active_product_ptr, optimal_num);
			k = refresh_product(product_ptr, optimal_num, conflict_product_ptr, active_product_ptr);
		}
		for (m = 0; m < product_num; m++)
		{
			if ((product_ptr + m)->operations[((product_ptr + m)->sum_operation) - 1].end_time>algorithm_time)
			{
				algorithm_time = (product_ptr + m)->operations[((product_ptr + m)->sum_operation) - 1].end_time;
			}
		}
		if (max_time>algorithm_time)
		{
			max_time = algorithm_time;
			initialize_completed_product();
		}
	}
	end_t = clock();
	used_time = end_t - start_t;
	////////////////////////////////////////////////////////
	/////////////////////////输出////////////////////////////
	output(completed_ptr);
	initgraph(screen_X, screen_Y);
	draw_bar();
	run();
	for ( i = 0; i < machine_num; i++)
	{
		fprintf(repaired_output_ptr, "M%d", i);
		for ( j = 0; j < (machine_product_ptr+i)->sum_operation; j++)
		{
			if ((machine_product_ptr + i)->operations[j].flag==-1)
			{
				fprintf(repaired_output_ptr, " (%d,检修,%d)", (machine_product_ptr + i)->operations[j].start_time, (machine_product_ptr + i)->operations[j].end_time);
			}
			else
			{
				fprintf(repaired_output_ptr, " (%d,%d-%d,%d)", (machine_product_ptr + i)->operations[j].start_time, (machine_product_ptr + i)->operations[j].shopnum - 1, (machine_product_ptr + i)->operations[j].procedure - 1, (machine_product_ptr + i)->operations[j].end_time);
			}
		}
		fprintf(repaired_output_ptr, "\n");
	}
	fprintf(repaired_output_ptr, "Time Used:%ds\nEnd Time:%d\n", used_time/1000, max_time+sum_repair_add_time);
	Sleep(5000);
	closegraph();
	////////////////////////////////////////////////////////
	/////////////////////////释放////////////////////////////
	free(completed_ptr);
	free(original_ptr);
	free(product_ptr);
	free(active_product_ptr);
	free(conflict_product_ptr);
	free(completed_operations);
	free(machine_product_ptr);
	fclose(input_ptr);
	fclose(output_ptr);
	fclose(repaired_output_ptr);
	////////////////////////////////////////////////////////
	return 0;
}