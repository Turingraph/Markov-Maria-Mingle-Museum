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

// string.c

void	*malloc_talk(size_t elem_size, const char *comment);
size_t	f_strlen(const char *str);
size_t	index_of_a(const char *str, char stop);

#endif
