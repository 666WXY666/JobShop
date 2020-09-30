#include"CORE.h"
//algorithm 1 process section
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