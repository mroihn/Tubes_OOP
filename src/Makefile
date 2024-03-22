CC = g++
CFLAGS = -Wall -g

SRC =  main.cpp ./GameManager/GameManager.cpp

TARGET = ../bin/main.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)