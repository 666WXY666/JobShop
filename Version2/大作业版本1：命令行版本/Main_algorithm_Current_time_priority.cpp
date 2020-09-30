#include"CORE.h"
//algorithm III process section
void get_result5(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number)
{
	int number_of_product;
	number_of_product=get_targeted_product3(product_number,ptr_to_products);
    while(number_of_product!=-1)
	{
		int number_of_shop;
	    number_of_shop=serach_and_complete_a_procedure(ptr_to_products,number_of_product,ptr_to_shops);
		//before deadline, we can make some addtion to reduce the  general process time
		int deadline=(ptr_to_shops+number_of_shop)->currenttime;
		addition(deadline,product_number,number_of_shop,ptr_to_products,ptr_to_shops);
		number_of_product=get_targeted_product3(product_number,ptr_to_products);
	}
	return ;
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



void get_result6(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number)//max_time(current) priority
{
	int number_of_product;
	number_of_product=get_targeted_product4(product_number,ptr_to_products);
    while(number_of_product!=-1)
	{
		int number_of_shop;
	    number_of_shop=serach_and_complete_a_procedure(ptr_to_products,number_of_product,ptr_to_shops);
		//before deadline, we can make some addtion to reduce the  general process time
		int deadline=(ptr_to_shops+number_of_shop)->currenttime;
		addition(deadline,product_number,number_of_shop,ptr_to_products,ptr_to_shops);
		number_of_product=get_targeted_product4(product_number,ptr_to_products);
	}
	return ;

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