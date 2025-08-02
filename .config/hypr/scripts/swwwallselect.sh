#!/bin/bash

WALLPAPER_DIR="$HOME/Imagens/Wallpapers/WallpaperGlobal"
SELECTED=$(find "$WALLPAPER_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" \) | sort | rofi -dmenu -i -p "Escolha o wallpaper")

[ -z "$SELECTED" ] && exit 0

swww img "$SELECTED" --transition-type grow --transition-fps 60 --transition-duration 1
