#include <Kraskal_.hpp>
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

SCENARIO("init", "[init]"){
	Graph test_;
	REQUIRE(test_.count() == 0);
}

SCENARIO("algorithm_1", "[algorithm_1]"){
	Graph test(4);
	test.AddWeightedEdge(0, 1, 1);			
	test.AddWeightedEdge(0, 2, 4);			
	test.AddWeightedEdge(0, 3, 3);					
	test.AddWeightedEdge(1, 3, 2);			
	test.AddWeightedEdge(3, 0, 3);					
	test.AddWeightedEdge(3, 2, 5);			
	test.AddWeightedEdge(2, 1, 4);											  
	vector<pair<int, edge>> k; 
	k.push_back(make_pair(1, edge(0, 1)));
	k.push_back(make_pair(2, edge(1, 3)));
	k.push_back(make_pair(4, edge(0, 2)));
	REQUIRE (k == test.kraskal());
}

SCENARIO("algorithm_2", "[algorithm_2]"){
	Graph test_(6);
	test_.AddWeightedEdge(0, 1, 6);
	test_.AddWeightedEdge(0, 2, 1);
	test_.AddWeightedEdge(0, 3, 5);
	test_.AddWeightedEdge(1, 2, 5);
	test_.AddWeightedEdge(1, 4, 3);
	test_.AddWeightedEdge(2, 3, 5);
	test_.AddWeightedEdge(2, 4, 6);
	test_.AddWeightedEdge(2, 5, 4);
	test_.AddWeightedEdge(3, 5, 2);
	test_.AddWeightedEdge(4, 5, 6);
	vector<pair<int, edge>> k; 
	k.push_back(make_pair(1, edge(0, 2)));
	k.push_back(make_pair(2, edge(3, 5)));
	k.push_back(make_pair(3, edge(1, 4)));
	k.push_back(make_pair(4, edge(2, 5)));
	k.push_back(make_pair(5, edge(1, 2)));
	REQUIRE (k == test_.kraskal());
}	

SCENARIO("algorithm_3", "[algorithm_3]"){
	Graph test(100);
	for (int i = 0; i < 5; i++)
	{
		test.AddWeightedEdge(i, i + 1, 1);
		test.AddWeightedEdge(i + 1, 4 - i, 2);
	}
	test.AddWeightedEdge(3, 6, 3);
	test.AddWeightedEdge(3, 6, 7);
	test.AddWeightedEdge(7, 6, 7);
	test.AddWeightedEdge(1, 7, 8);
	vector<pair<int, edge>> k;
	k.push_back(make_pair(1, edge(0, 1)));
	k.push_back(make_pair(1, edge(1, 2)));
	k.push_back(make_pair(1, edge(3, 2)));
	k.push_back(make_pair(1, edge(4, 3)));
	k.push_back(make_pair(1, edge(4, 5)));
	k.push_back(make_pair(3, edge(3, 6)));
	k.push_back(make_pair(7, edge(7, 6)));
	REQUIRE (k == test.kraskal());
}
