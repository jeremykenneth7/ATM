#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
using namespace std;
void cek();
void tarik();
void deposit();
void transfer();
void riwayat();
void pendaftaran();
void login();
void menu();

struct acc
{
    string nama;
    string pass;
    int saldo;
    long int norek;
    char KD;
};

struct nasabah
{
    string nama;
    string pass;
    int saldo;
    long int norek;
};
acc penerima[50];
nasabah akun[50];
nasabah masuk;
int i , j, n, m;

int main()
{
    int pilih;

    cout << "++===========================================++" << endl;
    cout << "||            SELAMAT DATANG DI ATM          ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "||                  Menu :                   ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "||              1. Pendaftaran               ||" << endl;
    cout << "||              2. Login                     ||" << endl;
    cout << "||              3. Exit                      ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "Pilih salah satu : ";
    cin >> pilih;

    if (pilih == 1)
    {
        pendaftaran();
    }
    if (pilih == 2)
    {
        login();
    }
    if (pilih == 3)
    {
        cout << "\nTERIMA KASIH TELAH MENGGUNAKAN JASA KAMI" << endl;
        exit(0);
    }
    return 0;
}

void cek()
{
    //read file
    ifstream ifs(akun[j].nama);
    int banyak_data = 0;
    if (ifs.is_open())
    {
        int i = banyak_data;
        while (!ifs.eof())
        {   
            ifs >> penerima[i].nama >> penerima[i].norek >> penerima[i].saldo >> penerima[i].KD >> akun[i].saldo; 
            i++;
        }
        banyak_data = banyak_data + i - 1 ;
        ifs.close();
    }

    cout << "Saldo Anda = Rp. " << akun[banyak_data-1].saldo << endl;
}

void tarik()
{
    int pilih, riktun;
    //read file
    ifstream ifs(akun[j].nama);
    int banyak_data = 0;
        if (ifs.is_open())
        {
            int i = banyak_data;
            while (!ifs.eof())
            {   
                ifs >> penerima[i].nama >> penerima[i].norek >> penerima[i].saldo >> penerima[i].KD >> akun[i].saldo; 
                i++;
            }
            banyak_data = banyak_data + i - 1 ;
            ifs.close();
        }

    cout << "++===========================================++" << endl;
    cout << "||                Penarikan                  ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "Saldo Anda \t\t= Rp. " << akun[banyak_data-1].saldo << endl << endl;

    cout << "++===========================================++" << endl;
    cout << "||            1. Rp. 100.000,00              ||" << endl;
    cout << "||            2. Rp. 250.000,00              ||" << endl;
    cout << "||            3. Rp. 500.000,00              ||" << endl;
    cout << "||            4. Rp. 750.000,00              ||" << endl;
    cout << "||            5. Rp. 1.000.000,00            ||" << endl;
    cout << "++===========================================++" << endl;

    cout << "Masukkan Pilihan  \t: ";
    cin >> pilih;
    if (pilih == 1)
    {
        riktun = 100000;
    }
    if (pilih == 2)
    {
        riktun = 250000;
    }
    if (pilih == 3)
    {
        riktun = 500000;
    }
    if (pilih == 4)
    {
        riktun = 750000;
    }
    if (pilih == 5)
    {
        riktun = 1000000;
    }
    cout << "===============================================" << endl;
    if (akun[banyak_data-1].saldo < riktun){
        cout << "Saldo Anda Tidak Mencukupi." << endl;
    }
    else{
        akun[banyak_data-1].saldo = akun[banyak_data-1].saldo - riktun;
        cout << "Saldo Anda Sekarang \t= Rp. " << akun[banyak_data-1].saldo << endl;
        penerima[i].nama = "Tarik_Tunai";
        penerima[i].norek = 8282000+banyak_data;
        penerima[i].saldo = riktun;
        penerima[i].KD = 'K';
        ofstream ofs2(akun[j].nama, ios::app);
        if (ofs2.is_open())
        {   
            ofs2 << left << setw(20) << penerima[i].nama 
                << setw(20) << penerima[i].norek
                << setw(20) << penerima[i].saldo
                << setw(20) << penerima[i].KD
                << setw(20) << akun[banyak_data-1].saldo
                << endl; 
            ofs2.close();
        }
    }

}


