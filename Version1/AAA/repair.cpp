#include"main.h"
//////////////////////////////////////////////////
/////////////////name:wangxingyu/////////////////
////////////////time:2018-03-24/////////////////
///////////////NO.2017211335///////////////////
//////////////////////////////////////////////
void repair(int repair_machine, int repair_time,int repair_start_time)
{
	int i, j, k = 1, add_time = 0, m, k2 = 1;
	for ( i = 0; k&&i < (machine_product_ptr+repair_machine)->sum_operation; i++)
	{
		if (repair_start_time<= (machine_product_ptr + repair_machine)->operations[0].start_time)
		{
			if (repair_start_time + repair_time<= (machine_product_ptr + repair_machine)->operations[0].start_time)
			{
				add_time = 0;
			}
			else
			{
				add_time = repair_start_time + repair_time - (machine_product_ptr + repair_machine)->operations[0].start_time;
			}
			for ( j = (machine_product_ptr + repair_machine)->sum_operation; j >0; j--)
			{
				(machine_product_ptr + repair_machine)->operations[j] = (machine_product_ptr + repair_machine)->operations[j - 1];
			}
			(machine_product_ptr + repair_machine)->operations[0].flag = -1;
			(machine_product_ptr + repair_machine)->operations[0].machine = repair_machine;
			(machine_product_ptr + repair_machine)->operations[0].procedure = -1;
			(machine_product_ptr + repair_machine)->operations[0].shopnum = -1;
			(machine_product_ptr + repair_machine)->operations[0].start_time = repair_start_time;
			(machine_product_ptr + repair_machine)->operations[0].end_time = repair_start_time + repair_time;
			(machine_product_ptr + repair_machine)->operations[0].time = repair_time;
			(machine_product_ptr + repair_machine)->sum_operation++;
			k = 0;
		}
		if (i!= (machine_product_ptr + repair_machine)->sum_operation-1)
		{
			if (repair_start_time>(machine_product_ptr + repair_machine)->operations[i].start_time&&repair_start_time<(machine_product_ptr + repair_machine)->operations[i].end_time)
			{
				repair_start_time = (machine_product_ptr + repair_machine)->operations[i].end_time;
				if (repair_start_time + repair_time <= (machine_product_ptr + repair_machine)->operations[i + 1].start_time)
				{
					add_time = 0;
				}
				else
				{
					add_time = repair_start_time + repair_time - (machine_product_ptr + repair_machine)->operations[i + 1].start_time;
				}
				for (j = (machine_product_ptr + repair_machine)->sum_operation; j > i + 1; j--)
				{
					(machine_product_ptr + repair_machine)->operations[j] = (machine_product_ptr + repair_machine)->operations[j - 1];
				}
				(machine_product_ptr + repair_machine)->operations[i + 1].flag = -1;
				(machine_product_ptr + repair_machine)->operations[i + 1].machine = repair_machine;
				(machine_product_ptr + repair_machine)->operations[i + 1].procedure = -1;
				(machine_product_ptr + repair_machine)->operations[i + 1].shopnum = -1;
				(machine_product_ptr + repair_machine)->operations[i + 1].start_time = repair_start_time;
				(machine_product_ptr + repair_machine)->operations[i + 1].end_time = repair_start_time + repair_time;
				(machine_product_ptr + repair_machine)->operations[i + 1].time = repair_time;
				(machine_product_ptr + repair_machine)->sum_operation++;
				k = 0;
			}
			else if (repair_start_time >= (machine_product_ptr + repair_machine)->operations[i].end_time&&repair_start_time <= (machine_product_ptr + repair_machine)->operations[i + 1].start_time)
			{
				if (repair_start_time + repair_time <= (machine_product_ptr + repair_machine)->operations[i + 1].start_time)
				{
					add_time = 0;
				}
				else
				{
					add_time = repair_start_time + repair_time - (machine_product_ptr + repair_machine)->operations[i + 1].start_time;
				}
				for (j = (machine_product_ptr + repair_machine)->sum_operation; j > i + 1; j--)
				{
					(machine_product_ptr + repair_machine)->operations[j] = (machine_product_ptr + repair_machine)->operations[j - 1];
				}
				(machine_product_ptr + repair_machine)->operations[i + 1].flag = -1;
				(machine_product_ptr + repair_machine)->operations[i + 1].machine = repair_machine;
				(machine_product_ptr + repair_machine)->operations[i + 1].procedure = -1;
				(machine_product_ptr + repair_machine)->operations[i + 1].shopnum = -1;
				(machine_product_ptr + repair_machine)->operations[i + 1].start_time = repair_start_time;
				(machine_product_ptr + repair_machine)->operations[i + 1].end_time = repair_start_time + repair_time;
				(machine_product_ptr + repair_machine)->operations[i + 1].time = repair_time;
				(machine_product_ptr + repair_machine)->sum_operation++;
				k = 0;
			}
		}
		if (i == (machine_product_ptr + repair_machine)->sum_operation - 1)
		{
			if (repair_start_time>(machine_product_ptr + repair_machine)->operations[i].start_time&&repair_start_time<(machine_product_ptr + repair_machine)->operations[i].end_time)
			{
				repair_start_time = (machine_product_ptr + repair_machine)->operations[i].end_time;
			}
			else if (repair_start_time >= (machine_product_ptr + repair_machine)->operations[i].end_time)
			{
				repair_start_time = repair_start_time;
			}
			add_time = 0;
			(machine_product_ptr + repair_machine)->operations[i + 1].flag = -1;
			(machine_product_ptr + repair_machine)->operations[i + 1].machine = repair_machine;
			(machine_product_ptr + repair_machine)->operations[i + 1].procedure = -1;
			(machine_product_ptr + repair_machine)->operations[i + 1].shopnum = -1;
			(machine_product_ptr + repair_machine)->operations[i + 1].start_time = repair_start_time;
			(machine_product_ptr + repair_machine)->operations[i + 1].end_time = repair_start_time + repair_time;
			(machine_product_ptr + repair_machine)->operations[i + 1].time = repair_time;
			(machine_product_ptr + repair_machine)->sum_operation++;
			k = 0;
		}
	}
	for ( i = 0; i < machine_num; i++)
	{
		k = 1;
		for ( j = 0; k&&j < (machine_product_ptr + i)->sum_operation; j++)
		{
			if (repair_start_time <= (machine_product_ptr + i)->operations[j].start_time&& (machine_product_ptr + i)->operations[j].flag!=-1)
			{
				for ( m = j; m < (machine_product_ptr + i)->sum_operation; m++)
				{
					(machine_product_ptr + i)->operations[m].start_time = (machine_product_ptr + i)->operations[m].start_time + add_time;
					(machine_product_ptr + i)->operations[m].end_time = (machine_product_ptr + i)->operations[m].end_time + add_time;
				}
				k = 0;
			}
		}
	}
	sum_repair_add_time = sum_repair_add_time + add_time;
}