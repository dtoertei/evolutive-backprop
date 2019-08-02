#include <iostream>
#include "Efektor.cpp"
#include "Akceptor.cpp"
#include "SkrivenaCelija.cpp"
#include "NeuronskaMreza.hpp"
#include "Tezina_ka_skrivenom_sloju.hpp"
#include "Tezina_izmedju_skrivenih_slojeva.hpp"
#include "Tezina_ka_efektoru.hpp"


#include "math.h"
//#include <vector>


using namespace std;

int main()
{

    NeuronskaMreza *mreza = new NeuronskaMreza(2,6,3,1);

    float dozvoljena_greska = mreza->getDozvoljenaGreska();
    float greska  = 0;
    int i = 0;
    do{
        greska = mreza->step();
        i++;
        //system("cls");
        cout<<greska<<" "<<i<<endl;
    }while(dozvoljena_greska<greska);


    system("cls");
    cout<<"*****BROJ ITERACIJA****** "<<i<<"*******\n";
    mreza->test();
    cout<<"\nGRESKA: "<<greska;
    cout<<"\nEcrit par: Daniel Toertei, August 2009."<<endl;

    //mreza->prikaziStanjeTezina();
    //mreza->prikaziStanjeCelija();
    cout<<"\n\n";

    cout<<"Broj deoba: "<<mreza->getBrojDeoba()<<endl;
    cout<<"Broj degeneracija sinapsi: "<<mreza->getBrojDegeneracijaSinapsi()<<endl;
    cout<<"Broj degeneracija celija: "<<mreza->getBrojDegenerisanihCelija()<<endl;
    cout<<"Vrsta degeneracija celija"<<mreza->getVrstaDegeneracijaCelija()<<endl;
    mreza->prikaziVelicinuMreze();

    //mreza->testnaFunkcija();

    //mreza->step();

    mreza->BackPropagationLog();

    return 0;
}
