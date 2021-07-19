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

#include <neweden/essence/rectangular_memory.h>

#include <string.h>

void
rectmem_move_range(
		char* ref_from,
		char* ref_to,
		char* from,
		char* to,
		size_t nX,
		size_t nY
) {
	char* buffer = allocate(nX * nY);

	for (unsigned int i = 0; i < nY; i += 1)
	{ memcpy(buffer + i * nX, rectmem_ystep(ref_from, from, i), nX); }

	for (unsigned int i = 0; i < nY; i += 1)
	{ memcpy(rectmem_ystep(ref_to, to, i), buffer + i * nX, nX); }

	return;
}
