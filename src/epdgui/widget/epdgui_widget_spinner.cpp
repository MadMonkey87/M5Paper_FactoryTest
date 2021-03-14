#include "epdgui_widget_spinner.h"

EPDGUI_Widget_Spinner::EPDGUI_Widget_Spinner(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Widget_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Spinner::Render(JsonVariant data)
{
    EPDGUI_Widget_Base::Render(data);

    String description = data["description"];
    String value = data["value"];

    this->_CanvasNormal->setTextSize(TEXT_SIZE);
    this->_CanvasNormal->setTextColor(FONT_COLOR);
    this->_CanvasNormal->setTextDatum(MC_DATUM);
    this->_CanvasNormal->drawString(description.c_str(),  _w/2, 35);

    this->_CanvasNormal->setTextSize(TEXT_SIZE);
    this->_CanvasNormal->setTextColor(FONT_COLOR);
    this->_CanvasNormal->setTextDatum(MC_DATUM);
    this->_CanvasNormal->drawString(value.c_str(),  _w/2, _h/2);
}