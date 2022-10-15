#!/bin/bash
echo "$1"
find "$1" -type d | wc -l
find "$1" -type f | wc -l
