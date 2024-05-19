#include <X11/Xlib.h>
#include <bits/stdc++.h>

int main() {
    Display* dpy = XOpenDisplay(NULL);

    char * str = "Hello world";

    while(true) {
        std::ifstream battCapacityFile("/sys/class/power_supply/BAT0/capacity");

        std::stringstream ss;

        int batCap;
        battCapacityFile >> batCap;

        ss << batCap << '%';

        std::string final = ss.str();
        XStoreName(dpy, DefaultRootWindow(dpy), final.c_str());
	    XSync(dpy, False);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    XCloseDisplay(dpy);
}