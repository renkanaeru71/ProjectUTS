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
		
		if ()
	
	
	
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
			//	tambahbuku();
				break;
			case 2: 
				cout << "TAMPIL DATA\n";
			//	tampilbuku();
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
