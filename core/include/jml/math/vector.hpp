/**
 * This specifies the data type that the neural network actually processes.
 * Author: Adam Hutchings
 * Date: 09-19-23
 */

#pragma once

#include <functional>

namespace jml {

class Vector {

    int length; // The number of entries in the vector

    double entries[];

public:

     Vector(int length);
    ~Vector();

    // This applies a given function to every component in the vector.
    void apply(std::function<double (double)> fn);

    // This adds every entry in v to this vector.
    void add(Vector& v);

};

}
