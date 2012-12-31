#!/bin/bash 
while [ 1 = 1 ]
do
	#eject cdrom
	eject 

	#pull back cd rom tray back
	eject -t 
done
