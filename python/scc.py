import sys
sys.setrecursionlimit(70000)

adj_list = {}
reverse = {}
order = [] 
leaders = {}

from trace1 import trace

def dfs_loop(G, process_ord):
    global leaders
    leaders = {}
    visited = set()
    for v in process_ord:
        if v not in visited:
            visited.add(v)
            dfs.leader = v
            dfs(G, v, visited)

# Iterative
# def dfs(G, v, visited):
    # stack = []
    # stack.append(('child', v))
    # while len(stack) > 0:
        # node = stack.pop()
        # if (node[0] == 'parent'):
            # order.append(node[1])
            # continue
        # stack.append(('parent', node[1]))
        # if node in visited:
            # continue
        # if dfs.leader not in leaders.keys():
            # leaders[dfs.leader] = [node[1]]
        # else:
            # leaders[dfs.leader].append(node[1])
        # try:
            # G[node[1]]
        # except KeyError:
            # order.append(node[1])
            # continue
        # for i in range(len(G[node[1]])-1, -1,-1):
            # if G[node[1]][i] not in visited:
                # visited.add(G[node[1]][i])
                # stack.append(('child', G[node[1]][i]))

# Recursive
def dfs(G, v, visited):
    if dfs.leader not in leaders.keys():
        leaders[dfs.leader] = [v]
    else:
        leaders[dfs.leader].append(v)
    try:
        G[v]
    except KeyError:
        order.append(v)
        return
    for n in G[v]:
        if n not in visited:
            visited.add(n) 
            dfs(G, n, visited)
    order.append(v)

if __name__ == '__main__':
    import fileinput
    for line in fileinput.input():
        edge = tuple(int(x) for x in line.strip('\n').split())
        if edge[0] not in adj_list:
            adj_list[edge[0]] = [edge[1]]
        else:
            adj_list[edge[0]].append(edge[1])
        if edge[1] not in reverse:
            reverse[edge[1]] = [edge[0]]
        else:
            reverse[edge[1]].append(edge[0])
    dfs_loop(reverse, tuple(reverse.keys()))
    # print(order)
    dfs_loop(adj_list, tuple(order[::-1]))
    # print(leaders)
    n = 0
    for l in sorted(leaders, key=lambda k: len(leaders[k]), reverse=True):
        if n > 4:
            break
        print(len(leaders[l]))
        n += 1
