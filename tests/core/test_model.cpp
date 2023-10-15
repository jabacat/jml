#include "catch2/catch_test_macros.hpp"
#include "jml/math/vector.hpp"
#include "jml/model.hpp"
#include <array>
#include <tuple>
#include <vector>

SCENARIO("Testing data added to model") {
    GIVEN("a model") {
        jml::Model M;

        // some testing data
        jml::Vector in1(3), in2(3), out1(2), out2(2);
        std::vector<jml::Vector> ins, outs;

        in1.set_entry(0, 3);
        in1.set_entry(1, 5);
        in1.set_entry(2, 7);
        in2.set_entry(0, 11);
        in2.set_entry(1, 13);
        in2.set_entry(2, 17);
        out1.set_entry(0, 19);
        out1.set_entry(1, 23);
        out2.set_entry(0, 29);
        out2.set_entry(1, 31);

        ins.push_back(in1);
        ins.push_back(in2);
        outs.push_back(out1);
        outs.push_back(out2);

        // Another STL container to test for iterators
        std::array<jml::Vector, 2> array_ins = {in1, in2},
                                   array_outs = {out1, out2};

        WHEN("testing datum is added") {
            M.add_testing_datum(in1, out1);

            THEN("model has added testing datum") {
                std::vector<jml::Vector> M_ins, M_outs;
                std::tie(M_ins, M_outs) = M.get_testing_data();

                REQUIRE(M_ins.size() == 1);
                REQUIRE(M_outs.size() == 1);

                REQUIRE(M_ins[0].get_entry(0) == 3);
                REQUIRE(M_ins[0].get_entry(1) == 5);
                REQUIRE(M_ins[0].get_entry(2) == 7);
                REQUIRE(M_outs[0].get_entry(0) == 19);
                REQUIRE(M_outs[0].get_entry(1) == 23);
            }

            AND_WHEN("more testing datum is added") {
                M.add_testing_datum(in2, out2);

                THEN("model has all added testing data") {
                    std::vector<jml::Vector> M_ins, M_outs;
                    std::tie(M_ins, M_outs) = M.get_testing_data();

                    REQUIRE(M_ins.size() == 2);
                    REQUIRE(M_outs.size() == 2);

                    REQUIRE(M_ins[0].get_entry(0) == 3);
                    REQUIRE(M_ins[0].get_entry(1) == 5);
                    REQUIRE(M_ins[0].get_entry(2) == 7);
                    REQUIRE(M_outs[0].get_entry(0) == 19);
                    REQUIRE(M_outs[0].get_entry(1) == 23);

                    REQUIRE(M_ins[1].get_entry(0) == 11);
                    REQUIRE(M_ins[1].get_entry(1) == 13);
                    REQUIRE(M_ins[1].get_entry(2) == 17);
                    REQUIRE(M_outs[1].get_entry(0) == 29);
                    REQUIRE(M_outs[1].get_entry(1) == 31);
                }
            }
        }

        WHEN("testing data is added with vector overload") {
            M.add_testing_data(ins, outs);

            THEN("model has added testing data") {
                std::vector<jml::Vector> M_ins, M_outs;
                std::tie(M_ins, M_outs) = M.get_testing_data();

                REQUIRE(M_ins.size() == 2);
                REQUIRE(M_outs.size() == 2);

                REQUIRE(M_ins[0].get_entry(0) == 3);
                REQUIRE(M_ins[0].get_entry(1) == 5);
                REQUIRE(M_ins[0].get_entry(2) == 7);
                REQUIRE(M_ins[1].get_entry(0) == 11);
                REQUIRE(M_ins[1].get_entry(1) == 13);
                REQUIRE(M_ins[1].get_entry(2) == 17);

                REQUIRE(M_outs[0].get_entry(0) == 19);
                REQUIRE(M_outs[0].get_entry(1) == 23);
                REQUIRE(M_outs[1].get_entry(0) == 29);
                REQUIRE(M_outs[1].get_entry(1) == 31);
            }

            AND_WHEN("more testing data is added") {
                M.add_testing_data(ins, outs);

                THEN("model has all added testing data") {
                    std::vector<jml::Vector> M_ins, M_outs;
                    std::tie(M_ins, M_outs) = M.get_testing_data();

                    REQUIRE(M_ins.size() == 4);
                    REQUIRE(M_outs.size() == 4);

                    REQUIRE(M_ins[0].get_entry(0) == 3);
                    REQUIRE(M_ins[0].get_entry(1) == 5);
                    REQUIRE(M_ins[0].get_entry(2) == 7);
                    REQUIRE(M_ins[1].get_entry(0) == 11);
                    REQUIRE(M_ins[1].get_entry(1) == 13);
                    REQUIRE(M_ins[1].get_entry(2) == 17);

                    REQUIRE(M_outs[0].get_entry(0) == 19);
                    REQUIRE(M_outs[0].get_entry(1) == 23);
                    REQUIRE(M_outs[1].get_entry(0) == 29);
                    REQUIRE(M_outs[1].get_entry(1) == 31);

                    REQUIRE(M_ins[2].get_entry(0) == 3);
                    REQUIRE(M_ins[2].get_entry(1) == 5);
                    REQUIRE(M_ins[2].get_entry(2) == 7);
                    REQUIRE(M_ins[3].get_entry(0) == 11);
                    REQUIRE(M_ins[3].get_entry(1) == 13);
                    REQUIRE(M_ins[3].get_entry(2) == 17);

                    REQUIRE(M_outs[2].get_entry(0) == 19);
                    REQUIRE(M_outs[2].get_entry(1) == 23);
                    REQUIRE(M_outs[3].get_entry(0) == 29);
                    REQUIRE(M_outs[3].get_entry(1) == 31);
                }
            }
        }

        WHEN("testing data is added with iterator overload") {
            M.add_testing_data(array_ins.begin(), array_ins.end(),
                               array_outs.begin(), array_outs.end());

            THEN("model has added testing data") {
                std::vector<jml::Vector> M_ins, M_outs;
                std::tie(M_ins, M_outs) = M.get_testing_data();

                REQUIRE(M_ins.size() == 2);
                REQUIRE(M_outs.size() == 2);

                REQUIRE(M_ins[0].get_entry(0) == 3);
                REQUIRE(M_ins[0].get_entry(1) == 5);
                REQUIRE(M_ins[0].get_entry(2) == 7);
                REQUIRE(M_ins[1].get_entry(0) == 11);
                REQUIRE(M_ins[1].get_entry(1) == 13);
                REQUIRE(M_ins[1].get_entry(2) == 17);

                REQUIRE(M_outs[0].get_entry(0) == 19);
                REQUIRE(M_outs[0].get_entry(1) == 23);
                REQUIRE(M_outs[1].get_entry(0) == 29);
                REQUIRE(M_outs[1].get_entry(1) == 31);
            }

            AND_WHEN("more testing data is added") {
                M.add_testing_data(ins.begin(), ins.end(), outs.begin(),
                                   outs.end());

                THEN("model has all added testing data") {
                    std::vector<jml::Vector> M_ins, M_outs;
                    std::tie(M_ins, M_outs) = M.get_testing_data();

                    REQUIRE(M_ins.size() == 4);
                    REQUIRE(M_outs.size() == 4);

                    REQUIRE(M_ins[0].get_entry(0) == 3);
                    REQUIRE(M_ins[0].get_entry(1) == 5);
                    REQUIRE(M_ins[0].get_entry(2) == 7);
                    REQUIRE(M_ins[1].get_entry(0) == 11);
                    REQUIRE(M_ins[1].get_entry(1) == 13);
                    REQUIRE(M_ins[1].get_entry(2) == 17);

                    REQUIRE(M_outs[0].get_entry(0) == 19);
                    REQUIRE(M_outs[0].get_entry(1) == 23);
                    REQUIRE(M_outs[1].get_entry(0) == 29);
                    REQUIRE(M_outs[1].get_entry(1) == 31);

                    REQUIRE(M_ins[2].get_entry(0) == 3);
                    REQUIRE(M_ins[2].get_entry(1) == 5);
                    REQUIRE(M_ins[2].get_entry(2) == 7);
                    REQUIRE(M_ins[3].get_entry(0) == 11);
                    REQUIRE(M_ins[3].get_entry(1) == 13);
                    REQUIRE(M_ins[3].get_entry(2) == 17);

                    REQUIRE(M_outs[2].get_entry(0) == 19);
                    REQUIRE(M_outs[2].get_entry(1) == 23);
                    REQUIRE(M_outs[3].get_entry(0) == 29);
                    REQUIRE(M_outs[3].get_entry(1) == 31);
                }
            }
        }

        WHEN("there is testing data and it is cleared") {
            M.add_testing_datum(in1, in2); // hi data
            M.clear_testing_data();        // bye data

            THEN("testing data in model is no more") {
                std::vector<jml::Vector> M_ins, M_outs;
                std::tie(M_ins, M_outs) = M.get_testing_data();

                REQUIRE(M_ins.size() == 0);
                REQUIRE(M_outs.size() == 0);
            }
        }
    }
}
