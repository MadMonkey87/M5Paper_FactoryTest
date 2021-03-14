#include "epdgui_widget_text.h"

EPDGUI_Widget_Text::EPDGUI_Widget_Text(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Widget_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Text::Render(JsonVariant data)
{
    EPDGUI_Widget_Base::Render(data);

    String description = "description";//data["description"];
    String value = "15.6";//data["value"];
    String hint = "hint";//data["description"];

    this->_CanvasNormal->setTextSize(TEXT_SIZE);
    this->_CanvasNormal->setTextColor(FONT_COLOR);
    this->_CanvasNormal->setTextDatum(MC_DATUM);
    this->_CanvasNormal->drawString(hint.c_str(),  _w/2, 35);

    this->_CanvasNormal->setTextSize(TEXT_SIZE);
    this->_CanvasNormal->setTextColor(FONT_COLOR);
    this->_CanvasNormal->setTextDatum(MC_DATUM);
    this->_CanvasNormal->drawString(value.c_str(),  _w/2, _h/2);

    this->_CanvasNormal->setTextSize(TEXT_SIZE);
    this->_CanvasNormal->setTextColor(FONT_COLOR);
    this->_CanvasNormal->setTextDatum(MC_DATUM);
    this->_CanvasNormal->drawString(description.c_str(),  _w/2, _h-35);
}