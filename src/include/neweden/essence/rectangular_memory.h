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
rectmem_self(
		char* block);

struct dimensions
rectmem_dimensions(
		char* block);

char*
rectmem_allocate(
		size_t x,
		size_t y);

int
rectmem_free(
		char** block);

size_t
rectmem_xindex_of(
		char* block,
		char* ptr);

size_t
rectmem_yindex_of(
		char* block,
		char* ptr);

char*
rectmem_ptr_from_coordinates(
		char* block,
		size_t x,
		size_t y);

char*
rectmem_xstep(
		char* block,
		char* current,
		unsigned int by);

char*
rectmem_ystep(
		char* block,
		char* current,
		unsigned int by);

void
rectmem_copy(
		char* ref_from,
		char* ref_to,
		char* from_start,
		char* from_end,
		char* to);

void
rectmem_copy_range(
		char* ref_from,
		char* ref_to,
		char* from,
		char* to,
		size_t nX,
		size_t nY);

void
rectmem_move(
		char* ref,
		char* from_start,
		char* from_end,
		char* to);

void
rectmem_move_range(
		char* ref,
		char* from,
		char* to,
		size_t nX,
		size_t nY);

#endif
