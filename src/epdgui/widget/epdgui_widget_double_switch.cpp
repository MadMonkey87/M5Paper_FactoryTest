#include "epdgui_widget_double_switch.h"

EPDGUI_Widget_Double_Switch::EPDGUI_Widget_Double_Switch(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Widget_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Double_Switch::Render(JsonVariant data)
{
    EPDGUI_Widget_Base::Render(data);

    this->_Canvas->fillRect(10,_h/2-1,_w-20,2, 6);
}