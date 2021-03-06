/**
 * @file GUI.cpp
 * @author Sergio MB
 * @brief Definicion de metodos de la clase GUI.
 */

#include "GUI.h"

GUI *GUI::instance = nullptr;

/**
 * @brief Constructor de la clase GUI, existe para evitar la instanciacion
 */
GUI::GUI() {}

/**
 * @brief Retorna la instancia de GUI, ya que la calse es un singleton, solo hay una interfaz.
 * @return
 */
GUI* GUI::getInstance() {
    if (instance == nullptr){
        instance = new GUI;
    }
    return instance;
}

/**
 * @brief Metodo que se ejecuta como thread desde el main, ya que mantiene la ventana abierta y actualizando constantemente todos los componentes
 * dentro de esta. Revisa eventos, crea componentes y llama a los botones y cuadros de texto para asignarles sus valores o que realicen los procesos
 * que se soliciten segun los eventos que ocurran.
 */
void GUI::Run() {
    sf::RenderWindow window(sf::VideoMode(1550, 850), "AtomiC! IDE",sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin(0,0);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow* winptr = &window;

    // (int fsize, sf::Color fontcolor, bool sel, int sizex, int sizey, int posx, int posy, sf::Color Bgcolor)
    TextBox *tempA = new TextBox(18,sf::Color::White,true,1002,546,44,44,sf::Color(128,128,128,255));
    codeA = tempA;

    //BUTTONS:
    //Button(int Posx, int Posy, int Width, int Height,int Fsize ,std::string Text, sf::Color Color)
    sf::Color color = sf::Color(0,128,128,255);

    Button* temprunBtn = new Button(50,6,155,30,26,"Run C!ode",color);
    runBtn = temprunBtn;

    Button console = Button(1392,624,155,30,26,"Console",color);

    Button* tempclear = new Button(1392,587,155,30,26,"Clear",color);
    clearlog = tempclear;

    Button log = Button(1392,661,155,30,26,"Open Log",color);
    log.SetEnabled(false);

    Button* tempnext = new Button(210,6,155,30,26,"Next",color);
    next = tempnext;
    next->SetEnabled(false);

    Button* tempstop = new Button(370,6,155,30,26,"Stop",color);
    stop = tempstop;
    stop->SetEnabled(false);

    Button r_up = Button(1355,6,90,30,26,"UP",color);
    r_up.SetEnabled(false);
    Button r_down = Button(1450,6,90,30,26,"Down",color);
    r_down.SetEnabled(false);

    Button lc_up = Button(1456,776,90,30,26,"UP",color);
    lc_up.SetEnabled(false);
    Button lc_down = Button(1456,816,90,30,26,"Down",color);
    lc_down.SetEnabled(false);

    //LOG&CONSOLE:
    LogCons *tlc = new LogCons(0,580,1550,270);
    lc = tlc;

    //RAMVIEWER:
    RemV *remv = new RemV(1050,40,540,550, sf::Color(0,102,102,255));

    ramView = remv;

    //SHAPES:
    sf::RectangleShape rect1(sf::Vector2f(1700.f,40.f));
    rect1.setPosition(0,0);
    rect1.setFillColor(sf::Color(96,96,96,255));


    sf::RectangleShape lineSpace(sf::Vector2f(40,550));
    lineSpace.setPosition(0,40);
    lineSpace.setFillColor(sf::Color(0,102,102,255));

    //TEXTS:
    sf::Font font;
    font.loadFromFile("../Fonts/consolas.ttf");

    sf::Text ram;
    ram.setString("RAM Live Viewer");
    ram.setFont(font);
    ram.setCharacterSize(24);
    ram.setColor(sf::Color(255,255,255,255));
    ram.setPosition(1010+540*0.333-40,6);

    sf::Text num;
    num.setString("#");
    num.setFont(font);
    num.setCharacterSize(24);
    num.setColor(sf::Color(255,255,255,255));
    num.setPosition(40*0.333,6);

    //IMAGES
    sf::Texture image;
    image.loadFromFile("../Imagenes/ram.png");
    sf::Sprite img;
    img.setTexture(image);
    img.setPosition(sf::Vector2f(1010+540*0.333-74.f,3.f));


    while (window.isOpen()) {

    if (ramView->GetLimit()) {
        r_up.SetEnabled(true);
        r_down.SetEnabled(true);
    }

    if (lc->IsLimit()) {
        lc_up.SetEnabled(true);
        lc_down.SetEnabled(true);
    }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased){
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;
                if (!isRunning) codeA->CheckClick(mouse[0],mouse[1]);
                if (runBtn->Clicked(mouse[0],mouse[1])){

                    //CODE FOR THE RUN BUTTON

                    if (codeA->GetCode()->GetStart()->getVal()->getString() != ""){
                        codeA->CheckClick(0,0);
                        isRunning = true;
                        remv->Reset();

                        next->SetEnabled(true);
                        stop->SetEnabled(true);
                        clearlog->SetEnabled(false);
                        runBtn->SetEnabled(false);

                        lc->Reset();
                        console.SetEnabled(true);
                        log.SetEnabled(false);
                        lc->AddLog("Sending...");

                        Line* temp = codeA->GetCode()->GetStart()->getNext();
                        while (temp != nullptr){
                            
                            Client::getInstance()->Send("FULL"+temp->getVal()->getString() + "\n");
                            temp = temp->getNext();

                        }

                        if (!codeA->GetCode()->SendTxT()){
                            next->SetEnabled(false);
                            stop->SetEnabled(false);
                            clearlog->SetEnabled(true);
                            runBtn->SetEnabled(true);
                            lc->AddLog("Finished");
                            isRunning = false;
                        }
                        lc->AddLog("Sent");

                        if (lc->IsCons()){
                            lc->Switch();
                            console.SetEnabled(false);
                            log.SetEnabled(true);
                        }
                    }
                } else if (console.Clicked(mouse[0],mouse[1])) {

                    lc->Switch();
                    console.SetEnabled(false);
                    log.SetEnabled(true);

                } else if(log.Clicked(mouse[0],mouse[1])){

                    lc->Switch();
                    console.SetEnabled(true);
                    log.SetEnabled(false);

                } else if (clearlog->Clicked(mouse[0],mouse[1])){

                    lc->Reset();
                    lc_up.SetEnabled(false);
                    lc_down.SetEnabled(false);

                } else if (stop->Clicked(mouse[0],mouse[1])){

                    Stop();
                    Client::getInstance()->Send("STOP");

                } else if (next->Clicked(mouse[0],mouse[1])){

                    if (!codeA->GetCode()->SendTxT()){
                        next->SetEnabled(false);
                        stop->SetEnabled(false);
                        clearlog->SetEnabled(true);
                        runBtn->SetEnabled(true);
                        lc->AddLog("Finished");
                        isRunning = false;
                    }
                    lc->AddLog("Sent");
                } else if (lc_up.Clicked(mouse[0],mouse[1])){

                    lc->GetCurrent()->Move("up");

                } else if (lc_down.Clicked(mouse[0],mouse[1])){

                    lc->GetCurrent()->Move("DOWN");

                }
            }

            if (event.type == sf::Event::MouseMoved){
                runBtn->MouseOver(mouse[0],mouse[1]);
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;
                next->MouseOver(mouse[0],mouse[1]);
                stop->MouseOver(mouse[0],mouse[1]);
                console.MouseOver(mouse[0],mouse[1]);
                log.MouseOver(mouse[0],mouse[1]);
                clearlog->MouseOver(mouse[0],mouse[1]);
                lc_up.MouseOver(mouse[0],mouse[1]);
                lc_down.MouseOver(mouse[0],mouse[1]);

            }

            if (event.type == event.TextEntered) {
                if (codeA->isSelected()) {
                    if (event.text.unicode == 8) {
                        codeA->Delete();
                    } else if (event.text.unicode == 13) {
                        codeA->NewLine();

                    } else {
                        char letter = static_cast<char>(event.text.unicode);
                        codeA->Write(letter);
                    }
                }
            }
        }

        window.clear();
        codeA->Draw(winptr);
        window.draw(rect1);
        ramView->Draw(winptr);
        window.draw(lineSpace);
        runBtn->Draw(winptr);
        next->Draw(winptr);
        stop->Draw(winptr);
        codeA->DrawLines(winptr);
        window.draw(ram);
        window.draw(num);
        lc->Draw(winptr);
        console.Draw(winptr);
        log.Draw(winptr);
        clearlog->Draw(winptr);
        window.draw(img);

        r_up.Draw(winptr);
        r_down.Draw(winptr);
        lc_up.Draw(winptr);
        lc_down.Draw(winptr);

        window.display();
    }
    exit(0);
}

/**
 * @brief Obtiene el visor de ram, funciona como puente para que el cliente lo acceda.
 * @return
 */
RemV *GUI::GetRamV() {

    return ramView;

}
/**
 * @brief Obtiene el log y la consola, funciona como puente para que el cliente lo acceda.
 * @return
 */
LogCons *GUI::GetLogCons() {
    return lc;
}

void GUI::Stop() {

    next->SetEnabled(false);
    stop->SetEnabled(false);
    clearlog->SetEnabled(true);
    runBtn->SetEnabled(true);
    isRunning = false;
    codeA->GetCode()->ResetToSend();

}
