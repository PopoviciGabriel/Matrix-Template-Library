# Matrix Template Library (C++)

## Overview
This project implements a compile-time sized matrix library in modern C++, using templates and non-type template parameters (NTTPs).  
Matrix dimensions are known at compile time, providing strong type safety and preventing invalid matrix operations.

## Features
- Generic matrix class: Matrix<T, Rows, Cols>
- Compile-time dimension checking
- Operator overloading: +, -, *, (), <<
- Matrix transpose
- Determinant and inverse for 2×2 matrices
- Supports multiple numeric types (int, double, etc.)
- Runtime error handling for singular matrices

## Design
Matrix dimensions are enforced at compile time:

```cpp
Matrix<int, 2, 3> A;
Matrix<int, 3, 2> B;
auto C = A * B; // Valid
