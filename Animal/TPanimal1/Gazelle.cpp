 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Gazelle.cpp
    // Méthode de la classe Gazelle
 /******************************************/
#include "Gazelle.h"
#include "Animals.h"
void Gazelle::affiche()const{
    std::cout<<"Gazelle :  x:"<<getX()<<",y:"<<getY()<<",energie:"<<getEnergie()<<"\n";

}
char Gazelle::getlettre()const{
    return lettre;
}