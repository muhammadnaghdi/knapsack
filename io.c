void io_get(item *items, int argc, char *argv[]) {
	for (int i = 0; i < argc - 2; i = i + 2) {
		int index = i >> 1;
		items[index].wight = atoi(argv[i + 2]);
		items[index].value = atoi(argv[i + 3]);
	}
	return;
}


void io_array_put(item *items, int size) {
	for (int i = 0; i < size; ++i) {
		printf("(%d,%d) ", items[i].wight, items[i].value);
	}
}
