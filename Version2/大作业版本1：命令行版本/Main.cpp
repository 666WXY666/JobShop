#include"CORE.h"
//attention: every produre in a product needs be process in a different shop,which means a lot of simplification to our algorithm and usage of space
//main section: control section:
int main(int argc,const char* argv[])
{
	int max[6];//0-5,attention!
	clock_t start_time,end_time;
	Greeting();
	P1();
	int shop_number;
	int product_number;


	S1(&product_number,&shop_number);


	product* ptr_to_products=creat_products(product_number);//we use (ptr_to_product+1)----(ptr_to_product+n)to express every product ,
	shop* ptr_to_shops=creat_shops(shop_number);//same usage;


	Initialize_products(product_number,ptr_to_products);
	Initialize_shops(shop_number,ptr_to_shops);


	S_of_products(ptr_to_products);
	start_time=clock();
	calculate_potential_value(ptr_to_products,product_number);

    get_result1(ptr_to_products,ptr_to_shops,product_number,shop_number);//pre order BSF
	max[0]=(ptr_to_shops+get_max_time(shop_number,ptr_to_shops))->currenttime;

	re_Initialize_products(product_number,ptr_to_products);
	re_Initialize_shops(shop_number,ptr_to_shops);

    get_result2(ptr_to_products,ptr_to_shops,product_number,shop_number);//max potential value priority
    max[1]=(ptr_to_shops+get_max_time(shop_number,ptr_to_shops))->currenttime;

	re_Initialize_products(product_number,ptr_to_products);
	re_Initialize_shops(shop_number,ptr_to_shops);

	get_result3(ptr_to_products,ptr_to_shops,product_number,shop_number);//post order BSF
	max[2]=(ptr_to_shops+get_max_time(shop_number,ptr_to_shops))->currenttime;

	re_Initialize_products(product_number,ptr_to_products);
	re_Initialize_shops(shop_number,ptr_to_shops);

	get_result4(ptr_to_products,ptr_to_shops,product_number,shop_number);//min_potential value priority
	max[3]=(ptr_to_shops+get_max_time(shop_number,ptr_to_shops))->currenttime;

	re_Initialize_products(product_number,ptr_to_products);
	re_Initialize_shops(shop_number,ptr_to_shops);

	get_result5(ptr_to_products,ptr_to_shops,product_number,shop_number);
	max[4]=(ptr_to_shops+get_max_time(shop_number,ptr_to_shops))->currenttime;

	re_Initialize_products(product_number,ptr_to_products);
	re_Initialize_shops(shop_number,ptr_to_shops);

	get_result6(ptr_to_products,ptr_to_shops,product_number,shop_number);
	max[5]=(ptr_to_shops+get_max_time(shop_number,ptr_to_shops))->currenttime;

	re_Initialize_products(product_number,ptr_to_products);
	re_Initialize_shops(shop_number,ptr_to_shops);
	//close the best method
	int K=find_min_process_time(max,6);
	switch(K)
	{
        case 1:get_result1(ptr_to_products,ptr_to_shops,product_number,shop_number);break;
        case 2:get_result2(ptr_to_products,ptr_to_shops,product_number,shop_number);break;
        case 3:get_result3(ptr_to_products,ptr_to_shops,product_number,shop_number);break;
		case 4:get_result4(ptr_to_products,ptr_to_shops,product_number,shop_number);break;
		case 5:get_result5(ptr_to_products,ptr_to_shops,product_number,shop_number);break;
		case 6:get_result6(ptr_to_products,ptr_to_shops,product_number,shop_number);break;
	}
	//compare
	end_time=clock();
	printf("the algorithm takes %f seconds to solve this problem.\n",(float)(end_time-start_time)/1000);
	P_all_shops(shop_number,ptr_to_shops);
	printf("End%d\n",max[K-1]);
	Ending();

	free(ptr_to_products);
	free(ptr_to_shops);
	return 0;
}