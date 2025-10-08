#ifndef LIBREGEX_PRIV_H_
#define LIBREGEX_PRIV_H_

#include "libregex.h"

void get_node_type(t_re *node, char *s);
void get_node_c(t_re *node, char *s);
uint8_t get_node_cs(t_re *node, char *s);
uint8_t get_node_minc(t_re *node, char *s);
uint8_t get_node_maxc(t_re *node, char *s);
uint8_t check_re_node(t_re *node);
t_re *build_re_node(char *s);
void append_re_node(t_re **head, t_re *node);
void convert_delimiters(t_re **head);
int8_t is_valid_range(const char *s);
int8_t get_charset(uint8_t *cs, const char *s);
int8_t get_reps(size_t *n, const char *s);
void reverse_charset(uint8_t *cs);
int8_t get_charset(uint8_t *cs, const char *s);

int8_t	ft_isdigit(char c);
int8_t	ft_isascii(char c);
int	ft_atoi(const char *nptr);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strchresc(const char *s, int c, int sc);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char *ft_chrstrchr(char *s, char a, char b, char sc);

/* Function prototypes */

#endif // LIBREGEX_PRIV_H_
