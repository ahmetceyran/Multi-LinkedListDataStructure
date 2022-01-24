#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <list>
#include <sstream>

using namespace std;

void listekur(char *,char *,char *,char *,char *);
void ara();
void numarara();
void soyadara();
void olustur();
void listele();
void dersSil();
void ogrenciSil();
void kesisimBul();
void dosyaoku();
void dosyaYaz();

int main();

struct dersler{
    char dersadi[15];
    char derskodu[10];
    dersler *sonraki;
};

struct ogr_dugum{
    char ogradi[20];
    char ogrsoyad[20];
    char ogrno[10];
    dersler *derskodu;
    ogr_dugum *sonraki;
}*bas;



void olustur()
{
    bas = NULL;
    dosyaoku();
}


void listekur(char *ad,char *soyad,char *numara,char *kod,char *ders){

    ogr_dugum *tara, *arka;
    tara = bas;
    if(bas == NULL){
        ogr_dugum *yenikisi;
        dersler *yeniders;
        yenikisi = new ogr_dugum;
        strcpy(yenikisi->ogradi,ad);
        strcpy(yenikisi->ogrsoyad,soyad);
        strcpy(yenikisi->ogrno,numara);
        yeniders = new dersler;
        yenikisi->derskodu = yeniders;
        strcpy(yeniders->derskodu,kod);
        strcpy(yeniders->dersadi,ders);
        yeniders->sonraki = NULL;
        yenikisi->sonraki = NULL;
        return ;
    }
    if(strcmp(numara,bas->ogrno)<0){
        ogr_dugum *yenikisi;
        dersler *yeniders;
        yenikisi = new ogr_dugum;
        strcpy(yenikisi->ogradi,ad);
        strcpy(yenikisi->ogrsoyad,soyad);
        strcpy(yenikisi->ogrno,numara);
        yeniders = new dersler;
        yenikisi->derskodu = yeniders;
        strcpy(yeniders->derskodu,kod);
        strcpy(yeniders->dersadi,ders);
        yeniders->sonraki = NULL;
        yenikisi->sonraki = NULL;
        yenikisi->sonraki = bas;
        bas = yenikisi;
        return;
    }
    while(tara && (strcmp(numara,tara->ogrno)>0)){
        arka = tara;
        tara = tara->sonraki;
    }
    if(tara && (strcmp(numara,tara->ogrno)==0)){
            dersler *yeniders;
        yeniders = new dersler;
        yeniders->sonraki = tara->derskodu;
        tara->derskodu = yeniders;
        strcmp(yeniders->derskodu,kod);
        strcmp(yeniders->dersadi,ders);
        return;
    }
    else{
        ogr_dugum *yenikisi;
        dersler *yeniders;
        yenikisi = new ogr_dugum;
        strcpy(yenikisi->ogradi,ad);
        strcpy(yenikisi->ogrsoyad,soyad);
        strcpy(yenikisi->ogrno,numara);
        yeniders = new dersler;
        yenikisi->derskodu = yeniders;
        strcpy(yeniders->derskodu,kod);
        strcpy(yeniders->dersadi,ders);
        yeniders->sonraki = NULL;
        yenikisi->sonraki = NULL;
        if(tara){
            yenikisi->sonraki = tara;
            arka->sonraki = yenikisi;
        }
        else{
            arka->sonraki = yenikisi;
        }
        return;
    }

}

void dersSil()
{
    ogr_dugum *tara, *arka;
    dersler *pd;
    int sayac=1001001;
    int numara;
    string ders;
    tara = bas;

    cout<<"Dersi silinecek ogrencinin numarasini giriniz:";
    cin>>numara;
    cout<<"\nSilinecek dersin kodunu giriniz:";
    cin>>ders;

    if(numara <= 1001000){
        cout<<"Hatali Ogrenci numarasi!!\n";
        return;
    }
    if(numara == 1001001)
    {
        pd=tara->derskodu;
        while(pd)
        {
            tara->derskodu = pd->sonraki;
            if(ders == pd->derskodu)
            {
                delete pd;
            }
            pd=tara->derskodu;
        }
        return;
    }

    while((tara != NULL) && (sayac < numara))
    {
        arka = tara;
        tara = tara->sonraki;
        sayac++;
    }
    if(sayac < numara){
        cout<<"Dersi silinecek öðrenci bulunamadi!!\n";
        return;
    }
    else{
        arka->sonraki=tara->sonraki;
        pd=tara->derskodu;
        while(pd)
        {
            tara->derskodu = pd->sonraki;
            if(ders == pd->derskodu)
            {
                delete pd;
            }
            pd = tara->derskodu;
        }
        return;
    }
}

void ogrenciSil()
{
    ogr_dugum *tara,*arka;
    dersler *pd;
    int sayac = 1001001;
    int numara;
    tara = bas;

    cout<<"Silinecek ogrencinin numarasini giriniz:";
    cin>>numara;

    if(numara <= 1001000){
        cout<<"Hatali Ogrenci numarasi!!\n";
        return;
    }
    if(numara == 1001001)
    {
        pd=tara->derskodu;
        while(pd)
        {
            tara->derskodu = pd->sonraki;
            delete pd;
            pd=tara->derskodu;
        }
        delete tara;
        return;
    }

    while((tara != NULL) && (sayac < numara))
    {
        arka = tara;
        tara = tara->sonraki;
        sayac++;
    }
    if(sayac < numara){
        cout<<"Silinecek öðrenci bulunamadi!!\n";
        return;
    }
    else{
        arka->sonraki=tara->sonraki;
        pd=tara->derskodu;
        while(pd)
        {
            tara->derskodu = pd->sonraki;
            delete pd;
            pd = tara->derskodu;
        }
        delete tara;
        return;
    }
}

