#include "placeholder.hpp"

int Placeholder::ReturnLetterCount(const std::string& str)
{
    int count = 0;

    for (const auto c : str)
    {
        if (c != '\n')
            count++;
    }

    return count;
}
