#!/bin/sh


g++ -o hw1 hw1.cpp 
./hw1 200 > hw1_result.txt
python3 hw1_plot.py < hw1_result.txt

