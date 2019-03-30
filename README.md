# Matrix
Matrix is a two-dimensional data structure with an easy to use and smart implementation with array operators and debug tools like dumping objects and supporting mathematics operators.

The idea comes from returning two-dimensional arrays from functions that is a boring proccess. Matrix also supports associative arrays to prevent using extra libraries like std::map for some needings. Matrix library can be used to store data on the ram because of its table based data structure and table operation supports. And more huge feature can be found in the documention.

## Installation and configure
Installation and configure is pretty easy, just clone header file located in `dist/Matrix.h` and add it to your project like:

`#include "Matrix.h"`

## Getting started
Usage of Matrix is very easy and more similar to c++ arrays.

```c++
Matrix<int> mat(3, 2);
mat[0][0] = 2;
mat[0][1] = 23;
mat[1][0] = 0;
mat[1][1] = -6;
mat[2][0] = 10;
mat[2][1] = 67;

cout << "Matrix[0][1] is " << mat[0][1];
```

## Documention
You can read the documention [here](https://www.amirforsati.ir/doc/11).
