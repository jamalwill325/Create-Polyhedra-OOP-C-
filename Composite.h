#ifndef COMPOSITE_H_INCLUDED
#define COMPOSITE_H_INCLUDED

#include <iostream>
#include <string>

#include "Polyhedron.h"

class Composite : public Polyhedron {
    private:
        /**
         * Number of polyhedra the
         * are part of this composite polyhedron
         */
        int numPolyhedra; ///Keeps track of size

        /**
         * Collection of polyhedra of which
         * this composite polyhedron is composed
         */
        Polyhedron** polyhedra; ///Pointer to an array of pointers

    public:
        /**
         * Default Constructor
         */
        Composite();

        /**
         * Copy Constructor
         */
        Composite(const Composite& src);

        /**
         * Destructor
         */
        virtual ~Composite();



        virtual Polyhedron* clone() const;

        /**
         * Read all component polyhedra
         *
         * @pre polyhedra == nullptr
         *   && numPolyhedra == 0
         */
        virtual void read(std::istream& ins);

        /**
         * Print all polyhedra
         */
        virtual void display(std::ostream& outs) const;

        /**
         * Scale all polyhedra
         */
        virtual void scale(double scalingFactor);

        /**
         * Assignment Operator
         */
        Composite& operator=(Composite rhs); ///Will use copy and swap method

        /**
         * Swap the contents of two `Composite`s
         * <p>
         * I am using a friend function here and only here (under protest)
         */
        friend
        void swap(Composite& lhs, Composite& rhs);
};

/**
 *
 */
inline
Polyhedron* Composite::clone() const
{
    return new Composite(*this);
}



#endif // COMPOSITE_H_INCLUDED
