all:
	g++ -Wall -std=c++14 main.cpp arpnoid.cpp util.cpp -o arpnoid

.PHONY: all