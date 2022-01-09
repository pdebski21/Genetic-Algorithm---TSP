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

    for (; smaller_idx < res_path.size() / 2; smaller_idx++, larger_idx--)
    {
        std::swap(res_path[smaller_idx], res_path[larger_idx]);
    }
    return res_path;
}

std::vector<int> scramble_mutation(std::vector<int> &path)
{
}

std::vector<int> &choose_path(std::vector<int> &path1, std::vector<int> &path2)
{
    if (rand() % 2 == 1)
        return path2;
    return path1;
}

std::vector<int> corssover_pmx(std::vector<int> &path1, std::vector<int> &path2)
{
    std::vector<int> res_path(path1.size());

    // section to copy
    int rand_vertex1, rand_vertex2;
    int smaller_idx, larger_idx;
    do
    {
        rand_vertex1 = rand() % (res_path.size() - 1);
        rand_vertex2 = rand() % (res_path.size() - 1);
    } while (rand_vertex1 == rand_vertex2);
    smaller_idx = std::min(rand_vertex1, rand_vertex2);
    larger_idx = std::max(rand_vertex1, rand_vertex2);

    // choose from which path to copy
    std::vector<int> &choosen_path = choose_path(path1, path2);
    for (int idx = smaller_idx; idx <= larger_idx; idx++)
    {
        res_path[idx] = choosen_path[idx];
    }

    // find not copied elements and match copy between tables
    
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

void genetic_algorithm_tsp(Graph &graph)
{
    std::vector<int> init_path(graph.getVertexCount());
    std::iota(std::begin(init_path), std::end(init_path), 0);
    std::random_shuffle(init_path.begin(), init_path.end());

    int global_tsp = INT_MAX;
    std::vector<int> globla_path;
    std::vector<int> next_path;

    srand(time(NULL));

    while (true)
    {
    }
}
