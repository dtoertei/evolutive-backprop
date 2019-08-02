#include <iostream>
#include <sstream>
#include "SkrivenaCelija.hpp"
#include "Tezina_pragova.hpp"
#include <math.h>

using namespace std;

SkrivenaCelija::SkrivenaCelija(int broj_skrivenog_sloja,int broj_celije_u_sloju,double prag_aktivacije){
        this->prag_aktivacije = prag_aktivacije;
        this->tezina_praga = 0.0;
        this->pozitivna_kumulativna_greska_celije = 0;
        this->negativna_kumulativna_greska_celije = 0;
        this->pobuda = 0;
        this->prethodna_pobuda = 0;
        this->naredna_pobuda = 0;
        this->faktor_secanja = 0.99;
        this->log_faktora_aktivnosti = "";
        this->broj_zapisa = 0;

        stringstream out;
        out << broj_skrivenog_sloja;
        out << broj_celije_u_sloju;
        this->kljuc = out.str();

        filename[0] = kljuc.at(0);
        filename[1] = kljuc.at(1);
        filename[2] = '\0';
    }

double SkrivenaCelija::getPragAktivacije(){
        return this->prag_aktivacije;
    }
double SkrivenaCelija::getTezinaPraga(){
        return this->tezina_praga;
    }
double SkrivenaCelija::getPobuda(){
        return this->pobuda;
    }
double SkrivenaCelija::getPrethodniIzlaz(){
        return 1/(1+exp(-this->prethodna_pobuda));
    }
double SkrivenaCelija::getNaredniIzlaz(){
        return 1/(1+exp(-this->naredna_pobuda));
    }

double SkrivenaCelija::getIzlaz(){
        return this->izlaz;
    }
double SkrivenaCelija::getIzlaznaGreska(){
        return this->izlazna_greska;
    }
double SkrivenaCelija::getNormalizovanaIzlaznaGreska(){
        return this->normalizovana_izlazna_greska;
    }
int SkrivenaCelija::getBroj_skrivenog_sloja(){
    char sloj = this->kljuc.at(0);
    return (int)sloj-48;
    }
int SkrivenaCelija::getBroj_celije_u_skrivenom_sloju(){
    string sub = this->kljuc.substr(1);
    int length = sub.length();
    int broj = 0;
    for(int i = 0; i<length; i++){
        broj += (((int)sub.at(i))-48)*pow(10,(length-1-i));
        }
    return broj;
    }
double SkrivenaCelija::getSrednja_kumulativna_vrednost_promene_greske_izlaza_celije(){
    return srednja_kumulativna_vrednost_promene_greske_izlaza_celije;
    }
double SkrivenaCelija::getPozitivna_kumulativna_greska(){
    return pozitivna_kumulativna_greska_celije;
    }
double SkrivenaCelija::getNegativna_kumulativna_greska(){
    return negativna_kumulativna_greska_celije;
    }
double SkrivenaCelija::getVerovatnoca_deobe(){
    return verovatnoca_deobe;
    }
double SkrivenaCelija::getInformativnaEnergija(){
    return informativna_energija;
    }

string SkrivenaCelija::getKljuc(){
    return this->kljuc;
    }

Mapa_pobudjujucih_tezina SkrivenaCelija::getPobudjujuceTezine(){
    return pobudjujuce_tezine;
    }
Mapa_pobudjivackih_tezina SkrivenaCelija::getPobudjivackeTezine(){
    return pobudjivacke_tezine;
    }
string SkrivenaCelija::getPrvuPobudjivackuTezinu(){
    if(pobudjivacke_tezine.empty()){
        return NULL;
        }
    it2 = pobudjivacke_tezine.begin();
    return it2->second;
    }
string SkrivenaCelija::getPrvuPobudjujucuTezinu(){
    if(pobudjujuce_tezine.empty()){
        return NULL;
        }
    it1 = pobudjujuce_tezine.begin();
    return it1->second;
    }
void SkrivenaCelija::erasePrvuPobudjivackuTezinu(){
    if(!pobudjivacke_tezine.empty()){
        it2 = pobudjivacke_tezine.begin();
        pobudjivacke_tezine.erase(it2->second);
    }
    }
void SkrivenaCelija::erasePrvuPobudjujucuTezinu(){
    if(!pobudjujuce_tezine.empty()){
        it1 = pobudjujuce_tezine.begin();
        pobudjujuce_tezine.erase(it1->second);
    }
    }
