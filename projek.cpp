#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#define MAX 100
using namespace std;

struct dataLaptop{
    int id_laptop;
    char nama_laptop[90];
    long harga;
    int garansi, stok;
};

FILE *arsipLaptop,*f1,*f2,*f3;

void input(),output(),cari(),sorting(),transaksi(),lihat(char a[]),
bubblesort(dataLaptop laptop[], int banyakData),quicksort(dataLaptop laptop[], int first,int last),
shellsort(dataLaptop laptop[], int banyakData),insertsort(dataLaptop laptop[], int banyakData),
selectionsort(dataLaptop laptop[], int banyakData);

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
    dataLaptop laptop[MAX];
    char namaFile[50];
    int banyakData=0;
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
    for (int i=0;i<banyakData;i++){
        cout<<"ID laptop\t: "; cin>>laptop[i].id_laptop; 
        cout<<"Nama Laptop\t: "; cin>>laptop[i].nama_laptop;
        cout<<"Harga \t\t: ";cin>>laptop[i].harga;
        cout<<"Garansi \t: ";cin>>laptop[i].garansi;
        cout<<"Stok \t\t: ";cin>>laptop[i].stok;
        fwrite(&laptop[i],sizeof(laptop[i]),1,arsipLaptop);
        cout<<endl<<endl;
    }
    fclose(arsipLaptop);
    system("pause");
    main();
}

void output(){
    char namaFile[50];
    dataLaptop laptop[MAX];
    int i=0;

    system("cls");
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|      OUTPUT DATA      |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"Cari nama file : "; cin>>namaFile;
    cout<<endl<<endl<<endl;
    if((arsipLaptop=fopen(namaFile,"r"))==NULL){
        cout<<"File tidak ditemukan :(\n\n";
    } else {
        lihat(namaFile);
    }
    
    
    fclose(arsipLaptop);
    system("pause");
    main();
}

void cari(){
    bool found=false;
    char cari[50];
    int id_cari,metode;
    dataLaptop laptop[MAX];
    int i=0,banyakData=0,tengah=0;

    system("cls");
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|      CARI DATA      |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"Cari nama file : "; cin>>cari;

    if((arsipLaptop=fopen(cari,"r"))==NULL){
        cout<<"File tidak ditemukan :(\n\n";
    } else {
        cout<<"Cari data berdasarkan ID : "; cin>>id_cari;
        cout<<endl<<endl;
        atas:
        cout<<"Pilih metode pencarian\n1. Sequential Search\n2. Binary Search\nPilih : ";
        cin>>metode;
        switch (metode){
            case 1:
                while((fread(&laptop[i],sizeof(laptop[i]),1,arsipLaptop)==1)&&!found){
                if(id_cari==laptop[i].id_laptop){
                    found=true;
                    cout<<"\nData ditemukan!";
                    } 
                    i++;
                }
            
                if(found){
                    i--;
                    cout<<endl<<endl<<endl<<setfill('=')<<setw(75)<<"="<<endl;
                    cout<<"   ID LAPTOP     NAMA LAPTOP      HARGA           GARANSI        STOK"<<endl;
                    cout<<setfill('=')<<setw(75)<<"="<<endl;
                    cout<<"   "<<laptop[i].id_laptop<<"               ";
                    cout<<laptop[i].nama_laptop<<setfill(' ')<<setw(20-strlen(laptop[i].nama_laptop));
                    cout<<laptop[i].harga<<"               ";
                    cout<<laptop[i].garansi<<"         ";
                    cout<<laptop[i].stok<<"         "<<endl;
                    cout<<setfill('=')<<setw(75)<<"="<<endl;
                } else {
                    cout<<"Data tidak ditemukan :(\n\n";
                }
            break;
                 

            case 2:
                while((fread(&laptop[i],sizeof(laptop[i]),1,arsipLaptop)==1)){
                    i++;
                    banyakData++;
                 }
                 quicksort(laptop,0,banyakData);
                 i=0;
                 while((!found)&&i<=banyakData){
                    tengah=(i+banyakData)/2;
                    if(id_cari==laptop[tengah].id_laptop){
                        found=true;
                    } else if(id_cari<laptop[tengah].id_laptop){
                        banyakData=tengah-1;
                    } else {
                        i=tengah+1;
                    }
                 }
                 if(found){
                   
                    cout<<endl<<endl<<endl<<setfill('=')<<setw(75)<<"="<<endl;
                    cout<<"   ID LAPTOP     NAMA LAPTOP      HARGA           GARANSI        STOK"<<endl;
                    cout<<setfill('=')<<setw(75)<<"="<<endl;
                    cout<<"   "<<laptop[tengah].id_laptop<<"               ";
                    cout<<laptop[tengah].nama_laptop<<setfill(' ')<<setw(20-strlen(laptop[tengah].nama_laptop));
                    cout<<laptop[tengah].harga<<"               ";
                    cout<<laptop[tengah].garansi<<"         ";
                    cout<<laptop[tengah].stok<<"         "<<endl;
                    cout<<setfill('=')<<setw(75)<<"="<<endl;
                } else {
                    cout<<"Data tidak ditemukan :(\n\n";
                }

            break;

            default :
                cout<<"Salah Input\n\n";
                system("pause");
                goto atas;


        }
        
    }
    
    
    fclose(arsipLaptop);
    system("pause");
    main();
}

