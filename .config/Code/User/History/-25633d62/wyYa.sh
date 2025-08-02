#!/bin/bash

WALLPAPER_DIR="$HOME/Imagens/Wallpapers"
DELAY=60  # Tempo entre trocas em segundos

# Inicia o daemon do swww se ainda não estiver rodando
if ! pgrep -x "swww-daemon" > /dev/null; then
    swww-daemon &
    sleep 1  # Dá um tempo pro daemon iniciar
fi

while true; do
    # Seleciona aleatoriamente uma imagem da pasta
    WALLPAPER=$(find "$WALLPAPER_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg" -o -iname "*.gif" \) | shuf -n 1)
    
    # Aplica o wallpaper com transição
    swww img "$WALLPAPER" --transition-type any --transition-fps 60 --transition-duration 1

    # Espera antes de trocar novamente
    sleep $DELAY
done