 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier main.cpp
    // fonction principale
 /******************************************/
#include "Monde.h"
#include "Lion.h"
#include "Gazelle.h"
int main()
{
    int nbAnimVoulu =50;
    Monde le_monde(nbAnimVoulu);
    le_monde.peuplement();
    le_monde.remplirTab();
    //le_monde.affiche();
 
    std::cout<<"----------------------"<<"\n";
    do{
        for(int i=0;i<le_monde.getNBAnimaux() ;i++){
            le_monde.bouge(i);   
        }
        //std::cout<<"size:"<<le_monde.gettab_anim().size();

        le_monde.colision(le_monde.getNBAnimaux());
        le_monde.remplirTab();
        
        le_monde.affiche();
        
    }while(le_monde.getNBAnimaux() != 0);
    std::cout<<"\n---\nfin \n---\n";

    // Lion monlion;
    // Lion lionceau(4,8,55);
    // monlion.affiche();
    // lionceau.affiche();
    // Gazelle une_gaz;
    // Gazelle martine(10,9,80);
    // une_gaz.affiche();
    // martine.affiche();
    // std::cout<<martine.getlettre()<<"----"<<monlion.getlettre()<<"\n";
    std::cout<<"nombre de gazelle mangée : "<<le_monde.getnb_g_manger()<<"\n";

}