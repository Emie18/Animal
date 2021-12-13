 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Animals.cpp
    // Méthodes de la classe Animals
 /******************************************/

#include "Animals.h"

//int Animals::nb_animaux =0;

void Animals::affiche() const{
    std::cout<<"x:"<<x<<",y:"<<y<<",energie:"<<energie<<"\n";
    //std::cout<<"nombre d'animaux: "<<nb_animaux<<"\n";
}
Animals::Animals(){
    x=0;
    y=0;
    energie = 100;
   // nb_animaux ++;
    //std::cout<<"dans le cteur\n";
}
Animals::Animals(int x_init, int y_init, int energie_init){
    x= x_init;
    y= y_init;
    energie= energie_init;
    //nb_animaux ++;
}
Animals::~Animals(){
    //std::cout<<"appel du destructeur \n";
    //nb_animaux --;
}
int Animals::getX()const{
    return x;
}
int Animals::getY()const{
    return y;
}
int Animals::getEnergie()const{
    return energie;
}
void Animals::setX(int val){
    x= val;
}
void Animals::setY(int val){
    y= val;
}
void Animals::setEnergie(int val){
    energie= val;
}
char Animals:: getlettre()const{
    return lettre;
}
int Animals:: getNbAnimaux(){
    //return nb_animaux;
}
bool Animals:: samePosition(const Animals &anim1, const Animals &anim2){
    return (anim1.x==anim2.x && anim1.y == anim2.y) ;
}