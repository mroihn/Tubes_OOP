CC = g++
CFLAGS = -Wall -g

SRC =    ./src/pcolor/pcolor.c ./src/InvItems/InvItems.cpp ./src/User/User.cpp ./src/Inventory/Inventory.cpp ./src/GameManager/GameManager.cpp ./src/main.cpp

TARGET = ./bin/main.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET)