/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troberts <troberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 01:59:19 by troberts          #+#    #+#             */
/*   Updated: 2022/07/12 17:04:08 by troberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define GNL_BUFFER_SIZE 4096

# ifndef T_LIST
#  define T_LIST

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# endif

/*
** @brief Printf, except it's my own. Support c(har), s(tring), p(ointer),
** d(igit), i(nt), u(nsigned int), x(lower base 16), X(upper base 16),
** %(print %).
** 
** @param ... "string, %FLAG", variable_flag
** @return int Number of bytes displayed.
*/
int			ft_printf(const char *fmt, ...);

/*
** @brief Get the next line of a file descriptor WITH the newline.
** 
** @param fd file descriptor of file to read
** @return char* line that's been read, or NULL if EOF or error
*/
char		*get_next_line(int fd);

/* ************************************************************************** */
/*                                   PART 1                                   */
/* ************************************************************************** */

/*
** @brief Fill memory with a constant byte
** 
** @param s memory area pointed to by s
** @param c constant byte c
** @param n fills the first n bytes
** @return void* Returns a pointer to the memory area s
*/
void		*ft_memset(void *s, int c, size_t n);

/*
** @brief Zero a byte string with '\0' to the area
** 
** @param s location pointed to by s
** @param n erases the data in the n bytes
*/
void		ft_bzero(void *s, size_t n);

/*
** @brief Copy memory area
** 
** @param dest memory area dest
** @param src from memory area src
** @param n copies n bytes
** @return void* pointer to dest
*/
void		*ft_memcpy(void *dest, const void *src, size_t n);

/*
** @brief copy memory area, stopping when the character c is found.
** 
** @param dest to memory area dest
** @param src from memory area src
** @param c character c to found
** @param n copies no more than n bytes
** @return void* returns a pointer to the next character in dest after c,
** or NULL if c was not found in the first n characters of src
*/
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);

/*
** @brief copy memory area of size n bytes
** 
** @param dest to memory area dest
** @param src from memory area src
** @param n copies n bytes
** @return void* pointer to dest
*/
void		*ft_memmove(void *dest, const void *src, size_t n);

/*
** @brief scan memory for a character
** 
** @param s memory area pointed
** @param c 
** @param n 
** @return void* scans the initial n bytes
*/
void		*ft_memchr(const void *s, int c, size_t n);

/*
** @brief compares the first n bytes (each interpreted as unsigned char) of the
** memory areas s1 and s2
** 
** @param s1 memory areas
** @param s2 memory areas 
** @param n bytes
** @return int 0, if the s1 and s2 are equal; a negative value if s1 is less
** than s2; a positive value if s1 is greater than s2. If n is zero, the return
** value is zero.
*/
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** @brief calculates the length of the string pointed to by s, excluding the
** terminating null byte ('\0')
** 
** @param s 
** @return size_t number of bytes in the string
*/
size_t		ft_strlen(const char *s);

/*
** @brief copy up to size-1 bytes to src or len of src if shorter and
** NULL-terminate dst.
** 
** @param dst destination string
** @param src sourse string (must be NULL-terminated)
** @param size size in byte of src, copy up to size-1
** @return size_t length of src (why ? don't know...)
*/
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/*
** @brief appends the NUL-terminated string src to the end of dst.  It will
** append at most size - strlen(dst) - 1 bytes, NUL-terminating the result
** 
** @param dst destination string (must be NULL-terminated)
** @param src sourse string (must be NULL-terminated)
** @param size append at most size - strlen(dst) - 1 bytes
** @return size_t initial length of dst plus the length of src
*/
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/*
** @brief returns a pointer to the first occurrence of the character c in the
** string s
** 
** @param s 
** @param c terminating null byte is considered part of the string, so that if
** c is specified as '\0', these functions return a pointer to the terminator
** @return char* return a pointer to the matched character or NULL if the
** character is not found
*/
char		*ft_strchr(const char *s, int c);

