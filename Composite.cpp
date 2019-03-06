#include "Polyhedron.h"
#include "Composite.h"

/**
 *
 */
Composite::Composite()
    :Polyhedron("Composite"),
     numPolyhedra(0),
      polyhedra(nullptr)
{
}

Composite::Composite(const Composite &src) ///Copy constructor, this is for the clone method. 1st of BIG 3
    :Polyhedron("Composite"),
    numPolyhedra(0),
      polyhedra(nullptr)
{
   this -> numPolyhedra = src.numPolyhedra;
   ///this -> polyhedra = src.polyhedra;

   /// numPolyhedra = src.numPolyhedra; ///How any does source haveMust have the same number to start Step1
   this -> polyhedra = new Polyhedron*[numPolyhedra]; ///Brand new set of distinct array of pointers. Step1

   for (int i = 0; i < numPolyhedra; i++) ///Traverse. ALWAYS for arrays. Do not think just do.
   {
       ///copy each data that the pointer is pointing
       polyhedra[i]= (src.polyhedra[i])->clone();
   }
   boundingBox = src.boundingBox; ///Make these to this

   std::cerr << "End of copy\n";

}

/**
 *
 */
Composite::~Composite() ///Destructor. 2ND of big 3.
{
    if(polyhedra != nullptr)
    {
        for (int i = 0; i < numPolyhedra; i++)
        {
            delete polyhedra[i];
        }

        delete[] polyhedra;
        polyhedra = nullptr; /// necesary
    }
}
//------------------------HINT------------------------

/**
 *
 */
void Composite::read(std::istream& ins) ///READ each shape.
{
  ins >> numPolyhedra;

  polyhedra = new Polyhedron*[numPolyhedra]; ///Brand new set of distinct array of pointers. Step1

  for (int i = 0; i < numPolyhedra; i++) ///Need to allocate the new array. There may be more than one shape.
  {
    ins >> polyhedra[i];
    boundingBox.merge(polyhedra[i]->getBoundingBox());
  }
  std::cerr << "End of read\n";
}


/**
 *
 */
void Composite::display(std::ostream& outs) const
{
    Polyhedron::display(outs);

    outs << numPolyhedra << " polyhedra" << "\n";

    for (int i = 0; i < numPolyhedra; i++)
    {
        ///polyhedra[i]->display(outs);
        outs << "  " << (*polyhedra[i]) << "\n";
    }
}

/**
 *
 */
void Composite::scale(double scalingFactor)
{
    for (int i = 0; i < numPolyhedra; i++)
    {
        polyhedra[i] -> scale(scalingFactor);
    }
    Polyhedron::scale(scalingFactor);
}

/**
 *
 */
Composite& Composite::operator=(Composite rhs) ///Big 3
{
    swap(*this, rhs);

    return *this;
}

/**
 *
 */
void swap(Composite& lhs, Composite& rhs)
{
    using std::swap;

    std::swap(lhs.numPolyhedra, rhs.numPolyhedra);
    std::swap(lhs.polyhedra, rhs.polyhedra);

    // Friend functions allow direct access
    // to all data members.
    // This is well known 3-line
    // swap code
    BoundingBox temp = lhs.boundingBox;
    lhs.boundingBox  = rhs.boundingBox;
    rhs.boundingBox  = temp;
}



