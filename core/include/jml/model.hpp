/**
 * This is the header file with the specifications for any top-level neural net
 * model. Any useful application of the JML library will most likely include
 * this header.
 * Author: Adam Hutchings
 * 09-17-23
*/

#pragma once

namespace jml {

// For setting up the model
// Incorporates parameter counts, dimensions, special layers (conv, maxpooling, etc.) and a frequency table for activation functions
class Model_Specification {
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
};

class Model_Layer {
public:
    virtual ~Model_Layer() = 0;
};

class Model_Layer_Hidden : private Model_Layer {
public:
    Model_Layer_Hidden(int dim1, int dim2, unsigned int* actv_func_frequencies, double* actv_func_params);
    ~Model_Layer_Hidden() {

    };

private:
    // Structs here already point to their data
    Matrix layer_matrix;
    Vector layer_bias_vector;
    // Array of ActivationFunction's
    // The size of this will be dictated by the associated matrix
    ActivationFunction* layer_actv_funcs;

};

Model_Layer_Hidden::Model_Layer_Hidden(int dim1, int dim2, unsigned int* actv_func_frequencies, double* actv_func_params) {
    layer_matrix = Matrix(dim1, dim2 - 1);
    layer_bias_vector = Vector(dim1);
    layer_actv_funcs = new ActivationFunction(dim1);

    // NOTE: Replace this constant when more functions get added
    int num_of_actv_funcs_ids = 4;

    int curr_perceptron = 0;
    for (int curr_func_id = 0; curr_func_id < num_of_actv_funcs_ids; curr_func_id++) {
        // Currently, this checks for a 1 and initializes the perceptrons with the corresponding function
        if (actv_func_frequencies[curr_func_id] == 1) {
            switch(curr_func_id) {
                case 0:
                    while (curr_perceptron < dim1) {
                        layer_actv_funcs[curr_perceptron] = ReLU();
                        curr_perceptron++;
                    }
                    break;
                case 1:
                    while (curr_perceptron < dim1) {
                        layer_actv_funcs[curr_perceptron] = LeakyReLU(actv_func_params[1]);
                        curr_perceptron++;
                    }
                    break;
                case 2:
                    while (curr_perceptron < dim1) {
                        layer_actv_funcs[curr_perceptron] = Sigmoid();
                        curr_perceptron++;
                    }
                    break;
                case 3:
                    while (curr_perceptron < dim1) {
                        layer_actv_funcs[curr_perceptron] = FastSigmoid(actv_func_params[3]);
                        curr_perceptron++;
                    }
                    break;
            }
            break;
        }

        /* NOTE: This commented-out version allows for mixing/matching and could be optimized with type comparisons
         * curr_num_funcs_to_place is initialized outside the loops with 0

        curr_num_funcs_to_place = actv_func_frequencies[curr_func_id];
        if (curr_func_id == 0) {
            while (curr_num_funcs_to_place > 0) {
                layer_actv_funcs[curr_perceptron] = ReLU();
                curr_perceptron++;
                curr_num_funcs_to_place--;
            }
        } elseif (curr_func_id == 1) {
            while (curr_num_funcs_to_place > 0) {
                layer_actv_funcs[curr_perceptron] = Sigmoid();
                curr_perceptron++;
                curr_num_funcs_to_place--;
            }
        }

        * ...and similarily for the other functions.
        */
    }
};

Matrix::~Matrix() {
    delete this->entries;
}

// Transition class for loading in/saving model, includes parameters and activation func ID's (enum <-> func pointer mappings?)
class Model_Layer_Compressed {
  friend class Model_Layer;

};

class Model {
  friend class Model_Layer_Hidden;

public:
  Model();
  std:unique_ptr<Vector> apply(Vector& in);

private:
  Model_Layer* layers_arr; // Array of layer addresses
  unsigned int num_layers; // A.k.a. the number of entries in layers_arr
};

}

std:unique_ptr<Vector> Model::apply(Vector& in) {
    for (int curr_layer_num = 0; curr_layer_num < num_layers; curr_layer_num++) {
        
    }
}
