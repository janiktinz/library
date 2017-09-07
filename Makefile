# author Janik und Patrick Tinz
CC = g++

OBJ = Book.o List.o  Menu.o main.o

# Name des Programms
TARGET = library

FLAGS = -g -std=c++11 -Wall -MMD -fmessage-length=0

all: $(TARGET)

#special - "make clean" löscht alle *.o Dateien
clean:
	rm -fv $(OBJ)

%.o : %.cpp
	$(CC) -c $(FLAGS) -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LIBS)