#!/bin/sh

python3 -m venv local_lib
source local_lib/bin/activate
python3 -m pip --version
python3 -m pip install --log install.log --force-reinstall git+https://github.com/jaraco/path.git
python3 my_program.py