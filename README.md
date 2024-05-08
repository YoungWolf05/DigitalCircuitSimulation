# Digital Circuit Simulation

## Changes
- Fixed simulator produces no output when it should (see [33482ad](https://github.com/YoungWolf05/DigitalCircuitSimulation/commit/33482adc84fdc04d54c4c0a58a247e680e179c38))
- Speed Optimization on getting smallest value using priority_queue (see [f338a33](https://github.com/YoungWolf05/DigitalCircuitSimulation/commit/f338a338d642786b22f6d0b9ac8599b1d7346e32))
- Speed Optimization on writing output to Json (see [2ab4b01](https://github.com/YoungWolf05/DigitalCircuitSimulation/commit/2ab4b0114b41d15820f7f0348135e9c7ba6be9f6))
- Chore Cleanup (see [8941e62](https://github.com/YoungWolf05/DigitalCircuitSimulation/commit/8941e623c67309c836ba24466d2ae0a57d2f7622))

## Benchmark Methodology
```
#include <iostream>
#include <chrono>

// start time
auto start = std::chrono::high_resolution_clock::now();

// target method
auto simulation = Simulation::FromFile(input);

// end time
auto end = std::chrono::high_resolution_clock::now();

// compute the duration
std::chrono::duration<double> elapsed_seconds = end - start;

// print result 
std::cout << "Simulation time: " << elapsed_seconds.count() << " seconds" << std::endl;
```
## Result
The test file used is 5devadas13.in. The simulation is run in **release** mode. 
The simulation is executed in **~720ms** without printing the probe to the console. 
Result is shown in the table below

![image](https://github.com/YoungWolf05/DigitalCircuitSimulation/assets/100288056/2d9b53f2-6051-4998-ba39-c70e9f932ca6)

