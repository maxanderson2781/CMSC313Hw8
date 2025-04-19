# Matrix Operations in C and C++

## AUTHORING
- **Authors:** Max Anderson
- **Affiliation:** UMBC – CMSC 313 (Computer Organization and Assembly Language)
- **Class Time:** [M-W 8:30 - 9:45 AM]

## PURPOSE OF SOFTWARE
This project implements matrix operations in C and C++ to demonstrate:
- Differences in memory management and abstraction between C and C++
- Use of dynamic allocation in C
- Operator overloading and encapsulation in C++

## FILES
- `matrix.cpp` – Implementation of the `Matrix` class in C++
- `matrix.hpp` – Header file for `matrix.cpp`, defining the `Matrix` class and function declarations
- `matrix.c` – Procedural implementation of matrix functions in C
- `matrix.h` – Header file for `matrix.c`, defining the `Matrix` struct and function declarations
- `Makefile` – Contains build instructions to compile and run both C and C++ versions
- `README.md` – This documentation

## BUILD INSTRUCTIONS
To build and run:

## C++
```bash
  make cpp
  make runcpp
```
## C
```bash
  make c
  make runc
```
## Output

For both the output should be:
```bash
90 70
200 150
```
