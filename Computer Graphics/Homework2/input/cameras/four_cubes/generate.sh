#!/bin/bash

for angle in {0..360}
do
    if [ "$angle" -lt "10" ]
    then
        value="00$angle"
    elif [ "$angle" -lt "100" ]
    then
        value="0$angle"
    else
        value="$angle"
    fi

cameraFile="1
#Camera 1
0 0 5
0 0 -1
0 1 0
-1 1 -1 1 1 512 512
four_cubes_$value.ppm"

    printf "%s" "$cameraFile" > four_cubes_$value.txt
done
