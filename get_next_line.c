/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rruiz <rruiz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:13:26 by rruiz             #+#    #+#             */
/*   Updated: 2025/11/17 10:17:57 by rruiz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*extract_clean(char *line, char *remains);
char		*fill_line(int fd, char *line, char *remains);
static void	save_remains(char *line, char *remains, char *newline);
static void	var_def(size_t *i, char **newline, size_t *line_len, char *line);

char	*get_next_line(int fd)
{
	static char	remains[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup("");
	line = fill_line(fd, line, remains);
	if (!line || line[0] == '\0')
	{
		free(line);
		remains[0] = '\0';
		return (NULL);
	}
	return (extract_clean(line, remains));
}

static void	save_remains(char *line, char *remains, char *newline)
{
	size_t	i;
	size_t	j;

	j = 0;
	if (newline)
	{
		i = (newline - line) + 1;
		while (line[i])
		{
			remains[j] = line[i];
			i++;
			j++;
		}
	}
	remains[j] = '\0';
}

static void	var_def(size_t *i, char **newline, size_t *line_len, char *line)
{
	*i = 0;
	*newline = ft_strchr(line, '\n');
	if (*newline)
		*line_len = (*newline - line) + 1;
	else
		*line_len = ft_strlen(line);
}

char	*extract_clean(char *line, char *remains)
{
	char	*newline;
	char	*extracted_line;
	size_t	line_len;
	size_t	i;

	var_def(&i, &newline, &line_len, line);
	extracted_line = malloc(sizeof(char) * (line_len + 1));
	if (!extracted_line)
	{
		free(line);
		return (NULL);
	}
	while (i < line_len)
	{
		extracted_line[i] = line[i];
		i++;
	}
	extracted_line[i] = '\0';
	save_remains(line, remains, newline);
	free(line);
	return (extracted_line);
}

char	*fill_line(int fd, char *line, char *remains)
{
	int	read_bytes;

	read_bytes = 1;
	line = ft_strjoin_free(line, remains);
	if (!line)
		return (NULL);
	remains[0] = '\0';
	while (!ft_strchr(line, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, remains, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			if (read_bytes == -1)
			{
				free(line);
				return (NULL);
			}
			break ;
		}
		remains[read_bytes] = '\0';
		line = ft_strjoin_free(line, remains);
		if (!line)
			return (NULL);
	}
	return (line);
}

// int main()
// {
// 	// int fd = open("long_nl.txt", O_RDONLY);
// 	// int fd = open("star_wars.txt", O_RDONLY);
// 	int fd = open("empty", O_RDONLY);
// 	if (fd == -1)
// 		{
// 			printf("Erreur de fd!!");
// 			return 0;
// 		}
// 	for (int i = 1; i < 1; i++)
// 	{
// 		char *test = get_next_line(fd);
// 		printf("ligne %d : %s", i, test);
// 		free(test);
// 	}
// 	close(fd);
// 	return 0;
// }

				// ## Normal Tests ## //
// int	main(int argc, char **argv)
// {
// 	char	*next_line;
// 	int		count;
// 	int		fd;

// 	count = 0;
// 	fd = 0;
// 	if (argc == 1)
// 		fd = 0;
// 	else if (argc == 2)
// 		fd = open(argv[1], O_RDONLY);
// 	else
// 	{
// 		printf("Write \"./a.out\" followed by either:\n");
// 		printf("- A valid text file.\n");
// 		printf("- A string.\n");
// 	}
// 	if (fd == -1)
// 	{
// 		printf("Error opening file or incorrect file name.\n");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (next_line == NULL)
// 		{
// 			printf("[NULL]\n");
// 			break;
// 		}
// 		count++;
// 		printf("[%d]: %s", count, next_line);
// 		free(next_line);
// 		next_line = NULL;
// 	}
// 	if (fd != 0)
//         close(fd);
// 	return (0);
// }

				// ## Invalid FD ## //
// int main(void)
// {
// 	char	*next_line;
// 	int		count;

// 	count = 0;
// 	printf("--- Test: Invalid FD (-1) ---\n");
// 	next_line = get_next_line(-1);
// 	printf("[%d]: %s\n", count, next_line);
// 	free(next_line);
// 	next_line = get_next_line(-1);
// 	printf("[%d]: %s\n", count, next_line);
// 	free(next_line);
// 	return (0);
// }

			// ## Call empty.txt twice ## //
// int main(void)
// {
// 	char	*next_line;
// 	int		count;
// 	int		fd;

// 	count = 0;
// 	fd = 0;
// 	printf("--- Test Empty.txt ---\n");
// 	fd = open("empty.txt", O_RDONLY);
// 	next_line = get_next_line(fd);
// 	printf("[%d]: %s\n", count, next_line);
// 	if (next_line == NULL)
// 		printf("[NULL]\n");
// 	free(next_line);
// 	next_line = get_next_line(fd);
// 	printf("[%d]: %s\n", count, next_line);
// 	if (next_line == NULL)
// 		printf("[NULL]\n");
// 	free(next_line);
// 	close(fd);
// 	return (0);
// }