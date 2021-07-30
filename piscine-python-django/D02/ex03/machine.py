#!/usr/bin/python3

import random
from beverages import HotBeverage, Coffee, Tea, Chocolate, Cappuccino

class   CoffeeMachine:

    class   EmptyCup(HotBeverage):
        def __init__(self, Price=0.90, Name="empty cup"):
            HotBeverage.__init__(self, Price, Name)

        def description(self) -> str:
            return "An empty cup?! Gimme my money back!"


    class   BrokenMachineException(Exception):
        def __init__(self):
            super().__init__("This coffee machine has to be repaired.")


    def __init__(self):
        self.Count = 0


    def repair(self):
        self.Count = 0


    def serve(self, bev) -> HotBeverage():
        if not issubclass(bev, HotBeverage):
            raise Exception("We don't have that beverage")
        if self.Count >= 10:
            raise CoffeeMachine.BrokenMachineException
        else:
            self.Count += 1
            if random.randrange(2):
                return bev()
            else:
                return CoffeeMachine.EmptyCup()