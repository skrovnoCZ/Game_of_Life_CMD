/*
*   This is a universal library for printing values to console.
*   
*
*/

#ifndef __GRID_SCREEN__
#define __GRID_SCREEN__

#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>

#define SYMBOL_EDGE (char)219
#define SYMBOL_DET (char)177
#define SYMBOL_POINT 'X'
#define SYMBOL_CIRCLE 'O'
#define SYMBOL_NULL ' '

class grid_screen
{
private:
    std::string m_grid;
    std::string m_grid_cache;
    size_t m_width;
    size_t m_height;
    bool m_render;
    bool m_rendered;
    int m_shift_x;
    int m_shift_y;
public:
    grid_screen(size_t new_height, size_t new_width);
    void set_point(int new_x, int new_y, char new_symbol);
    size_t get_width();
    size_t get_height();
    void print_grid();
    void refresh_grid();
    void shift_x(int new_shift);
    void shift_y(int new_shift);
    int get_shift_x();
    int get_shift_y();
    void shift_reset();
    void render_status_reset();
    ~grid_screen();
private:
    size_t str_coord_2d(size_t x, size_t y, size_t line_len);
    void SetCursorPosition(char x, char y);
};

#endif