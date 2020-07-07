#include "Gui.h"

//---------------------Class Panel-------------------------------------


//Acceseur
sf::Vector2i Panel::getSize() { return this->Component.Dim; }
sf::Vector2i Panel::getPos() { return this->Component.pos; }
bool Panel::getIsHover() { return this->Component.isHover; }

//Mutateur
void Panel::setSize(sf::Vector2i pSize) { this->Component.Dim = pSize; }
void Panel::setPos(sf::Vector2i pPos) { this->Component.pos = pPos; }
void Panel::setVisible(bool pVisible){ this->Component.Visible = pVisible; }
void Panel::setColor(sf::Color pColor){ this->Component.Color = pColor; }

void Panel::setImage(std::string pNameImage)
{
	if (!this->Component.Texture.loadFromFile(pNameImage))
	{
		std::cout << "Impossible de charger " << pNameImage << std::endl;
	}
	this->Component.Dim.x = this->Component.Texture.getSize().x;
	this->Component.Dim.y = this->Component.Texture.getSize().y;
	this->Component.Sprite.setTexture(this->Component.Texture);
	this->Component.Image = true;
}

//Mehtode
void Panel::newPanel(int pX, int pY, int pW, int pH, sf::Color pColor)
{
	this->Component.pos.x = pX;
	this->Component.pos.y = pY;
	this->Component.Dim.x = pW;
	this->Component.Dim.y = pH;
	this->Component.Color = pColor;
	this->Component.Visible = true;
	this->Component.Image = false;
	this->mEventOk == false;
}

void Panel::drawPanel(sf::RenderWindow& window)
{

	/*if (this->Component.isHover == true)
	{
		this->mRectSel.setSize(sf::Vector2f(this->Component.Dim.x + 5, this->Component.Dim.y + 5));
		this->mRectSel.setPosition(sf::Vector2f(this->Component.pos.x - 2.5, this->Component.pos.y - 2.5));
		window.draw(this->mRectSel);
	}*/

	if (this->Component.Image == false)
	{
		this->Component.Rectangle.setSize(sf::Vector2f(this->Component.Dim.x, this->Component.Dim.y));
		this->Component.Rectangle.setPosition(sf::Vector2f(this->Component.pos.x, this->Component.pos.y));
		this->Component.Rectangle.setFillColor(this->Component.Color);
		window.draw(this->Component.Rectangle);
	}
	else
	{
		this->Component.Sprite.setPosition(sf::Vector2f(this->Component.pos.x, this->Component.pos.y));
		window.draw(this->Component.Sprite);
	}	

	if (this->mScale == true)
	{
		this->mRect.setPosition(sf::Vector2f(this->mPosRect.x, this->mPosRect.y));
		window.draw(this->mRect);
	}
		
}

void Panel::draw(sf::RenderWindow& window)
{
	if (this->Component.Visible == true)
	{
		this->drawPanel(window);
	}

}

bool Panel::eventIsHover(sf::RenderWindow& window)
{
	this->mMouse.x = sf::Mouse::getPosition(window).x;
	this->mMouse.y = sf::Mouse::getPosition(window).y;

	if (this->mMouse.x > this->Component.pos.x && this->mMouse.x < this->Component.pos.x + this->Component.Dim.x &&
		this->mMouse.y > this->Component.pos.y && this->mMouse.y < this->Component.pos.y + this->Component.Dim.y)
	{
		this->Component.isHover = true;
		this->mPosRectSel.x = this->Component.pos.x;
		this->mPosRectSel.y = this->Component.pos.y;
		return true;
	}
	else
	{
		this->Component.isHover = false;
		return false;
	}
		
}

