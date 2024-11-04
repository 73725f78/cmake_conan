.PHONY: install_deps
.PHONY: install_conan_deps
.PHONY: build
.PHONY: run

run:
	cd build && make run

toolchain: 
	#cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
	cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=Debug/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Debug
	cd build && cmake --build .

install_conan_deps:
	#cd build && conan profile detect
	#cd build && conan install .. --build=missing
	cd build && conan install .. --build=missing --settings=build_type=Debug

install_deps:
	pip install conan

clean:
	cd build && rm -rf *