void listele()
{
    ogr_dugum *p;
    while(bas)
    {
        p = bas;
        bas = bas->sonraki;
        cout<<p;
    }
}

void ara()
{
    char secim;

    cout<<"Aramayi numaraya gore yapmak icin N, Soyada gore yapmak icin S harfini giriniz.\n";
    cin>>secim;

    if(secim == 'N')
        numarara();
    if(secim == 'S')
        soyadara();
    else
        cout<<"Yanlis giris yaptiniz!!";

    return;

}

void numarara()
{
    ogr_dugum *tara;
    dersler *pd;
    char *numara;
    int sayac = 0;
    int bulunan = 0;
    tara = bas;

    cout<<"Aranacak numarayi giriniz: ";
    cin>>numara;

    while(tara)
    {
        sayac++;
        if(strncmp(numara,tara->ogrno,strlen(numara))==0)
        {
            bulunan++;
            cout<<sayac<<".kayit"<<tara->ogradi<<tara->ogrsoyad<<tara->ogrno<<"\n";
            cout<<"Aldigi dersler:\n";
            pd = tara->derskodu;
            while(pd)
            {
                cout<<pd->derskodu<<"\t";
                cout<<pd->dersadi;
                pd = pd->sonraki;
            }
        }
        tara = tara->sonraki;
    }
    return ;

}

void soyadara()
{
    ogr_dugum *tara;
    dersler *pd;
    char *soyad;
    int sayac = 0;
    int bulunan = 0;
    tara = bas;

    cout<<"Aranacak soyad'ı giriniz: ";
    cin>>soyad;

    while(tara)
    {
        sayac++;
        if(strncmp(soyad,tara->ogrsoyad,strlen(soyad))==0)
        {
            bulunan++;
            cout<<sayac<<".kayit"<<tara->ogradi<<tara->ogrsoyad<<tara->ogrno<<"\n";
            cout<<"Aldigi dersler:\n";
            pd = tara->derskodu;
            while(pd)
            {
                cout<<pd->derskodu<<"\t";
                cout<<pd->dersadi;
                pd = pd->sonraki;
            }
        }
        tara = tara->sonraki;
    }
    return ;
}

void kesisimBul()
{
    ogr_dugum *tara;
    dersler *pd,*pd2;
    string ders1,ders2;
    tara = bas;

    cout<<"Kesisimi bulunacak derslerin kodlarini giriniz:";
    cin>>ders1;
    cout<<"\t";
    cin>>ders2;

    while(bas)
    {
        pd = tara->derskodu;
        tara->derskodu = pd->sonraki;
        pd2 = tara->derskodu;
        tara->derskodu = pd2->sonraki;
        if(((ders1 == pd->derskodu) && (ders2 == pd2->derskodu)) || ((ders2 == pd->derskodu) && (ders1 == pd2->derskodu)))
            cout<<bas;
        bas=bas->sonraki;
        tara=bas;
    }
}

void dosyaoku()
{
    fstream oku;
    string line, kelime;
    int i=0;
    char dosyalar[3][50]={"mat101.txt","fiz101.txt","eng101.txt"};
    char derskod[20],dersadi[20],ad[20],soyad[20],numara[20];

    for(i=0;i<3;i++)
    {
        oku.open(dosyalar[i]);

        getline(oku,line);
        stringstream s(line);
        s>>derskod;
        s>>dersadi;

        while(getline(oku, line))
        {
            stringstream s(line);
            s>>numara;
            s>>ad;
            s>>soyad;
            listekur(ad,soyad,numara,derskod,dersadi);
        }
        oku.close();
    }

    return;

}

void dosyaYaz()
{
    ofstream dosyam("ogreciler.txt");
    int ogrsayi;
    struct ogr_dugum *it = bas;
    struct dersler* temp;
    string line;

    while(it != nullptr)
    {
        line = "";
        temp = it->derskodu;
        ogrsayi = 0;
        while (temp != nullptr)
        {
            if(ogrsayi == 0)
            {
                line.append(it->ogrno);
                line.append(" ");
                line.append(it->ogradi);
                line.append(" ");
                line.append(it->ogrsoyad);
                line.append(" ");
                ogrsayi++;
            }
            line.append(temp->dersadi);
            line.append(" ");
            line.append(temp->derskodu);
            line.append(" ");
            temp = temp->sonraki;
        }
        dosyam.close();
    }
}

int main()
{
    olustur();
    char secim;

    cout<<"-----------Islem Menusu----------\n"<<"Arama yapmak icin: A\n"<<"Ders silmek icin: D\n"<<"Ogrenci silmek icin: O\n";
    cout<<"Kesisim bulmak icin: K\n"<<"Listeyi ekrana yazdirmak icin: L\n"<<"Dosyaya yazdirmak icin: Y\n"<<"Cikis icin: C\n";
    cin>>secim;

    if(secim == 'A')
        ara();
    if(secim == 'D')
        dersSil();
    if(secim == 'O')
        ogrenciSil();
    if(secim == 'K')
        kesisimBul();
    if(secim == 'L')
        listele();
    if(secim == 'Y')
        dosyaYaz();
    else
        return 0;
}
