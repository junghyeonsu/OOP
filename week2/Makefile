.SUFFIXES: .cpp .o

OBJECTS = student_id.o print.o main.o 

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
			  $(CXX) -o $(TARGET) $(OBJECTS)

clean :
	rm -rf $(OBJECTS) $(TARGET)

student_id.o : student_id.cpp
print.o : print.cpp
main.o : main.cpp	
