#include "Log.h"
#include "Application.h"

int main()
{
	Usurper::Log::Init();

	US_INFO("Hello Usurper!");
	Usurper::Application app;
	app.Run();
}