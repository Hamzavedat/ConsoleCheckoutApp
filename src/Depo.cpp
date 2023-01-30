#include <iostream>
#include <string>
#include <fstream>
#include "..\include\Product.h"
#include <sstream>

using namespace std;
using namespace Project;

Product create_product(string barcode);

int main(){
	int j = 0;
 	string barcode;
	string line;
	string line2;
	string name;
	Product Prd[100];
	int number;
	float buy_price;
	float sale_price;

	while(j < 100){

 		cout<<"Barcode(Press q for quit):\n";
 		cin>>barcode;//Giris yapilacak urun barkodu alinacak
 		if (barcode == "q"){
 			break;
 		}	

		ifstream file("../data/data.txt");
		
		while(1){

			getline(file, line);
			istringstream line2(line);
			getline(line2, line, '-');
			if (line== barcode){	
				getline(line2, line, '-');
				name = line;
				getline(line2, line, '-');
				number = stoi(line);
				getline(line2, line, '-');
				buy_price = stof(line);
				getline(line2, line);
				sale_price = stof(line);
				Product prd(name,barcode,number,buy_price,sale_price);

				prd.show_screen();

				cout<<"New Number"<<endl;
				cin>>number;
				cout<<"New Buy price"<<endl;
				cin>>buy_price;
				cout<<"New Sale price"<<endl;
				cin>>sale_price;
				prd.set_pro(number,buy_price,sale_price);
				Prd[j] = prd;
				file.close();
				++j;
				break;
			}
			else if(file.eof()){
				file.close();
				cout<<"No products found"<<endl;
				Product prd = create_product(barcode);
				Prd[j] = prd;
				j++;
				break;
			}
		}
		
 	}
 	if(j == 100){
 		cout<<"you have entered enough products"<<endl;
 	}
 	string data = "../data/data.txt";
 	upgrade_data(data, Prd, j-1);
}

Product create_product(string barcode){
	string name;
	int number;
	float buy_price;
	float sale_price;
	cout<<"Name"<<endl;
	cin>>name;
	cout<<"Number"<<endl;
	cin>>number;
	cout<<"Buy price"<<endl;
	cin>>buy_price;
	cout<<"Sale price"<<endl;
	cin>>sale_price;
	Product Prd(barcode,name,number,buy_price,sale_price);
	return Prd;
}