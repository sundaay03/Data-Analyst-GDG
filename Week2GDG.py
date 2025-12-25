import numpy as np

def tambah_nilai():
    matkul = np.array (["Algoritma", "Kalulus", "Pemrograman Dasar", "Matematika Diskrit"])
    komponen = np.array (["Tugas", "UTS", "UAS"])

    nilai = np.zeros((len(matkul), len(komponen)))
    for i in range (len(matkul)):
        print(f"\nMasukkan nilai untuk mata kuliah {matkul[i]}:")
        for j in range (len(komponen)):
            nilai[i][j] = float(input(f"  {komponen[j]}: "))

    return matkul, komponen, nilai

def rata_mk(matkul, nilai):
    rata = np.mean(nilai, axis=1)
    print("\nRata-rata nilai per mata kuliah:")
    for i in range(len(matkul)):
        print(f"- {matkul[i]}: {rata[i]:.2f}")

def rata(nilai):
    return np.mean(nilai)

def maks_mk(matkul, nilai):
    print("\nNilai tertinggi dan terendah per mata kuliah:")
    for i in range(len(matkul)):
        maksimum = np.max(nilai[i])
        minimum = np.min(nilai[i])
        print(f"- {matkul[i]}: Tertinggi = {maksimum}, Terendah = {minimum}")

def maks_min(nilai):
    return np.max(nilai), np.min(nilai)

def menu():
    print("\nMenu Program Nilai Mahasiswa")
    print("1. Tambah Nilai Mahasiswa")
    print("2. Hitung Rata-rata Nilai per Mata Kuliah")
    print("3. Hitung Rata-rata Nilai Keseluruhan")
    print("4. Tampilkan Nilai Tertinggi dan Terendah per Mata Kuliah")
    print("5. Tampilkan Nilai Tertinggi dan Terendah Keseluruhan")
    print("6. Keluar")

def main():
    matkul = np.array([])
    komponen = np.array([])
    nilai = np.array([[]])

    while True:
        menu()
        pilihan = int(input("Pilih Menu 1-6: "))

        match pilihan:
            case 1:
                matkul, komponen, nilai = tambah_nilai()
                print("\nData berhasil ditambahkan.")
            case 2:
                if nilai.size > 0:
                    rata_mk(matkul, nilai)
                else:
                    print("\nData belum ada!")
            case 3:
                if nilai.size > 0:
                    print("\nRata-rata nilai keseluruhan:", rata(nilai))
                else:
                    print("\nData belum ada!")
            case 4:
                if nilai.size > 0:
                    maks_mk(matkul, nilai)
                else:
                    print("\nData belum ada!")
            case 5:
                if nilai.size > 0:
                    maksimum, minimum = maks_min(nilai)
                    print("\nNilai Tertinggi Keseluruhan:", maksimum)
                    print("Nilai Terendah Keseluruhan:", minimum)
                else:
                    print("\nData belum ada!")
            case 6:
                print("Keluar dari program.")
                break
            case _:
                print("Pilihan tidak valid. Silakan coba lagi.")

main()