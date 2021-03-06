#include "euler.hpp"
#include <fstream>
#include <gtest/gtest.h>
#include <plotter.hpp>
#include <valarray>

using Vec2 = std::valarray<double>;
using Vec2Map = std::map<double, Vec2>;

void calculate_one_free_fall(std::string const& k_string)
{
    double k = std::stod(k_string);

    Vec2 v0 { 2.0, 10.0 };
    Vec2 p0 { 0.0, 0.0 };

    auto force = [k](std::valarray<double> v) {
        return std::valarray<double> { 0.0, -9.81 } - k * v;
    };

    double t_start = 0.0;
    double t_end = 3.0;
    double delta = 0.01;

    double t = t_start;
    Vec2 v = v0;
    Vec2 p = p0;
    Vec2Map data;

    std::string const filename = "free_fall_parabola.pos.k" + k_string + ".dat.txt";
    std::ofstream file { filename };
    while (t <= t_end) {
        // write out the current position
        file << t << " " << p[0] << " " << p[1] << std::endl;
        data[t] = p;

        // integrate velocity first
        // TODO

        // integrate position second
        // TODO

        // increment time
        t += delta;
    }

    Plotter plotter;
    plotter.set_xrange(-0.5, 4.5);
    plotter.set_yrange(0, 5.5);
    plotter.add_data(data);
    auto const picture_filename = "freefall_k" + k_string + "_plot.png";
    plotter.write_png(picture_filename, 800, 800);
}

TEST(EulerApplication, FreeFallTrajectories)
{
    std::vector<std::string> k_values { "0", "0.1", "0.4", "1.0", "4.0" };

    for (auto const& k_string : k_values) {
        calculate_one_free_fall(k_string);
    }
}
