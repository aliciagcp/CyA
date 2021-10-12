CXX = g++
CXXFLAGS = -Wall

alfabetos_main: alfabetos_main.o alfabetos.o
	$(CXX) $(CXXFLAGS) alfabetos.o alfabetos_main.o -o alfabetos_main

.PHONY: clean
clean:
	rm -rf *.o alfabetos_main