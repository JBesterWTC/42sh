/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 08:46:22 by jbester           #+#    #+#             */
/*   Updated: 2016/08/08 11:33:12 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H__
# define __LIBFT_H__
# include <unistd.h>
# include <stdlib.h>
# include "ft_get_next_line.h"

/*Replaces characters in b with character c for length len*/
void	*ft_memset(void *b, int c, size_t len);

/*Replaces each character of string s with 0 while less than or equal to length n*/
void	ft_bzero(void *s, size_t n);

/*Copies n characters from string at memory block src to memory block dst*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*Copies string from memory block src to memory block dst until find char c, then return pointer to byte just ater that*/
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*Copies len bytes from string src to string dst*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*Locates a character in string s*/
void	*ft_memchr(const void *s, int c, size_t n);

/*Compares 2 byte strings while length is less than n*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*Finds the length of string s*/
size_t	ft_strlen(const char *s);

/*Copies string s1 to a new string with sufficient memory allocted*/
char	*ft_strdup(const char *s1);

/*Copies string src to string dst, no memory allocated*/
char	*ft_strcpy(char *dst, const char *src);

/*Copies string to src to dst, while less than len*/
char	*ft_strncpy(char *dst, const char *src, size_t len);

/*Joins two strings into one*/
char	*ft_strcat(char *s1, const char *s2);

/*Joins n characters of s2 to s1*/
char	*ft_strncat(char *s1, const char *s2, size_t n);

/*Checks how many characters of src could be joined to dst*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/*Finds first instance of c (converted to char) in s*/
char	*ft_strchr(const char *s, int c);

/*Finds last instance of c (converted to char) in s*/
char	*ft_strrchr(const char *s, int c);

/*Searches for first occurence of string little within big*/
char	*ft_strstr(const char *big, const char *little);

/*Searches for first occurence of string little within len characters of big*/
char	*ft_strnstr(const char *big, const char *little, size_t len);

/*Compares two strings*/
int		ft_strcmp(const char *s1, const char *s2);

/*Compares two strings for length n*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*Converts a string of digit characters into integers*/
int		ft_atoi(const char *str);

/*Checks if the given character is an alphabetic character*/
int		ft_isalpha(int c);

/*Checks if the given character is a digit character*/
int		ft_isdigit(int c);

/*Checks if the given character is alphanumeric*/
int		ft_isalnum(int c);

/*Checks if the given character is part of the ascii table*/
int		ft_isascii(int c);

/*Checks if the given character is printable*/
int		ft_isprint(int c);

/*Converts the given character to uppercase*/
int		ft_toupper(int c);

/*Converts the given character to lowercase*/
int		ft_tolower(int c);

/*Allocates a new memory block and initializes it to 0*/
void	*ft_memalloc(size_t size);

/*Frees a memory block and sets it to NULL*/
void	ft_memdel(void **ap);

/*Allocates memory for a new string and initializes each character to '\0'*/
char	*ft_strnew(size_t size);

/*Frees a string and sets it pointer to NULL*/
void	ft_strdel(char **as);

/*Iterates through a string applying the function f to each character*/
void	ft_striter(char *s, void (*f)(char *));

/*Iterates through a string applying the function f to the index and each character at that index*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*Creates a new string with characters from previous string with function f applied to them*/
char	*ft_strmap(char const *s, char (*f)(char));

/*Creates a new string with characters from previous string with function f applied to characters and index*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*Lexographically compares string 1 and string 2*/
int		ft_strequ(char const *s1, char const *s2);

/*Lexographically compares string 1 and string 2 until '\0' or n characters is reached*/
int		ft_strnequ(char const *s1, char const *s2, size_t n);

/*Creates a new substring starting at start and using length len*/
char	*ft_strsub(char const *s1, unsigned int start, size_t len);

/*Joins two strings to form a new string*/
char	*ft_strjoin(char const *s1, char const *s2);

/*Returns string without spaces/etc at beginning or ending of string*/
char	*ft_strtrim(char const *s);

/*Returns a 2D array with new strings from the original string using the character c as a delimiter*/
char	**ft_strsplit(char const *s, char c);

/*Finds the length of an int*/
int		ft_intlen(int n);

/*Converts an integer into a string*/
char	*ft_itoa(int n);

/*Writes the passed character to standard output*/
void	ft_putchar(char c);

/*Writes the passed string to standard output*/
void	ft_putstr(char const *str);

/*Writes the passed to string to standard output followed by a newline*/
void	ft_putendl(char const *s);

/*Writes the passed number to the standard output*/
void	ft_putnbr(int n);

/*Writes the passed character to the file descriptor fd*/
void	ft_putchar_fd(char c, int fd);

/*Writes the passed character to the file descriptor fd*/
void	ft_putstr_fd(char const *s, int fd);

/*Writes the passed string to the file descriptor fd followed by a newline*/
void	ft_putendl_fd(char const *s, int fd);

/*Writes the passed number to the file descriptor fd followed by a newline*/
void	ft_putnbr_fd(int n, int fd);

/*Sets every character in a string to '\0'*/
void	ft_strclr(char *s);

/*Finds the siez of a 2D array*/
int		ft_array_size(char **arr);

/*Copies a 2D array into a new one from position start to position end*/
char	**ft_copy_2Darray(char **dst, char **src, int start, int end);

#endif
