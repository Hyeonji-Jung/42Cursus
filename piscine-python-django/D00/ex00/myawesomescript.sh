#!/bin/sh

if [ $1 ]; then
    curl --head --silent $1 2>/dev/null | grep "Location: " | cut -c 11-
fi