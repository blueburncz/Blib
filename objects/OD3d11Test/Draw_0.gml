var _matWorld = matrix_get(matrix_world);
var _matView = matrix_get(matrix_view);
var _matProj = matrix_get(matrix_projection);

gpu_set_cullmode(cull_noculling);
gpu_set_ztestenable(false);
gpu_set_zwriteenable(false);

b_surface_clear(surface, c_red, 1);

b_set_render_targets(B_ID_NONE, surface);

matrix_set(matrix_world, matrix_build(32, 32, 0, 0, 0, 0, 256, 256, 1));

shader_set(ShTest);
vertex_submit(vBuffer, pr_trianglelist, -1);
shader_reset();

b_reset_render_targets();

matrix_set(matrix_world, _matWorld);
matrix_set(matrix_view, _matView);
matrix_set(matrix_projection, _matProj);