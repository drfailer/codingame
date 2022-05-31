import sys
import math
import numpy as np

def main():
    # game loop
    while True:
        mountains = []
        for i in range(8):
            mountain_h = int(input())  # represents the height of one mountain.
            mountains.append(mountain_h)
    
        order = np.argsort(np.array(mountains)) # sort indixes
        print(np.flip(order)[0]) # print the highest mountain
    

if __name__ == '__main__':
    main()
