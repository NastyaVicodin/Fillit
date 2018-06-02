# Fillit
Backtracking algorithm was used.

Fillit is a project that helped to discover and/or familiarize with a recurring problematic in programming: searching the optimal solution among a huge set of possibilities, in a respectable timing. In this particular project, I found a way to assemble a given Tetriminos set altogether in the smallest possible square.

A Tetriminos is a 4-blocks geometric figure you probably already heard of, thanks to the popular game Tetris.

Fillit is not about recoding Tetris, even if it’s still a variant of this game. Program took a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.

Obviously, main goal is to find the smallest square in the minimal amount of time, despite an exponentially growing number of possibilities each time a piece is added.

# General instructions
* Project must be written in C and must respect the Norme coding standard.
* The allowed functions are : exit, open, close, write, read, malloc and free.
* Makefile must compile your code without relinks.
* It must contain the following rules : all, clean ,fclean et re.
* You must compile your binary with the Wall, Wextra and Werror flags. Any other flag are forbidden, especially those for optimising purposes.
* The binary must be named fillit and located in the root directory of your repository.
