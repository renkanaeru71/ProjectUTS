//kelompok 11: 
// 123250061 - Rizky Pratama
// 123250065 - Gilbert Bagus Nugroho
// 123250066 - Ahmad Rofiq Asysyakury
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

typedef struct {
    long nopendaftaran;
    string nama;
    string tanggal;
} pendaftaran;

pendaftaran dat[10];
pendaftaran dattemp[10];
int jumlah = 0;
char namafile[20];
char listfile[100][20];
int t = 0;
int updatemode = 0;
int addfile = 0;
int lanjut = 1;
int i = 0;
int cari = 0;
int status = 0;
int statusmergeurut = 0;
int adafile = 0;

void simpanFile(){
    FILE *fptr = fopen("folder.txt", "ab");
    if(fptr == NULL){
        cout << "Error";
    } else {
        fwrite(namafile, 20, 1, fptr);
        fclose(fptr);
    }
}

void simpandata(){
    FILE *f = fopen(namafile, updatemode ? "ab" : "wb");
    if(!f){ cout << "Gagal membuka file!"; return; }
    fwrite(dat, sizeof(pendaftaran), jumlah, f);
    fclose(f);

    bool found=false;
    FILE *idx = fopen("folder.txt", "rb");
    t = 0;
    if(idx){
        while(fread(listfile[t],20,1,idx)==1){
            if(strcmp(listfile[t], namafile)==0) found=true;
            t++;
        }
        fclose(idx);
    }
    if(!found) simpanFile();

    cout << "Data tersimpan ke " << namafile << " ";
}

void input(){
	int n;
	cout << "\nINPUT DATA\n";
	cout << "==================================\n";
	cout << "Jumlah data (max 10): ";
    cin >> n;
	
	if(n > 0 && n < 11){
		cout << endl;
		
		for(jumlah = 0; jumlah < n; jumlah++){
		cout <<"Data ke -" << jumlah+1 << endl;
		cout << "No Pendaftaran: ";
		cin >> dat[jumlah].nopendaftaran;
		cin.ignore();
		cout << "Nama: ";
		getline(cin, dat[jumlah].nama);
		cout << "Tanggal:(YYYY-MM-DD): ";
		getline(cin, dat[jumlah].tanggal);
		cout << endl;
		
		dattemp[jumlah] = dat[jumlah];
		} 
		}else {
			cout << "Jumlah harus antara 1 - 10!\n";
			cin.ignore();
			return;

			}
			cekfile();
			if(adafile){
				cout << "File sudah ada, overwrite(0) / append(1): ";
				cin >> updatemode;
			}
			simpandata();
			updatemode = 0;
	}		

void cekfile(){
    FILE *f = fopen(namafile, "rb");
    adafile = (f != NULL);
    if(f) fclose(f);
}

