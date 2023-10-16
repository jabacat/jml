#include <jml/model.hpp>
#include <tuple>

namespace jml {

Model::Model() {}

std::unique_ptr<Vector> Model::apply(Vector& in) {

    std::unique_ptr<Vector> inp = std::make_unique<Vector>(in);
    std::unique_ptr<Vector> outp;

    for (Model_Layer ml : this->layers) {
        outp = ml.matrix.multiply(*inp);
        inp = std::move(outp);
        inp->add(ml.bias_vector);
        inp->apply(ml.act.get());
    }

    return inp;
}

void Model::add_testing_data(std::vector<Vector> ins,
                             std::vector<Vector> outs) {
    return add_testing_data(std::begin(ins), std::end(ins), std::begin(outs),
                            std::end(outs));
}

void Model::add_testing_datum(Vector in, Vector out) {
    testing_data_inputs.push_back(in);
    testing_data_outputs.push_back(out);
}

void Model::clear_testing_data() {
    testing_data_inputs.clear();
    testing_data_outputs.clear();
}

const std::tuple<std::vector<Vector>, std::vector<Vector>>
Model::get_testing_data() const {
    return {this->testing_data_inputs, this->testing_data_outputs};
}

} // namespace jml
