#ifndef __EPDGUI_WIDGET_Double_Switch_H
#define __EPDGUI_WIDGET_Double_Switch_H

#include "epdgui_widget_base.h"
#include "../epdgui_container.h"
#include "ArduinoJson.h"

class EPDGUI_Widget_Double_Switch: public EPDGUI_Widget_Base
{

public:
    EPDGUI_Widget_Double_Switch(int16_t x, int16_t y, int16_t w, int16_t h);
    void Render(JsonVariant data);
};


#endif //__EPDGUI_WIDGET_Double_Switch_H