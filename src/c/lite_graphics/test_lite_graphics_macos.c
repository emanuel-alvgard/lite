#include "lite_graphics_macos.h"

int main(int argc, char** argv)
{
    
    struct objc_class *pool = objc_getClass("NSAutoreleasePool");
    
    /*
    if (!pool)
    {
        return -1;
    }
    pool = objc_msgSend(pool, sel_registerName("alloc"));
    if (!pool)
    {
        return -1;
    }
    pool = objc_msgSend(pool, sel_registerName("init"));

    app = objc_msgSend(objc_getClass("NSApplication"),
                       sel_registerName("sharedApplication"));

    NSRunAlertPanel(CFSTR("Testing"),
                    CFSTR("This is a simple test to display NSAlertPanel."),
                    CFSTR("OK"), NULL, NULL);

    objc_msgSend(pool, sel_registerName("release"));
    */
    return 0;
}