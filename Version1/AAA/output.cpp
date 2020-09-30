#include"main.h"
void output(product *completed_ptr)
{
	int i, j, k, m, min_start_time, n = 0;
	completed_operations = (OP*)malloc(sizeof(OP)*operation_num);
	machine_product_ptr = (machine_product*)malloc(sizeof(machine_product)*machine_num);
	for (k = 0; k < machine_num; k++)
	{
		m = 0;
		fprintf(output_ptr, "M%d", k);
		//printf("M%d", k);
		for (i = 0; i < product_num; i++)
		{
			for (j = 0; j < (completed_ptr + i)->sum_operation; j++)
			{
				if ((completed_ptr + i)->operations[j].machine == k)
				{
					(completed_operations + m)->end_time = (completed_ptr + i)->operations[j].end_time;
					(completed_operations + m)->start_time = (completed_ptr + i)->operations[j].start_time;
					(completed_operations + m)->shopnum = (completed_ptr + i)->operations[j].shopnum;
					(completed_operations + m)->procedure = (completed_ptr + i)->operations[j].procedure;
					(completed_operations + m)->machine = (completed_ptr + i)->operations[j].machine;
					(completed_operations + m)->flag = (completed_ptr + i)->operations[j].flag;
					(completed_operations + m)->time = (completed_ptr + i)->operations[j].time;
					m++;
				}
			}
		}
		for (i = 0; i < m - 1; i++)
		{
			for (j = 0; j < m - 1; j++)
			{
				if ((completed_operations + j)->start_time >(completed_operations + j + 1)->start_time)
				{
					temp_completed_operations.end_time = (completed_operations + j)->end_time;
					temp_completed_operations.shopnum = (completed_operations + j)->shopnum;
					temp_completed_operations.start_time = (completed_operations + j)->start_time;
					temp_completed_operations.procedure = (completed_operations + j)->procedure;
					(completed_operations + j)->end_time = (completed_operations + j + 1)->end_time;
					(completed_operations + j)->start_time = (completed_operations + j + 1)->start_time;
					(completed_operations + j)->shopnum = (completed_operations + j + 1)->shopnum;
					(completed_operations + j)->procedure = (completed_operations + j + 1)->procedure;
					(completed_operations + j + 1)->end_time = temp_completed_operations.end_time;
					(completed_operations + j + 1)->shopnum = temp_completed_operations.shopnum;
					(completed_operations + j + 1)->start_time = temp_completed_operations.start_time;
					(completed_operations + j + 1)->procedure = temp_completed_operations.procedure;
				}
			}
		}
		(machine_product_ptr + n)->machine_num = n;
		(machine_product_ptr + n)->sum_operation = m;
		(machine_product_ptr + n)->current_ptr = 0;
		for (i = 0; i < m; i++)
		{
			(machine_product_ptr + n)->operations[i].end_time = (completed_operations + i)->end_time;
			(machine_product_ptr + n)->operations[i].flag = (completed_operations + i)->flag;
			(machine_product_ptr + n)->operations[i].machine = (completed_operations + i)->machine;
			(machine_product_ptr + n)->operations[i].procedure = (completed_operations + i)->procedure;
			(machine_product_ptr + n)->operations[i].shopnum = (completed_operations + i)->shopnum;
			(machine_product_ptr + n)->operations[i].start_time = (completed_operations + i)->start_time;
			(machine_product_ptr + n)->operations[i].time = (completed_operations + i)->time;
			fprintf(output_ptr, " (%d,%d-%d,%d)", (completed_operations + i)->start_time, (completed_operations + i)->shopnum-1, (completed_operations + i)->procedure-1, (completed_operations + i)->end_time);
			/*printf(" (%d,%d-%d,%d)", (completed_operations + i)->start_time, (completed_operations + i)->shopnum, (completed_operations + i)->procedure, (completed_operations + i)->end_time);*/
		}
		n++;
		fprintf(output_ptr, "\n");
		/*printf("\n");*/
	}
	fprintf(output_ptr, "Time Used:%ds\nEnd Time:%d\n", used_time/1000, max_time);
	/*printf("Time Used:%dms\nEnd Time:%d\n", used_time, max_time);*/
}


