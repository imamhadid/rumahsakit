#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<dos.h>
#include<cstring>
using namespace std;

string rumahsakit;

struct pasien {

	string namadepan;
	string namabelakang;
	int usia;
	char darah[5];
	char jeniskelamin;
    long long ID;
    pasien*next;
};

class antrian {
	pasien *awal,*belakang;
	public:
	antrian() {
		awal=NULL;
		belakang=NULL;
	}
    pasien input();
    void umum();
    void darurat();
    void panggilan();
    void listpasien();
    int urutan(int);
    char dokter[50];
};

int antrian :: urutan(int item) {

    
	 if(awal==NULL)
     return false;
     else {
     int tanda=0;
     pasien*p=new pasien();
     p=awal;

     while( p->next!=NULL && p->ID!=item ) {
        p=p->next;
     }
     if(p->ID==item) {
	 	tanda=1;
	 	return true;
     }
     if(tanda==0)
     return false;
     }
}

int pilihan() {

   char b[20];
   cin.getline(b, sizeof(b));
   return atoi(b);
}

pasien antrian :: input() {
    int tanda=0;
   pasien *p=new pasien();
   cout << "\n   Masukan Data Pasien\n";
   cout<<"\n   Nama Depan         : ";
   getline(cin,p->namadepan);
   cout << "   Nama Belakang      : ";
   getline(cin,p->namabelakang);
   again :
   cout << "   Golongan Darah     : ";
   cin>>p->darah;
   if((strcmp(p->darah,"A+")==0)||(strcmp(p->darah,"a+")==0)||(strcmp(p->darah,"A-")==0)||(strcmp(p->darah,"a-")==0)||
      (strcmp(p->darah,"B+")==0)||(strcmp(p->darah,"b+")==0)||(strcmp(p->darah,"B-")==0)||(strcmp(p->darah,"b-")==0)||
      (strcmp(p->darah,"O+")==0)||(strcmp(p->darah,"o+")==0)||(strcmp(p->darah,"O-")==0)||(strcmp(p->darah,"o-")==0)||
      (strcmp(p->darah,"AB+")==0)||(strcmp(p->darah,"ab+")==0)||(strcmp(p->darah,"AB-")==0)||(strcmp(p->darah,"ab-")==0))
             tanda=1;
    if(tanda==0) {
        cout<<"\n   Golongan darah tidak diketahui..\n\n";
        goto again;

    }
   cout<<"   Jenis Kelamin(P/W) : ";
   cin>>p->jeniskelamin;
   cout<<"   Usia               : ";
   cin>>p->usia;
   cout<<"   Nomor Handphone    : ";
   cin>>p->ID;


	if(urutan(p->ID)) {
		p->ID=0;
		cout << "\n   Masukan nomor dengan benar.";
	}
	return *p;
}

void output(pasien *p) {
	cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n   Data Pasien:\n";
	cout<<"\n   Nama Depan          : "<<p->namadepan;
	cout<<"\n   Nama Belakang       : "<<p->namabelakang;
	cout<<"\n   Jenis Kelamin       : "<<p->jeniskelamin;
	cout<<"\n   Usia                : "<<p->usia;
	cout<<"\n   Golongan Darah      : "<<p->darah;
	cout<<"\n   Nomor Handphone     : "<<p->ID;
	cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
}
void antrian :: darurat() {
     pasien*p=new pasien();
     *p=input();
     if(p->ID==0)
     return;

     if(awal==NULL) {
         awal=p;
         belakang=p;
         p->next=NULL;
     }
     else {
        p->next=awal;
        awal=p;
     }
     system("cls");
     cout << "\n\tpasien added:";
     output(p);
}
void antrian:: umum() {
     pasien*p=new pasien();
     *p=input();
     if(p->ID==0)
     return;

     if(awal==NULL) {
     	awal=p;
        belakang=p;
        p->next=NULL;
     }
     else {
     	p->next=NULL;
        belakang->next=p;
        belakang=p;
     }
     system("cls");

     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  Rumah Sakit " <<rumahsakit;
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
     cout <<"\n  -------Pasien Telah Ditambahkan------";
     output(p);
}
void antrian :: panggilan() {

	 system("cls");
     if(awal==NULL) {
     	cout<<"\n  Tidak ada pasien";
     }
     else {
     	pasien*p=new pasien();
     	p=awal;
     	awal=awal->next;
 	    cout << "\n  Ada pasien:";
        output(p);
 	 }
}

