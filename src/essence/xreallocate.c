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

#include <neweden/essence/allocate.h>

#include <errno.h>
#include <string.h>

int
xreallocate(
	void** array,
	size_t old_size,
	size_t new_size)
{
	if (!old_size || !new_size || !array || !*array)
	{ return (errno = EINVAL, 0); }

	void* new = realloc(*array, new_size);
	if (new_size > old_size)
	{ memset((char*) new + old_size, 0, new_size - old_size); }
	
	if (!new)
	{ return 0; }
	
	*array = new;
	return 1;
}