#include <iostream>
#include "Akceptor.hpp"
#include <sstream>

using namespace std;

Akceptor::Akceptor(double izlaz,int broj_akceptora){
        this->prethodni_izlaz = 0;
        this->izlaz= izlaz;
        this->broj_akceptora = broj_akceptora;
    }

double Akceptor::getIzlaz(){
        return this->izlaz;
    }
double Akceptor::getPrethodniIzlaz(){
        return this->prethodni_izlaz;
    }

int Akceptor::getBrojAkceptora(){
        return this->broj_akceptora;
    }
string Akceptor::AkceptorToString(){

    string log = "";
    stringstream out;

    out << "\nStanje akceptora ";
    out << this->broj_akceptora;
    out << ":\n\tIzlaz:\t";
    out << this->izlaz;
    out << "\n\t\tPrethodni izlaz, naredni:\t";
    out << getPrethodniIzlaz();
    out << " ";
    out << getIzlaz();
    out << "\n\n";
    log = out.str();
    return log;
    }

void Akceptor::setIzlaz(double izlaz){
        this->prethodni_izlaz = this->izlaz;
        this->izlaz= izlaz;
    }

void Akceptor::setBrojAkceptora(int broj_akceptora){
        this->broj_akceptora = broj_akceptora;
    }

void Akceptor::prikaziStanje(){
        cout<<"\nStanje akceptora:\n\tIzlaz:\t"
        <<this->izlaz<<"\n\tBroj akceptora:\t"
        <<this->broj_akceptora<<"\n\t\tPrethodni izlaz, naredni:\t"
        <<getPrethodniIzlaz()<<" "<<getIzlaz()<<endl;
    }
