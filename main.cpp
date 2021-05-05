#include <SFML/Graphics.hpp>
#include <string>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "hello world!", sf::Style::Close | sf::Style::Titlebar);

    sf::RectangleShape cursor(sf::Vector2f(100.0f,100.0f));
    sf::Vector2f initialPosition((float)window.getSize().x/2.0f,(float)window.getSize().y/2.0f);
    cursor.setPosition(initialPosition);
    cursor.setOrigin(cursor.getSize()/2.0f);
    sf::Font segoeUI;
    if(!segoeUI.loadFromFile("Segoe UI.ttf"))
        return 0;
    sf::Text text("Hello SFML", segoeUI, 50);
    sf::Text display_CursorX("", segoeUI, 40);
    sf::Text display_CursorY("", segoeUI, 40);
    
    display_CursorX.setPosition(0.0f,100.0f);
    display_CursorY.setPosition(0.0f,140.0f);


    text.setPosition(cursor.getPosition());
    cursor.setFillColor(sf::Color(150,0,255));

    while(window.isOpen())
    {
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            text.setPosition((float)mousePos.x, (float)mousePos.y);
            cursor.setPosition((float)mousePos.x, (float)mousePos.y);
            
        }

        display_CursorX.setString("X: " + std::to_string((int)cursor.getPosition().x));
        display_CursorY.setString("Y: " + std::to_string((int)cursor.getPosition().y));

        window.clear();
        window.draw(cursor);
        window.draw(text);
        window.draw(display_CursorX);
        window.draw(display_CursorY);
        window.display();
    }

    return 0;
}