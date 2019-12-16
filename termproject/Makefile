.SUFFIXES: .cpp .o

OBJECTS = Fold.o Tree.o map.o puyopuyo.o

CXX = g++

TARGET = test

$(TARGET) : $(OBJECTS)
	$(CXX) -o $(TARGET) $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)

Fold.o : Fold.cpp

Tree.o : Tree.cpp

map.o : map.cpp

puyopuyo.o : puyopuyo.cpp
