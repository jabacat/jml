/**
 * This is the header file with the specifications for any top-level neural net
 * model. Any useful application of the JML library will most likely include
 * this header.
 * Author: Adam Hutchings
 * 09-17-23
*/

#pragma once

#include <vector>

#include <jml/math/matrix.hpp>
#include <jml/math/vector.hpp>

namespace jml {

// For setting up the model
// Incorporates parameter counts, dimensions, special layers (conv, maxpooling, etc.) and a frequency table for activation functions
/* class Model_Specification {
private:
    unsigned int num_layers;
    // Specifies whether the layer is hidden, convolutional, maxpooling, etc.
    unsigned char* layer_types
    // Specifies dimensions of each layer
    int** layer_dims;
    // 2D array of frequencies (e.g. layer [23] can have [5 ReLU's, 2 sigmoids, 7 binary steps and 0 for other functions])
    // If within a layer the total # of specified functions != the # of perceptrons, there will be a proportional allocation
    unsigned int** actv_func_frequencies_table;
    // Parameters of funcs which use them (currently only would support a single value for a type of function in a layer)
    unsigned int** actv_func_params_table;
}; */

// TODO: separate into different kinds of layers.
class Model_Layer {

friend class Model;

private:
    Matrix matrix;
    Vector bias_vector;

};

// Transition class for loading in/saving model, includes parameters and activation func ID's (enum <-> func pointer mappings?)
class Model_Layer_Compressed {

    friend class Model_Layer;

};

class Model {
    // friend class Model_Layer_Hidden;

public:
    Model();
    std::unique_ptr<Vector> apply(Vector& in);

private:
    std::vector<Model_Layer> layers; // Array of layer addresses

};

}
