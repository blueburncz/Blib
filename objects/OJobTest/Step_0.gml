while (true)
{
	var _job = b_get_finished_job();
	if (_job == -1)
	{
		break;
	}
	show_debug_message(b_object_get_type(_job) + " " + string(_job) + " finished!");
	show_debug_message("Exists: " + string(b_object_exists(_job)));
	b_object_destroy(_job);
	show_debug_message("Exists: " + string(b_object_exists(_job)));
}