#ifndef __KEYBOARD_KEYS__
#define __KEYBOARD_KEYS__

#include <Windows.h>

#define VK_RESET 0x00   //key reset status
#define VK_L_C 0x43 //key C (missing in Windows.h)
#define VK_L_E 0x45 //key E (missing in Windows.h)
#define VK_L_L 0x4C //key E (missing in Windows.h)
#define VK_L_Q 0x51 //key Q (missing in Windows.h)

class keyboard_keys
{
private:
    bool m_key_up;      //variable to prevent holding keyboard key
    bool m_key_down;    //variable to prevent holding keyboard key
    bool m_key_left;    //variable to prevent holding keyboard key
    bool m_key_right;   //variable to prevent holding keyboard key
    bool m_key_num1;    //variable to prevent holding keyboard key
    bool m_key_c;       //variable to prevent holding keyboard key
    bool m_key_e;       //variable to prevent holding keyboard key
    bool m_key_l;       //variable to prevent holding keyboard key
    bool m_key_alt;     //variable to prevent holding keyboard key
    bool m_key_q;       //variable to prevent holding keyboard key
    bool m_key_enter;   //variable to prevent holding keyboard key
    bool m_key_control; //variable to prevent holding keyboard key
    bool m_key_escape;  //variable to prevent holding keyboard key
    int m_key;          //variable to prevent holding keyboard key
public:
    keyboard_keys();
    void keyboard_key_up();
    void keyboard_key_down();
    void keyboard_key_left();
    void keyboard_key_right();
    void keyboard_key_num1();
    void keyboard_key_c();
    void keyboard_key_e();
    void keyboard_key_l();
    void keyboard_key_alt();
    void keyboard_key_q();
    void keyboard_key_enter();
    void keyboard_key_ctrl();
    void keyboard_key_esc();
    void reset_keys();
    int get_key();
    ~keyboard_keys();
};

#endif