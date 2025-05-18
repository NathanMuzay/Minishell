/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** fortune
*/

#include "../include/mysh.h"

char *const fort[] = {
    "Success is not final, failure is not fatal: it is the courage"
    " to continue that counts.",
    "The quieter you become, the more you can hear.",
    "In the middle of difficulty lies opportunity.",
    "Eat. Sleep. Code. Repeat.",
    "Make it work, make it right, make it fast.",
    "There is no cloud. It’s just someone else’s computer.",
    "I'm not lazy. I'm just on energy-saving mode.",
    "If debugging is the process of removing bugs, then programming "
    "must be the process of putting them in.",
    "The code that is the hardest to debug is the code that you know "
    "cannot possibly be wrong.",
    "Shell yeah.",
    "rm -rf / — because why not?",
    "Coding is 90% debugging and 10% writing bugs.",
    "Segmentation fault (core dumped)… again.",
    "Beware of infinite loops — they're infinite.",
    "42 is the answer to life, the universe and everything.",
    "There are two hard things in computer science: cache invalidation, "
    "naming things, and off-by-one errors.",
    "Keep calm and fix the segmentation fault.",
    "printf(\"Hello World\") — the start of every great journey.",
    "To err is human, to blame it on the computer shows management potential.",
    "Coffee. Code. Collapse. Repeat.",
    "Your shell is cooler than most people's code editors.",
    "Talk is cheap. Show me the code.",
    "Don’t comment bad code — rewrite it.",
    "Computers are fast. Programmers keep it slow.",
    "Don't panic. Just 'man' it.",
    "alias coffee='echo I need one more...'",
    "One does not simply write bug-free code.",
    "Pipes are life. Redirections are destiny.",
    "ls -la: the only command you truly need.",
    "Hack the planet."
};

void fortune(mysh_t *sh)
{
    int line = 0;

    sh = sh;
    srand(time(NULL));
    line = rand() % count_lines_array(fort);
    printf("%s\n", fort[line]);
    return;
}
