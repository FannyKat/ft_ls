#include "my_ls.h"

void				block_bytes(t_list *file, t_list *begin)
{
	struct stat 		fd;
	t_data			bytes;

	begin = file;
	bytes.total = 0;
	while (file->next)
	{
		stat(file->content, &fd);
		bytes.total += fd.st_blocks;
		file = file->next;
	}
	file = begin;
	printf("total %llu\n", bytes.total);
}

char				*get_name(char *av)
{
	char			*str;
	int			i;

	i = ft_strlen(av);
	while (i > 0 && av[i] != '/')
		i--;
	i = av[i] == '/' ? i + 1 : i;
	str = ft_strdup(av + i);
	return (str);
}

char				*get_time(char *av)
{
	av = ft_strsub(av, 4, ft_strlen(av) - (4 + 9));
	return (av);
}

void 				*get_mode(mode_t fd)
{ 
	printf("%s", S_IRUSR & (fd) ? "r" : "-");
	printf("%s", S_IWUSR & (fd) ? "w" : "-");
	printf("%s", S_IXUSR & (fd) ? "x" : "-");
	printf("%s", S_IRGRP & (fd) ? "r" : "-");
	printf("%s", S_IWGRP & (fd) ? "w" : "-");
	printf("%s", S_IXGRP & (fd) ? "x" : "-");
	printf("%s", S_IROTH & (fd) ? "r" : "-");
	printf("%s", S_IWOTH & (fd) ? "w" : "-");
	printf("%s ", S_IXOTH & (fd) ? "x " : "- ");
	return (0);
}

void 				inspect_file(char *path, int size)
{
	struct stat 		fd;
	struct passwd		*getuid;
	struct group		*getgid;

	stat(path, &fd);
	getuid = getpwuid(fd.st_uid);
	getgid = getgrgid(fd.st_gid);
	if (size)
	{
		printf("%s", S_ISDIR (fd.st_mode) ? "d" : "-");
		get_mode(fd.st_mode);
		printf("%lu ", fd.st_nlink);
		printf("%s ", getuid->pw_name);
		printf("%s ", getgid->gr_name);
		printf("%lu ", fd.st_size);
		printf("%s ", get_time(ctime(&fd.st_mtime)));
		S_ISDIR (fd.st_mode) ? printf("\033[1;34m") : 0;
		printf("%s\n", get_name(path));
		printf("\033[0m");	
	}
}