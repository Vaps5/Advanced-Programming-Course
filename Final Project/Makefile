# Makefile for compiling three independent C++ programs one at a time

# Compiler and flags
CXX = g++
CXXFLAGS = -O2 -std=c++17

# Programs
TARGETS = LeastSquares Maximum_BeamSearch Maximum_WithoutBeamSearch

# Default target (optional)
all:
	@echo "Usage: make [TARGET]"
	@echo "Available targets: $(TARGETS)"
	@echo "Example: make LeastSquares"

# Compile individual programs
LeastSquares: LeastSquares.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

Maximum_BeamSearch: Maximum_BeamSearch.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

Maximum_WithoutBeamSearch: Maximum_WithoutBeamSearch.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean compiled .exe files (for Windows)
clean:
	del /Q $(TARGETS:=.exe) 2> NUL
