#include "epdgui_widget_icon_toggle.h"

EPDGUI_Widget_Icon_Toggle::EPDGUI_Widget_Icon_Toggle(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Widget_Graphic_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Icon_Toggle::Render(JsonVariant data)
{
    EPDGUI_Widget_Graphic_Base::Render(data);

    String description = data["description"];
    //String icon = data["icon"];

    //this->_Canvas->drawJpgFile(SD, icon.c_str(),_w/2-70,_h/2-70-25, 140,140);
    //this->_CanvasPressed->drawJpgFile(SD, icon.c_str(),_w/2-70,_h/2-70-25, 140,140);

    RenderDescriptionLabel(description.c_str());
}

void EPDGUI_Widget_Icon_Toggle::Init(JsonVariant data)
{
    
    EPDGUI_Widget_Graphic_Base::Render(data);
}