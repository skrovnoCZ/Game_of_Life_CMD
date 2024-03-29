#include "grid_screen.h"

grid_screen::grid_screen(size_t new_height, size_t new_width)
{
    for (size_t y = 0; y < new_height; y++)
    {
        for (size_t x = 0; x < new_width; x++)
        {
            if (!((y > 0) && (y < new_height - 1)))
            {
                m_grid += SYMBOL_EDGE;
            }
            else
            {
                if (!((x > 0) && (x < new_width - 1)))
                {
                    m_grid += SYMBOL_EDGE;
                }
                else
                {
                    m_grid += SYMBOL_NULL;
                }
            }
        }

        m_grid += "\n";
    }

    m_grid_cache = m_grid;
    m_width = new_width;
    m_height = new_height;
    m_render = true;
    m_rendered = false;
    m_shift_x = 0;
    m_shift_y = 0;
}

void grid_screen::set_point(int new_x, int new_y, char new_symbol)
{
    new_x += m_shift_x;
    new_y += m_shift_y;

    if ((new_x > 0) && (new_x < m_width - 1) && (new_y > 0) && (new_y < m_height - 1))
    {
        m_grid[str_coord_2d(new_x, (m_height - 1) - new_y, m_width)] = new_symbol;  //the reason for "(m_height - 1) - new_y" is to reverse y input
    }
#if 0
    else
    {
        log_output(LOG_TYPE_WARNING,
                   "Point set out of range at X: "+ std::to_string(new_x + 1)
                   + " Y: " + std::to_string(new_y + 1)
                   + ". Screen dimensions: Width " + "0-" + std::to_string(m_width - 1)
                   + ", Height: " + "0-" + std::to_string(m_height - 1));
    }
#endif
}

size_t grid_screen::get_width()
{
    return m_width;
}

size_t grid_screen::get_height()
{
    return m_height;
}

//universal for both windows and linux terminals
void grid_screen::print_grid()
{
#if 0
    if (m_render && !m_rendered)    //flip-flop to do "cout" every second time
    {
#ifdef __linux__ 
        system("clear");
#elif _WIN32
        //system("CLS");
        SetCursorPosition(0, 0);
#else
#endif

        std::cout << m_grid;
        m_render = false;
        m_rendered = true;
    }
    else if (!m_render && m_rendered)
    {
        m_render = true;
        m_rendered = false;
    }
#endif
    SetCursorPosition(0, 0);
    std::cout << m_grid;
}

void grid_screen::refresh_grid()
{
    m_grid = m_grid_cache;
}

void grid_screen::shift_x(int new_shift)
{
    m_shift_x += new_shift;
}

void grid_screen::shift_y(int new_shift)
{
    m_shift_y += new_shift;
}

void grid_screen::shift_reset()
{
    m_shift_x = 0;
    m_shift_y = 0;
}

void grid_screen::render_status_reset()
{
    m_render = true;
    m_rendered = false;
}

int grid_screen::get_shift_x()
{
    return m_shift_x;
}

int grid_screen::get_shift_y()
{
    return m_shift_y;
}

grid_screen::~grid_screen()
{
}

//this function is for calculating 2d input coordinates to 1d string
size_t grid_screen::str_coord_2d(size_t x, size_t y, size_t line_len)
{
    return ((line_len * y) + x + y);
}

void grid_screen::SetCursorPosition(char x, char y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}