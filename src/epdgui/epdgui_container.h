#ifndef __EPDGUI_CONTAINER_H
#define __EPDGUI_CONTAINER_H

#include "epdgui_base.h"

class EPDGUI_Container : public EPDGUI_Base
{
public:
    EPDGUI_Container();
    ~EPDGUI_Container();
    void Draw(m5epd_update_mode_t mode = UPDATE_MODE_DU4);
    void Draw(M5EPD_Canvas* canvas);
    void EPDGUI_AddComponent(EPDGUI_Base* component);
    void Bind(int16_t event, void (*func_cb)(epdgui_args_vector_t &));
    void UpdateState(int16_t x, int16_t y);

};

#endif //__EPDGUI_CONTAINER_H