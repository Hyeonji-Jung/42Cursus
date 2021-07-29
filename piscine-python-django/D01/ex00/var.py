#!/usr/bin/python3

def ft_type(var):
    print("{0} has a type {1}".format(var, type(var)))

def my_var():
    ft_type(42)
    ft_type("42")
    ft_type("quarante-deux")
    ft_type(42.0)
    ft_type(True)
    ft_type([42])
    ft_type({42: 42})
    ft_type((42,))
    ft_type(set())

if __name__ == '__main__':
    my_var()  