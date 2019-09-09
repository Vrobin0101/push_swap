# include "libft.h"
# include <stdio.h>

int		main(void)
{
	int fd;
	char *line;

	fd = 0;
	while (get_next_line(0, &line) > 0)
		printf("%s\n", line);
}
