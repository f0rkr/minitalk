#include "minitalk.h"

void	valcino(int signal)
{
	static unsigned char	c;
	static char		i = 0;

	c += (SIGUSR1 == signal) << i++;
	if (i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
	return ;
}

int	main(void)
{
	signal(SIGUSR1, valcino);
	signal(SIGUSR2, valcino);
	ft_putstr_fd(1, "Server running with pid: ");
	printf("%d \n", (int) getpid());
	while (1)
		pause();
	return (0);
}
