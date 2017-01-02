#!/bin/bash

#
# This script repeatedly executes the ray tracing executable
# for all corresponding scene and camera files in the given
# path. It then creates a video from the output ppm files.
#
# ffmpeg should be installed for the video creation to work.
# You can install it on a Ubuntu system using:
#
# sudo apt-get install ffmpeg
#

executable=$1
scenePath=$2
cameraPath=$3
videoName=$4

for i in $scenePath/*.txt
do
    justName=`basename $i ".txt"`
    cameraFile="$cameraPath/$justName.txt"

    cmd="$executable $i $cameraFile"
    echo $cmd
    $cmd
done

cmd="ffmpeg -r 30 -i ${videoName}_%03d.ppm -vcodec libx264 $videoName.mp4"
echo $cmd
$cmd
