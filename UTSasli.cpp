#include <iostream>
#include <iomanip>
using namespace std;


typedef struct {
    long nopendaftaran;
    string nama;
    string tanggal;
} pendaftaran;

pendaftaran dat[10];
pendaftaran dattemp[10];
int jumlah = 0;

void input(){
	int n;
	cout << "\nINPUT DATA\n";
	cout << "==================================\n";
	cout << "Jumlah data (max 10): ";
    cin >> n;
	
	if(n<11){
		cout << endl;
		
		for(jumlah = 0; jumlah < n; jumlah++){
		cout <<"Data ke -" << jumlah+1 << endl;
		cout << "No Pendaftaran: ";
		cin >> dat[jumlah].nopendaftaran;
		cout << "Nama: ";
		cin >> dat[jumlah].nama;
		cout << "Tanggal: ";
		cin >> dat[jumlah].tanggal;
		cout << endl;
		
		dattemp[jumlah] = dat[jumlah];
		}
	
	}
}

void BubbleS(){
	for (int a=0; a<jumlah-1; a++){
		for(int b=0; b<jumlah-1-a; b++){
			if(dat[b+1].nopendaftaran < dat[b].nopendaftaran){
				swap(dat[b], dat[b+1]);
				}
			}
		}
	return;
	}

void seqsearching(){
	system("clear");
	int cari;
	int x =0;
	bool ketemu = false;
	
	cout << "\nSEQUENTIAL SEARCH\n";
	cout << "==================\n";
	
	cout << "\n No Pendaftaran yang dicari: ";
	cin >> cari;
	
	while (x<jumlah && !ketemu){
		if(dat[x].nopendaftaran == cari){
			ketemu = true;
			} else 
			{
				x++;
		}
		
	}
	if(!ketemu){
		cout << cari << "tidak ditemukan!\n";
		}
		else{
			cout << "\nData ditemukan";
            cout << "\n==========================\n";
			cout << "No Pendaftaran \t: "   << dat[x].nopendaftaran << endl;
			cout << "Nama \t: " << dat[x].nama << endl;
			cout << "Tanggal \t: "   << dat[x].tanggal << endl;
			cout << "==========================\n";
			
			}

}

void dataawal()
{
    for (int x = 0; x < jumlah; x++)
    {
        dat[x] = dattemp[x];
    }
}

void binary(){
	system("clear");
	int cari;
	int kiri, tengah, kanan;
	bool ketemu = false;
	cout << "BINARY SEARCH\n";
	cout << "==================\n";

    cout << "\nNo Pendaftaraan yang dicari = ";
    cin >> cari;
    
    kiri = 0;
    kanan = jumlah-1;
    
    while (kiri <= kanan && !ketemu){
		tengah = (kiri + kanan) / 2;
		
		if (dat[tengah].nopendaftaran == cari)
		{
			ketemu = true;
			}
		else if (cari < dat[tengah].nopendaftaran){
			kanan = tengah -1;
			}
		else {
			kiri = tengah + 1;
			}
	}
	
	if(!ketemu){
		cout << cari << "tidak ditemukan!" << endl;
		}
		else {
        cout << "\nData ditemukan";
        cout << "\n==========================\n";
        cout << "No pendaftaran   \t: " << dat[tengah].nopendaftaran << endl;
        cout << "Nama \t: " << dat[tengah].nama << endl;
        cout << "Tanggal   \t: " << dat[tengah].tanggal << endl;
        cout << "==========================\n";
			}
}

void searching (){
	char ulang;
	int pilih;
	
	do{
		system("clear");
		cout << "MENU SEARCHING\n";
		cout << "=========================\n";
		cout << "1. Sequential\n";
		cout << "2. Binary\n";
		cout << "3. EXIT\n";
		cout << "=========================\n";
		cout << "Pilih: ";
		cin >> pilih;  
		cout << endl;
		
		if (pilih == 1){
			seqsearching();
			}
		else if (pilih == 2){
			BubbleS();
			binary();
			dataawal();
			}
		else if (pilih == 3){
			ulang = 't';
			}
		else {
			cout << "Pilihan di menu searching tidak ada...\n";
			}
			
		if (pilih != 3){
			cout << "Ulangi (y/t) : ";
			cin >> ulang;
			}
		} while (ulang == 'y' || ulang == 'Y');
	}
	

void tampil(){
	if (jumlah == 0){
		cout << "Data masih kosong!\n";
		cin.ignore();
		return;
		}
           cout << "\n====================================================\n";
           
			cout << left
				 << setw(20) << "NO PENDAFTARAN"
				 << setw(20) << "NAMA"
				 << setw(15) << "TANGGAL"
				 << endl;
           cout << "====================================================\n";
		for (int x = 0; x < jumlah; x++){
		
        cout << left
			 << setw(20)  << dat[x].nopendaftaran
             << setw(20)  << dat[x].nama
             << setw(15) << dat[x].tanggal        
             << endl;
    }
	cin.ignore();
}



int main (){
	int pilih;
	cout << "PROGRAM TUGAS\n";
	system("clear");
	
	do{
		system("clear");
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
				system("clear");
				cout << "INPUT DATA\n";
				input();
				cin.ignore();
				system("clear");
				break;
			case 2: 
				system("clear");
				cout << "TAMPIL DATA\n";
				tampil();
				cin.ignore();
				system("clear");
				break;
			case 3:
				cout << "SEARCHING\n";
				searching();
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
