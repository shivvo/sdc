CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
HEADERS=clock.h controller.h flow.h flow_factory.h node.h network_fabric.h packet.h schedule.h simulator.h
SOURCES=main.cpp clock.cpp controller.cpp flow.cpp flow_factory.cpp node.cpp network_fabric.cpp packet.cpp schedule.cpp simulator.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sdc

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o sdc