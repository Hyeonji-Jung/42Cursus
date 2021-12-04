#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define S_A 4
# define S_B 2

typedef struct s_node
{
	int		val;
	t_node	*left;
	t_node	*right;
}	t_node;

typedef struct s_stack
{
	t_node	*header;
	t_node	*footer;
}	t_stack;

typedef struct s_var
{
	int		max_size;
	char	*arr;
	t_stack	*A;
	t_stack	*B;
	int		a_size;
	int		b_size;
}	t_var;

#endif
