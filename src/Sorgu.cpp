#include <iostream>
#include <string>
#include <fstream>
#include "..\include\Product.h"
#include <sstream>

using namespace std;
using namespace Project;


int main(){
	
	while(1){
		ifstream file("../data/data.txt");//Verilerin tutuldugu dosyayi okuma modunda açmak icin
		string barcode;//Sorgu için verilen barkod degerini tutacak
		string line;//Veri satirlari tutacak ve parcalanacak
		string line2;//Satirin parcalanbilmesi için kullanilacak
		string name;//Urun adi tutacak
		int number;//Urun sayisi tutacak
		float buy_price;//Alis fiyati tutacak
		float sale_price;//Satis fiyati tutacak
		int i = 1;//Arama sonucu ile donguyu kontrol etmek icin kullanilacak

		cout<<"Enter the barcode of the product:\n";
		cin>>barcode;
		
		while(i){

			getline(file, line);//Urun bilgileri tek satirda tutuldugu icin satir alinmakta
			istringstream line2(line);//Urun özelliklerini ayri ayri alabilmek icin string stream cevirimi yapilmakta 
			getline(line2, line, '-');//ilk taba kadar olan kisim barkodu vermekte
			if (line== barcode){	
				getline(line2, line, '-');//İkinci taba kadar olan kisim adi vermekte
				name = line;
				getline(line2, line, '-');//Ücüncü taba kadar olan kisim sayiyi vermekte
				number = stoi(line);//string to integer cevirimi yapilmkata
				getline(line2, line, '-');//Son taba kadar olan kisim gelis fiyatini vermekte
				buy_price = stof(line);//string to float cevirimi yapilmakta
				getline(line2, line);//Son tabdan sonrasi ise satis fiyatini vermekte
				sale_price = stof(line);
				Product Prd(name,barcode,number,buy_price,sale_price);//urun nesnesi alinan bilgilerle tanimlanmakta
				Prd.wrt_screen();//Ürün bilgieri ekrana bastirilmakta
				i = 0;
				file.close();
			}
			else if(file.eof()){
				cout<<"No products found"<<endl;
				i = 0;
				file.close();
			}
		}
	}

}
