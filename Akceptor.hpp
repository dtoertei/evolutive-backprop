#ifndef AKCEPTOR_HPP_INCLUDED
#define AKCEPTOR_HPP_INCLUDED
#include <iostream>

using namespace std;

class Akceptor{
    private:
    double izlaz; //ulaz i izlaz su ovde isti, ali AKO IKADA ZATREBA NEKA KONVERZIJA...
    double prethodni_izlaz;
    int broj_akceptora; //setuje se u NeuronskaMreza zbog tezina
    public:
    Akceptor(){};
    Akceptor(double izlaz,int broj_akceptora);

    double getIzlaz();
    double getPrethodniIzlaz();
    int getBrojAkceptora();
    string AkceptorToString();

    void setIzlaz(double izlaz);
    void setBrojAkceptora(int broj_akceptora);

    void prikaziStanje();
};

#endif // AKCEPTOR_HPP_INCLUDED
