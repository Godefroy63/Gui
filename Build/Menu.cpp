#include "Menu.h"

Menu::Menu()
{
	this->GrpGui.clear();
	
}

void Menu::load(int pLargeurEcr, int pHauteurEcr)
{
	this->Event = true;
	this->mCopieIndex = 0;

	this->mListPanel.push_back(new Panel);
	this->mListPanel[0]->newPanel(200, 100, 200, 100, sf::Color(150, 150, 150, 150));
	this->mListPanel[0]->setImage("Image/Panel1.png");
	this->GrpGui.push_back(this->mListPanel[0]);

	/*this->mListPanel.push_back(new Panel);
	this->mListPanel[1]->newPanel(100, 100, 200, 100, sf::Color(150, 150, 150, 150));
	this->GrpGui.push_back(this->mListPanel[1]);

	this->mListPanel.push_back(new Panel);
	this->mListPanel[2]->newPanel(100, 100, 500, 100, sf::Color(100, 150, 150, 150));
	this->GrpGui.push_back(this->mListPanel[2]);*/

	this->mListText.push_back(new Text);
	this->mListText[0]->newText(100, 100, 200, 100, 20, "Menu", "Font/VCR_OSD_MONO_1.001.ttf");
	//this->mListText[0]->setImageText("Image/Panel1.png");
	this->mListText[0]->setColorText(sf::Color(200, 200, 200, 255));
	this->mListText[0]->setAlignement("center", "center");
	this->GrpGui.push_back(this->mListText[0]);

	this->mLostBouton.push_back(new Bouton);
	this->mLostBouton[0]->newBouton(400, 100, 200, 100, sf::Color(150, 200, 150, 150), sf::Color(150, 150, 150, 150), sf::Color(150, 150, 200, 150));
	this->mLostBouton[0]->addBoutonText(20, "Start", "Font/VCR_OSD_MONO_1.001.ttf", "center", "center");
	this->GrpGui.push_back(this->mLostBouton[0]);
}

void Menu::update(sf::RenderWindow& window, Input input)
{
	for (size_t i{ 0 }; i < this->GrpGui.size(); i++)
	{
		this->GrpGui[this->GrpGui.size() - 1 - i]->update(window, input, this->Event);
		
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	for (size_t i{ 0 }; i < this->GrpGui.size(); i++)
	{
		this->GrpGui[i]->draw(window);
	}

}
