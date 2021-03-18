#ifndef _FRAME_PLAYGROUND_H_
#define _FRAME_PLAYGROUND_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_Playground : public Frame_Base
{
public:
    static const int16_t GRID_WIDTH = 2;
    static const int16_t GRID_HEIGHT = 3;

public:
    Frame_Playground();
    ~Frame_Playground();
    int run();
    int init(epdgui_args_vector_t &args);

private:
    EPDGUI_Page_Container *_page_container;
    int16_t lastButtonIndex = 0;
};

#endif //_FRAME_PLAYGROUND_H_