#include "gol_engine.h"



gol_engine::gol_engine(size_t new_y, size_t new_x)
{
    m_editor_enabled = false;
    m_selector_x = new_x / 2;
    m_selector_y = new_y / 2;
    m_cell_counter = 0;
    std::string vector_line(new_x, CELL_DEAD);
    std::vector<std::string> vector_inicialise(new_y, vector_line);
    m_gol_grid = vector_inicialise;
    m_gol_grid_cache = m_gol_grid;
    grid_inicialise();
}

void gol_engine::editor_enable()
{
    m_editor_enabled = true;
}

bool gol_engine::get_editor_status()
{
    return m_editor_enabled;
}

void gol_engine::edit_grid_contents()   //game grid editor
{
    m_keyboard.keyboard_key_up();
    m_keyboard.keyboard_key_down();
    m_keyboard.keyboard_key_left();
    m_keyboard.keyboard_key_right();
    m_keyboard.keyboard_key_num1();
    m_keyboard.keyboard_key_ctrl();
    m_keyboard.keyboard_key_alt();
    m_keyboard.keyboard_key_c();
    m_keyboard.keyboard_key_enter();

    switch (m_keyboard.get_key())
    {
    case VK_UP:
        if ((m_selector_y - 1) > 0)
        {
            m_selector_y--;
        }
        break;
    case VK_DOWN:
        if ((m_selector_y + 1) < m_gol_grid.size() - 1)
        {
            m_selector_y++;
        }
        break;
    case VK_LEFT:
        if ((m_selector_x - 1) > 0)
        {
            m_selector_x--;
        }
        break;
    case VK_RIGHT:
        if ((m_selector_x + 1) < m_gol_grid.at(m_selector_y).size() - 1)
        {
            m_selector_x++;
        }
        break;
    case VK_MENU:   //alt
        m_gol_grid[m_selector_y][m_selector_x] = CELL_DEAD;
        m_gol_grid_cache = m_gol_grid;
        break;
    case VK_CONTROL:
        m_gol_grid[m_selector_y][m_selector_x] = CELL_ALIVE;
        m_gol_grid_cache = m_gol_grid;
        break;
    case VK_RETURN: //enter
        m_editor_enabled = false;
        break;
    case VK_L_C:
        clear_screen();
        break;
    case VK_NUMPAD1:
        clear_screen();
        load_sample_one();
        m_gol_grid_cache = m_gol_grid;
        break;
    //case VK_NUMPAD2:
        //clear_screen();
        //load_sample_two();
        //m_gol_grid_cache = m_gol_grid;
        //break;
    default:
        break;
    }

    m_keyboard.reset_keys();
}

void gol_engine::render_screen()
{
    for (size_t y = 0; y < m_gol_grid.size(); y++)
    {
        if (m_editor_enabled)
        {
            for (size_t x = 0; x < m_gol_grid.at(y).size(); x++)
            {
                if ((y == m_selector_y) && (x == m_selector_x))
                {
                    std::cout << '*';
                }
                else
                {
                    std::cout << m_gol_grid.at(y).at(x);    //TODO: fix slow rendering
                }
            }
        }
        else
        {
            std::cout << m_gol_grid.at(y);
        }

        std::cout << std::endl;
    }
}



void gol_engine::render_screen_parallel()
{
    /*
    parallel_for (size_t(0), 5, [&](size_t i)
    {
        for (size_t i = 0; i < length; i++)
        {

        }
    });
    */
}

void gol_engine::clear_screen()
{
    m_gol_grid = m_gol_grid_default;
    m_gol_grid_cache = m_gol_grid_default;
}

