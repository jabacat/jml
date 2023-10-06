#include <jml/model.hpp>

namespace jml {

std::unique_ptr<Vector> Model::apply(Vector& in) {

    std::unique_ptr<Vector> inp  = std::make_unique<Vector>(in);
    std::unique_ptr<Vector> outp;

    for (Model_Layer ml : this->layers) {
        outp = ml.matrix.multiply(std::move(inp));
        inp = std::move(outp);
        inp->add(ml.bias_vector);
        inp->apply(ml.act);
    }

    return inp;

}

void Model::add_testing_data(std::vector<Vector> ins, std::vector<Vector> outs) {
    inputs .insert(std::end(inputs),  std::begin(ins),  std::end(ins));
    outputs.insert(std::end(outputs), std::begin(outs), std::end(outs));
}

void Model::add_testing_datum(Vector in, Vector out) {
    inputs .push_back(in);
    outputs.push_back(out);
}

void Model::clear_testing_data() {
    inputs .clear();
    outputs.clear();
}

}
