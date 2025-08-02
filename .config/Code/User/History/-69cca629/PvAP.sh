#!/bin/bash

# Pasta onde ficam seus wallpapers
WALLPAPER_DIR="$HOME/Imagens/Wallpapers/meuswallpapers"
INDEX_FILE="$HOME/.config/hypr/scripts/wallpaper_index"
WALLPAPERS=($(find "$WALLPAPER_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" \) | sort))

# Se não existir ainda, começa no 0
[ ! -f "$INDEX_FILE" ] && echo 0 > "$INDEX_FILE"

# Pega o index atual
INDEX=$(cat "$INDEX_FILE")

# Argumentos: -n (next), -p (previous)
case "$1" in
    -n)
        INDEX=$(( (INDEX + 1) % ${#WALLPAPERS[@]} ))
        ;;
    -p)
        INDEX=$(( (INDEX - 1 + ${#WALLPAPERS[@]}) % ${#WALLPAPERS[@]} ))
        ;;
    *)
        echo "Uso: $0 -n | -p"
        exit 1
        ;;
esac

# Salva o novo índice
echo "$INDEX" > "$INDEX_FILE"

# Define o wallpaper
swww img "${WALLPAPERS[$INDEX]}" --transition-type grow --transition-fps 60 --transition-duration 1