void sorting(){
    char namaFile[50];
    dataLaptop laptop[MAX];
    int i=0,banyakdata=0;
    int pilih;
    system("cls");
    
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|     SORTING DATA      |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"Cari nama file : "; cin>>namaFile;
    lihat(namaFile);
    if((arsipLaptop=fopen(namaFile,"r"))==NULL){
        cout<<"File tidak ditemukan :(\n\n";
    } else {
       
        while(fread(&laptop[i],sizeof(laptop[i]),1,arsipLaptop)==1){
            banyakdata++;
            i++;
        }
        atas:
        cout<<endl<<endl;
        cout<<setfill('=')<<setw(25)<<"="<<endl;
        cout<<"|     METHOD SORTING      |"<<endl;
        cout<<setfill('=')<<setw(25)<<"="<<endl;
        cout<<"1. Bubble \n2. Quick Sort\n3. Shell Sort\n4. Insertion Sort\5. Selection Sort \nPilih : "; cin>>pilih;
        switch(pilih){
            case 1:
            bubblesort(laptop,banyakdata);
            break;

            case 2:
            quicksort(laptop,0,banyakdata-1);
            break;

            case 3:
            shellsort(laptop,banyakdata);
            break;

            case 4:
            insertsort(laptop,banyakdata);
            break;

            case 5:
            selectionsort(laptop,banyakdata);
            break;

            default:
            cout<<"Salah input ! "<<endl;
            system("pause");
            goto atas;
        }
        cout<<endl<<endl;
        cout<<setfill('=')<<setw(75)<<"="<<endl;
        cout<<"   ID LAPTOP     NAMA LAPTOP      HARGA           GARANSI        STOK"<<endl;
        cout<<setfill('=')<<setw(75)<<"="<<endl;
        for(int j=0;j<banyakdata;j++){
        cout<<"   "<<laptop[j].id_laptop<<"               ";
        cout<<laptop[j].nama_laptop<<setfill(' ')<<setw(20-strlen(laptop[j].nama_laptop));
        cout<<laptop[j].harga<<"            ";
        cout<<laptop[j].garansi<<"            ";
        cout<<laptop[j].stok<<"       "<<endl;
        }
        cout<<setfill('=')<<setw(75)<<"="<<endl;
    }
    fclose(arsipLaptop);
    system("pause");
    main();
}

