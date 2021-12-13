 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Lion.h
    // Classe Lion
 /******************************************/
#ifndef LION_H
#define LION_H
    #include "Animals.h"
class Lion:public Animals {
    private:
     static const char lettre ='L';
    public:
    Lion():Animals(){}
    Lion(int x_init, int y_init, int energie_init):Animals(x_init, y_init, energie_init){
    }
    ~Lion(){}
    void affiche()const override ;
    char getlettre()const override;
};
#endif