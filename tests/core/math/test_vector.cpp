#include "catch2/catch_test_macros.hpp"
#include "jml/math/activation_functions.hpp"
#include "jml/math/vector.hpp"

SCENARIO("Vector entries can be get, set, and added to") {
    GIVEN("a vector of some length") {
        jml::Vector V(3);

        WHEN("vector entries are set") {
            REQUIRE_NOTHROW([&V]() {
                V.set_entry(0, 7);
                V.set_entry(1, 8);
                V.set_entry(2, 9);
            }());

            THEN("the vector entries are set as specified") {
                REQUIRE(V.get_entry(0) == 7);
                REQUIRE(V.get_entry(1) == 8);
                REQUIRE(V.get_entry(2) == 9);
            }

            AND_WHEN("vector entries are added to") {
                REQUIRE_NOTHROW(V.add_entry(0, 3));

                THEN("the entry is updated") { REQUIRE(V.get_entry(0) == 10); }
            }
        }
    }
}

SCENARIO("Vector is added to another vector") {
    GIVEN("two vectors of the same length and some values") {
        jml::Vector v1(3), v2(3);

        // Initialize the two vectors
        v1.set_entry(0, 0);
        v1.set_entry(1, 1);
        v1.set_entry(2, 2);

        v2.set_entry(0, 3);
        v2.set_entry(1, 4);
        v2.set_entry(2, 5);

        WHEN("the vectors are added") {
            v1.add(v2);

            THEN("the first vector's entries are changed") {
                REQUIRE(v1.get_entry(0) == 3);
                REQUIRE(v1.get_entry(1) == 5);
                REQUIRE(v1.get_entry(2) == 7);
            }

            THEN("the second vector's entries are unchanged") {
                REQUIRE(v2.get_entry(0) == 3);
                REQUIRE(v2.get_entry(1) == 4);
                REQUIRE(v2.get_entry(2) == 5);
            }
        }

        // Adding vectors of different lengths is UB for now
    }
}

SCENARIO("Activation function is applied to a vector") {
    GIVEN("a vector and an activation function") {
        jml::Vector v(3);
        jml::ReLU act; // Use ReLU for simplicity

        v.set_entry(0, -10);
        v.set_entry(1, 0);
        v.set_entry(2, 10);

        WHEN("the activation function is applied to the vector") {
            v.apply(&act);

            THEN("the vector entries arer correctly modified") {
                REQUIRE(v.get_entry(0) == 0);
                REQUIRE(v.get_entry(1) == 0);
                REQUIRE(v.get_entry(2) == 10);
            }
        }
    }
}
