/* Copyright (C) 2021 Peter Markfelder
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public
 * License version 3 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include <neweden/essence/dynamic_array.h>

#include <stdlib.h>
#include <string.h>

struct dyn_arr {
	ne_size_t number_of_elements, limit;
	ne_size_t size_of_element;
	ne_size_t (*new_limit_func) (ne_size_t);
	char array[];
};

dyn_arr_t*
dyn_arr_create(
	ne_size_t l,
	ne_size_t soe,
	ne_size_t (*nl_func) (ne_size_t)
) {
	if (l == 0 || soe == 0) return NULL;

	dyn_arr_t* arr;
	arr = malloc(sizeof (*arr) + l * soe);

	if(arr) {
		arr->limit = l;
		arr->number_of_elements = 0;
		arr->size_of_element = soe;
		return arr;
	} else {
		return NULL;
	}
}

void
dyn_arr_destroy(
	dyn_arr_t* arr
) {
	free(arr);
	return;
}

ne_size_t
dyn_arr_get_number_of_elements(
	dyn_arr_t* arr
) {
	return arr->number_of_elements;
}

void*
dyn_arr_get_at(
	dyn_arr_t* arr,
	ne_size_t i
) {
	return arr->array + arr->size_of_element * i;
}

void*
dyn_arr_get_first(
	dyn_arr_t* arr
) {
	return arr->array;
}

void*
dyn_arr_get_last(
	dyn_arr_t* arr
) {
	return arr->array + arr->size_of_element * (arr->number_of_elements - 1);
}

void
dyn_arr_copy_element(
	dyn_arr_t* arr,
	void* d,
	void* s
) {
	memcpy(d, s, arr->size_of_element);
	return;
}

void
dyn_arr_clear(
	dyn_arr_t* arr
) {
	arr->number_of_elements = 0;
}

dyn_arr_t*
dyn_arr_insert(
	dyn_arr_t* arr,
	ne_size_t i,
	void* e,
	ne_size_t n_elements
) {
	ne_size_t new_limit;

	while (arr->number_of_elements + n_elements >= arr->limit) {
		new_limit = arr->new_limit_func(arr->limit);
		dyn_arr_t* new = realloc(arr, sizeof (*arr) + new_limit * arr->size_of_element);

		if (!new) return arr;
		new->limit = new_limit;
		arr = new;
	}

	memmove(dyn_arr_get_at(arr, i + n_elements),
			dyn_arr_get_at(arr, i),
			arr->size_of_element * (arr->number_of_elements - i));

	memcpy(dyn_arr_get_at(arr, i),
			e,
			arr->size_of_element * n_elements);

	arr->number_of_elements += n_elements;
	return arr;
}

dyn_arr_t*
dyn_arr_append(
	dyn_arr_t* arr,
	void* e,
	ne_size_t n_elements
) {
	return dyn_arr_insert(arr, arr->number_of_elements, e, n_elements);
}

dyn_arr_t*
dyn_arr_prepend(
	dyn_arr_t* arr,
	void* e,
	ne_size_t n_elements
) {
	return dyn_arr_insert(arr, 0, e, n_elements);
}

void
dyn_arr_remove(
	dyn_arr_t* arr,
	ne_size_t i,
	ne_size_t n_elements
) {
	memmove(dyn_arr_get_at(arr, i),
			dyn_arr_get_at(arr, i + n_elements),
			arr->size_of_element * (arr->number_of_elements - i - n_elements));
	arr->number_of_elements -= n_elements;
	return;
}

void
dyn_arr_remove_last(
	dyn_arr_t* arr,
	ne_size_t n_elements
) {
	dyn_arr_remove(arr, arr->number_of_elements - n_elements, n_elements);
	return;
}

void
dyn_arr_remove_first(
	dyn_arr_t* arr,
	ne_size_t n_elements
) {
	dyn_arr_remove(arr, 0, n_elements);
	return;
}

ne_size_t
dyn_arr_size(
	dyn_arr_t* arr
) {
	return sizeof (*arr) + arr->limit * arr->size_of_element;
}

dyn_arr_t*
dyn_arr_copy(
	dyn_arr_t* arr,
	ne_size_t (*new_limit_func) (ne_size_t)
) {
	dyn_arr_t* new = malloc(dyn_arr_size(arr));
	if(!new) return NULL;
	else {
		if (new_limit_func)
			new->new_limit_func = new_limit_func;
		memcpy(new, arr, dyn_arr_size(arr));
		return new;
	}
}

ne_size_t
dyn_arr_times_two(
	ne_size_t size
) {
	return size * 2;
}
