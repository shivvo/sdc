CC=g++
CFLAGS=-c -g -Wall -std=c++11
LDFLAGS=
HEADERS=clock.h controller.h flow.h flow_factory.h logger.h network_fabric.h node.h node_factory.h packet.h schedule.h simple_drain_node.h simple_drain_node_factory.h simulator.h
SOURCES=clock.cpp controller.cpp flow.cpp flow_factory.cpp logger.cpp network_fabric.cpp node.cpp node_factory.cpp packet.cpp schedule.cpp simple_drain_node.cpp simple_drain_node_factory.cpp simulator.cpp
OBJECTS=$(SOURCES:.cpp=.o) 
EXECUTABLES=agg_stats stats
MAIN_SOURCES= $(foreach e,$(EXECUTABLES), $(e).cpp)

all: $(MAINS) $(SOURCES) $(EXECUTABLES)
    
$(EXECUTABLES): $(OBJECTS) $(MAIN_OBJECTS) $(HEADERS) $(MAIN_SOURCES)
	$(CC) $(CFLAGS) $@.cpp -o $@.o; $(CC) $(LDFLAGS) $(OBJECTS) $@.o -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o agg_stats stats