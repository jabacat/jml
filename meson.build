project('jml', 'cpp',
        default_options: ['cpp_std=c++14'],
        meson_version: '>=1.2.0')

core_inc = include_directories('core/include')

catch2_proj = subproject('catch2', default_options: {'tests': false})
catch2_dep = catch2_proj.get_variable('catch2_with_main_dep')

subdir('core')

subdir('tests')
