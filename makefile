myls: myls.o
	g++ myls.o -o myls
myls.o: myls.cpp
	g++ -c myls.cpp -o myls.o