#include"CORE.h"
//input process section
void S1(int* product_number,int* shop_number)
{
	scanf("%d %d",product_number,shop_number);
	getchar();
	printf("scan process completed.\n");
	return ;
}
void S_of_products(product* ptr_to_products)
{
	printf("Please input the detailed information of producs:\n");
	int n;//the products
	scanf("%d",&n);
	getchar();
	while(n!=-1)
	{
		int time;
		int shopnumber=0;
		char mark='1';
		while(mark!='\n')
		{
		    scanf("(%d,%d)",&time,&shopnumber);
			scanf("%c",&mark);
			(ptr_to_products+n)->general_procedure++;
			(ptr_to_products+n)->procedures[(ptr_to_products+n)->general_procedure].order=(ptr_to_products+n)->general_procedure;
			(ptr_to_products+n)->procedures[(ptr_to_products+n)->general_procedure].shopnumber=shopnumber;
			(ptr_to_products+n)->procedures[(ptr_to_products+n)->general_procedure].time=time;
			(ptr_to_products+n)->procedures[(ptr_to_products+n)->general_procedure].start_time=0;
		}
		scanf("%d",&n);
		if(n==-1)
			break;
	    scanf("(%d,%d)",&time,&shopnumber);
		scanf("%c",&mark);
	}
	getchar();
	printf("scan process completed.\n");
	return ;
}