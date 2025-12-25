/*
Dibuat oleh: 3337250154 - Sandi Riandi - C
             3337250052 - Raditya Ahmad Pratama - C
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ANGGOTA = 10;

// ================= STRUKTUR DATA ==================
struct Keluarga {
    int nik;
    string nama;
    string jenisKelamin;
    string alamat;
    string tanggalLahir;
    string agama;
    string pendidikan;
    string pekerjaan;
    string statusPerkawinan;
    string statusKewarganegaraan; 
};

Keluarga daftarKeluarga[MAX_ANGGOTA];
int jumlahKeluarga = 0;

// ================== FUNGSI UTILITAS ==================
void muatDariFile(const string &kartuKeluarga) {
    ifstream file(kartuKeluarga);
    if (!file.is_open()) {
        // Jika file belum ada, anggap kosong
        cout << "File " << kartuKeluarga << " belum ada. Mulai dengan data kosong.\n";
        return;
    }

    jumlahKeluarga = 0;
    string line;
    while (getline(file, line) && jumlahKeluarga < MAX_ANGGOTA) {
        if (line.empty()) continue;

        stringstream ss(line);
        string NIKStr, nama, jenisKelaminStr, alamatStr, tanggalLahirStr,
               agamaStr, pendidikanStr, pekerjaanStr, statusPerkawinanStr, statusKewarganegaraanStr;

    
        if (!getline(ss, NIKStr, '|')) continue;
        if (!getline(ss, nama, '|')) continue;
        if (!getline(ss, jenisKelaminStr, '|')) continue;
        if (!getline(ss, alamatStr, '|')) continue;
        if (!getline(ss, tanggalLahirStr, '|')) continue;
        if (!getline(ss, agamaStr, '|')) continue;
        if (!getline(ss, pendidikanStr, '|')) continue;
        if (!getline(ss, pekerjaanStr, '|')) continue;
        if (!getline(ss, statusPerkawinanStr, '|')) continue;
        if (!getline(ss, statusKewarganegaraanStr, '|')) continue;

        Keluarga b;
        b.nik   = stoi(NIKStr);
        b.nama = nama;
        b.jenisKelamin = (jenisKelaminStr);
        b.alamat = (alamatStr);
        b.tanggalLahir = tanggalLahirStr;
        b.agama = agamaStr;
        b.pendidikan = pendidikanStr;
        b.pekerjaan = pekerjaanStr;
        b.statusPerkawinan = statusPerkawinanStr;
        b.statusKewarganegaraan = statusKewarganegaraanStr;

        daftarKeluarga[jumlahKeluarga++] = b;
    }

    file.close();
    cout << "Data berhasil dimuat dari " << kartuKeluarga << ". Jumlah Keluarga: " 
         << jumlahKeluarga << "\n";
}

void simpanKeFile(const string &kartuKeluarga) {
    ofstream file(kartuKeluarga);
    if (!file.is_open()) {
        cout << "Gagal membuka file " << kartuKeluarga << " untuk disimpan.\n";
        return;
    }
    
    for (int i = 0; i < jumlahKeluarga; ++i) {
        file << daftarKeluarga[i].nik   << "|"
             << daftarKeluarga[i].nama << "|"
             << daftarKeluarga[i].jenisKelamin << "|"
             << daftarKeluarga[i].alamat << "|"
             << daftarKeluarga[i].tanggalLahir << "|"
             << daftarKeluarga[i].agama << "|"
             << daftarKeluarga[i].pendidikan << "|"
             << daftarKeluarga[i].pekerjaan << "|"
             << daftarKeluarga[i].statusPerkawinan << "|"
             << daftarKeluarga[i].statusKewarganegaraan << "\n";
    }

    file.close();
    cout << "Data berhasil disimpan ke " << kartuKeluarga << "\n";
}

int cariIndexById(int NIK) {
    for (int i = 0; i < jumlahKeluarga; ++i) {
        if (daftarKeluarga[i].nik == NIK) return i;
    }
    return -1;
}

// ================== CRUD ==================
void tampilkanKeluarga() {
    if (jumlahKeluarga == 0) {
        cout << "Belum ada data Keluarga.\n";
        return;
    }
                                // Diubah
    cout << left << setw(5)  << "NIK"
         << left << setw(20) << "|" "Nama"
         << left << setw(15) << "|" "Jenis Kelamin"
         << left << setw(15) << "|" "Alamat"
         << left << setw(20) << "|" "Tanggal Lahir"
         << left << setw(10) << "|" "Agama"
         << left << setw(15) << "|" "Pendidikan"
         << left << setw(15) << "|" "Pekerjaan"
         << left << setw(20) << "|" "Status Perkawinan"
         << left << setw(10) << "|" "Status Kewarganegaraan" << "\n";
    cout << string(170, '-') << "\n";

    for (int i = 0; i < jumlahKeluarga; ++i) {
        cout << left << setw(5) << daftarKeluarga[i].nik
             << left << setw(20) << daftarKeluarga[i].nama
             << left << setw(15) << daftarKeluarga[i].jenisKelamin
             << left << setw(15) << daftarKeluarga[i].alamat
             << left << setw(20) << daftarKeluarga[i].tanggalLahir
             << left << setw(10) << daftarKeluarga[i].agama
             << left << setw(15) << daftarKeluarga[i].pendidikan
             << left << setw(15) << daftarKeluarga[i].pekerjaan
             << left << setw(20) << daftarKeluarga[i].statusPerkawinan
             << left << setw(10) << daftarKeluarga[i].statusKewarganegaraan << "\n";
    }
}

void tambahKeluarga() {
    if (jumlahKeluarga >= MAX_ANGGOTA) {
        cout << "Array penuh, tidak bisa menambah Keluarga lagi.\n";
        return;
    }

    Keluarga b;
    cout << "\nMasukkan NIK                    : ";
    cin >> b.nik;
    cin.ignore(); // bersihkan newline

    if (cariIndexById(b.nik) != -1) {
        cout << "NIK sudah digunakan, silakan pakai NIK lain.\n";
        return;
    }

    cout << "Masukkan Nama Keluarga          : ";
    getline(cin, b.nama);

    cout << "Masukkan Jenis Kelamin          : ";
    getline(cin, b.jenisKelamin);
    
    cout << "Masukkan Alamat                 : ";
    getline(cin, b.alamat);

    cout << "Masukkan Tanggal Lahir          : ";
    getline(cin, b.tanggalLahir);

    cout << "Masukkan Agama                  : ";
    getline(cin, b.agama);

    cout << "Masukkan Pendidikan             : ";
    getline(cin, b.pendidikan);

    cout << "Masukkan Pekerjaan              : ";
    getline(cin, b.pekerjaan);

    cout << "Masukkan Status Perkawinan      : ";
    getline(cin, b.statusPerkawinan);

    cout << "Masukkan Status Kewarganegaraan : ";
    getline(cin, b.statusKewarganegaraan);

    daftarKeluarga[jumlahKeluarga++] = b;
    cout << "Keluarga berhasil ditambahkan.\n";
}

void ubahKeluarga() {
    if (jumlahKeluarga == 0) {
        cout << "Belum ada data Keluarga.\n";
        return;
    }

    int NIK;
    cout << "Masukkan NIK Keluarga yang akan diubah: ";
    cin >> NIK;
    cin.ignore();

    int index = cariIndexById(NIK);
    if (index == -1) {
        cout << "Keluarga dengan NIK " << NIK << " tNIKak ditemukan.\n";
        return;
    }

    cout << "Data lama:\n";
    cout << "Nama                   : " << daftarKeluarga[index].nama << "\n";
    cout << "Jenis Kelamin          : " << daftarKeluarga[index].jenisKelamin << "\n";
    cout << "Alamat                 : " << daftarKeluarga[index].alamat << "\n";
    cout << "Tanggal Lahir          : " << daftarKeluarga[index].tanggalLahir << "\n";
    cout << "Agama                  : " << daftarKeluarga[index].agama << "\n";
    cout << "Pendidikan             : " << daftarKeluarga[index].pendidikan << "\n";
    cout << "Pekerjaan              : " << daftarKeluarga[index].pekerjaan << "\n";
    cout << "Status Perkawinan      : " << daftarKeluarga[index].statusPerkawinan << "\n";
    cout << "Status Kewarganegaraan : " << daftarKeluarga[index].statusKewarganegaraan << "\n\n";

    Keluarga &b = daftarKeluarga[index];
    string input;
    
    // Diubah
    cout << "Nama baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.nama = input;

    cout << "Jenis Kelamin baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.jenisKelamin = input;

    cout << "Alamat baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.alamat = input;

    cout << "Tanggal Lahir baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.tanggalLahir = input;

    cout << "Agama baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.agama = input;

    cout << "Pendidikan baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.pendidikan = input;

    cout << "Pekerjaan baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.pekerjaan = input;

    cout << "Status Perkawinan baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.statusPerkawinan = input;

    cout << "Status Kewarganegaraan baru (kosongkan jika tidak diubah): ";
    getline(cin, input);
    if (!input.empty()) b.statusKewarganegaraan = input;

    cout << "Data Keluarga berhasil diubah.\n";
}

void hapusKeluarga() {
    if (jumlahKeluarga == 0) {
        cout << "Belum ada data Keluarga.\n";
        return;
    }

    int NIK;
    cout << "Masukkan NIK Keluarga yang akan dihapus: ";
    cin >> NIK;

    int index = cariIndexById(NIK);
    if (index == -1) {
        cout << "Keluarga dengan NIK " << NIK << " tidak ditemukan.\n";
        return;
    }

    // Geser elemen setelahnya ke depan
    for (int i = index; i < jumlahKeluarga - 1; ++i) {
        daftarKeluarga[i] = daftarKeluarga[i + 1];
    }
    jumlahKeluarga--;

    cout << "Keluarga berhasil dihapus.\n";
}

// ================== MENU ==================
void tampilkanMenu() {
    cout << "\n=== MENU CRUD Keluarga ===\n";
    cout << "1. Tampilkan Semua Keluarga\n";
    cout << "2. Tambah Keluarga\n";
    cout << "3. Ubah Keluarga\n";
    cout << "4. Hapus Keluarga\n";
    cout << "5. Simpan ke File\n";
    cout << "0. Keluar\n";
    cout << "\nPilihan: ";
}

int main() {
    string kartuKeluarga = "Keluarga.txt";
    muatDariFile(kartuKeluarga);

    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore(); // bersihkan newline

        switch (pilihan) {
            case 1:
                tampilkanKeluarga();
                break;
            case 2:
                tambahKeluarga();
                break;
            case 3:
                ubahKeluarga();
                break;
            case 4:
                hapusKeluarga();
                break;
            case 5:
                simpanKeFile(kartuKeluarga);
                break;
            case 0:
                cout << "Keluar program...\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    // Otomatis simpan saat keluar (opsional)
    simpanKeFile(kartuKeluarga);

    return 0;
}