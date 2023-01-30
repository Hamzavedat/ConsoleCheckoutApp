#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;
namespace Project{

	class Product{
		private:
			string name;
			string barcode;
			int number;
			float buy_price;
			float sale_price;
		public:
			Product();
			Product(string name, string barcode, int number, float buy_price, float sale_price);
			float get_buyprice();
			float get_saleprice();
			string get_name();
			string get_barcode();
			int get_number();
			void wrt_screen();
			void show_screen();
			void set_number(int number2);
			void set_pro(int number2, float buy_price2, float sale_price2);


	};

	const void upgrade_data(string data,Product Prd[] ,int size);

}

#endif