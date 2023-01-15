#include <iostream> //PROJEK MABA 2022 HEHE
#include <fstream>

using namespace std;

struct data
{
    string nama;
    string jurusan;
    int umur, presensi[999];
    float nilai[999];
};

void display(int a, int b, int c) // fungsi input dan menyimpan ke file txt
{
    struct data mhs;
    //=================================input======================================
    for (int d = 1; d <= a; d++)
    {
        cout << " Masukan data mahasiswa ke-" << d << endl;
        cout << " Nama mahasiswa    : ";
        cin >> mhs.nama;
        cout << " Umur mahasiswa    : ";
        cin >> mhs.umur;
        cout << " Jurusan mahasiswa : ";
        cin >> mhs.jurusan;
        cout << endl;
        cout << " Masukan presensi mahasiswa (1 = hadir, 0 = tidak hadir)\n";
        for (int e = 0; e < b; e++)
        {
            cout << " Pertemuan ke " << e + 1 << " : ";
            cin >> mhs.presensi[e];
            cout << " Nilai : ";
            cin >> mhs.nilai[e];
            cout << endl;
        }

        //============================================================================
        system("cls");
        //=========================menyimpan ke file txt dan output===================
        ofstream simpanText("Mhs.txt", ios::app);
        simpanText << " Data mahasiswa ke-" << d << endl;
        simpanText << " Nama mahasiswa    : " << mhs.nama << endl;
        simpanText << " Umur mahasiswa    : " << mhs.umur << endl;
        simpanText << " Jurusan mahasiswa : " << mhs.jurusan << endl
                   << endl;
        simpanText << " Data presensi mahasiswa :\n";
        for (int e = 0; e < b; e++)
        {
            if (mhs.presensi[e] == 1)
            {
                simpanText << " Pertemuan ke " << e + 1 << " : Hadir\n";
            }
            else if (mhs.presensi[e] == 0)
            {
                simpanText << " Pertemuan ke " << e + 1 << " : Tidak hadir\n";
            }

            simpanText << " Nilai : " << mhs.nilai[e] << endl;
        }
        simpanText << "====================================================================\n"
                   << endl;
        simpanText.close();
    }
    system("START /MIN NOTEPAD Mhs.txt");
    //============================================================================
}

void bacaData() //============================output layar========================
{
    ifstream bacaFile("mhs.txt"); // membaca file
    string tampungData;

    while (getline(bacaFile, tampungData))
    {
        cout << tampungData << endl; // menampilkan file
    }

} //==============================================================================

int main()
{
    int a, b, c;
    cout << "==========================================\n";
    cout << "===Program Presensi Dan Nilai Mahasiswa===\n";
    cout << "==========================================\n";
    cout << " Masukan Jumlah Mahasiswa: ";
    cin >> a;
    cout << " Masukan Jumlah Pertemuan: ";
    cin >> b;
    cout << endl;

    display(a, b, c);
    bacaData();
    return 0;
}
