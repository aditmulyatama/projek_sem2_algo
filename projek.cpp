#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
using namespace std;

struct dataLaptop{
    int id_laptop;
    char nama_laptop[90];
    long harga;
    int garansi, stok;
};

FILE *arsipLaptop,*f1,*f2,*f3;

void input(),output(),cari(),sorting(),transaksi(),lihat(char a[]);

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
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|      INPUT DATA       |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
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
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|      OUTPUT DATA      |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"Cari nama file : "; cin>>namaFile;
    arsipLaptop=fopen(namaFile,"r");
    cout<<endl<<endl<<endl<<setfill('=')<<setw(75)<<"="<<endl;
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
  
    system("cls");
    cout<<"mntap";
}

void sorting(){
    system("cls");
    cout<<"mantap";
}

void transaksi(){
    system("cls");
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|    TRANSAKSI DATA     |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    char file1[50],file2[50],file3[50];
    dataLaptop laptop;
    int pilih;
    int jmlData=0,batas,z=1;
    cout<<"1. Merging Sambung \n2. Splitting\nPilih : "; cin>>pilih;

    switch (pilih)
    {
    case 1:
        system("cls");
        cout<<setfill('=')<<setw(25)<<"="<<endl;
        cout<<"|    Merging Sambung    |"<<endl;
        cout<<setfill('=')<<setw(25)<<"="<<endl;
        cout<<"Masukkan nama file 1 : ";cin>>file1;
        lihat(file1);
        cout<<"\nMasukkan nama file 2 : ";cin>>file2;
        lihat(file2);
        cout<<"\n\nMasukkan nama file sambung : ";cin>>file3;

        if ((f1 = fopen(file1,"r"))==NULL || (f2 = fopen(file2,"r"))==NULL || (f3 = fopen(file3,"w"))==NULL)
        { 
            cout<<"File gagal!\n ";
            exit(1);
        }

        while(fread(&laptop,sizeof(laptop),1,f1)){
            fwrite(&laptop,sizeof(laptop),1,f3);
        } while(fread(&laptop,sizeof(laptop),1,f2)){
            fwrite(&laptop,sizeof(laptop),1,f3);
        }

        cout<<"file berhasil disambungkan ! ";
        
        fclose(f1); fclose(f2); fclose(f3);
        break;
    
    case 2:
        system("cls");
        cout<<setfill('=')<<setw(25)<<"="<<endl;
        cout<<"|    Splitting File     |"<<endl;
        cout<<setfill('=')<<setw(25)<<"="<<endl;
        cout<<"Masukkan nama file yang akan dibagi menjadi 2 file: ";cin>>file1;
        lihat(file1);
         cout<<"Masukkan nama file 1 : ";cin>>file2;
         cout<<"\nMasukkan nama file 2 : ";cin>>file3;
        if ((f1 = fopen(file1,"r"))==NULL || (f2 = fopen(file2,"w"))==NULL || (f3 = fopen(file3,"w"))==NULL)
        { 
            cout<<"File gagal dibuka!\n ";
            exit(1);
        }
        while(fread(&laptop,sizeof(laptop),1,f1)){
            jmlData++;
        }
        fclose(f1);
        f1 = fopen(file1,"r");
        batas=jmlData/2;
        
        while(fread(&laptop,sizeof(laptop),1,f1)){
            if(z<batas) {
                fwrite(&laptop,sizeof(laptop),1,f2);
                z++;
            }
            else if (batas <= jmlData){ 
                fwrite(&laptop,sizeof(laptop),1,f3);
                batas++;
            
             }
        }
        fclose(f1); fclose(f2); fclose(f3);
        system ("pause");
        break;
    default:
        break;
    }
    main();
}

void lihat(char namaFile[]){
    dataLaptop laptop;
    arsipLaptop=fopen(namaFile,"r");
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    cout<<"   ID LAPTOP     NAMA LAPTOP      HARGA           GARANSI        STOK"<<endl;
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    while(fread(&laptop,sizeof(laptop),1,arsipLaptop)==1){
        cout<<"   "<<laptop.id_laptop<<"               ";
        cout<<laptop.nama_laptop<<"         ";
        cout<<laptop.harga<<"            ";
        cout<<laptop.garansi<<"         ";
        cout<<laptop.stok<<"         "<<endl;
    }
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    fclose(arsipLaptop);
}

