#!/bin/bash

# Pasta onde as screenshots vão ficar
DIR=~/Pictures/Screenshots
mkdir -p "$DIR"

# Hora e data pra nome do arquivo
FILE="$DIR/screenshot_$(date +%Y-%m-%d_%H-%M-%S).png"

case "$1" in
  s)  # captura parcial (slurp pra selecionar área)
    grim -g "$(slurp)" "$FILE"
    ;;
  sf) # captura parcial, tela congelada (só grim + slurp, pq freeze é mais avançado)
    grim -g "$(slurp)" "$FILE"
    ;;
  m)  # print do monitor atual (usando grim --focused)
    grim -o "$(hyprctl activewindow | grep monitor | awk '{print $2}')" "$FILE"
    ;;
  p)  # print de todos os monitores
    grim "$FILE"
    ;;
  *)  # se não passar argumento, printa tudo
    grim "$FILE"
    ;;
esac

notify-send "Screenshot salva em" "$FILE"
