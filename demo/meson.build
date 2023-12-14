if get_option('with_demo').enabled()
    demo_apps = [
        'element', 'rocket', 'robotics',
        'qubit', 'physics', 'satellite']

    foreach iter : demo_apps
        executable('demo_' + iter, 'demo_' + iter + '.c', dependencies : [tscl_xscience_c_dep])
    endforeach
endif