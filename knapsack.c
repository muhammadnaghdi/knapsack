void kanpsack_item_init(item *i, int wight, int value) {
	i->wight = wight;
	i->value = value;
	return;
}
	
void knapsack_solve(int total, item *items, int size) {
	item **max = (item **) malloc(sizeof(item *) * (total + 1));	
	super_list **w = (super_list **) malloc(sizeof(super_list *) * (total + 1));

	for (int i = 0; i < size; ++i) {
		if (items[i].wight <= total) {
			if (max[items[i].wight] == NULL) {
				max[items[i].wight] = &items[i];
			} else if (max[items[i].wight]->value < items[i].value) {
				max[items[i].wight] = &items[i]; 
			}
		}
	}

	for (int i = 1; i <= total; ++i) {
		int best;
		if (max[i] != NULL) {
			best = max[i]->value;
		} else {
			best = 0;
		}
		
		int flag = 0;
		for (int k = 1; k < i >> 1; ++k) {
			int current = w[k]->value + w[i - k]->value;
			if (current > best) {
				if (w[i] == NULL) {
					w[i] = (super_list *) malloc(sizeof(super_list));
					list_super_list_init(w[i]);
				}
				list_super_list_set(w[i], w[k], w[i-k]);
				flag = 1;
			}
		}
		
		if (!flag) {
			if (w[i] == NULL) {
				w[i] = (super_list *) malloc(sizeof(super_list));
				list_super_list_init(w[i]);
			}
			
			if (max[i] != NULL) {
				list *l	= (list *) malloc(sizeof(list));
				list_list_init(l);

				node *n = (node *) malloc(sizeof(node));
				list_node_init(n, max[i]);
				
				list_list_add(l, n);

				list_super_list_set_data(w[i], l);
			}
		}
	}
	
	list_super_list_print(w[total]);
}
