#!/usr/bin/python3

import sys

def capital_city():
    var = sys.argv
    if len(var) == 2:
        states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
        }
        flag = False
        for i in states.items():
            if var[1] == i[0]:
                print_city(i[1])
                flag = True
        print_unknown(flag)

def print_city(state):
    flag = False
    capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
        }
    for i in capital_cities.items():
        if i[0] == state:
            print(i[1])
            flag = True
            break
    print_unknown(flag)

def print_unknown(flag):
    if flag != True:
        print("Unknown State")

if __name__ == '__main__':
    capital_city()