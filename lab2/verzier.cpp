#include "verzier.h"

prog2::Verzier::Verzier() {
    D = 3;
    std::cout << "constructor1" << std::endl;
}

prog2::Verzier::Verzier(double a) {
    if (a <= 0) {
        throw std::invalid_argument("Invalid radius\n");
    }
    D = a;
}

void prog2::Verzier::setD() {
    std::cout << "Enter the diametr ->" << std::endl;
    double r;
    check_val(r);
    D = r;
}

double prog2::Verzier::get_Y() const {
    double y, x;
    std::cout << "Enter the X ->" << std::endl;
    check_val(x);
    y = pow(getD(), 3) / (pow(x, 2) + pow(getD(), 2));
    return y;
}

void prog2::Verzier::inflection_points(double points[4]) const {
    points[0] = getD()/sqrt(3);
    points[1] = 3*getD()/4;
    points[2] = -getD()/sqrt(3);
    points[3] = 3*getD()/4;
}

double prog2::Verzier::square() const {
    return M_PI*pow(getD(), 2);
}

double prog2::Verzier::volume() const {
    return pow(M_PI, 2)*pow(getD(), 3)/2;
}

char* prog2::Verzier::formula() const { // y = D^3 / (D*2 + x^2);
    double d = getD();
    char s1[80] = "y = ";
    char a[20];
    sprintf(a, "%0.2f", d);  // d выводится с 2 цифрами после запятой
    char s3[] = "^3 / (x^2 + ";
    char s4[] = "^2)";
    char* s = strcat(s1, a);
    s = strcat(s, s3);
    s = strcat(s, a);
    s = strcat(s, s4);
    std::cout << s << std::endl;
    return s;
}
