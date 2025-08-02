#!/bin/bash

WALL=$(find ~/Imagens/Wallpapers -type f \( -iname '*.jpg' -o -iname '*.png' -o -iname '*.jpeg' \) | tofi --config ~/.config/tofi/config)

[ -z "$WALL" ] && exit

swww img "$WALL" --transition-type grow --transition-pos 0.5,0.5 --transition-fps 60 --transition-step 90
