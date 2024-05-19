#include <X11/Xlib.h>
#include <bits/stdc++.h>
#include <ctime>
#include "fmt/core.h"
#include "fmt/chrono.h"

int main() {
    Display* dpy = XOpenDisplay(NULL);

    while(true) {
        std::ifstream battCapacityFile("/sys/class/power_supply/BAT0/capacity");
        int batCap;
        battCapacityFile >> batCap;

        auto time = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(time);


        std::string output = fmt::format("Battery: {} | Date: {:%A, %B %d %Y | %r}", batCap, fmt::localtime(t));
        XStoreName(dpy, DefaultRootWindow(dpy), output.c_str());
	    XSync(dpy, False);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    XCloseDisplay(dpy);
}