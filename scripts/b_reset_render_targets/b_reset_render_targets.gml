/// @func b_surface_reset_target()
function b_reset_render_targets() {
	gml_pragma("forceinline");
	external_call(global.__bResetRenderTargets);


}
