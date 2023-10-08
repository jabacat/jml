core_sources = ['src/math/matrix.cpp', 'src/math/vector.cpp', 'src/math/activation_functions.cpp', 'src/model.cpp', 'capi/cjml.cpp']
jmlcore = library('jmlcore',
                  core_sources,
                  include_directories: core_inc,
                  install: true)

jmlcore_dep = declare_dependency(link_with: jmlcore, include_directories: core_inc)
