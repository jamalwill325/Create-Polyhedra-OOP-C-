#include "Cylinder.h"



const double Cylinder::PI = 3.14159265359;
/**
 *
 */
Cylinder::Cylinder()
    :Polyhedron("Cylinder"),
     height(0),
     radius(0)
{

}
/**
 *
 */

Cylinder::Cylinder(double r, double h)
    :Polyhedron("Cylinder"),
     height(h),
     radius(r)
{
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}
/**
 *
 */
Cylinder::Cylinder(const Cylinder &src) ///Copy constructor
    :Polyhedron("Cylinder")
{
   this -> radius = src.radius;
   this -> height = src.height;
}
//------------------------HINT------------------------check above

/**
 *
 */
Cylinder::~Cylinder() ///No dynamic memory
{
}

void Cylinder::read(std::istream& ins) ///READ
{
/* do not need a for loop because I am only reading for one Cylinder
*/
  ins >> radius >> height;
  double d = this->getDiameter(); ///Similar to sphere
  boundingBox.setUpperRightVertex(d, d, height);///Similar to sphere
}

void Cylinder::display(std::ostream& outs) const ///DISPLAY
{
    Polyhedron::display(outs);

    outs << "Radius: " << radius
         << " "
         << "Height: " << height;
}

void Cylinder::scale(double scalingFactor) ///SCALE
{
    radius *= scalingFactor;///Must scale both attributes of Cylinder
    height *= scalingFactor;///Must scale both attributes of Cylinder

    Polyhedron::scale(scalingFactor);
}
