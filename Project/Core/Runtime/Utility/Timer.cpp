//
// Created by PERHAPS-MACHINE on 2/26/2021.
//

#include "Timer.h"

namespace CT
{
    void Timer::Start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    double Timer::Now() {
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_seconds = now-startTime;

        return elapsed_seconds.count();
    }

}