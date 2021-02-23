//
// Created by PERHAPS-MACHINE on 2/23/2021.
//

#ifndef CREATIONTOOL_SCREENWINDOW_H
#define CREATIONTOOL_SCREENWINDOW_H

namespace CT
{
    struct ScreenWindowInfo
    {
        int width, height;
    };

    class ScreenWindow {
    public:
        //Set the window's title, if supported.
        virtual void SetTitle(const char* title);
        //Swap the double buffered window
        virtual void SwapBuffers();
        //Get some basic info about the window
        virtual ScreenWindowInfo GetInfo();

    };
}

#endif //CREATIONTOOL_SCREENWINDOW_H
