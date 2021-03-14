#include "epdgui_widget_base.h"

EPDGUI_Widget_Base::EPDGUI_Widget_Base(int16_t x, int16_t y, int16_t w, int16_t h): 
EPDGUI_Base(x, y, w, h)
{

}

void EPDGUI_Widget_Base::Init(JsonVariant data)
{
    Render(data);
    this->_CanvasPressed->ReverseColor();
}

void EPDGUI_Widget_Base::Render(JsonVariant data)
{
    this->_CanvasNormal = new M5EPD_Canvas(&M5.EPD);
    this->_CanvasPressed = new M5EPD_Canvas(&M5.EPD);
    this->_CanvasNormal->createCanvas(_w, _h);
    this->_CanvasPressed->createCanvas(_w, _h);

    this->_CanvasNormal->fillRect(0,0,_w,_h, GROUND_COLOR);
    this->_CanvasPressed->fillRect(0,0,_w,_h, 15-GROUND_COLOR);

    this->_CanvasNormal->fillRoundRect(0,0,_w,_h,CORNER_ROUNDING,BORDER_COLOR);
    this->_CanvasNormal->fillRoundRect(BORDER_WIDTH,BORDER_WIDTH,_w-BORDER_WIDTH*2,_h-BORDER_WIDTH*2,CORNER_ROUNDING-BORDER_WIDTH,BACKGROUND_COLOR);

    this->_CanvasPressed->fillRoundRect(0,0,_w,_h,CORNER_ROUNDING,BACKGROUND_COLOR);
}

EPDGUI_Widget_Base::~EPDGUI_Widget_Base()
{
    delete this->_CanvasNormal;
    delete this->_CanvasPressed;
}

M5EPD_Canvas* EPDGUI_Widget_Base::CanvasNormal()
{
    return this->_CanvasNormal;
}

M5EPD_Canvas* EPDGUI_Widget_Base::CanvasPressed()
{
    return this->_CanvasPressed;
}

void EPDGUI_Widget_Base::Draw(m5epd_update_mode_t mode)
{
    if(_ishide)
    {
        return;
    }

    if(_state == EVENT_NONE || _state == EVENT_RELEASED)
    {
        this->_CanvasNormal->pushCanvas(_x, _y, mode);
    }
    else if(_state == EVENT_PRESSED)
    {
        Serial.println(mode);
        this->_CanvasPressed->pushCanvas(_x, _y, mode);
    }
}

void EPDGUI_Widget_Base::Draw(M5EPD_Canvas* canvas)
{
    if(_ishide)
    {
        return;
    }

    if(_state == EVENT_NONE || _state == EVENT_RELEASED)
    {
        _CanvasNormal->pushToCanvas(_x, _y, canvas);
    }
    else if(_state == EVENT_PRESSED)
    {
        _CanvasPressed->pushToCanvas(_x, _y, canvas);
    }
}

void EPDGUI_Widget_Base::Bind(int16_t event, void (* func_cb)(epdgui_args_vector_t&))
{
    if(event == EVENT_PRESSED)
    {
        _pressed_cb = func_cb;
    }
    else if(event == EVENT_RELEASED)
    {
        _released_cb = func_cb;
    }
}

void EPDGUI_Widget_Base::UpdateState(int16_t x, int16_t y)
{
    if(!_isenable || _ishide)
    {
        return;
    }

    bool is_in_area = isInBox(x, y);

    if(is_in_area)
    {
        if(_state == EVENT_NONE)
        {
            _state = EVENT_PRESSED;
            // Serial.printf("%s Pressed ", _label.c_str());
            Draw();
            if(_pressed_cb != NULL)
            {
                _pressed_cb(_pressed_cb_args);
            }
        }
    }
    else
    {
        if(_state == EVENT_PRESSED)
        {
            _state = EVENT_NONE;
            Draw();
            if(_released_cb != NULL)
            {
                _released_cb(_released_cb_args);
            }
        }
    }
}