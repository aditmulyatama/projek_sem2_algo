#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
using namespace std;

struct dataLaptop{
    char id_laptop[5];
    char nama_laptop[90];
    long harga;
    int garansi, stok;
};

FILE *arsipLaptop;

void input(),output(),cari(),sorting(),transaksi();

int main()
{   
    system("cls");
    int pilih;



    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"| BACKSPACECOMPUTER.COM |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"1. INPUT DATA"<<endl;
    cout<<"2. OUTPUT DATA"<<endl;
    cout<<"3. CARI DATA"<<endl;
    cout<<"4. SORTING DATA"<<endl;
    cout<<"5. TRANSAKSI DATA"<<endl;
    cout<<"6. KELUAR"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"PILIH : "; cin>>pilih;

    switch (pilih)
    {
    case 1:
        input();
        break;
    case 2:
        output();
        break;
    case 3:
        cari();
        break;   
    case 4:
        sorting();
        break;
    case 5:
        transaksi();
        break;
    case 6:
        exit(1);
        break;        
    default:
        cout<<"Salah Input ! ";
        system("pause");
        main();
        break;
    }

    return 0;
}

void input(){
    dataLaptop laptop;
    char namaFile[50];
    int banyakData;
    system("cls");
    cout<<"masukkan nama file : "; cin>>namaFile;
    if((arsipLaptop=fopen(namaFile,"w"))==NULL){
        cout<<"file tidak dapat dibuat";
        input();
    }
    
    cout<<endl<<"Banyak Data : "; cin>>banyakData;
    cout<<endl;
    for (int i=1;i<=banyakData;i++){
        cout<<"ID laptop\t: "; cin>>laptop.id_laptop; 
        cout<<"Nama Laptop\t: "; cin>>laptop.nama_laptop;
        cout<<"Harga \t\t: ";cin>>laptop.harga;
        cout<<"Garansi \t: ";cin>>laptop.garansi;
        cout<<"Stok \t\t: ";cin>>laptop.stok;
        fwrite(&laptop,sizeof(laptop),1,arsipLaptop);
        cout<<endl<<endl;
    }
    fclose(arsipLaptop);
    system("pause");
    main();
}

void output(){
    char namaFile[50];
    dataLaptop laptop;
    system("cls");
    cout<<"Cari nama file : "; cin>>namaFile;
    arsipLaptop=fopen(namaFile,"r");
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    cout<<"   ID LAPTOP     NAMA LAPTOP      HARGA           GARANSI        STOK"<<endl;
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    while(fread(&laptop,sizeof(laptop),1,arsipLaptop)==1){
        cout<<"   "<<laptop.id_laptop<<"               ";
        cout<<laptop.nama_laptop<<"         ";
        cout<<laptop.harga<<"               ";
        cout<<laptop.garansi<<"         ";
        cout<<laptop.stok<<"         "<<endl;
    }
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    fclose(arsipLaptop);
    system("pause");
    main();
}

void cari(){
    cout<<"haha";
    system("cls");
    cout<<"mntap";
}

void sorting(){
    system("cls");
    cout<<"mantap";
}

void transaksi(){
    system("cls");
    cout<<"mantap";
}

