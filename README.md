# SDC - Shiv's Data Center

This is a packet-level simulator for testing and evaluating scheduled network fabrics in a data center. We include the logs we used to compile the statistics used in "SDC: Exploring Statically and Dynamically Scheduled Network Fabrics in Data Centers".

## Requirements

The following are required to run this simulator.

* Ubuntu 16.04
* `g++` with C++11 support
* `make`

## Running

To compile the code:
```
make
```

To generate the average goodput proportionality statistics, first we must generate the logs:
```
./stats
```
