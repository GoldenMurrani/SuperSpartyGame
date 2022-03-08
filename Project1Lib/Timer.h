/**
 * @file Timer.h
 * @author Vijay
 *
 *
 */

#ifndef PROJECT1_TIMER_H
#define PROJECT1_TIMER_H

class Timer {
private:
    double mMinute = 0.0;
    double mSecond = 0.0;

public:
    /// Default constructor (disabled)
    Timer() = delete;

    /// Copy constructor (disabled)
    Timer(const Timer&) = delete;

    void Update(double elapsed);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void Reset();

};

#endif //PROJECT1_TIMER_H
