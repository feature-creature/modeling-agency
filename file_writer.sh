#!/bin/bash

stagnant=1;

while [ $stagnant -lt 2 ]
do
    awk -v min=1 -v max=1000000 'BEGIN{srand(); print int(min+rand()*(max-min+1))}' >> file.txt;
    sleep 1;
done
