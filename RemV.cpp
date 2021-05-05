/**
 * @file RemV.H
 * @author Sergio MB
 * @brief Declaracion de las clases
 */

#include "RemV.h"

/**
 * @brief Constructor de la clase RemV que le asigna todos sus valores iniciales.
 * @param Posx
 * @param Posy
 * @param Width
 * @param Height
 * @param Color
 */
RemV::RemV(int Posx, int Posy, int Width, int Height, sf::Color Color) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    color = Color;

    Build();

}

/**
 * @brief Metodo build que construye las figuras que requiere la clase, textos y listas de texto para que funcione correctamente.
 */
void RemV::Build() {

    sf::RectangleShape tempR(sf::Vector2f(width, height));
    tempR.setPosition(posx, posy);
    tempR.setFillColor(color);

    area = tempR;

    sf::RectangleShape tempL(sf::Vector2f(5,height));
    col1 = tempL;
    col1.setPosition(posx + (width*0.25) -20,posy);
    col1.setFillColor(sf::Color(128,128,128,255));

    col2 = tempL;
    col2.setPosition(posx+ width -2*( (width*0.25)) -25,posy);
    col2.setFillColor(sf::Color(128,128,128,255));

    col3 = tempL;
    col3.setPosition(posx+ width -( (width*0.25)) -15,posy);
    col3.setFillColor(sf::Color(128,128,128,255));

    sf::RectangleShape rtmp(sf::Vector2f(width,5));
    rtmp.setPosition(posx,posy+29);
    rtmp.setFillColor(sf::Color(128,128,128,255));

    row1 = rtmp;

    CodeTxT *tempV = new CodeTxT;
    type = tempV;
    type->SetPosX(posx + 5);
    type->SetPosY(posy + 29);

    CodeTxT *tempV2 = new CodeTxT;
    val = tempV2;
    val->SetPosX(col1.getPosition().x + 5);
    val->SetPosY(posy + 32);
    val->SetFsize(16);

    CodeTxT *tempV3 = new CodeTxT;
    addr = tempV3;
    addr->SetPosX(col2.getPosition().x + 5);
    addr->SetPosY(posy + 32);
    addr->SetFsize(16);

    CodeTxT *tempV4 = new CodeTxT;
    refs = tempV4;
    refs->SetPosX(col3.getPosition().x + 5);
    refs->SetPosY(posy + 29);

    font.loadFromFile("../Fonts/consolas.ttf");

    rtitles.setFont(font);
    rtitles.setCharacterSize(20);
    rtitles.setColor(sf::Color::White);
    rtitles.setPosition(posx+5,posy+5);
    rtitles.setString("   Name      Value       Address      Refs");

}

/**
 * @brief Metodo Draw que se encarga de colocar en pantalla los componentes del log y consola. Recibe el puntero a la
 * ventana del GUI.
 * @param win
 */
void RemV::Draw(sf::RenderWindow *win) {

    win->draw(area);
    win->draw(col1);
    win->draw(col2);
    win->draw(col3);
    win->draw(row1);
    win->draw(rtitles);

    if (drawt){
        Line* temp = type->GetStart();
        while (temp != nullptr){
            sf::Text *todraw = temp->getVal();
            win->draw(*todraw);
            temp = temp->getNext();
        }

        Line* temp1 = val->GetStart();
        while (temp1 != nullptr){
            sf::Text *todraw = temp1->getVal();
            win->draw(*todraw);
            temp1 = temp1->getNext();
        }

        Line* temp2 = addr->GetStart();
        while (temp2 != nullptr){
            sf::Text *todraw = temp2->getVal();
            win->draw(*todraw);
            temp2 = temp2->getNext();
        }

        Line* temp3 = refs->GetStart();
        while (temp3 != nullptr){
            sf::Text *todraw = temp3->getVal();
            win->draw(*todraw);
            temp3 = temp3->getNext();
        }
    }

}

/**
 * @brief Asigna el json del cual debe colocar los valores en las listas de texto para que se actualicen en pantalla.
 * @param js
 */
void RemV::SetJson(json js) {

    j = js;
    BuildText();

}

/**
 * @brief Agrega a todas las listas de texto lo que se solicita segun el json.
 */
void RemV::BuildText() {

    int num = 0;
    while (num != j.size()){
        std::string jtype = j["num"+std::to_string(num)]["type"];
        std::string jval = j["num"+std::to_string(num)]["value"];
        std::string jaddr = j["num"+std::to_string(num)]["address"];
        std::string jrefs  = j["num"+std::to_string(num)]["refs"];

        type->Insert(jtype);
        val->Insert(jval);
        addr->Insert(jaddr);
        refs->Insert(jrefs);

        type->SetPosY(type->GetY()+24);
        val->SetPosY(val->GetY()+24);
        addr->SetPosY(addr->GetY()+24);
        refs->SetPosY(refs->GetY()+24);
        num++;
    }
    drawt = true;

}

/**
 * @brief Devuelve las listas de texto a nullptr para que se reinicien los valores.
 */
void RemV::Reset() {

    type->SetStart(nullptr);
    val->SetStart(nullptr);
    addr->SetStart(nullptr);
    refs->SetStart(nullptr);

    type->SetPosX(posx + 5);
    type->SetPosY(posy + 29);

    val->SetPosX(col1.getPosition().x + 5);
    val->SetPosY(posy + 30);

    addr->SetPosX(col2.getPosition().x + 5);
    addr->SetPosY(posy + 30);

    refs->SetPosX(col3.getPosition().x + 5);
    refs->SetPosY(posy + 29);


}

/**
 * @brief Asigna true o false para dibujar el texto o no, para evitar errores cuando la lista es nullptr.
 * @param flag
 */
void RemV::SetDrawt(bool flag) {

    drawt = flag;

}
