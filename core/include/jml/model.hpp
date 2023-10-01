/**
 * This is the header file with the specifications for any top-level neural net
 * model. Any useful application of the JML library will most likely include
 * this header.
 * Author: Adam Hutchings
 * 09-17-23
*/

#pragma once

namespace jml {

class Model_Layer {
  friend class Layer_Actv_Funcs_List;

private:
  Matrix* layer_matrix;
  Vector* layer_bias_vector;
  // Array of pointers to function pointers (because lonely function pointers might not be contiguous in memory)
  // The size of this will be dictated by the associated matrix
  double (*layer_actv_funcs_arr[])();
};

// Transition class for loading in/saving model, includes parameters and activation func ID's (enum <-> func pointer mappings?)
class Model_Layer_Compressed {
  friend class Model_Layer;

};

class Model {
  friend class Model_Layer;

public:
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
