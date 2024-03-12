if get_option('with_test').enabled()
    test_deps = [
        dependency('fscl-xtest-c'),
        dependency('fscl-xmock-c')
    ]

    test_src = ['xunit_runner.c']
    test_cubes = [
        'element', 'arospace', 'robotics',
        'biological',
        'qubit', 'qcircuit', 'physics', 'dataset']

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('xcli', test_src, include_directories: dir, dependencies: [test_deps, fscl_xscience_c_dep])
    test('xunit_tests', pizza)  # Renamed the test target for clarity
endif
