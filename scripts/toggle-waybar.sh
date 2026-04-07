#!/usr/bin/env bash

PIDS=$(ps -u "$USER" -o pid,comm | grep "[w]aybar" | awk '{print $1}')

if [ -n "$PIDS" ]; then
    echo "Closing waybar..."
    echo "$PIDS" | xargs kill -9
else
    echo "Opening waybar..."
    waybar &
fi