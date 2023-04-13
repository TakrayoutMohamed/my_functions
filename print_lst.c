void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%d** -> ",lst->content);
		lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}
