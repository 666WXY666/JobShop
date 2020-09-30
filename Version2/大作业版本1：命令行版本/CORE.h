/*program started at 8:50 April the twenty fifth*/
/*the deadline could be 8:49 May the twenty fifth*/
/*have a general finished in April the twenty ninth*/
/*first version completed at May the 8th 18:22*/
/*programming  language: C/C++*/
#define _EDITOR_GUAPI_
#define _VERSION_1_0_0_
#ifndef _CORE_H_
#define _CORE_H_
//headfile of the general function
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//quote of other standard headfiles are included here.
struct procedure
{
	int start_time;//new deftype
	int order;
	int time;
	int shopnumber;
	int potentional_time;
};
struct product
{
	int hadcostedtime_cludewating;
	int general_procedure;
	int current_procedure;
	procedure procedures[201];//we assume that the max procedure of a product is 30,we abandon 0
};//a product
struct CompletedProcedure
{
	int number_of_product;
	int order;
	int start_time;
	int end_time;
};//a procedure in shop
struct shop
{
	int general_procedure;//we may assume that we mover the ptr first then we record a procedure.
	int currenttime;
	CompletedProcedure Finished_procedure[201];
};




//output section:
void Greeting(void);
void P1(void);
void P_all_products(int product_number,product* ptr_to_product);
void P_all_shops(int shop_number,shop* ptr_to_shops);
void Ending(void);



//input section:
void S1(int* product_number,int* shop_number);
void S_of_products(product* ptr_to_product);



//initialize section:
product* creat_products(int product_number);
shop* creat_shops(int shop_number);
void Initialize_products(int products_number,product* ptr_to_product);
void Initialize_shops(int shop_number,shop* ptr_to_shop);



//refresh section:
//we add various algorithm and compare them to get  the shortest result.
void re_Initialize_products(int products_number,product* ptr_to_product);
void re_Initialize_shops(int shop_number,shop* ptr_to_shop);



//ordered traversal algorithm section:
void get_result1(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number);
void get_result3(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number);//converse order of getresult 1,they have the samilar algorithm



//potential value priority_search section:
void get_result2(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number);
int get_targeted_product(int product_number,product* ptr_to_product);//return the product number
//----
void get_result4(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number);//min_potential time priority
int get_targeted_product2(int product_number,product* ptr_to_product);
//----
void calculate_potential_value(product* ptr_to_products,int product_number);//belows:functions attach getresult2
int  search_repeat(product* ptr_to_products,int product_number,int number_of_shop);//if there is at least one repeat in the current floor ,reutn 1,else return 0
int find_max_potential_in_a_level(product* ptr_to_products,int product_number,int number_of_shop);//search the maximum potential time in the current floor,return its product number.



//current time priority:
void get_result5(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number);//current max_time priority
int get_targeted_product3(int product_number,product* ptr_to_product);
//----
void get_result6(product* ptr_to_products,shop* ptr_to_shops,int product_number,int shop_number);
int get_targeted_product4(int product_number,product* ptr_to_product);



//public function parts:
int serach_and_complete_a_procedure(product* ptr_to_products,int number_of_product,shop* ptr_to_shops);//basic search function,return the number of the shop
void addition(int deadline,int product_number,int currputed_shop_number,product* ptr_to_products,shop* ptr_to_shops);
int find_min_process_time(int* max,int size);//the return value had been processed as plus one 
int get_max_time(int shop_number,shop* ptr_to_shop);
#endif