 /******************************************/                           
    // TP Animaux cours de C++
    // ELR --- CIR2 ---2021/2022
    // fichier Monde.cpp
    // Méthodes de la classe monde
 /******************************************/
#include "Monde.h"
#include "Lion.h"
#include "Gazelle.h"

// initialisation du nombre d'animaux
Monde::Monde(int nb_ani)
{
    nb_animaux = nb_ani;
}
//destructeur
Monde::~Monde() {}
//creation des lions et gazelles
void Monde::peuplement()
{
    srand(time(NULL));
    int engie, xx, yy;
    for (int i = 0; i < MAX_Y; i++)
    {
        for (int j = 0; j < MAX_X; j++)
        {
            tab2D[i][j] = '-';
        }
    }
    for (int i = 0; i < nb_animaux; i++)
    {
        engie = rand() % 100;
        xx = rand() % MAX_X;
        yy = rand() % MAX_Y;
        if (i % 2)
        {
            tab_anim.push_back(new Lion(xx, yy, engie));
        }
        else
        {
            tab_anim.push_back(new Gazelle(xx, yy, engie));
        }
    }
}
//affiche le tableau
void Monde::affiche()
{
    system("clear");
    std::cout << "\n";
    for (int nb; nb < MAX_X + 2; nb++)
    {
        std::cout << "~";
    }
    std::cout << "\n";
    for (int i = 0; i < MAX_Y; i++)
    {
        std::cout << "|";
        for (int j = 0; j < MAX_X; j++)
        {
            std::cout << GRN;
            std::cout << tab2D[i][j];
        }
        std::cout << NC;
        std::cout << "|\n";
    }
    for (int nb; nb < MAX_X + 2; nb++)
    {
        std::cout << "~";
    }
    std::cout << "\n";
    usleep(100000);
}
//remplir le tableau d'animaux
void Monde::remplirTab()
{
    for (int i = 0; i < MAX_Y; i++)
    {
        for (int j = 0; j < MAX_X; j++)
        {
            tab2D[i][j] = ' ';
        }
    }
    for (auto animal : tab_anim)
    {
        tab2D[animal->getY()][animal->getX()] = animal->getlettre();
    }
}
//retourne -1 ou +1
int Monde::positif_ou_negatif()
{
    if (rand() % 2 == 1)
    {
        return 1;
        // printf("déplacemen 1");
    }
    else
    {
        return -1;
        //printf("déplacemetn -1");
    }
}
//delacement en x
void Monde::bouger_x(int nb, int val)
{
    if (tab_anim[nb]->getX() + val < 0)
    {
        tab_anim[nb]->setX(0);
    }
    else if (tab_anim[nb]->getX() + val >= MAX_X)
    {
        tab_anim[nb]->setX(MAX_X - 1);
    }
    else
    {
        tab_anim[nb]->setX(tab_anim[nb]->getX() + val);
    }
}
//deplacement en y
void Monde::bouger_y(int nb, int val)
{
    if (tab_anim[nb]->getY() + val < 0)
    {
        tab_anim[nb]->setY(0);
    }
    else if (tab_anim[nb]->getY() + val >= MAX_Y)
    {
        tab_anim[nb]->setY(MAX_Y - 1);
    }
    else
    {
        tab_anim[nb]->setY(tab_anim[nb]->getY() + val);
    }
}
//affectation des nouvelles positions
void Monde::modif_position(int nb, int val)
{
    if (positif_ou_negatif() == 1)
    {
        bouger_x(nb, val);
    }
    else
    {
        bouger_y(nb, val);
    }
}
//bouge un animal
void Monde::bouge(int nb)
{
    int val, deplacement;
    val = positif_ou_negatif();
    if (en0(nb))
    {
        //supprime l'animal
        delete tab_anim[nb];
        tab_anim.erase(tab_anim.begin() + nb);
    }
    else
    {
        //enlèver de l'énergie à l'animal
        tab_anim[nb]->setEnergie(tab_anim[nb]->getEnergie() - 1);
        modif_position(nb, val);
    }
}
//gère les collisions
void Monde::colision(int nbanimaux)
{
    int x, y, x2, y2, a;
    for (int i = 0; i < nbanimaux; i++)
    {
        x = tab_anim[i]->getX();
        y = tab_anim[i]->getY();
        for (int j = 0; j < nbanimaux; j++)
        {
            x2 = tab_anim[j]->getX();
            y2 = tab_anim[j]->getY();
            if (x2 == x && y2 == y)
            {
                a = j;
                if (j != i)
                {
                    lion_vs_gazelle(tab_anim[i]->getlettre(), tab_anim[j]->getlettre(), i, j);
                    printf("mm\n");
                    // tab_anim[a]->setX(tab_anim[a]->getX()-1);
                    //  if(tab_anim[a]->getX()<0){
                    //      tab_anim[a]->setX(0);
                    //  }
                }
            }
        }
    }
}
//les lions mangent les gazelles
void Monde::lion_vs_gazelle(char lettre1, char lettre2, int nb_lettre1, int nb_lettre2)
{
    if ((lettre1 == 'L') && (lettre2 == 'G'))
    {
        delete tab_anim[nb_lettre2];
        tab_anim.erase(tab_anim.begin() + nb_lettre2);
        nb_g_manger++;
        tab_anim[nb_lettre1]->setEnergie(tab_anim[nb_lettre1]->getEnergie() + 10);
    }
    if ((lettre1 == 'G') && (lettre2 == 'L'))
    {
        delete tab_anim[nb_lettre1];
        tab_anim.erase(tab_anim.begin() + nb_lettre1);
        nb_g_manger++;
        tab_anim[nb_lettre2]->setEnergie(tab_anim[nb_lettre2]->getEnergie() + 10);
    }
}
//retourn 1 si l'animal n'a plus d'énergie
int Monde::en0(int i)
{
    if (tab_anim[i]->getEnergie() == 0)
    {
        return 1;
    }
}