void gol_engine::grid_inicialise()
{
    for (size_t y = 0; y < m_gol_grid.size(); y++)
    {
        for (size_t x = 0; x < m_gol_grid.at(y).size(); x++)
        {
            if (!((y > 0) && (y < m_gol_grid.size() - 1)))
            {
                m_gol_grid[y][x] = SCREEN_EDGE; //fill screen edge with SCREEN_EDGE symbols
            }
            else
            {
                if (!((x > 0) && (x < m_gol_grid.at(y).size() - 1)))
                {
                    m_gol_grid[y][x] = SCREEN_EDGE; //fill screen edge with SCREEN_EDGE symbols
                }
            }
        }
    }

    m_gol_grid_cache = m_gol_grid;
    m_gol_grid_default = m_gol_grid;
}

void gol_engine::cell_scanner() //cell scanner one by one
{
    for (size_t y = 1; y < m_gol_grid.size() - 1; y++)
    {
        for (size_t x = 1; x < m_gol_grid.at(y).size() - 1; x++)
        {
            gol_logic(y, x);
        }
    }

    m_gol_grid = m_gol_grid_cache;  //input vector grid cache to vector grid after scanning entire grid
}

void gol_engine::gol_logic(size_t new_y, size_t new_x)  //game logic and 3x3 scanner around selected cell (excluding selected cell so the max number of neighbors can be 8)
{
    m_cell_counter = 0;

    //-------------------START neighbor counter-------------------------------------------------------
    for (size_t y = 0; y < 3; y++)
    {
        for (size_t x = 0; x < 3; x++)
        {
            if ((m_gol_grid.at(new_y - 1 + y).at(new_x - 1 + x) == CELL_ALIVE)) //if char is living cell
            {
                if (!((new_y - 1 + y == new_y) && (new_x - 1 + x == new_x)))    //if not selected cell (if y and x coordinates are not the same as cell source coordinates)
                {
                    m_cell_counter++;   //neighbor counter
                }
            }
        }
    }
    //-------------------END neighbor counter---------------------------------------------------------

    //-------------------START game logic-------------------------------------------------------------
    switch (m_gol_grid.at(new_y).at(new_x)) //coordinates of selected cell
    {
    case CELL_DEAD: //if selected cell is dead
        if (m_cell_counter == 3)    //if neighbor count of selected cell equal to 3
        {
            m_gol_grid_cache.at(new_y).at(new_x) = CELL_ALIVE;  //set selected cell as alive
        }
        break;
    case CELL_ALIVE:    //if selected cell is alive
        if (!((m_cell_counter > 1) && (m_cell_counter < 4)))    //if neighbor count of selected cell equal to 2 or 3
        {
            m_gol_grid_cache.at(new_y).at(new_x) = CELL_DEAD;   //set selected cell as dead
        }
        break;
    default:
        break;
    }
    //-------------------END game logic---------------------------------------------------------------
}

void gol_engine::load_sample_one()
{
    size_t center_x = m_gol_grid.at(0).size() / 2;
    size_t center_y = m_gol_grid.size() / 2;

    for (size_t y = 0; y < m_gol_grid.size(); y++)
    {
        for (size_t x = 0; x < m_gol_grid.at(y).size(); x++)
        {
            if ((y > (center_y - 4)) && (y < (center_y + 3)))
            {
                if (y == (center_y - 3) && (((x > center_x - 4) && (x < center_x)) || ((x > center_x + 1) && (x < center_x + 4))))
                {
                    m_gol_grid[y][x] = CELL_ALIVE;
                }

                if (((y == center_y - 1) && (x == center_x + 2)) || ((y == center_y) && (x == center_x - 2)))
                {
                    m_gol_grid[y][x] = CELL_ALIVE;
                }

                if ((x == center_x) && ((y == center_y - 2) || (y == center_y + 1)))
                {
                    m_gol_grid[y][x] = CELL_ALIVE;
                }

                if (y == (center_y + 2) && (((x > center_x - 4) && (x < center_x - 1)) || ((x > center_x) && (x < center_x + 4))))
                {
                    m_gol_grid[y][x] = CELL_ALIVE;
                }
            }
        }
    }
}

gol_engine::~gol_engine()
{
}
