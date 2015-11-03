import random, sys, copy
'''
def mincut(al):
    adj_list = copy.deepcopy(al)

    while len(adj_list) > 2:
        v1 = random.choice(list(adj_list.keys()))
        v2 = random.choice(list(adj_list[v1].keys()))

        for key in adj_list[v2].keys():
            if key in adj_list[v1].keys():
                adj_list[v1][key] += adj_list[v2][key]
            else:
                adj_list[v1][key] = adj_list[v2][key]

        for v in adj_list[v2]:
            if v1 in adj_list[v].keys():
                adj_list[v][v1] += adj_list[v][v2]
            else:
                adj_list[v][v1] = adj_list[v][v2]
            del adj_list[v][v2]

        del adj_list[v1][v1]
        del adj_list[v2]
    # return list(list(adj_list.values())[0].values())[0]
    return list(adj_list[v1].values())[0]
'''

def mincut(al):
    adj_list = copy.deepcopy(al)
    length = []

    while len(adj_list) > 2:
        v1 = random.choice(list(adj_list.keys()))
        v2 = random.choice(adj_list[v1])

        adj_list[v1].extend(adj_list[v2])

        for v in adj_list[v2]:
            adj_list[v].remove(v2)
            adj_list[v].append(v1)
        while v1 in adj_list[v1]:
            adj_list[v1].remove(v1)
        del adj_list[v2]
    for v in adj_list.keys():
        length.append(len(adj_list[v]))
    return length[0]

def main():
    al = dict()
    with open(sys.argv[1], 'r') as f:
        for line in f:
            lst = list(map(int, line.split()))
            # al[lst[0]] = {key: 1 for key in lst[1:]}
            al[lst[0]] = lst[1:]

    final = 1e9

    for _ in range(int(sys.argv[2])):
        m = mincut(al)
        if m < final:
            final = m
    #print(mincuts)
    #print(min(mincuts))
    print(final)

if __name__ == '__main__':
    main()

