#!/bin/bash

echo "Installing dependencies if needed...."
sleep 5
sudo apt install ca-certificates curl gnupg lsb-release -y
sleep 5

echo "Getting Docker setup...."
curl -fsSL https://get.docker.com -o get-docker.sh
sleep 5

echo "Installing...."
sleep 5
./get-docker.sh
sleep 5

echo "Creating Docker group user...."
sudo groupadd docker
sudo usermod -aG docker $USER
sleep 5

echo "Creating Service....."
sudo systemctl enable docker.service
sudo systemctl enable containerd.service
echo "Done...."

sleep 5
echo "LOGOUT AND LOGIN TO ENABLE PERMISSIONS"
