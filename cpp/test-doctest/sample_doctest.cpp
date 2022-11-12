
#include <sstream>
#include "doctest/doctest.h"
#include "recently_used_list.h"

// This code is needed so you can see the contents of the vectors of items when the tests fail
namespace doctest
{
    template <typename T>
    struct StringMaker<std::vector<T> >
    {
        static String convert(const std::vector<T>& in) {
            std::ostringstream oss;

            oss << "[";
            for(typename std::vector<T>::const_iterator it = in.begin(); it != in.end(); ++it)
                oss << *it << ", ";
            oss << "]";

            return oss.str().c_str();
        }
    };
}

TEST_CASE ("RecentlyUsedListDoctest") {
    SUBCASE("empty list") {
        auto rul = RecentlyUsedList();
        auto expected = vector<string>();
        REQUIRE(rul.getContents() == expected);
    }

    SUBCASE("one item"){
        auto rul = RecentlyUsedList();
        rul.insert("item");
        auto expected = vector<string>{"item"};
        REQUIRE(rul.getContents() == expected);
    }

    SUBCASE("order two items by most recently inserted"){
        auto rul = RecentlyUsedList();
        rul.insert("item1");
        rul.insert("item2");
        auto expected = vector<string>{"item2", "item1"};
        REQUIRE(rul.getContents() == expected);
    }

    SUBCASE("duplicate items are moved not inserted"){
        auto rul = RecentlyUsedList();
        rul.insert("item1");
        rul.insert("item2");
        rul.insert("item1");
        auto expected = vector<string>{"item1", "item2"};
        REQUIRE(rul.getContents() == expected);
    }

    SUBCASE("empty strings are not allowed"){
        auto rul = RecentlyUsedList();
        rul.insert("");
        auto expected = vector<string>{};
        REQUIRE(rul.getContents() == expected);
    }

}


