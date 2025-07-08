#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>

using namespace std;

void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct Penyewa
{
    string nama;
    long long nik;
    long long nohp;
    string alamat;
    bool jeniskel;
};

struct RENTAL
{
    int merek;
    long hargaCivic       = 500000;
    long hargaJazz        = 300000;
    long hargaBrio        = 400000;
    long hargaCRV         = 500000;
    long hargaCity        = 500000;
    long hargaYaris       = 600000;
    long hargaInnova      = 800000;
    long hargaAvanza      = 350000;
    long hargaFortuner    = 550000;
    long hargaRush        = 650000;
    long hargaAyla        = 400000;
    long hargaSigra       = 300000;
    long hargaXenia       = 350000;
    long hargaTerios      = 450000;
    long hargaRocky       = 200000;
    long hargaXpander     = 430000;
    long hargaCross       = 500000;
    long hargaPajero      = 550000;
    long hargaXforce      = 300000;
    long hargaTriton      = 400000;
    Penyewa penyewa;
    long durasi;
    string tanggal;
    long long totalharga;
    long long totalbayar;
    long long kembalian;
    int pil;
    int paket;
    int jam, hari, week;
};

void cetakBingkaiAtasBawah(int panjang, int lebar)
{
    if (lebar > panjang)
    {
        cout << endl;
        return;
    }
    else
    {
        cout << "=";
    }
    cetakBingkaiAtasBawah(panjang, lebar + 1);
}

string getMEREK(int merek)
{
    switch (merek) {
        case 1: return "Honda";
        case 2: return "Toyota";
        case 3: return "Daihatsu";
        case 4: return "Mitsubishi";
        default: return "Tidak Diketahui";
    }
}

string getMOBIL(int pil)
{
    switch (pil)
    {
        case 1:  return "Civic";
        case 2:  return "Jazz";
        case 3:  return "Brio";
        case 4:  return "CRV";
        case 5:  return "City";
        case 6:  return "Yaris";
        case 7:  return "Innova";
        case 8:  return "Avanza";
        case 9:  return "Fortuner";
        case 10: return "Rush";
        case 11: return "Ayla";
        case 12: return "Sigra";
        case 13: return "Xenia";
        case 14: return "Terios";
        case 15: return "Rocky";
        case 16: return "Xpander";
        case 17: return "Xpander Cross";
        case 18: return "Pajero Sport";
        case 19: return "XForce";
        case 20: return "Triton";
        default: return "Tidak Diketahui";
    }
}

string getPAKET(int paket)
{
    switch (paket)
    {
        case 1: return "Per Jam";
        case 2: return "Per Hari";
        case 3: return "Per Minggu";
        default: return "Tidak Diketahui";
    }
}

void inputPenyewaData(Penyewa& p)
{
    cout << "Masukkan Nama Anda\t: ";
    getline(cin, p.nama);
    cout << "Masukkan NIK Anda\t: ";
    cin >> p.nik;
    clearInputBuffer();
    cout << "Masukkan Nomor HP Anda\t: ";
    cin >> p.nohp;
    clearInputBuffer();
    cout << "Masukkan Alamat Anda\t: ";
    getline(cin, p.alamat);
    cout << "Pilih Jenis Kelamin (1 = Laki-laki, 2 = Perempuan) : ";
    int jk;
    cin >> jk;
    p.jeniskel = (jk == 1);
    clearInputBuffer();
}

