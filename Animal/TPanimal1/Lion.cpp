 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Lion.cpp
    // Méthode de la classe Lion
 /******************************************/
#include "Lion.h"
#include "Animals.h"
void Lion::affiche()const {
    std::cout<<"Lion :  x:"<<getX()<<",y:"<<getY()<<",energie:"<<getEnergie()<<"\n";

}
char Lion::getlettre()const{
    return lettre;
}