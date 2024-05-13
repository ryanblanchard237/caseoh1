
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

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>

#include <iostream>

// #include <winnt.h>
// #include <WinUser.h>
// 
// void initialize_window(sf::Window* main_window_funcvar)
// {
//     int full_screen_window_width  = GetSystemMetrics(SM_CXFULLSCREEN);
//     int full_screen_window_height = GetSystemMetrics(SM_CYFULLSCREEN);
// 
//     int chosen_window_width  = full_screen_window_width * 0.8;
//     int chosen_window_height = full_screen_window_height * 0.8;
// 
//     (*main_window_funcvar).setSize(sf::Vector2u(full_screen_window_width, full_screen_window_height));
// 
//     (*main_window_funcvar).create(sf::VideoMode(chosen_window_width, chosen_window_height), "CaseOh dietary regimen");
// 
//     // Alright this didn't work very well.
// }

void initialize_caseoh_sprite(
    sf::Texture* caseoh_texture_funcvar,
    sf::Sprite* caseoh_sprite_funcvar,
    sf::Window* main_window_funcvar)
{
    caseoh_texture_funcvar->loadFromFile(".\\images\\caseoh\\caseoh_fanart_____by_peepeesuckerz_dgmzus5-414w--25percent.jpg");
    (*caseoh_sprite_funcvar).setTexture(*caseoh_texture_funcvar);

    //debug
    sf::FloatRect caseoh_bounds = (*caseoh_sprite_funcvar).getLocalBounds();
    std::cout << "caseoh is " << caseoh_bounds.width << " x " << caseoh_bounds.height;
    // Got me 103x72.
    
    float upper_left_x = (*main_window_funcvar).getSize().x/2 - (*caseoh_sprite_funcvar).getLocalBounds().width/2;
    float upper_left_y = (*main_window_funcvar).getSize().y/2 - (*caseoh_sprite_funcvar).getLocalBounds().height/2;
    (*caseoh_sprite_funcvar).setPosition(upper_left_x,upper_left_y);
}

int main(int argc, char** argv)
{
    //sf::RenderWindow main_window;
    //initialize_window(&main_window);
    // This didnt' work very well.

    sf::RenderWindow main_window(sf::VideoMode(1280, 720), "SFML works!");
    main_window.setVerticalSyncEnabled(true);
    // Can I set the sf::RenderWindow size by detecting the computer's display size?
    // -- Google: "c++ windows get display size".
    // -- https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsystemmetrics
    //    Microsft Learn > Windows > Apps > Win32 > API > Windows and Messages > Winuser.h > GetSystemMetrics function.
    //    
    //    int GetSystemMetrics(int nIndex);
    //    And there is a big ol table of all the things that you can give "GetSystemMetrics()" for nIndex.
    //    SM_CYFULLSCREEN: "The height of the client area for a full-screen window on the primary display monitor, in pixels.
    //                      To get the coordinates of the portion of the screen not obscured by the system taskbar or by application desktop toolbars,
    //                      call the SystemParametersInfo function with the SPI_GETWORKAREA value."
    //    SM_CXFULLSCREEN: "The width of the client area for a ..."
    //                     "To get..."
    //                     "call the SystemParametersInfo function with the SPI_GETWORKAREA value."
    //
    // This didnt work very well.
    //
    // Think ill just try half of 2560 x 1440.
    //                              30     20
    //                            1250    700
    //                            1280 x  720
    // Looks good.
    // May-13 1:20 am.

    sf::Texture caseoh_texture;
    sf::Sprite caseoh_sprite;
    initialize_caseoh_sprite(&caseoh_texture, &caseoh_sprite, &main_window);

    while (main_window.isOpen())
    {
        sf::Event window_event;
        while (main_window.pollEvent(window_event))
        {
            switch(window_event.type)
            {
                case sf::Event::Closed:{
                    main_window.close();
                }
                break;

                case sf::Event::KeyPressed:{
                    switch(window_event.key.scancode){
                        default:
                            break;
                    }
                }
                break;
                
                case sf::Event::KeyReleased:{
                    switch(window_event.key.scancode){
                        default:
                            break;
                    }
                }
                break;

                default:
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
            ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            caseoh_sprite.move(-10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
            ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            caseoh_sprite.move(+10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
            ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            caseoh_sprite.move(0, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            caseoh_sprite.move(0, +10);
        }
        // Time 0138: this works.
        // The speed of motion is *extremely* dependent on the framerate.
        // If I do not set vertical sync enabled on main_window, he moves real fast. (And my GPU is at 100% use, and CPU use like 15%.)
        // If I do     set vertical sync enabled,
        // -- case moves much slower.
        // -- pc power usage is lower.
        //    (Like 12% gpu use
        //           4% cpu use.)
        //
        // +---------------------------+
        // | Vertical sync     OFF   ON |
        // | CPU use %          15    4 |
        // | Graphics use %    100   12 |
        // +---------------------------+

        main_window.clear();
        main_window.draw(caseoh_sprite);
        main_window.display();
    }

    return 0;
}

// 2024-05-12  8:33pm
// HECK YEAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH