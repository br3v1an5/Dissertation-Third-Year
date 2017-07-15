#!/bin/bash

for num in {1..500}
do
  	g++ -std=c++11 main.cpp -o main.out
  	sh fileSetup.sh
	./main.out thisisatest
	echo
done