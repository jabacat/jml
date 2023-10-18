core_test_sources = [
    'core/math/test_matrix.cpp',
    'core/math/test_vector.cpp',
    'core/math/test_activation_functions.cpp',
    'core/math/test_losses.cpp',
    'core/test_model.cpp',
]

tests = executable('core_tests',
                   core_test_sources,
                   dependencies: [catch2_dep, jmlcore_dep])
test('core', tests, args: ['--reporter', 'TAP'], protocol: 'tap')
