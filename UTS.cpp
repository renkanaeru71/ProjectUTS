//kelompok 11: 123250061, 123250065, 123250066
#include <iostream>
#include <iomanip>
using namespace std;

void searching (){
	char ulang;
	int pilih;
	
	do{
		system("cls");
		cout << "MENU SEARCHING\n";
		cout << "=========================\n";
		cout << "1. Sequential\n";
		cout << "2. Binary\n";
		cout << "3. EXIT\n";
		cout << "=========================\n";
		cout << "Pilih: ";
		cin >> pilih;  
		cout << endl;
		
		if (pilih == 1)
		{
			seqsearching();
			}
		else if (pilih == 2)
		{
			BubbleS();
			binary();
			dataawal();
			}
		else if (pilih == 3)
		{
			ulang = 't';
			}
		else 
		{
			cout << "Pilihan di menu searching tidak ada...\n";
			}
			
		if (pilih != 3)
		{
			cout << "Ulangi (y/t) : ";
			cin >> ulang;
			}
		} while (ulang == 'y' || ulang == 'Y');
	}
	
	
	
	}

int main (){
	int pilih;
	cout << "PROGRAM TUGAS\n";
	
	do{
		system("cls");
		cout << "MENU\n";
		cout << "PROGRAM TUGAS\n";
		cout << "=========================\n";
		cout << "1. INPUT DATA\n";
		cout << "2. TAMPIL DATA\n";
		cout << "3. SEARCHING\n";
		cout << "4. SORTING\n";
		cout << "5. EXIT\n";
		cout << "=========================\n";
		cout << "Pilih: ";
		cin >> pilih;  
		
		switch(pilih){
			case 1 : 
				cout << "INPUT DATA\n";
			//	input();
				break;
			case 2: 
				cout << "TAMPIL DATA\n";
			//	tampil();
				break;
			case 3:
				cout << "SEARCHING\n";
			//	searching();
				break;
			case 4: 
				cout << "SORTING\n";
			//	checkreq();
				break;
			case 5: 
				cout << "Exiting program...\n";
				break;
			default:
				cout << "PILIHAN TIDAK VALID\n";
			
			}
		

		} while (pilih !=5);
		
		return 0;
	}
