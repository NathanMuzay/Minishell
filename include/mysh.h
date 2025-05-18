/*
** EPITECH PROJECT, 2025
** mysh header
** File description:
** mysh.h
*/

#include "my.h"

#ifndef MYSH
    #define MYSH

    #define SUCCESS 0
    #define ERROR 84
    #define BAD_COMMAND 1
    #define ENV_BAD_ARGS 127

    #define COLOR_RED     "\x1b[31m"
    #define COLOR_GREEN   "\x1b[32m"
    #define COLOR_YELLOW  "\x1b[33m"
    #define COLOR_BLUE    "\x1b[34m"
    #define COLOR_MAGENTA "\x1b[35m"
    #define COLOR_CYAN    "\x1b[36m"
    #define COLOR_RESET   "\x1b[0m"
    #define BOLD          "\e[1m"
    #define BOLD_OFF      "\e[m"

typedef enum {
    LAST,
    SEMICOLON,
    AND,
    OR,
    SINGLE_QUOTES,
    DOUBLE_QUOTES,
    BACKTICKS,
    BRACKETS,
    NONE
} separator_t;

typedef struct index_s {
    int brackets;
    int squotes;
    int dquotes;
    int backticks;
} i_t;

typedef struct commands_s {
    char *cmd;
    separator_t separator;
    separator_t mother;
    separator_t next;
} commands_t;

typedef struct alias_s {
    char *command_base;
    char *new_name;
    struct alias_s *next;
} alias_t;

typedef struct history_s {
    char *cmd;
    int id;
    int hour;
    int min;
} history_t;

typedef struct local_var_s {
    char *name;
    char *value;
    struct local_var_s *next;
} local_var_t;

typedef struct mysh_s {
    struct stat sb;
    char **env;
    char **local_env;
    char *line;
    size_t line_size;
    char *cmd_path;
    char **cmd_args;
    char **separated_space;
    char **tmp;
    local_var_t *locals;
    int status;
    int cursor;

    // process
    int index_pid;

    // commands
    int cmd_index;
    int cmd_pos;
    commands_t *cmds;
    commands_t **brackets_cmds;

    // redirections
    int is_redirect;
    int file;
    int fd2;
    int fd3;
    int std_output;

    // pipes
    int pipefd[2];
    char **commands;
    int i;
    int lol;
    int cmd_count;

    // alias
    alias_t *alias;
    int alias_count;

    // history
    history_t *history;
    int id_command;
    int current_history_index;

    // brackets
    separator_t mere;
    int brackets;
    int nb_brackets;

    // cd
    char *curr_dir;
    char *last_dir;
    size_t path_size;

    // time
    struct timeval start;
    struct timeval end;

    // index
    i_t *in;

    // interactivité
    int interactive_input;
} mysh_t;

typedef struct builtins_s {
    char *cmd;
    void (*function)(mysh_t *);
} builtins_t;

typedef struct {
    commands_t *cmds;
    mysh_t *sh;
    char *str;
    int *index;
} parse_ctx_t;

// shell
int minishell(char **env);
void shell_display_prompt(mysh_t *sh);
void shell_process_commands(mysh_t *sh);
void shell_handle_builtins(mysh_t *sh);
void shell_execute_command(mysh_t *sh, char **cmd);
void shell_simple_command(mysh_t *sh, char **cmd);
void shell_catch_status(mysh_t *sh, pid_t pid);

// commands
void parsing(mysh_t *sh);
commands_t *parse_commands(mysh_t *sh, char *str);
int is_end_separator(const char *str);

// parsing
void parse_brackets(commands_t *cmds, mysh_t *sh, char *str, int *index);
void parse_backtick(commands_t *cmds, mysh_t *sh, char *str, int *index);
void parse_logic(parse_ctx_t *ctx, char delim, separator_t sep, int advance);

// path
char *path_get_full_cmd(mysh_t *sh, char *cmd, char **env);

// redirections
void redirection_handler(mysh_t *sh);
int redirect1(mysh_t *sh, int i);
int redirect2(mysh_t *sh, int i);
int redirect3(mysh_t *sh, int i);
void redirection_close(mysh_t *sh);

// pipes
void execute_piped_commands(char *cmd_line, mysh_t *sh);
pid_t pipe_write_execute(mysh_t *sh, int *fd, pid_t pid1);
pid_t pipe_read_execute(mysh_t *sh, int *fd, pid_t pid2, int pipe_index);

// inhibitors
char **inhibitors_process(char **array);

// alias
void set_alias(mysh_t *sh);
int is_alias(mysh_t *sh);
int init_tmp_alias_array(mysh_t *sh, int *indicateur);
int change_tmp(mysh_t *sh, int test, alias_t *al);
int alias_process(mysh_t *sh);
int apply_aliases(mysh_t *sh);
int handle_alias_execution(mysh_t *sh, int indicateur);

// history
void history_update(mysh_t *sh);
void simple_history(mysh_t *sh);
void double_history(mysh_t *sh);
void history_display(mysh_t *sh);
void flag_history(mysh_t *sh);

// local env
void my_set(mysh_t *sh);
void my_unset(mysh_t *sh);
char *local_var_token(char *token);

// quotes
char **quotes(commands_t *cmds, char *str, int i);

// brackets
void brackets(mysh_t *sh);

// check
int check_matching(char *line);

// builtins
void my_cd(mysh_t *sh);
void my_setenv(mysh_t *sh);
void my_unsetenv(mysh_t *sh);
void my_env(mysh_t *sh);
void my_exit(mysh_t *sh);

// if
void handle_if_command(mysh_t *sh);
int my_arrlen(char **array);
int valid_wi(mysh_t *sh);

// where
void handle_where_command(mysh_t *sh);

// backtick
char *backtick_management(char *str);

// utils
char *delete_newline(char *str);
int is_arg_empty(const char *str);
int my_isalnum_underscore(char c);
int my_isalpha_underscore(char c);
char **split_by_semicolon(char *str);
char *type_to_string(separator_t sep);
int tab_count(commands_t *cmd);
char **quotes_to_array(char *str);
void reset_parse(mysh_t *sh);

// globbing
char **globbings(char **args);
void free_args(char **args);

// termios
void enable_raw_mode(struct termios *oldt);
void disable_raw_mode(struct termios *oldt);
size_t my_getline(char **lineptr, size_t *n, FILE *stream, mysh_t *sh);
size_t delete_char(size_t *n, char **lineptr, mysh_t *sh);
size_t write_char(int c, size_t *n, char **lineptr, mysh_t *sh);

//arrow
size_t handle_arrow(char **lineptr, size_t *n, FILE *stream, mysh_t *sh);
size_t up_arrow(char **lineptr, size_t *n, mysh_t *sh);
size_t down_arrow(char **lineptr, size_t *n, mysh_t *sh);
void right_arrow(mysh_t *sh);
void left_arrow(mysh_t *sh);

// bonuses
void repeat(mysh_t *sh);
void fortune(mysh_t *sh);
void chaos(mysh_t *sh);
void peda(mysh_t *sh);

// free
void free_shell(mysh_t *sh);
void free_array(char **array);

#endif
