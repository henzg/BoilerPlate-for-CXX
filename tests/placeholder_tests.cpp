#include "doctest.h"
#include "placeholder.hpp"

TEST_CASE("seven letter word returns 7")
{
    CHECK(Placeholder::ReturnLetterCount("Testing") == 7);
}

TEST_CASE("empty string returns 0")
{
    CHECK(Placeholder::ReturnLetterCount("") == 0);
}

TEST_CASE("six letter word returns 6")
{
    CHECK(Placeholder::ReturnLetterCount("SIXSIX") == 6);
}

TEST_CASE("two letters with a new line sign returns 2")
{
    CHECK(Placeholder::ReturnLetterCount("ab\n") == 2);
}
