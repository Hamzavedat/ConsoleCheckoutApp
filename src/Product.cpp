#include <iostream>
#include <string>
#include <fstream>
#include "..\include\Product.h"
#include <sstream>

using namespace std;

namespace Project{

	Product::Product():name(""),barcode(""),number(0),buy_price(0),sale_price(0)
	{

	}

	Product::Product(string name, string barcode, int number, float buy_price, float sale_price):
					name(name),barcode(barcode),number(number),buy_price(buy_price),sale_price(sale_price)
	{

	}

	//Sorgu programi icin kullanilmakta ve gelis fiyati harici bilgier ekrana yansitilmaktadir
	void Product::wrt_screen(){

		cout<<"Product Name: "<<name<<endl;
		cout<<"Product Barcode: "<<barcode<<endl;
		cout<<"Product Number: "<<number<<endl;
		cout<<"Product Price: "<<sale_price<<endl;
	}

	void Product::show_screen(){
		cout<<"Product Name: "<<name<<endl;
		cout<<"Product Barcode: "<<barcode<<endl;
		cout<<"Product Number: "<<number<<endl;
		cout<<"Product Buy Price: "<<buy_price<<endl;		
		cout<<"Product Sale Price: "<<sale_price<<endl;
	}

	string Product::get_barcode(){
		return barcode;
	}

	int Product::get_number(){
		return number;
	}

	float Product::get_saleprice(){
		return sale_price;
	}

	float Product::get_buyprice(){
		return buy_price;
	}

	string Product::get_name(){
		return name;
	}

	void Product::set_number(int number2){
		number = number2;
	}

	void Product::set_pro(int number2, float buy_price2, float sale_price2){
		number = number2;
		buy_price = buy_price2;
		sale_price = sale_price2;
	}
	const void upgrade_data(string data,Product Prd[] ,int size){
		string line, line2, line3;
		ofstream temp("../data/temp.txt",ios::app);
	 	ifstream file(data);
		for(int k =0; k<=size; k++){
			temp<<Prd[k].get_barcode()<<'-'<<Prd[k].get_name()<<'-'
				<<Prd[k].get_number()<<'-'<<Prd[k].get_buyprice()<<'-'<<Prd[k].get_saleprice()<<endl;		

		}	 	
	 	while(!file.eof()){
			getline(file, line3);
			istringstream line2(line3);
			getline(line2, line, '-');
			int y = 1;
			for(int k =0; k<=size; k++){
				
				if(Prd[k].get_barcode() == line){
					y = 0;
				}

			}
			if(y){
				temp<<line3<<endl;
			}
				
		}
		temp.close();
		file.close();
		cout<<"Updating files..\n";
		remove(data);
		rename("../data/temp.txt",data);
		}
	}