cat /etc/passwd | awk '!/^#/' | awk 'NR % 2 == 0 {print $0}' | cut -d ":" -f 1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | sed 's/$/, /' | tr -d '\n' | sed 's/, $/.'/ | tr -d '\n'
