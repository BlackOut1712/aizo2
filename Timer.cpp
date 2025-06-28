#include <iostream>
#include "Timer.h"
#include <chrono>
#include <thread>

Timer::Timer() {
    this->reset();
}

int Timer::start() {
    // This function starts the timer and sets the start time
    this->start_time = std::chrono::high_resolution_clock::now();
    return 0; 
}

int Timer::stop() {
    // This function stops the timer and sets the end time
    this->end_time = std::chrono::high_resolution_clock::now();
    return 0; 
}

int Timer::result() {
    // This function calculates the elapsed time and returns it
    this->elapsed_time = std::chrono::duration_cast<std::chrono::microseconds>(this->end_time - this->start_time).count();
    return this->elapsed_time;
}

void Timer::reset() {
    // This function resets the elapsed time.
    this->elapsed_time = 0;
}
