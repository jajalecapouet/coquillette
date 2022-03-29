/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_dollars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:26:54 by njaros            #+#    #+#             */
/*   Updated: 2022/03/29 16:35:40 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "coquillette.h"

char	*quotage(char *str, int *dquote, int *quote)
{
	char	*add;
	char	*join;
	int		i;

	i = -1;
	add = readline(">");
	while (add[++i])
	{
		if (add[i] == 34 && !*quote)
			*dquote = ft_switch(*dquote);
		if (add[i] == 39 && !*dquote)
			*quote = ft_switch(*quote);
	}
	join = ft_strjoin("\n", add);
	free(add);
	add = ft_strjoin(str, join);
	free(str);
	free(join);
	return (add);
}

char	*check_quote_end(char *str)
{
	int		i;
	int		quote;
	int		dquote;
	char	*next;

	quote = 0;
	dquote = 0;
	str = cherche_merde(str, &quote, &dquote);
	i = -1;
	while (str && (dquote || quote))
		str = quotage(str, &dquote, &quote);
	if (str)
		str = pipage(str);
	return (str);
}

char	*replace_dollz(char *str, int *i, int end)
{
	char	*replaced;
	char	*sub1; 
	char	*sub2;
	char	*no_dollz;

	if (*i == 0)
		sub1 = ft_strdup("");
	else
		sub1 = ft_substr(str, 0, *i);
	sub2 = ft_substr(str, *i + 1, end - (*i + 1));
	no_dollz = ft_strjoin(sub1, getenv(sub2));
	free(sub1);
	sub1 = ft_substr(str, end, ft_strlen(str));
	*i += ft_strlen(getenv(sub2)) - 1;
	free(sub2);
	replaced = ft_strjoin(no_dollz, sub1);
	free(no_dollz);
	free(sub1);
	free(str);
	return (replaced);
}

char	*pid_dollz(char *str, int *i)
{
	char	*number;
	char	*sub;
	char	*tmp;

	if (str[*i + 1] == '$')
		number = ft_itoa(getpid());
	else
		return (str);
	sub = ft_substr(str, 0, *i);
	tmp = ft_strjoin(sub, number);
	free(sub);
	sub = ft_substr(str, *i + 2, ft_strlen(str));
	*i += ft_strlen(number) - 1;
	free(number);
	number = ft_strjoin(tmp, sub);
	free(str);
	free(tmp);
	free(sub);
	return (number);
}

char	*dollar_searcher(char *str)
{
	int		i;
	int		end;
	int		quote;

	quote = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == 39 || str[i] == 34)
			quote = ft_quote_switch(quote, str[i]);
		if (str[i] == '$' && !quote && str[i + 1] && str[i + 1] != ' ')
		{
			if (str[i + 1] == '?' || str[i + 1] == '$')
				str = pid_dollz(str, &i);
			else
			{
				end = i + 1;
				while (str[end] && !ft_metachar(str[end]))
					end++;
				str = replace_dollz(str, &i, end);
			}
		}
	}
	return (str);
}
