#include "epdgui_widget_icon.h"

EPDGUI_Widget_Icon::EPDGUI_Widget_Icon(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Widget_Graphic_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Icon::Render(JsonVariant data)
{
    EPDGUI_Widget_Graphic_Base::Render(data);

    String description = data["description"];

    String icon = "/Icons/xbox.jpg";
    this->_Canvas->drawJpgFile(SD, icon.c_str(),_w/2-50,_h/2-50-35, 100,100);
    this->_CanvasPressed->drawJpgFile(SD, icon.c_str(),_w/2-50,_h/2-50-35, 100,100);

    RenderDescriptionLabel(description.c_str());
}