#!/usr/bin/env python3

from path import Path

def test():
    print(f"Current Dir: {Path.getcwd()}")
    try:
        Path.makedirs('./test')
    except Exception as e:
        return print(e)
    try:
        Path.touch('test/something')
    except Exception as e:
        return print(e)
    f = Path('test/something')
    f.write_text('Writing Text ...')
    with open(f.abspath(), 'r') as f:
        print(f.read())

if __name__ == '__main__':
    test()