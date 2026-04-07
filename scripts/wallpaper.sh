#!/usr/bin/env bash

WALLPAPER_DIR="$HOME/Pictures/wallpapers"

WALLPAPER=$(find "$WALLPAPER_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg"  -o -iname "*.webp" -o -iname "*.gif" \) | shuf -n 1)

if ! pgrep -x "awww-daemon" > /dev/null; then
    awww-daemon &
    sleep 0.5
fi

awww img "$WALLPAPER" --transition-type any --transition-fps 60 --transition-duration 2

ln -sf "$WALLPAPER" "$HOME/.cache/current_wallpaper"