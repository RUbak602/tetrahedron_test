// tetrahedron_test.cpp :
//
//typedef double f !!!
#include"vector3d.h"
#include<iostream>
bool sameSign(double num1, double num2)
{
    return num1 >= 0 && num2 >= 0 || num1 < 0 && num2 < 0;
}
bool SameSide(vector3d vertex1, vector3d vertex2, vector3d vertex3, vector3d vertex4, vector3d point)
{
vector3d normal = (vertex2 - vertex1).cross_product(vertex3 - vertex1);
double dotV4 = normal.dot_product(vertex4 - vertex1);
double dotP = normal.dot_product(point - vertex1);
return sameSign(dotV4, dotP);
}
bool PointInTetrahedron(vector3d vertex1, vector3d vertex2, vector3d vertex3, vector3d vertex4, vector3d point)
{
    return SameSide(vertex1, vertex2, vertex3, vertex4, point) &&
        SameSide(vertex2, vertex3, vertex4, vertex1, point) &&
        SameSide(vertex3, vertex4, vertex1, vertex2, point) &&
        SameSide(vertex4, vertex1, vertex2, vertex3, point);
}

int main()
{
    vector3d tetra[4];
    vector3d vertex1;
    vector3d vertex2;
    vector3d vertex3;
    vector3d vertex4;
    vector3d point;
    double x;
    double y;
    double z;
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << "Enter cordinates " << i +1 << " vertex of tetrahedron (with gaps like x y z)\n";
        std::cin >> x >> y >> z;
        tetra[i] = { x,y,z };
    }
    std::cout << "Enter cordinates of point (with gaps like x y z) \n";
    std::cin >> x >> y >> z;
    point = { x, y, z };
    /*for (size_t i = 0; i < 3; i++)
    {
        tetra[i].disp();
    }*/
    std::cout << std::boolalpha;
    std::cout << "This point in tetrahedron: " << PointInTetrahedron(tetra[0], tetra[1], tetra[2], tetra[3], point);
    return 0;
}

