#ifndef LAB2_CURVE_VERZIER_H
#define LAB2_CURVE_VERZIER_H

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <limits>


namespace prog2 {

    template <class N>
    int check_val(N &a) {
        std::cin >> a;
        while (!std::cin.good() || a <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect data\nPlease, repeat->" << std::endl;
            std::cin >> a;
        }
        return 1;
    }

    class Verzier {
    private:
        double D;  //диаметр окружности

    public:
        Verzier();
        Verzier(double a);
        double getD() const { return D; }
        void setD();
        double get_Y() const;
        void inflection_points(double points[4]) const;
        double square() const;
        double volume() const;
        char* formula() const;
    };
}

#endif //LAB2_CURVE_VERZIER_H
