#include "genetic_tsp.hpp"

std::vector<int> inversion_mutation(std::vector<int> &path)
{
    std::vector<int> res_path(path);
    int rand_vertex1, rand_vertex2;
    int smaller_idx, larger_idx;
    do
    {
        rand_vertex1 = rand() % (res_path.size() - 1);
        rand_vertex2 = rand() % (res_path.size() - 1);
    } while (rand_vertex1 == rand_vertex2);

    smaller_idx = std::min(rand_vertex1, rand_vertex2);
    larger_idx = std::max(rand_vertex1, rand_vertex2);
    int mid_idx = (larger_idx + smaller_idx + 1) / 2;

    for (; smaller_idx < mid_idx; smaller_idx++, larger_idx--)
    {
        std::swap(res_path[smaller_idx], res_path[larger_idx]);
        //std::cout << "swap: " << smaller_idx << "|" << larger_idx << std::endl;
    }
    return res_path;
}

std::vector<int> scramble_mutation(std::vector<int> &path)
{
}

crossing_pair choose_path(std::vector<int> &path1, std::vector<int> &path2)
{
    if (rand() % 2 == 1)
        return crossing_pair(path1, path2);
    return crossing_pair(path2, path1);
}

crossing_pair corssover_pmx(std::vector<int> &path1, std::vector<int> &path2)
{
    show_path(path1);
    show_path(path2);

    std::vector<int> res_path1(path1.size());
    std::vector<int> res_path2(path2.size());

    // section to copy
    int rand_vertex1, rand_vertex2;
    int smaller_idx, larger_idx;
    do
    {
        rand_vertex1 = rand() % (res_path1.size() - 1);
        rand_vertex2 = rand() % (res_path1.size() - 1);
    } while (rand_vertex1 == rand_vertex2);
    smaller_idx = std::min(rand_vertex1, rand_vertex2);
    larger_idx = std::max(rand_vertex1, rand_vertex2);

    // choose from which path to copy
    //crossing_pair choosen_path = choose_path(path1, path2);

    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        res_path1[idx] = path2[idx];
        res_path2[idx] = path1[idx];
    }

    // find not copied elements and match copy between tables
    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        std::vector<int>::iterator position_p1 = std::find(res_path1.begin() + smaller_idx, res_path1.begin() + larger_idx, path1[idx]);
        if (position_p1 == res_path1.begin() + larger_idx)
        {
            // find in path 2 postion of path1[idx] and fill this place in res path 1 with value
            std::vector<int>::iterator position_p2 = std::find(path2.begin(), path2.end(), path1[idx]);
            res_path1[position_p2 - path2.begin()] = path1[idx];
        }
    }

    // find not copied elements and match copy between tables
    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        std::vector<int>::iterator position_p1 = std::find(res_path2.begin() + smaller_idx, res_path2.begin() + larger_idx, path2[idx]);
        if (position_p1 == res_path2.begin() + larger_idx)
        {
            // find in path 2 postion of path1[idx] and fill this place in res path 1 with value
            std::vector<int>::iterator position_p2 = std::find(path1.begin(), path1.end(), path2[idx]);
            res_path2[position_p2 - path1.begin()] = path2[idx];
        }
    }

    // fill crossover results with
    for (int idx = 0; idx < res_path1.size(); idx++)
    {
        if (!res_path1[idx])
        {
            res_path1[idx] = path2[idx];
            res_path2[idx] = path1[idx];
        }
    }

    return crossing_pair(res_path1, res_path2);
}

std::vector<int> crossover_ox(std::vector<int> &path1, std::vector<int> &path2)
{
}

std::vector<int> crossover_ex(std::vector<int> &path1, std::vector<int> &path2)
{
}

double tsp(std::vector<int> path, Graph &graph)
{
    int res = 0;
    for (int i = 1; i < path.size(); i++)
    {
        res += graph.at(path[i - 1], path[i]);
    }
    return res;
}

std::vector<std::vector<int>> survivors_selection()
{
}

/** population */

std::vector<int> new_random_path(std::vector<int> &init_path)
{
    std::vector<int> new_path(init_path);
    std::random_shuffle(new_path.begin() + 1, new_path.end() - 1);
    return new_path;
}

std::vector<std::vector<int>> create_random_population(Graph &graph, Params &params)
{
    // create init path
    std::vector<int> init_path(graph.getVertexCount());
    std::iota(std::begin(init_path), std::end(init_path), 0);
    std::random_shuffle(init_path.begin(), init_path.end());
    init_path.push_back(init_path.front());

    // create init population
    std::vector<std::vector<int>> init_population(params.init_population_size);
    for (int i = 0; i < params.init_population_size; i++)
    {
        init_population[i] = new_random_path(init_path);
        show_path(init_population[i]);
    }

    return init_population;
}

void show_path(std::vector<int> &path)
{
    std::cout << "path {";
    for (auto e : path)
    {
        std::cout << e << ", ";
    }
    std::cout << "}" << std::endl;
}

void mutate_population()
{
}

void crossover_population()
{
}

std::vector<std::vector<int>> select_survivors(std::vector<std::vector<int>> &population, Graph &graph, int next_population_size)
{
    std::vector<std::vector<int>> res;
    std::unordered_map<int, std::vector<int>> tsp_map;

    for (auto path : population)
    {
        tsp_map[tsp(path, graph)] = path;
    }

    if (tsp_map.size() > next_population_size)
    {
        res.resize(next_population_size);
        for (int i = 0; i < next_population_size; i++)
        {
        }
        return res;
    }
    else
    {
        res.resize(tsp_map.size());
    }
}

void genetic_algorithm_tsp(Graph &graph, Params &params)
{
    int global_tsp = INT_MAX;
    std::vector<int> globla_path;
    srand(time(NULL));

    // init population
    std::vector<std::vector<int>> population = create_random_population(graph, params);

    std::cout << "inversion mutation:" << std::endl;
    std::vector<int> mut_path = inversion_mutation(population[population.size() - 1]);
    show_path(mut_path);

    std::cout << "corssing pmx:" << std::endl;
    crossing_pair cross_path_pair = corssover_pmx(population[population.size() - 1], population[population.size() - 2]);
    show_path(cross_path_pair.first);
    show_path(cross_path_pair.second);

    while (true)
    {
        // crossover
        // mutation
        // survivors selection
    }
    // best solution
}
