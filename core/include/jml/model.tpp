#pragma once

#include "model.hpp"

namespace jml {

template <typename Iter>
void Model::add_testing_data(Iter inb, Iter ine, Iter otb, Iter ote) {
    testing_data_inputs.insert(std::end(testing_data_inputs), inb, ine);
    testing_data_outputs.insert(std::end(testing_data_outputs), otb, ote);
}

} // namespace jml
