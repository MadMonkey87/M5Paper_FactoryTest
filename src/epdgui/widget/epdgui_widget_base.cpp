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
    // todo: check if canvase exists already
    this->_Canvas = new M5EPD_Canvas(&M5.EPD);
    this->_Canvas->createCanvas(_w, _h);

    RenderBackground(RENDER_BACKGROUND_MODE_FULL, this->_Canvas, false);
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

void EPDGUI_Widget_Base::RenderDescriptionLabel(const char *string)
{
    this->_Canvas->setTextSize(TEXT_SIZE);
    this->_Canvas->setTextColor(FONT_COLOR);
    this->_Canvas->setTextDatum(MC_DATUM);
    this->_Canvas->drawString(string, _w / 2, _h - 35);
}

void EPDGUI_Widget_Base::RenderBackground(int16_t mode, M5EPD_Canvas *canvas, bool pressed)
{
    int16_t x = 0;
    int16_t y = 0;
    int16_t w = canvas->width();
    int16_t h = canvas->height();

    if (mode == RENDER_BACKGROUND_MODE_MIDDLE)
    {
        canvas->fillCanvas(BACKGROUND_COLOR);
    }
    else
    {
        canvas->fillCanvas(pressed ? 15 - GROUND_COLOR : GROUND_COLOR);
        int16_t offset = CORNER_ROUNDING + BORDER_WIDTH;

        switch (mode)
        {
        case RENDER_BACKGROUND_MODE_TOP_LEFT:
            w += offset;
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_TOP:
            w += offset * 2;
            h += offset;
            x -= offset;
            break;
        case RENDER_BACKGROUND_MODE_TOP_RIGHT:
            x -= offset;
            w += offset;
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_LEFT:
            w += offset;
            y -= offset;
            h += offset * 2;
            break;
        case RENDER_BACKGROUND_MODE_RIGHT:
            w += offset;
            x -= offset;
            y -= offset;
            h += offset * 2;
            break;
        case RENDER_BACKGROUND_MODE_BOTTOM_LEFT:
            w += offset;
            y -= offset;
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_BOTTOM_MIDDLE:
            w += offset * 2;
            x -= offset;
            y -= offset;
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_BOTTOM_RIGHT:
            w += offset;
            x -= offset;
            y -= offset;
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_MIDDLE_VERTICAL:
            x -= offset;
            w += offset * 2;
            break;
        case RENDER_BACKGROUND_MODE_MIDDLE_HORIZONTAL:
            y -= offset;
            h += offset * 2;
            break;
        case RENDER_BACKGROUND_MODE_FULL:
            break;
        case RENDER_BACKGROUND_MODE_FULL_WITHOUT_TOP:
            y -= offset;
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_FULL_WITHOUT_BOTTOM:
            h += offset;
            break;
        case RENDER_BACKGROUND_MODE_FULL_WITHOUT_LEFT:
            x -= offset;
            w += offset;
            break;
        case RENDER_BACKGROUND_MODE_FULL_WITHOUT_RIGHT:
            w += offset;
            break;
        }
    }

    canvas->fillRoundRect(x, y, w, h, CORNER_ROUNDING, pressed ? BACKGROUND_COLOR : BORDER_COLOR);
    if (!pressed)
    {
        canvas->fillRoundRect(x + BORDER_WIDTH, y + BORDER_WIDTH, w - BORDER_WIDTH * 2, h - BORDER_WIDTH * 2, CORNER_ROUNDING - BORDER_WIDTH, BACKGROUND_COLOR);
    }
}