string SkrivenaCelija::SK_ToString(){

    string log = "";
    stringstream out;

    out << "\nStanje SK ";
    out << this->getKljuc();
    out << ":\n\tBias:\t";
    out << this->getPragAktivacije();
    out << "\tTezina biasa: ";
    out << this->getTezinaPraga();
    out << "\n\tPobuda: ";
    out << this->getPobuda();
    out << "\tIzlaz: ";
    out << this->getIzlaz();
    out << "\n\tPrethodni izlaz, naredni, trenutni?: ";
    out << this->getPrethodniIzlaz();
    out << " ";
    out << this->getNaredniIzlaz();
    out << " ";
    out << this->getIzlaz();
    out << "\n\tIzlazna greska: ";
    out << this->getIzlaznaGreska();
    out << "\n\tNormalizovana izlazna greska: ";
    out << this->getNormalizovanaIzlaznaGreska();
    out << "\n\tPozitivna kumulativna greska: ";
    out << this->getPozitivna_kumulativna_greska();
    out << "\n\tNegativna kumulativna greska: ";
    out << this->getNegativna_kumulativna_greska();
    out << "\n\tSrednja kumulativna vrednost promene greske izlaza celije: ";
    out << this->getSrednja_kumulativna_vrednost_promene_greske_izlaza_celije();
    out << "\n\tVerovatnoca deobe: ";
    out << this->getVerovatnoca_deobe();
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
    out << "\n\tPobudjivacke tezine: ";
    if(pobudjivacke_tezine.empty()){
        out << "nema";
    }else{
        for(it2 = pobudjivacke_tezine.begin(); it2 != pobudjivacke_tezine.end(); it2++){
            out << it2->second;
            out << " ";
        }
    }

    out << "\n\n\n";
    log = out.str();
    return log;
    }

void SkrivenaCelija::setPragAktivacije(double prag_aktivacije){
        this->prag_aktivacije = prag_aktivacije;
    }
void SkrivenaCelija::setTezinaPraga(double tezina_praga){
        this->tezina_praga = tezina_praga;
    }
void SkrivenaCelija::setPobuda(double pobuda){
        this->prethodna_pobuda = this->pobuda;
        this->pobuda = pobuda;
        this->naredna_pobuda = pobuda;

        string s;
        stringstream out;
        out << broj_zapisa;
        out << " ";
        out << this->prethodna_pobuda;
        out << " ";
        out << this->naredna_pobuda;
        out << "\n";

        s = out.str();
        //apdejtujLogFaktoraAktivnosti(s);
        //broj_zapisa++;
}
void SkrivenaCelija::apdejtujLogFaktoraAktivnosti(string log_faktora_aktivnosti){
    this->log_faktora_aktivnosti.append(log_faktora_aktivnosti);
}
void SkrivenaCelija::zapisiLogFaktoraAktivnosti(){
    filestr.open(filename);
    if (filestr.is_open()){
        filestr << log_faktora_aktivnosti;
    }
    filestr.close();
}
void SkrivenaCelija::setIzlaz(double izlaz){
        this->izlaz = 1/(1+exp(-izlaz));
    }
void SkrivenaCelija::setIzlaznaGreska(double izlazna_greska){
        this->izlazna_greska = izlazna_greska;
    }
void SkrivenaCelija::setNormalizovanaIzlaznaGreska(double normalizovana_izlazna_greska){
        this->normalizovana_izlazna_greska = normalizovana_izlazna_greska;
    }
void SkrivenaCelija::setSrednja_kumulativna_vrednost_promene_greske_izlaza_celije(){
    double zbir = pozitivna_kumulativna_greska_celije+negativna_kumulativna_greska_celije;
    double razlika = pozitivna_kumulativna_greska_celije-negativna_kumulativna_greska_celije;
    if(razlika<0)razlika*=-1;
    if(zbir>0){
        srednja_kumulativna_vrednost_promene_greske_izlaza_celije = 1-(razlika/zbir);
        }else{
        srednja_kumulativna_vrednost_promene_greske_izlaza_celije = 0;
        }
    }
void SkrivenaCelija::setPozitivna_kumulativna_greska(){
    double nova_pozitivna_kumulativna_greska_celije = 0;
    if(normalizovana_izlazna_greska>0){
        nova_pozitivna_kumulativna_greska_celije = normalizovana_izlazna_greska + faktor_secanja*pozitivna_kumulativna_greska_celije;
    }else{
        nova_pozitivna_kumulativna_greska_celije = faktor_secanja*pozitivna_kumulativna_greska_celije;
        }
    pozitivna_kumulativna_greska_celije = nova_pozitivna_kumulativna_greska_celije;
    }
