/**
 * @file LogCons.h
 * @author Sergio MB
 * @brief Definicion de metodos de la clase LogCons
 */
#include "LogCons.h"

/**
 * @brief Constructor de la clase que asigna posicion y valores segun lo recibido.
 * @param Posx
 * @param Posy
 * @param Width
 * @param Height
 */
LogCons::LogCons(int Posx, int Posy, int Width, int Height) {

    posx = Posx;
    posy = Posy;
    width = Width;
    height = Height;
    isCons = false;
    title = "Log";

    Build();

}
/**
 * @brief Metodo que construye los objetos que utiliza la clase y les asigna sus valores iniciales.
 */
void LogCons::Build() {

    sf::RectangleShape tempS(sf::Vector2f(width,height));
    tempS.setPosition(posx,posy);
    tempS.setFillColor(sf::Color(64,64,64,255));

    this->box = tempS;

    sf::RectangleShape tempL(sf::Vector2f(1550,5));
    tempL.setPosition(0,posy + 34);
    tempL.setFillColor(sf::Color(230,230,230,255));

    l = tempL;

    font.loadFromFile("../Fonts/comic-sans-ms.ttf");

    sftitle.setFont(font);
    sftitle.setCharacterSize(22);
    sftitle.setColor(sf::Color(255,255,255,255));
    sftitle.setString(title);
    sftitle.setPosition(posx + 15, posy + 5);


    CodeTxT *templog = new CodeTxT;
    logTxT = templog;
    logTxT->SetPosX(15);
    logTxT->SetPosY(posy + 45);
    logTxT->Insert("Welcome to C!");

    current = logTxT;

    CodeTxT *tempcons = new CodeTxT;
    consTxT = tempcons;
    consTxT->SetPosX(15);
    consTxT->SetPosY(posy + 45);
    consTxT->Insert("Console Output:");

}
/**
 * @brief Metodo draw que se encarga de dibujar los componentes en la interfaz, recibe un puntero a la ventana para dibujar en ella.
 * @param win
 */
void LogCons::Draw(sf::RenderWindow *win) {

    win->draw(box);
    win->draw(sftitle);
    win->draw(l);

    if (isCons){
        //win->draw(consTxt);
    } else {
        //win->draw(logTxt);
    }
    Line *temp = current->GetStart();
    while (temp != nullptr){
        sf::Text *todraw = temp->getVal();
        win->draw(*todraw);
        temp = temp->getNext();
    }
}

/**
 * @brief Metodo switch que se encarga de cambiar entre log y consola.
 */
void LogCons::Switch() {
    if (isCons){
        title = "Log";
        isCons = false;
        current = logTxT;
    } else {
        title = "Console";
        isCons = true;
        current = consTxT;
    }
    sftitle.setString(title);
}

/**
 * @brief Agrega el texto que recibe a la consola
 * @param msg
 */
void LogCons::AddCons(std::string msg) {

    cons = msg;
    cons += "\n";
    consTxT->Insert(cons);

}

/**
 * @brief Agrega el texto que recibe al log.
 * @param msg
 */
void LogCons::AddLog(std::string msg) {

    log = msg;
    log += "\n";
    logTxT->SetPosY(logTxT->GetY()+24);
    logTxT->Insert(log);

}

/**
 * @brief Resetea la consola y el log a sus valores iniciales.
 */
void LogCons::Reset(){

    CodeTxT *templog = new CodeTxT;
    logTxT = templog;
    logTxT->SetPosX(15);
    logTxT->SetPosY(posy + 45);
    logTxT->Insert("Run C!");

    current = logTxT;

    CodeTxT *tempcons = new CodeTxT;
    consTxT = tempcons;
    consTxT->SetPosX(15);
    consTxT->SetPosY(posy + 45);
    consTxT->Insert("Console Output:");

}

bool LogCons::IsCons() {

    return isCons;

}
