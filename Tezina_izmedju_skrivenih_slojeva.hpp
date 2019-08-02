#ifndef TEZINA_IZMEDJU_SKRIVENIH_SLOJEVA_H_INCLUDED
#define TEZINA_IZMEDJU_SKRIVENIH_SLOJEVA_H_INCLUDED

#include <iostream>
#include "Tezina.hpp"
#include "SkrivenaCelija.hpp"

class Tezina_izmedju_skrivenih_slojeva : public Tezina{
    private:
    SkrivenaCelija *prva_skrivena_celija;
    SkrivenaCelija *druga_skrivena_celija;
    string kljuc;
    public:
    Tezina_izmedju_skrivenih_slojeva(){};
    Tezina_izmedju_skrivenih_slojeva(SkrivenaCelija *prva_skrivena_celija,SkrivenaCelija *druga_skrivena_celija,double vrednost){
        this->prva_skrivena_celija = prva_skrivena_celija;
        this->druga_skrivena_celija = druga_skrivena_celija;
        this->pocetak = prva_skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->kraj = druga_skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->vrednost = vrednost;
        this->prethodni_faktor_aktivnosti = 0.0;

        int i = prva_skrivena_celija->getBroj_skrivenog_sloja();
        i++; // zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
        int k = prva_skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        int x = druga_skrivena_celija->getBroj_skrivenog_sloja();
        x++; // zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
        int y = druga_skrivena_celija->getBroj_celije_u_skrivenom_sloju();

        string s;
        stringstream out;
        out << i;
        out << x;
        out << k;
        out << y;
        s = out.str();
        this->kljuc = s;

        }
    Tezina_izmedju_skrivenih_slojeva(Tezina_izmedju_skrivenih_slojeva &tezina){
        this->prva_skrivena_celija = tezina.prva_skrivena_celija;
        this->druga_skrivena_celija = tezina.druga_skrivena_celija;
        this->pocetak = tezina.prva_skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->kraj = tezina.druga_skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->vrednost = tezina.vrednost;
        this->kljuc = tezina.kljuc;
        }

    SkrivenaCelija& getPrvaSkrivenaCelija(){
        return *this->prva_skrivena_celija;
        }
    SkrivenaCelija& getDrugaSkrivenaCelija(){
        return *this->druga_skrivena_celija;
        }

    string Tezina_izmedju_SK_ToString(){
        string log = "";
        stringstream out;

        out << "\nStanje Tezine izmedju skrivenih slojeva: ";
        out << this->getKljuc();
        out << "\n\tVrednost: ";
        out << this->getVrednost();
        out << "\n\tFaktor aktivnosti: ";
        out << this->getFaktorAktivnosti();
        out << "\t Prethodni faktor aktivnosti: ";
        out << this->prethodni_faktor_aktivnosti;
        out << "\n\tNormalizovani faktor aktivnosti: ";
        out <<this->getNormalizovaniFaktorAktivnosti();

        out << "\n\n";
        log = out.str();
        return log;
        }

    void setPrvaSkrivenaCelija(SkrivenaCelija& skrivena_celija){
        this->prva_skrivena_celija = &skrivena_celija;
        }
    void setDrugaSkrivenaCelija(SkrivenaCelija& skrivena_celija){
        this->druga_skrivena_celija = &skrivena_celija;
        }
    string getKljuc(){return this->kljuc;}

    void prikaziStanje(){
        cout<<"\nPrikaz stanja tezine w["<<pocetak<<"]["<<kraj<<"]:\n";

        cout<<"\tSkrivena celija koja pobudjuje drugu skrivenu celiju:";
        if(prva_skrivena_celija!=NULL)
        prva_skrivena_celija->prikaziStanje();
        cout<<endl;

        cout<<"\tSkrivena celija koja biva pobudjujena:";
        if(druga_skrivena_celija!=NULL)
        druga_skrivena_celija->prikaziStanje();
        cout<<endl;

        cout<<"\tVrednost tezine je: "<<vrednost<<endl;
        cout<<"\tFaktor aktivnosti: "<<faktor_aktivnosti<<endl;
        cout<<"\tPrethodni faktor aktivnosti: "<<prethodni_faktor_aktivnosti<<endl;
        cout<<"\tNormalizovani faktor aktivnosti: "<<normalizovani_faktor_aktivnosti<<endl;
        cout<<"\tVerovatnoca degeneracije tezine je: "<<verovatnoca_degeneracije_sinapse<<endl;

        cout<<"\tKljuc tezine je: "<<kljuc<<endl;
        }
};

#endif // TEZINA_IZMEDJU_SKRIVENIH_SLOJEVA_H_INCLUDED
