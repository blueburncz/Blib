while (true)
{
	var _job = blib_get_finished_job();
	if (_job == undefined)
	{
		break;
	}
	show_debug_message(_job.GetType() + " " + string(_job) + " finished!");
	show_debug_message("Exists: " + string(_job.Exists()));
	_job.Destroy();
	show_debug_message("Exists: " + string(_job.Exists()));
}