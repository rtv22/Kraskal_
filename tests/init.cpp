#include <Kraskal_.hpp>
#include <catch.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

SCENARIO("init", "[init]"){
	Graph test_;
	REQUIRE(test_.count() == 0);
}

SCENARIO("algorithm", "[algorithm]"){
	Graph test(4);
	test.AddWeightedEdge(0, 1, 1);			////   (1)-вес			 0                            0
	test.AddWeightedEdge(0, 2, 4);			////    1- вершина графа        /| \			     / \
	test.AddWeightedEdge(0, 3, 3);			////			    (1)/ |  \(4)	        (4) /   \(1)
	test.AddWeightedEdge(1, 0, 1);			////			      /	 |   \			   /     \
	test.AddWeightedEdge(1, 3, 2);			////			     1   |    2       -------->   2       1   
	test.AddWeightedEdge(3, 0, 3);			////			      \  |(3)/				  |
	test.AddWeightedEdge(3, 1, 2);			////			    (2)\ |  /(5)                          |(2)
	test.AddWeightedEdge(3, 2, 5);			////		                \| /                              |
	test.AddWeightedEdge(2, 1, 4);			////			         3				  3
	test.AddWeightedEdge(2, 3, 5);									  
	vector<pair<int, edge>> k; 
	k.push_back(make_pair(1, edge(0, 1)));
	k.push_back(make_pair(2, edge(1, 3)));
	k.push_back(make_pair(4, edge(0, 2)));
	REQUIRE((k == test.kraskal()) == true);
}

SCENARIO("algorithm_1", "[algorithm_1]"){
	Graph test_(6);
	test_.AddWeightedEdge(0, 1, 6);
	test_.AddWeightedEdge(0, 2, 1);
	test_.AddWeightedEdge(0, 3, 5);
	test_.AddWeightedEdge(1, 0, 6);
	test_.AddWeightedEdge(1, 2, 5);
	test_.AddWeightedEdge(1, 4, 3);
	test_.AddWeightedEdge(2, 0, 1);
	test_.AddWeightedEdge(2, 1, 5);
	test_.AddWeightedEdge(2, 3, 5);
	test_.AddWeightedEdge(2, 4, 6);
	test_.AddWeightedEdge(2, 5, 4);
	test_.AddWeightedEdge(3, 0, 5);
	test_.AddWeightedEdge(3, 2, 5);
	test_.AddWeightedEdge(3, 5, 2);
	test_.AddWeightedEdge(4, 1, 3);
	test_.AddWeightedEdge(4, 2, 6);
	test_.AddWeightedEdge(4, 5, 6);
	test_.AddWeightedEdge(5, 3, 2);
	test_.AddWeightedEdge(5, 2, 4);
	test_.AddWeightedEdge(5, 4, 6);
	vector<pair<int, edge>> k; 
	k.push_back(make_pair(1, edge(0, 2)));
	k.push_back(make_pair(2, edge(3, 5)));
	k.push_back(make_pair(3, edge(1, 4)));
	k.push_back(make_pair(4, edge(2, 5)));
	k.push_back(make_pair(5, edge(1, 2)));
	REQUIRE((k == test_.kraskal()) == true);
}	
