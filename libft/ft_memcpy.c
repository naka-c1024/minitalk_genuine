/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:46:11 by ynakashi          #+#    #+#             */
/*   Updated: 2021/08/27 09:15:20 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	const char	*p2;

	if (dst == src)
		return (dst);
	p1 = (char *)dst;
	p2 = (const char *)src;
	while (n-- > 0)
		*p1++ = *p2++;
	return (dst);
}
/*
//not NULL guard
#include <stdio.h>
#include <string.h>
int	main(void)
{
	// ft_memcpy(NULL, "segfaulter tu dois", 17);
	// memcpy(NULL, "segfaulter tu dois", 17);

	char str1[] = "xxxxxxx";
	int i;

	printf("before:");
	i = 0;
	while (i < 7)
	{
		printf("%d ",str1[i]);
		i++;
	}
	printf("\n");

	ft_memcpy(str1, "aa\0aaa", 6);

	printf("after:");
	i = 0;
	while (i < 7)
	{
		printf("%d ",str1[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
