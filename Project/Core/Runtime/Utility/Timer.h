//
// Created by PERHAPS-MACHINE on 2/26/2021.
//

#ifndef CREATIONTOOL_TIMER_H
#define CREATIONTOOL_TIMER_H
#include <chrono>

namespace CT
{
    class Timer {
    public:
        Timer() { Start(); }

        //Mark the start of the difference.
        void Start();
        //Returns the difference between now and when Start() was called in seconds.
        double Now();

    private:
        std::chrono::time_point<std::chrono::steady_clock> startTime;
    };

}

#endif //CREATIONTOOL_TIMER_H
