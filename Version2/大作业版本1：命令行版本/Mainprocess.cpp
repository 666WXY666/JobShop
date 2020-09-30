#include"CORE.h"
void get_result1(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number)
{
	int number_of_product;
	int flag=1;//the ending station:£¬after search the current level£¬there is at most 0 procedure.
	while(flag==1)
	{
		flag=0;
		for(number_of_product=1;number_of_product<=product_number;number_of_product++)
		{
			if((ptr_to_products+number_of_product)->current_procedure<=(ptr_to_products+number_of_product)->general_procedure)
			{
				flag=1;
				serach_and_complete_a_procedure(ptr_to_products,number_of_product,ptr_to_shops);
			}
		}
	}
	return ;
}
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
void get_result3(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number)
{
	int number_of_product;
	int flag=1;
	while(flag==1)
	{
		flag=0;
		for(number_of_product=product_number;number_of_product>=1;number_of_product--)
		{
			if((ptr_to_products+number_of_product)->current_procedure<=(ptr_to_products+number_of_product)->general_procedure)
			{
				flag=1;
				serach_and_complete_a_procedure(ptr_to_products,number_of_product,ptr_to_shops);
			}
		}
	}
	return ;
}
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