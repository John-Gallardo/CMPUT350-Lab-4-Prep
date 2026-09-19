#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <cstdint>

class Timer {
    public:
        // aliases
        using Nanos   = std::chrono::nanoseconds;
        using Micros  = std::chrono::microseconds;
        using Millis  = std::chrono::milliseconds;
        using Seconds = std::chrono::seconds;
        using Minutes = std::chrono::minutes;
        using Hours   = std::chrono::hours;

        // constructor
        Timer() {
            // TODO:
        }

        // resets state of timer
        void restart() {
            // TODO:
        }

        // returns time unit T since timer was last clicked/restarted/constructed
        template <typename T>
        uint64_t click() {
            // TODO:
        }
    private:

};

#endif  // TIMER_H
