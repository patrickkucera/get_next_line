/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:49:13 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/19 11:27:20 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/** ft_strlen
 * Calcule la longueur de la chaîne s jusqu'à, mais n'incluant pas le
 * caractère nul de fin. Exemple : ft_strlen("1234") => 4
 *
 * C'est la chaîne dont la longueur doit être trouvée.
 * Cette fonction renvoie la longueur de la chaîne.
 */
size_t	ft_strlen(const char *S)
{
	size_t	i;

	i = 0;
	while (S[i])
		i++;
	return (i);
}

/** ft_strdup
 * Renvoie un pointeur vers une chaîne d'octets terminée par un caractère nul,
 * qui est un doublon de la chaîne pointée par str. Le pointeur retourné 
 * doit être passé à free pour éviter une fuite de mémoire. Si une erreur se
 * produit, un pointeur nul est renvoyé et errno peut être défini.
 *
 * Pointeur vers la chaîne d'octets terminée par un caractère nul à dupliquer.
 * 
 * Un pointeur vers la chaîne nouvellement allouée, ou un pointeur nul
 * si une erreur s'est produite.
 */
char	*ft_strdup(const char *STR)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen(STR) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (s == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = STR[i];
	return (s);
}

/** ft_substr
 * Alloue (avec malloc(3)) et renvoie une sous-chaîne de la chaîne
 * 's'. La sous-chaîne commence à l'index 'start' et a une taille maximale 'len'.
 *
 * s La chaîne à partir de laquelle créer la sous-chaîne.
 * start L'index de début de la sous-chaîne dans la chaîne 's'.
 * len La longueur maximale de la sous-chaîne.
 * 
 * La sous-chaîne. NULL si l'allocation échoue.
*/
char	*ft_substr(char const *S, unsigned int start, size_t len)
{
	size_t	i;
	size_t	srclen;
	char	*str;

	if (!S)
		return (NULL);
	srclen = ft_strlen(S);
	if (start > srclen)
		return (ft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (S[start + i] && i < len)
	{
		str[i] = S[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/** ft_strchr
 * Recherche la première occurrence du caractère c
 * (un caractère non signé) dans la chaîne pointée par l'argument s. le
 * le caractère nul de fin est considéré comme faisant partie de la chaîne ; donc
 * si c est \\0, les fonctions localisent le \\0 final.
 *
 * Il s'agit de la chaîne C à analyser.
 * C'est le caractère à localiser. Il est passé comme int,
 * mais il est reconverti en interne en char.
 * 
 * Cela renvoie un pointeur sur la première occurrence du caractère c
 * dans la chaîne s, ou NULL si le caractère n'est pas trouvé.
 */
char	*ft_strchr(const char *S, int c)
{
	char	*str;
	char	ch;

	str = (char *)S;
	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}

/** ft_strjoin
 * Alloue (avec malloc(3)) et retourne une nouvelle chaîne, qui est la
 * résultat de la concaténation de ’s1’ et ’s2’.
 *
 * s1 @La chaîne de préfixe.
 * s2 La chaîne de suffixe.
 * 
 * La nouvelle chaîne. NULL si l'allocation échoue.
 */
char	*ft_strjoin(const char *S1, const char *S2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!S1 || !S2)
		return (NULL);
	size = ft_strlen(S1) + ft_strlen(S2) + 1;
	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	i = -1;
	while (S1[++i])
		str[i] = S1[i];
	j = -1;
	while (S2[++j])
		str[i + j] = S2[j];
	str[i + j] = '\0';
	return (str);
}
