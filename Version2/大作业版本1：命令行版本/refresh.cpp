#include"CORE.h"
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