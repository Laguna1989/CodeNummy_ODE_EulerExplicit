#ifndef RANDU_HPP_GUARD
#define RANDU_HPP_GUARD

#include <cmath>
#include <cstdint>
#include <functional>
#include <map>


template <typename T>
T explicit_euler_integrate_one_step(std::function<T(T)> func, T y0, double delta)
{
    return func(y0) * delta + y0;

    // fake implementataion
    //return y0;
}

template <typename T>
std::map<double, T> explicit_euler_integrate(
    std::function<T(T)> func, T y0, double delta, double t_start, double t_end)
{
    std::map<double, T> values;
    values[t_start] = y0;

    // to be implemented by user
    double t = t_start;
    T y = y0;
    while (t <= t_end)
    {
        values[t] = y;
        y = explicit_euler_integrate_one_step(func, y , delta);
        t += delta;
    }
    return values;

    // fake implementation
//    std::map<double, T> values;
//    values[42.0] = y0;
//    return values;
}


#endif