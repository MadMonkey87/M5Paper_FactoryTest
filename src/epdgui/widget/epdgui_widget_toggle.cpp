#include "epdgui_widget_toggle.h"

EPDGUI_Widget_Toggle::EPDGUI_Widget_Toggle(int16_t x, int16_t y, int16_t w, int16_t h) : EPDGUI_Widget_Base(x, y, w, h)
{
}

void EPDGUI_Widget_Toggle::Render(JsonVariant data)
{
    EPDGUI_Widget_Base::Render(data);

    this->_Canvas->fillRoundRect((_w - TOGGLE_WIDTH) / 2, (_h - TOGGLE_HEIGHT) / 2, TOGGLE_WIDTH, TOGGLE_HEIGHT, TOGGLE_CORNER_RADIUS, TOGGLE_BORDER_COLOR);
    this->_Canvas->fillRoundRect((_w - TOGGLE_WIDTH) / 2 + TOGGLE_BORDER_WIDTH, (_h - TOGGLE_HEIGHT) / 2 + TOGGLE_BORDER_WIDTH, TOGGLE_WIDTH - 2 * TOGGLE_BORDER_WIDTH, TOGGLE_HEIGHT - 2 * TOGGLE_BORDER_WIDTH, TOGGLE_CORNER_RADIUS - TOGGLE_BORDER_WIDTH, TOGGLE_BACKGROUND_COLOR);
    int16_t KNOB_MARGIN = (TOGGLE_HEIGHT - TOGGLE_KNOB_HEIGHT) / 2;
    this->_Canvas->fillRoundRect((_w - TOGGLE_WIDTH) / 2 + KNOB_MARGIN, (_h - TOGGLE_HEIGHT) / 2 + KNOB_MARGIN, TOGGLE_KNOB_WIDTH, TOGGLE_KNOB_HEIGHT, TOGGLE_KNOB_CORNER_RADIUS, TOGGLE_KNOB_COLOR);

    String description = data["description"];
    RenderDescriptionLabel(description.c_str());
}