void deposit()
{
    int pilih, deposit;
    //read file
    ifstream ifs(akun[j].nama);
    int banyak_data = 0;
    if (ifs.is_open())
    {
        int i = banyak_data;
        while (!ifs.eof())
        {   
            ifs >> penerima[i].nama >> penerima[i].norek >> penerima[i].saldo >> penerima[i].KD >> akun[i].saldo; 
            i++;
        }
        banyak_data = banyak_data + i - 1 ;
        ifs.close();
    }

    cout << "++===========================================++" << endl;
    cout << "||                Isi Saldo                  ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "Saldo Anda \t\t= Rp. " << akun[banyak_data-1].saldo << endl;
    cout << "++===========================================++" << endl;
    cout << "||            1. Rp. 100.000,00              ||" << endl;
    cout << "||            2. Rp. 250.000,00              ||" << endl;
    cout << "||            3. Rp. 500.000,00              ||" << endl;
    cout << "||            4. Rp. 750.000,00              ||" << endl;
    cout << "||            5. Rp. 1.000.000,00            ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "Masukkan Pilihan \t: ";
    cin >> pilih;
    if (pilih == 1)
    {
        deposit = 100000;
    }
    if (pilih == 2)
    {
        deposit = 250000;
    }
    if (pilih == 3)
    {
        deposit = 500000;
    }
    if (pilih == 4)
    {
        deposit = 750000;
    }
    if (pilih == 5)
    {
        deposit = 1000000;
    }
    cout << "===============================================" << endl;
    akun[banyak_data-1].saldo = akun[banyak_data-1].saldo + deposit;
    cout << "Saldo Anda Sekarang        : Rp. " << akun[banyak_data-1].saldo << endl;
    penerima[i].nama = "Isi_Saldo";
    penerima[i].norek = 9292000+banyak_data;
    penerima[i].saldo = deposit;
    penerima[i].KD = 'D';
    ofstream ofs2(akun[j].nama, ios::app);
    if (ofs2.is_open())
    {   
        ofs2 << left << setw(20) << penerima[i].nama 
            << setw(20) << penerima[i].norek
            << setw(20) << penerima[i].saldo
            << setw(20) << penerima[i].KD
            << setw(20) << akun[banyak_data-1].saldo
            << endl; 
        ofs2.close();
    }
}

void transfer()
{
    int pilih;
    //read file
    ifstream ifs(akun[j].nama);
    int banyak_data = 0;
    if (ifs.is_open())
    {
        int i = banyak_data;
        while (!ifs.eof())
        {   
            ifs >> penerima[i].nama >> penerima[i].norek >> penerima[i].saldo >> penerima[i].KD >> akun[i].saldo; 
            i++;
        }
        banyak_data = banyak_data + i - 1 ;
        ifs.close();
    }

    cout << "++===========================================++" << endl;
    cout << "||                 Transfer                  ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "Saldo Anda                 : Rp. " << akun[banyak_data-1].saldo << endl;

    cout << "Masukkan Username Penerima : ";
    cin.ignore();
    getline(cin, penerima[i].nama);
    cout << "Masukkan No.Rek Penerima   : ";
    cin >> penerima[i].norek;
    penerima[i].KD = 'K';

    cout << "++===========================================++" << endl;
    cout << "||            1. Rp. 50.000,00               ||" << endl;
    cout << "||            2. Rp. 100.000,00              ||" << endl;
    cout << "||            3. Rp. 250.000,00              ||" << endl;
    cout << "||            4. Rp. 500.000,00              ||" << endl;
    cout << "||            5. Rp. 750.000,00              ||" << endl;
    cout << "||            6. Rp. 1.000.000,00            ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "Masukkan Pilihan \t: ";
    cin >> pilih;
    if (pilih == 1)
    {
        penerima[i].saldo = 50000;
    }
    if (pilih == 2)
    {
        penerima[i].saldo = 100000;
    }
    if (pilih == 3)
    {
        penerima[i].saldo = 250000;
    }
    if (pilih == 4)
    {
        penerima[i].saldo = 500000;
    }
    if (pilih == 5)
    {
        penerima[i].saldo = 750000;
    }
    if (pilih == 6)
    {
        penerima[i].saldo = 1000000;
    }
    cout << "===============================================" << endl;
    if (akun[banyak_data-1].saldo < penerima[i].saldo)
    {
        cout << "Transfer Tidak Berhasil. Saldo Anda Tidak Mencukupi." << endl;
    }
    else
    {    
        akun[banyak_data-1].saldo = akun[banyak_data-1].saldo - penerima[i].saldo;
        cout << "Transfer Berhasil." << endl;
        cout << "Nama Penerima      \t: " << penerima[i].nama << endl;
        cout << "No.REK Pemenerima  \t: " << penerima[i].norek << endl;
        cout << "Saldo Anda Sekarang \t= Rp. " << akun[banyak_data-1].saldo << endl;
        ofstream ofs2(akun[j].nama, ios::app);
        if (ofs2.is_open())
        {   
            ofs2 << left << setw(20) << penerima[i].nama 
                << setw(20) << penerima[i].norek
                << setw(20) << penerima[i].saldo
                << setw(20) << penerima[i].KD
                << setw(20) << akun[banyak_data-1].saldo
                << endl; 
            ofs2.close();
        }
    }
}

void riwayat()
{
    //read file
    ifstream ifs(akun[j].nama);
    int banyak_data = 0;
    if (ifs.is_open())
    {
        int i = banyak_data;
        while (!ifs.eof())
        {   
            ifs >> penerima[i].nama >> penerima[i].norek >> penerima[i].saldo >> penerima[i].KD >> akun[i].saldo; 
            i++;
        }
        banyak_data = banyak_data + i - 1 ;
        ifs.close();
    }
    cout << "++===========================================++" << endl;
    cout << "||             Riwayat Transaksi             ||" << endl;
    cout << "++===========================================++" << endl;
    cout << "| Ket./Penerima | No. REK    | Jumlah   | K/D |" << endl;
    cout << "+=============================================+" << endl;
    for (i = 0; i < banyak_data; i++)
    {
        cout << "| " << setw(14) << setfill(' ') << setiosflags(ios::left)<< penerima[i].nama;
        cout << "| " << setw(11) << setfill(' ') << setiosflags(ios::left)<< penerima[i].norek;
        cout << "| " << setw(9) << setfill(' ') << setiosflags(ios::left)<< penerima[i].saldo;
        cout << "| " << setw(4) << setfill(' ') << setiosflags(ios::left)<< penerima[i].KD << "|" <<endl;
    }
    cout << "+=============================================+" << endl;
}

