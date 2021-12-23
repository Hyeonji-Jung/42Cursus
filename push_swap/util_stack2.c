#include "push_swap.h"

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*bottom;
	t_node	*temp;

	bottom = stack->bottom;
	if (bottom->left == stack->top)
		return (0);
	temp = bottom->left;
	temp->left->right = bottom;
	bottom->left = temp->left;
	temp->left = NULL;
	temp->right = NULL;
	return (temp);
}

int	get_stack_size(t_stack *stack)
{
	int		size;
	t_node	*p;

	size = 0;
	p = stack->top->right;
	while (p != stack->bottom)
	{
		size++;
		p = p->right;
	}
	return (size);
}

int	get_any_stack_size_a(int pre_size)
{
	int	any_size;

	any_size = pre_size / 2;
	return (any_size);
}

int	get_any_stack_size_b(int pre_size)
{
	int	any_size;

	any_size = pre_size / 2;
	if (pre_size % 2 == 1)
		any_size += 1;
	return (any_size);
}

void	printStack_test(t_stack *stack) // ERASE
{
	t_node	*p;

	printf("TOP:   ");
	p = stack->top->right;
	while (p != stack->bottom)
	{
		printf("%d ", p->val);
		p = p->right;
	}
	printf("  :BOTTOM\n");
}
