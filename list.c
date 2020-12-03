void list_node_init(node *n, item *i) {
	n->data = i;
	n->value = i->value;
	return;
}

void list_list_init(list *l) {
	l->value = 0;
	return;
}

void list_list_add(list *l, node *n) {
	if (l->first == NULL) {
		l->first = n;
		l->last = n;
		l->value = n->value;
		return;
	}
	l->value += n->value;
	l->last->next = n;
	l->last = n;
	return;
}

void list_list_print(list *l) {
	node *n = l->first;
	while (n != NULL) {
		printf("(%d,%d) ", n->data->wight, n->data->value);
		n = n-> next;
	}
	return;
}

void list_super_list_init(super_list *sl) {
	sl->value = 0;	
	return;
}

void list_super_list_print(super_list *sl) {
	if (sl->value <= 0) {
		return;
	}
	if (sl->data != NULL) {
		list_list_print(sl->data);
		return;
	}
	list_super_list_print(sl->first);
	list_super_list_print(sl->second);
	return;
}

void list_super_list_set(super_list *d, super_list *f, super_list *s) {
	d->first = f;
	d->second = s;
	d->value = f->value + s->value;
	return;
}

void list_super_list_set_data(super_list *d, list *data) {
	d->data = data;
	d->value = data->value;
	return;
}
