#pragma once
/////////////////////////////////////////////
/////////////////name:王兴宇//////////////////
////////////////time:2018-05-23//////////////
///////////////NO:2017211335/////////////////
//////////////team：8组///////////////////////
//////////////ver:α终极版/////////////////////
/////////////////////////////////////////////

/////////////////////////create.c///////////////////////
void initialize_product();/*用于初始化产品结构体数组*/
void initialize_completed_product();/*用于初始化最终完成的产品结构体数组*/

OP *initialize_active_product();/*初始化可进行的操作集函数的原型，作用：分配空间并把所有记录了该操作是否已删除的‘flag’重置为‘1’(未删除)*/
void create_active_product(product *product_ptr, OP *active_product_ptr);/*首次创建可进行的操作集函数的原型，作用：把所有产品的首次操作加入可进行的操作集*/

OP *initialize_conflict_product();/*初始化冲突的操作集函数的原型，作用：分配空间*/
void create_conflict_product(OP *active_product_ptr, OP *conflict_product_ptr, int *conflict_product_subscript_address);
/*创建每个冲突的操作集函数的原型，作用：把所有可操作集中与结束时间最短的操作机器冲突的操作取出和它本身一起组成冲突操作集，并更改该冲突操作集的最大下标*/
///////////////////////////////////////////////////////


