#!/bin/bash

echo "Creating Docker swarm services..."
sleep 5

echo "Creating MQTT Service... 1/5"
docker service create -d --name mqtt-production -publish 1900:1883 -network=production -replicas 2 mqtt-production
echo "Done"
sleep 10

echo "Creating Console 1 Service... 2/5" 
docker service create -d --name console-1-terminal -publish 1850:1880 -volume console-1-production-data:/data -network=production -replicas 2 console-1-terminal
echo "Done"
sleep 10

echo "Creating Console 2 Service... 3/5" 
docker service create -d --name console-2-terminal -publish 1860:1880 -volume console-2-production-data:/data -network=production -replicas 2 console-2-terminal
echo "Done"
sleep 10

echo "Creating Mobile App Service... 4/5" 
docker service create -d --name mobile-app -publish 1870:1880 -volume mobile-app-production-data:/data -network=production -replicas 5 mobile-app
echo "Done"
sleep 10

echo "Creating Main Console Service... 5/5" 
docker service create -d --name main-console -publish 1880:1880 -volume main-console-production-data:/data -network=production -replicas 5 main-console
echo "All Done"
sleep 10