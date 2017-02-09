#include "Juego.h"
#include "menu.h"
#include "Game_Over.h"
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;
int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SPACEWORD", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    menu m(window);
   m.loop();
  //Juego j(window);

 //j.loop();

    return 0;
}
