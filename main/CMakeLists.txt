#============================================
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/logger.properties main.properties COPYONLY)

add_executable(main
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(main
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_BINARY_DIR}
)

target_link_libraries(main
	Poco::Foundation
	Poco::Util
	nng::nng
	testing_lib
)

#============================================
add_custom_target(run
	COMMAND main
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMENT "==============================> Main ${CMAKE_CURRENT_SOURCE_DIR}"
)
