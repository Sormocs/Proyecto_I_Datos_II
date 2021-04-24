#include "GUI.h"
#include "TextBox.h"
#include "Button.h"
#include "LogCons.h"

GUI *GUI::instance = nullptr;

GUI::GUI() {}

GUI* GUI::getInstance() {
    if (instance == nullptr){
        instance = new GUI;
    }
    return instance;
}

void GUI::Run() {
    sf::RenderWindow window(sf::VideoMode(1550, 850), "AtomiC! IDE",sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin(0,0);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow* winptr = &window;

    // (int fsize, sf::Color fontcolor, bool sel, int sizex, int sizey, int posx, int posy, sf::Color Bgcolor)
    TextBox *codeA = new TextBox(18,sf::Color::White,true,1142,546,44,44,sf::Color(128,128,128,255));

    //BUTTONS:
    //Button(int Posx, int Posy, int Width, int Height,int Fsize ,std::string Text, sf::Color Color)
    Button runBtn = Button(50,6,155,30,26,"Run C!ode",sf::Color(0,128,128,255));
    Button console = Button(1392,624,155,30,26,"Console",sf::Color(0,128,128,255));
    Button log = Button(1392,661,155,30,26,"Open Log",sf::Color(0,128,128,255));

    //LOG&CONSOLE:
    LogCons lc = LogCons(0,580,1550,270);

    //SHAPES:
    sf::RectangleShape rect1(sf::Vector2f(1700.f,40.f));
    rect1.setPosition(0,0);
    rect1.setFillColor(sf::Color(96,96,96,255));

    sf::RectangleShape RAMViewer(sf::Vector2f(400, 550));
    RAMViewer.setPosition(1190, 40);
    RAMViewer.setFillColor(sf::Color(0, 102, 102, 255));

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
    ram.setPosition(1150+400*0.333,6);

    sf::Text num;
    num.setString("#");
    num.setFont(font);
    num.setCharacterSize(24);
    num.setColor(sf::Color(255,255,255,255));
    num.setPosition(40*0.333,6);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonReleased){
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;
                codeA->CheckClick(mouse[0],mouse[1]);
                if (runBtn.Clicked(mouse[0],mouse[1])){

                    //CODE FOR THE RUN BUTTON
                    codeA->GetCode()->CoutCode();
                    if (codeA->GetCode()->GetStart()->getVal()->getString() != ""){
                        codeA->GetCode()->SendTxT();
                    }
                } else if (console.Clicked(mouse[0],mouse[1]) or log.Clicked(mouse[0],mouse[1])) {
                    lc.Switch();
                }
            }

            if (event.type == sf::Event::MouseMoved){
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;
                runBtn.MouseOver(mouse[0],mouse[1]);
                console.MouseOver(mouse[0],mouse[1]);
                log.MouseOver(mouse[0],mouse[1]);
            }

            if (event.type == event.TextEntered) {
                if (codeA->isSelected()) {
                    if (event.text.unicode == 8) {
                        codeA->Delete();
                    } else if (event.text.unicode == 13) {
                        codeA->NewLine();
                        //lnumstr += "\n";
                        //lnum += 1;
                        //lnumstr += std::to_string(lnum);
                    } else {
                        char letter = static_cast<char>(event.text.unicode);
                        codeA->Write(letter);
                    }
                }
            }
        }
        //lines.setString(lnumstr);
        window.clear();
        codeA->Draw(winptr);
        window.draw(rect1);
        window.draw(RAMViewer);
        window.draw(lineSpace);
        runBtn.Draw(winptr);
        codeA->DrawLines(winptr);
        //window.draw(lines);
        window.draw(ram);
        window.draw(num);
        lc.Draw(winptr);
        console.Draw(winptr);
        log.Draw(winptr);

        window.display();
        //codeA->Draw(winptr);
    }
}
