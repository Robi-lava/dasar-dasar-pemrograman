#include <iostream>
using namespace std;

int main()
{
    string user, pass, user_benar = "robi", pass_benar = "155";
    int angka_tebak, angka_benar = 7, menu;

    cout << "Selamat Datang Silahkan Login\n";
    do
    {
        cout << "Masukkan Username :";
        cin >> user;
        cout << "Masukkan Password :";
        cin >> pass;
        if (user == user_benar && pass == pass_benar)
        {
            cout << "Pilih menu : \n";
            cout << "1. Games Tebak-Tebakan \n";
            cout << "2. Exit\n";
            cout << "Pilih menu : ";
            cin >> menu;

            switch (menu)
            {
            case 1:
                cout << "Selamat datang di permainan tebak angka\n";
                cout << "Tebak angka dari 1-10\n";

                do
                {
                    cout << "Masukkan angka tebakan : ";
                    cin >> angka_tebak;
                    if (angka_tebak > angka_benar)
                    {
                        cout << "Angka terlalu besar\n";
                    }
                    else if (angka_tebak < angka_benar)
                    {
                        cout << "Angka terlalu kecil\n";
                    }
                    else
                    {
                        break;
                    }
                } while (angka_tebak != angka_benar);

                {
                    cout << "Selamat tebakan anda benar";
                }
                break;
            case 2:
                cout << "Exit, sampai jumpa";
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "Login gagal, Coba lagi\n";
        }
    } while (user != user_benar && pass != pass_benar);
}
