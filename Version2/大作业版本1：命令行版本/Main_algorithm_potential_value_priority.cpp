#include"CORE.h"
//algorithm II process section.
//maxium priority
void get_result2(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number)//potential time priority search method,but it is not the best at most of time.
{
	int number_of_product;
	number_of_product=get_targeted_product(product_number,ptr_to_products);
    while(number_of_product!=-1)
	{
		int number_of_shop;
	    number_of_shop=serach_and_complete_a_procedure(ptr_to_products,number_of_product,ptr_to_shops);
		//before deadline, we can make some addtion to reduce the  general process time
		int deadline=(ptr_to_shops+number_of_shop)->currenttime;
		addition(deadline,product_number,number_of_shop,ptr_to_products,ptr_to_shops);
		number_of_product=get_targeted_product(product_number,ptr_to_products);
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



//minium priority
void get_result4(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number)
{
	int number_of_product;
	number_of_product=get_targeted_product2(product_number,ptr_to_products);
    while(number_of_product!=-1)
	{
		int number_of_shop;
	    number_of_shop=serach_and_complete_a_procedure(ptr_to_products,number_of_product,ptr_to_shops);
		//before deadline, we can make some addtion to reduce the  general process time
		int deadline=(ptr_to_shops+number_of_shop)->currenttime;
		addition(deadline,product_number,number_of_shop,ptr_to_products,ptr_to_shops);
		number_of_product=get_targeted_product2(product_number,ptr_to_products);
	}
	return ;
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



//public funcion in this part:
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