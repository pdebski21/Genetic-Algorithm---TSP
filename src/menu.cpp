#include "menu.hpp"

void menu()
{

    std::unique_ptr<Graph> graph;
    std::string fileName;

    int control = -1;
    bool loop = true;
    int test_iter = 0;

    while (loop)
    {
        std::cout << "1) read data from file" << std::endl;
        std::cout << "2) enter stop criterion" << std::endl;
        std::cout << "3) set initial population size" << std::endl;
        std::cout << "4) set mutation factor" << std::endl;
        std::cout << "5) set crossover factor" << std::endl;
        std::cout << "5) choose mutation method" << std::endl;
        std::cout << "6) run algorithm with set parameters" << std::endl;
        std::cout << "7) exit" << std::endl;

        std::cin >> control;
        switch (control)
        {
        case 1:
            std::cin >> fileName;
            graph = read_graph_file(fileName);
            graph->show();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            loop = false;
            break;
        default:
            std::cout << "Wrong menu option" << std::endl;
            break;
        }
    }
}