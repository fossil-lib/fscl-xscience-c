cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

code = files(
    'element.c', 'arospace.c', 'robotics.c',
    'qubit.c', 'qcircuit.c, 'physics.c',
    'dataset.c')

lib = static_library('fscl-xscince-c',
    code,
    dependencies: m_dep,
    include_directories: dir)

fscl_xscience_c_dep = declare_dependency(
    link_with: lib,
    include_directories: dir)
