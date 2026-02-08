#!/bin/bash

#Nodes
M=node2
N0=nf8.usc.edu
N1=nf9.usc.edu
N2=nf5.usc.edu
N3=nf6.usc.edu

#IP Addresses
IP0=10.0.8.3
IP1=10.0.9.3
IP2=10.0.10.3
IP3=10.0.11.3

PORT=5110

#Starting the server on all nodes - receiver
ssh -f $M@$N0 "iperf -s -p $PORT > receiver_server.log 2>&1" &
echo "Starting node 0 as server"
ssh -f $M@$N1 "iperf -s -u > receiver_server.log 2>&1" &
echo "Starting node 1 as server"
ssh -f $M@$N2 "iperf -s -u > receiver_server.log 2>&1" &
echo "Starting node 2 as server"
ssh -f $M@$N3 "iperf -s -u > receiver_server.log 2>&1" &
echo "Starting node 2 as server"

sleep 2

#Starting the client on all nodes - sender
ssh $M@$N3 "iperf -c $IP0 -t 10 -i 1 -p $PORT" &
echo "Starting node 3 as client"
sleep 12
ssh $M@$N2 "iperf -c $IP1 -b 100M -l 512 -t 30 -i 1" &
echo "Starting node 3 as client"
sleep 32
ssh $M@$N1 "iperf -c $IP2 -u -b 1000M -l 512 -t 30 -i 1" &
echo "Starting node 3 as client"
sleep 32
ssh $M@$N0 "iperf -c $IP3 -u -b 1000M -l 1024 -t 30 -i 1" &
echo "Starting node 3 as client"
sleep 32

#killing the client and the server
#ssh $M@$N0 "pkill iperf"
#echo "Killing the server"

#ssh $M@$N1 "pkill iperf"
#echo "Killing the client"

echo "Test Complete"