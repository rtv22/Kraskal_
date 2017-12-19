#include <Kraskal_.hpp>
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

SCENARIO("algorithm", "[algorithm]"){
	Graph test_;
	REQUIRE(test_.count() == 0);
}
