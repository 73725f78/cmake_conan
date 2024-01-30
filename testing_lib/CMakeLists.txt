add_library(testing_lib)

target_sources(testing_lib
	PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}/src/Testing.cpp
)

target_include_directories(testing_lib
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/
	${PROJECT_BINARY_DIR}
) 

target_link_libraries(testing_lib
	Poco::Foundation 
	Poco::Util
)
