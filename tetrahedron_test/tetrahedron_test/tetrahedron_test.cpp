// tetrahedron_test.cpp :
//
//typedef double f !!!
#include"vector3d.h"
#include<iostream>
//Funtion return true if num1 and num2 have same sign
bool sameSign(double num1, double num2)
{
    return num1 >= 0 && num2 >= 0 || num1 < 0 && num2 < 0;
}
// For a tetrahedron plane(based on vertex1,2,3), check if the point is on the same side as the rest of the vertex (vertex4)
bool SameSide(vector3d vertex1, vector3d vertex2, vector3d vertex3, vector3d vertex4, vector3d point)
{
vector3d normal = (vertex2 - vertex1).cross_product(vertex3 - vertex1);
double dotV4 = normal.dot_product(vertex4 - vertex1);
double dotP = normal.dot_product(point - vertex1);
return sameSign(dotV4, dotP);
}
//For a tetrahedron (based on vertex1,2,3,4), check if the point is inside in this tetrahedron
bool PointInTetrahedron(vector3d vertex1, vector3d vertex2, vector3d vertex3, vector3d vertex4, vector3d point)
{
    return SameSide(vertex1, vertex2, vertex3, vertex4, point) &&
        SameSide(vertex2, vertex3, vertex4, vertex1, point) &&
        SameSide(vertex3, vertex4, vertex1, vertex2, point) &&
        SameSide(vertex4, vertex1, vertex2, vertex3, point);
}
//Square of triangle based on vector1 and vector2
double squareOfTriangle(vector3d vector1, vector3d vector2)
{
    vector3d result = vector1.cross_product(vector2);
    return result.magnitude();
}
//Function for find center of sphere in tetrahedron
vector3d centerSphereInTetra(vector3d vertex1, vector3d vertex2, vector3d vertex3, vector3d vertex4)
{
    // SX - square of triangle opposte from vertex "X"
    double S1 = squareOfTriangle(vertex3 - vertex2, vertex4 - vertex2);
    double S2 = squareOfTriangle(vertex3 - vertex1, vertex4 - vertex1);
    double S3 = squareOfTriangle(vertex4 - vertex1, vertex2 - vertex1);
    double S4 = squareOfTriangle(vertex3 - vertex1, vertex2 - vertex1);
    double sumS = S1 + S2 + S3 + S4;
    vector3d result = { (S1 * vertex1.x + S2 * vertex2.x + S3 * vertex3.x + S4 * vertex4.x) / sumS,(S1 * vertex1.y + S2 * vertex2.y + S3 * vertex3.y + S4 * vertex4.y) / sumS,(S1 * vertex1.z + S2 * vertex2.z + S3 * vertex3.z + S4 * vertex4.z) / sumS };
    return result;
}
int main()
{
    vector3d tetra[4];
    vector3d vertex1 = { 1,3,6 };
    vector3d vertex2 = { 2,2,1 };
    vector3d vertex3 = { -1,0,1 };
    vector3d vertex4 = { -4,6,-3 };
    vector3d point = { -0.5,2.75,1.25 };
    std::cout << std::boolalpha;
    std::cout << "This point in tetrahedron: " << PointInTetrahedron(vertex1, vertex2, vertex3, vertex4, point)<<std::endl;

    vector3d centerTetra = centerSphereInTetra(vertex1, vertex2, vertex3, vertex4);
    std::cout << "Center of sphere in tetrahedron (point equidistant from surface): ";
    centerTetra.disp();
    return 0;
}

