#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "list.h"
#include "list.c"
#include "knapsack.h"
#include "knapsack.c"
#include "io.h"
#include "io.c"

int main(int argc, char *argv[]) {
	int default_size = (argc - 2) >> 1;
	item *items = (item *) malloc(default_size * sizeof(item));
	io_get(items, argc, argv);
	//io_array_put(items, default_size);
	
	knapsack_solve(atoi(argv[1]), items, default_size);
	puts("");
	return 0;
}
