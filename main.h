#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
extern char **environ;

/* basic functions  */
int _putchar(char C);
void prints(char *str);
char *str_concatenate(char *s_one, char *s_two);
char *_str_copy(char *des, char *source);
int _str_length(const char *S);
int _str_compare(char *s_one, char *s_two);
char *_strstr(char *str1, char *str2);
char *_str_dup(char *s);
char *_memory_copy(char *des, char *source, unsigned int n);
char *_int_to_ascii(int num, int base);
int _c_toi(char *n);
/*essential functions */

char **split_str(char *line, char **env);
void pri_prompt(void);
char *input_reader(void);
void print_env(char **env);
void _put_str(char *s);

/*process */

int execute_command(char **av, char **args,
	char **env_var, int status, int counter);
char **search(char **env_var);
char **_path_chooser(char *fpath);

/*signal */

void handle_signal(int signal);
int _sta(char **cmd, char **aktacha);
int *_error(char *argv, int count, char *args);


/*memory */
void *_allocat_loc(unsigned int nm, unsigned int size);

#endif /* MAIN_H */

