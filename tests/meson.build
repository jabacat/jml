core_test_sources = [
    'core/math/test_matrix.cpp',
    'core/math/test_activation_functions.cpp',
]

tests = executable('core_tests',
                   core_test_sources,
                   dependencies: [catch2_dep, jmlcore_dep])
test('core', tests, args: ['--reporter', 'TAP'], protocol: 'tap')
