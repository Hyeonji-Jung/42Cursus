#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MAX_ARR 2147483648
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

/*util_preprocess.c*/
int		ft_atoi(char *from, char *to);
void	ft_bzero(void *dest, size_t size);
// void	*ft_memset(void *dest, int c, size_t size);

/*util_std.c*/
void	ft_error(void);
void	ft_putstr(char *s, int fd);

/*util_stack.c*/
t_node	*getNewNode(int num);
void	initStack(t_var *var);
void	pushTop(t_stack *stack, t_node *new_node);
void	pushBottom(t_stack *stack, t_node *new_node);
t_node	*popTop(t_stack *stack);
t_node	*popBottom(t_stack *stack);
void	printStack_test(t_stack *stack); ///////////Please erase

/*preprocess.c*/
void	preprocess(t_var *var, int argc, char **argv);
int		parseArg(t_var *var, char *str, char *pos, char *neg);
void	checkArg(char *pos, char *neg, int n);
void	sortArr(t_var *var, char *pos, char *neg, int cnt);

/*stack_operate.c*/
char	*sa(t_var *var);
char	*sb(t_var *var);
char	*ss(t_var *var);
char	*pa(t_var *var);
char	*pb(t_var *var);
char	*ra(t_var *var);
char	*rb(t_var *var);
char	*rr(t_var *var);

#endif