void Panel::eventMoovePannel(sf::RenderWindow& window, Input input, bool& pEventOk)
{
	
	if (this->Component.isHover == true && input.getButton().Click_left == true && pEventOk == true)
	{
		this->mEventOk = true;
		this->mPrise = true;
		pEventOk = false;
	}
	
	if (input.getButton().Click_left == false)
	{
		this->mPrise = false;
		this->mDelta.x = this->mMouse.x - this->Component.pos.x;
		this->mDelta.y = this->mMouse.y - this->Component.pos.y;
		this->mMouseDown = this->mMouse;
		pEventOk = true;
	}

	if (this->mPrise == true)
	{
		this->Component.pos.x = this->mMouse.x - this->mDelta.x;
		this->Component.pos.y = this->mMouse.y - this->mDelta.y;
	}
}

void Panel::eventScalePannel(sf::RenderWindow& window, Input input, bool& pEventOk)
{
	
	if (this->mMouse.x > this->Component.pos.x && this->mMouse.x < this->Component.pos.x + this->mRectScale &&
		this->mMouse.y> this->Component.pos.y && this->mMouse.y < this->Component.pos.y + this->mRectScale)
	{ 
		this->mPosRect.x = this->Component.pos.x;
		this->mPosRect.y = this->Component.pos.y;
		this->mScale = true;
		this->mCoin = 1;
	}
	else if (this->mMouse.x > this->Component.pos.x + this->Component.Dim.x - this->mRectScale && this->mMouse.x < this->Component.pos.x + this->Component.Dim.x &&
		this->mMouse.y > this->Component.pos.y && this->mMouse.y < this->Component.pos.y + this->mRectScale)
	{
		this->mPosRect.x = this->Component.pos.x + this->Component.Dim.x - this->mRectScale;
		this->mPosRect.y = this->Component.pos.y;
		this->mScale = true;
		this->mCoin = 2;
	}
	else if (this->mMouse.x > this->Component.pos.x && this->mMouse.x < this->Component.pos.x + this->mRectScale &&
		this->mMouse.y > this->Component.pos.y + this->Component.Dim.y - this->mRectScale && this->mMouse.y < this->Component.pos.y + this->Component.Dim.y)
	{
		this->mPosRect.x = this->Component.pos.x;
		this->mPosRect.y = this->Component.pos.y + this->Component.Dim.y - this->mRectScale;
		this->mScale = true;
		this->mCoin = 3;
	}
	else if (this->mMouse.x > this->Component.pos.x + this->Component.Dim.x - this->mRectScale && this->mMouse.x < this->Component.pos.x + this->Component.Dim.x &&
		this->mMouse.y > this->Component.pos.y + this->Component.Dim.y - this->mRectScale && this->mMouse.y < this->Component.pos.y + this->Component.Dim.y)
	{
		this->mPosRect.x = this->Component.pos.x + this->Component.Dim.x - this->mRectScale;
		this->mPosRect.y = this->Component.pos.y + this->Component.Dim.y - this->mRectScale;
		this->mScale = true;
		this->mCoin = 4;
	}
	else
		this->mScale = false;

	if (input.getButton().Click_left == false)
	{
		this->mPosScale.x = this->Component.pos.x + this->Component.Dim.x;
		this->mPosScale.y = this->Component.pos.y + this->Component.Dim.y;
		this->mDimScale.x = this->Component.Dim.x;
		this->mDimScale.y = this->Component.Dim.y;
		this->mCoin = 0;
		this->mPriseScale = false;
		pEventOk = true;
	}

	if (this->mScale == true && input.getButton().Click_left == true && pEventOk == true)
	{
		this->mPriseScale = true;
		pEventOk = false;
	}
		
	if (this->mPriseScale == true && this->mCoin == 1)
	{
		this->Component.pos.x = this->mMouse.x - this->mDelta.x;
		this->Component.pos.y = this->mMouse.y - this->mDelta.y;
		this->Component.Dim.x = this->mPosScale.x - this->mMouse.x;
		this->Component.Dim.y = this->mPosScale.y - this->mMouse.y;
	}
	else if (this->mPriseScale == true && this->mCoin == 2)
	{
		this->Component.Dim.x = this->mDimScale.x +(this->mMouse.x - this->mPosScale.x);
		this->Component.Dim.y = this->mPosScale.y - this->mMouse.y;
		this->mPrise = false;
		this->Component.pos.y = this->mMouse.y - this->mDelta.y;
	}
	else if (this->mPriseScale == true && this->mCoin == 3)
	{
		this->Component.Dim.x = this->mPosScale.x - this->mMouse.x;
		this->Component.Dim.y = this->mDimScale.y + (this->mMouse.y - this->mPosScale.y);
		this->mPrise = false;
		this->Component.pos.x = this->mMouse.x - this->mDelta.x;
	}
	else if (this->mPriseScale == true && this->mCoin == 4)
	{
		this->Component.Dim.x = this->mDimScale.x + (this->mMouse.x - this->mPosScale.x);
		this->Component.Dim.y = this->mDimScale.y + (this->mMouse.y - this->mPosScale.y);
		this->mPrise = false;
	}
		
}

