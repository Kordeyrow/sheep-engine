#pragma once
#include <utils/singleton.h>

// Enables user to close the app
class App : public Singleton<App> {
    friend class Singleton<App>;
public:
    bool is_closed() const;
    void close();
private:
    App();
private:
    bool _is_closed;
};
