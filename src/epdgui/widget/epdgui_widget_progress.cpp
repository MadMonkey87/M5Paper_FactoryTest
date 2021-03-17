#include "epdgui_widget_progress.h"

EPDGUI_Widget_Progress::EPDGUI_Widget_Progress(int16_t x, int16_t y, int16_t w, int16_t h) : EPDGUI_Widget_Base(x, y, w, h)
{
}

void EPDGUI_Widget_Progress::Render(JsonVariant data)
{
    EPDGUI_Widget_Base::Render(data);

    this->Render();

    String description = data["description"];
    RenderDescriptionLabel(description.c_str());
}

void EPDGUI_Widget_Progress::Init(JsonVariant data)
{
    Render(data);
}

void EPDGUI_Widget_Progress::Bind(int16_t event, void (*func_cb)(epdgui_args_vector_t &))
{
}

void EPDGUI_Widget_Progress::UpdateState(int16_t x, int16_t y)
{
}

void EPDGUI_Widget_Progress::Render()
{
    this->_Canvas->fillCircle(_w / 2, _h / 2 + OFFSET_Y, OUTER_RADIUS, OUTER_BORDER_COLOR);
    this->_Canvas->fillCircle(_w / 2, _h / 2 + OFFSET_Y, OUTER_RADIUS - OUTER_BORDER_WIDTH, OUTER_BACKGROUND_COLOR);
    this->_Canvas->fillCircle(_w / 2, _h / 2 + OFFSET_Y, INNER_RADIUS + INNER_BORDER_WIDTH, INNER_BORDER_COLOR);
    this->_Canvas->fillCircle(_w / 2, _h / 2 + OFFSET_Y, INNER_RADIUS, INNER_BACKGROUND_COLOR);

    int16_t x = _w / 2 - OUTER_RADIUS - OUTER_BORDER_WIDTH;
    int16_t y = _h / 2 + OFFSET_Y;
    this->_Canvas->fillTriangle(_w / 2, _h / 2 + OFFSET_Y, _w / 2, _h / 2 + OFFSET_Y + OUTER_RADIUS - OUTER_BORDER_WIDTH, x, y, 4);

    String value = "65%";
    this->_Canvas->setTextSize(TEXT_SIZE);
    this->_Canvas->setTextColor(FONT_COLOR);
    this->_Canvas->setTextDatum(MC_DATUM);
    this->_Canvas->drawString(value.c_str(), _w / 2, _h / 2 + OFFSET_Y);
}