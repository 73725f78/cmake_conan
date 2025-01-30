configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/logger.properties logger.properties COPYONLY)

enable_testing()
include(GoogleTest)

add_executable(test_main
	${CMAKE_CURRENT_SOURCE_DIR}/src/test_main.cpp
)

target_include_directories(test_main
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

target_link_libraries(test_main
	Poco::Foundation
	Poco::Util
	gtest::gtest
)

gtest_discover_tests(test_main
	#TEST_FILTER *MixColumns*
)
