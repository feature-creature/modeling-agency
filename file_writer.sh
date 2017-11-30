awk -v min=1 -v max=1000000 'BEGIN{srand(); print int(min+rand()*(max-min+1))}' >> file.txt;

