import sys
import math

# stack a new container `c` in a stack
def stack(stacks, c):
    if len(stacks) > 0:
        last = None
        j = -1
        for i, k in enumerate(stacks):
            if k[0] >= c and (last == None or last > k[0]):
                j = i
                last = k[0]
        if j == -1:
            stacks.append(list(c))
        else:
            stacks[j].insert(0, c)
    else:
        stacks.append(list(c))


def main():
    n = int(input())
    for i in range(n):
        line = input()
        stacks = []
        for y in line:
            stack(stacks, y)
        print(len(stacks))

if __name__ == '__main__':
    main()