/*
** @brief returns a pointer to the last occurrence of the character c in the
** string s
** 
** @param s 
** @param c terminating null byte is considered part of the string, so that if
** c is specified as '\0', these functions return a pointer to the terminator
** @return char* return a pointer to the matched character or NULL if the
** character is not found
*/
char		*ft_strrchr(const char *s, int c);

/*
** @brief locates the first occurrence of the null-terminated string little in
** the string big, where not more than len characters are searched.  Characters
** that appear after a '\0' character are not searched
** 
** @param big where to search
** @param little what to search
** @param len number of characters to search in big
** @return char* If little is an empty string, big is returned; if little
** occurs nowhere in big, NULL is returned; otherwise a pointer to the first
** character of the first occurrence of little is returned
*/
char		*ft_strnstr(const char *big, const char *little, size_t len);

/*
** @brief compare two strings
** 
** @param s1 string s1
** @param s2 string s2
** @param n compares only the first (at most) n bytes of s1 and s2
** @return int 0, if the s1 and s2 are equal; a negative value if s1 is less
** than s2; a positive value if s1 is greater than s2
*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** @brief convert a string to an integer. Undefined if string is bigger than an
** int
** 
** @param nptr string to convert
** @return int 
*/
int			ft_atoi(const char *nptr);

/*
** @brief checks for an alphabetic character
** 
** @param c must have the value of an unsigned char
** @return int nonzero if the character is in the tested class, and zero if not
*/
int			ft_isalpha(int c);

/*
** @brief checks for a digit (0 through 9)
** 
** @param c must have the value of an unsigned char
** @return int nonzero if the character is in the tested class, and zero if not
*/
int			ft_isdigit(int c);

/*
** @brief checks for an alphanumeric character; it is equivalent to (isalpha(c)
**|| isdigit(c))
** 
** @param c must have the value of an unsigned char
** @return int nonzero if the character is in the tested class, and zero if not
*/
int			ft_isalnum(int c);

/*
** @brief checks whether c is a 7-bit unsigned char value that fits into the
** ASCII character set
** 
** @param c must have the value of an unsigned char
** @return int nonzero if the character is in the tested class, and zero if not
*/
int			ft_isascii(int c);

/*
** @brief checks for any printable character including space (' ')
** 
** @param c must have the value of an unsigned char
** @return int nonzero if the character is in the tested class, and zero if not
*/
int			ft_isprint(int c);

/*
** @brief convert uppercase
** 
** @param c If c is neither an unsigned char value nor EOF, the behavior of
** these functions is undefined
** @return int converted letter, or c if the conversion was not possible
*/
int			ft_toupper(int c);

/*
** @brief convert lowercase
** 
** @param c If c is neither an unsigned char value nor EOF, the behavior of
** these functions is undefined
** @return int converted letter, or c if the conversion was not possible
*/
int			ft_tolower(int c);

/*
** @brief allocates memory for an array of nmemb elements of size bytes each
** and returns a pointer to the allocated memory. The memory is set to zero.
** If the multiplication of nmemb and size would result in integer overflow,
** then  calloc() returns an error.
** 
** @param nmemb array of nmemb elements
** @param size size in bytes of each elements
** @return void* return a pointer to the allocated memory. On error, these
** functions return NULL. NULL may also be returned by a successful call to
** calloc() with nmemb or size equal to zero
*/
void		*ft_calloc(size_t nmemb, size_t size);

/*
** @brief returns a pointer to a new string which is a duplicate of the string
** s.  Memory for the new string is obtained with malloc(3), and can be freed
** with free(3)
** 
** @param s string to duplicate
** @return char* On success, the strdup() function returns a pointer to the
** duplicated string.  It returns NULL if insufficient memory was available
*/
char		*ft_strdup(const char *s);

/* ************************************************************************** */
/*                                 OLD PART 1                                 */
/* ************************************************************************** */

/*
** @brief copies the string pointed to by src, including the terminating null
** byte ('\0'), to the buffer pointed to by dest. The strings may not overlap.
** 
** @param dest the destination string dest must be large enough to receive the
** copy
** @param src pointer to the source string
** @return char* pointer to the destination string dest
*/
char		*ft_strcpy(char *dest, const char *src);

