#include "frame_playground.h"

Frame_Playground::Frame_Playground() : Frame_Base()
{
    _frame_name = "Frame_Playground";

    _sample_button_1 = new EPDGUI_Button(20, 140, 240, 240);
    _sample_button_1->CanvasNormal()->fillRoundRect(0,0,240,240,32,15);
    _sample_button_1->CanvasNormal()->fillRoundRect(4,4,240-8,240-8,32,8);
    _sample_button_1->CanvasPressed()->ReverseColor();
    _sample_button_1->SetEnable(true);

    _sample_button_2 = new EPDGUI_Button(280, 140, 240, 240);
    _sample_button_2->CanvasNormal()->fillRoundRect(0,0,240,240,16,15);
    _sample_button_2->CanvasNormal()->fillRoundRect(2,2,240-4,240-4,16,4);
    _sample_button_2->CanvasPressed()->ReverseColor();
    _sample_button_2->SetEnable(true);

    _sample_button_3 = new EPDGUI_Button(20, 400, 240, 240);
    _sample_button_3->CanvasNormal()->fillRoundRect(0,0,240,240,8,15);
    _sample_button_3->CanvasNormal()->fillRoundRect(1,1,240-2,240-2,8,2);
    //memcpy(_sample_button_3->CanvasNormal()->frameBuffer(), ImageResource_home_button_background_228x228, _sample_button_3->CanvasNormal()->getBufferSize());
    _sample_button_3->CanvasPressed()->ReverseColor();
    _sample_button_3->SetEnable(true);

    _sample_button_4 = new EPDGUI_Button(280, 400, 240, 240);
    _sample_button_4->CanvasNormal()->fillRoundRect(0,0,240,240,16,15);
    _sample_button_4->CanvasNormal()->fillRoundRect(2,2,240-4,240-4,16,1);
    _sample_button_4->CanvasPressed()->ReverseColor();
    _sample_button_4->SetEnable(true);

    _sample_button_5 = new EPDGUI_Button(20, 660, 240, 240);
    _sample_button_5->CanvasNormal()->fillRoundRect(0,0,240,240,16,15);
    _sample_button_5->CanvasNormal()->fillRoundRect(2,2,240-4,240-4,16,0);
    _sample_button_5->CanvasPressed()->ReverseColor();
    _sample_button_5->SetEnable(true);

    _sample_button_6 = new EPDGUI_Button("Hello!", 280, 660, 240, 240);
    _sample_button_6->SetEnable(true);



    exitbtn("Back");
    _canvas_title->drawString("Playground... feel free to play;P", 270, 34);

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_Playground::~Frame_Playground()
{
    delete _sample_button_1;
    delete _sample_button_2;
    delete _sample_button_3;
    delete _sample_button_4;
    delete _sample_button_5;
    delete _sample_button_6;
}

int Frame_Playground::init(epdgui_args_vector_t &args)
{
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(_key_exit);

    EPDGUI_AddObject(_sample_button_1);
    EPDGUI_AddObject(_sample_button_2);
    EPDGUI_AddObject(_sample_button_3);
    EPDGUI_AddObject(_sample_button_4);
    EPDGUI_AddObject(_sample_button_5);
    EPDGUI_AddObject(_sample_button_6);


    return 0;
}

int Frame_Playground::run(void)
{
    return 1;
}
