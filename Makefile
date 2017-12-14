CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
HEADERS=clock.h controller.h flow.h flow_factory.h logger.h network_fabric.h node.h packet.h schedule.h simulator.h
SOURCES=main.cpp clock.cpp controller.cpp flow.cpp flow_factory.cpp logger.cpp network_fabric.cpp node.cpp packet.cpp schedule.cpp simulator.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=sdc

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o sdc *-log.csv