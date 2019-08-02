#ifndef KLJUC_TEZINA_HPP_INCLUDED
#define KLJUC_TEZINA_HPP_INCLUDED

class Kljuc_tezina{
    private:
    int broj_prethodnog_sloja;
    int broj_narednog_sloja;
    int broj_celije_pobudjivaca;
    int broj_pobudjivane_celije;
    public:
    Kljuc_tezina(){};
    Kljuc_tezina(int broj_prethodnog_sloja,int broj_narednog_sloja,int broj_celije_pobudjivaca,int broj_pobudjivane_celije){
        this->broj_prethodnog_sloja = broj_prethodnog_sloja;
        this->broj_narednog_sloja = broj_narednog_sloja;
        this->broj_celije_pobudjivaca = broj_celije_pobudjivaca;
        this->broj_pobudjivane_celije = broj_pobudjivane_celije;
        }
    int getBroj_prethodnog_sloja(){return broj_prethodnog_sloja;};
    int getBroj_narednog_sloja(){return broj_narednog_sloja;};
    int getBroj_celije_pobudjivaca(){return broj_celije_pobudjivaca;};
    int getBroj_pobudjivane_celije(){return broj_pobudjivane_celije;};

    void setBroj_prethodnog_sloja(int broj_prethodnog_sloja){this->broj_prethodnog_sloja = broj_prethodnog_sloja;};
    void setBroj_narednog_sloja(int broj_narednog_sloja){this->broj_narednog_sloja = broj_narednog_sloja;};
    void setBroj_celije_pobudjivaca(int broj_celije_pobudjivaca){this->broj_celije_pobudjivaca = broj_celije_pobudjivaca;};
    void setBroj_pobudjivane_celije(int broj_pobudjivane_celije){this->broj_pobudjivane_celije = broj_pobudjivane_celije;};
};

#endif // KLJUC_TEZINA_HPP_INCLUDED
