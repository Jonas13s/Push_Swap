#include "stack.h"
#include "libft.h"

int	check_number(char **str, int args)
{
	int	i;
	int	temp;

	if (args <= 1)
		return (1);
	i = 1;
	temp = -1;
	while(str[i])
	{
		temp = num_count(ft_atoi(str[i]));
		if (temp == 1)
			if (!ft_isdigit(str[i][0]))
				return (1);
		if (ft_strlen(str[i]) != temp)
			return (1);
		i++;
	}
	return (0);
}

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

void	fill_stack(int args, char **argv, t_stack *stack)
{
	int	i;

	i = 1;
	args = args - 2;
	stack->top = args;
	while(args != -1)
	{
		stack->array[args] = ft_atoi(argv[i]);
		args--;
		i++;
	}
}

int	main(int args, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = initialize(args - 1);
	b = initialize(args - 1);
	ft_bzero(b->array, b->size);
	if (check_number(argv, args))
		return (error());
	fill_stack(args, argv, a);
	reverse_rotate(a);
	push_stack(a, b);
	swap(a);
	reverse_rotate(a);
	push_stack(b, a);
	int i = 0;
	while(i <= a->top)
	{
		ft_printf("%d %d\n", a->array[a->top - i], b->array[b->top - i]);
		i++;
	}
	return (0);
}