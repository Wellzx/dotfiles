#!/bin/bash

LOGFILE="$HOME/.config/hypr/scripts/wallpaper.log"
WALLPAPER_DIR="$HOME/Imagens/Wallpapers"
DELAY=100  # Tempo entre trocas em segundos

echo "===== Script iniciado em $(date) =====" >> "$LOGFILE"

# Inicia o daemon do swww se ainda não estiver rodando
if ! pgrep -x "swww-daemon" > /dev/null; then
    echo "$(date): Iniciando swww-daemon..." >> "$LOGFILE"
    swww-daemon &
    sleep 2  # Dar um tempinho maior pro daemon iniciar
else
    echo "$(date): swww-daemon já está rodando." >> "$LOGFILE"
fi

while true; do
    # Seleciona aleatoriamente uma imagem da pasta
    WALLPAPER=$(find "$WALLPAPER_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg" -o -iname "*.gif" \) | shuf -n 1)
    
    if [ -z "$WALLPAPER" ]; then
        echo "$(date): Nenhum wallpaper encontrado em $WALLPAPER_DIR" >> "$LOGFILE"
        sleep $DELAY
        continue
    fi

    echo "$(date): Definindo wallpaper: $WALLPAPER" >> "$LOGFILE"
    swww img "$WALLPAPER" --transition-type any --transition-fps 60 --transition-duration 1

    sleep $DELAY
done