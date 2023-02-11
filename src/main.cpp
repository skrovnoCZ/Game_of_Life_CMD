#include <iostream>

#include "gol_engine.h"
#include "ConsoleColor.h"   //downloaded library

int main()
{
    keyboard_keys keyboard;
    size_t size_x = 25;
    size_t size_y = 25;

    std::cout << "!Recreation of 'Game of Life' by xkrivan5!\n\n";
    std::cout << "Controls:\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "E      -Enter editor.\n";
    std::cout << "ENTER  -Confirm and exit editor.      (in editor)\n";
    std::cout << "CTRL   -Place cell.                   (in editor)\n";
    std::cout << "ALT    -Remove cell.                  (in editor)\n";
    std::cout << "C      -Clear screen.                 (in editor)\n";
    std::cout << "UP     -Move up.                      (in editor)\n";
    std::cout << "DOWN   -Move down.                    (in editor)\n";
    std::cout << "LEFT   -Move left.                    (in editor)\n";
    std::cout << "RIGHT  -Move right.                   (in editor)\n";
    std::cout << "NUM_1  -Load sample 1.                (in editor)\n";
    std::cout << "ESC    -Exit game.\n";
    std::cout << "-------------------------------------------------\n\n";
    std::cout << "Set font in console config to 'Raster Font' and size '8x8' for best experience!!!\n\n";
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    std::cout << "!!!!!!" << red <<"CAUTION. FLASHING IMAGES" << white << "!!!!!!\n";
    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n";
    std::cout << "Set grid size (smaller is faster, bigger is slower. Optimal is 25x25).\n" << std::endl;
    std::cout << "X: ";
    std::cin >> size_x;
    std::cout << "\nY: ";
    std::cin >> size_y;
    std::cout << std::endl;

    gol_engine* p_game_of_life = new gol_engine(size_y, size_x);

    while (keyboard.get_key() != VK_ESCAPE) //game cycle
    {
        system("CLS");
        keyboard.reset_keys();
        keyboard.keyboard_key_e();
        keyboard.keyboard_key_esc();

        if (keyboard.get_key() == VK_L_E)
        {
            p_game_of_life->editor_enable();
        }

        while (p_game_of_life->get_editor_status()) //editor cycle
        {
            system("CLS");
            p_game_of_life->edit_grid_contents();
            p_game_of_life->render_screen();
        }

        if (!p_game_of_life->get_editor_status())   //if editor disabled then run gol behavior
        {
            p_game_of_life->cell_scanner();
        }

        p_game_of_life->render_screen();
    }

    delete p_game_of_life;
    p_game_of_life = nullptr;

    return 0;
}
