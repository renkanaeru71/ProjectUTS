//kelompok 11: 123250061, 123250065, 123250066

#include <iostream>
#include <string>
using namespace std;

typedef struct {
    long NoPendaftaran;
    string Nama;
    string Tanggal;
} pendaftaran;

pendaftaran data[100];
int jumlah = 0;

void tambahData() {
    cout << "\n=== TAMBAH DATA ===" << endl;
    cout << "No Pendaftaran       : ";
    cin >> data[jumlah].NoPendaftaran;
    cin.ignore();
    cout << "Nama                 : ";
    getline(cin, data[jumlah].Nama);
    cout << "Tanggal (DD/MM/YYYY) : ";
    getline(cin, data[jumlah].Tanggal);
    jumlah++;
    cout << "Data berhasil ditambahkan!" << endl;
}

void tampilData() {
    cout << "\n=== DAFTAR DATA PENDAFTARAN ===" << endl;
    if (jumlah == 0) {
        cout << "Belum ada data." << endl;
        return;
    }
    cout << "--------------------------------------------------------------" << endl;
    cout << "No\tNo PendaftaranNama\t\t\tTanggal" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << "\t"
             << data[i].NoPendaftaran << "\t\t"
             << data[i].Nama << "\t\t\t"
             << data[i].Tanggal << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
}

void cariData() {
    long cari;
    bool ketemu = false;
    cout << "\n=== CARI DATA ===" << endl;
    cout << "Masukkan No Pendaftaran yang dicari: ";
    cin >> cari;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].NoPendaftaran == cari) {
            cout << "\nData ditemukan:" << endl;
            cout << "No Pendaftaran : " << data[i].NoPendaftaran << endl;
            cout << "Nama           : " << data[i].Nama << endl;
            cout << "Tanggal        : " << data[i].Tanggal << endl;
            ketemu = true;
            break;
        }
    }
    if (!ketemu) {
        cout << "Data dengan No Pendaftaran " << cari << " tidak ditemukan." << endl;
    }
}

void hapusData() {
    long hapus;
    int ketemu = -1;
    cout << "\n=== HAPUS DATA ===" << endl;
    cout << "Masukkan No Pendaftaran yang akan dihapus: ";
    cin >> hapus;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].NoPendaftaran == hapus) {
            ketemu = i;
            break;
        }
    }
    if (ketemu == -1) {
        cout << "Data tidak ditemukan." << endl;
        return;
    }
    for (int i = ketemu; i < jumlah - 1; i++) {
        data[i] = data[i + 1];
    }
    jumlah--;
    cout << "Data berhasil dihapus!" << endl;
}

void editData() {
    long edit;
    int ketemu = -1;
    cout << "\n=== EDIT DATA ===" << endl;
    cout << "Masukkan No Pendaftaran yang akan diedit: ";
    cin >> edit;
    for (int i = 0; i < jumlah; i++) {
        if (data[i].NoPendaftaran == edit) {
            ketemu = i;
            break;
        }
    }
    if (ketemu == -1) {
        cout << "Data tidak ditemukan." << endl;
        return;
    }
    cin.ignore();
    cout << "Nama baru (sebelumnya: " << data[ketemu].Nama << "): ";
    getline(cin, data[ketemu].Nama);
    cout << "Tanggal baru (sebelumnya: " << data[ketemu].Tanggal << "): ";
    getline(cin, data[ketemu].Tanggal);
    cout << "Data berhasil diperbarui!" << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU UTAMA ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampil Data" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Edit Data" << endl;
        cout << "5. Hapus Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilData(); break;
            case 3: cariData();   break;
            case 4: editData();   break;
            case 5: hapusData();  break;
            case 0: cout << "Terima kasih!" << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}