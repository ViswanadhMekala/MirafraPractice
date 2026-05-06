#!/bin/bash

# 1. Compile the latest code
echo "Compiling..."
gcc server.c -o server -lpthread -lrt
gcc client.c -o client -lrt

# 2. Start the server in the background
./server &
SERVER_PID=$! # Capture the server's Process ID
echo "Server started with PID: $SERVER_PID"

# 3. Give the server a moment to initialize IPC resources
sleep 1

# 4. Automate the client with input
echo "Sending '1+1' to client..."
echo "1+1" | ./client

echo "Sending '10*5' to client..."
echo "10*5" | ./client

# 5. Clean up: Kill the server and remove IPC segments
echo "Cleaning up..."
kill $SERVER_PID
# Optional: force remove IPCs if the server didn't clean up
# ipcrm -a 

