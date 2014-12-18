CC=g++
VERSION= -std=c++14
CFLAGS=-c -Wall
LDFLAGS= -lcurl 
SOURCES=main.cpp networkManager.cpp levelManipulator.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=crossflip

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(VERSION) $(CFLAGS) $< -o $@


clean:
	rm -rf *o crossflip
