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

#ifndef __SET_H_INCLUDED
#define __SET_H_INCLUDED 1

#define set_cut(first, second, first_count, second_count, compare) \
	_set_cut( \
			(char*) (first), \
			(char*) (second), \
			sizeof *(first), \
			(first_count), \
			(second_count), \
			(compare))

void* 
_set_cut(
		char* first,
		char* second,
		size_t element_size,
		size_t first_count,
		size_t second_count,
		int (*compare)(void*, void*)
);

#endif
