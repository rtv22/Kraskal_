#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define edge pair<int,int>

class Graph {
private:
	vector<pair<int, edge>> G; // исходный граф
	vector<pair<int, edge>> T; // конечный
	int *parent;
	int n; //Кол-во вершин графа
public:
	Graph();
	Graph(int count);
	int count();
	int array_(int );
	Graph operator==(Graph &copy);
	Graph(const Graph &copy);
	void AddWeightedEdge(int first, int second, int w);
	int find_set(int i);
	void union_set(int u, int v);
	void comp();
	vector<pair<int, edge>> kraskal();
	void print();
};
