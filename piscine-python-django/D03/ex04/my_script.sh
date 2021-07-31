#!/bin/sh

python3 -m venv django_env
source django_env/bin/activate
python3 -m pip install --upgrade pip
python3 -m pip install -r requirement.txt