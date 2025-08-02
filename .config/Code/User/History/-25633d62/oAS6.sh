#!/bin/bash

LOGFILE="$HOME/.config/hypr/scripts/wallpaper.log"
WALLPAPER_DIR="$HOME/Imagens/Wallpapers/WallpaperGlobal"

# Arquivo para guardar o índice atual
INDEX_FILE="$HOME/.config/hypr/scripts/wallpaper_index"

# Pega a lista de wallpapers
mapfile -t WALLPAPERS < <(find "$WALLPAPER_DIR" -type f \( -iname '*.jpg' -o -iname '*.png' -o -iname '*.jpeg' \) | sort)

TOTAL=${#WALLPAPERS[@]}

if [ $TOTAL -eq 0 ]; then
  echo "$(date): Nenhum wallpaper encontrado em $WALLPAPER_DIR" >> "$LOGFILE"
  exit 1
fi

# Se não existir arquivo índice, começa em 0
if [ ! -f "$INDEX_FILE" ]; then
  echo 0 > "$INDEX_FILE"
fi

CURRENT_INDEX=$(cat "$INDEX_FILE")

case "$1" in
  -n)
    # Próximo wallpaper
    CURRENT_INDEX=$(( (CURRENT_INDEX + 1) % TOTAL ))
    ;;
  -p)
    # Anterior wallpaper
    CURRENT_INDEX=$(( (CURRENT_INDEX - 1 + TOTAL) % TOTAL ))
    ;;
  *)
    # Se não passar argumento, escolhe aleatório
    CURRENT_INDEX=$(( RANDOM % TOTAL ))
    ;;
esac

# Atualiza o índice no arquivo
echo $CURRENT_INDEX > "$INDEX_FILE"

WALLPAPER="${WALLPAPERS[$CURRENT_INDEX]}"

echo "$(date): Definindo wallpaper: $WALLPAPER" >> "$LOGFILE"

# Troca wallpaper com transição suave
swww img "$WALLPAPER" --transition-type grow --transition-fps 60 --transition-duration 1