# Membuat menu program nilai mahasiswa
# Dibuat oleh: Sandi Riandi - Universitas Sultan Ageng Tirtayasa

def tambah_nilai():
    nama = input("\nMasukkan nama mahasiswa: ")
    nim = input("Masukkan NIM mahasiswa: ")
    matkul = {
        "Matematika Diskrit": float(input("Masukkan nilai Matematika Diskrit: ")),
        "Algoritma dan Pemrograman": float(input("Masukkan nilai Algoritma dan Pemrograman: ")),
        "Kalkulus": float(input("Masukkan nilai Kalkulus: ")),
        "Bahasa Pemrograman I": float(input("Masukkan nilai Bahasa Pemrograman I: "))
    }
    return nama, nim, matkul

def tampilkan_nilai(nama, nim, matkul):
    print(f"\nNilai Mahasiswa: {nama} (NIM: {nim})")
    for mata_kuliah, nilai in matkul.items():
        print(f"{mata_kuliah}: {nilai}")

def average_nilai(matkul):
    total = sum(matkul.values())
    return total / len(matkul)

def nilai_max_min(matkul):
    return max(matkul.values()), min(matkul.values())

def tampilan_menu():
    print("\nMenu Program Nilai Mahasiswa")
    print("1. Tambah Nilai Mahasiswa")
    print("2. Tampilkan Nilai Mahasiswa")
    print("3. Hitung Rata-rata Nilai")
    print("4. Tampilkan Nilai Tertinggi dan Terendah")
    print("5. Tampilkan Semua Data")
    print("6. Keluar")

def main():
    nama = ""
    nim = ""
    matkul = {}

    while True:
        tampilan_menu()
        pilihan = int(input("Pilih Menu 1-6: "))

        match pilihan:
            case 1:
                nama, nim, matkul = tambah_nilai()
                print("\nData berhasil ditambahkan.")
            case 2:
                if matkul:
                    tampilkan_nilai(nama, nim, matkul)
                else:
                    print("Data belum ada!")
            case 3:
                if matkul:
                    print("\nRata-rata nilai:", average_nilai(matkul))
                else:
                    print("\nData belum ada!")
            case 4:
                if matkul:
                    maksimum, minimum = nilai_max_min(matkul)
                    print("\nNilai Tertinggi:", maksimum)
                    print("Nilai Terendah:", minimum)
                else:
                    print("\nData belum ada!") 
            case 5:
                if matkul:
                    tampilkan_nilai(nama, nim, matkul)
                    print("Rata-rata nilai:", average_nilai(matkul))
                    
                    maksimum, minimum = nilai_max_min(matkul)
                    print("Nilai Tertinggi:", maksimum)
                    print("Nilai Terendah:", minimum)
                else:
                    print("Data belum ada!")
            case 6:
                print("\nKeluar program.")
                break

            case _:
                print("\nPilihan tidak valid!")
main()