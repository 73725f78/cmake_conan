#============================================
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/logger.properties aes.properties COPYONLY)

add_executable(main
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_include_directories(main
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_BINARY_DIR}
)

target_link_libraries(main
	Poco::Util
	Poco::Foundation
	nng::nng
)

#============================================
add_custom_target(run
	COMMAND main
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	COMMENT "==============================> Main ${CMAKE_CURRENT_SOURCE_DIR}"
)
