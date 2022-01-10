 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Gazelle.h
    // Classe Gazelle
 /******************************************/
#ifndef GAZELLE_H
#define GAZELLE_H
    #include "Animals.h"
class Gazelle:public Animals {
    private:
     static const char lettre ='G';
    public:
    Gazelle():Animals(){}
    Gazelle(int x_init, int y_init, int energie_init):Animals(x_init, y_init, energie_init){
    }
    ~Gazelle(){}
    void affiche()const override;
    char getlettre()const override;

};
#endif