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

#include <stddef.h>

#define dynarr_len(block) _dynarr_len((char *) (block))
#define dynarr_free(block) _dynarr_free((char **) (block))

#define dynarr_insert_n(block, index, elements, n) \
	_dynarr_insert_n( \
			(char **) (block), \
			(index), \
			(void *) (elements), \
			(n), \
			sizeof **(block))

#define dynarr_append_n(block, elements, n) \
	_dynarr_append_n( \
			(char **) (block), \
			(void *) (elements), \
			(n), \
			sizeof **(block))

#define dynarr_prepend_n(block, elements, n) \
	_dynarr_insert_n( \
			(char **) (block), \
			0, \
			(void *) (elements), \
			(n), \
			sizeof **(block))

#define dynarr_remove_n(block, index, n) \
	_dynarr_remove_n( \
			(char **) (block), \
			(index), \
			(n), \
			sizeof **(block))

#define dynarr_remove_first_n(block, n) \
	_dynarr_remove_n( \
			(char **) (block), \
			0, \
			(n), \
			sizeof **(block))

#define dynarr_remove_last_n(block, n) \
	_dynarr_remove_last_n( \
			(char **) (block), \
			(n), \
			sizeof **(block))

typedef struct
{
	size_t len, limit;
	char block[];
} dynarr;

dynarr*
_dynarr_self(
		char* block
);

size_t
_dynarr_len(
		char* block
);

int
_dynarr_free(
		char** block
);

int
_dynarr_insert_n (
		char** block,
		size_t index,
		void* elements,
		size_t n,
		size_t element_size
);

int
_dynarr_append_n (
		char** block,
		void* elements,
		size_t n,
		size_t element_size
);

int
_dynarr_remove_n (
		char** block,
		size_t index,
		size_t n,
		size_t element_size
);

int
_dynarr_remove_last_n (
		char** block,
		size_t n,
		size_t element_size
);

int
_dynarr_resize_to_n (
		char** block,
		size_t n,
		size_t element_size
);

int
_dynarr_prepare_for_n (
		char** block,
		size_t n,
		size_t element_size
);

int
_dynarr_prepare_for_n_more (
		char** block,
		size_t n,
		size_t element_size
);

#endif
