# malloc
Que se cache derriere malloc ? Vous l'utilisez depuis la piscine C, mais ce n'est pas un appel système. Découvrez les rouages d'une gestion optimum de la mémoire, et recodez-le, ainsi que free et realloc.

## Comment compiler la lib ?
Sous Linux :
  `make`

Sous Docker :

-  `./launch.sh` 
-  `make -j` pour compiler la lib uniquement, `make -j test` pour compiler un programme de test.

Pour utiliser gdb :

- `gdb ./test`
- `set environment LD_PRELOAD lib/libft_malloc.so`
