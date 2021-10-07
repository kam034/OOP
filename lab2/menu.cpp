#include "menu.h"
#include "verzier.h"

/*1) Определить состояние класса.

2) Разработать необходимые конструкторы и методы получения и изменения параметров, определяющих кривую.

3) Вернуть координату y в декартовой системе координат, принадлежащую верзьере в зависимости от x.

4) Вернуть координаты точек перегиба верзьеры.

5) Вернуть площадь полосы между верзьерой и ее асимптотой.

6) Вернуть объем тела, полученной вращением полосы из пункта 6 вокруг асимптоты.

7)Вернуть текстовое представление уравнения верзьеры в декартовой системе координат в виде строки (char[] или wchar_t[]).
*/
#define choice 6

//template <class N>
//int check_val(N &a) {
//    std::cin >> a;
//    while (!std::cin.good() || a <= 0) {
//        std::cin.clear();
//        std::cin.ignore();
//        std::cout << "Incorrect data\nPlease, repeat->" << std::endl;
//        std::cin >> a;
//    }
//    return 1;
//}

void make_choice(int &a) {
    std::cin >> a;
    while (!std::cin.good() || (a < 0) || a > choice) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect data\nPlease, repeat->" << std::endl;
        std::cin >> a;
    }
}


void print_menu() {
    std::cout << "----Functions for working with verzier agnesi----" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << "1. Enter the radius of the verzier circle" << std::endl;
    std::cout << "2. Return the y coordinate belonging to the versier depending on x" << std::endl;
    std::cout << "3. Return the coordinates of the versier inflection points" << std::endl;
    std::cout << "4. Return the square of the strip between the versier and its asymptote" << std::endl;
    std::cout << "5. Return the volume of the rotation body of the strip around the asymptote" << std::endl;
    std::cout << "6. Return the textual representation of the verzier equation" << std::endl;
    std::cout << "Make a choice, please -> " << std::endl;
}

void menu(prog2::Verzier &a) {
    int ch;
    while(true) {
        print_menu();
        make_choice(ch);
        if (ch == 0) {
            break;
        }
        if (ch == 1) {
            a.setD();
        }
        if (ch == 2) {
            double y = a.get_Y();
            std::cout << "Y coordinate is : " << y << std::endl;
        }
        if (ch == 3) {
            double ar[4];
            a.inflection_points(ar);
            std::cout << "(X1 = " << ar[0] << ", " << "Y1 = " << ar[1] << "); " << "(X2 = " << ar[2] << ", " << "Y2 = " << ar[3] << ")" << std::endl;
         }
        if (ch == 4 ) {
            double s = a.square();
            std::cout << "Square = " << s << std::endl;
        }
        if (ch == 5) {
            double v = a.volume();
            std::cout << "Volume = " << v << std::endl;
        }
        if (ch == 6) {
            char* s = a.formula();
            std::cout << "Equation: " << s << std::endl;
        }
    }
}


