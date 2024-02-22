cat /etc/passwd | set '^#' | awk "NR % 2 == 0 {print $0}" | rev | sort -R | awk "NR>=\$FT_LINE1 && NR<=\$FT_LINE2" | tr '\n' ',' | sed 's/,$/\./' | sed 's/,/, /g'

