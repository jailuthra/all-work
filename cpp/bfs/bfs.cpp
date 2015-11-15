#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

map<int, int> levels;

void bfs(map<int, vector<int> > adj_list, int start_node)
{
	vector<int> visited;
	queue<int> q;
	q.push(start_node);
	levels[start_node] = 0;
	vector<int> connected;
	int node, n;
	int i;
	while (q.size() > 0) {
		node = q.front(); q.pop();
		if (find(visited.begin(), visited.end(), node) != visited.end()) {
			continue;
		}
		visited.push_back(node);
		connected = adj_list[node];	
		for (auto& n: connected) {
			if (find(visited.begin(), visited.end(), n) == visited.end()) {
				q.push(n);
				if (levels.find(n) == levels.end()) {
					levels[n] = levels[node] + 1;
				}
			}
		}
	}
}

int main(int argc, char * argv[])
{
	map<int, vector<int> > adj_list;
	vector<int> node_list;
	string line;
	stringstream ss;
	int node;
	int edge;
	int i, j;
	while(getline(cin, line)) {
		ss = stringstream();
		ss.str(line);
		node_list = vector<int>();
		ss >> node;
		while (ss >> edge) {
			node_list.push_back(edge);
		}
		adj_list[node] = node_list;
	}
	int start_node = adj_list.begin()->first;
	bfs(adj_list, start_node);
	for(auto& node_i: levels) {
		for(j = 0; j<node_i.second; j++) {
			cout << "    ";
		}
		cout << node_i.first << endl;
	}
	return 0;
}
