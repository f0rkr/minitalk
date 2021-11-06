#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>

# define SIGUSR1 30
# define SIGUSR2 31

void	ft_putstr_fd(int fd, char *string);
int	is_digit(char *string);
#endif
