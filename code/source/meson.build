code = files(
    'element.c', 'rocket.c', 'robotics.c',
    'qubit.c', 'physics.c')

lib = static_library('tscl-xscince-c',
    code,
    include_directories: dir)

tscl_xscience_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
