CC=g++
CFLAGS=-c -g -Wall -std=c++11
LDFLAGS=
HEADERS=clock.h controller.h flow.h flow_factory.h logger.h network_fabric.h node.h node_factory.h packet.h schedule.h simple_drain_node.h simple_drain_node_factory.h simulator.h synth_flow_factory.h
SOURCES=main.cpp clock.cpp controller.cpp flow.cpp flow_factory.cpp logger.cpp network_fabric.cpp node.cpp node_factory.cpp packet.cpp schedule.cpp simple_drain_node.cpp simple_drain_node_factory.cpp simulator.cpp synth_flow_factory.cpp
OBJECTS=$(SOURCES:.cpp=.o) 
EXECUTABLE=sdc

all: $(MAINS) $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o sdc