# includes
core_inc = include_directories('include', 'capi', 'internal')

# set c++ visiblity if building as a shared library
if get_option('default_library') == 'shared'
    core_dll_defs = ['-DJML_DLL', '-DJML_DLL_EXPORTS']
else
    core_dll_defs = []
endif

# TODO: pkg-config stuff

core_sources = ['src/math/matrix.cpp', 'src/math/vector.cpp', 'src/math/activation_functions.cpp', 'src/model.cpp', 'src/logger.cpp', 'capi/cjml.cpp']
jmlcore = library('jmlcore',
                  core_sources,
                  include_directories: core_inc,
                  install: true,
                  cpp_args: core_dll_defs,
                  gnu_symbol_visibility: 'inlineshidden')

jmlcore_dep = declare_dependency(link_with: jmlcore, include_directories: core_inc)
