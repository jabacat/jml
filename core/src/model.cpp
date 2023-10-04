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

}
