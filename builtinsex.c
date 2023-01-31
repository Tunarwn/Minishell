#include "minishell.h"

int ft_atoi(char *nbr)
{
	int i = 0;
	int res = 0;
	int c = 0;
	while(nbr[i])
	{
		if(nbr[i] >= '0' && nbr[i] <= '9')
		{
			res *= 10;
			res += nbr[i] - '0';
		}
		i++;
	}
	return res;
}

int ex_re(char *exst)
{
	int i = 0;
	while(exst[i] <= 32)
		i++;
	if (exst[i] == 'e' && exst[i + 1] == 'x' && exst[i + 2] == 'i' && exst[i + 3] == 't')
		return 0;
	return 1;
}

void	is_exits(char *ex)
{
	int i = 0;

	while(ex[i])
	{
		if (ex[i - 1] == 't')
			break;
		i++;
	}
	int check = 0;
	while(ex[i])
	{
		if(ex[i] >= 'a' && ex[i] <= 'z')
			printf("Minishell: %s: numeric argument required\n", ex);
		if (ex[i] != ' ' && (ex[i] > '9' || ex[i] < '0'))
		{
			check = 255;
			break;
		}
		if (ex[i] >= '0' && ex[i] <= '9')
			check = ft_atoi(ex);
		i++;
	}
	exit(check);
}
