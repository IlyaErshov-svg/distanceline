// distanceline.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "distance3D.h"
#include "ownLinePoint.h"

int main()
{
    Line line1 = { Point{0.,0.,0.},Point{3.,0.,0.}};
    Line line2 = { Point{2.,-2.,3.},Point{-2.,2.,3.}};
    double distance = distance3Dbetweenlines<Point, Line>(line1, line2);
    std::cout << distance << std::endl;
    return 0;
}
