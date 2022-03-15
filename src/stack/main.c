#include "stack.h"
#include "libft.h"

int	check_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j])
		{
			ft_isdigit(str[i][j])
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int args, char **argv)
{
	t_stack *s;


	return (0);
}