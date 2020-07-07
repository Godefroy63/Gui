#pragma once
#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Input.h"


class Gui
{
	
	public:

	//Constructeur
	Gui(){}
	virtual ~Gui(){}

	//Accesseur
	virtual sf::Vector2i getSize() = 0;
	virtual sf::Vector2i getPos() = 0;

	//Mutateur
	virtual void setVisible(bool pVisible) = 0;
	virtual void setImage(std::string pNameImage) = 0;
	virtual void setSize(sf::Vector2i pSize) = 0;
	virtual void setPos(sf::Vector2i pPos) = 0;
	
	//Methode
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(sf::RenderWindow& window,Input input, bool& pEventOk) = 0;
	virtual bool eventIsHover(sf::RenderWindow& window) = 0;
	virtual void eventMoovePannel(sf::RenderWindow& window, Input input, bool& pEventOk) = 0;
	virtual void eventScalePannel(sf::RenderWindow& window, Input input, bool& pEventOk) = 0;


};

class Panel :public Gui
{
	protected:

	//Structure
	struct sPanel
	{
		sf::Vector2i pos, Dim;
		bool Visible, isHover,Image;
		sf::Color Color;
		sf::Texture Texture;
		sf::Sprite Sprite;
		sf::RectangleShape Rectangle;
		
	};

	public:

	//Constructeur
	Panel::Panel() : Gui(), Component()
	{ 
		this->mPrise = false;
		this->mScale = false;
		this->mPriseScale = false;
		this->mRect.setSize(sf::Vector2f(this->mRectScale, this->mRectScale));
		this->mRect.setFillColor(sf::Color(250, 128, 114, 150));
		this->mRectSel.setFillColor(sf::Color(119, 181, 254, 150));
	}
	virtual ~Panel(){}


	//Accesseur
	sf::Vector2i getSize();
	sf::Vector2i getPos();
	bool getIsHover();

	//Mutateur
	void setSize(sf::Vector2i pSize);
	void setPos(sf::Vector2i pPos);
	void setImage(std::string pNameImage);
	void setVisible(bool pVisible);
	void setColor(sf::Color pColor);

	//Methode
	void newPanel(int pX, int pY, int pW, int pH, sf::Color pColor);
	void drawPanel(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, Input input,bool& pEventOk);
	bool eventIsHover(sf::RenderWindow& window);
	void eventMoovePannel(sf::RenderWindow& window, Input input, bool& pEventOk);
	void eventScalePannel(sf::RenderWindow& window, Input input, bool& pEventOk);


	private:

	sPanel Component;
	sf::RectangleShape mRect,mRectSel;
	sf::Vector2i mMouse, mDelta, mPosRect,mPosRectSel, mMouseDown, mPosScale, mDimScale;
	const int mRectScale{ 10 };
	bool mPrise,mScale,mPriseScale,mEventOk;
	int mCoin;
	
	
};

class Text :public Panel
{
	protected:
	//Structure
	struct sText
	{
		sf::Vector2i pos, Dim, Dtext;
		bool Visible, isHover;
		sf::Color Color;
		std::string sText,AlignementX, AlignementY;
		sf::Font Font;
		sf::Text  Text;
		int CharSize;
	};

	public: 

	//Constructeur
	Text() :Panel(), TextComponent(){}
	virtual ~Text() {}

	//Mutateur
	void setVisible(bool pVisible);
	void setImageText(std::string pNameImage);
	void setColorText(sf::Color pColor);
	void setColorPanel(sf::Color pColor);
	void setAlignement(std::string pAlignementX, std::string pAlignementY);

	//Methode
	void newText(int pX, int pY, int pW, int pH, int pCharSize,std::string pTexte, std::string pfont);
	void drawText(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	

	private:

	sText TextComponent;
};

class Bouton : public Text
{
	public:

	//Constructeur
	Bouton() :Text() {}
	virtual ~Bouton() {}

	//Mutateur
	void setVisible(bool pVisible);
	//void setImageState1(std::string pNameImage);
	//void setImageState2(std::string pNameImage);
	//void setImageState3(std::string pNameImage);
	void setColorState1(sf::Color pColor);
	void setColorState2(sf::Color pColor);
	void setColorState3(sf::Color pColor);
	
	//Methode
	void newBouton(int pX, int pY, int pW, int pH, sf::Color pColor1,sf::Color pColor2,sf::Color pColor3);
	void addBoutonText(int pCharSize, std::string pTexte, std::string pfont, std::string pAlignementX,std::string pAlignementY);
	void drawBouton(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window, Input input, bool& pEventOk);
	void eventClik(Input input);

	private:

	sf::Vector2i mPos, mDim;
	sf::Color mColor1, mColor2, mColor3;
	bool mVisible, mBoutonPress, mBoutonDown,mText;
	int mState,mFrame;
	
};




#endif // !GUI_H



