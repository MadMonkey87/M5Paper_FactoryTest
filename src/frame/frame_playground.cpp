#include "frame_playground.h"
#include "SD.h"
#include "ArduinoJson.h"
#include "FS.h"

Frame_Playground::Frame_Playground() : Frame_Base()
{
    Serial.print("Frame_Playground constructor");

    _frame_name = "Frame_Playground";

    _page_container = new EPDGUI_Page_Container(0, 120, 540, 960 - 120);

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
        int16_t x = 0;
        int16_t y = 0;
        int16_t p = 0;
        int16_t last_grid_height = 0;
        for (JsonVariant v : array)
        {
            int16_t grid_width = v["grid_width"];
            if (grid_width <= 0)
            {
                grid_width = 1;
            }
            else if (grid_width > GRID_WIDTH)
            {
                grid_width = GRID_WIDTH;
            }
            int16_t grid_height = v["grid_height"];
            if (grid_height <= 0)
            {
                grid_height = 1;
            }
            else if (grid_height > GRID_HEIGHT)
            {
                grid_height = GRID_HEIGHT;
            }

            // go to next row/column/page if not enough space is available
            if (GRID_WIDTH - x < grid_width)
            {
                x = 0;
                y += last_grid_height;
            }

            if (GRID_HEIGHT - y < grid_height)
            {
                x = 0;
                y = 0;
                p++;
                last_grid_height = 0;
            }

            int16_t pos_x = 20 + (x * 260);
            int16_t pos_y = 20 + 120 + (y * 260);
            int16_t width = 240 * grid_width + (grid_width - 1) * (x + 1) * 20;
            int16_t height = 240 * grid_height + (grid_height - 1) * (y + 1) * 20;

            x += grid_width;
            last_grid_height = last_grid_height > grid_height ? last_grid_height : grid_height;

            if (v["widgettype"] == "icon")
            {
                EPDGUI_Widget_Icon *_widget_icon = new EPDGUI_Widget_Icon(pos_x, pos_y, width, height);
                _widget_icon->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_icon, p);
            }
            else if (v["widgettype"] == "text")
            {
                EPDGUI_Widget_Text *_widget_text = new EPDGUI_Widget_Text(pos_x, pos_y, width, height);
                _widget_text->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_text, p);
            }
            else if (v["widgettype"] == "doubleswitch")
            {
                EPDGUI_Widget_Double_Switch *_widget_double_switch = new EPDGUI_Widget_Double_Switch(pos_x, pos_y, width, height);
                _widget_double_switch->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_double_switch, p);
            }
            else if (v["widgettype"] == "toggle")
            {
                EPDGUI_Widget_Toggle *_widget_toggle = new EPDGUI_Widget_Toggle(pos_x, pos_y, width, height);
                _widget_toggle->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_toggle, p);
            }
            else if (v["widgettype"] == "icontoggle")
            {
                EPDGUI_Widget_Icon_Toggle *_widget_icon_toggle = new EPDGUI_Widget_Icon_Toggle(pos_x, pos_y, width, height);
                _widget_icon_toggle->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_icon_toggle, p);
            }
            else if (v["widgettype"] == "progress")
            {
                EPDGUI_Widget_Progress *_widget_progress = new EPDGUI_Widget_Progress(pos_x, pos_y, width, height);
                _widget_progress->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_progress, p);
            }
            else if (v["widgettype"] == "multibutton")
            {
                EPDGUI_Widget_Multi_Button *_widget_multi_button = new EPDGUI_Widget_Multi_Button(pos_x, pos_y, width, height, grid_height * 3);
                _widget_multi_button->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_multi_button, p);
            }
            else if (v["widgettype"] == "spinner")
            {
                EPDGUI_Widget_Spinner *_widget_spinner = new EPDGUI_Widget_Spinner(pos_x, pos_y, width, height);
                _widget_spinner->Init(v);
                _page_container->EPDGUI_AddComponent(_widget_spinner, p);
            }
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

    delete _page_container;
}

int Frame_Playground::init(epdgui_args_vector_t &args)
{
    Serial.print("Frame_Playground init");

    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(_key_exit);

    _page_container->Init();
    EPDGUI_AddObject(_page_container);

    return 0;
}

int Frame_Playground::run(void)
{
    M5.update();
    if (M5.BtnL.isPressed() && lastButtonIndex != -1)
    {
        lastButtonIndex = -1;
        _page_container->SetPageIndex(_page_container->GetPageIndex() - 1);
    }
    else if (M5.BtnR.isPressed() && lastButtonIndex != 1)
    {
        lastButtonIndex = 1;
        _page_container->SetPageIndex(_page_container->GetPageIndex() + 1);
    }
    else if (!M5.BtnL.isPressed() && lastButtonIndex == -1)
    {
        lastButtonIndex = 0;
    }
    else if (!M5.BtnR.isPressed() && lastButtonIndex == 1)
    {
        lastButtonIndex = 0;
    }

    return 1;
}