/*
** @brief copies at most n bytes of src to the buffer pointed to by dest. The
** strings may not overlap. If there is no null byte among the first n bytes of
** src, the string placed in dest will not  be  null-terminated.
** 
** @param dest the destination string dest must be large enough to receive the
** copy
** @param src pointer to the source string
** @param n if the length of src is less than n, writes additional null bytes
** to dest to ensure that a total of n bytes are written
** @return char* pointer to the destination string dest
*/
char		*ft_strncpy(char *dest, const char *src, size_t n);

/*
** @brief appends  the  src string to the dest string, overwriting the
** terminating null byte ('\0') at the end of dest, and then adds a terminating
** null byte.  The strings may not overlap, and the dest string must have
** enough space for the result.  If dest is not large enough, program behavior
** is unpredictable
** 
** @param dest destination string (NULL-terminated)
** @param src  source string (NULL-terminated)
** @return char* pointer to the resulting string dest
*/
char		*ft_strcat(char *dest, const char *src);

/*
** @brief appends n bytes of the  src string to the dest string, overwriting
** the terminating null byte ('\0') at the end of dest, and then adds a
** terminating null byte.  The strings may not overlap, and the dest string
** must have enough space for the result.  If dest is not large enough, program
** behavior is unpredictable
** 
** @param dest size of dest must be at least strlen(dest)+n+1 (n from src plus
** the terminating null byte)
** @param src src does not need to be null-terminated if it contains n or more
** bytes
** @param n it will use at most n bytes from src
** @return char* pointer to the resulting string dest
*/
char		*ft_strncat(char *dest, const char *src, size_t n);

/*
** @brief finds the first occurrence of the substring needle in the string
** haystack.  The terminating null bytes ('\0') are not compared.
** 
** @param haystack where to search
** @param needle what to search
** @return char* pointer to the beginning of the located substring, or NULL if
** the substring is not found
*/
char		*ft_strstr(const char *haystack, const char *needle);

/*
** @brief compares the two strings s1 and s2. The locale is not taken into
** account, the comparison is done using unsigned characters.
** 
** @param s1 
** @param s2 
** @return int 0, if the s1 and s2 are equal; a negative value if s1 is less
** than s2; a positive value if s1 is greater than s2
*/
int			ft_strcmp(const char *s1, const char *s2);

/* ************************************************************************** */
/*                                   PART 2                                   */
/* ************************************************************************** */

/*
** @brief Allocates (with malloc(3)) and returns a substring from the string
** 's'. The substring begins at index 'start' and is of maximum size 'len'.
** 
** @param s The string from which to create the substring
** @param start The start index of the substring in the string 's'
** @param len The maximum length of the substring
** @return char* The substring or NULL if the allocation fails or an empty
** malloc string if start >= lenght of s
*/
char		*ft_substr(char const *s, unsigned int start, size_t len);

/*
** @brief Allocates (with malloc(3)) and returns a new string, which is the
** result of the concatenation of 's1' and s2'
** 
** @param s1 The prefix string
** @param s2 The suffix string
** @return char* The new string, or NULL if the allocation fails.
*/
char		*ft_strjoin(char const *s1, char const *s2);

/*
** @brief Allocates (with malloc(3)) and returns a copy of 's1' with the
** characters specified in 'set' removed from the beginning and the end of the
** string
** 
** @param s1 The string to be trimmed
** @param set The reference set of characters to trim
** @return char* The trimmed string or NULL if the allocation fails
*/
char		*ft_strtrim(char const *s1, char const *set);

/*
** @brief Allocates (with malloc(3)) and returns an array of strings obtained
** by splitting 's' using the character 'c' as a delimiter. The array must end
** with a NULL pointe
** 
** @param s The string to be split
** @param c The delimiter characte
** @return char** The array of new strings resulting from the split or NULL if
** the allocation fails
*/
char		**ft_split(char const *s, char c);

