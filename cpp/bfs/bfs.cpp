#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

map<int, int> levels;

vector<int> get_connected(int node, vector< vector<int> > adj_list)
{
	vector<int> connected;
	int i, j;
	for(i=0; i<adj_list.size(); i++) {
		if (adj_list[i][0] == node) {
			for (j=1; j<adj_list[i].size(); j++) {
				connected.push_back(adj_list[i][j]);
			}
			break;
		}
	}
	return connected;
}

void bfs(vector< vector<int> > adj_list, int start_node)
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
		connected = get_connected(node, adj_list);	
		for (i=0; i<connected.size(); i++) {
			n = connected[i];
			if (find(visited.begin(), visited.end(), n) == visited.end()) {
				q.push(n);
				if (levels.find(n) == levels.end()) {
					levels[n] = levels[node] + 1;
				}
			}
		}
		/*cout << endl << "Queue is: ";
		queue<int> qu = q;
		while(qu.front()) {
			cout << qu.front() << " ";
			qu.pop();
		}
		cout << endl;*/
	}
}

int main()
{
	vector< vector<int> > adj_list;
	vector<int> node_list;
	string line;
	stringstream ss;
	int node;
	int i, j;
	while(getline(cin, line)) {
		ss = stringstream();
		ss.str(line);
		node_list = vector<int>();
		while (ss >> node) {
			node_list.push_back(node);
		}
		adj_list.push_back(node_list);
	}
	int start_node = adj_list[0][0];
	bfs(adj_list, start_node);
	for(auto& node_i: levels) {
		for(j = 0; j<node_i.second; j++) {
			cout << "    ";
		}
		cout << node_i.first << endl;
	}
	return 0;
}
