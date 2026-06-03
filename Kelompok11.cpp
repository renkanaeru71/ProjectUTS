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

void simpandata() {
    ofstream f;

    if(updatemode)
        f.open(namafile, ios::app);   // append
    else
        f.open(namafile);             // overwrite

    if(!f){
        cout << "Gagal membuka file!\n";
        return;
    }

    for(int i = 0; i < jumlah; i++){
        f << dat[i].nopendaftaran << "|"
          << dat[i].nama << "|"
          << dat[i].tanggal << endl;
    }

    f.close();
    
    bool found = false;
    FILE *idx = fopen("folder.txt", "rb");
    t = 0;

    if(idx){
        while(fread(listfile[t],20,1,idx)==1){
            if(strcmp(listfile[t], namafile)==0)
                found = true;
            t++;
        }
        fclose(idx);
    }

    if(!found)
        simpanFile();

    cout << "Data tersimpan ke " << namafile << endl;
}

void cekfile(){
    FILE *f = fopen(namafile, "rb");
    adafile = (f != NULL);
    if(f) fclose(f);
}

void input(){
	int n;
	cout << "\n+---------------------------------+\n";
	cout << "|            INPUT DATA           |\n";
	cout << "+---------------------------------+\n";
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
			
		cout << "Masukkan nama file: ";
		cin >> namafile;
			
			cekfile();
			if(adafile){
				cout << "File sudah ada, overwrite(0) / append(1): ";
				cin >> updatemode;
			}
			simpandata();
			updatemode = 0;
	}		


void ambilData() {
    ifstream f(namafile);

    if(!f){
        cout << "Error membuka file!\n";
        return;
    }

    if(statusmergeurut == 0)
    jumlah = 0;
    string line;

    while(getline(f, line)){
        if(line.empty() || line.length() < 3) continue;

        int p1 = line.find('|');
        int p2 = line.find('|', p1+1);

        if(p1 != string::npos && p2 != string::npos){
            dat[jumlah].nopendaftaran = stol(line.substr(0,p1));
            dat[jumlah].nama = line.substr(p1+1, p2-p1-1);
            dat[jumlah].tanggal = line.substr(p2+1);

            dattemp[jumlah] = dat[jumlah];
            jumlah++;
        }
    }

    f.close();

    cout << "\n=======================================================\n";
    cout << left
         << "| " << setw(18) << "NO PENDAFTARAN"
         << "| " << setw(20) << "NAMA"
         << "| " << setw(12) << "TANGGAL" << "|\n";
    cout << "=======================================================\n";

    for(int i=0;i<jumlah;i++){
        cout << left
             << "| " << setw(18) << dat[i].nopendaftaran
             << "| " << setw(20) << dat[i].nama
             << "| " << setw(12) << dat[i].tanggal << "|\n";
    }
    cout << "=======================================================\n";
}

