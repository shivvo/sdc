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

To generate the average goodput and flow completion time statistics, first we must generate the logs:
```
./stats
```
This takes up to 45 minutes. Then, run:
```
./agg_stats
```
This should generate two files, `avg-fct-agg-log.csv` and `avg-gp-agg-log.csv`.

To generate and run the provided synthetic workload, run:
```
./sim_synth_simpledrain
./sim_synth_roundrobin
```
If either process hangs when completing the final few flows, it is safe to Ctrl-C and just use the logs generated to compute statistics.
The logs will be `synth-fct-simple-drain-log.csv` and `synth-fct-round-robin-pairs-log.csv`.

To generate a new synthetic workload, run:
```
./synth
```
The characteristics of the synthetic workflows are controlled by `synth.cpp`.