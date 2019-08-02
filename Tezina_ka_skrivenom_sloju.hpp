#ifndef TEZINA_KA_SKRIVENOM_SLOJU_HPP_INCLUDED
#define TEZINA_KA_SKRIVENOM_SLOJU_HPP_INCLUDED

#include <iostream>
#include "Tezina.hpp"
#include "Akceptor.hpp"
#include "SkrivenaCelija.hpp"

#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <stdlib.h>

class Tezina_ka_skrivenom_sloju : public Tezina{
    private:
    Akceptor *akceptorski_ulaz;
    SkrivenaCelija *skrivena_celija; //za veze izmedju skrivenog sloja i akceptora/efektora
    string kljuc;
    string log_faktora_aktivnosti;
    ofstream filestr;
    char filename[5];
    int broj_zapisa;
    //static int broj_promena_faktora_aktivnosti;
    public:
    Tezina_ka_skrivenom_sloju(){};
    Tezina_ka_skrivenom_sloju(Akceptor *akceptorski_ulaz,SkrivenaCelija *skrivena_celija,double vrednost){
        this->akceptorski_ulaz = akceptorski_ulaz;
        this->skrivena_celija = skrivena_celija;
        this->pocetak = akceptorski_ulaz->getBrojAkceptora();
        this->kraj = skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->vrednost = vrednost;
        this->faktor_aktivnosti = 0.0;
        this->log_faktora_aktivnosti = "";
        this->broj_zapisa = 0;
        //this->broj_promena_faktora_aktivnosti = 0;

        string str1 = "01";
        int i = akceptorski_ulaz->getBrojAkceptora();
        int k = skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        string s;
        stringstream out;
        out << i;
        out.clear();
        out << k;
        s = out.str();
        str1.append(s);
        this->kljuc = str1;


        filename[0] = kljuc.at(0);
        filename[1] = kljuc.at(1);
        filename[2] = kljuc.at(2);
        filename[3] = kljuc.at(3);
        filename[4] = '\0';

        }
    Tezina_ka_skrivenom_sloju(Tezina_ka_skrivenom_sloju &tezina){
        this->akceptorski_ulaz = tezina.akceptorski_ulaz;
        this->skrivena_celija = tezina.skrivena_celija;
        this->pocetak = tezina.akceptorski_ulaz->getBrojAkceptora();
        this->kraj = tezina.skrivena_celija->getBroj_celije_u_skrivenom_sloju();
        this->vrednost = tezina.vrednost;
        this->kljuc = tezina.kljuc;
        }

    Akceptor& getAkceptorski_ulaz(){
        return *this->akceptorski_ulaz;
        }
    SkrivenaCelija& getSkrivenaCelija(){
        return *this->skrivena_celija;
        }

    string Tezina_ka_SK_ToString(){
        string log = "";
        stringstream out;

        out << "\nStanje Tezine ka skrivenom sloju: ";
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

    void setAkceptorski_ulaz(Akceptor& akceptor){
        this->akceptorski_ulaz = &akceptor;
        }
    void setSkrivenaCelija(SkrivenaCelija& skrivena_celija){
        this->skrivena_celija = &skrivena_celija;
        }
    string getKljuc(){return this->kljuc;}

    void setFaktorAktivnostiSinapse(double faktor_aktivnosti,int broj_celija_u_sloju_pobudjivaca, double vrednost_tezine, double razlika_izlaza_akceptorskog_pobudjivaca, double informativna_energija_pobudjene_celije, double prethodnik){

        this->prethodni_faktor_aktivnosti = this->faktor_aktivnosti;
        this->faktor_aktivnosti = faktor_aktivnosti;

        string s;
        stringstream out;
        out << broj_zapisa;
        out << " ";
        out << this->prethodni_faktor_aktivnosti;
        out << " ";
        out << this->faktor_aktivnosti;
        out << "\n";

        s = out.str();
        //apdejtujLogFaktoraAktivnosti(s);
        //broj_zapisa++;
        };
    void apdejtujLogFaktoraAktivnosti(string log_faktora_aktivnosti){

        this->log_faktora_aktivnosti.append(log_faktora_aktivnosti);

        }

    void zapisiLogFaktoraAktivnosti(){
        filestr.open(filename);
        if (filestr.is_open()){
            filestr << log_faktora_aktivnosti;
            }
        filestr.close();
        }

    void prikaziStanje(){

        //zapisiLogFaktoraAktivnosti();

        cout<<"\nPrikaz stanja tezine w["<<pocetak<<"]["<<kraj<<"]:"<<endl; //OVO JE I KLJUC TEZINA
        cout<<"\tAkceptorski ulaz:";
        akceptorski_ulaz->prikaziStanje();
        cout<<endl;

        cout<<"\tSkrivena celija:";
        if(skrivena_celija!=NULL)
        skrivena_celija->prikaziStanje();
        cout<<endl;

        cout<<"\tVrednost tezine je: "<<vrednost<<endl;

        cout<<"\tFaktor aktivnosti: "<<getFaktorAktivnosti()<<endl;

//        cout<<"\tPrethodni faktor aktivnosti: "<<getPrethodniFaktorAktivnosti()<<endl;
//        cout<<"\tNormalizovani faktor aktivnosti: "<<normalizovani_faktor_aktivnosti<<endl;
//        cout<<"\tVerovatnoca degeneracije tezine je: "<<verovatnoca_degeneracije_sinapse<<endl;

        cout<<"\tKljuc tezine je: "<<kljuc<<endl;
        }

};


#endif // TEZINA_KA_SKRIVENOM_SLOJU_HPP_INCLUDED
