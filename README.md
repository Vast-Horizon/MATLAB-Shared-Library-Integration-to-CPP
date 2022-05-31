# MATLAB-Shared-Library-Integration-to-CPP
![image](https://user-images.githubusercontent.com/50966363/171179730-852b5613-c327-4689-b6f1-a1974054b334.png)

This program is an example of using MATLAB generated lib/dll in a C++ environment 
Please watch the demo video: https://youtu.be/R8kBlu9kYDE

.dll, .lib, .h files are generated from a MATLAB function avgFunc.m.
mcc -W 'cpplib:FuncLib,all' -T link:lib Func.m


main.cpp is the source c++ code for this demonstration.
It reads a data file (mydata.txt) that has five columns of numeric data, and the shared library will calculate the mean of each line of the data file.
