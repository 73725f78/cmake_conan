#pragma once

#include <Poco/Logger.h>
#include <gtest/gtest.h>
#include <Poco/AutoPtr.h>
#include <Poco/Util/LoggingConfigurator.h>
#include <Poco/Util/PropertyFileConfiguration.h>
#include <gmock/gmock.h>

using namespace Poco::Util;

class SetupEnvironment: public ::testing::Environment {
	private:
		static const std::string logger_config_file;

	public:
		SetupEnvironment(){
			std::cout << "============================== Running SetupEnvironment constructor" << std::endl;
		}

		virtual ~SetupEnvironment(){}
		void TearDown() override {}
		void SetUp() override {	
			try{
				Poco::AutoPtr<PropertyFileConfiguration> pConfig = new PropertyFileConfiguration(logger_config_file);
				LoggingConfigurator configurator;
				configurator.configure(pConfig);
				std::cout << "Poco::Logger configure with file: " << logger_config_file << std::endl;
			}catch(std::exception &e){
				std::cerr << "Error configuring logger file: " << logger_config_file << std::endl;
				std::cerr << e.what() << std::endl;
			}

			Poco::Logger &log = Poco::Logger::get("SetupEnvironment");
			log.information("SetupEnvironment.SetUp",__FILE__,__LINE__);
		}
};

const std::string SetupEnvironment::logger_config_file = "logger.properties"; 

class Alumno{
	private:
		Poco::Logger &log = Poco::Logger::get("Alumno");

	public:
		virtual void testing(){
			log.information("Calling Alumno.testing",__FILE__,__LINE__);
		}	
};

class Profesor{
	private:
		Alumno& al;

	public:
		Profesor(Alumno& _al): al{_al}{
			al.testing();
			al.testing();
			al.testing();
		}
};

class MockAlumno: public Alumno{
	public:
		MOCK_METHOD(void, testing, (), (override));
};
