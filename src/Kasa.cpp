#include <iostream>
#include <string>
#include <fstream>
#include "..\include\Product.h"
#include <sstream>

using namespace std;
using namespace Project;

ofstream tax("../output/tax.txt",ios::app);



int num_pro = 0;
Product Prd_list[100];

void search_product(string barcode);//Girilen barkoddaki urunu arayacak 

void wrt_tax(Product Prd);//Verilen urunu fise yazdiracak

int main(){
	string barcode;
	int number;
	int count;
	float sum = 0.0;
	tax<<"Name\tNumber\tPrice"<<endl;

	while(count < 100){

		cout<<"Barcode(Press q for quit):"<<endl;
		cin>>barcode;//Barkod alinacak cikis icin q ya basilacak
		if(barcode == "q"){
			break;
		}

		count = num_pro;//urun sayisini elde tutacak

		//ayni urunden tekrar satis yapildiginda listeye tekrar eklenmeden sayi alma kismina gidecek
		//ayni urnunun tekrar listeye eklenmesi iki kere dosyaya yazilmasina yol acacaktir
		if (num_pro>0){

			for(int i = 0; i<num_pro; i++){
				if(Prd_list[i].get_barcode() == barcode){
					count = i;
					goto A;

				}

			}
		}

		search_product(barcode);//verilen urunu dosyada arayacak

		if(num_pro != count){//Urun bilgisi bulundu ise num_pro artacaktır bu kosul saglandiysa sayi alma kismina gecilecektir
			A: 
				cout<<"Number"<<endl;
				cin>>number;
				if(Prd_list[count].get_number() < number){
					//stoktan daha fazla satis yapilmaya calisinca hata vererek tekrar sayi isteyecek
					cout<<"There is not enough product"<<endl;
					goto A;
				}

			Prd_list[count].set_number(Prd_list[count].get_number() - number);//listelenen urunlerin satis yapidigi kadar sayisi eksilecek
			wrt_tax(Prd_list[count], number);//Fise yazmak icin urun gonderilecek
			sum  += number*Prd_list[count].get_saleprice();//Toplam ucret hesaplanacak
			cout<<"Toplam ucret"<<sum;	
		}
	}

	if(count == 100){
 		cout<<"you have entered enough products"<<endl;
 	}

	tax<<"\nTotal Price --> "<<sum<<endl;
	tax.close();
	
	string data ="../data/data.txt";
	upgrade_data(data,Prd_list,count);
	
	return 0;

}

void search_product(string barcode){
		ifstream file("../data/data.txt");//Verilerin tutuldugu dosyayi okuma modunda açmak icin
		string line;//Veri satirlari tutacak ve parcalanacak
		string line2;//Satirin parcalanbilmesi için kullanilacak
		string name;//Urun adi tutacak
		int number;//Urun sayisi tutacak
		float buy_price;//Alis fiyati tutacak
		float sale_price;//Satis fiyati tutacak

		while(1){

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
				Prd_list[num_pro] = Prd;
				num_pro++;//urun sayisi artacak
				file.close();
				break;
			}
			else if(file.eof()){
				cout<<"Urun Bilgisi Bulunamadi"<<endl;
				file.close();
				break;
			}
		}
}

void wrt_tax(Product Prd, int number){

	tax<<Prd.get_name()<<"\t"<<number<<'\t'<<Prd.get_saleprice()<<endl;//verilen urunu fise yazdiracak

}