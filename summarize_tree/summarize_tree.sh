#!/bin/bash

numdirs=$(find "$1" -type d | wc -l)
printf "There were %d directories.\n" $numdirs
numfiles=$(find "$1" -type f | wc -l)
printf "There were %d regular files.\n" $numfiles
