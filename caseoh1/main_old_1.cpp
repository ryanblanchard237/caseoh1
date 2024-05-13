// gaphics   DONE
// window
// audio     DONE
// network   DONE
// system    DONE

// a b c d e f g h i j k lmnop q r s t u v w x y z
// audio
//             graphics
//                        network
//                                 system
//                                        window

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Network.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

int main_old_1(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "project 1");
	sf::CircleShape circle1(100.f);
	circle1.setFillColor(sf::Color::Green);

	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();
		window.draw(circle1);
		window.display();
	}

	return 0;
}

//1>main.obj : error LNK2019: unresolved external symbol "__declspec(dllimport) public: __cdecl sf::String::String(char const *,class std::locale const &)" (__imp_??0String@sf@@QEAA@PEBDAEBVlocale@std@@@Z) referenced in function main
//warning LNK4272: library machine type 'x86' conflicts with target machine type 'x64'