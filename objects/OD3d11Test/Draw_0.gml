var _world = matrix_get(matrix_world);
var _view = matrix_get(matrix_view);
var _proj = matrix_get(matrix_projection);

gpu_push_state();
gpu_set_cullmode(cull_counterclockwise);
gpu_set_ztestenable(true);
gpu_set_zwriteenable(true);

surface.Clear(c_red, 1);
depth_stencil.Clear(1, 0);

blib_set_render_targets(surface, depth_stencil);

matrix_set(matrix_world, matrix_build(0, 0, 0, 0, 0, 0, 2, 2, 1));
matrix_set(matrix_view, matrix_build_lookat(10, 10, 10, 0, 0, 0, 0, 0, 1));
matrix_set(matrix_projection, matrix_build_projection_perspective_fov(60, 1, 1, 8192));

shader_set(ShTest);
vertex_submit(vbuffer, pr_trianglelist, -1);
shader_reset();

blib_reset_render_targets();

gpu_pop_state();

matrix_set(matrix_world, _world);
matrix_set(matrix_view, _view);
matrix_set(matrix_projection, _proj);