#!/bin/bash

#wybierz nazwe pliku z wiersza poleceń
filename=$1

#wytnij nazwe pliku bez rozszerzenia
#np. test.c zamieni się na test
output_file=$(echo $filename | cut -d "." -f 1)

#wybranie opcji z terminala i przeprowadzenie operacji
if [[ "$2" == "-r" ]]; then
        rm -v $filename
elif [[ "$2" == "-c" ]]; then
        gcc -g -o $output_file $filename #opcja g zostawia w pliku symbole dla debuggera
else 
	#przykładowe użycie:        
	echo "Usage: $0 [filename] [options]"
        echo "Avaliable options:"
        echo "-c - compile program with debugging symbols"
        echo "-r - remove file"
        echo "run - executes created binary"
        exit 1
fi

#execute program
if [[ "$3" == "run" ]]; then
        ./$output_file
        echo ""
fi
exit 0
