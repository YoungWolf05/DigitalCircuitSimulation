// Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <iostream>

#include "Simulation.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Simulator.exe <simfile> [json]" << std::endl;
        std::cout << "simulation output is in circuit.json" << std::endl;
        exit(0);
    }
    bool json = (argc >= 3 && "json" == std::string(argv[2]));
    std::ifstream input(argv[1], std::ios::in);
    auto simulation = Simulation::FromFile(input);

    if (json)
    {
        simulation->LayoutFromFile(input);
        // probe all gates should only be executed when     
        // json output is on 
        simulation->ProbeAllGates();
    }

    simulation->Run();

    if (json)
    {
        simulation->UndoProbeAllGates();
        std::ofstream output("circuit.json", std::ios::out);
        simulation->WriteToJsonFile(output);
        output.close();
    }
     simulation->PrintProbes(std::cout);
}