void Panel::update(sf::RenderWindow& window, Input input, bool& pEventOk)
{
	this->eventIsHover(window);
	this->eventScalePannel(window, input, pEventOk);
	this->eventMoovePannel(window, input, pEventOk);
}

//---------------------Class Text-------------------------------------

//Mutateur
void Text::setVisible(bool pVisible) { this->TextComponent.Visible = pVisible; }
void Text::setColorText(sf::Color pColor) { this->TextComponent.Color = pColor; }
void Text::setColorPanel(sf::Color pColor) { this->setColor(pColor); }

void Text::setAlignement(std::string pAlignementX, std::string pAlignementY)
{
	this->TextComponent.AlignementX = pAlignementX;
	this->TextComponent.AlignementY = pAlignementY;
}

void Text::setImageText(std::string pNameImage) 
{ 
	this->setImage(pNameImage); 
	this->TextComponent.Dim.x = this->getSize().x;
	this->TextComponent.Dim.y = this->getSize().y;
}

//Methode
void Text::newText(int pX, int pY, int pW, int pH,int pCharSize, std::string pTexte, std::string pfont)
{
	this->TextComponent.Visible = true;

	this->newPanel(pX, pY, pW, pH, sf::Color(150, 150, 150, 255));
	
	this->TextComponent.pos.x = pX;
	this->TextComponent.pos.y = pY;
	this->TextComponent.Dim.x = pW;
	this->TextComponent.Dim.y = pH;
	
	if (!this->TextComponent.Font.loadFromFile(pfont))
	{
		std::cout << "Impossible de charger le Font" << std::endl;
	}

	this->TextComponent.sText = pTexte;
	this->TextComponent.Text.setFont(this->TextComponent.Font);
	this->TextComponent.CharSize = pCharSize;
	this->TextComponent.Color = sf::Color(255, 255, 255, 255);
	this->TextComponent.Text.setColor(this->TextComponent.Color);
	this->TextComponent.AlignementX = "right";
	this->TextComponent.AlignementY = "up";

}

void Text::drawText(sf::RenderWindow& window)
{
	int X{ 0 }, Y{ 0 };

	this->TextComponent.Dtext.x = sf::FloatRect(this->TextComponent.Text.getGlobalBounds()).width;
	this->TextComponent.Dtext.y = sf::FloatRect(this->TextComponent.Text.getGlobalBounds()).height;

	this->TextComponent.pos = this->getPos();
	this->TextComponent.Dim = this->getSize();

	this->TextComponent.Text.setString(this->TextComponent.sText);
	this->TextComponent.Text.setCharacterSize(this->TextComponent.CharSize);

	if (this->TextComponent.AlignementX == "center")
		X = this->TextComponent.pos.x + this->TextComponent.Dim.x / 2 - this->TextComponent.Dtext.x / 2;
	else if (this->TextComponent.AlignementX == "right")
		X = this->TextComponent.pos.x + 5;
	else if (this->TextComponent.AlignementX == "left")
		X = this->TextComponent.pos.x + this->TextComponent.Dim.x - this->TextComponent.Dtext.x - 5;


	if (this->TextComponent.AlignementY == "center")
		Y = this->TextComponent.pos.y + this->TextComponent.Dim.y / 2 - this->TextComponent.Dtext.y;
	else if (this->TextComponent.AlignementY == "up")
		Y = this->TextComponent.pos.y;
	else if (this->TextComponent.AlignementY == "down")
		Y = this->TextComponent.pos.y + this->TextComponent.Dim.y - this->TextComponent.Dtext.y * 2;
	
	this->TextComponent.Text.setPosition(sf::Vector2f(X, Y));
	this->TextComponent.Text.setColor(this->TextComponent.Color);
	window.draw(this->TextComponent.Text);

	
}

