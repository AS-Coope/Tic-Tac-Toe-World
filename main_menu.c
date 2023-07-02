#pragma once
#include "stdio.h"
#include "menu.h"

// global variables
// int playOption = 0;

// definitions for all main menu functions

// properly placing play here needs me to add more C files and header files for the functions it calls
// and then for those functions that those functions call... I need to define an actual
// structure for the project first, instead of just trying to 'structure' on the fly all willy-nilly
// the same applies to settings()

/*
void play()
{
    system ("cls");
    printf ("\t|Play");
    printf ("\n\t|1. Story Mode");
    printf ("\n\t|2. Tournament Mode");
    printf ("\n\t|3. Back to Main Menu");
    printf ("\n\t|Choice: ");
    scanf ("%d", &playOption);
    switch (playOption)
    {
        case 1:
            storyMode();
        break;

        case 2:
            tournamentMode();
        break;

        case 3:
            mainMenu();
        break;

        default:
            printf ("\n\tInvalid Option");
            play();
        break;
    }
}
*/

void instructions()
{
    system ("cls");
    printf ("\t|Instructions:\n");
    printf ("\t|In Tic-tac-toe: World, choose a tile from the 9 tiles arranged in a 3 x 3 (MATRIX) board.\n");
    printf ("\t|Place your target on any of the tiles that does not already have a target.\n");
    printf ("\t|Once you have 3 of your targets either placed vertically, horizontally or diagonally, you win.\n");
    printf ("\t|If the opposite occurs you lose. The other option is a draw.\n");
    printf ("\t|The Story Mode and Tournament Mode should be a fun change. Enjoy!\n\t");
    printf ("-ZrC\n");
    getch ();
    mainMenu();
}

void about()
{
    system ("cls");
    printf ("\t|About:\n");
    printf ("\t|Tic-tac-toe is a strategy game where players choose a tile to place a target. Getting 3 targets in a row, column ");
    printf ("or diagonally makes that \n\t|player the winner of the game. This website was very helpful in helping me ");
    printf ("understand the inner workings of it: \n\t|http://cprogrammingnotes.com/question/tic-tac-toe-game.html . ");
    printf ("I analayzed and used some of the code, tweaking it to fit this version. It is the\n\t|first game I thought of coding and ");
    printf ("it taught me a lot (plus Youtubers kept telling me to try this to start making games). \n\t|I made it for fun as a summer project and I put the logo in at the start ");
    printf ("(a twist on my handle) for fun.\n\t");
    printf ("\n\t|The game eventually turned into my SBA and with the help of my friends, my teacher, Mr. Lewis, and the good old internet, ");
    printf ("I have been able to complete it,\n\t|calling it Tic-Tac-Toe: World because of its Story Mode.\n\t|Have fun playing!\n\t");
    printf ("-ZrC\n");
    getch ();
    mainMenu();
}
