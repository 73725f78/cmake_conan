#include <fstream>
#include <iostream>
#include <Poco/Util/Option.h>
#include <Poco/Util/OptionSet.h>
#include <Poco/Util/Application.h>
#include <Poco/Util/HelpFormatter.h>
#include <Poco/Util/OptionCallback.h>

#include "Testing.hpp"
#include "config.hpp"
#include <nng/transport/tcp/tcp.h>

using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::Util::OptionCallback;

class Main_app: public Application {

	Poco::Logger &log = Poco::Logger::get("Main_app");

	private:

		bool helpRequested;
		int port;

	public:
		Main_app(): helpRequested{false}, port{9999} {}

	protected:	

		void initialize(Application& self) {
			loadConfiguration();
			Application::initialize(self);
		}

		void uninitialize() {
			Application::uninitialize();
		}

		void reinitialize(Application& self) {
			Application::reinitialize(self);
		}

		void defineOptions(OptionSet& options){
			Application::defineOptions(options);

			options.addOption(
					Option("help", "h", "Display this help information")
					.callback(OptionCallback<Main_app>(this, &Main_app::handleHelp)));

			options.addOption(
					Option("server port number", "p", "port")
					.argument("<port>")
					.callback(OptionCallback<Main_app>(this, &Main_app::set_port)));
		}

		void set_port(const std::string& name, const std::string& value) { 
			port = std::stoi(value);
		}

		void handleHelp(const std::string& name, const std::string& value) {
			helpRequested = true;
			displayHelp();
			stopOptionsProcessing();
		}

		void displayHelp() {
			HelpFormatter helpFormatter(options());
			helpFormatter.setCommand(commandName());
			helpFormatter.setUsage("<options>");
			helpFormatter.setHeader("A command line interface (cli) application for AES encryption/decryption.");
			helpFormatter.format(std::cout);
		}

		int main(const std::vector<std::string>& args){
			if (!helpRequested){
				log.information(std::string{"***** Running : "} + PROJECT_NAME,__FILE__,__LINE__);
				log.information(std::string{"***** Version : "} + PROJECT_VER,__FILE__,__LINE__);

				log.information("Application options : " , 					__FILE__,__LINE__);
				log.information("  -port             : " + std::to_string(port) , 	__FILE__,__LINE__);
				log.debug("Testing debug");
			}

			nng_tcp_register();

			Testing t;
			t.method_testing();

			return Application::EXIT_OK;
		}
};

POCO_APP_MAIN(Main_app)
