#ifndef CYLINDER_H_INCLUDED
#define CYLINDER_H_INCLUDED

#include <iostream>
#include <string>

#include "Polyhedron.h"

class Cylinder : public Polyhedron {
    private:
        static const double PI; ///pi

        double height; ///Length of height Recording 39:00
        double radius; ///length of radius

    public:
        /**
         * Default Constructor
         */
        Cylinder();

        /**
         * Construct a cylinder with
         * specified height and radius
         */
        Cylinder(double r, double h);


        Cylinder(const Cylinder &src); ///Copy constructor
        /**
         * Destructor
         */
        ~Cylinder(); ///No virtual?

        double getRadius() const; ///return radius

        void setRadius(double r); ///Change the radius

        double getHeight() const; ///return height

        void setHeight(double h); ///change the height

        double getDiameter() const; ///gets diameter of Cylinder

        void setDiameter(); ///change diameter of Cylinder

        virtual double area() const; ///Computer area. GO to .cpp OPTIONAL

        virtual Polyhedron* clone() const; ///Return a new duplicate Cylinder
        virtual void read(std::istream& ins); ///Read all component polyhedra
        virtual void scale(double scalingFactor); ///Scale all polyhedra
        virtual void display(std::ostream& outs) const; ///Prints out Cylinder
};

/**
* radius inline
*/
inline
double Cylinder::getRadius() const ///always call the function not variable type
{
    return radius;
}

inline
void Cylinder::setRadius( double r)
{
    radius = r;
}
/**
* Diameter inline
*/
inline
double Cylinder::getDiameter() const
{
    return (2 * radius);
}
/**
* area inline
*/
inline
double Cylinder::area() const ///do not include virtual keyword in its definition
{
    return (PI * radius * height);
}

/**
* clone inline is a protector or wrapper for the copy constructor
*/
inline
Polyhedron* Cylinder::clone() const
{
    return new Cylinder(*this); ///Grab this cylinder, dereference it and then pass it in to the copy constructor
}

#endif // CYLINDER_H_INCLUDED
