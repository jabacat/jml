#include <jml.h>

#include <vector>

#include <jml/math/activation_functions.hpp>
#include <jml/math/vector.hpp>

// This is the global vector of all JML Vector objects.
std::vector<jml::Vector> vectors;

// Look up a Vector in the array.
jml::Vector &vector_lookup_(unsigned vid) {
    jml::Vector &v = vectors.at(vid);
    // TODO -- exception?
    return v;
}

int jml_vector_add(unsigned v1, unsigned v2) {
    jml::Vector &to = vector_lookup_(v1);
    jml::Vector &from = vector_lookup_(v2);
    to.add(from);
    return 0;
}

int jml_vector_add_entry(unsigned vid, int pos, double val) {
    jml::Vector &v = vector_lookup_(vid);
    v.add_entry(pos, val);
    return 0;
}

int jml_vector_apply(unsigned vid, JMLActivFunc val) {
    jml::Vector &v = vector_lookup_(vid);
    jml::ActivationFunction *a;
    switch (val) {
    case JACT_FSIG:
        a = new jml::FastSigmoid();
    case JACT_SIG:
        a = new jml::Sigmoid();
    case JACT_RELU:
        a = new jml::ReLU();
    }
    v.apply(a);
    delete a;
    return 0;
}

double jml_vector_get_entry(unsigned vid, int pos) {
    jml::Vector &v = vector_lookup_(vid);
    return v.get_entry(pos);
}

int jml_vector_get_size(unsigned vid) {
    jml::Vector &v = vector_lookup_(vid);
    return v.get_size();
}

double jml_vector_set_entry(unsigned vid, int pos, double val) {
    jml::Vector &v = vector_lookup_(vid);
    v.set_entry(pos, val);
    return 0;
}

/**
 * Returns the newly created vector ID.
 */
unsigned jml_vector_init(int length) {
    unsigned id = vectors.size();
    vectors.push_back(jml::Vector(length));
    return id;
}

int jml_vector_free(unsigned vid) {
    jml::Vector &v = vector_lookup_(vid);
    // TODO ensure no access can happen in the future
    v.~Vector();
    return 0;
}