void menu() 
{
    int pilih;
    char backtomenu;

    do
    {
    
        cout << "++===========================================++" << endl;
        cout << "||                   Menu                    ||" << endl;
        cout << "++===========================================++" << endl;
        cout << "|| 1. Cek Saldo                              ||" << endl;
        cout << "|| 2. Penarikan                              ||" << endl;
        cout << "|| 3. Isi Saldo                              ||" << endl;
        cout << "|| 4. Transfer                               ||" << endl;
        cout << "|| 5. Riwayat Transaksi                      ||" << endl;
        cout << "|| 6. Logout                                 ||" << endl;
        cout << "++===========================================++" << endl;
        cout << "Pilih salah satu : ";
        cin >> pilih;


        if (pilih == 1) 
        {
            cek();
        } 
        else if (pilih == 2) 
        {
            tarik();
        }
        else if (pilih == 3) 
        {
            deposit();
        }
        else if (pilih == 4) 
        {
            transfer();
        }
        else if (pilih ==  5)
        {
            riwayat();
        }
        else if (pilih == 6)
        {
            system("cls");
            main();
        }
        cout << "Kembali ke Menu (y/n) ? ";
        cin >> backtomenu;
        system("cls");
    } 
    while (backtomenu == 'y' || backtomenu == 'Y');
    main();
}

void pendaftaran()
{
    cout << endl;

    cout << "++===========================================++" << endl;
    cout << "||                Pendaftaran                ||" << endl;
    cout << "++===========================================++" << endl;
    
    cout << "Masukkan Username          : ";
    cin.ignore();
    getline(cin,akun[j].nama);
    cout << "Masukkan Password          : ";
    cin >> akun[j].pass;
    cout << "Masukkan No. Rekening(NIM) : ";
    cin >> akun[j].norek;
    cout << "Masukkan Saldo Awal        : ";
    cin >> akun[j].saldo;

    ofstream ofs(".txt", ios::app);
        if (ofs.is_open())
        {   
            ofs << left << setw(20) << akun[j].nama 
                << setw(20) << akun[j].pass
                << setw(20) << akun[j].norek
                << endl; 
            ofs.close();
        }

    penerima[i].nama = akun[j].nama;
    penerima[i].norek = akun[j].norek;
    penerima[i].saldo = akun[j].saldo;
    penerima[i].KD = 'D';

    ofstream ofs2(akun[j].nama, ios::app);
        if (ofs2.is_open())
        {   
            ofs2 << left << setw(20) << penerima[i].nama 
                << setw(20) << penerima[i].norek
                << setw(20) << penerima[i].saldo
                << setw(20) << penerima[i].KD
                << setw(20) << akun[j].saldo
                << endl; 
            ofs2.close();
        }

    system("cls");
    main();
}

void login()
{
    cout << endl;
    cout << "++===========================================++" << endl;
    cout << "||                   Login                   ||" << endl;
    cout << "++===========================================++" << endl;
 
    char relog;
    
    ifstream ifs(".txt");
    int banyak_data = 0;
        if (ifs.is_open())
        {
            int i = banyak_data;
            while (!ifs.eof())
            {   
                ifs >> akun[i].nama >> akun[i].pass >> akun[i].norek; 
                i++;
            }
            banyak_data = banyak_data + i - 1 ;
            ifs.close();
        }

    cout << "Masukkan Username          : ";
    cin.ignore();
    getline(cin,masuk.nama);

    cout << "Masukkan Password          : ";
    cin >> masuk.pass;
    bool found = false;
    j = 0;
    while((j < banyak_data) & (!found))
    {
        if(akun[j].nama == masuk.nama)
        found = true;
        else 
        j = j + 1;
    }
    if(found){
        if(masuk.pass == akun[j].pass){
            cout << "Login berhasil!" << endl;
            cout << "Press any key to continue . . . ";
            getch();
            system("cls");
            menu();
        }

        if(masuk.pass != akun[j].pass) { 
            cout << "Password salah" << endl;
            cout << "Login lagi ? (y/n)"; cin >> relog;
            if(relog == 'y' or relog == 'Y'){
                system("cls");
                login();
            }
            if(relog == 'n' or relog == 'N'){
                system("cls");
                main();
            }
        }
    }
    else{
        cout << "Username atau Password Anda belum terdaftar atau salah," << endl;
        cout << "pilih pendaftaran" << endl;
        cout << "Press any key to continue . . . ";
        getch();
        system("cls");
        main();
    }
}