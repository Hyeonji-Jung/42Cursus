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

typedef struct s_list_node
{
	char				*val;
	struct s_list_node	*left;
	struct s_list_node	*right;
}	t_list_node;

typedef struct s_list
{
	struct s_list_node	*top;
}	t_list;

typedef struct s_var
{
	int				max_size;
	int				*pivot_arr;
	struct s_stack	*A;
	struct s_stack	*B;
	struct s_list	*list;
	int				a_size;
	int				b_size;
}	t_var;

/*re_a.c , re_b.c*/
void		re_a(t_var *var, int pre_size, int pre_pivot_idx);
void		re_b(t_var *var, int pre_size, int pre_pivot_idx);

/*util_preprocess.c*/
int			ft_atoi(char *from, char *to);
void		quick_sort(int *data, int start, int end);
void		check_dup(int *a, int cnt);

/*util_std1.c*/
void		ft_putstr(char *s, int fd);
void		ft_error(void);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *p, size_t n);
t_node		*max_node(t_node *t1, t_node *t2, t_node *t3);

/*util_std2.c*/
int			cmp(char *s1, char *s2);

/*util_sort.c*/
int			is_sorted(t_node *temp, int len, int now_stack);

/*sort_3.c*/
void		sort_only_three_a(t_var *var);
void		sort_only_three_b(t_var *var);
void		sort_three_a(t_var *var);
void		sort_three_b(t_var *var);

/*sort_4.c*/


/*util_list1.c*/
t_list_node	*get_new_list_node(char *str);
void		init_list(t_var *var);
void		save_list(t_var *var, char *str);
void		print_list(t_var *var);

/*util_list2.c*/
void		optimize_list(t_list *list);

/*util_stack1.c*/
t_node		*get_new_node(int num);
void		init_stack(t_var *var);
void		push_top(t_stack *stack, t_node *new_node);
void		push_bottom(t_stack *stack, t_node *new_node);
t_node		*pop_top(t_stack *stack);

/*util_stack2.c*/
t_node		*pop_bottom(t_stack *stack);
int			get_stack_size(t_stack *stack);
int			get_any_stack_size_a(int pre_size);
int			get_any_stack_size_b(int pre_size);
void		printStack_test(t_stack *stack); // ERASE

/*preprocess.c*/
void		preprocess(t_var *var, int argc, char **argv);
int			parse_arg(t_var *var, char *str, int len);
void		put_arr(t_var *var);

/*stack_operate1.c*/
char		*sa(t_var *var);
char		*sb(t_var *var);
char		*ss(t_var *var);
char		*pa(t_var *var);
char		*pb(t_var *var);

/*stack_operate2.c*/
char		*ra(t_var *var);
char		*rb(t_var *var);
char		*rr(t_var *var);
char		*rra(t_var *var);
char		*rrb(t_var *var);

/*stack_operate3.c*/
char		*rrr(t_var *var);
#endif
