#include "epdgui_widget_icon.h"

EPDGUI_Widget_Icon::EPDGUI_Widget_Icon(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Widget_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Icon::Render(JsonVariant data)
{
    EPDGUI_Widget_Base::Render(data);

    String title = data["description"];

    String icon = "/Icons/xbox.jpg";

    this->_CanvasNormal->drawJpgFile(SD, icon.c_str(),_w/2-50,_h/2-50-35, 100,100);
    this->_CanvasNormal->setTextSize(TEXT_SIZE);
    this->_CanvasNormal->setTextColor(FONT_COLOR);
    this->_CanvasNormal->setTextDatum(MC_DATUM);
    this->_CanvasNormal->drawString(title.c_str(),  _w/2, _h-35);

    this->_CanvasPressed->drawJpgFile(SD, icon.c_str(),_w/2-50,_h/2-50-35, 100,100);
    this->_CanvasPressed->setTextSize(TEXT_SIZE);
    this->_CanvasPressed->setTextColor(FONT_COLOR);
    this->_CanvasPressed->setTextDatum(MC_DATUM);
    this->_CanvasPressed->drawString(title.c_str(),  _w/2, _h-35);
}