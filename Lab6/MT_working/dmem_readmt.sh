#!/bin/bash

TOOL=./ylr_risc_cpureg.pl   # change if needed

echo "--------------------------------------"
echo "Stopping CPU..."
echo "--------------------------------------"
$TOOL stop
sleep 1

echo "--------------------------------------"
echo "Reading DMEM values..."
echo "--------------------------------------"

echo "Thread 0"
$TOOL dmemr 0
$TOOL dmemr 1
$TOOL dmemr 2
$TOOL dmemr 3
$TOOL dmemr 4
$TOOL dmemr 5
$TOOL dmemr 6
$TOOL dmemr 7
$TOOL dmemr 8
$TOOL dmemr 9
$TOOL dmemr 10
$TOOL dmemr 11
$TOOL dmemr 12

echo "Thread 1"
$TOOL dmemr 65
$TOOL dmemr 66
$TOOL dmemr 67
$TOOL dmemr 68
$TOOL dmemr 69
$TOOL dmemr 70
$TOOL dmemr 71
$TOOL dmemr 72
$TOOL dmemr 73
$TOOL dmemr 74
$TOOL dmemr 75
$TOOL dmemr 76
$TOOL dmemr 77

echo "Thread 2"
$TOOL dmemr 129
$TOOL dmemr 130
$TOOL dmemr 131
$TOOL dmemr 132
$TOOL dmemr 133
$TOOL dmemr 134
$TOOL dmemr 135
$TOOL dmemr 136
$TOOL dmemr 137
$TOOL dmemr 138
$TOOL dmemr 139
$TOOL dmemr 140
$TOOL dmemr 141

echo "Thread 3"
$TOOL dmemr 193
$TOOL dmemr 194
$TOOL dmemr 195
$TOOL dmemr 196
$TOOL dmemr 197
$TOOL dmemr 198
$TOOL dmemr 199
$TOOL dmemr 200
$TOOL dmemr 201
$TOOL dmemr 202
$TOOL dmemr 203
$TOOL dmemr 204
$TOOL dmemr 205

echo "--------------------------------------"
echo "Done."
echo "--------------------------------------"