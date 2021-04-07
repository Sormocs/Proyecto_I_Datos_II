#include "GUI.h"
#include "TextBox.h"

GUI *GUI::instance = nullptr;

GUI::GUI() {}

GUI* GUI::getInstance() {
    if (instance == nullptr){
        instance = new GUI;
    }
    return instance;
}

void GUI::Run() {
    sf::RenderWindow window(sf::VideoMode(1550, 850), "C! IDE",sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2i centerwin((sf::VideoMode::getDesktopMode().width/2)-445,(sf::VideoMode::getDesktopMode().height/2)-480);
    window.setPosition(centerwin);
    float mouse[2] = {};
    sf::RenderWindow* winptr = &window;

    // (int fsize, sf::Color fontcolor, bool sel, int sizex, int sizey, int posx, int posy, sf::Color Bgcolor)
    TextBox *codeA = new TextBox(18,sf::Color::White,true,1150,550,40,60,sf::Color(128,128,128,255));

    sf::Font font;
    font.loadFromFile("../Fonts/comic-sans-ms.ttf");

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
                std::cout << "Click" << std::endl;
                codeA->CheckClick(mouse[0],mouse[1]);
            }

            if (event.type == event.TextEntered) {
                if (codeA->isSelected()) {
                    if (event.text.unicode == 8) {
                        codeA->Delete();
                    } else if (event.text.unicode == 13) {
                        codeA->NewLine();
                    } else {
                        std::cout << event.text.unicode << std::endl;
                        char letter = static_cast<char>(event.text.unicode);
                        codeA->Write(letter);
                    }
                }
            }
        }
        window.clear();
        Shapes(winptr);
        codeA->Draw(winptr);
        window.display();
    }
}

void GUI::Shapes(sf::RenderWindow* ptr) {
    sf::RectangleShape rect1(sf::Vector2f(1700.f,60.f));
    rect1.setPosition(0,0);
    rect1.setFillColor(sf::Color::Cyan);

    sf::RectangleShape writeArea(sf::Vector2f(1250,600));
    writeArea.setPosition(40,60);
    writeArea.setFillColor(sf::Color(128,128,128,255));

    ptr->draw(rect1);
}

