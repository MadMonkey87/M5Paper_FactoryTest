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
    EPDGUI_Button *_sample_button_1;
    EPDGUI_Button *_sample_button_2;
    EPDGUI_Button *_sample_button_3;
    EPDGUI_Button *_sample_button_4;
    EPDGUI_Button *_sample_button_5;
    EPDGUI_Button *_sample_button_6;
};

#endif //_FRAME_PLAYGROUND_H_