void ambilFile(){
    t = 0;

    FILE *fptr = fopen("folder.txt","rb");

    cout << "\n+---------------------------------+\n";
    cout << "|           DAFTAR FILE           |\n";
    cout << "+---------------------------------+\n";

    if(fptr == NULL){
        cout << "| Belum ada file yang disimpan    |\n";
        cout << "+---------------------------------+\n";
        lanjut = 0;
    } else {
        while(fread(listfile[t],20,1,fptr)==1){
            cout << "| - " << left << setw(29) << listfile[t] << "|\n";
            t++;
        }
        cout << "+---------------------------------+\n";
        fclose(fptr);
        lanjut = 1;
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
	
	cout << "\n+---------------------------------+\n";
	cout << "|        SEQUENTIAL SEARCH        |\n";
	cout << "+---------------------------------+\n";
	
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
	cout << "\n+---------------------------------+\n";
	cout << "|          BINARY SEARCH          |\n";
	cout << "+---------------------------------+\n";

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
		cout << "+---------------------------------+\n";
		cout << "|         MENU SEARCHING          |\n";
		cout << "+---------------------------------+\n";
		cout << "| 1. Sequential Search            |\n";
		cout << "| 2. Binary Search                |\n";
		cout << "| 3. Kembali                      |\n";
		cout << "+---------------------------------+\n";
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
        cout << "\n=======================================================\n";
        cout << left
             << "| " << setw(18) << "NO PENDAFTARAN"
             << "| " << setw(20) << "NAMA"
             << "| " << setw(12) << "TANGGAL" << "|\n";
        cout << "=======================================================\n";
		for (int x = 0; x < jumlah; x++){
		
        cout << left
			 << "| " << setw(18) << dat[x].nopendaftaran
             << "| " << setw(20) << dat[x].nama
             << "| " << setw(12) << dat[x].tanggal        
             << "|\n";
    }
    cout << "=======================================================\n";
	cin.ignore();
}

void simpanHasilSorting(){
    char pilih;
    char filebaru[20];

    cout << "\nSimpan hasil sorting ke file? (y/t): ";
    cin >> pilih;

    if(pilih == 'y' || pilih == 'Y'){
        cout << "Nama file output: ";
        cin >> filebaru;

        strcpy(namafile, filebaru);
        updatemode = 0;   
        simpandata();

        cout << "Hasil sorting berhasil disimpan!\n";
    }
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
        cout << "+---------------------------------+\n";
        cout << "|           MENU SORTING          |\n";
        cout << "+---------------------------------+\n";
        cout << "| 1. Bubble Sort                  |\n";
        cout << "| 2. Selection Sort               |\n";
        cout << "| 3. Insertion Sort               |\n";
        cout << "| 4. Shell Sort                   |\n";
        cout << "| 5. Quick Sort                   |\n";
        cout << "| 6. Merge Sort                   |\n";
        cout << "| 7. Kembali ke Menu Utama        |\n";
        cout << "+---------------------------------+\n";
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
			simpanHasilSorting();
			dataawal();
			break;
			
			case 2: 
			cout << "\nData Sebelum disorting: \n";
			tampil();
			SelectionS();
			cout << "\nData setelah disorting: \n";
			tampil();
			simpanHasilSorting();
			dataawal();
			break;
			
			case 3:
			cout << "\nData Sebelum disorting: \n";
			tampil();
			insertionS();
			cout << "\nData setelah disorting: \n";
			tampil();
			simpanHasilSorting();
			dataawal();
			break;

			case 4:
			cout << "\nData Sebelum disorting: \n";		
			tampil();
			shellS();
			cout << "\nData setelah disorting: \n";
			tampil();
			simpanHasilSorting();
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
			simpanHasilSorting();
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
	
void updateData(){
    long cari;
    bool ketemu = false;

    cout << "\nUPDATING DATA FILE\n";
    cout << "----------------\n";
    cout << "Nama File yang mau di update data : ";
    cin >> namafile;

    ambilData();

    cout << "\nNo Pendaftaran yang mau diupdate : ";
    cin >> cari;

    cin.ignore();

    for(int x=0; x<jumlah; x++){
        if(dat[x].nopendaftaran == cari){
            ketemu = true;

            cout << "\nData semula :\n";
            cout << "\tNo Pendaftaran : "
                 << dat[x].nopendaftaran << endl;
            cout << "\tNama           : "
                 << dat[x].nama << endl;
            cout << "\tTanggal        : "
                 << dat[x].tanggal << endl;

            cout << "\nInput update :\n";

            cout << "\tNo Pendaftaran : ";
            cin >> dat[x].nopendaftaran;
            cin.ignore();

            cout << "\tNama           : ";
            getline(cin, dat[x].nama);

            cout << "\tTanggal        : ";
            getline(cin, dat[x].tanggal);

            cout << endl;
            break;
        }
    }

    if(!ketemu){
        cout << "Data tidak ditemukan!\n";
        return;
    }

    simpandata();

    cout << "\nData updating berhasil :\n";
    ambilData();
}

void mergesambungfile(){
    int n;
    char file[4][20], hasil[20];

    cout << "\nMERGE SAMBUNG\n";
    cout << "Jumlah file (max 4): ";
    cin >> n;

    for(int x=0; x<n; x++){
        cout << "Nama file " << x+1 << ": ";
        cin >> file[x];
    }

    cout << "Output file: ";
    cin >> hasil;

    ofstream out(hasil);

    for(int x=0; x<n; x++){
        ifstream in(file[x]);
        string baris;

        while(getline(in, baris)){
            if(!baris.empty()){
                out << baris << endl;
            }
        }
        in.close();
    }

    out.close();

    // Mendaftarkan file hasil merge ke folder.txt jika belum ada
    strcpy(namafile, hasil);
    bool found = false;
    FILE *idx = fopen("folder.txt", "rb");
    t = 0;
    if(idx){
        while(fread(listfile[t],20,1,idx)==1){
            if(strcmp(listfile[t], namafile)==0)
                found = true;
            t++;
        }
        fclose(idx);
    }
    if(!found) simpanFile();

    cout << "Merge selesai ke file " << hasil << endl;
}

void splittingfile(){
    int n;
    char filehasil[3][20];
    long bawah, atas;

    cout << "\nSPLITTING FILE\n";
    cout << "----------------\n";
    cout << "Nama file yang mau di splitting: ";
    cin >> namafile;

    ambilData();

    cout << "Banyaknya file hasil splitting (max 3): ";
    cin >> n;

    for(int x=0; x<n; x++){

        cout << "Nama File " << x+1 << " : ";
        cin >> filehasil[x];

        do{
            adafile = 0;

            strcpy(namafile, filehasil[x]);
            cekfile();

            if(adafile){
                cout << "File sudah ada!\n";
                cout << "Ulangi input Nama File " << x+1 << " : ";
                cin >> filehasil[x];
            }

        }while(adafile);

        cout << "Batas bawah No Pendaftaran : ";
        cin >> bawah;

        cout << "Batas atas No Pendaftaran  : ";
        cin >> atas;

        ofstream out(filehasil[x]);

        if(!out){
            cout << "Error\n";
            continue;
        }

        for(int j=0; j<jumlah; j++){
            if(dat[j].nopendaftaran >= bawah &&
               dat[j].nopendaftaran <= atas){

                out << dat[j].nopendaftaran << "|"
                    << dat[j].nama << "|"
                    << dat[j].tanggal << endl;
            }
        }

        out.close();

        strcpy(namafile, filehasil[x]);
        simpanFile();

        adafile = 0;
    }

    cout << "\nHasil SPLITTING FILE:\n";

    for(int x=0; x<n; x++){
        strcpy(namafile, filehasil[x]);

        cout << "\nNama File " << x+1
             << " : " << namafile << endl;

        ambilData();
        cout << endl;
    }
}

void hapusDataFile() {
    long cari;
    char yakin;

    cout << "\nHAPUS DATA FILE\n";
    cout << "----------------\n";
    cout << "Nama File yang datanya mau dihapus : ";
    cin >> namafile;

    ambilData();

    if(jumlah == 0){
        cout << "Data kosong!\n";
        return;
    }

    cout << "\nNo Pendaftaran yang mau dihapus : ";
    cin >> cari;

    ofstream f(namafile);

    if(!f){
        cout << "Error membuka file!\n";
        return;
    }

    bool ketemu = false;

    for(int i=0; i<jumlah; i++){
        if(dat[i].nopendaftaran == cari){
            ketemu = true;

            cout << "\nData ditemukan:\n";
            cout << "No Pendaftaran : " << dat[i].nopendaftaran << endl;
            cout << "Nama           : " << dat[i].nama << endl;
            cout << "Tanggal        : " << dat[i].tanggal << endl;

            cout << "Yakin data ini DIHAPUS (y/t)? ";
            cin >> yakin;

            if(yakin=='y' || yakin=='Y'){
                cout << "Data berhasil dihapus!\n";
                continue;   
            }
        }

        f << dat[i].nopendaftaran << "|"
          << dat[i].nama << "|"
          << dat[i].tanggal << endl;
    }

    f.close();

    if(!ketemu)
        cout << "Data tidak ditemukan!\n";

    cout << "\nPenghapusan data berhasil:\n";
    ambilData();
}

void mergeurutfile(){
    int n;
    char file[4][20];
    char hasil[20];

    status = 1;

    cout << "\nMERGE URUT\n";
    cout << "----------------\n";
    cout << "Banyaknya file yang akan di merge urut (max 4): ";
    cin >> n;

    // 1. Meminta input nama file sumber
    for(int i=0; i<n; i++){
        cout << "Nama File " << i+1 << " : ";
        cin >> file[i];
    }

    cout << "Di MERGE URUT dan disimpan di file : ";
    cin >> hasil;

    // 2. Loop untuk memuat data dari file sumber ke dalam array
    for(int i=0; i<n; i++){
        strcpy(namafile, file[i]); // Set nama file yang mau dibaca

        // Jika ini bukan file pertama, set statusmergeurut = 1
        // Ini agar fungsi ambilData() tidak me-reset isi array
        // melainkan menumpuk (append) data baru di bawah data sebelumnya
        if(i != 0)
            statusmergeurut = 1; 

        ambilData(); // Baca isi file dan masukkan ke dalam array memori
    }

    // 3. Set target file output ke 'hasil'
    strcpy(namafile, hasil);

    // 4. Mengurutkan gabungan data yang ada di array memori
    BubbleS();      
    
    // 5. Menyimpan hasil array yang sudah diurutkan ke file 'hasil'
    updatemode = 0; // Mode overwrite (buat file baru)
    simpandata();

    // 6. Reset variabel ke kondisi awal
    statusmergeurut = 0;
    status = 0;

    cout << "\nHasil MERGE URUT : \n";
    ambilData(); // Tampilkan isi file hasil merge
}

void operasi(){
    char ulang;
    int pilih;

    do{
        system("cls");
        cout << "+---------------------------------+\n";
        cout << "|       MENU OPERASI FILE         |\n";
        cout << "+---------------------------------+\n";
        cout << "| 1. Merging Sambung              |\n";
        cout << "| 2. Merging Urut                 |\n";
        cout << "| 3. Splitting                    |\n";
        cout << "| 4. Updating Data                |\n";
        cout << "| 5. Hapus Data                   |\n";
        cout << "| 6. Kembali ke Menu Utama        |\n";
        cout << "+---------------------------------+\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih){
            case 1:
                cout<<"Merge Sambung\n";
				mergesambungfile();
                break;
            case 2:
                cout<<"Merge Urut\n";
                mergeurutfile();
                break;
            case 3:
                cout<<"Splitting\n";
                splittingfile();
                break;
            case 4:
                cout<<"Updating\n";
                updateData();
                break;
            case 5:
                cout<<"Hapus Data\n";
                hapusDataFile();
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


int main (){
	int pilih;
	cout << "PROGRAM TUGAS\n";
	system("cls");
	
	do{
		system("cls");
		cout << "+---------------------------------+\n";
		cout << "|      PROGRAM TUGAS STRUKDAT     |\n";
		cout << "+---------------------------------+\n";
		cout << "| 1. Input Data                   |\n";
		cout << "| 2. Tampil Data                  |\n";
		cout << "| 3. Searching                    |\n";
		cout << "| 4. Sorting                      |\n";
		cout << "| 5. Operasi File                 |\n";
		cout << "| 6. Keluar Program               |\n";
		cout << "+---------------------------------+\n";
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
				ambilFile();
				if(lanjut==1){
					cout << "Nama file yang akan ditampilkan: ";
					cin >> namafile;
					ambilData();
					cin.ignore();
				} else {
					cin.ignore();
				}
				cout << "\nTekan Enter untuk kembali ke menu...";
				cin.ignore();
				system("cls");
				break;
			case 3:
				system("cls");
				ambilFile();
				if (lanjut == 1) {
					cout << "Nama file: ";
					cin >> namafile;
					ambilData();
					searching();
				}
				system("cls");
				break;
			case 4: 
				system("cls");
				ambilFile();
				if (lanjut == 1) {
					cout << "Nama file: ";
					cin >> namafile;
					ambilData();
					sorting();
				}
    			cin.ignore();
				system("cls");
				break;
			case 5:
				system("cls");
				ambilFile();
				if (lanjut == 1) {
					operasi();
				}
				cin.ignore();
				system("cls");
				break;
			case 6: 
				cout << "Exiting program...\n";
				break;
			default:
				cout << "PILIHAN TIDAK VALID\n";			
			}
		
		} while (pilih != 6);
		return 0;
	}
