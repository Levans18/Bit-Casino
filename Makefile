GCC = g++
CFLAGS = -std=c++17
TARGET = BitCasino
CPPFILES = ./GameUtility/*.cpp ./GameModes/*cpp *.cpp 

all: 
	@$(GCC) $(CFLAGS) -o $(TARGET) $(CPPFILES)

run: 
	@./BitCasino

clean: 
	@rm -rf BitCasino