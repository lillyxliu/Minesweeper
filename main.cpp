#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

// source: from instructions:
void setText(sf::Text &text,float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top + textRect.height/2.0f);
    text.setPosition(x,y);
}

sf::Text printText(string msg, sf::Font font, int size,sf::Color color_, float x, float y, bool bold, bool underline) {
    sf::Text text(msg, font, size);
    text.setFillColor(color_);
    if (bold && underline) {
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }
    if (bold) {
        text.setStyle(sf::Text::Bold);
    }
    if (underline) {
        text.setStyle(sf::Text::Underlined);
    }
    setText(text, x, y);
    return text;
}

// source: example
string toCamalCase(const string& str) {
    string result = str;
    result[0] = toupper(result[0]);
    for (int i = 1; i<str.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

int gameWindow(){
    int width = 800, height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "Game Window", sf::Style::Close);
    window.display();

    sf::Font font;
    if (!font.loadFromFile("files/font.ttf")) {
        cout << "Failed to load font" << endl;
        return -1;
    }

    sf::Text titleText("This is the Game Window!", font, 24);
    titleText.setFillColor(sf::Color::Black);
    titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    setText(titleText, width/2, height/2-150);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(titleText);
        window.display();
    }
    return 0;
}



int renderStart() {
    int width = 800, height = 600;
    sf::RenderWindow window(sf::VideoMode(width, height), "Start Window", sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("files/font.ttf")) {
        cout << "Failed to load font" << endl;
        return -1;
    }

    sf::Text titleText("WELCOME TO MINESWEEPER", font, 24);
    titleText.setFillColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold | sf::Text::Underlined);
    setText(titleText, width/2, height/2-150);

    sf::Text nameText("Enter your name.", font, 20);
    nameText.setFillColor(sf::Color::White);
    nameText.setStyle(sf::Text::Bold);
    setText(nameText, width/2, height/2-75);

    sf::Text userText("", font, 20);
    userText.setFillColor(sf::Color::White);
    userText.setStyle(sf::Text::Bold);
    setText(userText, width/2, height/2-45);

    string playerName;

   // sf::Text titleText = printText("WELCOME TO MINESWEEPER", font,24,sf::Color::White, width/2,height/2-150,true,true);
    bool flip;
    int counter = 0;
    while(window.isOpen()) {
        window.draw(userText);
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            // source: example
            if (event.type == sf::Event::TextEntered ) {
                // Handle backspace key
                if (event.text.unicode == 8) { // 8 is the ASCII code for backspace
                    if (!playerName.empty()) {
                        playerName.pop_back();
                        userText.setString(playerName);
                        setText(userText, width/2, height/2-45);
                    }
                } else if (event.text.unicode < 128 & playerName.length()<=11 ) {
                    char enteredChar = static_cast<char>(event.text.unicode);
                    if (std::isalpha(enteredChar)) {
                        playerName += enteredChar;
                        userText.setString(playerName);
                        setText(userText, width/2, height/2-45);
                    }
                }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) ) {
                    if (playerName.length()>0){
                        cout << "test";
                        window.close();
                        gameWindow();
                    }
                }
            }
        }
        string camelcaseName = toCamalCase(playerName);

        if (flip) {
            string finalString = camelcaseName + "|" ;
            userText.setString(finalString);
            counter++;
        }else {
            string finalString = camelcaseName ;
            userText.setString(finalString);
            counter--;
        }
        if (counter>2000) {
            flip = false;
        }
        if (counter<0) {
            flip = true;
        }


        window.clear(sf::Color::Blue);
        window.draw(titleText);
        window.draw(nameText);
        window.draw(userText);
        window.display();
    }
    return 0;
}


int main() {
  // //  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");
  //   sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::Close);
  //  // sf:RenderTarget::clear(const color & color = sf::Color::Black);
  //   window.clear(sf::Color::Blue);
  //   sf::CircleShape shape(100.f);
  //   shape.setFillColor(sf::Color::Red);
  //
  //   // create graphial text:
  //
  //
  //   while(window.isOpen()) {
  //       sf::Event event;
  //       while(window.pollEvent(event)) {
  //           if(event.type == sf::Event::Closed) {
  //               window.close();
  //           }
  //       }
  //
  //       window.clear(sf::Color::Blue);
  //       window.draw(shape);
  //       window.display();
  //   }
  //   return 0;
  //  renderStart();
    renderStart();
    return 0;
}
