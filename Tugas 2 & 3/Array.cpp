#include <iostream>
using namespace std;

int main()
{
    int jumlah_data;
    int nilai_pelajaran[jumlah_data] = {};
    /*
    [3] bisa langsung diisi = {30,50,100}
    [] = {}, klo kosong bisa fleksible
    */

    cout << "Silahkan masukkan jumlah data nilai pelajaran : ";
    cin >> jumlah_data;

    for (int i = 0; i < jumlah_data; i++)
    {
        cout << endl
             << "Nilai ke " << i + 1 << endl;
        cout << "Nilai pelajaran : ";
        cin >> nilai_pelajaran[i];
        cout << endl;
    }

    /* Manual :
    cout << "nilai bahasa inggris : ";
    cin >> nilai_pelajaran[0];

    cout << "nilai bahasa indonesia : ";
    cin >> nilai_pelajaran[1];

    cout << "nilai fisika : ";
    cin >> nilai_pelajaran[2];

    float rata_rata = ((nilai_pelajaran[1] + nilai_pelajaran[0] + nilai_pelajaran[2]) / jumlah_data);

    cout << "Rata Rata : " << rata_rata; */
}