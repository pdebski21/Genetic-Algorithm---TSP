#include "params.hpp"

/** Params */

Params::Params()
{
}

void Params::showParams()
{
}

/** State */

State::State()
{
}

void State::show()
{
}

void State::show_path()
{
    std::cout << "path: { " << std::endl;
    for (auto p : path)
    {
        std::cout << p << ", ";
    }
    std::cout << "}" << std::endl;
}
