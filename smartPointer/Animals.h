 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Animals.h
    // classe Animals
 /******************************************/
#ifndef ANIMALS_H
#define ANIMALS_H
#include <iostream>
 class Animals{
    private :
        int x;
        int y;
        int energie;
        static const char lettre ='a';
    public :
        virtual void affiche() const;
        Animals();
        Animals(int x_init, int y_init, int energie_init);
        ~Animals();
        int getX() const;
        int getY() const;
        int getEnergie() const;
        void setX(int val);
        void setY(int val);
        void setEnergie(int val);
        //virtual char getlettre()const =0;
        static int getNbAnimaux();
        static bool samePosition(const Animals &anim1, const Animals &anim2);
 };
 #endif