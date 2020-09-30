#include"main.h"
#include"repair.h"
////////////////////////////////////////////////
///////////////name:wangxingyu/////////////////
//////////////time:2018-03-24/////////////////
/////////////NO.2017211335///////////////////
////////////////////////////////////////////
void draw_bar()
{
	int i, m, j;
	setbkcolor(WHITE);
	setcolor(BLACK);
	setfillcolor(WHITE);
	bar(0, 0, screen_X, position_Y + 60 * machine_num - 1);
	setcolor(RED);
	setfontbkcolor(WHITE);
	setfont(font_size, 0, "宋体");
	xyprintf(position_X + 1, position_Y + 60 * machine_num-20, " 时间   机器号(状态)       工件号-工序号       该状态已保持时间,该状态剩余时间");
	xyprintf(screen_X / 2 + 1, position_Y + 60 * machine_num-20, "检修指令：");
	xyprintf(screen_X / 2 + 1, position_Y + 60 * machine_num-20 + font_size, "检修指令序号 检修机器 检修时间");
	setcolor(BLACK);
	line(position_X - 1, 0, position_X - 1, screen_Y - 2);
	line(position_X - 1, 0, screen_X - position_X + 1, 0);
	line(position_X - 1, position_Y + 60 * machine_num-23, screen_X - position_X + 1, position_Y + 60 * machine_num-23);
	line(screen_X / 2, position_Y + 60 * machine_num - 23, screen_X / 2, screen_Y - 2);
	line(screen_X - position_X + 1, 0, screen_X - position_X + 1, screen_Y - 2);
	line(position_X - 1, screen_Y - 2, screen_X - position_X + 1, screen_Y - 2);
	line(screen_X / 2 + 244, position_Y + 60 * machine_num - 23, screen_X / 2 + 244, screen_Y - 2);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(13, 0, "宋体");
	for ( i = 0; i < product_num; i++)
	{
		for (j = 0; j < machine_num; j++)
		{
			xyprintf(screen_X / 2 + 248+50*j, position_Y + 60 * machine_num+13*i-20, "%2d%3d",(original_ptr+i)->operations[j].machine, (original_ptr + i)->operations[j].time);
		}
	}
	setfont(font_size, 0, "宋体");
	for ( i = 0; i < machine_num; i++)
	{
		xyprintf(1, position_Y + 60 * i-1, "%d",i);
	}
	for (m = 0; m < machine_num; m++)
	{
		for (i = 0; i < (machine_product_ptr + m)->sum_operation; i++)
		{
			if ((machine_product_ptr + m)->operations[i].flag==-1)
			{
				setfillcolor(RED);
			}
			else
			{
				setfillcolor(GREEN);
			}
			bar(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60, position_X + (machine_product_ptr + m)->operations[i].end_time * times, position_Y + m * 60 + 12);
			rectangle(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60, position_X + (machine_product_ptr + m)->operations[i].end_time * times, position_Y + m * 60 + 12);
			setcolor(RED);
			setfontbkcolor(WHITE);
			setfont(12, 0, "宋体");
			if (i % 2 == 0)
			{
				xyprintf(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60 - 12, "%d-%d", (machine_product_ptr + m)->operations[i].start_time, (machine_product_ptr + m)->operations[i].end_time);
				if ((machine_product_ptr + m)->operations[i].flag!=-1)
				{
					xyprintf(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60 - 24, "(%d,%d)", (machine_product_ptr + m)->operations[i].shopnum - 1, (machine_product_ptr + m)->operations[i].procedure - 1);
				}
				else
				{
					xyprintf(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60 - 24, "检修");
				}
			}
			else
			{
				xyprintf(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60 + 12, "%d-%d", (machine_product_ptr + m)->operations[i].start_time, (machine_product_ptr + m)->operations[i].end_time);
				if ((machine_product_ptr + m)->operations[i].flag!=-1)
				{
					xyprintf(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60 + 24, "(%d,%d)", (machine_product_ptr + m)->operations[i].shopnum - 1, (machine_product_ptr + m)->operations[i].procedure - 1);
				}
				else
				{
					xyprintf(position_X + (machine_product_ptr + m)->operations[i].start_time * times, position_Y + m * 60 + 24, "检修");
				}
			}
			setcolor(BLACK);
		}
	}
}
void run()
{
	int i, j = 0, m, n, sum1 = 0, sum2 = 0, temp, l, count = 0, flag1 = 1, flag2 = 0, flag3 = 0;
	//char c[10];
	key_msg k = { 0 };
	setcolor(RED);
	setfontbkcolor(WHITE);
	setfont(font_size, 0, "宋体");
	xyprintf(position_X + 1, position_Y + 60 * machine_num-20, " 时间   机器号(状态)       工件号-工序号       该状态已保持时间,该状态剩余时间");
	for (i = 0; i <= max_time+sum_repair_add_time; i = i + rate * wait)
	{
		xyprintf(screen_X / 2 + 1, position_Y + 60 * machine_num -20, "检修指令：");
		xyprintf(screen_X / 2 + 1, position_Y + 60 * machine_num -20 + font_size, "检修指令序号 检修机器 检修时间");
		if (kbhit())
		{
			/*inputbox_getline("检修指令", "请输入检修指令：(格式为 C机器号 检修时间，按回车确认)", c, 10);*/
			k = getkey();
			if (k.key == 67)
			{
				flag3 = 1;
			}
			if (flag3)
			{
				if (k.key!=67)
				{
					if (k.key == 32)
					{
						flag1 = 0;
						flag2 = 1;
					}
					if (k.key == 13)
					{
						flag2 = 0;
						count++;
					}
					if (flag1&&k.key != 13 && k.key != 32)
					{
						sum1 = sum1 * 10 + (k.key - 48);
					}
					if (flag2&&k.key != 13 && k.key != 32)
					{
						sum2 = sum2 * 10 + (k.key - 48);
					}
				}
			}
			/*sum1 = atoi(c + 1);
			temp = sum1;
			for (j = 0; temp>0; j++)
			{
				temp = temp / 10;
			}
			if (sum1 == 0)
			{
				j = 1;
			}
			sum2 = atoi(c + j + 1);*/
			if (flag1==0&&flag2==0)
			{
				xyprintf(screen_X / 2 + 1, position_Y + 60 * machine_num + 1 + (count + 1)*font_size - 20, "%12d%9d%9d", count, sum1, sum2);
				repair(sum1, sum2, i);
				draw_bar();
				flag1 = 1;
				flag2 = 0;
				flag3 = 0;
				sum1 = 0;
				sum2 = 0;
				setfillcolor(BLUE);
				for (l = 0; l < machine_num; l++)
				{
					bar(position_X, position_Y + l * 60 + 4, position_X + i * times, position_Y + l * 60 + 8);
				}
			}
			fflush(stdin);
		}
		for (m = 0; m < machine_num; m++)
		{
			setfillcolor(WHITE);
			bar(position_X + 1, font_size + 2 + position_Y + 60 * machine_num + m * font_size-20, screen_X / 2, font_size + 2 + position_Y + 60 * machine_num + 15 + m * font_size-20);
			setcolor(RED);
			setfontbkcolor(WHITE);
			setfont(font_size, 0, "宋体");
			xyprintf(position_X + 1, position_Y + 60 * machine_num-20, " 时间   机器号(状态)       工件号-工序号       该状态已保持时间,该状态剩余时间");
			if ((i - rate * wait < (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time&&i>(machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time) || i == (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time)
			{
				if ((machine_product_ptr + m)->current_ptr < (machine_product_ptr + m)->sum_operation - 1)
				{
					(machine_product_ptr + m)->current_ptr++;
				}
			}
			if ((machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].flag==-1)
			{
				xyprintf(position_X + 2, font_size + 1 + position_Y + 60 * machine_num + m * font_size-20, "%5d %3d(检修)                无-无%27d,%d", i, m, i - (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].start_time, (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time - i);
			}
			else
			{
				if ((machine_product_ptr + m)->current_ptr > 0)
				{
					if (i >= (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr - 1].end_time&&i < (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].start_time)
					{
						xyprintf(position_X + 2, font_size + 1 + position_Y + 60 * machine_num + m * font_size-20, "%5d %3d(空闲)                无-无%27d,%d", i, m, i - (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr - 1].end_time, (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].start_time - i);
					}
				}
				if (i >= 0 && i<(machine_product_ptr + m)->operations[0].start_time)
				{
					xyprintf(position_X + 2, font_size + 1 + position_Y + 60 * machine_num + m * font_size-20, "%5d %3d(空闲)                无-无%27d,%d", i, m, i, (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].start_time - i);
				}
				if (i >= (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].start_time&&i <= (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time)
				{
					xyprintf(position_X + 2, font_size + 1 + position_Y + 60 * machine_num + m * font_size-20, "%5d %3d(加工) %17d-%d%28d,%d", i, m, (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].shopnum - 1, (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].procedure - 1, i - (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].start_time, (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time - i);
				}
				if (i >(machine_product_ptr + m)->operations[(machine_product_ptr + m)->sum_operation - 1].end_time)
				{
					xyprintf(position_X + 2, font_size + 1 + position_Y + 60 * machine_num + m * font_size-20, "%5d %3d(空闲)                无-无%27d,无", i, m, i - (machine_product_ptr + m)->operations[(machine_product_ptr + m)->current_ptr].end_time);
				}
			}
			setcolor(BLUE);
			for (n = 0; n < times*wait*rate; n++)
			{
				line(position_X +n + i * times, position_Y + m * 60 + 4, position_X + n + i * times, position_Y + m * 60 + 8);
			}
			setcolor(RED);
		}
		Sleep(wait * 1000);
	}
}