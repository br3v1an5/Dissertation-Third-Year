#!/bin/bash

#remember to reset the setup.txt file

for num in {1..500}
do
  	sh fileSetupTesting.sh
	g++ -std=c++11 main.cpp -o main.out
	./main.out a
done