#include"CORE.h"
void Greeting(void)
{
	printf("Welcome to the Job Shop system\n");
	return ;
}
void P1(void)
{
	printf("Please input the number of products and shops:\n");
	return ;
}
void P_all_products(int product_number,product* ptr_to_product)//just for test, debug version.
{
	int i=1;
	printf("product inforamtion:\n");
	for(i=1;i<=product_number;i++)
	{
		printf("ID:%d\nnow its No.%d procedure is processing.\n",i,(ptr_to_product+i)->current_procedure);
		int ii;
		for(ii=1;ii<=(ptr_to_product+i)->general_procedure;ii++)
			printf("procedure %d: time: %d shopnumber: %d start time:%d potential time:%d\n",ii,(ptr_to_product+i)->procedures[ii].time,(ptr_to_product+i)->procedures[ii].shopnumber,(ptr_to_product+i)->procedures[ii].start_time,(ptr_to_product+i)->procedures[ii].potentional_time);
	}
	printf("Information of products outputs completed\n");
	return ;
}
void P_all_shops(int shop_number,shop* ptr_to_shops)
{
	int current_shop;
	int current_procedure;
	for(current_shop=1;current_shop<=shop_number;current_shop++)
	{
		printf("M%d",current_shop);
		for(current_procedure=1;current_procedure<=(ptr_to_shops+current_shop)->general_procedure;current_procedure++)
	        printf("(%d,%d-%d,%d)",(ptr_to_shops+current_shop)->Finished_procedure[current_procedure].start_time,(ptr_to_shops+current_shop)->Finished_procedure[current_procedure].number_of_product,(ptr_to_shops+current_shop)->Finished_procedure[current_procedure].order,(ptr_to_shops+current_shop)->Finished_procedure[current_procedure].end_time);
		printf("\n");
	}
	return ;
}
void Ending(void)
{
	printf("all processes end,thank you for your use.\n");
	return ;
}//mark of the ending
