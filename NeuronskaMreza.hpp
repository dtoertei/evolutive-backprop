#ifndef NEURONSKAMREZA_HPP_INCLUDED
#define NEURONSKAMREZA_HPP_INCLUDED
#include <iostream>

#include "Akceptor.hpp"
#include "Efektor.hpp"
#include "SkrivenaCelija.hpp"
#include "Tezina_ka_skrivenom_sloju.hpp"
#include "Tezina_izmedju_skrivenih_slojeva.hpp"
#include "Tezina_ka_efektoru.hpp"
#include "Kljuc_skrivenih_celija.hpp"
#include "Kljuc_tezina.hpp"
#include "Tezina_pragova.hpp"
#include "Tezina_akceptora_ka_efektoru.hpp"

#include <map>
#include <vector>
#include <math.h>
#include <cmath>
#include <sstream>
#include <fstream>

typedef map<int,Akceptor*> Akceptori;
typedef map<int,Efektor*> Efektori;
typedef map<string,SkrivenaCelija*> SkriveneCelije;

typedef map<string,Tezina_ka_skrivenom_sloju*> Tezine_ka_skrivenom_sloju;
typedef map<string,Tezina_izmedju_skrivenih_slojeva*> Tezine_izmedju_skrivenih_slojeva;
typedef map<string,Tezina_ka_efektoru*> Tezine_ka_efektoru;
typedef map<string,Tezina_pragova*> Tezine_pragova;
typedef map<string,Tezina_akceptora_ka_efektoru*> Tezine_akceptora_ka_efektoru;


class NeuronskaMreza{
        private:
        Akceptori akceptori;
        Efektori efektori;
        SkriveneCelije skrivene_celije;
        Tezine_ka_skrivenom_sloju tezine_ka_skrivenom_sloju;
        Tezine_izmedju_skrivenih_slojeva tezine_izmedju_skrivenih_slojeva;
        Tezine_ka_efektoru tezine_ka_efektoru;
        Tezine_pragova tezine_pragova;
        Tezine_akceptora_ka_efektoru tezine_akceptora_ka_efektoru;

        int broj_ulaza;
        int broj_skrivenih_celija;
        int broj_izlaza;
        int dubina;

        int broj_uzoraka;
        int broj_iteracija;
        float dozvoljena_greska;
        float izlazna_greska_pri_odgovoru_mreze;
        //atributi potrebni za deobu celija
        int broj_ciklusa_proteklih_od_zadnje_deobe;
        int faktor_oporavka;
        double vremenski_faktor_deobe;
        double tezinski_faktor_deobe;
        double faktor_secanja_degeneracije_sinapse;
        double faktor_mutacije;
        int broj_deoba;
        //atributi potrebni za degeneraciju sinapsi
        double granicna_vrednost_aktivnosti_sinapsi;
        double faktor_degeneracije_sinapsi;
        double faktor_osetljivosti_na_degeneraciju;
        double vremenski_faktor_degeneracije_sinapsi;
        int broj_ciklusa_proteklih_od_poslednje_degeneracije_sinapse_u_mrezi;
        int faktor_oporavka_na_degeneraciju_sinapse;
        int broj_degeneracija_sinapsi;
        //atributi potrebni za degeneraciju celija
        int broj_degenerisanih_celija;
        string vrsta_degeneracije_celije;

        protected:
        Akceptori::iterator a1;
        Efektori::iterator e1;
        SkriveneCelije::iterator s1;
        SkriveneCelije::iterator s2;
        Tezine_ka_skrivenom_sloju::iterator t1;
        Tezine_izmedju_skrivenih_slojeva::iterator t2;
        Tezine_ka_efektoru::iterator t3;
        Tezine_pragova::iterator t4;
        Tezine_akceptora_ka_efektoru::iterator t5;

        //float obucavajuci_skup_ulaza[4][2];
        //float obucavajuci_skup_izlaza[4];
        //float obucavajuci_skup_ulaza[4][2];
        //float obucavajuci_skup_izlaza[4][2];

        float obucavajuci_skup_ulaza[4][2];
        float obucavajuci_skup_izlaza[4][3];
        int broj_slojeva[]; //zbog prava pristupa kasnije iz metode

        public:

        //OVAJ KONSTRUKTOR NECE OSTATI OVAKAV, SAMO SLUZI ZA PROBU KREIRANJA MREZE ZA OBUKU NA XOR PRIMERU
        // XOR:  {0,0} -> {0}
        //       {1,0} -> {1}
        //       {0,1} -> {1}
        //       {1,1} -> {0}
        void setObucavajuciSkup(){
/*
            broj_uzoraka = 4;

            obucavajuci_skup_ulaza[0][0] = 0;
            obucavajuci_skup_ulaza[0][1] = 0;
            obucavajuci_skup_izlaza[0] = 0;

            obucavajuci_skup_ulaza[1][0] = 1;
            obucavajuci_skup_ulaza[1][1] = 0;
            obucavajuci_skup_izlaza[1] = 1;

            obucavajuci_skup_ulaza[2][0] = 0;
            obucavajuci_skup_ulaza[2][1] = 1;
            obucavajuci_skup_izlaza[2] = 1;

            obucavajuci_skup_ulaza[3][0] = 1;
            obucavajuci_skup_ulaza[3][1] = 1;
            obucavajuci_skup_izlaza[3] = 0;
*/
            /**
            OBUCAVAJUCI SKUP ZA ISPITIVANJE DEGENERACIJE SINAPSI
            */
/*
            broj_uzoraka = 4;

            obucavajuci_skup_ulaza[0][0] = 1;
            obucavajuci_skup_ulaza[0][1] = 1;
            obucavajuci_skup_izlaza[0][0] = 1;
            obucavajuci_skup_izlaza[0][1] = 1;


            obucavajuci_skup_ulaza[1][0] = 1;
            obucavajuci_skup_ulaza[1][1] = 0;
            obucavajuci_skup_izlaza[1][0] = 1;
            obucavajuci_skup_izlaza[1][1] = 0;


            obucavajuci_skup_ulaza[2][0] = 0;
            obucavajuci_skup_ulaza[2][1] = 1;
            obucavajuci_skup_izlaza[2][0] = 0;
            obucavajuci_skup_izlaza[2][1] = 1;


            obucavajuci_skup_ulaza[3][0] = 0;
            obucavajuci_skup_ulaza[3][1] = 0;
            obucavajuci_skup_izlaza[3][0] = 0;
            obucavajuci_skup_izlaza[3][1] = 0;
*/
            /**
            OBUCAVAJUCI SKUP ZA OR, AND I XOR FUNKCIJE ODJEDNOM
            */

            broj_uzoraka = 4;

            obucavajuci_skup_ulaza[0][0] = 1;
            obucavajuci_skup_ulaza[0][1] = 1;
            obucavajuci_skup_izlaza[0][0] = 1;
            obucavajuci_skup_izlaza[0][1] = 1;
            obucavajuci_skup_izlaza[0][2] = 0;

            obucavajuci_skup_ulaza[1][0] = 1;
            obucavajuci_skup_ulaza[1][1] = 0;
            obucavajuci_skup_izlaza[1][0] = 1;
            obucavajuci_skup_izlaza[1][1] = 0;
            obucavajuci_skup_izlaza[1][2] = 1;

            obucavajuci_skup_ulaza[2][0] = 0;
            obucavajuci_skup_ulaza[2][1] = 1;
            obucavajuci_skup_izlaza[2][0] = 1;
            obucavajuci_skup_izlaza[2][1] = 0;
            obucavajuci_skup_izlaza[2][2] = 1;

            obucavajuci_skup_ulaza[3][0] = 0;
            obucavajuci_skup_ulaza[3][1] = 0;
            obucavajuci_skup_izlaza[3][0] = 0;
            obucavajuci_skup_izlaza[3][1] = 0;
            obucavajuci_skup_izlaza[3][2] = 0;

            }
        // KONSTRUKTOR ZA ZADAVANJE PROIZVOLJNE VELICINE NEURONSKE MREZE, ali za OBICAN BACKPROPAGATION ALGORITAM
        NeuronskaMreza(int broj_ulaza,int broj_skrivenih_celija, int broj_izlaza,int dubina){

            srand(time(NULL));
            this->broj_ulaza = broj_ulaza;
            this->broj_izlaza = broj_izlaza;
            this->broj_skrivenih_celija = broj_skrivenih_celija;
            this->dubina = dubina;
            this->broj_slojeva[dubina+1];
            broj_iteracija = 0;
            dozvoljena_greska = 0.0001;
            //inicijalizacija atributa za deobu
            this->broj_ciklusa_proteklih_od_zadnje_deobe = 0;
            this->faktor_oporavka = 1000;
            this->tezinski_faktor_deobe = 0.025;
            this->faktor_mutacije = 1;
            this->broj_deoba = 0;
            //inicijalizacija atributa za degenereciju SINAPSI
            this->faktor_secanja_degeneracije_sinapse = 0.99;
            this->granicna_vrednost_aktivnosti_sinapsi = 0.25;
            this->faktor_osetljivosti_na_degeneraciju = 20;
            this->faktor_degeneracije_sinapsi = 1;
            this->broj_ciklusa_proteklih_od_poslednje_degeneracije_sinapse_u_mrezi = 0;
            this->faktor_oporavka_na_degeneraciju_sinapse = 1000;
            this->broj_degeneracija_sinapsi = 0;
            //inicijalizacija atributa za degeneraciju CELIJA
            this->broj_degenerisanih_celija = 0;
            this->vrsta_degeneracije_celije = "";

            //UBACIVANJE ULAZA I CELIJA U MREZU, sa TEZINAMA PRAGOVA
            for(int i = 0; i<broj_ulaza; i++){
                Akceptor *akceptor = new Akceptor(0,i);
                akceptori.insert(make_pair(i,akceptor));
            }
            for(int k = 0; k<dubina; k++){
                for(int i = 0; i<broj_skrivenih_celija; i++){
                    SkrivenaCelija *celija = new SkrivenaCelija(k,i,0.2);
                    s1 = skrivene_celije.end();
                    skrivene_celije.insert(s1,pair<string,SkrivenaCelija*>(celija->getKljuc(),celija));
                    Tezina_pragova *tezina = new Tezina_pragova(celija->getKljuc(),((double)rand()/RAND_MAX-0.5));
                    tezine_pragova.insert(make_pair(tezina->getKljuc(),tezina));
                }
            }
            for(int j = 0; j<broj_izlaza; j++){
                Efektor *efektor = new Efektor(0,0,0,0.2,0,j,dubina+1);
                efektori.insert(make_pair(efektor->getBrojEfektora(),efektor));
                Tezina_pragova *tezina = new Tezina_pragova(konkatenacijaIntegera_u_String(efektor->getBrojSloja(),efektor->getBrojEfektora()),((double)rand()/RAND_MAX-0.5));
                tezine_pragova.insert(make_pair(tezina->getKljuc(),tezina));
                }
            //UBACIVANJE TEZINA U MREZU, AKCEPTOR -> SK
            for(int i = 0; i<broj_ulaza; i++){
                Akceptor *akceptor = akceptori.find(i)->second;
                for(int k = 0; k<broj_skrivenih_celija; k++){
                    SkrivenaCelija *celija = skrivene_celije.find(konkatenacijaIntegera_u_String(0,k))->second;
                    Tezina_ka_skrivenom_sloju *akceptorska_tezina = new Tezina_ka_skrivenom_sloju(akceptor,celija,((double)rand()/RAND_MAX-0.5));
                    tezine_ka_skrivenom_sloju.insert(make_pair(akceptorska_tezina->getKljuc(),akceptorska_tezina));

                    //postavljanje pobudjujucih tezina kod skrivenih celija
                    celija->addPobudjujucuTezinu(akceptorska_tezina->getKljuc());
                    }
                }
            //UBACIVANJE TEZINA U MREZU, SK -> SK
            for(int i = 0; i<dubina; i++){
                if((i+1)==(dubina))break;
                for(int k = 0; k<broj_skrivenih_celija; k++){
                    SkrivenaCelija *prethodna = skrivene_celije.find(konkatenacijaIntegera_u_String(i,k))->second;
                    for(int j = 0; j<broj_skrivenih_celija; j++){
                        SkrivenaCelija *sledeca = skrivene_celije.find(konkatenacijaIntegera_u_String(i+1,j))->second;
                        Tezina_izmedju_skrivenih_slojeva *tezina = new Tezina_izmedju_skrivenih_slojeva(prethodna,sledeca,((double)rand()/RAND_MAX-0.5));
                        tezine_izmedju_skrivenih_slojeva.insert(make_pair(tezina->getKljuc(),tezina));
                        //postavljanje pobudjujucih tezina kod skrivenih celija
                        sledeca->addPobudjujucuTezinu(tezina->getKljuc());
                        //postavljanje pobudjivackih tezina kod skrivenih celija
                        prethodna->addPobudjivackuTezinu(tezina->getKljuc());
                        }
                    }
                }
            //UBACIVANJE TEZINA U MREZU, SK -> EFEKTORI
            for(int i = 0; i<broj_skrivenih_celija; i++){
                SkrivenaCelija *poslednja = skrivene_celije.find(konkatenacijaIntegera_u_String(dubina-1,i))->second;
                for(int k = 0; k<broj_izlaza; k++){
                    Efektor *efektor = efektori.find(k)->second;
                    Tezina_ka_efektoru *efektorska_tezina = new Tezina_ka_efektoru(poslednja,efektor,((double)rand()/RAND_MAX-0.5));
                    tezine_ka_efektoru.insert(make_pair(efektorska_tezina->getKljuc(),efektorska_tezina));
                    //postavljanje pobudjujucih tezina kod efektora
                    efektor->addPobudjujucuTezinu(efektorska_tezina->getKljuc());
                    //postavljanje pobudjivackih tezina kod skrivenih celija
                    poslednja->addPobudjivackuTezinu(efektorska_tezina->getKljuc());
                    }
                }
            setObucavajuciSkup();
            setInicijalnaVelicinaMreze();
            }
        void postaviUlaze(int uzorak, bool test){
            if(test)cout<<"***************************POSTAVLJANJE ULAZA***************************"<<endl;
            for(int i = 0; i<broj_ulaza; i++){
                if(test)cout<<"Prethodno stanje:"<<"\n\takceptor "<<akceptori.find(i)->second->getBrojAkceptora()<<": "<<akceptori.find(i)->second->getIzlaz()<<endl;
                akceptori.find(i)->second->setIzlaz(obucavajuci_skup_ulaza[uzorak][i]);
                if(test)cout<<"Novo stanje:"<<"\n\takceptor "<<akceptori.find(i)->second->getBrojAkceptora()<<": "<<akceptori.find(i)->second->getIzlaz()<<endl;
                }
            cout<<"\n";
            }
        void setInicijalnaVelicinaMreze(){
            int velicina = this->dubina + 1;

            for(int i = 0; i<= velicina; i++){
                broj_slojeva[i] = 0;
            }
            this->broj_slojeva[0] = broj_ulaza;
            this->broj_slojeva[velicina] = broj_izlaza;

            for(s1 = skrivene_celije.begin(); s1!= skrivene_celije.end(); s1++){
                broj_slojeva[s1->second->getBroj_skrivenog_sloja()+1]++;
            }
        }
        void prikaziVelicinuMreze(){
            //int velicina = this->dubina + 1;

            //cout<<"\n\nVELICINA MREZE\n\n";
            //for(int i = 0; i<= velicina; i++){
            //    cout<<" "<<broj_slojeva[i]<<" ";
            //}
            cout<<akceptori.size()<<" ";
            cout<<skrivene_celije.size()<<" ";
            cout<<efektori.size()<<endl;
        }

