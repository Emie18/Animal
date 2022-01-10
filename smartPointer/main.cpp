#include "Animals.h"
#include <vector>
#include <memory>
int main()
{

    using namespace std;
    int nb_animaux = 100;
    std::vector<std::unique_ptr<Animals>> tab_animal;
    //peublement
    for (int i = 0; i < nb_animaux; ++i)
    {
        tab_animal.push_back(make_unique<Animals>(i,3,6));
    }
    //std::unique_ptr<Animals> uptr = std::make_unique <Animals>();

    for(auto &ani:tab_animal){
        ani->affiche();
    }
    for (int i = 0; i < nb_animaux; i++)
    {
        if (i % 2)
        {
            //tab_animal[i]=nullptr;
            tab_animal.erase(tab_animal.begin() + i);
        }
    }
    
   //tab_animal.erase(remove(tab_animal.begin(),tab_animal.end(),nullptr),tab_animal.end() );
    cout << "nb animaux :" << tab_animal.size() << "\n";
}