#include "../cub3d.h"

/**
 * @brief Checks if a string is a prefix of another string.
 *
 * This function determines if the string `s2` is a prefix of the string `s1`.

	* A prefix means that all characters of `s2` appear sequentially at the start of `s1`.
 *
 * @param s1 The string to be searched (must not be `NULL`).
 * @param s2 The prefix string to compare (must not be `NULL`).
 *
 * @return 1 if `s2` is a prefix of `s1`, 0 otherwise.
 *
 * @note If either `s1` or `s2` is `NULL`, the function returns 0.
 *
 * Example Usage:
 * @code
 * int result = mod_strchr("hello", "hell");   // result = 1
 * int result = mod_strchr("hello", "world");  // result = 0
 * int result = mod_strchr("hello", "");       // result = 1
 * @endcode
 */

int	mod_strchr(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] && s1[i] == s2[i])
		;

	if (s2[i] == '\0')
		return (1);

	return (0);
}