/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspies <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 08:33:53 by tspies            #+#    #+#             */
/*   Updated: 2018/08/29 08:33:54 by tspies           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

int		main(void)
{
	int					ptr;
	int					num;
	unsigned long		test_l = 42;
	unsigned long long	test_ll = 42;
	short				test_h = 42;
	unsigned char		test_hh = 42;
	size_t				test_z = 42;
	intmax_t			test_j = 42;
	wint_t				test_l_on_c = L'µ';
	wchar_t				A = L'µ';
	wchar_t				*S = L"œ∑´´®†¥¨ˆøπ";

	num = 42;

	printf("---------------------------------------------------------------\n\n");
	printf("This Will Test Your Printf Against Original Printf.\n\n");
	printf("Original Printf will have '[ ]' around result.\n\n");
	printf("Your Printf will have '( )' around result.\n\n");
	printf("---------------------------------------------------------------\n");

	ft_printf("\n------>SIMPLE TESTS<------\n\n");
	printf(" Testing c: [%c]\n Testing s: [%s]\n Testing p: [%p]\n Testing d: [%d]\n Testing dbl ['%%']\n\n", 'X', "This is a simple string", &ptr, num);
	ft_printf(" Testing c: (%c)\n Testing s: (%s)\n Testing p: (%p)\n Testing d: (%d)\n Testing dbl ('%%')\n\n", 'X', "This is a simple string", &ptr, num);

	ft_printf("\n------>LESS SIMPLE TESTS<------\n\n");
	printf(" Multiple convertions test d: [%d]\n Multiple convertions test c: [%c]\n Multiple convertions test s: [%s]\n\n", 42, 'X', "Hello World");
	ft_printf(" Multiple convertions test d: (%d)\n Multiple convertions test c: (%c)\n Multiple convertions test s: (%s)\n\n", 42, 'X', "Hello World");

	ft_printf("\n------>SLIGHTLY COMPLICATED TESTS<------\n\n");
	printf(" Less Usual S: [%S]\n", S);
	printf(" Less Usual D: [%D]\n", 21);
	printf(" Less Usual i: [%i]\n", 42);
	printf(" Less Usual o: [%o]\n", 250);
	printf(" Less Usual O: [%O]\n", 500);
	printf(" Less Usual u: [%u]\n", 1000);
	printf(" Less Usual x: [%x]\n", 2000);
	printf(" Less Usual X: [%X]\n", 4000);
	printf(" Less Usual C: [%C]\n\n", A);

	ft_printf(" Less Usual S: (%S)\n", S);
	ft_printf(" Less Usual D: (%D)\n", 21);
	ft_printf(" Less Usual i: (%i)\n", 42);
	ft_printf(" Less Usual o: (%o)\n", 250);
	ft_printf(" Less Usual O: (%O)\n", 500);
	ft_printf(" Less Usual u: (%u)\n", 1000);
	ft_printf(" Less Usual x: (%x)\n", 2000);
	ft_printf(" Less Usual X: (%X)\n", 4000);
	ft_printf(" Less Usual C: (%C)\n\n", A);

	ft_printf("\n------>COMPLICATED TEST<------\n\n");
	printf(" Starting with char: [%c]\n", 'X');
	printf(" Followed by int: [%d]\n", 42);
	printf(" Followed by int: [%d]\n", 42);
	printf(" Followed by char: [%c]\n", 'X');

	printf(" Starting with char: (%c)\n", 'X');
	printf(" Followed by int: (%d)\n", 42);
	printf(" Followed by int: (%d)\n", 42);
	printf(" Followed by char: (%c)\n\n", 'X');
	
	ft_printf("\n------>MORE COMPLICATE TESTS<------\n\n");
	printf(" Testing Left Justified: [%-5d]\n", 42);
	printf(" Testing Right Justified: [%5d]\n", 42);
	printf(" Testing '+' symbol: [%+d]\n", 42);
	printf(" Testing '#' symbol: [%#o]\n", 42);
	printf(" Testing '0' padding: [%05d]\n", 42);
	printf(" Testing white space padding right: [% 5d]\n", 42);
	printf(" Testing white space padding left: [%-5d]\n\n", 42);

	ft_printf(" Testing Left Justified: (%-5d)\n", 42);
	ft_printf(" Testing Right Justified: (%5d)\n", 42);
	ft_printf(" Testing '+' symbol: (%+d)\n", 42);
	ft_printf(" Testing '#' symbol: (%#o)\n", 42);
	ft_printf(" Testing '0' padding: (%05d)\n", 42);
	ft_printf(" Testing white space padding right: (% 5d)\n", 42);
	ft_printf(" Testing white space padding left: (%-5d)\n\n", 42);

	ft_printf("\n------>MORE STUFF TO TEST<------\n\n");
	ft_printf("       --->Testing 'l'<---\n\n");
	printf(" Testing 'l' modifier on d: [%ld]\n", test_l);
	printf(" Testing 'l' modifier on i: [%li]\n", test_l);
	printf(" Testing 'l' modifier on o: [%lo]\n", test_l);
	printf(" Testing 'l' modifier on u: [%lu]\n", test_l);
	printf(" Testing 'l' modifier on x: [%lx]\n", test_l);
	printf(" Testing 'l' modifier on X: [%lX]\n", test_l);
	printf(" Testing 'l' modifier on c: [%lc]\n\n", test_l_on_c);
	printf(" Testing 'l' modifier on s: [%ls]\n\n", S);

	ft_printf(" Testing 'l' modifier on d: (%ld)\n", test_l);
	ft_printf(" Testing 'l' modifier on i: (%li)\n", test_l);
	ft_printf(" Testing 'l' modifier on o: (%lo)\n", test_l);
	ft_printf(" Testing 'l' modifier on u: (%lu)\n", test_l);
	ft_printf(" Testing 'l' modifier on x: (%lx)\n", test_l);
	ft_printf(" Testing 'l' modifier on X: (%lX)\n", test_l);
	ft_printf(" Testing 'l' modifier on c: (%lc)\n", test_l_on_c);
	ft_printf(" Testing 'l' modifier on s: (%ls)\n\n", S);

	ft_printf("       --->Testing 'll'<---\n\n");
	printf(" Testing 'll' modifier on d: [%lld]\n", test_ll);
	printf(" Testing 'll' modifier on i: [%lli]\n", test_ll);
	printf(" Testing 'll' modifier on o: [%llo]\n", test_ll);
	printf(" Testing 'll' modifier on u: [%llu]\n", test_ll);
	printf(" Testing 'll' modifier on x: [%llx]\n", test_ll);
	printf(" Testing 'll' modifier on X: [%llX]\n\n", test_ll);

	ft_printf(" Testing 'll' modifier on d: (%lld)\n", test_ll);
	ft_printf(" Testing 'll' modifier on i: (%lli)\n", test_ll);
	ft_printf(" Testing 'll' modifier on o: (%llo)\n", test_ll);
	ft_printf(" Testing 'll' modifier on u: (%llu)\n", test_ll);
	ft_printf(" Testing 'll' modifier on x: (%llx)\n", test_ll);
	ft_printf(" Testing 'll' modifier on X: (%llX)\n\n", test_ll);

	ft_printf("       --->Testing 'h'<---\n\n");
	printf(" Testing 'h' modifier on d: [%hd]\n", test_h);
	printf(" Testing 'h' modifier on i: [%hi]\n", test_h);
	printf(" Testing 'h' modifier on o: [%ho]\n", test_h);
	printf(" Testing 'h' modifier on u: [%hu]\n", test_h);
	printf(" Testing 'h' modifier on x: [%hx]\n", test_h);
	printf(" Testing 'h' modifier on X: [%hX]\n\n", test_h);

	ft_printf(" Testing 'h' modifier on d: (%hd)\n", test_h);
	ft_printf(" Testing 'h' modifier on i: (%hi)\n", test_h);
	ft_printf(" Testing 'h' modifier on o: (%ho)\n", test_h);
	ft_printf(" Testing 'h' modifier on u: (%hu)\n", test_h);
	ft_printf(" Testing 'h' modifier on x: (%hx)\n", test_h);
	ft_printf(" Testing 'h' modifier on X: (%hX)\n\n", test_h);

	ft_printf("       --->Testing 'hh'<---\n\n");
	printf(" Testing 'hh' modifier on d: [%hhd]\n", test_hh);
	printf(" Testing 'hh' modifier on i: [%hhi]\n", test_hh);
	printf(" Testing 'hh' modifier on o: [%hho]\n", test_hh);
	printf(" Testing 'hh' modifier on u: [%hhu]\n", test_hh);
	printf(" Testing 'hh' modifier on x: [%hhx]\n", test_hh);
	printf(" Testing 'hh' modifier on X: [%hhX]\n\n", test_hh);

	ft_printf(" Testing 'hh' modifier on d: (%hhd)\n", test_hh);
	ft_printf(" Testing 'hh' modifier on i: (%hhi)\n", test_hh);
	ft_printf(" Testing 'hh' modifier on o: (%hho)\n", test_hh);
	ft_printf(" Testing 'hh' modifier on u: (%hhu)\n", test_hh);
	ft_printf(" Testing 'hh' modifier on x: (%hhx)\n", test_hh);
	ft_printf(" Testing 'hh' modifier on X: (%hhX)\n\n", test_hh);

	ft_printf("       --->Testing 'j'<---\n\n");
	printf(" Testing 'j' modifier on d: [%jd]\n", test_j);
	printf(" Testing 'j' modifier on i: [%ji]\n", test_j);
	printf(" Testing 'j' modifier on o: [%jo]\n", test_j);
	printf(" Testing 'j' modifier on u: [%ju]\n", test_j);
	printf(" Testing 'j' modifier on x: [%jx]\n", test_j);
	printf(" Testing 'j' modifier on X: [%jX]\n\n", test_j);

	ft_printf(" Testing 'j' modifier on d: (%jd)\n", test_j);
	ft_printf(" Testing 'j' modifier on i: (%ji)\n", test_j);
	ft_printf(" Testing 'j' modifier on o: (%jo)\n", test_j);
	ft_printf(" Testing 'j' modifier on u: (%ju)\n", test_j);
	ft_printf(" Testing 'j' modifier on x: (%jx)\n", test_j);
	ft_printf(" Testing 'j' modifier on X: (%jX)\n\n", test_j);

	ft_printf("       --->Testing 'z'<---\n\n");
	printf(" Testing 'z' modifier on d: [%zd]\n", test_z);
	printf(" Testing 'z' modifier on i: [%zi]\n", test_z);
	printf(" Testing 'z' modifier on o: [%zo]\n", test_z);
	printf(" Testing 'z' modifier on u: [%zu]\n", test_z);
	printf(" Testing 'z' modifier on x: [%zx]\n", test_z);
	printf(" Testing 'z' modifier on X: [%zX]\n\n", test_z);

	ft_printf(" Testing 'z' modifier on d: (%zd)\n", test_z);
	ft_printf(" Testing 'z' modifier on i: (%zi)\n", test_z);
	ft_printf(" Testing 'z' modifier on o: (%zo)\n", test_z);
	ft_printf(" Testing 'z' modifier on u: (%zu)\n", test_z);
	ft_printf(" Testing 'z' modifier on x: (%zx)\n", test_z);
	ft_printf(" Testing 'z' modifier on X: (%zX)\n\n", test_z);

	ft_printf("\n------>AND FINALLY, PRECISION<------\n\n");
	printf("Test no width and precision: [%.s]", "This is a string\n");
	return (0);
}
