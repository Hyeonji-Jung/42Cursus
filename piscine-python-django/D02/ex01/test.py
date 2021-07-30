#!/usr/bin/python3

from intern import Intern

noname = Intern()
mark = Intern(Name='Mark')

print(noname)
print(mark)

print(mark.make_coffee())

try:
    noname.work()
except Exception as exc:
    print(exc)
