#ifndef KLJUC_SKRIVENIH_CELIJA_HPP_INCLUDED
#define KLJUC_SKRIVENIH_CELIJA_HPP_INCLUDED

class Kljuc_skrivenih_celija{
    private:
    int broj_skrivenog_sloja;
    int broj_celije_u_skrivenom_sloju;
    public:
    Kljuc_skrivenih_celija(){};
    Kljuc_skrivenih_celija(int broj_skrivenog_sloja,int broj_celije_u_skrivenom_sloju){
            this->broj_skrivenog_sloja = broj_skrivenog_sloja;
            this->broj_celije_u_skrivenom_sloju = broj_celije_u_skrivenom_sloju;
        }
    int getBroj_skrivenog_sloja(){return broj_skrivenog_sloja;};
    int getBroj_celije_u_skrivenom_sloju(){return broj_celije_u_skrivenom_sloju;};

    void setBroj_skrivenog_sloja(int broj_skrivenog_sloja){this->broj_skrivenog_sloja = broj_skrivenog_sloja;};
    void setBroj_celije_u_skrivenom_sloju(int broj_celije_u_skrivenom_sloju){this->broj_celije_u_skrivenom_sloju = broj_celije_u_skrivenom_sloju;};
};

#endif // KLJUC_SKRIVENIH_CELIJA_HPP_INCLUDED
