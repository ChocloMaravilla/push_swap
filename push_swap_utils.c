/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedina- <rmedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:23:28 by rmedina-          #+#    #+#             */
/*   Updated: 2024/03/15 17:51:16 by rmedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Esta función comprueba si el carácter dado es un dígito numérico del 0 al 9.
int	ft_isnum(int c)
{
	return (c >= '0' && c <= '9');
}

// Esta función convierte la cadena de caracteres 
// dada en un número entero largo.
// Ignora los espacios en blanco iniciales y luego 
// procesa los dígitos numéricos
// hasta que se encuentra un carácter no numérico o se 
// alcanza el final de la cadena.
// La función también maneja los signos positivos y 
// negativos y registra errores
// mediante el parámetro 'err'.
int	ft_atoi(const char *str)
{
	long		i;
	long		result;
	long		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

// Esta función verifica si hay duplicados entre los 
// argumentos proporcionados en la línea de comandos.
// Utiliza la función ft_atoi_long para convertir los 
// argumentos en números enteros largos
// y luego los compara para detectar duplicados. Además, 
// registra errores de conversión
// utilizando el parámetro 'num_err'.
int	ft_isdupli(int argc, char **argv)
{
	int	count;
	int	num_err;
	int	count2;
	int	num1;
	int	num2;

	count = 1;
	while (count < argc)
	{
		count2 = 1;
		while (argv[count2])
		{
			num_err = 0;
			num1 = ft_atoi(argv[count]);
			num2 = ft_atoi(argv[count2]);
			if ((count != count2 && num1 == num2))
				return (ERROR);
			count2++;
		}
		count++;
	}
	return (0);
}

// Esta función determina si un número en una cadena 
// de caracteres es positivo o negativo.
// Modifica el parámetro 'sign' según el signo encontrado 
// en la posición 'a' de la cadena.
void	positive_or_negative(const char *str, int *a, int *sign)
{
	if (str[*a] == '-')
	{
		*sign = -1;
		a++;
	}
	else if (str[*a] == '+')
		a++;
}
