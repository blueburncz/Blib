for (var i = 1; i <= 3; ++i)
{
	var _job = new BLIB_CSleepJob(i * 1000);
	if (!_job.Exists())
	{
		show_error("Failed to create SleepJob!", true);
	}
	_job.Start();
	show_debug_message("Created job " + string(_job));
}