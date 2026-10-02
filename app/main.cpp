#include "placeholder.hpp"
#include <iostream>
#include <format>

int main()
{
    int res = Placeholder::ReturnLetterCount("Testing");
    std::cout << std::format("Your word has {} letters!", res);
}
