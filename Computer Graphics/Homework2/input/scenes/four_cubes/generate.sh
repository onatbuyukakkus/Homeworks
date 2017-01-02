#!/bin/bash

for angle in {0..360}
do
sceneFile="2
0 0 0
25 25 25
1
0 2.5 5 
255 255 255
1
#Material 1
1 1 1
1 1 1
1 1 1 10 
0 0 0 		
#Textures
1
cube_texture.jpg
#Translation
4
-2.0 -2.0 0.0
2.0 -2.0 0.0
2.0 2.0 0.0
-2.0 2.0 0.0
#Scaling
1
2.0 2.0 2.0
#Rotation
4
$angle 1.0 0.0 0.0
$angle 0.0 1.0 0.0
$angle 0.0 0.0 1.0
$angle 1.0 1.0 1.0
4
#CubeInstance
1
1
3
r 1
s 1
t 1
#CubeInstance
1
1
3
r 2
s 1
t 2
#CubeInstance
1
1
3
r 3
s 1
t 3
#CubeInstance
1
1
3
r 4
s 1
t 4"

    if [ "$angle" -lt "10" ]
    then
        printf "%s" "$sceneFile" > four_cubes_00$angle.txt
    elif [ "$angle" -lt "100" ]
    then
        printf "%s" "$sceneFile" > four_cubes_0$angle.txt
    else
        printf "%s" "$sceneFile" > four_cubes_$angle.txt
    fi
done