void SkrivenaCelija::setNegativna_kumulativna_greska(){
    double nova_negativna_kumulativna_greska_celije = 0;
    if(normalizovana_izlazna_greska<0){
        nova_negativna_kumulativna_greska_celije= -normalizovana_izlazna_greska + faktor_secanja*negativna_kumulativna_greska_celije;
    }else{
        nova_negativna_kumulativna_greska_celije = faktor_secanja*negativna_kumulativna_greska_celije;
        }
    negativna_kumulativna_greska_celije = nova_negativna_kumulativna_greska_celije;
    }
void SkrivenaCelija::setVerovatnoca_deobe(double tezinski_faktor_deobe, double vremenski_faktor_deobe){
    verovatnoca_deobe = tezinski_faktor_deobe*vremenski_faktor_deobe*srednja_kumulativna_vrednost_promene_greske_izlaza_celije;
    }
void SkrivenaCelija::setInformativnaEnergija(double informativna_energija){
    this->informativna_energija = informativna_energija;
    }

void SkrivenaCelija::addPobudjujucuTezinu(string kljuc){
    pobudjujuce_tezine.insert(make_pair(kljuc,kljuc));
    }
void SkrivenaCelija::addPobudjivackuTezinu(string kljuc){
    pobudjivacke_tezine.insert(make_pair(kljuc,kljuc));
    }
void SkrivenaCelija::erasePobudjujucuTezinu(string kljuc){
    if(!pobudjujuce_tezine.empty())
    pobudjujuce_tezine.erase(kljuc);
    }
void SkrivenaCelija::erasePobudjivackuTezinu(string kljuc){
    if(!pobudjivacke_tezine.empty())
    pobudjivacke_tezine.erase(kljuc);
    }

void SkrivenaCelija::prikaziStanje(){

        //zapisiLogFaktoraAktivnosti();

        cout<<"\nStanje skrivene celije:\n"<<"\n\tPobuda:\t"
        <<pobuda;
//        cout<<"\n\tPrag aktivacije:\t"
//        <<prag_aktivacije<<"\n\tIzlaz:\t"
//        <<getIzlaz()<<"\n\tIzlazna greska:\t"
//        <<getIzlaznaGreska()<<"\n\tNormalizovana izlazna greska:\t"
//        <<getNormalizovanaIzlaznaGreska()<<"\n\tPozitivna kumulativna greska celije:\t"
//        <<getPozitivna_kumulativna_greska()<<"\n\tNegativna kumulativna greska celije:\t"
//        <<getNegativna_kumulativna_greska()<<"\n\tSrednja kumulativna vrednost promene greske izlaza celije:"
//        cout<<getSrednja_kumulativna_vrednost_promene_greske_izlaza_celije();
        cout<<"\n\tKljuc skrivene celije:\n\t\tBroj skrivenog sloja celije:\t"
        <<getBroj_skrivenog_sloja()<<"\n\t\tBroj celije:\t"
        <<getBroj_celije_u_skrivenom_sloju();
//        cout<<"\n\t\tPrethodni izlaz, naredni, informativna energija:\t"
//        <<getPrethodniIzlaz()<<" "<<getNaredniIzlaz()<<"  "<<getInformativnaEnergija();
        cout<<endl;
        cout<<"Pobudjujuce tezine: ";
        if(!pobudjujuce_tezine.empty()){
        for(it1 = pobudjujuce_tezine.begin(); it1 != pobudjujuce_tezine.end(); it1++)
            cout<<it1->second<<" ";
        }
        cout<<endl;
        cout<<"Pobudjivacke tezine: ";
        if(!pobudjivacke_tezine.empty()){
        for(it2 = pobudjivacke_tezine.begin(); it2 != pobudjivacke_tezine.end(); it2++)
            cout<<it2->second<<" ";
        }
        cout<<endl;
        cout<<"BIAS: "<<getPragAktivacije()<<endl;
        cout<<"TEZINA BIAS-a: "<<getTezinaPraga()<<endl;
        cout<<"POBUDA: "<<pobuda<<endl;
        cout<<"IZLAZ: "<<getIzlaz()<<endl;
    }