void transaksi(){
    char file1[50],file2[50],file3[50];
    dataLaptop laptop;
    int pilih,i=0;
    int jmlData=0,batas,z=1;

    system("cls");
    cout<<setfill('=')<<setw(25)<<"="<<endl;
    cout<<"|    TRANSAKSI DATA     |"<<endl;
    cout<<setfill('=')<<setw(25)<<"="<<endl;
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
       
        }

        while(fread(&laptop,sizeof(laptop),1,f1)){
            fwrite(&laptop,sizeof(laptop),1,f3);
        } while(fread(&laptop,sizeof(laptop),1,f2)){
            fwrite(&laptop,sizeof(laptop),1,f3);
        }

        cout<<"file berhasil disambungkan ! \n\n";
        system("pause");
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
            if(z<batas-2) {
                fwrite(&laptop,sizeof(laptop),1,f2);
                z++;
            }
            else if (batas <= jmlData+2){ 
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
    dataLaptop laptop[MAX];
    int i=0;
    arsipLaptop=fopen(namaFile,"r");
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    cout<<"   ID LAPTOP     NAMA LAPTOP      HARGA           GARANSI        STOK"<<endl;
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    while(fread(&laptop[i],sizeof(laptop[i]),1,arsipLaptop)==1){
        cout<<"   "<<laptop[i].id_laptop<<"               ";
        cout<<laptop[i].nama_laptop<<setfill(' ')<<setw(20-strlen(laptop[i].nama_laptop));
        cout<<laptop[i].harga<<"            ";
        cout<<laptop[i].garansi<<"            ";
        cout<<laptop[i].stok<<"       "<<endl;
    }
    cout<<setfill('=')<<setw(75)<<"="<<endl;
    fclose(arsipLaptop);
}

void bubblesort(dataLaptop laptop[], int banyakData){
    dataLaptop temp;
    int i, j;
        for (i=0; i<banyakData-1; i++)
            for (j=0; j<banyakData-1-i; j++)
                if (laptop[j].id_laptop > laptop[j+1].id_laptop)
                {
                temp = laptop[j];
                laptop[j]= laptop[j+1];
                laptop[j+1]= temp;
        }
}

void quicksort(dataLaptop laptop[], int first,int last){
    dataLaptop temp;
    int low, high, list_separator;
    low = first;
    high = last;
    list_separator= laptop[(first+last)/2].id_laptop;
    do {
        while (laptop[low].id_laptop<list_separator) low++;
        while (laptop[high].id_laptop>list_separator) high--;
        if (low<=high)
        {
            temp= laptop[low];
            laptop[low++]= laptop[high];
            laptop[high--]= temp;
        }
    } while (low<=high);
    if (first<high) quicksort(laptop, first, high);
    if (low<last) quicksort(laptop, low, last);
}

void shellsort(dataLaptop laptop[], int banyakData){
    for (int gap = banyakData/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < banyakData; i += 1)
        {
            int temp = laptop[i].id_laptop;
            dataLaptop lepi=laptop[i];

            int j;
            for (j = i; j >= gap && laptop[j - gap].id_laptop > temp; j -= gap)
                laptop[j] = laptop[j - gap];

            laptop[j]=lepi;
            laptop[j].id_laptop = temp;
        }
    }
}

void insertsort(dataLaptop laptop[], int banyakData){
    int i, key, j;
    dataLaptop temp;
    for (i = 1; i < banyakData; i++)
    {   
        temp=laptop[i];
        key = laptop[i].id_laptop;
        j = i - 1;
 
        while (j >= 0 && laptop[j].id_laptop > key)
        {
            laptop[j + 1] = laptop[j];
            j = j - 1;
        }
        laptop[j+1]=temp;
        laptop[j + 1].id_laptop = key;
    }
}

void selectionsort(dataLaptop laptop[], int byk){
    dataLaptop temp;
     for(int i=0;i<byk-1;i++){
        int min = i;
        for(int j=i+1;j<byk;j++){
            if(laptop[j].id_laptop<laptop[min].id_laptop){
                min=j;
            }
        }
        if(min!=i){
            temp=laptop[min];
            laptop[min]=laptop[i];
            laptop[i]=temp;
        }
    }
}