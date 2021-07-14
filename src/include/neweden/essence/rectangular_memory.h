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

#ifndef __RECTANGULAR_MEMORY_H_INCLUDED
#define __RECTANGULAR_MEMORY_H_INCLUDED 1

#include <stddef.h>

struct dimensions {
	size_t x, y;
};

struct rectmem {
	struct dimensions dim;
	char block[];
};

struct rectmem*
_rectmem_self(
		char* block);

struct dimensions*
_rectmem_dimensions(
		char* block);

#define rectmem_dimensions(block) \
	_rectmem_dimensions( \
			(char*) (block))

int
_rectmem_allocate(
		char** block,
		size_t x,
		size_t y,
		size_t element_size);

int
_rectmem_free(
		char** block);

#define rectmem_allocate(block, x, y) \
	_rectmem_allocate( \
			(char **) (block), \
			(x), \
			(y), \
			sizeof **(block))

#define rectmem_free(block) \
	_rectmem_free( \
			(char **) (block))

size_t
_rectmem_xindex_of(
		char** block,
		char* ptr,
		size_t element_size);

size_t
_rectmem_yindex_of(
		char** block,
		char* ptr,
		size_t element_size);

#define rectmem_xindex_of(block, ptr) \
	_rectmem_xindex_of( \
			(char**) (block), \
			(char*) (ptr), \
			sizeof **(block))

#define rectmem_yindex_of(block, ptr) \
	_rectmem_yindex_of( \
			(char**) (block), \
			(char*) (ptr), \
			sizeof **(block))

char*
_rectmem_xstep(
		char** block,
		char* current,
		unsigned int by,
		size_t element_size);

char*
_rectmem_ystep(
		char** block,
		char* current,
		unsigned int by,
		size_t element_size);

#define rectmem_xstep(block, current, by) \
	_rectmem_xstep( \
			(char**) (block), \
			(char*) current, \
			(by), \
			sizeof **(block))

#define rectmem_ystep(block, current, by) \
	_rectmem_ystep( \
			(char**) (block), \
			(char*) current, \
			(by), \
			sizeof **(block))

int
_rectmem_copy(
		char** ref_from,
		char** ref_to,
		char* from_start,
		char* from_end,
		char* to,
		size_t element_size);

int
_rectmem_copy_range(
		char** ref_from,
		char** ref_to,
		char* from,
		char* to,
		size_t nX,
		size_t nY,
		size_t element_size);

int
_rectmem_move(
		char** block,
		char* from_start,
		char* from_end,
		char* to,
		size_t element_size);

int
_rectmem_move_range(
		char** block,
		char* from,
		char* to,
		size_t nX,
		size_t nY,
		size_t element_size);

#define rectmem_copy(from, to, x1, y1, x2, y2, nX, nY) \
	_rectmem_copy( \
			(char**) (from), \
			(char**) (to), \
			(x1), \
			(y1), \
			(x2), \
			(y2), \
			(nX), \
			(nY), \
			sizeof **(from))

#define rectmem_move(block, x1, y1, x2, y2, nX, nY) \
	_rectmem_move( \
			(char**) (block), \
			(x1), \
			(y1), \
			(x2), \
			(y2), \
			(nX), \
			(nY), \
			sizeof **(block))

#endif