/*
** @brief Allocates (with malloc(3)) and returns a string representing the
** integer received as an argument. Negative numbers must be handled.
** 
** @param n the integer to convert
** @return char* The string representing the integer or NULL if the allocation
** fails
*/
char		*ft_itoa(int n);

/*
** @brief Applies the function 'f' to each character of the string 's', and
** passing its index as first argument to create a new string (with malloc(3))
** resulting from successive applications of 'f'.
** 
** @param s The string on which to iterate
** @param f The function to apply to each character
** @return char* The string created from the successive applications of 'f'.
** Returns NULL if the allocation fails
*/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** @brief Applies the function 'f' on each character of the string passed as
** argument, passing its index as first argument. Each character is passed by
** address to 'f' to be modified if necessary
** 
** @param s The string on which to iterate
** @param f The function to apply to each character
*/
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** @brief Outputs the character 'c' to the given file descriptor with write(3)
** 
** @param c The character to outpu
** @param fd The file descriptor on which to write
*/
void		ft_putchar_fd(char c, int fd);

/*
** @brief Outputs the string 's' to the given file descriptor with write(3)
** 
** @param s The string to output
** @param fd The file descriptor on which to write
*/
void		ft_putstr_fd(char *s, int fd);

/*
** @brief Outputs the string 's' to the given file descriptor followed by a
** newline with write(3)
** 
** @param s The string to outpu
** @param fd The file descriptor on which to write
*/
void		ft_putendl_fd(char *s, int fd);

/*
** @brief Outputs the integer 'n' to the given file descriptor write(3)
** 
** @param n The integer to output
** @param fd The file descriptor on which to write
*/
void		ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*                                 OLD PART 2                                 */
/* ************************************************************************** */

/*
** @brief Allocates (with malloc(3)) and returns a "fresh" memory area.
** The memory allocated is initialized to 0.
** 
** @param size The size in byte of the memory that needs to be allocated
** @return void* The allocated memory area or NULL if allocation fails
*/
void		*ft_memalloc(size_t size);

/*
** @brief Takes as a parameter the address of a memory area that needs to be
** freed with free(3), then puts the pointer to NULL
** 
** @param ap A pointer's address that needs its memory freed
*/
void		ft_memdel(void **ap);

/*
** @brief Allocates (with malloc(3)) and returns a "fresh" string ending with
** '\0'. Each character of the string is initialized at '\0'
** 
** @param size The size in byte of the string to be allocated
** @return char* The string allocated and initialized to 0. If the allocation
** fails the function returns NULL
*/
char		*ft_strnew(size_t size);

/*
** @brief Takes as a parameter the address of a string that need to be freed
** with free(3), then sets its pointer to NULL.
** 
** @param as The string's address that needs to be freed and its pointer set
to NULL
*/
void		ft_strdel(char **as);

/*
** @brief Sets every character of the string to the value '\0'
** 
** @param s The string that needs to be cleared
*/
void		ft_strclr(char *s);

/*
** @brief Applies the function f to each character of the string passed
as argument. Each character is passed by address to f to be
modified if necessary.
** 
** @param s The string to iterate
** @param f The function to apply to each character of s
*/
void		ft_striter(char *s, void (*f)(char *));

/*
** @brief Lexicographical comparison between s1 and s2. If the 2
strings are identical the function returns 1, or 0 otherwise
** 
** @param s1 
** @param s2 
** @return int non-zero if identical, zero if not
*/
int			ft_strequ(char const *s1, char const *s2);

/*
** @brief Lexicographical comparison between s1 and s2 up to n characters or
** until a '\0' is reached.
** 
** @param s1 
** @param s2 
** @param n The maximum number of characters to be compared
** @return int non-zero if identical, zero if not
*/
int			ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** @brief Outputs the character c to the standard output
** 
** @param c The character to output
*/
void		ft_putchar(char c);

/*
** @brief Outputs the string s to the standard output
** 
** @param s The string to output
*/
void		ft_putstr(char const *s);

/*
** @brief Outputs the string s to the standard output followed by a '\n'
** 
** @param s The string to output
*/
void		ft_putendl(char *s);

