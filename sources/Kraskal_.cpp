#include "Kraskal_.hpp"

Graph::Graph() : n{ 0 }, parent{ nullptr }
{}

int Graph::count()
{
	return n;
}

int Graph::array_(int value)
{
	return parent[value];
}

Graph::Graph(int n) {
	parent = new int[n];
	for (int i = 0; i < n; i++)
		parent[i] = i;
} 

void Graph::AddWeightedEdge(int first, int second, int w) {
	G.push_back(make_pair(w, edge(first, second)));
}

int Graph::find_set(int i) {
	if (i == parent[i])
		return i;
	else
		return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
	parent[u] = parent[v];
}

vector<pair<int, edge>> Graph::kraskal() {
	int uRep, vRep;
	sort(G.begin(), G.end()); // по возрастанию
	for (int i = 0; i < G.size(); i++) {
		uRep = find_set(G[i].second.first);
		vRep = find_set(G[i].second.second);
		if (uRep != vRep) { // чтобы не отображалось дважды
			T.push_back(G[i]);
			union_set(uRep, vRep);
		} 
	}
	return T;
}

void Graph::print() {
	cout << "Edge :" << " Weight" << endl;
	for (int i = 0; i < T.size(); i++) {
		cout << T[i].second.first << " - " << T[i].second.second << " : "
			<< T[i].first;
		cout << endl;
	}
}