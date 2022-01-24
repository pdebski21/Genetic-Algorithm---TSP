#ifndef GENETIC_TSP
#define GENETIC_TSP

#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

#include "Graph.hpp"
#include "params.hpp"

using mutation_pair = std::pair<std::vector<int> &, std::vector<int> &>;
using crossing_pair = std::pair<std::vector<int>, std::vector<int>>;

std::vector<int> new_random_path(std::vector<int> &init_path);
std::vector<std::vector<int>> create_random_population(Graph &graph, Params &params);
void show_path(std::vector<int> &path);
void genetic_algorithm_tsp(Graph &graph, Params &params);

#endif