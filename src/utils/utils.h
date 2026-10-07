#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <time.h>

// atoi.c

int		f_atoi(const char *src,
			bool *is_int, const char *base, size_t digits);
size_t	ft_putnbr_fd(int n, int fd, const char *base, size_t digits);

// debug.c

void	write_total_score(size_t score, size_t max_score);
int		compare_intarr(const int *str_1, const int *str_2, size_t n);
void	warning_file_not_exists(const char *src);

// string.c

void	*malloc_talk(size_t elem_size, const char *comment);
size_t	f_strlen(const char *str);
size_t	index_of_a(const char *str, char stop);
size_t	index_of_id(const size_t *arr, size_t length, size_t id);

#endif
