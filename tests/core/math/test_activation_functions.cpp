#include "catch2/catch_test_macros.hpp"
#include "catch2/matchers/catch_matchers.hpp"
#include "catch2/matchers/catch_matchers_floating_point.hpp"
#include "jml/math/activation_functions.hpp"

TEST_CASE("FastSigmoid function", "[activation_function]") {
    jml::FastSigmoid act;

    // FIXME: I don't know what mathematically significant values to check so
    // here's some random ones
    // FIXME: FastSigmoid impl appears to have forgotten the constant offset
    REQUIRE_THAT(act.f(-1), Catch::Matchers::WithinRel(-0.25, 0.00001));
    REQUIRE_THAT(act.f(0), Catch::Matchers::WithinRel(0, 0.00001));
    REQUIRE_THAT(act.f(1), Catch::Matchers::WithinRel(0.25, 0.00001));
}

TEST_CASE("Sigmoid activation function", "[activation_function]") {
    jml::Sigmoid act;

    REQUIRE_THAT(act.f(-1), Catch::Matchers::WithinRel(0.2689414, 0.00001));
    REQUIRE_THAT(act.f(0), Catch::Matchers::WithinRel(0.5, 0.00001));
    REQUIRE_THAT(act.f(1), Catch::Matchers::WithinRel(0.7310586, 0.00001));

    REQUIRE_THAT(act.df(-1), Catch::Matchers::WithinRel(0.1966119, 0.00001));
    REQUIRE_THAT(act.df(0), Catch::Matchers::WithinRel(0.25, 0.00001));
    REQUIRE_THAT(act.df(1), Catch::Matchers::WithinRel(0.1966119, 0.00001));
}

TEST_CASE("ReLU activation function", "[activation_function]") {
    jml::ReLU act;

    REQUIRE(act.f(-1) == 0);
    REQUIRE(act.f(0) == 0);
    REQUIRE(act.f(1) == 1);

    REQUIRE(act.df(-1) == 0);
    // REQUIRE(act.df(0) == 0); FIXME: is this UB?
    REQUIRE(act.df(1) == 1);
}

TEST_CASE("LeakyReLU activation function", "[activation_function]") {
    jml::LeakyReLU act;

    REQUIRE_THAT(act.f(-1), Catch::Matchers::WithinRel(-0.01, 0.00001));
    REQUIRE(act.f(0) == 0);
    REQUIRE(act.f(1) == 1);

    REQUIRE_THAT(act.df(-1), Catch::Matchers::WithinRel(0.01, 0.00001));
    // REQUIRE(act.df(0) == 0); FIXME: is this UB?
    REQUIRE(act.df(1) == 1);
}

TEST_CASE("LeakyReLU activation function with custom leak",
          "[activation_function]") {
    jml::LeakyReLU act(0.0001);

    // TODO: is it necessary to check function values?

    REQUIRE_THAT(act.df(-1), Catch::Matchers::WithinRel(0.0001, 0.00001));
    REQUIRE(act.df(1) == 1);
}
