# Configuración para Windows/VS Code
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O3
LDFLAGS = 

# Archivos
SRC = src/main.cpp
EXEC = retail_analytics.exe

all: $(EXEC)

$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -Iinclude $^ -o $@ $(LDFLAGS)

clean:
	del /Q $(EXEC) *.o

run: $(EXEC)
	.\$(EXEC)