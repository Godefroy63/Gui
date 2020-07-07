#include "main.h"


int main()
{
    //création de la fenerte
    sf::RenderWindow window(sf::VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "lender");
    
    //Limite les fps à 60 images / seconde
    window.setFramerateLimit(60);

    //On active la synchro verticale
    window.setVerticalSyncEnabled(true);

    //instance 
    Input input;
    Menu menu;
    menu.load(LARGEUR_FENETRE, HAUTEUR_FENETRE);
   
    //Game loop
    while (window.isOpen())
    {
        //Gestion des input
        input.getInput(window);

        //Update
        menu.update(window,input);
     
        //Affichage 
        window.clear(sf::Color(0, 0, 0));
        menu.draw(window);
        window.display();
       
    }

    return 0;
}



