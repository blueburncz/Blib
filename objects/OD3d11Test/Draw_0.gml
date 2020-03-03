var _matWorld = matrix_get(matrix_world);
var _matView = matrix_get(matrix_view);
var _matProj = matrix_get(matrix_projection);

gpu_set_cullmode(cull_noculling);
gpu_set_ztestenable(false);
gpu_set_zwriteenable(false);

b_surface_clear(surface, c_red, 1);

b_set_render_targets(B_ID_NONE, surface);

matrix_set(matrix_world, matrix_build(0, 0, 0, 0, 0, 0, 2, 2, 1));
matrix_set(matrix_view, matrix_build_lookat(10, 10, 10, 0, 0, 0, 0, 0, 1));
matrix_set(matrix_projection, matrix_build_projection_perspective_fov(60, 1, 1, 8192));

shader_set(ShTest);
vertex_submit(vBuffer, pr_trianglelist, -1);
shader_reset();

b_reset_render_targets();

matrix_set(matrix_world, _matWorld);
matrix_set(matrix_view, _matView);
matrix_set(matrix_projection, _matProj);