void ambilData(){
    FILE *ptr = fopen(namafile, "rb");
    if(ptr == NULL){
        cout << "Error";
        return;
    }

    // statusmergeurut == 0 -> reset index baca
    // disederhanakan dengan reset jumlah
    jumlah = 0;

    while(fread(&dat[jumlah], sizeof(dat), 1, ptr) == 1){
        jumlah++;
    }

    if(jumlah == 0){
        cout << "File kosong!";
    }
    else{
        // sesuai dekompilasi: kalau bukan mode searching/sorting langsung tampil
        cout << left << setw(15) << "NIM" << setw(10) << "KELAS" << setw(10) << "IPK" << " ";
        cout << "===================================";
        for(int i=0;i<jumlah;i++){
            cout << setw(15) << dat[i].nopendaftaran
                 << setw(10) << dat[i].nama
                 << setw(10) << dat[i].tanggal << " ";
            dattemp[i] = dat[i];
        }
    }

    fclose(ptr);
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

void SelectionS(){
    pendaftaran temp;
    int min;

    for (int a = 0; a < jumlah - 1; a++)
    {
        min = a;

        for (int b = a + 1; b < jumlah; b++)
        {
            if (dat[b].nama < dat[min].nama)
            {
                min = b;
            }
        }

        temp = dat[min];
        dat[min] = dat[a];
        dat[a] = temp;
	}

}

void shellS(){
	    int gap, a, b;

    for (gap = jumlah / 2; gap > 0; gap /= 2)
    {
        for (a = gap; a < jumlah; a++)
        {
            for (b = a - gap; b >= 0; b -= gap)
            {
                if (dat[b + gap].nopendaftaran < dat[b].nopendaftaran)
                {
                    swap(dat[b], dat[b + gap]);
                }
            }
        }
    }
}

void seqsearching(){
	system("cls");
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
		cout << cari << " tidak ditemukan!\n";
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

void insertionS(){
    pendaftaran temp;
    int a, b;
    for (a = 1; a < jumlah; a++) {
        temp = dat[a];
        b = a - 1;

        while (b >= 0 && dat[b].nopendaftaran > temp.nopendaftaran) {
            dat[b + 1] = dat[b];
            b = b - 1;
        }
        dat[b + 1] = temp;
    }
}

void quickS() {
    if (jumlah <= 1) return;

    int stack[10];
    int top = -1;

    stack[++top] = 0;
    stack[++top] = jumlah - 1;

    while (top >= 0) {
        int high = stack[top--];
        int low = stack[top--];
        long pivot = dat[high].nopendaftaran;
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (dat[j].nopendaftaran < pivot) {
                i++;
                swap(dat[i], dat[j]);
            }
        }
        swap(dat[i + 1], dat[high]);
        int pi = i + 1;

        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

void mergeS() {
    pendaftaran temp[10];
    
    for (int curr_size = 1; curr_size <= jumlah - 1; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < jumlah - 1; left_start += 2 * curr_size) {
            
            int mid = (left_start + curr_size - 1 < jumlah - 1) ? left_start + curr_size - 1 : jumlah - 1;
            int right_end = (left_start + 2 * curr_size - 1 < jumlah - 1) ? left_start + 2 * curr_size - 1 : jumlah - 1;

            int i = left_start;
            int j = mid + 1;
            int k = left_start;

            while (i <= mid && j <= right_end) {
                if (dat[i].nopendaftaran <= dat[j].nopendaftaran) {
                    temp[k] = dat[i];
                    i++;
                } else {
                    temp[k] = dat[j];
                    j++;
                }
                k++;
            }

            while (i <= mid) {
                temp[k] = dat[i];
                k++;
                i++;
            }

            while (j <= right_end) {
                temp[k] = dat[j];
                k++;
                j++;
            }

            for (i = left_start; i <= right_end; i++) {
                dat[i] = temp[i];
            }
        }
    }
}

void binary(){
	system("cls");
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
		cout << cari << " tidak ditemukan!" << endl;
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
	if (jumlah == 0){
		cout << "Data masih kosong!\n";
		cin.ignore();
		return;
		}
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

void sorting(){
	if (jumlah == 0){
		cout << "Data masih kosong!\n";
		cin.ignore();
		return;
		}
	char ulang;
	int pilih;
	
	do {
		system("cls");
        cout << "MENU SORTING :\n";
        cout << "=========================\n";
        cout << "1. BUBBLE SORT\n";
        cout << "2. SELECTION SORT\n";
        cout << "3. INSERTION SORT\n";
        cout << "4. SHELL SORT\n";
        cout << "5. QUICK SORT\n";
        cout << "6. MERGE SORT\n";
        cout << "7. Kembali ke MENU UTAMA\n";
        cout << "=========================\n";
        cout << "Pilih : ";
        cin >> pilih;
        cout << endl;
        
        switch(pilih) {
			case 1 :
			cout << "\nData Sebelum disorting: \n";
			tampil();
			BubbleS();
			cout << "\nData setelah disorting: \n";
			tampil();
			dataawal();
			break;
			
			case 2: 
			cout << "\nData Sebelum disorting: \n";
			tampil();
			SelectionS();
			cout << "\nData setelah disorting: \n";
			tampil();
			dataawal();
			break;
			
			case 3:
			cout << "\nData Sebelum disorting: \n";
			tampil();
			insertionS();
			cout << "\nData setelah disorting: \n";
			tampil();
			dataawal();
			break;

			case 4:
			cout << "\nData Sebelum disorting: \n";		
			tampil();
			shellS();
			cout << "\nData setelah disorting: \n";
			tampil();
			dataawal();
			break;

			case 5:
			cout << "\nData Sebelum disorting: \n";
			tampil();
			quickS();
			cout << "\nData setelah disorting: \n";
			tampil();
			dataawal();
			break;

			case 6:
			cout << "\nData Sebelum disorting: \n";
			tampil();
			mergeS();
			cout << "\nData setelah disorting: \n";
			tampil();
			dataawal();
			break;

			case 7:
			ulang = 't';
			break;

			default:
			cout << "Pilihan tidak valid, silakan pilih antara 1-7.\n";
			break;
		}
		
		if (pilih != 7){
			cout << "Ulangi (y/t) : ";
			cin >> ulang;
			}	
		} while (ulang == 'y' || ulang == 'Y');
	}

void operasi(){
    char ulang;
    int pilih;

    do{
        system("cls");
        cout << "MENU OPERASI FILE\n";
        cout << "=====================\n";
        cout << "1. MERGING SAMBUNG\n";
        cout << "2. MERGING URUT\n";
        cout << "3. SPLITTING\n";
        cout << "4. UPDATING DATA\n";
        cout << "5. HAPUS DATA\n";
        cout << "6. Kembali\n";
        cout << "=====================\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih){
            case 1:
                cout<<"Merge Sambung\n";
				mergesambungfile();
                break;
            case 2:
                cout<<"Merge Urut\n";
                break;
            case 3:
                cout<<"Splitting\n";
                break;
            case 4:
                cout<<"Updating\n";
                break;
            case 5:
                cout<<"Hapus Data\n";
                break;
            case 6:
                ulang='t';
                break;
            default:
                cout<<"Pilihan tidak valid\n";
        }

        if(pilih!=6){
            cout<<"Ulangi (y/t): ";
            cin>>ulang;
        }

    }while(ulang=='y'||ulang=='Y');
}

void mergesambungfile(){
    int jumlah;
    char file[4][20];
    char hasil[20];

    cout<<"MERGE SAMBUNG\n";
    cin>>jumlah;

    for(int i=0;i<jumlah;i++){
        cout<<"Nama file "<<i+1<<": ";
        cin>>file[i];
    }

    cout<<"Output file: ";
    cin>>hasil;

    //for(int i=0;i<jumlah;i++){
       // baca(file[i]);

    //    if(i==0)
         //   tulisBaru(hasil);
       // else
           // append(hasil);
    //}

    //tampilkan(hasil);
}

int main (){
	int pilih;
	cout << "PROGRAM TUGAS\n";
	system("cls");
	
	do{
		system("cls");
		cout << "MENU\n";
		cout << "PROGRAM TUGAS\n";
		cout << "=========================\n";
		cout << "1. INPUT DATA\n";
		cout << "2. TAMPIL DATA\n";
		cout << "3. SEARCHING\n";
		cout << "4. SORTING\n";
		cout << "5. OPERASI FILE\n";
		cout << "6. EXIT\n";
		cout << "=========================\n";
		cout << "Pilih: ";
		cin >> pilih;  
		
		switch(pilih){
			case 1 : 
				system("cls");
				cout << "INPUT DATA\n";
				input();
				cin.ignore();
				system("cls");
				break;
			case 2: 
				system("cls");
				tampil();
				cin.ignore();
				system("cls");
				break;
			case 3:
				system("cls");
				cout << "SEARCHING\n";
				searching();
				cin.ignore();
				system("cls");
				break;
			case 4: 
				system("cls");
				cout << "SORTING\n";
				sorting();
				cin.ignore();
				system("cls");
				break;
			case 5: 
				system("cls");
				cout << "SORTING\n";
				operasi();
				cin.ignore();
				system("cls");
				break;
			case 6: 
				cout << "Exiting program...\n";
				break;
			default:
				cout << "PILIHAN TIDAK VALID\n";			
			}
		
		} while (pilih !=6);
		return 0;
	}
