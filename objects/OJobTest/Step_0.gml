while (true)
{
	var _job = b_get_finished_job();
	if (_job == -1)
	{
		break;
	}
	show_debug_message(b_object_get_type(_job) + " " + string(_job) + " finished!");
}