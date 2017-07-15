#!/bin/bash
sed 's/,/ /g' setup.txt >unixSetupOne.txt
sed 's/\[//g;s/\]/ /g' < unixSetupOne.txt > unixSetupTwo.txt
tr -d '\n' < unixSetupTwo.txt > setupFile.txt
rm unixSetupOne.txt
rm unixSetupTwo.txt