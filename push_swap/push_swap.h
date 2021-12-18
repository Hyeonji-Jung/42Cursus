#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> // Edsfdf
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define S_A 4
# define S_B 2

typedef struct s_node
{
	int				val;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_var
{
	int				max_size;
	int				*pivot_arr;
	struct s_stack	*A;
	struct s_stack	*B;
	int				a_size;
	int				b_size;
}	t_var;

/*re_a.c , re_b.c*/
void	reA(t_var *var, int preSize, int prePivotIdx);
void	reB(t_var *var, int preSize, int prePivotIdx);

/*util_preprocess.c*/
int		ft_atoi(char *from, char *to);
void	quick_sort(int *data, int start, int end);
void	checkDup(int *a, int cnt);

/*util_std.c*/
void	ft_putstr(char *s, int fd);
void	ft_error(void);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *p, size_t n);

/*util_stack1.c*/
t_node	*getNewNode(int num);
void	initStack(t_var *var);
void	pushTop(t_stack *stack, t_node *new_node);
void	pushBottom(t_stack *stack, t_node *new_node);
t_node	*popTop(t_stack *stack);

/*util_stack2.c*/
t_node	*popBottom(t_stack *stack);
int		getStackSize(t_stack *stack);
int		getAnyStackSize_A(int preSize);
int		getAnyStackSize_B(int preSize);
void	printStack_test(t_stack *stack); // ERASE

/*preprocess.c*/
void	preprocess(t_var *var, int argc, char **argv);
int		parseArg(t_var *var, char *str, int len);
void	putArr(t_var *var);

/*stack_operate1.c*/
char	*sa(t_var *var);
char	*sb(t_var *var);
char	*ss(t_var *var);
char	*pa(t_var *var);
char	*pb(t_var *var);

/*stack_operate2.c*/
char	*ra(t_var *var);
char	*rb(t_var *var);
char	*rr(t_var *var);
char	*rra(t_var *var);
char	*rrb(t_var *var);

/*stack_operate3.c*/
char	*rrr(t_var *var);
#endif
