#!/usr/bin/env bash
if [ $# == 0 ]
then
	echo 'Usage: ./makevid [FPS]'
else
	ffmpeg -r $1 -i %05d.ppm -vcodec libx264 -crf 25 -pix_fmt yuv420p out.mp4
fi
