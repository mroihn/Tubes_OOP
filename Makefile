CC = g++
CFLAGS = -g -std=gnu++17

SRC =    ./src/main.cpp ./src/GameManager/GameManager.cpp ./src/Inventory/Inventory.cpp ./src/User/User.cpp  ./src/InvItems/InvItems.cpp ./src/Toko/Toko.cpp ./src/pcolor/pcolor.c 

TARGET = ./bin/main.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	$(TARGET)

clean:
	rm -f $(TARGET)