#include "frame_playground.h"
#include "SD.h"
#include "ArduinoJson.h"
#include "FS.h"

Frame_Playground::Frame_Playground() : Frame_Base()
{
    Serial.print("Frame_Playground constructor");

    _frame_name = "Frame_Playground";

    _widget_container = new EPDGUI_Container();

    File file = SD.open("/index.json");
    if (!file)
    {
        Serial.println("Failed to open file for reading");
        return;
    }

    String content = "";
    while (file.available())
    {
        content += (char)file.read();
    }

    DynamicJsonDocument doc(1024 * 16);
    DeserializationError error = deserializeJson(doc, content);
    if (error)
    {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
    }
    else
    {
        JsonArray array = doc["widgets"].as<JsonArray>();
        int x = 0;
        int y = 0;
        for (JsonVariant v : array)
        {
            if (x >= 2)
            {
                y++;
                x = 0;
            }
            EPDGUI_Widget_Base *_widget = new EPDGUI_Widget_Base(20 + (x * 260), 140 + (y * 260), 240, 240, v);
            _widget_container->EPDGUI_AddComponent(_widget);
            //Serial.println(v.as<int>());
            x++;
        }
    }

    exitbtn("Back");
    _canvas_title->drawString("Playground", 270, 34);

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
