#!/usr/bin/python3

import sys
import antigravity

def geohashing():
    if len(sys.argv) == 4:
        try:
           antigravity.geohash(float(sys.argv[1]), float(sys.argv[2]), bytes(sys.argv[3], 'utf-8'))
        except Exception:
            print(Exception)
    else:
        print("Error: 3 Arguments required")

if __name__ == '__main__':
    geohashing()