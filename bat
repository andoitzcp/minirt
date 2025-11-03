[----] test/src/plane.c:18: Assertion Failed
[----]   
[----]   The expression tuple_eq(n1, tuple_vector(0, 1, 0)) is false.
[----]   
[----] test/src/plane.c:19: Assertion Failed
[----]   
[----]   The expression tuple_eq(n2, tuple_vector(0, 1, 0)) is false.
[----]   
[----] test/src/plane.c:20: Assertion Failed
[----]   
[----]   The expression tuple_eq(n3, tuple_vector(0, 1, 0)) is false.
[----]   
[FAIL] plane::normal_at: (0.01s)
[----] test/src/utils.c:4: Assertion Failed
[----]   
[----]   : expected x:0.577350, returned x:0.000000.
[----]   
[----] test/src/utils.c:5: Assertion Failed
[----]   
[----]   : expected y:0.577350, returned y:0.000000.
[----]   
[----] test/src/utils.c:4: Assertion Failed
[----]   
[----]   : expected x:0.577350, returned x:0.000000.
[----]   
[----] test/src/utils.c:5: Assertion Failed
[----]   
[----]   : expected y:0.707107, returned y:0.000000.
[----]   
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:0.577350, returned z:-1.000000.
[----]   
[----] test/src/utils.c:4: Assertion Failed
[----]   
[----]   : expected x:0.000000, returned x:-0.341440.
[----]   
[----] test/src/utils.c:5: Assertion Failed
[----]   
[----]   : expected y:0.577350, returned y:0.000000.
[----]   
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:-0.707107, returned z:1.000000.
[----]   
[----] test/src/utils.c:5: Assertion Failed
[----]   
[----]   : expected y:0.970143, returned y:0.939904.
[----]   
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:0.577350, returned z:1.000000.
[----]   
[FAIL] sphere_normal_at::is_normalized: (0.01s)
[----] test/src/utils.c:4: Assertion Failed
[----]   
[----]   : expected x:1.000000, returned x:0.000000.
[----]   
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:-0.242536, returned z:0.000000.
[----]   
[FAIL] sphere_normal_at::transformed_sphere_point_1: (0.00s)
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:0.000000, returned z:-1.000000.
[----]   
[FAIL] sphere_normal_at::other_point: (0.00s)
[FAIL] sphere_normal_at::transformed_sphere_point_2: (0.00s)
[FAIL] sphere_normal_at::x: (0.00s)
[----] test/src/utils.c:5: Assertion Failed
[----]   
[----]   : expected y:1.000000, returned y:0.000000.
[----]   
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:1.000000, returned z:-0.000000.
[----]   
[----] test/src/utils.c:6: Assertion Failed
[----]   
[----]   : expected z:0.000000, returned z:-1.000000.
[----]   
[FAIL] sphere_normal_at::z: (0.01s)
[FAIL] sphere_normal_at::y: (0.01s)
[----] test/src/transform.c:65: Assertion Failed
[----]   
[----]   2.000000 vs 0.000000
[----]   
[----] test/src/transform.c:66: Assertion Failed
[----]   
[----]   3.000000 vs 0.000000
[----]   
[----] test/src/transform.c:67: Assertion Failed
[----]   
[----]   7.000000 vs 0.000000
[----]   
[FAIL] transform::sphere: (0.01s)
[----] test/src/scene.c:187: Assertion Failed
[----]   
[----]   0.080000 vs 0.380660
[----]   
[----] test/src/scene.c:203: Assertion Failed
[----]   
[----]   nan vs 0.800000
[----]   
[----] test/src/scene.c:188: Assertion Failed
[----]   
[----]   0.100000 vs 0.475830
[----]   
[----] test/src/scene.c:204: Assertion Failed
[----]   
[----]   nan vs 1.000000
[----]   
[----] test/src/scene.c:189: Assertion Failed
[----]   
[----]   0.060000 vs 0.285500
[----]   
[----] test/src/scene.c:205: Assertion Failed
[----]   
[----]   nan vs 0.600000
[----]   
[FAIL] world::color_at_hit: (0.00s)
[FAIL] world::color_at_intersect_behind: (0.00s)
[----] test/src/scene.c:78: Assertion Failed
[----]   
[----]   The expression tuple_eq(c.normv, tuple_vector(0, 0, -1)) is false.
[----]   
[----] test/src/scene.c:112: Assertion Failed
[----]   
[----]   The expression c.is_inside == 1 is false.
[----]   
[FAIL] world::prep_comps: (0.00s)
[FAIL] world::prep_comps_inside: (0.00s)
[----] test/src/scene.c:95: Assertion Failed
[----]   
[----]   The expression c.is_inside == 0 is false.
[----]   
[FAIL] world::prep_comps_outside: (0.00s)
[----] test/src/scene.c:159: Assertion Failed
[----]   
[----]   0.332379 vs 0.904980
[----]   
[----] test/src/scene.c:160: Assertion Failed
[----]   
[----]   0.332379 vs 0.904980
[----]   
[----] test/src/scene.c:161: Assertion Failed
[----]   
[----]   0.332379 vs 0.904980
[----]   
[FAIL] world::shade_hit_inside: (0.00s)
[----] test/src/scene.c:136: Assertion Failed
[----]   
[----]   0.639335 vs 0.380660
[----]   
[----] test/src/scene.c:137: Assertion Failed
[----]   
[----]   0.799169 vs 0.475830
[----]   
[----] test/src/scene.c:138: Assertion Failed
[----]   
[----]   0.479501 vs 0.285500
[----]   
[FAIL] world::shade_hit_outside: (0.00s)
[====] Synthesis: Tested: 77 | Passing: 61 | Failing: 16 | Crashing: 0 
