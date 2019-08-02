#ifndef TEZINA_AKCEPTORA_KA_EFEKTORU_H_INCLUDED
#define TEZINA_AKCEPTORA_KA_EFEKTORU_H_INCLUDED

#include <iostream>
#include "Tezina.hpp"
#include "Akceptor.hpp"
#include "Efektor.hpp"

class Tezina_akceptora_ka_efektoru : public Tezina{
    private:
    Efektor *efektorski_izlaz;
    Akceptor *akceptor; //za veze izmedju skrivenog sloja i efektora
    string kljuc;
    public:
    Tezina_akceptora_ka_efektoru(){};
    Tezina_akceptora_ka_efektoru(Akceptor *akceptor,Efektor *efektorski_izlaz,double vrednost){
        this->akceptor = akceptor;
        this->efektorski_izlaz = efektorski_izlaz;
        this->pocetak = akceptor->getBrojAkceptora();
        this->kraj = efektorski_izlaz->getBrojEfektora();
        this->vrednost = vrednost;
        this->prethodni_faktor_aktivnosti = 0.0;

        int i = 0; // broj akceptorskog sloja ucek je 0
        int k = akceptor->getBrojAkceptora();
        int x = efektorski_izlaz->getBrojSloja(); //x predstavlja poslednji, efektorski sloj
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
    Tezina_akceptora_ka_efektoru(Tezina_akceptora_ka_efektoru &tezina){
        this->efektorski_izlaz = tezina.efektorski_izlaz;
        this->akceptor = tezina.akceptor;
        this->pocetak = tezina.akceptor->getBrojAkceptora();
        this->kraj = tezina.efektorski_izlaz->getBrojEfektora();
        this->vrednost = tezina.vrednost;
        this->kljuc = tezina.kljuc;
        }

    Efektor& getEfektorski_izlaz(){
        return *this->efektorski_izlaz;
        }
    Akceptor& getAkceptor(){
        return *this->akceptor;
        }

    void setEfektorski_izlaz(Efektor& efektor){
        this->efektorski_izlaz = &efektor;
        }
    void setAkceptor(Akceptor& akceptor){
        this->akceptor = &akceptor;
        }
    string getKljuc(){return this->kljuc;}

    string Tezina_Akceptora_ka_Efektoru_ToString(){
        string log = "";
        stringstream out;

        out << "\nStanje Tezine akceptora ka efektoru: ";
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
        akceptor->prikaziStanje();
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

#endif // TEZINA_AKCEPTORA_KA_EFEKTORU_H_INCLUDED
