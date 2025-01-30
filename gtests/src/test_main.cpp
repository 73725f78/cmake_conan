#include <Poco/Logger.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "setup_environment.hpp"

using namespace std;

//SetupEnvironment configure poco logger with logger.properties
testing::Environment* const my_env = testing::AddGlobalTestEnvironment(new SetupEnvironment);

TEST(MainTest, Main_test){ 
	Poco::Logger &log = Poco::Logger::get("MainTest");

	int a = 5;
	int b = 5;

	log.information("Comparing values",__FILE__,__LINE__);
	log.debug("Comparing values",__FILE__,__LINE__);

	EXPECT_EQ(a, b);
}


TEST(OtroTest, Main_test){ 
	Poco::Logger &log = Poco::Logger::get("OtroTest");
	log.information("Running OtroTest",__FILE__,__LINE__);

	Alumno al;
	Profesor pr(al);

	MockAlumno mal;
	EXPECT_CALL(mal, testing()).Times(testing::AtLeast(3));

	Profesor pr2(mal);
	log.debug("Running MockObject",__FILE__,__LINE__);
}
