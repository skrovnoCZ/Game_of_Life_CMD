#ifndef __GOL_ENGINE__
#define __GOL_ENGINE__

#include <iostream>
#include <vector>
//#include <ppl.h>
//#include <array>
//#include <sstream>
#include <string>
#include "keyboard_keys.h"

#define CELL_DEAD ' '
#define CELL_ALIVE (char)219
#define SCREEN_EDGE (char)177

class gol_engine
{
private:
    keyboard_keys m_keyboard;
    std::vector<std::string> m_gol_grid;
    std::vector<std::string> m_gol_grid_cache;
    std::vector<std::string> m_gol_grid_default;
    size_t m_cell_counter;
    size_t m_selector_x;
    size_t m_selector_y;
    bool m_editor_enabled;
public:
    gol_engine(size_t new_y, size_t new_x);
    void editor_enable();
    bool get_editor_status();
    void edit_grid_contents();
    void cell_scanner();
    void render_screen();
    void render_screen_parallel();
    ~gol_engine();
private:
    void grid_inicialise(); //on startup
    void gol_logic(size_t new_y, size_t new_x);
    void clear_screen();
    void load_sample_one();
};

#endif