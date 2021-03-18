#ifndef __EPDGUI_PAGE_CONTAINER_H
#define __EPDGUI_PAGE_CONTAINER_H

#include "epdgui_base.h"
#include "epdgui_container.h"
#include "epdgui_page_indicator.h"
#include <list>

class EPDGUI_Page_Container : public EPDGUI_Base
{
public:
    static const int16_t INDICATOR_HEIGHT = 60;

public:
    EPDGUI_Page_Container(int16_t x, int16_t y, int16_t w, int16_t h);
    ~EPDGUI_Page_Container();
    void Draw(m5epd_update_mode_t mode = UPDATE_MODE_GLD16);
    void Draw(M5EPD_Canvas *canvas);
    void Bind(int16_t event, void (*func_cb)(epdgui_args_vector_t &));
    void UpdateState(int16_t x, int16_t y);
    void EPDGUI_AddComponent(EPDGUI_Base *component, int16_t pageIndex);
    void SetPageIndex(int16_t pageIndex);
    void Init();
    uint32_t GetPageIndex() { return _pageIndex; }

private:
    std::list<EPDGUI_Container *> _pages;
    EPDGUI_Container *GetPageByIndex(int16_t pageIndex);
    EPDGUI_Page_Indicator *_page_indicator;
    int16_t _pageIndex = 0;
};

#endif //__EPDGUI_PAGE_CONTAINER_H