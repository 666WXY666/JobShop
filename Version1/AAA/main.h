#pragma once
/////////////////////////////////////////////
/////////////////name:������//////////////////
////////////////time:2018-05-23//////////////
///////////////NO:2017211335/////////////////
//////////////team��8��///////////////////////
//////////////ver:���ռ���/////////////////////
/////////////////////////////////////////////

////////////////////head///////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<graphics.h>
///////////////////////////////////////////////////

//////////////////////macro////////////////////////
#define LIMIT 3000/*�������е�����ʱ��*/
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
struct operation/*һ�������ṹ��*/
{
	int flag;/*��¼�ò����Ƿ������,��1������δ��ɣ���0�����������,'-1'���������*/
	int shopnum;/*�ڼ��Ź���*/
	int procedure;/*�ڼ�������*/
	int machine;/*ʹ�õĻ������*/
	int start_time;/*��ʼʱ��*/
	int time;/*�ò����ļӹ�ʱ��*/
	int end_time;/*����ʱ��*/
};
typedef struct operation OP;/*������*/

struct product/*һ����Ʒ�ṹ��*/
{
	int flag;/*��¼�ò�Ʒ�Ƿ������,��1������δ��ɣ���0�����������*/
	int sum_operation;/*�ò�Ʒ���ܲ�����*/
	OP operations[50];/*�ò�Ʒ�Ĳ���*/
};
typedef struct product product;/*������*/

struct machine_product
{
	int machine_num;
	int sum_operation;
	int current_ptr;
	OP operations[50];
};
typedef struct machine_product machine_product;

extern int machine_num;/*������*/
extern int product_num;/*��Ʒ��*/
extern int operation_num;/*���в�Ʒ���ܲ�����*/
extern int optimal_num;/*���Ų�������±�*/
extern int conflict_product_subscript;/*��¼��ͻ�Ĳ����ṹ�������±�*/
extern int max_time;/*���в�Ʒ���ӹ���ɵ���ʱ��*/
extern int used_time;/*��������ʱ��*/
extern int sum_repair_add_time;

extern product* product_ptr;/*��Ʒ�ṹ��ָ��*/
extern product* original_ptr;/*���ԭʼ��Ʒ�ṹ��ָ��*/
extern product* completed_ptr;/*������ɲ�Ʒ�ṹ��ָ��*/
extern OP *active_product_ptr;/*�ɽ��еĲ����ṹ��ָ��*/
extern OP *conflict_product_ptr;/*��ͻ�Ĳ����ṹ��ָ��*/
extern OP *completed_operations;/*���ʱ��ɵĲ���*/
extern OP temp_completed_operations;/*��ʱ����*/
extern machine_product *machine_product_ptr;
extern FILE *input_ptr;
extern FILE *output_ptr;
extern FILE *repaired_output_ptr;
////////////////////////////////////////////////////////////////