void Text::draw(sf::RenderWindow& window)
{
	if (this->TextComponent.Visible == true)
	{
		this->drawPanel(window);
		this->drawText(window);
	}

}

//---------------------Class Bouton-------------------------------------

//Mutateur
void Bouton::setVisible(bool pVisible) { this->mVisible = pVisible; }
void Bouton::setColorState1(sf::Color pColor) { this->mColor1 = pColor; }
void Bouton::setColorState2(sf::Color pColor) { this->mColor2 = pColor; }
void Bouton::setColorState3(sf::Color pColor) { this->mColor3 = pColor; }


//Methode
void Bouton::newBouton(int pX, int pY, int pW, int pH, sf::Color pColor1, sf::Color pColor2, sf::Color pColor3)
{
	this->mVisible = true;
	this->mBoutonPress = false;
	this->mBoutonDown = true;
	this->mText = false;
	this->mState = 0;
	this->mFrame = 0;

	this->newPanel(pX, pY, pW, pH, pColor1);
	this->mPos.x = pX;
	this->mPos.y = pY;
	this->mDim.x = pW;
	this->mDim.y = pH;
	this->mColor1 = pColor1;
	this->mColor2 = pColor2;
	this->mColor3 = pColor3;
	
}

void Bouton::addBoutonText(int pCharSize, std::string pTexte, std::string pfont,std::string pAlignementX, std::string pAlignementY)
{
	this->newText(this->mPos.x, this->mPos.y, this->mDim.x, this->mDim.y, pCharSize, pTexte, pfont);
	this->setAlignement(pAlignementX, pAlignementY);
	this->mText = true;
}

void Bouton::drawBouton(sf::RenderWindow& window)
{
	if (this->mState == 0)
		this->setColorPanel(this->mColor1);

	if (this->mState == 1)
		this->setColorPanel(this->mColor2);

	if (this->mState == 2)
		this->setColorPanel(this->mColor3);

}

void Bouton::draw(sf::RenderWindow& window)
{
	if (this->getIsHover() == true && this->mBoutonPress == false)
		this->mState = 1;
	else if (this->mBoutonPress == true)
		this->mState = 2;
	else if (this->mBoutonPress == false)
		this->mState = 0;

	if (this->mVisible == true)
	{
		this->drawBouton(window);
		this->drawPanel(window);

		if(this->mText == true)
			this->drawText(window);
	}

}

void Bouton::update(sf::RenderWindow& window, Input input, bool& pEventOk)
{
	this->eventIsHover(window);
	this->eventScalePannel(window, input, pEventOk);
	this->eventMoovePannel(window, input, pEventOk);
	this->eventClik(input);
}

void Bouton::eventClik(Input input)
{
	
	if (input.getButton().Click_left == true && this->getIsHover() == true)
	{
		this->mBoutonPress = true;
		this->mBoutonDown = false;
	}

	if (input.getButton().Click_left == false)
	{
		this->mBoutonDown = true;
	}

	if (this->mBoutonDown == true)
	{
		this->mFrame++;

		if (this->mFrame == 100)
		{
			this->mBoutonPress = false;
			this->mFrame = 0;
		}
		
	}
}