        void setIzlaznaGreskaPriOdgovoruMreze(int uzorak){
                //Ep = 0.5*(suma[j]{Tpj - opj}^2)
                izlazna_greska_pri_odgovoru_mreze = 0;
                for(e1 = efektori.begin();e1!=efektori.end();e1++){
                    izlazna_greska_pri_odgovoru_mreze +=  pow((obucavajuci_skup_izlaza[uzorak][e1->second->getBrojEfektora()] - e1->second->getIzlaz()),2);
                    }
                izlazna_greska_pri_odgovoru_mreze *= 0.5;
            }
        void prikaziStanjeCelija(){
                for(a1 = akceptori.begin(); a1!=akceptori.end(); a1++){
                    a1->second->prikaziStanje();
                    }
                for(s1 = skrivene_celije.begin(); s1!=skrivene_celije.end(); s1++){
                    s1->second->prikaziStanje();
                    }
                for(e1 = efektori.begin(); e1!=efektori.end(); e1++){
                    e1->second->prikaziStanje();
                    }
            }
        void prikaziStanjeTezina(){
                cout<<"AKCEPTOR -> SKRIVENI SLOJ:"<<endl;
                for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){
                    t1->second->prikaziStanje();
                    }
                if(!tezine_izmedju_skrivenih_slojeva.empty()){
                    cout<<"TEZINE IZMEDJU SKRIVENIH SLOJEVA:"<<endl;
                    }
                for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!=tezine_izmedju_skrivenih_slojeva.end(); t2++){
                    t2->second->prikaziStanje();
                    }
                cout<<"SKRIVENI SLOJ -> EFEKTOR:"<<endl;
                for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++){
                    t3->second->prikaziStanje();
                    }
                cout<<"AKCEPTORI -> EFEKTOR:"<<endl;
                for(t5 = tezine_akceptora_ka_efektoru.begin(); t5!=tezine_akceptora_ka_efektoru.end(); t5++){
                    t5->second->prikaziStanje();
                    }
            }

        ~NeuronskaMreza(){
                for(a1 = akceptori.begin(); a1!=akceptori.end(); a1++)
                    delete a1->second;
                akceptori.clear();
                for(s1 = skrivene_celije.begin(); s1!=skrivene_celije.end(); s1++)
                    delete s1->second;
                skrivene_celije.clear();
                for(e1 = efektori.begin(); e1!=efektori.end(); e1++)
                    delete e1->second;
                efektori.clear();
                for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++)
                    delete t1->second;
                tezine_ka_skrivenom_sloju.clear();
                for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!=tezine_izmedju_skrivenih_slojeva.end(); t2++)
                    delete t2->second;
                tezine_izmedju_skrivenih_slojeva.clear();
                for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++)
                    delete t3->second;
                tezine_ka_efektoru.clear();
                for(t5 = tezine_akceptora_ka_efektoru.begin(); t5!=tezine_akceptora_ka_efektoru.end(); t5++)
                    delete t5->second;
                tezine_akceptora_ka_efektoru.clear();
            }
        /*
        (broj_sloja_pobudjivaca, broj_skrivenog_sloja, broj_celije_u_prethodnom_sloju, broj_celije_u_skrivenom_sloju) su argumenti za Kljuc_tezina
        izlaz skrivenih celija i efektora racuna se prema:
        NETpj = suma(i)[TEZINAji x Opi] + TETAj
        f(NETpj)
        */
        void generisiIzlazSkrivenihCelija(bool test){

            for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){
                //cout<<"Skrivena celija "<<s1->second->getKljuc()<<":"<<endl;
                double pobuda = 0.0;
                if(!s1->second->getPobudjujuceTezine().empty()){
                    Mapa_pobudjujucih_tezina mapa = s1->second->getPobudjujuceTezine();
                    Mapa_pobudjujucih_tezina::iterator it1 = mapa.begin();
                    //cout<<"Pobudjujuca tezina/ae: ";
                    for(it1; it1!=mapa.end(); it1++){
                        //cout<<it1->second<<" ";
                        if(tezine_ka_skrivenom_sloju.find(it1->second) != tezine_ka_skrivenom_sloju.end()){
                            double tezina = tezine_ka_skrivenom_sloju.find(it1->second)->second->getVrednost();
                            double izlaz_pobudjivaca = tezine_ka_skrivenom_sloju.find(it1->second)->second->getAkceptorski_ulaz().getIzlaz();
                            pobuda += tezina*izlaz_pobudjivaca;
                        }
                        if(tezine_izmedju_skrivenih_slojeva.find(it1->second) != tezine_izmedju_skrivenih_slojeva.end()){
                            double tezina = tezine_izmedju_skrivenih_slojeva.find(it1->second)->second->getVrednost();
                            double izlaz_pobudjivaca = tezine_izmedju_skrivenih_slojeva.find(it1->second)->second->getPrvaSkrivenaCelija().getIzlaz();
                            pobuda += tezina*izlaz_pobudjivaca;
                        }
                        //cout<<"pobuda-> "<<pobuda<<" ";
                    }
                }
                double bias = s1->second->getPragAktivacije();
                double vrednost_pragovske_tezine = tezine_pragova.find(s1->second->getKljuc())->second->getVrednost();
                s1->second->setPobuda(pobuda+bias*vrednost_pragovske_tezine);
                s1->second->setIzlaz(pobuda+bias*vrednost_pragovske_tezine);
            }
        }

        void generisiIzlazEfektora(bool test){

                for(e1 = efektori.begin(); e1!= efektori.end(); e1++){
                    //cout<<"Efektor "<<e1->second->getKljuc()<<":"<<endl;
                    double pobuda = 0.0;
                    if(!e1->second->getPobudjujuceTezine().empty()){
                        Mapa_pobudjujucih_tezina mapa = e1->second->getPobudjujuceTezine();
                        Mapa_pobudjujucih_tezina::iterator it1 = mapa.begin();
                        //cout<<"Pobudjujuca tezina/ae: ";
                        for(it1; it1!=mapa.end(); it1++){
                            //cout<<it1->second<<" ";
                            if(tezine_ka_efektoru.find(it1->second) != tezine_ka_efektoru.end()){
                                double tezina = tezine_ka_efektoru.find(it1->second)->second->getVrednost();
                                double izlaz_pobudjivaca = tezine_ka_efektoru.find(it1->second)->second->getSkrivenaCelija().getIzlaz();
                                pobuda += tezina*izlaz_pobudjivaca;
                            }
                            if(tezine_akceptora_ka_efektoru.find(it1->second) != tezine_akceptora_ka_efektoru.end()){
                                double tezina = tezine_akceptora_ka_efektoru.find(it1->second)->second->getVrednost();
                                double izlaz_pobudjivaca = tezine_akceptora_ka_efektoru.find(it1->second)->second->getAkceptor().getIzlaz();
                                pobuda += tezina*izlaz_pobudjivaca;
                            }
                        //cout<<"pobuda-> "<<pobuda<<" ";
                        }
                    }
                    double bias = e1->second->getPragAktivacije();
                    double vrednost_pragovske_tezine = tezine_pragova.find(konkatenacijaIntegera_u_String(e1->second->getBrojSloja(),e1->second->getBrojEfektora()))->second->getVrednost();
                    e1->second->setPobuda(pobuda+bias*vrednost_pragovske_tezine);
                    e1->second->setIzlaz(pobuda+bias*vrednost_pragovske_tezine);
                    //cout<<"Pobuda preko biasa: "<<bias*vrednost_pragovske_tezine<<endl;
                    //cout<<"Pobuda efektora: "<<pobuda<<endl;
                }
            }
            // METODA za pravljenje kljuca tezina
            string konkatenacijaIntegera_u_String(int broj_prethodnog_sloja,int broj_narednog_sloja, int broj_cel_pob, int broj_pob_cel){
                    string s;
                    stringstream out;
                    out << broj_prethodnog_sloja;
                    out << broj_narednog_sloja;
                    out << broj_cel_pob;
                    out << broj_pob_cel;
                    s = out.str();
                    return s;
                }
            // METODA za pravljenje kljuca skrivenih celija
            string konkatenacijaIntegera_u_String(int sloj,int celija){
                    string s;
                    stringstream out;
                    out << sloj;
                    out << celija;
                    s = out.str();
                    return s;
                }
          // METODA za nalazenje greske na izlazu iz celija skrivenog sloja i efektora
            void nadjiIzlaznuGreskuCelija(int uzorak,bool test){
                if(test)cout<<"****************************RACUNANJE IZLAZNE GRESKE*****************************"<<endl;
                /*IZLAZNA GRESKA EFEKTORA
                    DELTApj = (Tpj - Opj)*SUMA{IZVOD_AKTIVACIONE_FUNKCIJE(POBUDApj)}
                    IZVOD_AKTIVACIONE_FUNKCIJE = POBUDA*(1-POBUDA)
                */
                if(test)cout<<"IZLAZNA GRESKA EFEKTORA"<<endl;
                for(e1 = efektori.begin(); e1!= efektori.end(); e1++){
                    double net = e1->second->getPobuda();
                    double izlaz = e1->second->getIzlaz();
                    e1->second->setIzlaznaGreska((obucavajuci_skup_izlaza[uzorak][e1->second->getBrojEfektora()]-izlaz)*izlaz*(1-izlaz));
                        if(test)cout<<"Efektor: "<<e1->second->getBrojEfektora()<<"\n\tPobuda: "<<net<<"\n\tIzlaz: "<<izlaz<<"\n\tZeljeni izlaz: "<<obucavajuci_skup_izlaza[uzorak][e1->second->getBrojEfektora()]<<"\n\tIzlazna greska"<<e1->second->getIzlaznaGreska()<<endl;
                    }

                    ///IZLAZNA GRESKA SK = PRVI_IZVOD_AKTIVACIONE_FUNKCIJE[POBUDA] * (SUMA[GRESKE_CELIJA_NAREDNOG_NIVOA*TEZINE_KA_CELIJAMA_NAREDNOG_NIVOA])
                    //uzima se reverse iterator jer trazimo izlaznu gresku celija "od nazad" - back propagation
                    //u mapi su sortirane SK po kljucevima, od prve u nultom skrivenom sloju, pa do poslednje
                    SkriveneCelije::reverse_iterator rit;
                    for(rit = skrivene_celije.rbegin(); rit!= skrivene_celije.rend(); rit++){
                        if(!rit->second->getPobudjivackeTezine().empty()){
                        double suma_izlaznih_clanova = 0.0;
                        Mapa_pobudjivackih_tezina mapa = rit->second->getPobudjivackeTezine();
                        Mapa_pobudjivackih_tezina::iterator it1 = mapa.begin();
                        for(it1; it1!=mapa.end(); it1++){
                            //cout<<it1->second<<" ";
                            if(tezine_izmedju_skrivenih_slojeva.find(it1->second) != tezine_izmedju_skrivenih_slojeva.end()){
                                double tezina = tezine_izmedju_skrivenih_slojeva.find(it1->second)->second->getVrednost();
                                double izlazna_greska_pobudjene_celije = tezine_izmedju_skrivenih_slojeva.find(it1->second)->second->getDrugaSkrivenaCelija().getIzlaznaGreska();
                                suma_izlaznih_clanova += tezina*izlazna_greska_pobudjene_celije;
                            }
                            if(tezine_ka_efektoru.find(it1->second) != tezine_ka_efektoru.end()){
                                double tezina = tezine_ka_efektoru.find(it1->second)->second->getVrednost();
                                double izlazna_greska_pobudjene_celije = tezine_ka_efektoru.find(it1->second)->second->getEfektorski_izlaz().getIzlaznaGreska();
                                suma_izlaznih_clanova += tezina*izlazna_greska_pobudjene_celije;
                            }
                        }
                        double izlaz = rit->second->getIzlaz();
                        double prvi_izvod_aktivacione_funkcije = izlaz*(1-izlaz);
                        double izlazna_greska_SK = prvi_izvod_aktivacione_funkcije*suma_izlaznih_clanova;
                        rit->second->setIzlaznaGreska(izlazna_greska_SK);
                        }
                    }
                }
            // METODA za korekciju tezina
            void korigujTezine(bool test){
                if(test)cout<<"****************************KOREKCIJA TEZINA*****************************"<<endl;
                double eta = 2;
                double alfa = 1;
                double lambda = 5; //konstanta za sprecavanje paralize mreze. predstavlja po apsolutnoj vrednosti granicu pobude celije.
                if(test)cout<<"TEZINE KA SKRIVENOM SLOJU"<<endl;
                for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!= tezine_ka_skrivenom_sloju.end(); t1++){
                    Akceptor &akceptor = t1->second->getAkceptorski_ulaz();
                    SkrivenaCelija &celija = t1->second->getSkrivenaCelija();
                    double izlazna_greska_pobudjene_celije = celija.getIzlaznaGreska();
                    double pobuda_pobudjene_celije = celija.getPobuda();
                    pobuda_pobudjene_celije = ApsolutnaVrednost(pobuda_pobudjene_celije);
                    double izlaz_celije_pobudjivaca = akceptor.getIzlaz();
                    double stara_vrednost = t1->second->getVrednost();
                    double nova_vrednost = eta*izlazna_greska_pobudjene_celije*izlaz_celije_pobudjivaca + alfa*stara_vrednost;
                    //u slucaju paralize mreze
                    if(lambda<pobuda_pobudjene_celije){
                        double modifikovana_vrednost = lambda*((2/(1+exp(nova_vrednost/(-lambda))))-1);
                        nova_vrednost = modifikovana_vrednost;
                        }

                    t1->second->setVrednost(nova_vrednost);

                    if(test){
                        cout<<"Tezina "<<t1->second->getKljuc()<<endl;
                        cout<<"stara vrednost tezine: "<<stara_vrednost<<" Nova vrednost: "<<t1->second->getVrednost()<<endl;
                        }
                    }
                if(test)cout<<"TEZINE IZMEDJU SKRIVENIH SLOJEVA"<<endl;
                //KOREKCIJA TEZINA IZMEDJU SKRIVENIH SLOJEVA
                for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!= tezine_izmedju_skrivenih_slojeva.end(); t2++){
                    SkrivenaCelija &prva = t2->second->getPrvaSkrivenaCelija();
                    SkrivenaCelija &druga = t2->second->getDrugaSkrivenaCelija();
                    double izlazna_greska_pobudjene_celije = druga.getIzlaznaGreska();
                    double pobuda_pobudjene_celije = druga.getPobuda();
                    pobuda_pobudjene_celije = ApsolutnaVrednost(pobuda_pobudjene_celije);
                    double izlaz_celije_pobudjivaca = prva.getIzlaz();
                    double stara_vrednost = t2->second->getVrednost();
                    double nova_vrednost = eta*izlazna_greska_pobudjene_celije*izlaz_celije_pobudjivaca + alfa*stara_vrednost;
                    //u slucaju paralize mreze
                    if(lambda<pobuda_pobudjene_celije){
                        double modifikovana_vrednost = lambda*((2/(1+exp(nova_vrednost/(-lambda))))-1);
                        nova_vrednost = modifikovana_vrednost;
                        }

                    t2->second->setVrednost(nova_vrednost);

                    if(test){
                        cout<<"Tezina "<<t2->second->getKljuc()<<endl;
                        cout<<"stara vrednost tezine: "<<stara_vrednost<<" Nova vrednost: "<<t2->second->getVrednost()<<endl;
                    }
                }

                if(test)cout<<"\nTEZINE SK KA EFEKTORU"<<endl;
                //KOREKCIJA SK TEZINA KA EFEKTORU
                for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++){
                    SkrivenaCelija &skrivena_celija = t3->second->getSkrivenaCelija();
                    Efektor &efektorski_izlaz = t3->second->getEfektorski_izlaz();
                    double izlazna_greska_pobudjene_celije = efektorski_izlaz.getIzlaznaGreska();
                    double pobuda_pobudjene_celije = efektorski_izlaz.getPobuda();
                    pobuda_pobudjene_celije = ApsolutnaVrednost(pobuda_pobudjene_celije);
                    double izlaz_celije_pobudjivaca = skrivena_celija.getIzlaz();
                    double stara_vrednost = t3->second->getVrednost();
                    double nova_vrednost = eta*izlazna_greska_pobudjene_celije*izlaz_celije_pobudjivaca + alfa*stara_vrednost;
                    //u slucaju paralize mreze
                    //if(lambda<pobuda_pobudjene_celije){
                    //    double modifikovana_vrednost = lambda*((2/(1+exp(nova_vrednost/(-lambda))))-1);
                    //    nova_vrednost = modifikovana_vrednost;
                    //    }

                    t3->second->setVrednost(nova_vrednost);

                    if(test){
                        cout<<"Tezina "<<t3->second->getKljuc()<<endl;
                        cout<<"stara vrednost tezine: "<<stara_vrednost<<" Nova vrednost: "<<t3->second->getVrednost()<<endl;
                    }
                }

                if(test)cout<<"\nTEZINE AKCEPTORA KA EFEKTORU"<<endl;
                //KOREKCIJA A TEZINA KA EFEKTORU
                for(t5 = tezine_akceptora_ka_efektoru.begin(); t5!=tezine_akceptora_ka_efektoru.end(); t5++){
                    Akceptor &akceptor = t5->second->getAkceptor();
                    Efektor &efektorski_izlaz = t5->second->getEfektorski_izlaz();
                    double izlazna_greska_pobudjene_celije = efektorski_izlaz.getIzlaznaGreska();
                    double pobuda_pobudjene_celije = efektorski_izlaz.getPobuda();
                    pobuda_pobudjene_celije = ApsolutnaVrednost(pobuda_pobudjene_celije);
                    double izlaz_celije_pobudjivaca = akceptor.getIzlaz();
                    double stara_vrednost = t5->second->getVrednost();
                    double nova_vrednost = eta*izlazna_greska_pobudjene_celije*izlaz_celije_pobudjivaca + alfa*stara_vrednost;
                    //u slucaju paralize mreze, zakomentarisano zbog velike duzine obuke
                    //if(lambda<pobuda_pobudjene_celije){
                    //    double modifikovana_vrednost = lambda*((2/(1+exp(nova_vrednost/(-lambda))))-1);
                    //    nova_vrednost = modifikovana_vrednost;
                    //    }

                    t5->second->setVrednost(nova_vrednost);

                    if(test){
                        cout<<"Tezina "<<t5->second->getKljuc()<<endl;
                        cout<<"stara vrednost tezine: "<<stara_vrednost<<" Nova vrednost: "<<t5->second->getVrednost()<<endl;
                    }
                }

                if(test)cout<<"\nPRAGOVSKE TEZINE"<<endl;
                //KOREKCIJA PRAGOVSKIH TEZINA
                {
                    for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){
                        double bias = s1->second->getPragAktivacije();
                        double izlazna_greska_pobudjene_celije = s1->second->getIzlaznaGreska();
                        double prethodna_vrednost = tezine_pragova.find(s1->second->getKljuc())->second->getVrednost();
                        double naredna_vrednost = eta*izlazna_greska_pobudjene_celije*bias + alfa*prethodna_vrednost;
                        //u slucaju paralize mreze
                        if(lambda<s1->second->getPobuda()){
                            double modifikovana_vrednost = lambda*((2/(1+exp(naredna_vrednost/(-lambda))))-1);
                            naredna_vrednost = modifikovana_vrednost;
                        }
                        tezine_pragova.find(s1->second->getKljuc())->second->setVrednost(naredna_vrednost);
                        s1->second->setTezinaPraga(naredna_vrednost);
                        if(test)cout<<"Pragovska tezina SK "<<s1->second->getKljuc()<<", stara vrednost:"<<prethodna_vrednost<<" Nova vrednost: "<<naredna_vrednost<<endl;
                    }
                    for(e1 = efektori.begin(); e1 != efektori.end(); e1++){
                        double bias = e1->second->getPragAktivacije();
                        double izlazna_greska_pobudjene_celije = e1->second->getIzlaznaGreska();
                        double prethodna_vrednost = tezine_pragova.find(e1->second->getKljuc())->second->getVrednost();
                        double naredna_vrednost = eta*izlazna_greska_pobudjene_celije*bias + alfa*prethodna_vrednost;
                        //u slucaju paralize mreze
                        if(lambda<e1->second->getPobuda()){
                            double modifikovana_vrednost = lambda*((2/(1+exp(naredna_vrednost/(-lambda))))-1);
                            naredna_vrednost = modifikovana_vrednost;
                        }
                        tezine_pragova.find(e1->second->getKljuc())->second->setVrednost(naredna_vrednost);
                        e1->second->setTezinaPraga(naredna_vrednost);
                        if(test)cout<<"Pragovska tezina EF "<<e1->second->getKljuc()<<", stara vrednost:"<<prethodna_vrednost<<" Nova vrednost: "<<naredna_vrednost<<endl;
                    }
                }
            }

        ///BACK PROPAGATION LOG
        //postaviUlaze(i,test);
        //generisiIzlazSkrivenihCelija(test);
        //generisiIzlazEfektora(test);
        //nadjiIzlaznuGreskuCelija(i,test);
        //setIzlaznaGreskaPriOdgovoruMreze(i);
        //korigujTezine(test);
        void BackPropagationLog(){
            string back_propagation_log = "";
            postaviUlaze(0,false);
            generisiIzlazSkrivenihCelija(false);
            generisiIzlazEfektora(false);
            nadjiIzlaznuGreskuCelija(0,false);

            for(a1 = akceptori.begin(); a1 != akceptori.end(); a1++){
                back_propagation_log.append(a1->second->AkceptorToString());
            }
            for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){
                back_propagation_log.append(s1->second->SK_ToString());
            }
            for(e1 = efektori.begin(); e1 != efektori.end(); e1++){
                back_propagation_log.append(e1->second->EfektorToString());
            }
            for(t1 = tezine_ka_skrivenom_sloju.begin(); t1 != tezine_ka_skrivenom_sloju.end(); t1++){
                back_propagation_log.append(t1->second->Tezina_ka_SK_ToString());
            }
            for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2 != tezine_izmedju_skrivenih_slojeva.end(); t2++){
                back_propagation_log.append(t2->second->Tezina_izmedju_SK_ToString());
            }
            for(t3 = tezine_ka_efektoru.begin(); t3 != tezine_ka_efektoru.end(); t3++){
                back_propagation_log.append(t3->second->Tezina_ka_Efektoru_ToString());
            }
            for(t5 = tezine_akceptora_ka_efektoru.begin(); t5 != tezine_akceptora_ka_efektoru.end(); t5++){
                back_propagation_log.append(t5->second->Tezina_Akceptora_ka_Efektoru_ToString());
            }
            for(t4 = tezine_pragova.begin(); t4 != tezine_pragova.end(); t4++){
                back_propagation_log.append(t4->second->TezinaPragovaToString());
            }

        ofstream filestr;
        filestr.open("Back propagation log");
        if (filestr.is_open()){
            filestr << back_propagation_log;
            }
        filestr.close();
        }

        /**
        METODA PREDSTAVLJA JEDAN CIKLUS OBUKE MREZE
        */
        float step(){
            float greska = 0;
            for(int i = 0; i<broj_uzoraka; i++){
                bool test = false;
                postaviUlaze(i,test);
                //cout<<"postaviUlaze(i,test);"<<endl;
                generisiIzlazSkrivenihCelija(test);
                //cout<<"generisiIzlazSkrivenihCelija(test);"<<endl;
                generisiIzlazEfektora(test);
                //cout<<"generisiIzlazEfektora(test);"<<endl;
                nadjiIzlaznuGreskuCelija(i,test);
                //cout<<"nadjiIzlaznuGreskuCelija(i,test);"<<endl;
                setIzlaznaGreskaPriOdgovoruMreze(i);
                //cout<<"setIzlaznaGreskaPriOdgovoruMreze(i);"<<endl;
                korigujTezine(test);
                //cout<<"korigujTezine(test);"<<endl;
                procesDeobeCelija();
                //cout<<"procesDeobeCelija();"<<endl;
                procesDegeneracijeSinapsi();
                //cout<<"procesDegeneracijeSinapsi();"<<endl;

                //cout<<"procesDegeneracijeCelija();"<<endl;
                greska += getIzlaznaGreskaPriOdgovoruMreze(i);
                }
            procesDegeneracijeCelija();
            broj_iteracija++;
            broj_ciklusa_proteklih_od_zadnje_deobe++;
            broj_ciklusa_proteklih_od_poslednje_degeneracije_sinapse_u_mrezi++;
            return greska;
            }

        float getIzlaznaGreskaPriOdgovoruMreze(int uzorak){return izlazna_greska_pri_odgovoru_mreze;}
        int getBrojIteracija(){return broj_iteracija;}
        float getDozvoljenaGreska(){return dozvoljena_greska;}

        void test(){
            for(int i = 0; i<broj_uzoraka; i++){
                postaviUlaze(i,false);
                generisiIzlazSkrivenihCelija(false);
                generisiIzlazEfektora(false);
                cout<<obucavajuci_skup_ulaza[i][0]<<" FUNC "<<obucavajuci_skup_ulaza[i][1]<<": ";
                //cout<<efektori.find(0)->second->getIzlaz()<<endl;
                cout<<efektori.find(0)->second->getIzlaz()<<"  "<<efektori.find(1)->second->getIzlaz()<<"  "<<efektori.find(2)->second->getIzlaz()<<endl;
                //cout<<efektori.find(0)->second->getIzlaz()<<"  "<<efektori.find(1)->second->getIzlaz()<<endl;
            }
        }
        //Napomena: normalizovana izlazna greska celija racuna se posle nalazenja izlazne greske celija
        void nadjiNormalizovanuGreskuSkrivenihCelija(bool test){
            if(test)cout<<"****************************RACUNANJE NORMALIZOVANE IZLAZNE GRESKE*****************************"<<endl;
                /*NORMALIZOVANA IZLAZNA GRESKA SK
                    DELTApj = (1/SUMAj{OMEGAji})*IZLAZNA GRESKA
                */
                SkriveneCelije::reverse_iterator rit,rit2;
                for(rit = skrivene_celije.rbegin(); rit!= skrivene_celije.rend(); rit++){
                    double izlazna_greska_celije = rit->second->getIzlaznaGreska();
                    double smanjenje_uticaja_sinapsi_na_deobu_celija = 0;
                    int broj_sloja_pobudjivaca = rit->second->getBroj_skrivenog_sloja();
                    broj_sloja_pobudjivaca++; //zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
                    int broj_celije_pobudjivaca = rit->second->getBroj_celije_u_skrivenom_sloju();
                    // IZLAZNA GRESKA KA EFEKTORIMA
                    for(e1 = efektori.begin(); e1!=efektori.end(); e1++){
                        int broj_pobudjivanog_sloja = e1->second->getBrojSloja();
                        int broj_pobudjivane_celije = e1->second->getBrojEfektora();
                        if(tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_pobudjivanog_sloja,broj_celije_pobudjivaca,broj_pobudjivane_celije))!=tezine_ka_efektoru.end()){
                            double tezina = tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_pobudjivanog_sloja,broj_celije_pobudjivaca,broj_pobudjivane_celije))->second->getVrednost();
                            if(tezina<0)tezina*=-1; //abs(TEZINAji)
                            smanjenje_uticaja_sinapsi_na_deobu_celija += tezina;
                            if(test){
                                cout<<"pobudjivani efektor: "<<broj_pobudjivanog_sloja<<broj_pobudjivane_celije<<":"<<endl;
                                cout<<"parametar smanjenja uticaja sinapsi na deobu celija: "<<smanjenje_uticaja_sinapsi_na_deobu_celija<<endl;
                                }
                            }
                        }
                    // IZLAZNA GRESKA KA NAREDNIM SKRIVENIM SLOJEVIMA
                    if(test)cout<<"IZLAZNA GRESKA KA SKRIVENIM CELIJAMA"<<endl;
                    for(rit2 = skrivene_celije.rbegin(); rit2!= skrivene_celije.rend(); rit2++){
                        if(rit!=rit2){
                            int broj_pobudjivanog_sloja = rit2->second->getBroj_skrivenog_sloja();
                            broj_pobudjivanog_sloja++; //zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
                            int broj_pobudjivane_celije = rit2->second->getBroj_celije_u_skrivenom_sloju();
                            if(tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_pobudjivanog_sloja,broj_celije_pobudjivaca,broj_pobudjivane_celije))!=tezine_izmedju_skrivenih_slojeva.end()){
                                double tezina = tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_pobudjivanog_sloja,broj_celije_pobudjivaca,broj_pobudjivane_celije))->second->getVrednost();
                                if(tezina<0)tezina*=-1; //abs(TEZINAji)
                                smanjenje_uticaja_sinapsi_na_deobu_celija += tezina;
                                if(test){
                                    cout<<"pobudjivana celija: "<<broj_pobudjivanog_sloja<<broj_pobudjivane_celije<<":"<<endl;
                                    cout<<"parametar smanjenja uticaja sinapsi na deobu celija: "<<smanjenje_uticaja_sinapsi_na_deobu_celija<<endl;
                                    }
                                }
                            }else break; //nemoguca dalja pobuda
                        }
                    double normalizovana_izlazna_greska_celije = (1/smanjenje_uticaja_sinapsi_na_deobu_celija)*izlazna_greska_celije;
                    rit->second->setNormalizovanaIzlaznaGreska(normalizovana_izlazna_greska_celije);
                    if(test){
                        cout<<"Skrivena celija: "<<rit->second->getBroj_skrivenog_sloja()<<rit->second->getBroj_celije_u_skrivenom_sloju()<<endl;
                        cout<<"Ukupna izlazna greska ka narednom nivou: "<<rit->second->getIzlaznaGreska()<<endl;
                        cout<<"Normalizovana izlazna greska celije: "<<rit->second->getNormalizovanaIzlaznaGreska()<<endl;
                        }
                    }
            }
            void setVremenski_faktor_deobe(){
                vremenski_faktor_deobe = tanh(broj_ciklusa_proteklih_od_zadnje_deobe/faktor_oporavka);
            }
            double getVremenski_faktor_deobe(){
                return vremenski_faktor_deobe;
            }
            /** ispitivanje mogucnosti deobe celije, strogo se poziva TEK NAKON nalazenja izlaznih gresaka celija
                celija ce se podeliti ako je normalizovana vrednost razlike kumulativnih gresaka manja od verovatnoce deobe same celije:

                VEROVATNOCA_DEOBE > ABS[POZ_KUM_GRESKA - NEG_KUM_GRESKA]/(POZ_KUM_GRESKA + NEG_KUM_GRESKA),
                a istovremeno zadovoljava neke uslove:

                a) vrednost izlazne greske celije mora biti razlicita od nule
                b) u tekucem ciklusu obuke mreze nije vec doslo do deobe bilo koje celije mreze
                c) tezinski_faktor_deobe | 0<tezinski_faktor_deobe<1
            */
            bool deobaCelije(double tezinski_faktor_deobe, double vremenski_faktor_deobe, SkrivenaCelija *celija){
                bool deoba = false;

                celija->setPozitivna_kumulativna_greska();
                celija->setNegativna_kumulativna_greska();
                celija->setSrednja_kumulativna_vrednost_promene_greske_izlaza_celije();
                celija->setVerovatnoca_deobe(tezinski_faktor_deobe,vremenski_faktor_deobe);

                double poz_kum_greska = s1->second->getPozitivna_kumulativna_greska();
                double neg_kum_greska = s1->second->getNegativna_kumulativna_greska();
                double razlika = abs(poz_kum_greska - neg_kum_greska);
                double zbir = poz_kum_greska + neg_kum_greska;
                double verovatnoca_deobe = s1->second->getVerovatnoca_deobe();
                double normalizovana_vrednost_razlike_kumulativnih_gresaka = razlika/zbir;
                if(verovatnoca_deobe > normalizovana_vrednost_razlike_kumulativnih_gresaka){
                    if(celija->getIzlaznaGreska()!=0){
                        if(tezinski_faktor_deobe>0){
                           deoba = true;
                        }
                    }
                }
                return deoba;
                }
           void procesDeobeCelija(){
               nadjiNormalizovanuGreskuSkrivenihCelija(false); //normalizovana izlazna greska
               setVremenski_faktor_deobe();
               for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){
                    if(deobaCelije(tezinski_faktor_deobe,getVremenski_faktor_deobe(),s1->second)){
                        broj_ciklusa_proteklih_od_zadnje_deobe = 0;
                        dodajNovuSkrivenuCeliju(s1->second);
                        }
                   }
               }

           /**
                DODAVANJE NOVE SKRIVENE CELIJE

                zapravo, bitno je samo voditi racuna o sloju u koji dodajemo celiju broj slojeva ne prelazi 9, bar za sada ne.
                treba naci broj skrivenog sloja, te staviti celiju kao poslednju u sloj. nema potrebe, ako broj celija nije veoma velik
                (reda velicine 1000-e), voditi racuna o "nagomilavanju kljuceva" celija.

                NAPOMENA: VODI SE RACUNA O PODESAVANJU NOVIH TEZINA!
           */
           void dodajNovuSkrivenuCeliju(SkrivenaCelija *celija_roditelj){
               //generisanje kljuca celije potomka
               int skriveni_sloj = celija_roditelj->getBroj_skrivenog_sloja();
               int broj_roditelja = celija_roditelj->getBroj_celije_u_skrivenom_sloju();
               int brojac_celija = 0;
               for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){
                   if(s1->second->getBroj_skrivenog_sloja()==skriveni_sloj)brojac_celija++;
                   }
               string kljuc_potomka = konkatenacijaIntegera_u_String(skriveni_sloj,brojac_celija);
                   while(skrivene_celije.find(kljuc_potomka)!=skrivene_celije.end()){
                        brojac_celija++;
                        kljuc_potomka = konkatenacijaIntegera_u_String(skriveni_sloj,brojac_celija);
                   }
               SkrivenaCelija *potomak = new SkrivenaCelija(skriveni_sloj,brojac_celija,1);
               skrivene_celije.insert(make_pair(potomak->getKljuc(),potomak));
               // broj celija u sloju se takodje mora podesiti
               broj_slojeva[skriveni_sloj+1]++;
               //podesavanje pragovske tezine
               Tezina_pragova *tezina_praga = new Tezina_pragova(potomak->getKljuc(),tezine_pragova.find(celija_roditelj->getKljuc())->second->getVrednost());
               tezine_pragova.insert(make_pair(tezina_praga->getKljuc(),tezina_praga));
               //podesavanje tezina od prethodnog sloja
               if(skriveni_sloj==0){
                   //prvi skriveni sloj
                   for(int i = 0; i<broj_ulaza; i++){
                        Akceptor *akceptor = akceptori.find(i)->second;
                        if(tezine_ka_skrivenom_sloju.find(konkatenacijaIntegera_u_String(0,skriveni_sloj+1,i,broj_roditelja))!=tezine_ka_skrivenom_sloju.end()){
                            Tezina_ka_skrivenom_sloju *akceptorska_tezina = new Tezina_ka_skrivenom_sloju(akceptor,potomak,tezine_ka_skrivenom_sloju.find(konkatenacijaIntegera_u_String(0,skriveni_sloj+1,i,broj_roditelja))->second->getVrednost());
                            tezine_ka_skrivenom_sloju.insert(make_pair(akceptorska_tezina->getKljuc(),akceptorska_tezina));
                            //postavljanje pobudjujucih tezina kod skrivenih celija
                            potomak->addPobudjujucuTezinu(akceptorska_tezina->getKljuc());
                        }else{
                            Tezina_ka_skrivenom_sloju *akceptorska_tezina = new Tezina_ka_skrivenom_sloju(akceptor,potomak,0);
                            tezine_ka_skrivenom_sloju.insert(make_pair(akceptorska_tezina->getKljuc(),akceptorska_tezina));
                            //postavljanje pobudjujucih tezina kod skrivenih celija
                            potomak->addPobudjujucuTezinu(akceptorska_tezina->getKljuc());
                        }
                    }
                }else{
                    //bilo koji drugi skriveni sloj
                    for(int k = 0; k<broj_skrivenih_celija; k++){
                        if(skrivene_celije.find(konkatenacijaIntegera_u_String(skriveni_sloj-1,k))!=skrivene_celije.end()){
                            SkrivenaCelija *prethodna = skrivene_celije.find(konkatenacijaIntegera_u_String(skriveni_sloj-1,k))->second;
                            if(tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(skriveni_sloj,skriveni_sloj+1,k,broj_roditelja))!=tezine_izmedju_skrivenih_slojeva.end()){
                                Tezina_izmedju_skrivenih_slojeva *tezina = new Tezina_izmedju_skrivenih_slojeva(prethodna,potomak,tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(skriveni_sloj,skriveni_sloj+1,k,broj_roditelja))->second->getVrednost());
                                tezine_izmedju_skrivenih_slojeva.insert(make_pair(tezina->getKljuc(),tezina));
                                //postavljanje pobudjujucih tezina kod skrivenih celija
                                potomak->addPobudjujucuTezinu(tezina->getKljuc());
                            }else{
                                Tezina_izmedju_skrivenih_slojeva *tezina = new Tezina_izmedju_skrivenih_slojeva(prethodna,potomak,0);
                                tezine_izmedju_skrivenih_slojeva.insert(make_pair(tezina->getKljuc(),tezina));
                                //postavljanje pobudjujucih tezina kod skrivenih celija
                                potomak->addPobudjujucuTezinu(tezina->getKljuc());
                                }
                        }
                    }
                }
                //podesavanje tezina ka narednom sloju
                if((skriveni_sloj+1)==dubina){
                    //poslednji skriveni sloj
                    for(int k = 0; k<broj_izlaza; k++){
                        Efektor *efektor = efektori.find(k)->second;
                        if(tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,skriveni_sloj+2,broj_roditelja,k))!=tezine_ka_efektoru.end()){
                            double roditeljski_akson = tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,skriveni_sloj+2,broj_roditelja,k))->second->getVrednost();
                            double akson_potomka = -faktor_mutacije*roditeljski_akson;
                            roditeljski_akson *= (1 + faktor_mutacije);
                            tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,skriveni_sloj+2,broj_roditelja,k))->second->setVrednost(roditeljski_akson);
                            Tezina_ka_efektoru *efektorska_tezina = new Tezina_ka_efektoru(potomak,efektor,akson_potomka);
                            tezine_ka_efektoru.insert(make_pair(efektorska_tezina->getKljuc(),efektorska_tezina));
                            //postavljanje pobudjivackih tezina kod skrivenih celija
                            potomak->addPobudjivackuTezinu(efektorska_tezina->getKljuc());
                            //postavljanje pobudjujucih tezina kod efektora
                            efektor->addPobudjujucuTezinu(efektorska_tezina->getKljuc());
                        }else{
                            Tezina_ka_efektoru *efektorska_tezina = new Tezina_ka_efektoru(potomak,efektor,0);
                            tezine_ka_efektoru.insert(make_pair(efektorska_tezina->getKljuc(),efektorska_tezina));
                            //postavljanje pobudjivackih tezina kod skrivenih celija
                            potomak->addPobudjivackuTezinu(efektorska_tezina->getKljuc());
                            //postavljanje pobudjujucih tezina kod efektora
                            efektor->addPobudjujucuTezinu(efektorska_tezina->getKljuc());
                            }
                    }
                }else{
                    for(int k = 0; k<broj_ulaza; k++){
                        if(skrivene_celije.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,k))!=skrivene_celije.end()){
                            SkrivenaCelija *naredna = skrivene_celije.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,k))->second;
                            if(tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,skriveni_sloj+2,broj_roditelja,k))!=tezine_izmedju_skrivenih_slojeva.end()){
                                double roditeljski_akson = tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,skriveni_sloj+2,broj_roditelja,k))->second->getVrednost();
                                double akson_potomka = -faktor_mutacije*roditeljski_akson;
                                roditeljski_akson *= (1 + faktor_mutacije);
                                tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(skriveni_sloj+1,skriveni_sloj+2,broj_roditelja,k))->second->setVrednost(roditeljski_akson);

                                Tezina_izmedju_skrivenih_slojeva *tezina = new Tezina_izmedju_skrivenih_slojeva(potomak,naredna,akson_potomka);
                                tezine_izmedju_skrivenih_slojeva.insert(make_pair(tezina->getKljuc(),tezina));
                                //postavljanje pobudjivackih tezina kod skrivenih celija
                                potomak->addPobudjivackuTezinu(tezina->getKljuc());
                            }else{
                                Tezina_izmedju_skrivenih_slojeva *tezina = new Tezina_izmedju_skrivenih_slojeva(potomak,naredna,0);
                                tezine_izmedju_skrivenih_slojeva.insert(make_pair(tezina->getKljuc(),tezina));
                                //postavljanje pobudjivackih tezina kod skrivenih celija
                                potomak->addPobudjivackuTezinu(tezina->getKljuc());
                                }
                        }
                    }
                }
                broj_deoba++;

           }
        int getBrojDeoba(){return broj_deoba;}

        /**
            DEGENERACIJA SINAPSI
                AKCEPTOR->SKRIVENI SLOJ
                SKRIVENI SLOJ -> SKRIVENI SLOJ
                SKRIVENI SLOJ -> EFEKTORI
            informativna energija celije je zbir promena izlaza celija pobudjivaca mnozenih tezinama sinapsi preko kojih pobudjuju datu celiju

            Napomena: ne radi za premostavanje slojeva
        */
        void setInformativnaEnergijaCelija(){
            /**
            AKCEPTOR->SKRIVENI SLOJ
            */
            for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){

                if(s1->second->getBroj_skrivenog_sloja() == 1)break;
                double informativna_energija_celije = 0.0;

                for(a1 = akceptori.begin(); a1 != akceptori.end(); a1++){
                    // postoji tezina preko koje se pobudjuje skrivena celija iz akceptorskog sloja
                    if(tezine_ka_skrivenom_sloju.find(konkatenacijaIntegera_u_String(0,1,a1->second->getBrojAkceptora(),s1->second->getBroj_celije_u_skrivenom_sloju()))!=tezine_ka_skrivenom_sloju.end()){
                        double prethodni_izlaz = a1->second->getPrethodniIzlaz();
                        double naredni_izlaz = a1->second->getIzlaz();
                        double razlika_izlaza_celije_pobudjivaca = naredni_izlaz - prethodni_izlaz;
                        double vrednost_tezine = tezine_ka_skrivenom_sloju.find(konkatenacijaIntegera_u_String(0,1,a1->second->getBrojAkceptora(),s1->second->getBroj_celije_u_skrivenom_sloju()))->second->getVrednost();
                        informativna_energija_celije += ApsolutnaVrednost(vrednost_tezine*razlika_izlaza_celije_pobudjivaca);
                    }
                }
            /**
            SKRIVENI SLOJ -> SKRIVENI SLOJ
            */

                int broj_pobudjivanog_sloja = s1->second->getBroj_skrivenog_sloja();
                broj_pobudjivanog_sloja++; //zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
                int broj_pobudjivane_celije = s1->second->getBroj_celije_u_skrivenom_sloju();

                for(s2 = skrivene_celije.begin(); s2 != skrivene_celije.end(); s2++){
                    if(s1==s2)break;

                    int broj_sloja_pobudjivaca = s2->second->getBroj_skrivenog_sloja();
                    broj_sloja_pobudjivaca++; //zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
                    int broj_celije_pobudjivaca = s2->second->getBroj_celije_u_skrivenom_sloju();

                    if(tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_pobudjivanog_sloja,broj_celije_pobudjivaca,broj_pobudjivane_celije))!=tezine_izmedju_skrivenih_slojeva.end()){
                        double prethodni_izlaz = s2->second->getPrethodniIzlaz();
                        double naredni_izlaz = s2->second->getNaredniIzlaz();
                        double razlika_izlaza_celije_pobudjivaca = naredni_izlaz - prethodni_izlaz;
                        double vrednost_tezine = tezine_izmedju_skrivenih_slojeva.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_pobudjivanog_sloja,broj_celije_pobudjivaca,broj_pobudjivane_celije))->second->getVrednost();
                        informativna_energija_celije += ApsolutnaVrednost(vrednost_tezine*razlika_izlaza_celije_pobudjivaca);
                    }
                }
                s1->second->setInformativnaEnergija(informativna_energija_celije);
            }
            /**
                SKRIVENI SLOJ -> EFEKTORI
                Napomena: radi za sve skrivene slojeve, ali ne za akceptore
            */

            for(e1 = efektori.begin(); e1!=efektori.end(); e1++){

                int broj_sloja_efektora = e1->second->getBrojSloja();
                int broj_efektora = e1->second->getBrojEfektora();
                double informativna_energija_celije = 0.0;

                for(s1 = skrivene_celije.begin(); s1!=skrivene_celije.end(); s1++){

                    int broj_sloja_pobudjivaca = s1->second->getBroj_skrivenog_sloja();
                    broj_sloja_pobudjivaca++; //zbog toga sto numerisanje skrivenog sloja krece od 0 a za trazenje tezina je potrebno da bude 1
                    int broj_celije_pobudjivaca = s1->second->getBroj_celije_u_skrivenom_sloju();

                    if(tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_sloja_efektora,broj_celije_pobudjivaca,broj_efektora))!=tezine_ka_efektoru.end()){
                        double prethodni_izlaz = s1->second->getPrethodniIzlaz();
                        double naredni_izlaz = s1->second->getNaredniIzlaz();
                        double razlika_izlaza_celije_pobudjivaca = naredni_izlaz - prethodni_izlaz;
                        double vrednost_tezine = tezine_ka_efektoru.find(konkatenacijaIntegera_u_String(broj_sloja_pobudjivaca,broj_sloja_efektora,broj_celije_pobudjivaca,broj_efektora))->second->getVrednost();
                        informativna_energija_celije += ApsolutnaVrednost(vrednost_tezine*razlika_izlaza_celije_pobudjivaca);
                    }
                }
                e1->second->setInformativnaEnergija(informativna_energija_celije);
            }

        }
        /**
            PODESAVANJE FAKTORA AKTIVNOSTI SINAPSI
            -tezine_ka_skrivenom_sloju
            -tezine_izmedju_skrivenih_slojeva
            -tezine_ka_efektoru
        */
        void faktorAktivnostiSinapsi(){
            /**
            tezine_ka_skrivenom_sloju
            */
            for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){
                double prethodna_vrednost_faktora_aktivnosti_tezine = t1->second->getPrethodniFaktorAktivnosti();
                double informativna_energija_pobudjene_celije = (t1->second->getSkrivenaCelija()).getInformativnaEnergija();

                double prethodna_vrednost_akceptorskog_izlaza = (t1->second->getAkceptorski_ulaz()).getPrethodniIzlaz();
                double naredna_vrednost_akceptorskog_izlaza = (t1->second->getAkceptorski_ulaz()).getIzlaz();
                double razlika_izlaza_akceptorskog_pobudjivaca = naredna_vrednost_akceptorskog_izlaza - prethodna_vrednost_akceptorskog_izlaza;
                int broj_celija_u_sloju_pobudjivaca;

                double faktor_aktivnosti_tezine;
                if(informativna_energija_pobudjene_celije>0){
                    broj_celija_u_sloju_pobudjivaca = broj_slojeva[0];
                    faktor_aktivnosti_tezine = ( broj_celija_u_sloju_pobudjivaca * ApsolutnaVrednost(t1->second->getVrednost() * razlika_izlaza_akceptorskog_pobudjivaca) )/informativna_energija_pobudjene_celije + (faktor_secanja_degeneracije_sinapse * t1->second->getFaktorAktivnosti());
                }else{ //informativna energija celije je pozitivna vrednost ili nula
                    faktor_aktivnosti_tezine = faktor_secanja_degeneracije_sinapse * t1->second->getFaktorAktivnosti();
                }
                t1->second->setFaktorAktivnostiSinapse(faktor_aktivnosti_tezine,broj_celija_u_sloju_pobudjivaca,t1->second->getVrednost(),razlika_izlaza_akceptorskog_pobudjivaca,informativna_energija_pobudjene_celije,t1->second->getFaktorAktivnosti());
            }
            /**
            tezine_izmedju_skrivenih_slojeva
            */
            for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!=tezine_izmedju_skrivenih_slojeva.end(); t2++){
                double prethodna_vrednost_faktora_aktivnosti_tezine = t2->second->getPrethodniFaktorAktivnosti();
                double informativna_energija_pobudjene_celije = (t2->second->getDrugaSkrivenaCelija()).getInformativnaEnergija();

                double prethodna_vrednost_izlaza = (t2->second->getPrvaSkrivenaCelija()).getPrethodniIzlaz();
                double naredna_vrednost_izlaza = (t2->second->getPrvaSkrivenaCelija()).getNaredniIzlaz();
                double razlika_izlaza_celije_pobudjivaca = naredna_vrednost_izlaza - prethodna_vrednost_izlaza;

                double faktor_aktivnosti_tezine;
                if(informativna_energija_pobudjene_celije>0){
                    int broj_celija_u_sloju_pobudjivaca = broj_slojeva[(t2->second->getPrvaSkrivenaCelija()).getBroj_skrivenog_sloja()+1];
                    faktor_aktivnosti_tezine = ( broj_celija_u_sloju_pobudjivaca * ApsolutnaVrednost(t2->second->getVrednost() * razlika_izlaza_celije_pobudjivaca) )/informativna_energija_pobudjene_celije +
                                                    faktor_secanja_degeneracije_sinapse * t2->second->getFaktorAktivnosti();
                }else{ //informativna energija celije je pozitivna vrednost ili nula
                    faktor_aktivnosti_tezine = faktor_secanja_degeneracije_sinapse * t2->second->getFaktorAktivnosti();
                }
                t2->second->setFaktorAktivnostiSinapse(faktor_aktivnosti_tezine);
            }
            /**
            tezine_ka_efektoru
            */
            for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++){
                double prethodna_vrednost_faktora_aktivnosti_tezine = t3->second->getPrethodniFaktorAktivnosti();
                double informativna_energija_pobudjene_celije = (t3->second->getEfektorski_izlaz()).getInformativnaEnergija();

                double prethodna_vrednost_izlaza = (t3->second->getSkrivenaCelija()).getPrethodniIzlaz();
                double naredna_vrednost_izlaza = (t3->second->getSkrivenaCelija()).getNaredniIzlaz();
                double razlika_izlaza_celije_pobudjivaca = naredna_vrednost_izlaza - prethodna_vrednost_izlaza;

                double faktor_aktivnosti_tezine;
                if(informativna_energija_pobudjene_celije>0){
                    int broj_celija_u_sloju_pobudjivaca = broj_slojeva[(t3->second->getSkrivenaCelija()).getBroj_skrivenog_sloja()+1];
                    faktor_aktivnosti_tezine = ( broj_celija_u_sloju_pobudjivaca * ApsolutnaVrednost(t3->second->getVrednost() * razlika_izlaza_celije_pobudjivaca) )/informativna_energija_pobudjene_celije +
                                                    faktor_secanja_degeneracije_sinapse * t3->second->getFaktorAktivnosti();
                }else{ //informativna energija celije je pozitivna vrednost ili nula
                    faktor_aktivnosti_tezine = faktor_secanja_degeneracije_sinapse * t3->second->getFaktorAktivnosti();
                }
                t3->second->setFaktorAktivnostiSinapse(faktor_aktivnosti_tezine);
            }
        }

        /**
            PODESAVANJE NORMALIZOVANOG FAKTORA AKTIVNOSTI SINAPSI
            -tezine_ka_skrivenom_sloju
            -tezine_izmedju_skrivenih_slojeva
            -tezine_ka_efektoru
        */
        void normalizovaniFaktorAktivnostiSinapsi(){
            /**
            tezine_ka_skrivenom_sloju
            */
            for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){

                double faktor_aktivnosti_tezine = t1->second->getFaktorAktivnosti();
                int broj_celija_u_sloju_pobudjivaca = broj_slojeva[0];
                double normalizovani_faktor_aktivnosti_tezine = ((1 - faktor_secanja_degeneracije_sinapse)/broj_celija_u_sloju_pobudjivaca) * faktor_aktivnosti_tezine;

                t1->second->setNormalizovaniFaktorAktivnostiSinapse(normalizovani_faktor_aktivnosti_tezine);
            }
             /**
            tezine_izmedju_skrivenih_slojeva
            */
            for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!=tezine_izmedju_skrivenih_slojeva.end(); t2++){
                double faktor_aktivnosti_tezine = t2->second->getFaktorAktivnosti();
                int broj_celija_u_sloju_pobudjivaca = broj_slojeva[(t2->second->getPrvaSkrivenaCelija()).getBroj_skrivenog_sloja()+1];
                double normalizovani_faktor_aktivnosti_tezine = ((1 - faktor_secanja_degeneracije_sinapse)/broj_celija_u_sloju_pobudjivaca) * faktor_aktivnosti_tezine;

                t2->second->setNormalizovaniFaktorAktivnostiSinapse(normalizovani_faktor_aktivnosti_tezine);
            }
            /**
            tezine_ka_efektoru
            */
            for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++){
                double faktor_aktivnosti_tezine = t3->second->getFaktorAktivnosti();
                int broj_celija_u_sloju_pobudjivaca = broj_slojeva[(t3->second->getSkrivenaCelija()).getBroj_skrivenog_sloja()+1];
                double normalizovani_faktor_aktivnosti_tezine = ((1 - faktor_secanja_degeneracije_sinapse)/broj_celija_u_sloju_pobudjivaca) * faktor_aktivnosti_tezine;

                t3->second->setNormalizovaniFaktorAktivnostiSinapse(normalizovani_faktor_aktivnosti_tezine);
            }
        }

         /**
            VEROVATNOCA DEGENERACIJE SINAPSI
            -tezine_ka_skrivenom_sloju
            -tezine_izmedju_skrivenih_slojeva
            -tezine_ka_efektoru
        */
        void verovatnocaDegeneracijeSinapsi(){
            /**
            tezine_ka_skrivenom_sloju
            */
            for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){

                double verovatnoca_degeneracije_sinapse = 0.0;
                double normalizovani_faktor_aktivnosti_tezine = t1->second->getNormalizovaniFaktorAktivnosti();
                double vremenski_faktor_degeneracije_sinapsi = getVremenskiFaktorDegeneracijeSinapsi();

                if(normalizovani_faktor_aktivnosti_tezine<=granicna_vrednost_aktivnosti_sinapsi){
                    verovatnoca_degeneracije_sinapse =
                    faktor_degeneracije_sinapsi * vremenski_faktor_degeneracije_sinapsi *
                    (1 - ((1 - exp(-normalizovani_faktor_aktivnosti_tezine))/(1 - exp(-faktor_osetljivosti_na_degeneraciju))));
                }
                t1->second->setVerovatnocaDegeneracijeSinapse(verovatnoca_degeneracije_sinapse);
            }
            /**
            tezine_izmedju_skrivenih_slojeva
            */
            for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!=tezine_izmedju_skrivenih_slojeva.end(); t2++){

                double verovatnoca_degeneracije_sinapse = 0.0;
                double normalizovani_faktor_aktivnosti_tezine = t2->second->getNormalizovaniFaktorAktivnosti();
                double vremenski_faktor_degeneracije_sinapsi = getVremenskiFaktorDegeneracijeSinapsi();

                if(normalizovani_faktor_aktivnosti_tezine<=granicna_vrednost_aktivnosti_sinapsi){
                    verovatnoca_degeneracije_sinapse =
                    faktor_degeneracije_sinapsi * vremenski_faktor_degeneracije_sinapsi *
                    (1 - ((1 - exp(-normalizovani_faktor_aktivnosti_tezine))/(1 - exp(-faktor_osetljivosti_na_degeneraciju))));
                }
                t2->second->setVerovatnocaDegeneracijeSinapse(verovatnoca_degeneracije_sinapse);
            }
            /**
            tezine_ka_efektoru
            */
            for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++){

                double verovatnoca_degeneracije_sinapse = 0.0;
                double normalizovani_faktor_aktivnosti_tezine = t3->second->getNormalizovaniFaktorAktivnosti();
                double vremenski_faktor_degeneracije_sinapsi = getVremenskiFaktorDegeneracijeSinapsi();

                if(normalizovani_faktor_aktivnosti_tezine<=granicna_vrednost_aktivnosti_sinapsi){
                    verovatnoca_degeneracije_sinapse =
                    faktor_degeneracije_sinapsi * vremenski_faktor_degeneracije_sinapsi *
                    (1 - ((1 - exp(-normalizovani_faktor_aktivnosti_tezine))/(1 - exp(-faktor_osetljivosti_na_degeneraciju))));
                }
                t3->second->setVerovatnocaDegeneracijeSinapse(verovatnoca_degeneracije_sinapse);
            }
        }

        void setVremenskiFaktorDegeneracijeSinapsi(){
            vremenski_faktor_degeneracije_sinapsi = tanh(broj_ciklusa_proteklih_od_poslednje_degeneracije_sinapse_u_mrezi/faktor_oporavka_na_degeneraciju_sinapse);
        }
        double getVremenskiFaktorDegeneracijeSinapsi(){
            return vremenski_faktor_degeneracije_sinapsi;
        }
        /**
            PROCES DEGENERACIJE SINAPSE
            sinapsa ce se degenerisati ako je verovatnoca degeneracije iznad 50%
        */
        void procesDegeneracijeSinapsi(){

            setVremenskiFaktorDegeneracijeSinapsi();

            setInformativnaEnergijaCelija();
            faktorAktivnostiSinapsi();
            normalizovaniFaktorAktivnostiSinapsi();
            verovatnocaDegeneracijeSinapsi();

            /**
            tezine_ka_skrivenom_sloju
            */
            string kljuc_najmanje_aktivne_tezine;
            double verovatnoca_degeneracije_najmanje_aktivne_tezine = 0.0;

            for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){
                if(t1->second->getVerovatnocaDegeneracijeSinapse()>verovatnoca_degeneracije_najmanje_aktivne_tezine){
                    verovatnoca_degeneracije_najmanje_aktivne_tezine = t1->second->getVerovatnocaDegeneracijeSinapse();
                    kljuc_najmanje_aktivne_tezine = t1->second->getKljuc();
                }
            }
            /**
            tezine_izmedju_skrivenih_slojeva
            */
            for(t2 = tezine_izmedju_skrivenih_slojeva.begin(); t2!=tezine_izmedju_skrivenih_slojeva.end(); t2++){
                if(t2->second->getVerovatnocaDegeneracijeSinapse()>verovatnoca_degeneracije_najmanje_aktivne_tezine){
                    verovatnoca_degeneracije_najmanje_aktivne_tezine = t2->second->getVerovatnocaDegeneracijeSinapse();
                    kljuc_najmanje_aktivne_tezine = t2->second->getKljuc();
                }
            }
            /**
            tezine_ka_efektoru
            */
            for(t3 = tezine_ka_efektoru.begin(); t3!=tezine_ka_efektoru.end(); t3++){
                if(t3->second->getVerovatnocaDegeneracijeSinapse()>verovatnoca_degeneracije_najmanje_aktivne_tezine){
                    verovatnoca_degeneracije_najmanje_aktivne_tezine = t3->second->getVerovatnocaDegeneracijeSinapse();
                    kljuc_najmanje_aktivne_tezine = t3->second->getKljuc();
                }
            }

            if(verovatnoca_degeneracije_najmanje_aktivne_tezine>0.5){

                if(tezine_ka_skrivenom_sloju.find(kljuc_najmanje_aktivne_tezine)!=tezine_ka_skrivenom_sloju.end()){
                    SkrivenaCelija &celija = tezine_ka_skrivenom_sloju.find(kljuc_najmanje_aktivne_tezine)->second->getSkrivenaCelija();
                    celija.erasePobudjujucuTezinu(kljuc_najmanje_aktivne_tezine);

                    tezine_ka_skrivenom_sloju.erase(kljuc_najmanje_aktivne_tezine);
                }
                if(tezine_izmedju_skrivenih_slojeva.find(kljuc_najmanje_aktivne_tezine)!=tezine_izmedju_skrivenih_slojeva.end()){
                    SkrivenaCelija &prethodna = tezine_izmedju_skrivenih_slojeva.find(kljuc_najmanje_aktivne_tezine)->second->getPrvaSkrivenaCelija();
                    SkrivenaCelija &naredna = tezine_izmedju_skrivenih_slojeva.find(kljuc_najmanje_aktivne_tezine)->second->getDrugaSkrivenaCelija();
                    prethodna.erasePobudjivackuTezinu(kljuc_najmanje_aktivne_tezine);
                    naredna.erasePobudjujucuTezinu(kljuc_najmanje_aktivne_tezine);

                    tezine_izmedju_skrivenih_slojeva.erase(kljuc_najmanje_aktivne_tezine);
                }
                if(tezine_ka_efektoru.find(kljuc_najmanje_aktivne_tezine)!=tezine_ka_efektoru.end()){
                    SkrivenaCelija &celija = tezine_ka_efektoru.find(kljuc_najmanje_aktivne_tezine)->second->getSkrivenaCelija();
                    Efektor &efektor = tezine_ka_efektoru.find(kljuc_najmanje_aktivne_tezine)->second->getEfektorski_izlaz();
                    celija.erasePobudjivackuTezinu(kljuc_najmanje_aktivne_tezine);
                    efektor.erasePobudjujucuTezinu(kljuc_najmanje_aktivne_tezine);

                    tezine_ka_efektoru.erase(kljuc_najmanje_aktivne_tezine);
                }
                broj_degeneracija_sinapsi++;
                broj_ciklusa_proteklih_od_poslednje_degeneracije_sinapse_u_mrezi = 0;
            }
        }

        void procesDegeneracijeCelija(){
            int broj_celija = skrivene_celije.size();
            for(s1 = skrivene_celije.begin(); s1 != skrivene_celije.end(); s1++){
                    //SkrivenaCelija *celija = s1->second;
                    int skriveni_sloj = s1->second->getBroj_skrivenog_sloja();

                    //sve POBUDJUJUCE sinapse degenerisane
                    if(s1->second->getPobudjujuceTezine().empty()){
                             double izlaz_degenerisuce_celije = s1->second->getIzlaz();
                            ///novi prag pobudjivane celije: STARI_PRAG + VREDNOST_POBUDJIVACKE_TEZINE_DEGENERISUCE_CELIJE*IZLAZ_DEGENERISUCE_CELIJE
                            // TEZINE KA DRUGIM SLOJEVIMA SKRIVENIH CELIJA
                            while(!s1->second->getPobudjivackeTezine().empty()){
                                if(s1->second->getPobudjivackeTezine().empty())break;
                                string tezina = s1->second->getPrvuPobudjivackuTezinu();
                                //cout<<"A"<<endl;
                                if(tezine_izmedju_skrivenih_slojeva.find(tezina)!=tezine_izmedju_skrivenih_slojeva.end()){
                                    double vrednost_tezine = tezine_izmedju_skrivenih_slojeva.find(tezina)->second->getVrednost();
                                    SkrivenaCelija &pobudjena =  tezine_izmedju_skrivenih_slojeva.find(tezina)->second->getDrugaSkrivenaCelija();
                                    double stari_prag = pobudjena.getPragAktivacije();
                                    pobudjena.setPragAktivacije(stari_prag + vrednost_tezine*izlaz_degenerisuce_celije);
                                    tezine_izmedju_skrivenih_slojeva.erase(tezina);
                                }else{ //TEZINE KA EFEKTORIMA
                                    double vrednost_tezine = tezine_ka_efektoru.find(tezina)->second->getVrednost();
                                    Efektor &efektor =  tezine_ka_efektoru.find(tezina)->second->getEfektorski_izlaz();
                                    double stari_prag = efektor.getPragAktivacije();
                                    efektor.setPragAktivacije(stari_prag + vrednost_tezine*izlaz_degenerisuce_celije);
                                    tezine_ka_efektoru.erase(tezina);
                                }
                                //s1->second->prikaziStanje();
                                s1->second->erasePobudjivackuTezinu(tezina);
                            }
                            //cout<<"\n\n\nPOSLE BRISANJA\n";
                            //s1->second->prikaziStanje();
                            s1->second->eraseMapeTezina();
                            skrivene_celije.erase(s1);
                            broj_slojeva[skriveni_sloj+1]--;
                            broj_degenerisanih_celija++;
                            //cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;
                            vrsta_degeneracije_celije.append("A");
                            break;
                    }
                    //sve POBUDJIVACKE sinapse degenerisane
                    if(s1->second->getPobudjivackeTezine().empty()){
                        while(!s1->second->getPobudjujuceTezine().empty()){
                            if(s1->second->getPobudjujuceTezine().empty())break;
                            string tezina = s1->second->getPrvuPobudjujucuTezinu();
                            //cout<<"B"<<tezina<<endl;
                                if(tezine_izmedju_skrivenih_slojeva.find(tezina)!=tezine_izmedju_skrivenih_slojeva.end()){
                                    tezine_izmedju_skrivenih_slojeva.erase(tezina);
                                }else{ //TEZINE KA SKRIVENOM SLOJU
                                    if(tezine_ka_skrivenom_sloju.find(tezina)!=tezine_ka_skrivenom_sloju.end())
                                    tezine_ka_skrivenom_sloju.erase(tezina);
                                    //for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){
                                    //    cout<<" "<<t1->second->getKljuc()<<" ";
                                    //    }
                                    //cout<<"\n\n";
                                }
                                //s1->second->prikaziStanje();
                                s1->second->erasePobudjujucuTezinu(tezina);
                            }
                            //cout<<"\n\n\nPOSLE BRISANJA\n";
                            //s1->second->prikaziStanje();
                            //for(t1 = tezine_ka_skrivenom_sloju.begin(); t1!=tezine_ka_skrivenom_sloju.end(); t1++){
                            //            cout<<" "<<t1->second->getKljuc()<<" ";
                            //            }
                            //        cout<<"\n\n";
                        s1->second->eraseMapeTezina();
                        skrivene_celije.erase(s1);
                        //for(s2 = skrivene_celije.begin(); s2!=skrivene_celije.end(); s2++){
                        //                cout<<" "<<s2->second->getKljuc()<<" ";
                        //                }
                        //            cout<<"\n\n";
                        broj_slojeva[skriveni_sloj+1]--;
                        cout<<broj_slojeva[skriveni_sloj+1]<<endl;
                        broj_degenerisanih_celija++;
                        //cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;
                        vrsta_degeneracije_celije.append("B");
                        break;
                    }

            }
        }

        int getBrojDegeneracijaSinapsi(){return broj_degeneracija_sinapsi;}

        int getBrojDegenerisanihCelija(){return broj_degenerisanih_celija;}

        string getVrstaDegeneracijaCelija(){return vrsta_degeneracije_celije;}

        double ApsolutnaVrednost(double vrednost){
            return (vrednost<0)?(vrednost*=-1):vrednost;
        }

        void testnaFunkcija(){
            postaviUlaze(3,false);
            postaviUlaze(3,false);
            postaviUlaze(3,false);
/*            for(s1 = skrivene_celije.begin(); s1!=skrivene_celije.end(); s1++){
            //SkrivenaCelija *celija = s1->second;
            //int k = celija->getPobudjujuceTezine().size();
            //for (int i = 0; i<k; i++){
            //    celija->erasePobudjujucuTezinu();
            //    }
            s1->second->prikaziStanje();
            cout<<"BRISANJE POB TEZINA"<<endl;
            s1->second->erasePobudjujuceTezine();
            s1->second->prikaziStanje();
            cout<<endl;

            }
            postaviUlaze(0,false);
            generisiIzlazSkrivenihCelija(false);
            cout<<"AAAAAAAAAAAAnovo stanje"<<endl;
            for(s1 = skrivene_celije.begin(); s1!=skrivene_celije.end(); s1++){
                s1->second->prikaziStanje();
            }
*/
        cout<<"AAAAAAAAAAAA  novo stanje"<<endl;
        generisiIzlazSkrivenihCelija(false);
        prikaziStanjeTezina();
        }

};

#endif // NEURONSKAMREZA_HPP_INCLUDED
