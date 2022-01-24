#ifndef PARAMS
#define PARAMS

#include <iostream>
#include <vector>
#include <chrono>

struct Params
{
    double duration;
    int init_population_size;
    double mutation_factor;
    double crossover_factor;
    Params();
    void setParams();
    void showParams();
};

struct State
{
    int tsp;
    std::vector<int> path;

    State();
    void show();
    void show_path();
};

#endif