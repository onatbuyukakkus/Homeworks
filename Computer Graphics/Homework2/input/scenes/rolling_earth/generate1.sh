#!/bin/bash

for angle in {0..299}
do
xVal=$(echo "-10 + $angle*0.174533"|bc)
sceneFile="2
0 0 0
25 25 25
3
20 20 -60
3000000 3000000 3000000
-20 20 -60
3000000 3000000 3000000
0 -200 -60
3000000 3000000 3000000
2
#Material 1
1 1 1 
1 1 1 
1 1 1 150
0 0 0       
#Material 2
1 1 1 
0.6 0.6 0.6
0 0 0 150
0.8 0.8 0.8      
#Textures
2
earth.jpg
wood.jpg
#Translation
3
$xVal 0 -100
10 0 -100
0 -25 -50
#Scaling
2
10 10 10
300 30 300
#Rotation
1
$angle 0 0 -1 
2
#SphereInstance
1 
1 
3
s 1
r 1
t 1
#CubeInstance
2
2
2
s 2
t 3"

    if [ "$angle" -lt "10" ]
    then
        printf "%s" "$sceneFile" > rolling_earth_00$angle.txt
    elif [ "$angle" -lt "100" ]
    then
        printf "%s" "$sceneFile" > rolling_earth_0$angle.txt
    else
        printf "%s" "$sceneFile" > rolling_earth_$angle.txt
    fi
done

