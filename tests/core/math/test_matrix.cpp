#include "catch2/catch_test_macros.hpp"
#include "jml/math/vector.hpp"
#include <jml/math/matrix.hpp>
#include <memory>
#include <stdexcept>

SCENARIO("Matrix entries can be set and get", "[matrix]") {
    GIVEN("a matrix of some size") {
        // Create and initialize matrix
        jml::Matrix m(2, 3);

        THEN("the size is correct") {
            REQUIRE(m.get_n_rows() == 2);
            REQUIRE(m.get_n_cols() == 3);
        }

        WHEN("the values are set") {
            // Set matrix
            // TODO: should probably check for no throw here
            REQUIRE_NOTHROW([&m]() {
                m.set_entry(0, 0, 1);
                m.set_entry(1, 0, 2);
                m.set_entry(0, 1, 3);
                m.set_entry(1, 1, 4);
                m.set_entry(0, 2, 5);
                m.set_entry(1, 2, 6);
            }());
            
            THEN("the stored values are correct") {
                REQUIRE(m.get_entry(0, 0) == 1);
                REQUIRE(m.get_entry(1, 0) == 2);
                REQUIRE(m.get_entry(0, 1) == 3);
                REQUIRE(m.get_entry(1, 1) == 4);
                REQUIRE(m.get_entry(0, 2) == 5);
                REQUIRE(m.get_entry(1, 2) == 6);
            }
        }

        THEN("getting and setting out-of-bound entries throws out of range") {
            REQUIRE_THROWS_AS(m.set_entry(999, 999, 1.0), std::out_of_range);

            REQUIRE_THROWS_AS(m.get_entry(999, 999), std::out_of_range);
        }
    }
}

SCENARIO("Matrix is correctly multiplied with vector",
         "[matrix][vector]") {
    GIVEN("a matrix and vector with some values") {
        jml::Matrix m(2, 3);
        jml::Vector V(3);

        THEN("the matrix and vector have the specified dimensions") {
            REQUIRE(m.get_n_rows() == 2);
            REQUIRE(m.get_n_cols() == 3);
            REQUIRE(V.get_size() == 3);
        }
        WHEN("the matrix and vector are initialized") {
            // Initialize matrix to some values
            // TODO: add fuzzing?
            m.set_entry(0, 0, 1);
            m.set_entry(1, 0, 2);
            m.set_entry(0, 1, 3);
            m.set_entry(1, 1, 4);
            m.set_entry(0, 2, 5);
            m.set_entry(1, 2, 6);

            // Initialize vector to some values
            V.set_entry(0, 7);
            V.set_entry(1, 8);
            V.set_entry(2, 9);

            AND_WHEN("matrix and vector are multiplied") {
                auto ret = m.multiply(V);

                THEN("vector has length equal to number of rows") {
                    REQUIRE(ret->get_size() == 2);

                    AND_THEN("resultant vector values are correct") {
                        REQUIRE(ret->get_entry(0) == 76);
                        REQUIRE(ret->get_entry(1) == 100);
                    }
                }
            }
        }
    }
}
