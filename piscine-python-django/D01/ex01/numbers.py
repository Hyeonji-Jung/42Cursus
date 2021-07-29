#!/usr/bin/python3

def nums():
    f = open("numbers.txt", 'r')
    line = f.readline()

    for i in line:
        if i == ',':
            print("")
        else:
            print(i, end='')
    
    f.close()

if __name__ == '__main__':
    nums()