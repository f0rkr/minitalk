#include "minitalk.h"

int	sendData(int pid, char *data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if ((data[i] >> j) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					return (-1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				return (-1);
			j++;
			usleep(150);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !is_digit(argv[1]))
	{
		ft_putstr_fd(2, "usage: ./client [pid server] [message]\n");
		return (-1);
	}
	if (sendData(atoi(argv[1]), argv[2]) == -1)
	{
		ft_putstr_fd(2, "error: pid is incorrect\n");
		return (-1);
	}
	return (0);
}
