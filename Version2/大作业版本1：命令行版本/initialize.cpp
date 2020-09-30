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