#include "frame_playground.h"
#include "SD.h"
#include "ArduinoJson.h"
#include "FS.h"

Frame_Playground::Frame_Playground() : Frame_Base()
{
    Serial.print("Frame_Playground constructor");

    _frame_name = "Frame_Playground";

    String icon = "/Icons/xbox.jpg";

    _widget_container = new EPDGUI_Container();

    EPDGUI_Button* _sample_button_1 = new EPDGUI_Button(20, 140, 240, 240);
    _sample_button_1->CanvasNormal()->fillRoundRect(0,0,240,240,32,15);
    _sample_button_1->CanvasNormal()->fillRoundRect(4,4,240-8,240-8,32,8);
    _sample_button_1->CanvasPressed()->ReverseColor();
    _sample_button_1->SetEnable(true);

     EPDGUI_Button* _sample_button_2 = new EPDGUI_Button(280, 140, 240, 240);
    _sample_button_2->CanvasNormal()->fillRoundRect(0,0,240,240,16,15);
    _sample_button_2->CanvasNormal()->fillRoundRect(2,2,240-4,240-4,16,4);
    _sample_button_2->CanvasPressed()->ReverseColor();
    _sample_button_2->SetEnable(true);

     EPDGUI_Button* _sample_button_3 = new EPDGUI_Button(20, 400, 240, 240);
    _sample_button_3->CanvasNormal()->fillRoundRect(0,0,240,240,8,15);
    _sample_button_3->CanvasNormal()->fillRoundRect(1,1,240-2,240-2,8,2);
    //memcpy(_sample_button_3->CanvasNormal()->frameBuffer(), ImageResource_home_button_background_228x228, 228 * 228 / 2);
    _sample_button_3->CanvasNormal()->drawJpgFile(SD, icon.c_str(),70,70, 100,100, 50,50);
    _sample_button_3->CanvasPressed()->ReverseColor();
    _sample_button_3->SetEnable(true);

    EPDGUI_Button* _sample_button_4 = new EPDGUI_Button(280, 400, 240, 240);
    _sample_button_4->CanvasNormal()->fillRoundRect(0,0,240,240,16,15);
    _sample_button_4->CanvasNormal()->fillRoundRect(2,2,240-4,240-4,16,1);
    _sample_button_4->CanvasNormal()->drawJpgFile(SD, icon.c_str(),70,70, 100,100);
    _sample_button_4->CanvasPressed()->ReverseColor();
    _sample_button_4->SetEnable(true);

    EPDGUI_Button* _sample_button_5 = new EPDGUI_Button(20, 660, 240, 240);
    _sample_button_5->CanvasNormal()->fillRoundRect(0,0,240,240,16,15);
    _sample_button_5->CanvasNormal()->fillRoundRect(2,2,240-4,240-4,16,0);
    _sample_button_5->CanvasNormal()->drawJpgFile(SD, icon.c_str(),20,20, 200,200);
    _sample_button_5->CanvasPressed()->ReverseColor();
    _sample_button_5->SetEnable(true);

    File file = SD.open("/index.json");
    if(!file){
        Serial.println("Failed to open file for reading");
        return;
    }

    String title = "";
    String content = "";
    while(file.available()){
        content += (char)file.read();
    }

    DynamicJsonDocument doc(1024*16);
    DeserializationError error = deserializeJson(doc, content);
    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
    } else {
        JsonObject obj = doc.as<JsonObject>();
        String foo = doc["widgets"][0]["description"];
        title = foo;

        JsonArray array = doc["widgets"].as<JsonArray>();
        for(JsonVariant v : array) {
            //Serial.println(v.as<int>());
            title += ".";
        }
        title += "!";
    }
    

    EPDGUI_Button* _sample_button_6 = new EPDGUI_Button(title, 280, 660, 240, 240);
    _sample_button_6->SetEnable(true);

    //_widget_container->EPDGUI_AddComponent(_sample_button_1);
    //_widget_container->EPDGUI_AddComponent(_sample_button_2);
    //_widget_container->EPDGUI_AddComponent(_sample_button_3);
    /*_widget_container->EPDGUI_AddComponent(_sample_button_4);
    _widget_container->EPDGUI_AddComponent(_sample_button_5);*/
    _widget_container->EPDGUI_AddComponent(_sample_button_6);

    EPDGUI_Widget_Base* _sample_widget_1 = new EPDGUI_Widget_Base(20, 140, 240, 240);
    EPDGUI_Widget_Base* _sample_widget_2 = new EPDGUI_Widget_Base(280, 140, 240, 240);
    EPDGUI_Widget_Base* _sample_widget_3 = new EPDGUI_Widget_Base(20, 400, 240, 240);
    EPDGUI_Widget_Base* _sample_widget_4 = new EPDGUI_Widget_Base(280, 400, 240, 240);
    EPDGUI_Widget_Base* _sample_widget_5 = new EPDGUI_Widget_Base(20, 660, 240, 240);
    _widget_container->EPDGUI_AddComponent(_sample_widget_1);
    _widget_container->EPDGUI_AddComponent(_sample_widget_2);
    _widget_container->EPDGUI_AddComponent(_sample_widget_3);
    _widget_container->EPDGUI_AddComponent(_sample_widget_4);
    _widget_container->EPDGUI_AddComponent(_sample_widget_5);

    exitbtn("Back");
    _canvas_title->drawString("Playground... feel free to play;P", 270, 34);

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_Playground::~Frame_Playground()
{
    Serial.print("Frame_Playground destructor");

    delete _widget_container;
}

int Frame_Playground::init(epdgui_args_vector_t &args)
{
    Serial.print("Frame_Playground init");

    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(_key_exit);

    EPDGUI_AddObject(_widget_container);

    return 0;
}

int Frame_Playground::run(void)
{
    // Serial.print("Frame_Playground run");

    return 1;
}
