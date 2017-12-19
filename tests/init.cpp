#include <Kraskal_.hpp>
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

SCENARIO("algorithm", "[algorithm]"){
	Graph test_;
	REQUIRE(test_.count() == 0);
}

/*SCENARIO("algorithm", "[algorithm]")
{
	Graph test(6);
	test.AddWeightedEdge(0, 1, 6);
	test.AddWeightedEdge(0, 2, 1);
	test.AddWeightedEdge(0, 3, 5);
	test.AddWeightedEdge(1, 0, 6);
	test.AddWeightedEdge(1, 2, 5);
	test.AddWeightedEdge(1, 4, 3);
	test.AddWeightedEdge(2, 0, 1);
	test.AddWeightedEdge(2, 1, 5);
	test.AddWeightedEdge(2, 3, 5);
	test.AddWeightedEdge(2, 4, 6);
	test.AddWeightedEdge(2, 5, 4);
	test.AddWeightedEdge(3, 0, 5);
	test.AddWeightedEdge(3, 2, 5);
	test.AddWeightedEdge(3, 5, 2);
	test.AddWeightedEdge(4, 1, 3);
	test.AddWeightedEdge(4, 2, 6);
	test.AddWeightedEdge(4, 5, 6);
	test.AddWeightedEdge(5, 3, 2);
	test.AddWeightedEdge(5, 2, 4);
	test.AddWeightedEdge(5, 4, 6);
	vector<pair<int, edge>> T;
	T.push_back(make_pair(1, edge(0, 2)));
	T.push_back(make_pair(2, edge(3, 5)));
	T.push_back(make_pair(3, edge(1, 4)));
	T.push_back(make_pair(4, edge(2, 5)));
	T.push_back(make_pair(5, edge(1, 2)));
	REQUIRE(true==(test.kraskal() == T));
	
}
