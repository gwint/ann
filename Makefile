neural_network:	src/neural_network.o src/driver.o
	g++ -o neural_network src/neural_network.o src/driver.o

src/neural_network.o:	src/neural_network.cpp
	g++ -c src/neural_network.cpp -o src/neural_network.o

src/driver.o:	src/driver.cpp
	g++ -c src/driver.cpp -o src/driver.o

clean:
	rm -rf src/*.o neural_network
