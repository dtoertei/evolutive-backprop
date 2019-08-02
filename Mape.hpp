#ifndef MAPE_HPP_INCLUDED
#define MAPE_HPP_INCLUDED

#include <iostream>
#include "Akceptor.hpp"
#include "SkrivenaCelija.hpp"

#include <vector>
#include <map.h>

typedef vector<Akceptor*>Vektor_akceptora;
typedef map<SkrivenaCelija*,Vektor_akceptora*>Mapa_akceptorskih_pobudjivaca;

class Mape{
    private:
    static Vektor_akceptora vektor_akceptora;
    static Mapa_akceptorskih_pobudjivaca mapa_akceptorskih_pobudjivaca;
    static Vektor_akceptora::iterator it1;
    static Mapa_akceptorskih_pobudjivaca::iterator it2;

    public:

    static Vektor_akceptora* getVektor_akceptora(){return &vektor_akceptora;}
    static Mapa_akceptorskih_pobudjivaca* getMapa_akceptorskih_pobudjivaca(){return &mapa_akceptorskih_pobudjivaca;}

    static void ubaci_u_vektor_akceptora(Akceptor* a){
            it1 = vektor_akceptora.begin();
            vektor_akceptora.insert(it1,a);
        }

};

#endif // MAPE_HPP_INCLUDED
