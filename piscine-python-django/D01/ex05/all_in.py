#!/usr/bin/python3

import sys

def is_state(state):
    states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
    }
    for i in states.keys():
        if i.lower() == state.lower():
            return True
    return False

def is_capital(capital):
    capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
    }
    for i in capital_cities.values():
        if i.lower() == capital.lower():
            return True
    return False

def all_in():
    var = sys.argv
    if len(var) == 2:
        states = {
        "Oregon" : "OR",
        "Alabama" : "AL",
        "New Jersey": "NJ",
        "Colorado" : "CO"
        }
        capital_cities = {
        "OR": "Salem",
        "AL": "Montgomery",
        "NJ": "Trenton",
        "CO": "Denver"
        }
        tmp = var[1].split(",")
        data = []

        for i in tmp:
            if i != ' ':
                data.append(i.lstrip())
        for i in data:
            if is_state(i):
                for j in states.keys():
                    if j.lower() == i.lower():
                        print(capital_cities.get((states.get(j))), "is the capital of", j)
            elif is_capital(i):
                for j in capital_cities.keys():
                    if capital_cities.get(j).lower() == i.lower():
                        for k in states.keys():
                            if j == states.get(k):
                                print(capital_cities.get(j), "is the capital of", k)
            else:
                print(i, "is neither a capital city nor a state")

if __name__ == '__main__':
    all_in()