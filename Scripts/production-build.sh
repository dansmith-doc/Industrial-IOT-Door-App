#!/bin/bash

echo "Updating System..."
sudo apt update && sudo apt upgrade -y
echo "Done"
sleep 10

echo "Building Docker environment...."
sleep 5
chmod +x setup-docker.sh
./setup-docker.sh