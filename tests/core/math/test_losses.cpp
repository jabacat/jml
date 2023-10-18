#include "catch2/catch_test_macros.hpp"
#include <jml/math/loss_functions.hpp>
#include <jml/math/vector.hpp>

SCENARIO("Loss can be calculated from two vectors") {
    GIVEN("Two vectors of the same size") {
        jml::Vector vec1(3), vec2(3);
        vec1.set_entry(0, 1.0);
        vec1.set_entry(1, 2.0);
        vec1.set_entry(2, 3.0);
        vec2.set_entry(0, 4.0);
        vec2.set_entry(1, 2.0);
        vec2.set_entry(2,-2.0);
        auto loss = jml::l2lf(vec1, vec2);
        REQUIRE(loss == 5.0);
    }
}
