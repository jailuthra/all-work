import sys
sys.setrecursionlimit(70000)

adj_list = {}
reverse = {}
order = [] 
leaders = {}

from trace1 import trace

def dfs_loop(G, order):
    global leaders
    leaders = {}
    visited = set()
    for v in order:
        if v not in visited:
            visited.add(v)
            dfs.leader = v
            dfs(G, v, visited)

def dfs(G, v, visited):
    # print(v, end=' ')
    if dfs.leader not in leaders.keys():
        leaders[dfs.leader] = [v]
    else:
        leaders[dfs.leader].append(v)
    try:
        G[v]
    except KeyError:
        # finish[v] = dfs.current
        # dfs.current -= 1
        order.append(v)
        return
    for n in G[v]:
        if n not in visited:
            visited.add(n) 
            dfs(G, n, visited)
    # finish[v] = dfs.current
    # dfs.current -= 1
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
    dfs.current = max(reverse.keys())
    dfs_loop(reverse, order=reverse.keys())
    # print(order)
    # print()
    # print(order)
    # print(leaders)
    # print()
    dfs.current = max(adj_list.keys())
    dfs_loop(adj_list, order=tuple(order[::-1]))
    # print()
    # print(leaders)
    # print()
    #print(leaders)
    n = 0
    for l in sorted(leaders, key=lambda k: len(leaders[k]), reverse=True):
        if n > 4:
            break
        print(len(leaders[l]))
        n += 1

# @trace
# def dfs(G, v, visited):
    # stack = []
    # stack.append(v)
    # while len(stack) > 0:
        # node = stack.pop()
        # if node in visited:
            # continue
        # print(node, end=' ')
        # visited.add(node)
        # try:
            # G[node]
        # except KeyError:
            # continue
        # for i in range(len(G[node])-1, -1,-1):
            # if G[node][i] not in visited:
                # stack.append(G[node][i])
    # print()
