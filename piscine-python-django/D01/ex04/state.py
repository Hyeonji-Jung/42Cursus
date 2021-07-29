#!/usr/bin/python3

import sys

def capital_city():
    var = sys.argv
    if len(var) == 2:
        capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
        }
        flag = False
        for i in capital_cities.items():
            if var[1] == i[1]:
                print_state(i[0])
                flag = True
        print_unknown(flag)

def print_state(city):
    flag = False
    states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
        }
    for i in states.items():
        if i[1] == city:
            print(i[0])
            flag = True
            break
    print_unknown(flag)

def print_unknown(flag):
    if flag != True:
        print("Unknown capital city")

if __name__ == '__main__':
    capital_city()