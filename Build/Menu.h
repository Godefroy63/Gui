#pragma once
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include"Gui.h"

class Menu
{
	public:

	//Constructeur
	Menu();
	~Menu(){
		for (size_t i{ 0 }; i < this->GrpGui.size(); i++)
		{
			delete this->GrpGui[i];
			this->GrpGui[i] = nullptr;
		}

	}

	//Methode
	void load(int pLargeurEcr,int pHauteurEcr);
	void update(sf::RenderWindow& window,Input input);
	void draw(sf::RenderWindow& window);

	private:
		
	//std::vector<std::vector<AbstractGui*>> GrpGui;
	std::vector<Gui*> GrpGui;
	std::vector<Panel*> mListPanel;
	std::vector<Bouton*>mLostBouton;
	std::vector<Text*> mListText;
	bool Event;
	int mCopieIndex;
	//Text mText;



};


#endif // !MENU_H