/*
** @brief Applies the function f to each character of the string given as
** argument to create a "fresh" new string (with malloc(3)) resulting from the
** successive applications of f
** 
** @param s The string to map
** @param f The function to apply to each character of s
** @return char* The "fresh" string created from the successive applications of
** f
*/
char		*ft_strmap(char const *s, char (*f)(char));

/* ************************************************************************** */
/*                                   BONUS                                    */
/* ************************************************************************** */

/*
** @brief Allocates (with malloc(3)) and returns a new node. The member variable
** 'content' is initialized with the value of the parameter 'content'. The
** variable 'next' is initialized to NULL
** 
** @param content The content to create the node with
** @return t_list* The new node
*/
t_list		*ft_lstnew(void *content);

/*
** @brief Adds the node 'new' at the beginning of the list
** 
** @param lst The address of a pointer to the first link of a list
** @param new The address of a pointer to the node to be added to the list
*/
void		ft_lstadd_front(t_list **lst, t_list *new);

/*
** @brief Counts the number of nodes in a list
** 
** @param lst The beginning of the list
** @return size_t The length of the list
*/
size_t		ft_lstsize(t_list *lst);

/*
** @brief Returns the last node of the list
** 
** @param lst The beginning of the list
** @return t_list* Last node of the list
*/
t_list		*ft_lstlast(t_list *lst);

/*
** @brief Adds the node 'new' at the end of the list
** 
** @param lst The address of a pointer to the first link of a list
** @param new The address of a pointer to the node to be added to the list
*/
void		ft_lstadd_back(t_list **lst, t_list *new);

/*
** @brief Takes as a parameter a node and frees the memory of the node's content
** using the function 'del' given as a parameter and free the node. The memory
** of 'next' must not be freed
** 
** @param lst The node to free
** @param del The address of the function used to delete the content
*/
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/*
** @brief Deletes and frees the given node and every successor of that node,
** using the function 'del' and free(3). Finally, the pointer to the list must
** be set to NULL.
** 
** @param lst The address of a pointer to a node
** @param del The address of the function used to delete the content of the
** node
*/
void		ft_lstclear(t_list **lst, void (*del)(void *));

/*
** @brief Iterates the list 'lst' and applies the function 'f' on the content
** of each node
** 
** @param lst The address of a pointer to a node
** @param f The address of the function used to iterate on the list
*/
void		ft_lstiter(t_list *lst, void (*f)(void *));

/*
** @brief Iterates the list 'lst' and applies the function 'f' on the content
** of each node. Creates a new list resulting of the successive applications
** of the function 'f'. The 'del' function is used to delete the content of a
** node if needed (if allocation fails on one node, to delete the ).
** 
** @param lst The address of a pointer to a node
** @param f The address of the function used to iterate on the list
** @param del The address of the function used to delete the content of a node
** if needed
** @return t_list* The new list or NULL if the allocation fails, freeing the
** previous nodes
*/
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************************************************************************** */
/*                                   EXTRA                                    */
/* ************************************************************************** */

void		*ft_memrchr(const void *s, int c, size_t n);

/*
** @brief checks  for  white-space  characters. In the "C" and "POSIX" locales,
** these are: space, form-feed ('\\f'), newline ('\\n'), carriage return
** ('\\r'), horizontal tab ('\\t'), and vertical tab ('\\v').
** 
** @param c must have the value of an unsigned char
** @return int nonzero if the character is in the tested class, and zero if not
*/
int			ft_isspace(int c);

/*
** @brief convert a string to an long int. Undefined if string is bigger than
** an long int
** 
** @param nptr string to convert
** @return long 
*/
long		ft_atol(const char *nptr);

/*
** @brief convert a string to an long long int. Undefined if string is bigger
** than an long long int
** 
** @param nptr string to convert
** @return long long
*/
long long	ft_atoll(const char *nptr);

/*
** @brief Outputs the integer 'n' to the stdout
** 
** @param n The integer to output
*/
void		ft_putnbr(int n);

#endif
