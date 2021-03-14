#ifndef __EPDGUI_WIDGET_BASE_H
#define __EPDGUI_WIDGET_BASE_H

#include "../epdgui_base.h"
#include "ArduinoJson.h"

class EPDGUI_Widget_Base: public EPDGUI_Base
{
public:
    static const int16_t EVENT_NONE = 0;
    static const int16_t EVENT_PRESSED = 1;
    static const int16_t EVENT_RELEASED = 2;

    static const int16_t GROUND_COLOR = 0;

    static const bool RENDER_BORDER = true;
    static const int16_t CORNER_ROUNDING = 16;
    static const int16_t BORDER_WIDTH = 2;
    static const int16_t TEXT_SIZE = 26;

    static const int16_t BORDER_COLOR = 15;
    static const int16_t BACKGROUND_COLOR = 0;
    static const int16_t FONT_COLOR = 15;

public:
    EPDGUI_Widget_Base(int16_t x, int16_t y, int16_t w, int16_t h);
    ~EPDGUI_Widget_Base();
    void Draw(m5epd_update_mode_t mode = UPDATE_MODE_DU4);
    void Draw(M5EPD_Canvas* canvas);
    void Bind(int16_t event, void (* func_cb)(epdgui_args_vector_t&));
    void UpdateState(int16_t x, int16_t y);
    virtual void Render(JsonVariant data);
    void Init(JsonVariant data);

    M5EPD_Canvas* CanvasNormal();
    M5EPD_Canvas* CanvasPressed();

private:
    void (*_pressed_cb)(epdgui_args_vector_t& args) = NULL;
    void (*_released_cb)(epdgui_args_vector_t& args) = NULL;
    epdgui_args_vector_t _pressed_cb_args;
    epdgui_args_vector_t _released_cb_args;
    int16_t _state = EVENT_NONE;

public:
    M5EPD_Canvas* _CanvasNormal = NULL;
    M5EPD_Canvas* _CanvasPressed = NULL;
};


#endif //__EPDGUI_WIDGET_BASE_H