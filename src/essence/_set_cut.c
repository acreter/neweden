#include <stddef.h>
#include <neweden/essence/set.h>
#include <neweden/essence/dynamic_array.h>

void* 
_set_cut(
		char* first,
		char* second,
		size_t element_size,
		size_t first_count,
		size_t second_count,
		int (*compare)(void*, void*)
) {
	first_count = first_count ? first_count : dynarr_len(first);
	second_count = second_count ? second_count : dynarr_len(second);
	char* array = NULL;

	for (unsigned int i = 0; i < first_count; i++)
	{
		for (unsigned int j = 0; j < second_count; j++)
		{
			void* current_in_first = (void*) (first + (i * element_size));
			void* current_in_second = (void*) (second + (j * element_size));

			if (compare(current_in_first, current_in_second))
			{ _dynarr_append_n(&array, current_in_first, 1, element_size); }
		}
	}
	return (void*) array;
}
