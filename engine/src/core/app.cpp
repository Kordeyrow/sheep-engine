#include "pch.h"
#include "app.h"

App::App() : _is_closed{ false }
{
}

bool App::is_closed() const
{
    return _is_closed;
}

void App::close()
{
    _is_closed = true;
}
