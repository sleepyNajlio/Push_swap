#ifndef		PUSH_SWAP_H
# define	PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				markup;
	struct s_list	*next;
}	t_list;

typedef	struct s_array
{
	int *arr;
	int size;
}	t_array;

int		ft_atoi(const char *str);
void	check_error(int ac, char **av);
void	create_arr(int ac, char **av, t_array **arr);
void	ft_lstadd_back(t_list **lst, t_list *new, int index);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*indexation(t_array *arr, char **av);

#endif