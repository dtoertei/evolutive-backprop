#ifndef EFEKTOR_HPP_INCLUDED
#define EFEKTOR_HPP_INCLUDED

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

typedef map<string,string> Mapa_pobudjujucih_tezina;

class Efektor{

        private:
            double ulazna_tezina;
            double izlaz;
            double izlazna_greska;
            double prag_aktivacije;
            double tezina_praga;
            double pobuda;
            double informativna_energija;
            int broj_efektora;
            int broj_sloja;
            Mapa_pobudjujucih_tezina pobudjujuce_tezine;
            string log_faktora_aktivnosti;
            ofstream filestr;
            char filename[3];
            int broj_zapisa;
            string kljuc;

        public:
            Efektor(){};
            Efektor(double ulazna_tezina, double izlaz, double izlazna_greska,double prag_aktivacije,double pobuda, int broj_efektora, int broj_sloja);

            Mapa_pobudjujucih_tezina::iterator it1;

            double getUlaznaTezina();
            double getIzlaz();
            double getIzlaznaGreska();
            double getPragAktivacije();
            double getTezinaPraga();
            double getPobuda();
            double getInformativnaEnergija();
            int getBrojEfektora();
            int getBrojSloja();
            Mapa_pobudjujucih_tezina getPobudjujuceTezine();
            string getKljuc();
            string EfektorToString();

            void setUlaznaTezina(double ulazna_tezina);
            void setIzlaz(double izlaz);
            void setIzlaznaGreska(double izlazna_greska);
            void setPragAktivacije(double prag_aktivacije);
            void setTezinaPraga(double tezina_praga);
            void setPobuda(double pobuda);
            void setInformativnaEnergija(double informativna_energija);
            void setBrojEfektora(int broj_efektora);
            void setBrojSloja(int broj_sloja);
            void addPobudjujucuTezinu(string kljuc);
            void erasePobudjujucuTezinu(string kljuc);
            void apdejtujLogFaktoraAktivnosti(string log_faktora_aktivnosti);
            void zapisiLogFaktoraAktivnosti();
            void erasePobudjujuceTezine(){this->pobudjujuce_tezine.clear();}

            void prikaziStanje();
};

#endif // EFEKTOR_HPP_INCLUDED
