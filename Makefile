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
	echo "Leer opciones en el Makefile"
	#conan de puede descargar del conan center para ubuntu he instalar con sudo apt (mi recomendacion)
	#pip install conan				#Se requieren virtual environment en python3.12 > o mayores.
	#sudo apt install libnsl-dev			#Se en ubuntu 24.04 LTS (posiblemente oara nng)

tests: toolchain
	cd build/ && ctest --test-dir gtests/ -V

clean:
	cd build && rm -rf *
