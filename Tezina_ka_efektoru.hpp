#ifndef TEZINA_KA_EFEKTORU_HPP_INCLUDED
#define TEZINA_KA_EFEKTORU_HPP_INCLUDED

#include <iostream>
#include "Tezina.hpp"
#include "SkrivenaCelija.hpp"
#include "Efektor.hpp"

class Tezina_ka_efektoru : public Tezina{
    private:
    Efektor *efektorski_izlaz;
    SkrivenaCelija *skrivena_celija; //za veze izmedju skrivenog sloja i efektora
    string kljuc;
    public:
    Tezina_ka_efektoru(){};
    Tezina_ka_efektoru(SkrivenaCelija *skrivena_celija,Efektor *efektorski_izlaz,double vrednost){
        this->skrivena_celija = skrivena_celija;
        this->efektorski_izlaz = efektorski_izlaz;
        this->pocetak = skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->kraj = efektorski_izlaz->getBrojEfektora();
        this->vrednost = vrednost;
        this->prethodni_faktor_aktivnosti = 0.0;

        int i = skrivena_celija->getBroj_skrivenog_sloja();
        i++; // zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
        int k = skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        int x = i+1; //x predstavlja poslednji, efektorski sloj
        int y = efektorski_izlaz->getBrojEfektora();
        string s;
        stringstream out;
        out << i;
        out << x;
        out << k;
        out << y;
        s = out.str();
        this->kljuc = s;

        }
    Tezina_ka_efektoru(Tezina_ka_efektoru &tezina){
        this->efektorski_izlaz = tezina.efektorski_izlaz;
        this->skrivena_celija = tezina.skrivena_celija;
        this->pocetak = tezina.skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->kraj = tezina.efektorski_izlaz->getBrojEfektora();
        this->vrednost = tezina.vrednost;
        this->kljuc = tezina.kljuc;
        }

    Efektor& getEfektorski_izlaz(){
        return *this->efektorski_izlaz;
        }
    SkrivenaCelija& getSkrivenaCelija(){
        return *this->skrivena_celija;
        }

    void setEfektorski_izlaz(Efektor& efektor){
        this->efektorski_izlaz = &efektor;
        }
    void setSkriveniUlaz(SkrivenaCelija& skrivena_celija){
        this->skrivena_celija = &skrivena_celija;
        }
    string getKljuc(){return this->kljuc;}


    string Tezina_ka_Efektoru_ToString(){
        string log = "";
        stringstream out;

        out << "\nStanje Tezine ka efektoru: ";
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

    void prikaziStanje(){

        cout<<"\nPrikaz stanja tezine w["<<pocetak<<"]["<<kraj<<"]:\n";
        cout<<"\tSkrivena celija:";
        if(skrivena_celija!=NULL)
        skrivena_celija->prikaziStanje();
        cout<<endl;
/*
        cout<<"\tEfektorski izlaz:";
        efektorski_izlaz->prikaziStanje();
        cout<<endl;

        cout<<"\tVrednost tezine je: "<<vrednost<<endl;
        cout<<"\tFaktor aktivnosti: "<<faktor_aktivnosti<<endl;
        cout<<"\tPrethodni faktor aktivnosti: "<<prethodni_faktor_aktivnosti<<endl;
        cout<<"\tNormalizovani faktor aktivnosti: "<<normalizovani_faktor_aktivnosti<<endl;
        cout<<"\tVerovatnoca degeneracije tezine je: "<<verovatnoca_degeneracije_sinapse<<endl;
*/
        cout<<"\tKljuc tezine je: "<<kljuc<<endl;
        }
};

#endif // TEZINA_KA_EFEKTORU_HPP_INCLUDED
