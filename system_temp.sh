#!/bin/bash
TEMPERATURE=`cat /sys/class/thermal/thermal_zone0/temp | cut -c -2`;
TEMPERATUREDEC=`cat /sys/class/thermal/thermal_zone0/temp | cut -c 3`;
echo $TEMPERATURE"."$TEMPERATUREDEC >> sys_temp.txt
