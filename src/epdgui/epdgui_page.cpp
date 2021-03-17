#include "epdgui_page.h"

EPDGUI_Page::EPDGUI_Page(int16_t x, int16_t y, int16_t w, int16_t h) : EPDGUI_Base(x, y, w, h)
{
}

EPDGUI_Page::~EPDGUI_Page()
{
    for (std::list<EPDGUI_Container *>::iterator p = _pages.begin(); p != _pages.end(); p++)
    {
        delete (*p);
    }
}

void EPDGUI_Page::Init()
{
    _page_indicator = new EPDGUI_Page_Indicator(_x, _h - INDICATOR_HEIGHT + _y, _w, INDICATOR_HEIGHT, _pages.size());
}

void EPDGUI_Page::SetPageIndex(int16_t pageIndex)
{
    if (pageIndex < 0)
    {
        pageIndex = 0;
    }
    else if (pageIndex >= _pages.size())
    {
        pageIndex = _pages.size() - 1;
    }

    if (pageIndex == _pageIndex)
    {
        return;
    }

    _pageIndex = pageIndex;
    _page_indicator->SetPageIndex(pageIndex);

    M5.EPD.Clear(0);
    UpdateState(-1, -1);
    Draw();
    M5.EPD.UpdateArea(_x, _y, _w, _h, UPDATE_MODE_GC16);
}

void EPDGUI_Page::Draw(m5epd_update_mode_t mode)
{
    if (_ishide)
    {
        return;
    }

    GetPageByIndex(_pageIndex)->Draw(mode);
    _page_indicator->Draw(mode);
}

void EPDGUI_Page::Draw(M5EPD_Canvas *canvas)
{
    if (_ishide)
    {
        return;
    }

    GetPageByIndex(_pageIndex)->Draw(canvas);
    _page_indicator->Draw(canvas);
}

void EPDGUI_Page::Bind(int16_t state, void (*func_cb)(epdgui_args_vector_t &))
{
}

void EPDGUI_Page::UpdateState(int16_t x, int16_t y)
{
    if (!_isenable)
    {
        return;
    }

    GetPageByIndex(_pageIndex)->UpdateState(x, y);
    _page_indicator->UpdateState(x, y);
}

void EPDGUI_Page::EPDGUI_AddComponent(EPDGUI_Base *component, int16_t pageIndex)
{
    // add missing pages
    for (int i = _pages.size(); i < pageIndex + 1; i++)
    {
        _pages.push_back(new EPDGUI_Container(0, 0, _w, _h - INDICATOR_HEIGHT));
    }

    GetPageByIndex(pageIndex)->EPDGUI_AddComponent(component);
}

EPDGUI_Container *EPDGUI_Page::GetPageByIndex(int16_t pageIndex)
{
    auto iterator = _pages.begin();
    std::advance(iterator, pageIndex);
    //_pages.end();
    return *iterator;
}