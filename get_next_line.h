/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pakucera <pakucera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:00:17 by pakucera          #+#    #+#             */
/*   Updated: 2022/01/17 18:06:20 by pakucera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FT_INT_MIN -2147483648
# define FT_INT_MAX 2147483647

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
/**
 * Calcule la longueur de la chaîne s jusqu'à, mais n'incluant pas le
 * caractère nul de fin. Exemple : ft_strlen("1234") => 4
 *
 * C'est la chaîne dont la longueur doit être trouvée.
 * Cette fonction renvoie la longueur de la chaîne.
 */

char	*ft_strchr(const char *s, int c);
/**
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

char	*ft_strdup(const char *str);
/**
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

char	*ft_strjoin(char const *s1, char const *s2);
/**
 * Alloue (avec malloc(3)) et retourne une nouvelle chaîne, qui est la
 * résultat de la concaténation de ’s1’ et ’s2’.
 *
 * s1 @La chaîne de préfixe.
 * s2 La chaîne de suffixe.
 * 
 * La nouvelle chaîne. NULL si l'allocation échoue.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * Alloue (avec malloc(3)) et renvoie une sous-chaîne de la chaîne
 * 's'. La sous-chaîne commence à l'index 'start' et a une taille maximale 'len'.
 *
 * s La chaîne à partir de laquelle créer la sous-chaîne.
 * start L'index de début de la sous-chaîne dans la chaîne 's'.
 * len La longueur maximale de la sous-chaîne.
 * 
 * La sous-chaîne. NULL si l'allocation échoue.
*/

char	*get_next_line(int fd);
/**
 * Lit une ligne d'un descripteur de fichier
 *
 * fd Descripteur de fichier à lire.
 * 
 * Renvoie une chaîne incluant \\n si est une ligne. En cas de dossier
 * ne pas avoir \\n renvoyer une chaîne sans \\n, NULL si le fichier est vide
 * ou une erreur s'est produite.
 */

#endif
