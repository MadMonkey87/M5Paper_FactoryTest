#ifndef __EPDGUI_WIDGET_Progress_H
#define __EPDGUI_WIDGET_Progress_H

#include "epdgui_widget_base.h"
#include "ArduinoJson.h"

class EPDGUI_Widget_Progress : public EPDGUI_Widget_Base
{
public:
    static const int16_t OUTER_RADIUS = 80;
    static const int16_t INNER_RADIUS = 50;
    static const int16_t OFFSET_Y = -20;
    static const int16_t OUTER_BORDER_WIDTH = 2;
    static const int16_t INNER_BORDER_WIDTH = 2;
    static const int16_t OUTER_BORDER_COLOR = 15;
    static const int16_t INNER_BORDER_COLOR = 15;
    static const int16_t OUTER_BACKGROUND_COLOR = 3;
    static const int16_t INNER_BACKGROUND_COLOR = 0;

public:
    EPDGUI_Widget_Progress(int16_t x, int16_t y, int16_t w, int16_t h);
    void Bind(int16_t event, void (*func_cb)(epdgui_args_vector_t &));
    void UpdateState(int16_t x, int16_t y);
    void Init(JsonVariant data);
    void Render(JsonVariant data);

private:
    void Render();
};

#endif //__EPDGUI_WIDGET_Progress_H