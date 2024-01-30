#pragma once

#include <Poco/Logger.h>

class Testing{

	Poco::Logger &log = Poco::Logger::get("Testing");

	public:
		Testing();

		void method_testing();

};
