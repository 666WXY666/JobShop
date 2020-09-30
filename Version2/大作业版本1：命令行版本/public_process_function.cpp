#include"CORE.h"
int serach_and_complete_a_procedure(product* ptr_to_products,int number_of_product,shop* ptr_to_shops)
{
	procedure cur=(ptr_to_products+number_of_product)->procedures[(ptr_to_products+number_of_product)->current_procedure];//copy the current processing procedure.
	int number_of_shop=cur.shopnumber;//get the information of job(number)
	//compare if shop is not in process when we want to begin the procedure,begin immidetatley, wait for the finish of the shop procedure otherwise.
	(ptr_to_shops+number_of_shop)->general_procedure++;
	(ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].number_of_product = number_of_product;//from which product
	(ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].order = (ptr_to_products+number_of_product)->current_procedure;//which procedure
	(ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].start_time = (ptr_to_shops+number_of_shop)->currenttime  >  (ptr_to_products+number_of_product)->hadcostedtime_cludewating ? (ptr_to_shops+number_of_shop)->currenttime:(ptr_to_products+number_of_product)->hadcostedtime_cludewating;
	(ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].end_time = (ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].start_time+cur.time;
	(ptr_to_shops+number_of_shop)->currenttime = (ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].end_time;
	(ptr_to_products+number_of_product)->hadcostedtime_cludewating = (ptr_to_shops+number_of_shop)->Finished_procedure[(ptr_to_shops+number_of_shop)->general_procedure].end_time;
	(ptr_to_products+number_of_product)->current_procedure++;
	return number_of_shop;
}
void addition(int deadline,int product_number,int currputed_shop_number,product* ptr_to_products,shop* ptr_to_shops)
{
	int flag=1;//to record if or not a procedure can be 
	while(flag==1)
	{
		flag=0;
		int i;//current product
		for(i=1;i<=product_number;i++)//addtion before deadline
		{
			if((ptr_to_products+i)->current_procedure<=(ptr_to_products+i)->general_procedure)//vaild product(undone)
			{
			    int number_of_shop=(ptr_to_products+i)->procedures[(ptr_to_products+i)->current_procedure].shopnumber;//shopnumber gotten
			    int time=(ptr_to_products+i)->procedures[(ptr_to_products+i)->current_procedure].time;
				int later_time= (ptr_to_shops+number_of_shop)->currenttime   >  (ptr_to_products+i)->hadcostedtime_cludewating ?(ptr_to_shops+number_of_shop)->currenttime:(ptr_to_products+i)->hadcostedtime_cludewating;
				if(number_of_shop!=currputed_shop_number&&(time+later_time<=deadline))
				{
					flag=1;
					if(search_repeat(ptr_to_products,product_number,number_of_shop)==0)//without repeat£¬process directly
					{
						serach_and_complete_a_procedure(ptr_to_products,i,ptr_to_shops);
					}
					else//has repeat,close the one who has the biggest max_potential time 
					    serach_and_complete_a_procedure(ptr_to_products,find_max_potential_in_a_level(ptr_to_products,product_number,number_of_shop),ptr_to_shops);
				}
			}
		}
			
	}
	return ;
}
int find_min_process_time(int* max,int size)//to fine the best end time,
{
	int min=9999999;
	int i=0;
	int locator;
	for(i=0;i<size;i++)
	{
		if(max[i]<min)
		{
			min=max[i];
			locator=i;
		}
	}
	return locator+1;
}
int get_max_time(int shop_number,shop* ptr_to_shop)//find the ending time
{
	int max_time=0;
	int number_of_shop=-1;
	int i;
	for(i=1;i<=shop_number;i++)
	{
		if((ptr_to_shop+i)->currenttime>max_time)
		{
			max_time=(ptr_to_shop+i)->currenttime;
			number_of_shop=i;
		}
	}
	return number_of_shop;
}