void antrian :: listpasien() {
     if(awal==NULL) {
     	cout<<"\n  Tidak ada pasien";
 	 }
 	      system("cls");
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
     cout<<"\n  Rumah Sakit " <<rumahsakit;
     cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
     pasien*p=new pasien;
     p=awal;
     while(p!=NULL) {
        cout<<"\n   pasien data:\n";
		cout<<"\n   Nama Depan       : "<<p->namadepan;
		cout<<"\n   Nama Belakang    : "<<p->namabelakang;
		cout<<"\n   Jenis Kelamin    : "<<p->jeniskelamin;
        cout<<"\n   Usia             : "<<p->usia;
        cout<<"\n   Golongan darah   : "<<p->darah;
		cout<<"\n   Nomor Handphone  : "<<p->ID;
		cout<<"\n\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n";
        p=p->next;
     }
     cout<<"\n";
}


void menu (antrian * q) {
    int choice = 0, success;
    pasien p;
    while (choice != 5) {
    system("cls");
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
    cout<<"\n  Rumah Sakit " <<rumahsakit;
    cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<"\n\n   "<<q->dokter;
	cout<<"\n   [1] Pasien Umum\n";
	cout<<"   [2] Pasien Gawat Darurat\n";
	cout<<"   [3] Panggil Giliran\n";
	cout<<"   [4] Tampilkan Data Terakhir\n";
	cout<<"   [5] Ganti Dokter\n";
	cout<<"\n   Masukan Pilihan Anda : ";
	choice=pilihan();
	cout<<"  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";

    switch (choice) {
	  case 1:	q->umum();
				cout << "\n   Press any key";
	    		getch();
	 			break;

      case 2:	q->darurat();
	    		cout << "\n   Press any key";
	    		getch();
				break;

      case 3:	q->panggilan();
	 			cout<<"\n   Press any key";
     			getch();
	      		break;

      case 4:	system("cls");
	 			q->listpasien();
	 			cout<<"\n   Press any key";
	 			getch();
				break;
	 }
    }
}

int main () {
    SetConsoleTitleA("Cepat Tanggap - Program Rumah Sakit");
    system("color 0a");
      cout<<"\n\n\n\t\t\t\tLoading Screen Program UAS\n";
      cout<<"\t\t\t\tCreated by. Imam Hadid Gunawan\n";
      cout<<"\t\t\t\t--------2011019 IFB1J---------\n\n";
      char a=177, b=219;
      cout<<"\t\t\t\t";
      for (int i=0;i<=30;i++)
      cout<<a
         <<"\r"
         <<"\t\t\t\t";
      for (int i=0;i<=30;i++) {
      cout<<b;
      for (int j=0;j<=1e8;j++); 
      }
        cout<<"\n\n\n\t\t\t\t\n\n";
        system ("pause");
        system("clear"); 

    cout<<"Masukan Nama Rumah Sakit\n";
    cout<<"Tanpa Spasi! \n";
    cin>>rumahsakit;
    system("clear");

    int i, choice = 0;
	antrian bagian[4];

	while(choice!=5) {
		strcpy(bagian[0].dokter,"Dokter Umum\n");
		strcpy(bagian[1].dokter,"Dokter Spesialis\n");
		strcpy(bagian[2].dokter,"Dokter Anak, dan Gizi\n");
		strcpy(bagian[3].dokter,"Dokter Psikiater\n");
		system("cls");
		cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
		cout<<"\n  Rumah Sakit " <<rumahsakit;
		cout<<"\n  \xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n";
		cout<<"   Main Menu\n\n";
		for (i = 0; i < 4; i++) {
			cout<<"   "<<(i+1)<<": "<<bagian[i].dokter;
		}
		cout<<"   5: Exit";
		cout<<"\n\n   Masukan Pilihan Anda : ";
		choice=pilihan();
		if(choice>=1 && choice<=4) {
			menu(&bagian[choice-1]);
		}

	}
	if(choice==5)
	cout<<"\n\t\tThank you! \n";
	exit(0);
}