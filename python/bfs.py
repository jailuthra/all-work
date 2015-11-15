from collections import deque
import operator
import sys

levels = {}
adj_list = {}

def bfs(start):
    visited = set()
    queue = deque([start])

    global levels
    levels[start] = 0

    while len(queue) > 0:
        node = queue.pop()
        if node in visited:
            continue
        visited.add(node)
        for n in adj_list[node]:
            if n not in visited:
                queue.appendleft(n)
                if n not in levels.keys():
                    levels[n] = levels[node] + 1

if __name__ == '__main__':
    for line in sys.stdin:
        line = line.split()
        adj_list[line[0]] = tuple(line[1:])
    bfs(list(adj_list.keys())[0])
    levels = sorted(levels.items(), key=operator.itemgetter(1))
    for node in levels:
        print('    ' * node[1] + node[0])
