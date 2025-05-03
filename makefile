demo: demo.cpp RandomObject.o
	g++ demo.cpp RandomObject.o -o demo
	./demo

test: test.cpp RandomObject.o
	g++ test.cpp RandomObject.o -o test
	./test

RandomObject.o: RandomObject.cpp RandomObject.h
	g++ -c RandomObject.cpp -o RandomObject.o

clean:
	rm -f RandomObject.o demo test
