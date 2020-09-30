#include"CORE.h"
product* creat_products(int product_number)
{
	product* ptr_to_products=(product*)malloc((product_number+1)*sizeof(product));
	return ptr_to_products;
}
shop* creat_shops(int shop_number)
{
	shop* ptr_to_shops=(shop*)malloc((shop_number+1)*sizeof(shop));
	return ptr_to_shops;
}
void Initialize_products(int products_number,product* ptr_to_product)
{
	int i=1;
	for(i=1;i<=products_number;i++)
	{
		(ptr_to_product+i)->hadcostedtime_cludewating=0;
		(ptr_to_product+i)->general_procedure=0;
		(ptr_to_product+i)->current_procedure=1;
	}
	return ;
}
void Initialize_shops(int shop_number,shop* ptr_to_shop)
{
	int i=1;
	for(i=1;i<=shop_number;i++)
	{
		(ptr_to_shop+i)->general_procedure=0;//initialize;+then restore.
		(ptr_to_shop+i)->currenttime=0;
	}
	return ;
}
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
void calculate_potential_value(product* ptr_to_products,int product_number)
{
	int i;
	for(i=1;i<=product_number;i++)
	{
		int ii;
		for(ii=(ptr_to_products+i)->general_procedure;ii>=1;ii--)
		{
			if(ii==(ptr_to_products+i)->general_procedure)
				(ptr_to_products+i)->procedures[ii].potentional_time=(ptr_to_products+i)->procedures[ii].time;
			else
				(ptr_to_products+i)->procedures[ii].potentional_time=(ptr_to_products+i)->procedures[ii].time+(ptr_to_products+i)->procedures[ii+1].potentional_time;
		}
	}
	return ;
}
int get_targeted_product(int product_number,product* ptr_to_product)//potential priority select. attach to R2
{
	int number_of_product=-1;
	int max_potential_value=-1;
	int i;//for search.
	for(i=1;i<=product_number;i++)
	{
		if((ptr_to_product+i)->current_procedure<=(ptr_to_product+i)->general_procedure)
		{
			if(max_potential_value<(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].potentional_time)
			{
				max_potential_value=(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].potentional_time;
				number_of_product=i;
			}
		}
	}
	return number_of_product;
}//correct
int search_repeat(product* ptr_to_products,int product_number,int number_of_shop)//check repeat.
{
	int i;
	int repeat=0;
	for(i=1;i<=product_number;i++)
	{
		if((ptr_to_products+i)->procedures[(ptr_to_products+i)->current_procedure].shopnumber==number_of_shop)
		{
			repeat++;
		}
	}
	if(repeat==1)
		return 0;
	else
		return 1;
}
int find_max_potential_in_a_level(product* ptr_to_products,int product_number,int number_of_shop)
{
	int number_of_product=-1;
	int max_potential_value=-1;
	int i;
	for(i=1;i<=product_number;i++)
	{
		if((ptr_to_products+i)->current_procedure<=(ptr_to_products+i)->general_procedure)
		{
			if((ptr_to_products+i)->procedures[(ptr_to_products+i)->current_procedure].shopnumber==number_of_shop)//if is this kind
		    {
			    if( max_potential_value<(ptr_to_products+i)->procedures[(ptr_to_products+i)->current_procedure].potentional_time)
			    {
					max_potential_value=(ptr_to_products+i)->procedures[(ptr_to_products+i)->current_procedure].potentional_time;
					number_of_product=i;
			    }
		    }
		}
	}
	return number_of_product;
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
void re_Initialize_products(int products_number,product* ptr_to_product)//return to after scan
{
	int i=1;
	for(i=1;i<=products_number;i++)
	{
		(ptr_to_product+i)->hadcostedtime_cludewating=0;
		(ptr_to_product+i)->current_procedure=1;
	}
	return ;
}
void re_Initialize_shops(int shop_number,shop* ptr_to_shop)//return to after scan
{
	int i=1;
	for(i=1;i<=shop_number;i++)
	{
		(ptr_to_shop+i)->general_procedure=0;
		(ptr_to_shop+i)->currenttime=0;
	}
	return ;
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
int get_targeted_product2(int product_number,product* ptr_to_product)//potential priority select.(miniumprioty)attach to R4
{
	int number_of_product=-1;
	int min_potential_value=9999999;
	int i;//for search.
	for(i=1;i<=product_number;i++)
	{
		if((ptr_to_product+i)->current_procedure<=(ptr_to_product+i)->general_procedure)
		{
			if(min_potential_value>(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].potentional_time)
			{
				min_potential_value=(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].potentional_time;
				number_of_product=i;
			}
		}
	}
	return number_of_product;
}
int get_targeted_product3(int product_number,product* ptr_to_product) //attach to R5
{
	int number_of_product=-1;
	int min_time=9999999;
	int i;//for search.
	for(i=1;i<=product_number;i++)
	{
		if((ptr_to_product+i)->current_procedure<=(ptr_to_product+i)->general_procedure)
		{
			if(min_time>(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].time)
			{
				min_time=(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].time;
				number_of_product=i;
			}
		}
	}
	return number_of_product;
}
int get_targeted_product4(int product_number,product* ptr_to_product)//attach to R6
{
	int number_of_product=-1;
	int max_time=-1;
	int i;//for search.
	for(i=1;i<=product_number;i++)
	{
		if((ptr_to_product+i)->current_procedure<=(ptr_to_product+i)->general_procedure)
		{
			if(max_time<(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].time)
			{
				max_time=(ptr_to_product+i)->procedures[(ptr_to_product+i)->current_procedure].time;
				number_of_product=i;
			}
		}
	}
	return number_of_product;
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