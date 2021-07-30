#!/usr/bin/python3

import sys
import re
import settings

def open_file(filename):
    try:
        with open(filename, 'r') as f:
            template = f.read()
            return template
    except:
        print("Cannot open %s" % filename)
        return None

def fill_template(filename, data):
    try:
        with open(filename, 'w') as f:
            f.write(data)
    except:
        print("Cannot write %s" % filename)

def render(filename):
    template = open_file(filename)
    if template:
        dic = vars(settings)
        try:
            complete_template = template.format(**dic)
            fill_template("%s%s" % (filename[0:-9], ".html"), complete_template)
        except:
            print("Cannot fill %s" % filename)

if __name__ == '__main__':
    if len(sys.argv) == 2:
        if re.search('.*.template$', sys.argv[1]) is not None:
            render(sys.argv[1])
        else:
            print("Your file is not .template file")