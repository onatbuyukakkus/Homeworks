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
0 0 0
0 0 -1
0 1 0
-3 3 -2 2 10 2160 1440
rolling_earth_$value.ppm"

    printf "%s" "$cameraFile" > rolling_earth_$value.txt
done
