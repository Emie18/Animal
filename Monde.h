 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Monde.h
    // Classe Monde
 /******************************************/
#ifndef MONDE_H
#define MONDE_H
#include <iostream>
#include <vector>
#include "Animals.h"
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#define REDB "\e[41m"
#define GRN "\e[0;42m"
#define CYN "\e[0;36m"
#define NC "\e[0m"

class Monde
{
private:
    static const int MAX_X = 30;
    static const int MAX_Y = 15;
    int nb_animaux;
    char tab2D[MAX_Y][MAX_X];
    std::vector<Animals*> tab_anim;
    int nb_g_manger = 0;

public:
    Monde(int nb_ani);
    ~Monde();
    int getMAX_X() const { return MAX_X; }
    int getMAX_Y() const { return MAX_Y; }
    int getNBAnimaux() const { return tab_anim.size(); }
    int getnb_g_manger()const {return nb_g_manger;}
    void peuplement();
    void bouge(int nb);
    void remplirTab();
    void colision(int nbanimaux);
    void lion_vs_gazelle(char lettre1, char lettre2, int nb_lettre1, int nb_lettre2);
    int positif_ou_negatif();
    void bouger_x(int nb, int val);
    void bouger_y(int nb, int val);
    void modif_position(int nb, int val);
    std::vector<Animals*> gettab_anim() { return tab_anim; };
    int en0(int i);
    //void supprimeAnimal(Animals * animalmort);
    void affiche();
};
#endif