#include <iostream>
#include <iomanip>
using namespace std;

struct permainan
{
    int id;
    string nama;
    string genre;
    int harga;
};

int menu;
int bnyk_game;
permainan game[100];

void tambah_game()
{
    cout << "Berapa banyak game yang ingin di tambah? ";
    cin >> bnyk_game;
    cout << endl;

    for (int i = 0; i < bnyk_game; i++)
    {
        cout << "Masukkan ID Game : ";
        cin >> game[i].id;
        cout << "Masukkan Nama Game : ";
        cin.ignore();
        getline(cin, game[i].nama);
        cout << "Masukkan Genre Game : ";
        getline(cin, game[i].genre);
        cout << "Masukkan Harga Game : ";
        cin >> game[i].harga;
        cout << endl;
    }
    cout << "Data Berhasil Ditambahkan!";
    cout << endl;
}

void tampilkan_game()
{
    cout << "ID  | Nama Game | Genre | Harga " << endl;
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < bnyk_game; i++)
    {
        cout << game[i].id << " | " << game[i].nama << " | " << game[i].genre << " | " << game[i].harga << endl;
    }
    cout << endl;
}

void edit_game()
{
    int id_ubah;
    cout << "Masukkan Id game yang ingin di ubah : ";
    cin >> id_ubah;
    cin.ignore();
    bool benar = false;
    int index_game;
    for (int i = 0; i < bnyk_game; i++)
    {
        if (game[i].id == id_ubah)
        {
            benar = true;
            index_game = i;
            break;
        }
    }
    if (benar)
    {
        cout << "Data lama : " << game[index_game].nama << " - " << game[index_game].genre << " - " << game[index_game].harga << endl;

        cout << "Masukkan Nama Game baru : ";
        getline(cin, game[index_game].nama);
        cout << "Masukkan Genre Game baru : ";
        getline(cin, game[index_game].genre);
        cout << "Masukkan Harga Game baru : " << endl;
        // getline(cin,game[index_game].harga); //-> getline nya kalau dipake jadi error, katanya no matching function for call to 'getline()'
        cout << "Data Game Berhasil Diedit!";
        cout << endl;
    }
    else
    {
        cout << "Id Buku tidak Ditemukan.";
        cout << endl;
    }
}

void hapus_game()
{
    int id_hapus;
    cout << "Masukkan Id Game yang ingin di hapus : ";
    cin >> id_hapus;
    bool hapus = false;
    int index_hapus;

    for (int i = 0; i < bnyk_game; i++)
    {
        if (game[i].id == id_hapus)
        {
            hapus = true;
            index_hapus = i;
            break;
        }
    }
    if (hapus)
    {
        for (int i = index_hapus; i < bnyk_game; i++)
        {
            game[i] = game[i + 1];
        }
        bnyk_game--;
        cout << "Game Berhasil dihapus!";
        cout << endl;
    }
    else
    {
        cout << "Id Buku tidak Ditemukan.";
        cout << endl;
    }
}

void beli_game()
{
    int total_harga = 0;
    int diskon_voucher;
    int bnyk_game_dibeli;
    char jawab;
    char jawab_benar = 'Y';
    string kode;
    string kode_benar = "JPYUM";
    int id_game_dibeli[100];

    cout << "Masukkan jumalh game yang ingin di beli : ";
    cin >> bnyk_game_dibeli;
    for (int i = 0; i < bnyk_game_dibeli; i++)
    {
        cout << "Masukkan Id Game yang ingin di beli : " << endl;
        cout << "Id Game ke-" << (i + 1) << endl;
        cin >> id_game_dibeli[i];
    }
    for (int i = 0; i < bnyk_game_dibeli; i++)
    {
        for (int j = 0; j < bnyk_game; j++)
        {
            if (id_game_dibeli[i] == game[j].id)
            {
                total_harga += game[i].harga;
                break;
            }
        }
    }
    cout << "Apakah Anda Punya Kode Voucher? (Y/N)";
    cin >> jawab;
    cout << endl;
    if (jawab == jawab_benar)
    {
        cout << "Masukkan Kode Voucher : ";
        cin >> kode;
        if (kode == kode_benar)
        {
            cout << "Kode Benar, Diskon 10% Diterapkan!" << endl;
            diskon_voucher = total_harga - (total_harga * 0.10);
            cout << "Total Harga : " << diskon_voucher;
            cout << endl;
        }
        else
        {
            cout << "Kode Salah";
            cout << endl;
        }
    }
    else
    {
        cout << "Total Harga : " << total_harga;
        cout << endl;
    }
}

int main()
{
    do
    {
        cout << "===Sistem Pembelian Game Digital ===" << endl;
        cout << "1. Tambah Game" << endl;
        cout << "2. Tampilkan Daftar Game" << endl;
        cout << "3. Edit Data Game" << endl;
        cout << "4. Hapus Data Game" << endl;
        cout << "5. Beli Game" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            tambah_game();
            break;
        case 2:
            tampilkan_game();
            break;
        case 3:
            edit_game();
            break;
        case 4:
            hapus_game();
            break;
        case 5:
            beli_game();
            break;
        case 6:
            cout << "Keluar dari Program, Selamat Tinggal!";
            cout << endl;
            break;
        default:
            cout << "Menu Tidak Tersedia";
            cout << endl;
            break;
        }
    } while (menu != 6);
}