#include "minishell.h"

void	*builtins(char *cmd)
{
	if(ex_re(cmd) == 0)
		is_exits(cmd);
	return 0;
}
