# MATLAB-Shared-Library-Integration-to-CPP
This program is an example of using MATLAB generated lib/dll in a C++ environment 

.dll, .lib, .h files are generated from a MATLAB function avgFunc.m.
main.cpp is the source c++ code for this demonstration.
It reads a data file (mydata.txt) that has five columns of numeric data, and the shared library will calculate the mean of each line of the data file.
