#!/usr/bin/python3

import beverages

def HotBeverageTest(Class):
    cl = Class()
    print("_______________________")
    print("%s :" % Class.__name__)
    print(cl)
    print("_______________________")

HotBeverageTest(beverages.HotBeverage)
HotBeverageTest(beverages.Coffee)
HotBeverageTest(beverages.Tea)
HotBeverageTest(beverages.Chocolate)
HotBeverageTest(beverages.Cappuccino)