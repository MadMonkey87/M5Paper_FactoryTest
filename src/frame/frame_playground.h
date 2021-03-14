#ifndef _FRAME_PLAYGROUND_H_
#define _FRAME_PLAYGROUND_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_Playground : public Frame_Base
{
public:
    Frame_Playground();
    ~Frame_Playground();
    int run();
    int init(epdgui_args_vector_t &args);
private:
    EPDGUI_Container *_widget_container;
};

#endif //_FRAME_PLAYGROUND_H_