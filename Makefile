CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
HEADERS=packet.h node.h network_fabric.h flow.h
SOURCES=main.cpp packet.cpp node.cpp network_fabric.cpp flow.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sdc

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@
