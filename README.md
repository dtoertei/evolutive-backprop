# evolutive-backprop
The network learns a binary function with a tri-state output {XOR, OR, AND}.
Backpropagation is modified to use weight decay, cell decay and hidden cell division rules in order to optimize number of cells in an arbitrary hidden layer i.e. sparse multilayer perceptron architecture.

This example outputs logs such as number of iterations until convergence, number of cell divisions and number of decayed weights.

Output: {}
# Compile & run
g++ -o main.exe main.cpp
