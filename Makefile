all: build run

build:
	mkdir build && cd build && cmake ../ && make

run:
	cd build && ./Test

clean:
	rm -rf build