#include "GUI.h"
#include "TextBox.h"
#include "Button.h"

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
    font.loadFromFile("../Fonts/comic-sans-ms.ttf");

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

    sf::Text lines;
    int lnum = 1;
    lines.setString(std::string(std::to_string(lnum)));
    lines.setFont(font);
    lines.setCharacterSize(18);
    lines.setColor(sf::Color(255,255,255,255));
    lines.setPosition(40*0.333,45);


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
            }

            if (event.type == sf::Event::MouseMoved){
                mouse[0] = sf::Mouse::getPosition(window).x;
                mouse[1] = sf::Mouse::getPosition(window).y;
                runBtn.MouseOver(mouse[0],mouse[1]);
            }

            if (event.type == event.TextEntered) {
                if (codeA->isSelected()) {
                    if (event.text.unicode == 8) {
                        codeA->Delete();
                    } else if (event.text.unicode == 13) {
                        codeA->NewLine();
                        lnumstr += "\n";
                        lnum += 1;
                        lnumstr += std::to_string(lnum);
                    } else {
                        char letter = static_cast<char>(event.text.unicode);
                        codeA->Write(letter);
                    }
                }
            }
        }
        lines.setString(lnumstr);
        window.clear();
        codeA->Draw(winptr);
        window.draw(rect1);
        window.draw(RAMViewer);
        window.draw(lineSpace);
        runBtn.Draw(winptr);
        window.draw(lines);
        window.draw(ram);
        window.draw(num);
        window.display();
        //codeA->Draw(winptr);
    }
}
