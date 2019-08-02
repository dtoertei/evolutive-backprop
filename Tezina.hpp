#ifndef TEZINA_H_INCLUDED
#define TEZINA_H_INCLUDED

#include <iostream>
#include "Kljuc_tezina.hpp"

class Tezina{
    protected:

    int pocetak;
    int kraj;
    double vrednost;
    double faktor_aktivnosti;
    double prethodni_faktor_aktivnosti;
    double normalizovani_faktor_aktivnosti;
    double verovatnoca_degeneracije_sinapse;

    public:

    int getPocetak(){return pocetak;};
    int getKraj(){return kraj;};
    double getVrednost(){return vrednost;};
    double getFaktorAktivnosti(){return faktor_aktivnosti;};
    double getPrethodniFaktorAktivnosti(){return prethodni_faktor_aktivnosti;};
    double getNormalizovaniFaktorAktivnosti(){return normalizovani_faktor_aktivnosti;};
    double getVerovatnocaDegeneracijeSinapse(){return verovatnoca_degeneracije_sinapse;};
    string getKljuc();

    void setPocetak(int pocetak){this->pocetak = pocetak;};
    void setKraj(int kraj){this->kraj = kraj;};
    void setVrednost(double vrednost){this->vrednost = vrednost;};
    void setFaktorAktivnostiSinapse(double faktor_aktivnosti){
        this->prethodni_faktor_aktivnosti = this->faktor_aktivnosti;
        this->faktor_aktivnosti = faktor_aktivnosti;
        };
    void setNormalizovaniFaktorAktivnostiSinapse(double normalizovani_faktor_aktivnosti){this->normalizovani_faktor_aktivnosti = normalizovani_faktor_aktivnosti;};
    void setVerovatnocaDegeneracijeSinapse(double verovatnoca_degeneracije_sinapse){this->verovatnoca_degeneracije_sinapse = verovatnoca_degeneracije_sinapse;};

    void prikaziStanje();

};

#endif // TEZINA_H_INCLUDED
