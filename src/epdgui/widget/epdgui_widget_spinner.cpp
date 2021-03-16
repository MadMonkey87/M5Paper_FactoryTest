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

    this->_Canvas->setTextSize(TEXT_SIZE);
    this->_Canvas->setTextColor(FONT_COLOR);
    this->_Canvas->setTextDatum(MC_DATUM);
    this->_Canvas->drawString(value.c_str(),  _w/2, _h/2);
}

void EPDGUI_Widget_Spinner::RenderDescriptionLabel(const char *string)
{
    this->_Canvas->setTextSize(TEXT_SIZE);
    this->_Canvas->setTextColor(FONT_COLOR);
    this->_Canvas->setTextDatum(MC_DATUM);
    this->_Canvas->drawString(string,  _w/2, 35);
}

void EPDGUI_Widget_Spinner::Bind(int16_t event, void (*func_cb)(epdgui_args_vector_t &))
{

}

void EPDGUI_Widget_Spinner::UpdateState(int16_t x, int16_t y)
{
    
}
