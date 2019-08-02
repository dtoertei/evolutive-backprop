#ifndef SKRIVENACELIJA_H_INCLUDED
#define SKRIVENACELIJA_H_INCLUDED

#include <iostream>
#include <map>
#include <fstream>
#include "Kljuc_skrivenih_celija.hpp"
#include "Tezina.hpp"

typedef map<string,string> Mapa_pobudjujucih_tezina;
typedef map<string,string> Mapa_pobudjivackih_tezina;

class SkrivenaCelija{
    private:
    double ulazna_tezina;
    double izlazna_tezina;
    double prag_aktivacije;
    double tezina_praga;
    double pobuda;
    double prethodna_pobuda;
    double naredna_pobuda;
    double izlaz;
    double izlaz_u_prethodnom_ciklusu;
    double izlazna_greska;
    double normalizovana_izlazna_greska;
    double srednja_kumulativna_vrednost_promene_greske_izlaza_celije;
    double pozitivna_kumulativna_greska_celije;
    double negativna_kumulativna_greska_celije;
    double faktor_secanja;
    double verovatnoca_deobe;
    double informativna_energija;
    string kljuc;
    string log_faktora_aktivnosti;
    ofstream filestr;
    char filename[3];
    int broj_zapisa;

    Mapa_pobudjujucih_tezina pobudjujuce_tezine;
    Mapa_pobudjivackih_tezina pobudjivacke_tezine;


    public:
    SkrivenaCelija(){}
    SkrivenaCelija(int broj_skrivenog_sloja,int broj_celije_u_sloju,double prag_aktivacije);

    Mapa_pobudjujucih_tezina::iterator it1;
    Mapa_pobudjivackih_tezina::iterator it2;

    double getUlaznaTezina();
    double getIzlaznaTezina();
    double getPragAktivacije();
    double getTezinaPraga();
    double getPobuda();
    double getIzlaz();
    double getPrethodniIzlaz();
    double getNaredniIzlaz();
    double getIzlaznaGreska();
    double getNormalizovanaIzlaznaGreska();
    double getSrednja_kumulativna_vrednost_promene_greske_izlaza_celije();
    double getPozitivna_kumulativna_greska();
    double getNegativna_kumulativna_greska();
    double getVerovatnoca_deobe();
    double getInformativnaEnergija();
    int getBroj_skrivenog_sloja();
    int getBroj_celije_u_skrivenom_sloju();
    string getKljuc();
    Mapa_pobudjujucih_tezina getPobudjujuceTezine();
    Mapa_pobudjivackih_tezina getPobudjivackeTezine();
    string getPrvuPobudjivackuTezinu();
    string getPrvuPobudjujucuTezinu();
    void erasePrvuPobudjivackuTezinu();
    void erasePrvuPobudjujucuTezinu();
    string SK_ToString();

    void setUlaznaTezina(double ulazna_tezina);
    void setIzlaznaTezina(double izlazna_tezina);
    void setPragAktivacije(double prag_aktivacije);
    void setTezinaPraga(double tezina_praga);
    void setPobuda(double pobuda);
    void setIzlaz(double izlaz);
    void setIzlaznaGreska(double izlazna_greska);
    void setNormalizovanaIzlaznaGreska(double normalizovana_izlazna_greska);
    void setSrednja_kumulativna_vrednost_promene_greske_izlaza_celije();
    void setPozitivna_kumulativna_greska();
    void setNegativna_kumulativna_greska();
    void setVerovatnoca_deobe(double tezinski_faktor_deobe, double vremenski_faktor_deobe);
    void setInformativnaEnergija(double informativna_energija);
    void addPobudjujucuTezinu(string kljuc);
    void addPobudjivackuTezinu(string kljuc);
    void erasePobudjujucuTezinu(string kljuc);
    void erasePobudjivackuTezinu(string kljuc);
    void apdejtujLogFaktoraAktivnosti(string log_faktora_aktivnosti);
    void zapisiLogFaktoraAktivnosti();

    void eraseMapeTezina(){pobudjujuce_tezine.clear();
                           pobudjivacke_tezine.clear();
                           };
    void erasePobudjujuceTezine(){this->pobudjujuce_tezine.clear();}


    void prikaziStanje();
};

#endif // SKRIVENACELIJA_H_INCLUDED
