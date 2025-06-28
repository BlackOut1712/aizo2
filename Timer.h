#ifndef TIMER_H  
#define TIMER_H

#include <chrono>

class Timer
{
public:
    Timer(); // Initialize and prepare to start.
    void reset(); // Reset timer.
    int start(); // Start timer.
    int stop(); // Stop timer.
    int result(); // Return elapsed time [us].

private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;
    int elapsed_time; // Elapsed time in microseconds
};

#include "Timer.cpp"

#endif