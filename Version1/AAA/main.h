#pragma once
/////////////////////////////////////////////
/////////////////name:王兴宇//////////////////
////////////////time:2018-05-23//////////////
///////////////NO:2017211335/////////////////
//////////////team：8组///////////////////////
//////////////ver:α终极版/////////////////////
/////////////////////////////////////////////

////////////////////head///////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<graphics.h>
///////////////////////////////////////////////////

//////////////////////macro////////////////////////
#define LIMIT 3000/*程序运行的限制时间*/
#define screen_X  1520
#define screen_Y  810
#define rate  1
#define wait  1
#define times  1
#define position_X  15
#define position_Y  25
#define font_size 16
//////////////////////////////////////////////////

/////////////////////common////////////////////////
struct operation/*一个操作结构体*/
{
	int flag;/*记录该操作是否已完成,‘1’代表未完成，‘0’代表已完成,'-1'代表检修中*/
	int shopnum;/*第几号工件*/
	int procedure;/*第几道工序*/
	int machine;/*使用的机器编号*/
	int start_time;/*开始时间*/
	int time;/*该操作的加工时间*/
	int end_time;/*结束时间*/
};
typedef struct operation OP;/*重命名*/

struct product/*一个产品结构体*/
{
	int flag;/*记录该产品是否已完成,‘1’代表未完成，‘0’代表已完成*/
	int sum_operation;/*该产品的总操作数*/
	OP operations[50];/*该产品的操作*/
};
typedef struct product product;/*重命名*/

struct machine_product
{
	int machine_num;
	int sum_operation;
	int current_ptr;
	OP operations[50];
};
typedef struct machine_product machine_product;

extern int machine_num;/*机器数*/
extern int product_num;/*产品数*/
extern int operation_num;/*所有产品的总操作数*/
extern int optimal_num;/*最优操作解的下标*/
extern int conflict_product_subscript;/*记录冲突的操作结构体的最大下标*/
extern int max_time;/*所有产品都加工完成的总时间*/
extern int used_time;/*程序运行时间*/
extern int sum_repair_add_time;

extern product* product_ptr;/*产品结构体指针*/
extern product* original_ptr;/*存放原始产品结构体指针*/
extern product* completed_ptr;/*最终完成产品结构体指针*/
extern OP *active_product_ptr;/*可进行的操作结构体指针*/
extern OP *conflict_product_ptr;/*冲突的操作结构体指针*/
extern OP *completed_operations;/*输出时完成的操作*/
extern OP temp_completed_operations;/*临时变量*/
extern machine_product *machine_product_ptr;
extern FILE *input_ptr;
extern FILE *output_ptr;
extern FILE *repaired_output_ptr;
////////////////////////////////////////////////////////////////