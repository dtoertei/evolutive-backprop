#ifndef TEZINA_PRAGOVA_HPP_INCLUDED
#define TEZINA_PRAGOVA_HPP_INCLUDED

#include "Tezina.hpp"
#include <sstream>

class Tezina_pragova : public Tezina{
    string kljuc;
    public:
    Tezina_pragova(){}
    Tezina_pragova(string kljuc, double vrednost){
        this->kljuc = kljuc;
        this->vrednost = vrednost;
        }
    string getKljuc(){return this->kljuc;}

    string TezinaPragovaToString(){
        string log = "";
        stringstream out;

        out << "\nStanje Pragovske Tezine: ";
        out << this->getKljuc();
        out << "\n\tVrednost: ";
        out << this->getVrednost();

        out << "\n\n";
        log = out.str();
        return log;
        }
};

#endif // TEZINA_PRAGOVA_HPP_INCLUDED
