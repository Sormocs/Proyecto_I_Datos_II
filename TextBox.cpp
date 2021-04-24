/**
 * @file TextBox.cpp
 * @author Sergio MB
 * @brief Definicion de los metodos para que el TextBox funcione.
 */

#include "TextBox.h"
#include "CodeTxT.h"

/**
 * @brief Constructor de la clase TextBox, el cual llama al metodo build para generar figura y texto necesarios para que se muestre
 * luego en pantalla como se espera.
 * @param fsize
 * @param fontColor
 * @param sel
 * @param Sizex
 * @param Sizey
 * @param Posx
 * @param Posy
 * @param Bgcolor
 */
TextBox::TextBox(int fsize, sf::Color fontColor, bool sel, int Sizex, int Sizey, int Posx, int Posy, sf::Color Bgcolor) {

    fontsize = fsize;
    sizex = Sizex;
    sizey = Sizey;
    posx = Posx;
    posy = Posy;
    selected = sel;
    bgcolor = Bgcolor;
    fontcolor = fontColor;

    indx = posx + 7;
    indy = posy + 10;
    xlimit = posx + sizex;
    ylimit = posy + sizey;

    Build();

}
/**
 * @brief Metodo build, el cual genera los objetos de texto, asi como el area del cuadro que luego se van actualizando
 * conforme se escribe codigo.
 */
void TextBox::Build() {

    sf::RectangleShape box(sf::Vector2f(sizex,sizey));
    box.setPosition(posx,posy);
    box.setFillColor(sf::Color(bgcolor));

    if (selected){
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);
    } else{
        box.setOutlineColor(sf::Color(255,255,255,0));
    }

    this->box = box;

    sf::RectangleShape ind(sf::Vector2f(7,15));
    ind.setPosition(indx,indy);
    ind.setFillColor(sf::Color::White);

    this->tInd = ind;

    CodeTxT *lineList = new CodeTxT();
    code = lineList;
    code->SetPosX(posx + 5);
    code->SetPosY(posy + 5);
    code->Insert("");
    current = code->GetStart();
    currLine = current->getLine();

    CodeTxT *count = new CodeTxT();
    lineC = count;
    lineC->SetPosY(posy + 5);
    lineC->SetPosX(40*0.333);
    lineC->Insert(std::to_string(currLine));

}

/**
 * @brief Metodo que se llama en el while de la ventana principal, se encarga de dibujar el texto de cada elemento en la
 * lista que contiene cada linea que se ha escrito, recibe un puntero hacia la ventana principal para acceder a esta y
 * dibujar las figuras del textbox.
 * @param win
 */
void TextBox::Draw(sf::RenderWindow* win) {

    win->draw(box);

    if (selected) {
        tInd.setPosition(indx, indy);
        win->draw(tInd);
    }
    Line *current = code->GetStart();
    while (current != nullptr){
        sf::Text *todraw = current->getVal();
        win->draw(*todraw);
        current = current->getNext();
    }
//    txtbox.setString(text);
//    win->draw(txtbox);
}

/**
 * @brief Al igual que el draw recibe el puntero para colocar elementos en la ventana principal, nada mas que esta se encarga de
 * colocar solamente los numeros de linea fuera del area del cuadro de texto.
 * @param win
 */
void TextBox::DrawLines(sf::RenderWindow *win) {

    Line *current = lineC->GetStart();
    while (current != nullptr){
        sf::Text *todraw = current->getVal();
        win->draw(*todraw);
        current = current->getNext();
    }

}

/**
 * @brief Metodo para verificar si esta seleccionado el cuadro de texto.
 * @return true o false segun el caso.
 */
bool TextBox::isSelected() {
    return selected;
}

/**
 * @brief Revisa el si el click se dio dentro del area del cuadro para seleccionarlo o deseleccionarlo. Recibe la posicion del click.
 * @param x
 * @param y
 */
void TextBox::CheckClick(float x, float y) {
    if (posx < x && x < posx + sizex && posy < y && y < posy + sizey){
        selected = true;
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(4);

    } else{
        selected = false;
        box.setOutlineColor(sf::Color(255,255,255,0));

    }
}

/**
 * @brief Actualiza el texto segun lo que se vaya introduciendo, recibe el valor para agregar al texto, si lo que agrega supera
 * el limite horizontal, entonces crea una nueva linea para ahi dibujar el nuevo caracter.
 * @param val
 */
void TextBox::Write(char val) {
    if (posx + current->getVal()->getLocalBounds().width <= xlimit) {
        std::string character = std::string(1, val);
        std::string valstr = current->getVal()->getString();
        valstr += character;
        current->SetStr(valstr);
        indx = posx + 14 + current->getVal()->getLocalBounds().width - 2;
    } else{
        NewLine();
    }
}

/**
 * @brief Retrocede en la lista de las lineas del codigo para modificar la anterior, no elimina la actual y la deja en espera
 * para una posible modificacion futura.
 */
void TextBox::Delete() {

    if (current->getVal()->getString() == "" && current != code->GetStart()){

        if (code->GetStart()->getVal()->getPosition().y > posy) {
            currLine--;
            current = GetCurrent();
            indy -= 24;
        } else {
            lineC->Move("down");
            code->Move("down");
            currLine--;
            current = GetCurrent();
        }
        indx = posx + 14 + current->getVal()->getLocalBounds().width -2;

    } else if (current->getVal()->getString() != ""){
        std::string text = current->getVal()->getString();
        text.erase(text.end() - 1, text.end());
        current->getVal()->setString(text);
        indx = posx + 14 + current->getVal()->getLocalBounds().width -2;
    }
}

/**
 * @brief Metodo que crea una nueva linea en la lista code, creando un nuevo "nodo" dentro de la misma y aumenta el
 * numero de lineas, ademas de modificar las posiciones dentro de la lista para futuras inserciones.
 */
void TextBox::NewLine() {

    if (current->getNext() == nullptr && code->GetY()+48 < ylimit) {
        code->SetPosY(code->GetY() + 24);
        lineC->SetPosY(lineC->GetY()+24);
        code->Insert("");
        currLine++;
        lineC->Insert(std::to_string(currLine));
        current = GetCurrent();
        indy += 24;
    } else if (current->getNext() == nullptr && code->GetY()+48 > ylimit){
        code->Move("up");
        lineC->Move("up");
        code->Insert("");
        currLine++;
        lineC->Insert(std::to_string(currLine));
        current = GetCurrent();
        std::cout << "currLine: " << currLine << std::endl;
    } else {
        currLine++;
        current = GetCurrent();
        indy += 24;
    }
    indx = posx + 7;

}

/**
 * @brief Metodo que retorna la linea actual en la que se encuentra la persona.
 * @return
 */
Line* TextBox::GetCurrent() {
    Line *temp = code->GetStart();
    while (temp != nullptr){
        if (temp->getLine() == currLine){
            break;
        }
        temp = temp->getNext();
    }
    return temp;
}

/**
 * @brief Metodo que retorna la lista que contiene las lineas del codigo.
 * @return lista con lineas del codigo.
 */
CodeTxT* TextBox::GetCode() {
    return code;
}


