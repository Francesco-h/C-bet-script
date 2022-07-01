#/bin/sh


gcc -c -g -w  file/campionato.c -o file/obj/campionato.o
gcc -c -g -w  file/partite.c -o file/obj/partite.o
gcc -c -g -w  file/partita.c -o file/obj/partita.o
gcc -c -g -w  file/schedinacalcio.c -o file/obj/schedinacalcio.o
gcc -c -g -w  file/gara.c -o file/obj/gara.o
gcc -c -g -w  file/piloti.c -o file/obj/piloti.o
gcc -c -g -w  file/pilota.c -o file/obj/pilota.o
gcc -c -g -w  file/schedinaf1.c -o file/obj/schedinaf1.o
gcc -c -g -w  file/main.c -o file/obj/main.o

gcc file/obj/campionato.o file/obj/partite.o file/obj/partita.o file/obj/schedinacalcio.o file/obj/gara.o file/obj/piloti.o file/obj/pilota.o file/obj/schedinaf1.o file/obj/main.o -o main 

