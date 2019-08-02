#include <iostream>
#include <fstream>
#include "math.h"
#include "Efektor.hpp"

using namespace std;

Efektor::Efektor(double ulazna_tezina, double izlaz, double izlazna_greska,double prag_aktivacije,double pobuda,int broj_efektora,int broj_sloja){
    this->ulazna_tezina = ulazna_tezina;
    this->izlaz = izlaz;
    this->izlazna_greska = izlazna_greska;
    this->prag_aktivacije = prag_aktivacije;
    this->tezina_praga = 0.0;
    this->pobuda = pobuda;
    this->broj_efektora = broj_efektora;
    this->broj_sloja = broj_sloja;

    stringstream out;
    out << broj_sloja;
    out << broj_efektora;
    this->kljuc = out.str();

    filename[0] = kljuc.at(0);
    filename[1] = kljuc.at(1);
    filename[2] = '\0';
    };

double Efektor::getUlaznaTezina(){
        return this->ulazna_tezina;
    };

double Efektor::getIzlaz(){
        return this->izlaz;
    };

double Efektor::getIzlaznaGreska(){
        return this->izlazna_greska;
    };

double Efektor::getPragAktivacije(){
        return this->prag_aktivacije;
    };
double Efektor::getTezinaPraga(){
    return tezina_praga;
    };
double Efektor::getPobuda(){
        return this->pobuda;
    };

double Efektor::getInformativnaEnergija(){
    return informativna_energija;
    };

int Efektor::getBrojEfektora(){
        return this->broj_efektora;
    };

int Efektor::getBrojSloja(){
        return this->broj_sloja;
    };
string Efektor::getKljuc(){
        return this->kljuc;
    };
Mapa_pobudjujucih_tezina Efektor::getPobudjujuceTezine(){
    return pobudjujuce_tezine;
    };
void Efektor::addPobudjujucuTezinu(string kljuc){
    pobudjujuce_tezine.insert(make_pair(kljuc,kljuc));
    };
void Efektor::erasePobudjujucuTezinu(string kljuc){
    if(!pobudjujuce_tezine.empty())
    pobudjujuce_tezine.erase(kljuc);
    };
string Efektor::EfektorToString(){

    string log = "";
    stringstream out;

    out << "\nStanje efektora ";
    out << this->getKljuc();
    out << ":\n\tIzlaz:\t";
    out << this->getIzlaz();
    out << "\n\tIzlazna greska: ";
    out << this->getIzlaznaGreska();
    out << "\n\tBias: ";
    out << this->getPragAktivacije();
    out << "\tTezina praga: ";
    out << this->getTezinaPraga();
    out << "\n\tPobuda: ";
    out << this->getPobuda();
    out << "\n\tInformativna energija: ";
    out << this->getInformativnaEnergija();
    out << "\n\tPobudjujuce tezine: ";
    if(pobudjujuce_tezine.empty()){
        out << "nema";
    }else{
        for(it1 = pobudjujuce_tezine.begin(); it1 != pobudjujuce_tezine.end(); it1++){
            out << it1->second;
            out << " ";
        }
    }
    out << "\n\n\n";
    log = out.str();
    return log;
    };
void Efektor::setUlaznaTezina(double ulazna_tezina){
        this->ulazna_tezina = ulazna_tezina;
    };

void Efektor::setIzlaz(double izlaz){
        this->izlaz = 1/(1+exp(-izlaz));
    };

void Efektor::setIzlaznaGreska(double izlazna_greska){
        this->izlazna_greska = izlazna_greska;
    };

void Efektor::setPragAktivacije(double prag_aktivacije){
        this->prag_aktivacije = prag_aktivacije;
    };
void Efektor::setTezinaPraga(double tezina_praga){
        this->tezina_praga = tezina_praga;
    };
void Efektor::setPobuda(double pobuda){
        this->pobuda = pobuda;

        string s;
        stringstream out;
        out << broj_zapisa;
        out << " ";
        out << this->pobuda;
        out << "\n";

        s = out.str();
        apdejtujLogFaktoraAktivnosti(s);
        broj_zapisa++;
    };

void Efektor::setInformativnaEnergija(double informativna_energija){
    this->informativna_energija = informativna_energija;
    }

void Efektor::setBrojEfektora(int broj_efektora){
        this->broj_efektora = broj_efektora;
    };

void Efektor::setBrojSloja(int broj_sloja){
        this->broj_sloja = broj_sloja;
    };
void Efektor::apdejtujLogFaktoraAktivnosti(string log_faktora_aktivnosti){
    this->log_faktora_aktivnosti.append(log_faktora_aktivnosti);
    };
void Efektor::zapisiLogFaktoraAktivnosti(){
    filestr.open(filename);
    if (filestr.is_open()){
        filestr << log_faktora_aktivnosti;
    }
    filestr.close();
    };

void Efektor::prikaziStanje(){

    zapisiLogFaktoraAktivnosti();

    cout<<"\nStanje efektora je: "<<"\nUlazna tezina:\t"
    <<this->ulazna_tezina<<"\nIzlaz:\t"
    <<this->izlaz<<"\nIzlazna greska:\t"
    <<this->izlazna_greska<<"\nPobuda:\t"
    <<this->pobuda<<"\nPrag aktivacije:\t"
    <<this->prag_aktivacije<<"\nBroj efektora:\t"
    <<this->broj_efektora<<"\nBroj sloja:\t"
    <<this->broj_sloja<<"Informativna energija:\t"
    <<this->getInformativnaEnergija()<<endl;
    };
