#include "epdgui_widget_base.h"

EPDGUI_Widget_Base::EPDGUI_Widget_Base(int16_t x, int16_t y, int16_t w, int16_t h) : EPDGUI_Base(x, y, w, h)
{
}

EPDGUI_Widget_Base::~EPDGUI_Widget_Base()
{
    delete this->_Canvas;
}

void EPDGUI_Widget_Base::Init(JsonVariant data)
{
    Render(data);
}

void EPDGUI_Widget_Base::Render(JsonVariant data)
{
    this->_Canvas = new M5EPD_Canvas(&M5.EPD);
    this->_Canvas->createCanvas(_w, _h);
    this->_Canvas->fillRect(0, 0, _w, _h, GROUND_COLOR);
    this->_Canvas->fillRoundRect(0, 0, _w, _h, CORNER_ROUNDING, BORDER_COLOR);
    this->_Canvas->fillRoundRect(BORDER_WIDTH, BORDER_WIDTH, _w - BORDER_WIDTH * 2, _h - BORDER_WIDTH * 2, CORNER_ROUNDING - BORDER_WIDTH, BACKGROUND_COLOR);
}

M5EPD_Canvas *EPDGUI_Widget_Base::Canvas()
{
    return this->_Canvas;
}

void EPDGUI_Widget_Base::Draw(m5epd_update_mode_t mode)
{
    if (_ishide)
    {
        return;
    }

    this->_Canvas->pushCanvas(_x, _y, mode);
}

void EPDGUI_Widget_Base::Draw(M5EPD_Canvas *canvas)
{
    if (_ishide)
    {
        return;
    }

    _Canvas->pushToCanvas(_x, _y, canvas);
}

void EPDGUI_Widget_Base::Bind(int16_t event, void (*func_cb)(epdgui_args_vector_t &))
{
}

void EPDGUI_Widget_Base::UpdateState(int16_t x, int16_t y)
{
    if (!_isenable || _ishide)
    {
        return;
    }

    Draw();
}

void EPDGUI_Widget_Base::RenderDescriptionLabel(const char *string)
{
    this->_Canvas->setTextSize(TEXT_SIZE);
    this->_Canvas->setTextColor(FONT_COLOR);
    this->_Canvas->setTextDatum(MC_DATUM);
    this->_Canvas->drawString(string, _w / 2, _h - 35);
}