/**
 * This file provides the C API to JML.
 * Author: Adam Hutchings
 * Date: 10-07-23
 */

#ifndef JML_API_H
#define JML_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * This adds the entries in v2 to v1.
 */
int jml_vector_add(unsigned v1, unsigned v2);

/**
 * This adds val to the pos-th entry in the vector vid.
 */
int jml_vector_add_entry(unsigned vid, int pos, double val);

enum JMLActivFunc {
    JACT_FSIG,
    JACT_SIG,
    JACT_RELU,
};

/**
 * We use an enum to specify a type of activation function. TODO: make this
 * fully equivalent to the C++ API.
 */
int jml_vector_apply(unsigned vid, enum JMLActivFunc val);

double jml_vector_get_entry(unsigned vid, int pos);

int jml_vector_get_size(unsigned vid);

double jml_vector_set_entry(unsigned vid, int pos, double val);

/**
 * Returns the newly created vector ID.
 */
unsigned jml_vector_init(int length);

int jml_vector_free(unsigned vid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* JML_API_H */
