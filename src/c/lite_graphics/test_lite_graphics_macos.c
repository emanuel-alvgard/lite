#include "lite_graphics_macos.h"



int main() {
    return 0;
}


/*
enum {
        RECT_X = 20,
        RECT_Y = 20,
        RECT_WIDTH = 10,
        RECT_HEIGHT = 10,

        WIN_X = 10,
        WIN_Y = 10,
        WIN_WIDTH = 100,
        WIN_HEIGHT = 100,
        WIN_BORDER = 1
};



int main()
{
    Display *display;
    Window window;
    XEvent event;
    int screen;

    display = XOpenDisplay(NULL);

    screen = DefaultScreen(display);

    window = XCreateSimpleWindow(
        display, 
        RootWindow(display, screen), 
        WIN_X, 
        WIN_Y, 
        WIN_WIDTH, 
        WIN_HEIGHT,
        WIN_BORDER, 
        BlackPixel(display, screen), 
        WhitePixel(display, screen)
        );

        /* process window close event through event handler so XNextEvent does not fail 
        Atom del_window = XInternAtom(display, "WM_DELETE_WINDOW", 0);
        XSetWMProtocols(display, window, &del_window, 1);

        /* select kind of events we are interested in 
        XSelectInput(display, window, ExposureMask | KeyPressMask);

        /* display the window 
        XMapWindow(display, window);

        /* event loop 
        while (1) {
                XNextEvent(display, &event);

                if (event.type == KeyPress) {}
                else if (event.type == ClientMessage) { break; }
                else if (event.type == Expose) {
                    /* draw the window 
                    XFillRectangle(
                        display, 
                        window, 
                        DefaultGC(display, screen), 
                        RECT_X, 
                        RECT_Y, 
                        RECT_WIDTH, 
                        RECT_HEIGHT
                        );
                }
        }

        /* destroy window 
        XDestroyWindow(display, window);

        /* close connection to server 
        XCloseDisplay(display);

    return 0;
}
*/
