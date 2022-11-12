#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"
#include "recently_used_list.h"

TEST_CASE ("RecentlyUsedList") {
    SECTION("empty list") {
        auto rul = RecentlyUsedList();
        auto expected = vector<string>();
        REQUIRE(rul.getContents() == expected);
    }
    SECTION("one item"){
        auto rul = RecentlyUsedList();
        rul.insert("item");
        auto expected = vector<string>{"item"};
        REQUIRE(rul.getContents() == expected);
    }

    SECTION("order two items by most recently inserted"){
        auto rul = RecentlyUsedList();
        rul.insert("item1");
        rul.insert("item2");
        auto expected = vector<string>{"item2", "item1"};
        REQUIRE(rul.getContents() == expected);
    }

    SECTION("duplicate items are moved not inserted"){
        auto rul = RecentlyUsedList();
        rul.insert("item1");
        rul.insert("item2");
        rul.insert("item1");
        auto expected = vector<string>{"item1", "item2"};
        REQUIRE(rul.getContents() == expected);
    }

    SECTION("empty strings are not allowed"){
        auto rul = RecentlyUsedList();
        rul.insert("");
        auto expected = vector<string>{};
        REQUIRE(rul.getContents() == expected);
    }

}


