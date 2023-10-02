test_sources = ['core.cpp',
                'math/matrix.cpp']
tests = executable('tests', test_sources, dependencies: [catch2_dep])
test('tests', tests, args: ['--reporter', 'TAP'], protocol: 'tap')
