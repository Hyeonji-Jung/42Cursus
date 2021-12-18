#include "push_swap.h"

t_node	*popBottom(t_stack *stack)
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

int	getStackSize(t_stack *stack)
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

int	getAnyStackSize_A(t_var *var, int depth, int preSize)
{
	int	anySize;

	anySize = preSize / 2;
	return (anySize);
}

int	getAnyStackSize_B(t_var *var, int depth, int preSize)
{
	int	anySize;

	anySize = preSize / 2;
	if (preSize % 2 == 1)
		anySize += 1;
	return (anySize);
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
