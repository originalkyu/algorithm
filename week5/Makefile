CC = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = main.out
SOURCE = K17144
OBJS = $(SOURCE).o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: $(SOURCE).cpp

clean:
	rm -f *.o
	rm -f $(TARGET)