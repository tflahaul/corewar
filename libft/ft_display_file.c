#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE		512

int		    			ft_display_file(char const *file)
{
	int					fd;
	int					bytes;
	char				buffer[BUFF_SIZE + 1];

	if ((fd = open(file, O_RDONLY)) < 0)
        return (EXIT_FAILURE);
	while ((bytes = read(fd, buffer, BUFF_SIZE)) > 0)
		write(STDERR_FILENO, buffer, bytes);
	if (close(fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
