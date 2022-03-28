#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	printf("passthis");
	int	fd = open("multiple_line_with_nl", O_RDONLY);
	if (!fd)
	{
		printf("error");
		return (0);
	}
	char	*str;
	// int		i = 1;
	printf("passthis");
	str = get_next_line(fd);
	/*while ((str = get_next_line(fd)) != 0)
	{
		printf("%d\t%ld\n", i, ft_strlen(str));
		printf("%s", str);
		printf("\n");
	}*/
	free(str);
	close(fd);
	return (0);
}