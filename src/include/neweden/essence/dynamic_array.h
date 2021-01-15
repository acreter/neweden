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
 * along with this program. If not, see <https://www.gnu.org/licenses/>. */

#ifndef __DYNAMIC_ARRAY_H_INCLUDED
#define __DYNAMIC_ARRAY_H_INCLUDED 1

#include <neweden/essence/types.h>

typedef struct dyn_arr dyn_arr_t;

dyn_arr_t*
dyn_arr_create(
	ne_size_t limit,
	ne_size_t size_of_element,
	ne_size_t (*new_limit_func) (ne_size_t)
);

void
dyn_arr_destroy(
	dyn_arr_t* array
);

ne_size_t
dyn_arr_get_number_of_elements(
	dyn_arr_t* array
);

ne_size_t
dyn_arr_index_of(
	dyn_arr_t* array,
	void* element
);

void*
dyn_arr_get_at(
	dyn_arr_t* array,
	ne_size_t index
);

void*
dyn_arr_get_first(
	dyn_arr_t* array
);

void*
dyn_arr_get_last(
	dyn_arr_t* array
);

void
dyn_arr_copy_element(
	dyn_arr_t* array,
	void* dest,
	void* src
);

void
dyn_arr_clear(
	dyn_arr_t* array 
);

dyn_arr_t*
dyn_arr_insert(
	dyn_arr_t* array,
	ne_size_t index,
	void* elements,
	ne_size_t number_of_elements
);

dyn_arr_t*
dyn_arr_append(
	dyn_arr_t* array,
	void* elements,
	ne_size_t number_of_elements
);

dyn_arr_t*
dyn_arr_prepend(
	dyn_arr_t* array,
	void* elements,
	ne_size_t number_of_elements
);

void
dyn_arr_remove(
	dyn_arr_t* array,
	ne_size_t index,
	ne_size_t number_of_elements
);

void
dyn_arr_remove_last(
	dyn_arr_t* array,
	ne_size_t number_of_elements
);

void
dyn_arr_remove_first(
	dyn_arr_t* array,
	ne_size_t number_of_elements
);

ne_size_t
dyn_arr_size(
	dyn_arr_t* array
);

dyn_arr_t*
dyn_arr_copy(
	dyn_arr_t* array,
	ne_size_t (*new_limit_func) (ne_size_t)
);

ne_size_t
dyn_arr_times_two(
	ne_size_t size
);

#endif
