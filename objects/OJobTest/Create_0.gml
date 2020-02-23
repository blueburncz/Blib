for (var i = 1; i <= 3; ++i)
{
	var _job = b_sleep_job_create(i * 1000);
	b_job_start(_job);
	show_debug_message("Created job " + string(_job));
}