void inputRENTAL(RENTAL & rental)
{
    system("cls");

    cout << "=== Pilihan Merek Mobil Sewaan ===" << endl;
    cout << "1. Honda" << endl;
    cout << "2. Toyota" << endl;
    cout << "3. Daihatsu" << endl;
    cout << "4. Mitsubishi" << endl;

    cout << "Silahkan masukkan nomor merek yang Anda ingin pilih : ";
    cin >> rental.merek;
    clearInputBuffer();

    system("cls");

    switch (rental.merek)
    {
        case 1:
            system("cls");
            cout << "========== Honda ==========" << endl;
            cout << "Pilih mobil yang tersedia :" << endl;
            cout << "1. Civic" << endl;
            cout << "2. Jazz" << endl;
            cout << "3. Brio" << endl;
            cout << "4. CR-V" << endl;
            cout << "5. City" << endl;

            cout << "Anda memilih merek Honda, silahkan pilih mobil yang Anda inginkan : ";
            cin >> rental.pil;
            clearInputBuffer();

            if(rental.pil == 1)
            {
                cout << "\n=== Civic ===" << endl;
                cout << "Anda Memilih Mobil Civic" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaCivic << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if (rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaCivic ;
                    rental.durasi = rental.jam;
                    cout << "Nama Mobil = Civic" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;

                }
                else if (rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaCivic - 200000;
                    rental.durasi = rental.hari * 24;
                    cout << "Nama Mobil = Civic" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                }
                else if (rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaCivic - 400000 ;
                    rental.durasi = rental.week * 24 * 7;
                    cout << "Nama Mobil = Civic" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                }
            }
            else if (rental.pil == 2)
            {
                cout << "\n=== Jazz ===" << endl;
                cout << "Anda Memilih Mobil Jazz" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaJazz << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaJazz ;
                    cout << "Nama Mobil = Jazz" << endl;
                    cout << "Harga Mobil Sewa = Rp 300000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaJazz - 200000;
                    cout << "Nama Mobil = Jazz" << endl;
                    cout << "Harga Mobil Sewa = Rp 300000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaJazz - 400000 ;
                    cout << "Nama Mobil = Jazz" << endl;
                    cout << "Harga Mobil Sewa = Rp 300000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 3)
            {
                cout << "\n=== Brio ===" << endl;
                cout << "Anda Memilih Mobil Brio" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaBrio << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaBrio ;
                    cout << "Nama Mobil = Brio" << endl;
                    cout << "Harga Mobil Sewa = Rp 400000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaBrio - 200000;
                    cout << "Nama Mobil = Brio" << endl;
                    cout << "Harga Mobil Sewa = Rp 400000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaBrio - 400000 ;
                    cout << "Nama Mobil = Brio" << endl;
                    cout << "Harga Mobil Sewa = Rp 400000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 4)
            {
                cout << "\n=== CRV ===" << endl;
                cout << "Anda Memilih Mobil CRV" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaCRV << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaCRV ;
                    cout << "Nama Mobil = CRV" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaCRV - 200000;
                    cout << "Nama Mobil = CRV" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaCRV - 400000 ;
                    cout << "Nama Mobil = CRV" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 5)
            {
                cout << "\n=== City ===" << endl;
                cout << "Anda Memilih Mobil City" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaCity << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaCity ;
                    cout << "Nama Mobil = City" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaCity - 200000;
                    cout << "Nama Mobil = City" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaCity - 400000 ;
                    cout << "Nama Mobil = City" << endl;
                    cout << "Harga Mobil Sewa = Rp 500000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            break;

        case 2:
            system("cls");
            cout << "\n========== Toyota ==========" << endl;
            cout << "Pilih mobil yang tersedia :" << endl;
            cout << "6. Yaris" << endl;
            cout << "7. Innova" << endl;
            cout << "8. Avanza" << endl;
            cout << "9. Fortuner" << endl;
            cout << "10. Rush" << endl;

            cout << "Anda memilih merek Toyota, silahkan pilih mobil yang Anda inginkan : ";
            cin >> rental.pil;
            clearInputBuffer();

            if(rental.pil == 6)
            {
                cout << "\n=== Yaris ===" << endl;
                cout << "Anda Memilih Mobil Yaris" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaYaris << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaYaris ;
                    cout << "Nama Mobil = Yaris" << endl;
                    cout << "Harga Mobil Sewa = Rp 600000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaYaris - 200000;
                    cout << "Nama Mobil = Yaris" << endl;
                    cout << "Harga Mobil Sewa = Rp 600000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaYaris - 400000 ;
                    cout << "Nama Mobil = Yaris" << endl;
                    cout << "Harga Mobil Sewa = Rp 600000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 7)
            {
                cout << "\n=== Innova ===" << endl;
                cout << "Anda Memilih Mobil Innova" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaInnova << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaInnova ;
                    cout << "Nama Mobil = Innova" << endl;
                    cout << "Harga Mobil Sewa = Rp 800000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2){
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaInnova - 200000;
                    cout << "Nama Mobil = Innova" << endl;
                    cout << "Harga Mobil Sewa = Rp 800000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                } else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaInnova - 400000 ;
                    cout << "Nama Mobil = Innova" << endl;
                    cout << "Harga Mobil Sewa = Rp 800000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 8)
            {
                cout << "\n=== Avanza ===" << endl;
                cout << "Anda Memilih Mobil Avanza" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaAvanza << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaAvanza ;
                    cout << "Nama Mobil = Avanza" << endl;
                    cout << "Harga Mobil Sewa = Rp 350000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaAvanza - 200000;
                    cout << "Nama Mobil = Avanza" << endl;
                    cout << "Harga Mobil Sewa = Rp 350000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaAvanza - 400000 ;
                    cout << "Nama Mobil = Avanza" << endl;
                    cout << "Harga Mobil Sewa = Rp 350000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 9)
            {
                cout << "\n=== Fortuner ===" << endl;
                cout << "Anda Memilih Mobil Fortuner" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaFortuner << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaFortuner ;
                    cout << "Nama Mobil = Fortuner" << endl;
                    cout << "Harga Mobil Sewa = Rp 550000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaFortuner - 200000;
                    cout << "Nama Mobil = Fortuner" << endl;
                    cout << "Harga Mobil Sewa = Rp 550000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaFortuner - 400000 ;
                    cout << "Nama Mobil = Fortuner" << endl;
                    cout << "Harga Mobil Sewa = Rp 550000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 10)
            {
                cout << "\n=== Rush ===" << endl;
                cout << "Anda Memilih Mobil Rush" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaRush << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaRush ;
                    cout << "Nama Mobil = Rush" << endl;
                    cout << "Harga Mobil Sewa = Rp 650000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaRush - 200000;
                    cout << "Nama Mobil = Rush" << endl;
                    cout << "Harga Mobil Sewa = Rp 650000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaRush - 400000 ;
                    cout << "Nama Mobil = Rush" << endl;
                    cout << "Harga Mobil Sewa = Rp 650000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            break;

        case 3:
            system("cls");
            cout << "\n========== Daihatsu ==========" << endl;
            cout << "Pilih mobil yang tersedia :" << endl;
            cout << "11. Ayla" << endl;
            cout << "12. Sigra" << endl;
            cout << "13. Xenia" << endl;
            cout << "14. Terios" << endl;
            cout << "15. Rocky" << endl;

            cout << "Anda memilih merek Daihatsu, silahkan pilih mobil yang Anda inginkan : ";
            cin >> rental.pil;
            clearInputBuffer();

            if(rental.pil == 11)
            {
                cout << "\n=== Ayla ===" << endl;
                cout << "Anda Memilih Mobil Ayla" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaAyla << "/ Jam " << endl;
                cout << endl;

                cout << "Pilih paket yang Anda ingin pesan" << endl;
                cout << "1. Paket Per Jam" << endl;
                cout << "2. Paket Per Hari" << endl;
                cout << "3. Paket Per Minggu" << endl;
                cout << "Tentukan pilihan paket yang Anda inginkan : ";
                cin >> rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket == 1)
                {
                    cout << "\n===== Paket Per Jam =====" << endl;
                    cout << "Berapa jam yang ingin Anda sewa : ";
                    cin >> rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaAyla ;
                    cout << "Nama Mobil = Ayla" << endl;
                    cout << "Harga Mobil Sewa = Rp 400000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket == 2)
                {
                    cout << "\n===== Paket Per Hari =====" << endl;
                    cout << "Berapa hari yang ingin Anda sewa : ";
                    cin >> rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaAyla - 200000;
                    cout << "Nama Mobil = Ayla" << endl;
                    cout << "Harga Mobil Sewa = Rp 400000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket == 3)
                {
                    cout << "\n===== Paket Per Minggu =====" << endl;
                    cout << "Berapa minggu yang ingin Anda sewa : ";
                    cin >> rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaAyla - 400000 ;
                    cout << "Nama Mobil = Ayla" << endl;
                    cout << "Harga Mobil Sewa = Rp 400000" << endl;
                    cout << "Harga Total Sewa = Rp " << rental.totalharga << endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 12)
            {
                cout << "\n=== Sigra ===" << endl;
                cout << "Anda Memilih Mobil Sigra" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaSigra << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaSigra ;
                    cout<<"Nama Mobil = Sigra"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 300000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaSigra - 200000;
                    cout<<"Nama Mobil = Sigra"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 300000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaSigra - 400000 ;
                    cout<<"Nama Mobil = Sigra"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 300000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 13)
            {
                cout << "\n=== Xenia ===" << endl;
                cout << "Anda Memilih Mobil Xenia" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaXenia << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaXenia ;
                    cout<<"Nama Mobil = Xenia"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 350000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaXenia - 200000;
                    cout<<"Nama Mobil = Xenia"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 350000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaXenia - 400000 ;
                    cout<<"Nama Mobil = Xenia"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 350000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 14)
            {
                cout << "\n=== Terios ===" << endl;
                cout << "Anda Memilih Mobil Terios" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaTerios << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaTerios ;
                    cout<<"Nama Mobil = Terios"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 450000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaTerios - 200000;
                    cout<<"Nama Mobil = Terios"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 450000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaTerios - 400000 ;
                    cout<<"Nama Mobil = Terios"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 450000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 15)
            {
                cout << "\n=== Rocky ===" << endl;
                cout << "Anda Memilih Mobil Rocky" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaRocky << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaRocky ;
                    cout<<"Nama Mobil = Rocky"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 200000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaRocky - 200000;
                    cout<<"Nama Mobil = Rocky"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 200000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaRocky - 400000 ;
                    cout<<"Nama Mobil = Rocky"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 200000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            break;

        case 4:
            system("cls");
            cout << "\n========== Mitsubishi ==========" << endl;
            cout << "Pilih mobil yang tersedia :" << endl;
            cout << "16. Xpander" << endl;
            cout << "17. Xpander Cross" << endl;
            cout << "18. Pajero Sport" << endl;
            cout << "19. XForce" << endl;
            cout << "20. Triton" << endl;

            cout << "Anda memilih merek Mitsubishi, silahkan pilih mobil yang Anda inginkan : ";
            cin >> rental.pil;
            clearInputBuffer();

            if(rental.pil == 16)
            {
                cout << "\n=== Xpander ===" << endl;
                cout << "Anda Memilih Mobil Xpander" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaXpander << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaXpander ;
                    cout<<"Nama Mobil = Xpander"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 430000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaXpander - 200000;
                    cout<<"Nama Mobil = Xpander"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 430000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaXpander - 400000 ;
                    cout<<"Nama Mobil = Xpander"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 430000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 17)
            {
                cout << "\n=== Xpander Cross ===" << endl;
                cout << "Anda Memilih Mobil Cross" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaCross << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaCross ;
                    cout<<"Nama Mobil = Cross"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 500000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaCross - 200000;
                    cout<<"Nama Mobil = Cross"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 500000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaCross - 400000 ;
                    cout<<"Nama Mobil = Cross"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 500000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 18)
            {
                cout << "\n=== Pajero Sport ===" << endl;
                cout << "Anda Memilih Mobil Pajero Sport" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaPajero << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaPajero ;
                    cout<<"Nama Mobil = Pajero Sport"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 550000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaPajero - 200000;
                    cout<<"Nama Mobil = Pajero Sport"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 550000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaPajero - 400000 ;
                    cout<<"Nama Mobil = Pajero Sport"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 550000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 19)
            {
                cout << "\n=== XForce ===" << endl;
                cout << "Anda Memilih Mobil XForce" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaXforce << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaXforce ;
                    cout<<"Nama Mobil = XForce"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 300000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaXforce - 200000;
                    cout<<"Nama Mobil = XForce"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 300000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaXforce - 400000 ;
                    cout<<"Nama Mobil = XForce"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 300000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            else if(rental.pil == 20)
            {
                cout << "\n=== Triton ===" << endl;
                cout << "Anda Memilih Mobil Triton" << endl;
                cout << "Anda Harus Membayar = Rp " << rental.hargaTriton << "/ Jam " << endl;
                cout << endl;

                cout<<"Pilih paket yang Anda ingin pesan"<<endl;
                cout<<"1. Paket Per Jam"<<endl;
                cout<<"2. Paket Per Hari"<<endl;
                cout<<"3. Paket Per Minggu"<<endl;
                cout<<"Tentukan pilihan paket yang Anda inginkan :";
                cin>>rental.paket;
                clearInputBuffer();
                system("cls");

                if(rental.paket==1)
                {
                    cout<<"\n===== Paket Per Jam ====="<<endl;
                    cout<<"Berapa jam yang ingin Anda sewa : ";
                    cin>>rental.jam;
                    clearInputBuffer();
                    rental.totalharga = rental.jam * rental.hargaTriton ;
                    cout<<"Nama Mobil = Triton"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 400000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.jam;
                }
                else if(rental.paket==2)
                {
                    cout<<"\n===== Paket Per Hari ====="<<endl;
                    cout<<"Berapa hari yang ingin Anda sewa : ";
                    cin>>rental.hari;
                    clearInputBuffer();
                    rental.totalharga = rental.hari * 24 * rental.hargaTriton - 200000;
                    cout<<"Nama Mobil = Triton"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 400000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.hari * 24;
                }
                else if(rental.paket==3)
                {
                    cout<<"\n===== Paket Per Minggu ====="<<endl;
                    cout<<"Berapa minggu yang ingin Anda sewa : ";
                    cin>>rental.week;
                    clearInputBuffer();
                    rental.totalharga = rental.week * 7 * 24 * rental.hargaTriton - 400000 ;
                    cout<<"Nama Mobil = Triton"<<endl;
                    cout<<"Harga Mobil Sewa = Rp 400000"<<endl;
                    cout<<"Harga Total Sewa = Rp "<< rental.totalharga <<endl;
                    rental.durasi = rental.week * 24 * 7;
                }
            }
            break;

        default:
            cout << "Pilihan merek tidak valid." << endl;
            break;
    }
}

void displayRENTAL (const RENTAL & rental, int index)
{
    const int lebar = 60;
    cetakBingkaiAtasBawah(lebar, 1);

    if (index != -1)
    {
        cout << "Data Rental ke-" << index + 1 << endl;
    }
    cout << setw((lebar + 18) / 2) << "RENTAL MOBIL" << endl;
    cetakBingkaiAtasBawah(lebar, 1);

    cout << left << setw(20) << "Tanggal Pesanan"    << ": " << rental.tanggal << endl;
    cout << left << setw(20) << "Merek Mobil"        << ": " << getMEREK(rental.merek) << endl;
    cout << left << setw(20) << "Mobil"              << ": " << getMOBIL(rental.pil) << endl;
    cout << left << setw(20) << "Nama Penyewa"       << ": " << rental.penyewa.nama << endl;
    cout << left << setw(20) << "NIK"                << ": " << rental.penyewa.nik << endl;
    cout << left << setw(20) << "Nomor HP"           << ": " << rental.penyewa.nohp << endl;
    cout << left << setw(20) << "Alamat"             << ": " << rental.penyewa.alamat << endl;
    cout << left << setw(20) << "Jenis Kelamin"      << ": " << (rental.penyewa.jeniskel ? "Laki-laki" : "Perempuan") << endl;
    cout << left << setw(20) << "Paket Sewa"         << ": " << getPAKET(rental.paket) << endl;
    cout << left << setw(20) << "Total Harga"        << ": " << rental.totalharga << endl;
    cout << left << setw(20) << "Durasi (Jam)"       << ": " << rental.durasi << endl;

    cetakBingkaiAtasBawah(lebar, 1);
    cout<<endl;
}

void tampilkanRENTAL(const vector<RENTAL> &dataRENTAL, int indeks)
{
    if (indeks >= dataRENTAL.size()) return;
    displayRENTAL(dataRENTAL[indeks], indeks);
    tampilkanRENTAL(dataRENTAL, indeks + 1);
}

void cariRENTAL(const vector<RENTAL> &dataRENTAL)
{
    int cari;
    cout << "Masukkan Nomor Rental Mobil (1 - " << dataRENTAL.size() << "): ";
    cin >> cari;
    clearInputBuffer();

    if (cari >= 1 && cari <= dataRENTAL.size())
    {
        displayRENTAL(dataRENTAL[cari - 1], cari - 1);
    }
    else
    {
        cout << "Nomor Rental tidak ditemukan!\n";
    }
}

void cariMobilTerpopuler(const vector<RENTAL>& dataRENTAL)
{
    system("cls");
    if (dataRENTAL.empty())
    {
        cout << "Tidak ada data rental mobil untuk dianalisis.\n";
        return;
    }

    int banyak[21] = {0};

    for (size_t i = 0; i < dataRENTAL.size(); ++i)
    {
        if (dataRENTAL[i].pil >= 1 && dataRENTAL[i].pil <= 20)
        {
            banyak[dataRENTAL[i].pil]++;
        }
    }

    int total = 0;
    for (int i = 1; i <= 20; i++)
    {
        if (banyak[i] > total)
        {
            total = banyak[i];
        }
    }

    if (total == 0)
    {
        cout << "Tidak ada data rental mobil yang valid ditemukan.\n";
        return;
    }

    cout << "\nMobil yang paling sering disewa (Total Unit Disewa: " << total << "):\n";
    for (int i = 1; i <= 20; i++) {
        if (banyak[i] == total) {
            cout << "- Mobil " << getMOBIL(i) << " Disewa Sebanyak "
                 << banyak[i] << " Unit (dari total unit yang disewa: " << total << ")" << endl;
        }
    }
    cetakBingkaiAtasBawah(60, 1);
}

void simpanDataKeFile(const vector<RENTAL> &rentalni)
{
    ofstream file("data_rental.txt", ios::app);

    if (!file)
    {
        cerr << "Error membuka file untuk penyimpanan! Pastikan Anda memiliki izin menulis." << endl;
        return;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);

    file << "=======================================\n";
    file << "            LOG TRANSAKSI RENTAL MOBIL\n";
    file << "            Dicatat pada: "
         << (ltm->tm_year + 1900) << "-"
         << setw(2) << setfill('0') << (ltm->tm_mon + 1) << "-"
         << setw(2) << setfill('0') << ltm->tm_mday << " "
         << setw(2) << setfill('0') << ltm->tm_hour << ":"
         << setw(2) << setfill('0') << ltm->tm_min << ":"
         << setw(2) << setfill('0') << ltm->tm_sec << "\n";
    file << "=======================================\n\n";

    for (size_t i = 0; i < rentalni.size(); i++)
    {
        const RENTAL &rental = rentalni[i];

        file << "--- NOTA RENTAL MOBIL (Transaksi ke-" << i + 1 << ") ---" << endl;

        file << "Tanggal Transaksi: " << __DATE__ << " " << __TIME__ << endl;

        file << "---------------------------------------" << endl;

        file << "Data Penyewa:" << endl;
        file << "Nama: " << rental.penyewa.nama << endl;
        file << "NIK: " << rental.penyewa.nik << endl;
        file << "No. HP: " << rental.penyewa.nohp << endl;
        file << "Alamat: " << rental.penyewa.alamat << endl;
        file << "Jenis Kelamin: " << (rental.penyewa.jeniskel ? "Laki-laki" : "Perempuan") << endl;

        file << "---------------------------------------" << endl;

        file << "Detail Sewa Mobil:" << endl;
        file << "Merek Mobil: " << getMEREK(rental.merek) << endl;
        file << "Nama Mobil: " << getMOBIL(rental.pil) << endl;
        file << "Paket Sewa: " << getPAKET(rental.paket) << endl;

        if (rental.paket == 1)
        {
            file << "Durasi: " << rental.jam << " Jam" << endl;
        }
        else if (rental.paket == 2)
        {
            file << "Durasi: " << rental.hari << " Hari" << endl;
        }
        else if (rental.paket == 3)
        {
            file << "Durasi: " << rental.week << " Minggu" << endl;
        }

        file << "Total Harga Sewa Mobil Ini: Rp " << rental.totalharga << endl;

        file << "---------------------------------------" << endl;

        file << "Informasi Pembayaran (untuk mobil ini):" << endl;
        file << "Jumlah Dibayar: Rp " << rental.totalbayar << endl;

        if (rental.totalbayar < rental.totalharga)
        {
            file << "Status Pembayaran: Pembayaran Kurang (Kekurangan: Rp " << (rental.totalharga - rental.totalbayar) << ")" << endl;
        }
        else
        {
            file << "Kembalian: Rp " << rental.kembalian << endl;
            file << "Status Pembayaran: Berhasil" << endl;
        }

        file << "=======================================\n\n";
    }

    file.close();

    cout << "Semua data rental berhasil disimpan ke file 'data_rental.txt'\n";
}

void cariPenyewaTerbanyak(const vector<RENTAL>& dataRENTAL)
{
    system("cls");
    if (dataRENTAL.empty())
    {
        cout << "Tidak ada data penyewa untuk dianalisis.\n";
        return;
    }

    vector<long long> nikList;
    for (size_t i = 0; i < dataRENTAL.size(); i++)
    {
        nikList.push_back(dataRENTAL[i].penyewa.nik);
    }

    long long banyaknik = -1;
    int totalhtg = 0;

    for (size_t i = 0; i < nikList.size(); i++)
    {
        int hitung = 0;
        for (size_t j = 0; j < nikList.size(); j++)
        {
            if (nikList[j] == nikList[i])
            {
                hitung++;
            }
        }
        if (hitung > totalhtg)
        {
            totalhtg = hitung;
            banyaknik = nikList[i];
        }
    }

    if (totalhtg > 0)
    {
        cout << "\nPenyewa paling sering menyewa (Total: " << totalhtg << " kali):\n";
        for (size_t i = 0; i < dataRENTAL.size(); i++)
        {
            if (dataRENTAL[i].penyewa.nik == banyaknik)
            {
                cout << "Penyewa #" << i + 1 << " (dari transaksi ini):\n";
                cout << "Nama: " << dataRENTAL[i].penyewa.nama << endl;
                cout << "NIK: " << dataRENTAL[i].penyewa.nik << endl;
                cout << "No HP: " << dataRENTAL[i].penyewa.nohp << endl;
                cout << "Mobil yang disewa: " << getMOBIL(dataRENTAL[i].pil) << endl;
                cout << "Total harga sewa mobil ini: Rp " << dataRENTAL[i].totalharga << endl;
                cout << "--------------------------\n";
            }
        }
    }
    else
    {
        cout << "\nSemua penyewa hanya menyewa satu kali atau tidak ada data yang cukup untuk analisis.\n";
    }
    cetakBingkaiAtasBawah(60, 1);
}

bool bandingdrs(const RENTAL &a, const RENTAL &b)
{
    return a.durasi < b.durasi;
}

void cariDurasiB(vector <RENTAL>& data){

    sort(data.begin(), data.end(), bandingdrs);

    long durasiCari;
    cout << "Masukkan durasi yang ingin dicari (dalam jam): ";
    cin >> durasiCari;
    clearInputBuffer();

    int low = 0;
    int high = data.size() - 1;
    int indextm = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (data[mid].durasi == durasiCari)
        {
            indextm = mid;
            while (indextm > 0 && data[indextm - 1].durasi == durasiCari)
            {
                indextm--;
            }
            break;
        }
        else if (data[mid].durasi < durasiCari)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (indextm != -1)
    {
        cout << "\nData ditemukan dengan durasi " << durasiCari << " jam:\n";
        for (size_t i = indextm; i < data.size() && data[i].durasi == durasiCari; ++i)
        {
            displayRENTAL(data[i], i);
        }
    }
    else
    {
        cout << "\nData dengan durasi jam tidak ditemukan.\n";
    }
    cetakBingkaiAtasBawah(60, 1);
}

void sortDurasi(vector<RENTAL> &data)
{
    int n = data.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j].durasi > data[j+1].durasi)
            {
                RENTAL temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

void tampilkanDataTerurut(vector<RENTAL> &data) {
    system("cls");
    cout << "\n=== Mengurutkan Data Berdasarkan Durasi Sewa (jam) ===" << endl;

    vector<RENTAL> sortedData = data;

    sortDurasi(sortedData);

    cout << "Data berhasil diurutkan berdasarkan durasi sewa (dari terkecil):\n";
    for (size_t i = 0; i < sortedData.size(); i++)
    {
        displayRENTAL(sortedData[i], i);
    }

    cariDurasiB(data);
}

int main()
{
    char lagi;
    Penyewa mainPenyewa;

    vector<RENTAL> dataRENTAL;

    cout<<"=========================================="<<endl;
    cout<<"            RENT4L 21                     "<<endl;
    cout<<"=========================================="<<endl;

    do{
        cout << "\n--- Masukkan Data Penyewa Utama ---" << endl;
        inputPenyewaData(mainPenyewa);
        system("cls");

        int jumlahMobilSewaSaatIni;
        long long totalHargaSesiIni = 0;
        vector<size_t> currentSessionRentalIndices;

        cout << "Berapa banyak Mobil yang ingin dipinjam pada sesi ini? ";
        cin >> jumlahMobilSewaSaatIni;
        clearInputBuffer();
        system("cls");

        for (int i = 0; i < jumlahMobilSewaSaatIni; ++i) {
            RENTAL currentRental;
            currentRental.penyewa = mainPenyewa;

            time_t now = time(0);
            tm *ltm = localtime(&now);
            stringstream ss;
            ss << (ltm->tm_year + 1900) << "-"
               << setw(2) << setfill('0') << (ltm->tm_mon + 1) << "-"
               << setw(2) << setfill('0') << ltm->tm_mday << " "
               << setw(2) << setfill('0') << ltm->tm_hour << ":"
               << setw(2) << setfill('0') << ltm->tm_min << ":"
               << setw(2) << setfill('0') << ltm->tm_sec;
            currentRental.tanggal = ss.str();

            cout << "\n--- Masukkan Detail Mobil ke-" << i + 1 << " ---" << endl;
            inputRENTAL(currentRental);

            totalHargaSesiIni += currentRental.totalharga;
            dataRENTAL.push_back(currentRental);
            currentSessionRentalIndices.push_back(dataRENTAL.size() - 1);

            if (i < jumlahMobilSewaSaatIni - 1) {
                cout << "\nTekan Enter untuk melanjutkan ke input mobil berikutnya...";
                cin.get();
                system("cls");
            }
        }

        cout << "\n==========================================" << endl;
        cout << "Total Harga untuk semua " << jumlahMobilSewaSaatIni << " mobil dalam sesi ini: Rp " << totalHargaSesiIni << endl;
        cout << "==========================================" << endl;

        long long pembayaranSesi;
        cout << "Masukkan jumlah uang yang dibayarkan untuk seluruh sesi ini: Rp ";
        cin >> pembayaranSesi;
        clearInputBuffer();

        long long kembalianSesi = pembayaranSesi - totalHargaSesiIni;

        if (pembayaranSesi < totalHargaSesiIni) {
            cout << "Mohon maaf, pembayaran kurang dari total harga sesi." << endl;
            cout << "Kekurangan: Rp " << (totalHargaSesiIni - pembayaranSesi) << endl;
        } else {
            cout << "Kembalian: Rp " << kembalianSesi << endl;
            cout << "Pembayaran Berhasil untuk seluruh sesi!" << endl;
        }
        cetakBingkaiAtasBawah(60,1);

        for (size_t i = 0; i < currentSessionRentalIndices.size(); ++i) {
            size_t index = currentSessionRentalIndices[i];
            dataRENTAL[index].totalbayar = pembayaranSesi;
            dataRENTAL[index].kembalian = kembalianSesi;
        }

        cout << "\npenyewa baru (y/n) ? : ";
        cin >> lagi;
        clearInputBuffer();
        system("cls");
    } while(lagi=='y'||lagi=='Y');

    system("cls");
    cout << "\n=== Ringkasan Semua Data Rental yang Dimasukkan ===\n";
    for (size_t i = 0; i < dataRENTAL.size(); i++) {
        displayRENTAL(dataRENTAL[i], i);
    }

    simpanDataKeFile(dataRENTAL);

    char cariDurasi, cariLain, cariPenyewa, urutkan;


    cout << "\nApakah Anda ingin mengurutkan data berdasarkan durasi sewa (dalam jam)? (y/n): ";
    cin >> urutkan;
    clearInputBuffer();

    if (urutkan == 'y' || urutkan == 'Y') {
        tampilkanDataTerurut(dataRENTAL);
    }

    cout << "\nApakah Anda ingin mencari dan menampilkan data rental tertentu (berdasarkan nomor entri)? (y/n): ";
    cin >> cariLain;
    clearInputBuffer();

    while (cariLain == 'y' || cariLain == 'Y') {
        system("cls");
        cariRENTAL(dataRENTAL);
        cout << "\nIngin mencari data lain? (y/n): ";
        cin >> cariLain;
        clearInputBuffer();
    }

    cariMobilTerpopuler(dataRENTAL);

    cout << "\nApakah Anda ingin mencari penyewa paling sering? (y/n): ";
    cin >> cariPenyewa;
    clearInputBuffer();

    if (cariPenyewa == 'y' || cariPenyewa == 'Y') {
        cariPenyewaTerbanyak(dataRENTAL);
    }

    cout << "\nProgram selesai. Terima kasih.\n";
    return 0;
}

