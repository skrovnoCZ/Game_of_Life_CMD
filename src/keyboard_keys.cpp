#include "keyboard_keys.h"



keyboard_keys::keyboard_keys()
{
    m_key_up = false;
    m_key_down = false;
    m_key_left = false;
    m_key_right = false;
    m_key_num1 = false;
    m_key_c = false;
    m_key_e = false;
    m_key_l = false;
    m_key_alt = false;
    m_key_q = false;
    m_key_enter = false;
    m_key_control = false;
    m_key_escape = false;
    m_key = VK_RESET;
}



void keyboard_keys::keyboard_key_up()
{
    if ((GetKeyState(VK_UP) < 0) && (!m_key_up))
    {
        m_key = VK_UP;
        m_key_up = true;
    }
    else if (GetKeyState(VK_UP) >= 0 && (m_key_up))
    {
        m_key = VK_RESET;
        m_key_up = false;
    }
}

void keyboard_keys::keyboard_key_down()
{
    if ((GetKeyState(VK_DOWN) < 0) && (!m_key_down))
    {
        m_key = VK_DOWN;
        m_key_down = true;
    }
    else if (GetKeyState(VK_DOWN) >= 0 && (m_key_down))
    {
        m_key = VK_RESET;
        m_key_down = false;
    }
}

void keyboard_keys::keyboard_key_left()
{
    if ((GetKeyState(VK_LEFT) < 0) && (!m_key_left))
    {
        m_key = VK_LEFT;
        m_key_left = true;
    }
    else if (GetKeyState(VK_LEFT) >= 0 && (m_key_left))
    {
        m_key = VK_RESET;
        m_key_left = false;
    }
}

void keyboard_keys::keyboard_key_right()
{
    if ((GetKeyState(VK_RIGHT) < 0) && (!m_key_right))
    {
        m_key = VK_RIGHT;
        m_key_right = true;
    }
    else if (GetKeyState(VK_RIGHT) >= 0 && (m_key_right))
    {
        m_key = VK_RESET;
        m_key_right = false;
    }
}

void keyboard_keys::keyboard_key_num1()
{
    if ((GetKeyState(VK_NUMPAD1) < 0) && (!m_key_num1))
    {
        m_key = VK_NUMPAD1;
        m_key_num1 = true;
    }
    else if (GetKeyState(VK_NUMPAD1) >= 0 && (m_key_num1))
    {
        m_key = VK_RESET;
        m_key_num1 = false;
    }
}

void keyboard_keys::keyboard_key_c()
{
    if ((GetKeyState(VK_L_C) < 0) && (!m_key_c))
    {
        m_key = VK_L_C;
        m_key_c = true;
    }
    else if (GetKeyState(VK_L_C) >= 0 && (m_key_c))
    {
        m_key = VK_RESET;
        m_key_c = false;
    }
}

void keyboard_keys::keyboard_key_e()
{
    if ((GetKeyState(VK_L_E) < 0) && (!m_key_e))
    {
        m_key = VK_L_E;
        m_key_e = true;
    }
    else if (GetKeyState(VK_L_E) >= 0 && (m_key_e))
    {
        m_key = VK_RESET;
        m_key_e = false;
    }
}

void keyboard_keys::keyboard_key_l()
{
    if ((GetKeyState(VK_L_L) < 0) && (!m_key_l))
    {
        m_key = VK_L_L;
        m_key_l = true;
    }
    else if (GetKeyState(VK_L_L) >= 0 && (m_key_l))
    {
        m_key = VK_RESET;
        m_key_l = false;
    }
}

void keyboard_keys::keyboard_key_alt()
{
    if ((GetKeyState(VK_MENU) < 0) && (!m_key_alt))
    {
        m_key = VK_MENU;
        m_key_alt = true;
    }
    else if (GetKeyState(VK_MENU) >= 0 && (m_key_alt))
    {
        m_key = VK_RESET;
        m_key_alt = false;
    }
}

void keyboard_keys::keyboard_key_q()
{
    if ((GetKeyState(VK_L_Q) < 0) && (!m_key_q))
    {
        m_key = VK_L_Q;
        m_key_q = true;
    }
    else if (GetKeyState(VK_L_Q) >= 0 && (m_key_q))
    {
        m_key = VK_RESET;
        m_key_q = false;
    }
}

void keyboard_keys::keyboard_key_enter()
{
    if ((GetKeyState(VK_RETURN) < 0) && (!m_key_enter))
    {
        m_key = VK_RETURN;
        m_key_enter = true;
    }
    else if (GetKeyState(VK_RETURN) >= 0 && (m_key_enter))
    {
        m_key = VK_RESET;
        m_key_enter = false;
    }
}

void keyboard_keys::keyboard_key_ctrl()
{
    if ((GetKeyState(VK_CONTROL) < 0) && (!m_key_control))
    {
        m_key = VK_CONTROL;
        m_key_control = true;
    }
    else if (GetKeyState(VK_CONTROL) >= 0 && (m_key_control))
    {
        m_key = VK_RESET;
        m_key_control = false;
    }
}

void keyboard_keys::keyboard_key_esc()
{
    if ((GetKeyState(VK_ESCAPE) < 0) && (!m_key_escape))
    {
        m_key = VK_ESCAPE;
        m_key_escape = true;
    }
    else if (GetKeyState(VK_ESCAPE) >= 0 && (m_key_escape))
    {
        m_key = VK_RESET;
        m_key_escape = false;
    }
}

void keyboard_keys::reset_keys()
{
    m_key = VK_RESET;
}

int keyboard_keys::get_key()
{
    return m_key;
}


keyboard_keys::~keyboard_keys()
{
}
