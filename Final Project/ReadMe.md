# Optimization of Deproteinization Efficiency in Chitin Hydrolysis

This C++ project implements an algorithm to optimize the deproteinization efficiency in chitin hydrolysis, using sodium hydroxide (NaOH), based on a literature review of scientific experiments. The project uses **Least Squares Fitting**, **Exhaustive Search**, and a **Beam Search Algorithm** to find the optimal NaOH molarity, temperature, and processing time for chitin hydrolysis in *Acheta domesticus* (cricket flour).

## 📘 Project Structure


---

## How to Build and Run (VS Code with g++)

### Prerequisites

- [VS Code](https://code.visualstudio.com/)
- C++ compiler (e.g., `g++`, `clang++`)
- CMake (optional, for build configuration)
- GNU Make (if using Makefile)
- Python/Matlab (optional, for plotting)

### Build Instructions

You can compile the project with a simple g++ command:

make LeastSquares

```bash
g++ -std=c++17 -o LeastSquares LeastSquares.cpp
