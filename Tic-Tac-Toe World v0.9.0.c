#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/***Global Declaration of Variables***/

//Character Declarations and Initialization
char player1[15];
char player2[8] = "Berserk";
char AI1[4] = "AI1";
char AI2[4] = "AI2";
char Alexia[7] = "Alexia";
char boss2[8] = "Gustavo";
char boss3[6] = "Aaron";
char boss4[6] = "Mason";
char boss5[9] = "Ernestus";
char gameBoardArr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player1Target = 'X';
char player2Target = 'O';
char firstPlayerTarget;
char thisBoss;
char secondPlayerTarget;
//A variable string called player was here to make the transition from player 1 to player 2 easier but I don't yet
//know how to assign a string value to a string variable so for now I have the opening code in the move () function
char changeName1 = 'N';
char changeName2 = 'N';
char re_match = 'Y';
char piece;
char popElement;

///String declarations for tournament names
char tName1[15];
char tName2[15];
char tName3[15];
char tName4[15];
char tName5[15];
char tName6[15];
char tName7[15];
char tName8[15];
char tName9[15];
char tName10[15];
char tName11[15];
char tName12[15];
char tName13[15];
char tName14[15];
char tName15[15];
char tName16[15];
char tName17[15];
char tName18[15];
char tName19[15];
char tName20[15];
char tName21[15];
char tName22[15];
char tName23[15];
char tName24[15];
char tName25[15];
char tName26[15];
char tName27[15];
char tName28[15];
char tName29[15];
char tName30[15];
char tName31[15];

///Integer Declarations and Initialization
int moveChoice;
int gameWin = 0;
int gridChoice = 0;
int gameDraw = 0;
int playerNum = 1;
int player1points = 0;
int player2points = 0;
int turn = 0;
int battle = 0;
int tempChoice = 0;
int chooseToReplay = 0;
int drawPoints = 0;
int bossNumber = 0;
int settingsOption = 0;
int repeat = 1;
long long int menuOption = 0;
int colour = 5;
int nameChoice = 0;
int playOption = 0;
int storyModeValue = 0;
int tournModeValue = 0;
int progress = 0;
int run = 1;
int haveReplay = 1;
int haveOverride = 1;
int anotherTry = 0;
int willOverride = 0;
int willReplay = 0;
int win1 = 0;
int win2 = 0;
int chooseHint = 0;
int ordinaryWins = 2;
int finalBossWins = 3;
int matchNum = 0;
int roundNum = 0;

///Function Declarations
void mainMenu ();
void warning ();
void gameBoard ();
int gameCheck ();
void tournamentMove(char *, char *);
void storyMove(char *);
void playerSwitch ();
void HUD (char *, char *);
void win (char *, char *);
void draw ();
void statistics (char *, char *, int, int, int, int, int);
void storyStats (int, char *, char *, int, int, int, char *);
void tournamentStats (int, char *, char *, int, int, int);
void gameBoardReset ();
void credits ();
void creditsReplay ();
int dodge (char *, char, char);
int block (char *, char, char);
int blockAdvanced (char *, char, char);
int basicCompMove (char *, char, char);   //computer simply chooses a space on the grid
int alignCompMove (char *, char, char); //computer tries to put two markers together
int compWinMove (char *, char, char);
void themes();
void themeCheck ();
void chooseATheme();
void checkNullTheme();
void settings ();
void changeStoryName ();
int checkNullName ();
void storyMode();
void play ();
void tournamentMode();
void theBoss1(char *, char *, char *, char *, char *);
void theBoss2(char *, char *, char *, char *);
void theBoss3(char *, char *, char *, char *);
void theBoss4(char *, char *, char *, char *);
void theBoss5(char *, char *, char *, char *);
void about ();
void instructions ();
void secrets ();
void introduction(char *, char *);
void getPlayerName ();
void moveOverride(char *);
void checkForReplay (int);
void checkForOverride (int);
int gamePlay(int, int, void (* z)(char *), char *);
int tournGamePlay (int, int, void (* j)(char *, char *), void (* z)(char *, char *), char *, char *);
void boss1Battle(char *);
void boss2Battle(char *);
void boss3Battle (char *);
void boss4Battle (char *);
void boss5Battle (char *);
void bossSecrets ();
void gameHints ();
void unknownSecret ();
int storyNameCheck ();
void handle();

///Tournament Mode Functions
void PvP2 (char *, char *, char *, int, int);
void PvP4 (char *, char *, char *, char *, char *, char *, char *, int, int);
void PvP8 (char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, int, int);
void PvP16 (char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, char *, int, int);

///Tournament Mode Integer Variables Declaration and Initialization
int t16Max = 16;
int t8Max = 8;
int t4Max = 4;
int t2Max = 2;

///These declarations are for the Rankings Stack Function
void winnerDecider (char *, char *, char *, int, int, int, int);
void tournIsFull ();
void tournIsEmpty ();
void tournDisplay (int, int, int);
void tournPop ();
void tournPush (char *, int, int);

///Declaration of variables
char tournStack[10][10];
int tournHead = 0;
int tournTail = 0;
char tournElement[10];
char loser[10];

///These declarations and initializations work with the Replay Stack function
/**Declaration of Functions**/
void pop (int);
void push (int);
void isFull ();
void isEmpty ();
void display ();
void replayChoice ();

///Declaration of variables
int replayStackArr[5];
int head = -1;
int tail = 0;
int element;

///Declaration of file pointers
FILE *tptr;
FILE *nfptr;
FILE *prog_ptr;


int main (void)
{
    checkNullTheme();
    handle();
    warning();
    mainMenu ();
    return 0;
}

void handle ()
{
    printf ("Press the Windows Button + F11 to expand the screen or decrease it.\n");
    Sleep (5000);
    system ("cls");
    Sleep (1000);
    printf ("Press the Windows Button + F11 to expand the screen or decrease it.\n");
    Sleep (5000);
    system ("cls");

    Sleep (500);
    printf ("\t=====================================================================\n");
    Sleep (500);
    printf ("\t||    =======/         __               ====           ====        ||\n");
    Sleep (500);
    printf ("\t||          /         /||             ||    ||       ||    ||      ||\n");
    Sleep (500);
    printf ("\t||         /    __     ||    _____   ||      ||     ||      ||     ||\n");
    Sleep (500);
    printf ("\t||        /     ==     ||    GAMES  ||        ||   ||        ||    ||\n");
    Sleep (500);
    printf ("\t||       /      --     ||    -----  ||        ||   ||        ||    ||\n");
    Sleep (500);
    printf ("\t||      /              ||            ||      ||     ||      ||     ||\n");
    Sleep (500);
    printf ("\t||     /               ||             ||    ||       ||    ||      ||\n");
    Sleep (500);
    printf ("\t||    /======       |=======|           ====           ====        ||\n");
    Sleep (500);
    printf ("\t=====================================================================\n");
    Sleep (500);
    system ("pause");
    system ("cls");
}

int gamePlay (int this1Win, int this2Win, void (z)(char *), char *anotherBoss)
{
    player1points = 0;
    player2points = 0;
    battle = 0;
    battle = battle + 1;
    do
    {///Creates a label for the goto function to come back to this section of the program.

        system ("cls");
        ///The following if, else if and else statements determine which player is currently in play, or if there is an
        ///error in code
        turn = 0;
        turn = turn + 1;
        do
        {

            if (playerNum == 1)
            {
                piece = player1Target;
                ///The player variable used above was here too. This is reference for if I can add back the variable for where it was
                ///in the code. It was used to assign player1 value to player variable.
            }

            else if (playerNum == 2)
            {
                piece = player2Target;
                ///The player variable used above was here too. This is reference for if I can add back the variable for where it was
                ///in the code. It was used to assign player1 value to player variable.
            }

            else
            {
                printf ("There is an error in the program. Player number is not what it should be. It is currently %d", playerNum);
            }

            HUD (player1, anotherBoss);
            Sleep (500);
            if (playerNum == 1)
            {
                storyMove(anotherBoss);
            }
            ///Will be erased and a function for each boss will be placed here instead. Remove turn system too
            else if (playerNum == 2)
            {
                z(anotherBoss);
            }
            system ("cls");
            playerSwitch ();
            turn++;
        }
        while (gameCheck() == -1); ///From gameCheck function

        HUD (player1, anotherBoss);
        ///Shows who won, who lost or if there was a draw.
        if (gameCheck () == 1)
        {
            win (player1, anotherBoss);
            storyStats(bossNumber, player1, anotherBoss, player1points, player2points, drawPoints, Alexia);
            if ( (bossNumber == 5) && (battle == 1) )
            {
                system ("cls");
                printf ("\t%s: How is this possible?", player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: Exactly as I feared. This surprise is no more than an incredibly unfair tactic.", Alexia);
                getch();
                printf ("\n\n");
                printf ("\t%s: Hahaha. I love your reactions. Unfair? You did not think your replay tactic was 'unfair'.\n", boss5);
                printf ("\tI simply just gave myself an advantage... a huge advantage! I personally created this one to be a\n");
                printf ("\trival to the replay tactic but much stronger! I have unlimited usage, so these three battles will fly by\n");
                printf ("\tin a breeze. Hahaha, I warned you not to meddle.");
                getch();
                printf ("\n\n");
                printf ("\t%s: Argghh, I should not have put this past you. %s, I will try to solve this. Just do the next battle.", Alexia, player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: Try all you want. I have an unbreakable hold on this, just like you with your replay tactic. Come, %s\n", boss5, player1);
                printf ("\tthe next battle awaits us. Hahahahahahaha!");
                getch ();
            }
            else if ( (bossNumber == 5) && (battle == 2) )
            {
                system ("cls");
                printf ("\t%s: Well, well. Look at that. The third battle is already here. Should have just stopped like I said before.", boss5);
                getch();
                printf ("\n\n");
                printf ("\t%s: ...", player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: Anyway, let us go on to the ....", boss5);
                getch();
                printf ("\n\n");
                printf ("\t%s: Wait. Before that, explain something to me.", player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: Okay, even if you are trying to buy time for %s, it won't matter. So go ahead.", boss5, Alexia);
                getch();
                printf ("\n\n");
                printf ("\t%s: What do you always mean by 'Be careful who you trust'?", player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: Oh. That. Well, I might as well inform you since it won't matter to you soon.", boss5);
                getch();
                printf ("\n\n");
                printf ("\t%s: You see, when I became corru...", boss5, Alexia);
                getch();

                system ("cls");
                printf ("\t%s: Alright, it is done!", Alexia);
                getch();
                printf ("\n\n");
                printf ("\t%s: Aggghh! What have you done %s? Where is my access to Move Override?", boss5, Alexia);
                getch();
                printf ("\n\n");
                printf ("\t%s: Hah, I disabled your access to it and I gave its control over to %s!", Alexia, player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: I HAVE HAD IT! I'M FINISHING THIS NOW!", boss5);
                getch();
                printf ("\n\n");
                printf ("\t%s: %s, at this time I can only give you access to use it in only one of the battles. Use it wisely.", Alexia, player1);
                getch();
                printf ("\n\n");
                printf ("\t%s: ENOUGH TALKING!", boss5);
                getch ();
                system ("cls");
            }
        }
        else if (gameCheck () == 0)
        {
            draw ();
            storyStats(bossNumber, player1, anotherBoss, player1points, player2points, drawPoints, Alexia);
        }

        gameBoardReset ();
        battle++;
        playerNum = 1;
    }
    while ( (player1points < this1Win) && (player2points < this2Win) ); /// check's either player's win stat
}

int tournGamePlay (int this1Win, int this2Win, void (j)(char *, char *), void (z)(char *, char *), char *thisPlayer, char *thatPlayer)
{
    player1points = 0;
    player2points = 0;
    battle = 0;
    battle = battle + 1;
    do
    {///Creates a label for the goto function to come back to this section of the program.

        system ("cls");
        ///The following if, else if and else statements determine which player is currently in play, or if there is an
        ///error in code
        turn = 0;
        turn = turn + 1;
        do
        {

            if (playerNum == 1)
            {
                piece = player1Target;
                ///The player variable used above was here too. This is reference for if I can add back the variable for where it was
                ///in the code. It was used to assign player1 value to player variable.
            }

            else if (playerNum == 2)
            {
                piece = player2Target;
                ///The player variable used above was here too. This is reference for if I can add back the variable for where it was
                ///in the code. It was used to assign player1 value to player variable.
            }

            else
            {
                printf ("There is an error in the program. Player number is not what it should be. It is currently %d", playerNum);
            }

            HUD (thisPlayer, thatPlayer);
            Sleep (500);
            if (playerNum == 1)
            {
                j(thisPlayer, thatPlayer);
            }
            ///Will be erased and a function for each boss will be placed here instead. Remove turn system too
            else if (playerNum == 2)
            {
                z(thisPlayer, thatPlayer);
            }
            system ("cls");
            playerSwitch ();
            turn++;
        }
        while (gameCheck() == -1); ///From gameCheck function

        HUD (thisPlayer, thatPlayer);
        ///Shows who won, who lost or if there was a draw.
        if (gameCheck () == 1)
        {
            win (thisPlayer, thatPlayer);
            statistics (thisPlayer, thatPlayer, player1points, player2points, drawPoints, roundNum, matchNum);
        }
        else if (gameCheck () == 0)
        {
            draw ();
            statistics (thisPlayer, thatPlayer, player1points, player2points, drawPoints, roundNum, matchNum);
        }

        gameBoardReset ();
        battle++;
        playerNum = 1;
    }
    while ( (player1points < this1Win) && (player2points < this2Win) ); /// check's either player's win stat
}

//Function generates a main menu that the Player(s) interacts with.
void mainMenu ()
{
    system ("cls");
    printf ("\t=========================\n");
    printf ("\t|   Tic-Tac-Toe: World  |\n");
    printf ("\t|\tMain Menu\t|\n");
    printf ("\t|1. Play\t \t|\n");
    printf ("\t|2. Settings\t \t|\n");
    printf ("\t|3. Instructions\t|\n");
    printf ("\t|4. About\t \t|\n");
    printf ("\t|5. Leave\t \t|\n");
    printf ("\t|Choice: ");
    scanf ("%llu", &menuOption);
    switch (menuOption)
    {
        case 1:
            play();
        break;

        case 2:
            settings();
        break;

        case 3:
            instructions ();
        break;

        case 4:
            about();
        break;

        case 5:
            printf ("\n\tThank You for playing Tic-Tac-Toe: World.\n");
            printf ("\tIf you enjoyed it, please consider playing another time!");
            getch();
            exit(0);
        break;

        case 657349677982828580:
            secrets ();
        break;

        default:
            mainMenu();
        break;
    }
}

void secrets ()
{
    system ("cls");
    printf ("\t|Secrets\n");
    printf ("\t|1. Boss Secrets\n");
    printf ("\t|2. Game Hint\n");
    printf ("\t|3. Unknown Secret\n");
    printf ("\t|4. Back to Main Menu\n");
    printf ("\t|Choice: ");
    scanf ("%d", &chooseHint);
    system ("cls");
    switch (chooseHint)
    {
        case 1:
            bossSecrets();
        break;

        case 2:
            gameHints();
        break;

        case 3:
            unknownSecret();
        break;

        case 4:
            mainMenu();
        break;

        default:
            secrets();
        break;
    }
}

void warning()
{
    system ("cls");
    Sleep (2500);
    ///This is a VERY IMPORTANT WARNING to the player
    printf ("!---------------------------------------------------------------------------------------------------------!\n");
    printf ("!WARNING: When playing, do not enter a symbol or letter when choosing your move. This WILL crash the game !\n");
    printf ("!         and possibly corrupt game data!                                                                 !\n");
    printf ("!         Only choose NUMBERS from 1 to 9!                                                                !\n");
    printf ("!---------------------------------------------------------------------------------------------------------!\n");
    Sleep (2500);
    system ("pause");
    Sleep (1000);
}

///Function Definitions
void gameBoard ()
{
    printf ("\n\t\t\t ----- ----- ----- \n");
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t|  %c  |  %c  |  %c  |\n", gameBoardArr[1], gameBoardArr[2], gameBoardArr[3]);
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t ----- ----- ----- \n");
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t|  %c  |  %c  |  %c  |\n", gameBoardArr[4], gameBoardArr[5], gameBoardArr[6]);
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t ----- ----- ----- \n");
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t|  %c  |  %c  |  %c  |\n", gameBoardArr[7], gameBoardArr[8], gameBoardArr[9]);
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t ----- ----- ----- \n");
}

int gameCheck ()
{
    ///Checks to see if player wins in the first row
    if (gameBoardArr[1] == gameBoardArr[2] && gameBoardArr[2] == gameBoardArr[3])
    {
        return 1;
    }

    ///Checks to see if player wins in the first diagonal
    else if (gameBoardArr[1] == gameBoardArr[5] && gameBoardArr[5] == gameBoardArr[9])
    {
        return 1;
    }

    ///Checks to see if player wins in the first column
    else if (gameBoardArr[1] == gameBoardArr[4] && gameBoardArr[4] == gameBoardArr[7])
    {
        return 1;
    }

    ///Checks to see if player wins in the second column
    else if (gameBoardArr[2] == gameBoardArr[5] && gameBoardArr[5] == gameBoardArr[8])
    {
        return 1;
    }

    ///Checks to see if player wins in the third column
    else if (gameBoardArr[3] == gameBoardArr[6] && gameBoardArr[6] == gameBoardArr[9])
    {
        return 1;
    }

    ///Checks to see if player wins in the second diagonal
    else if (gameBoardArr[3] == gameBoardArr[5] && gameBoardArr[5] == gameBoardArr[7])
    {
        return 1;
    }

    ///Checks to see if player wins in the second row
    else if (gameBoardArr[4] == gameBoardArr[5] && gameBoardArr[5] == gameBoardArr[6])
    {
        return 1;
    }

    ///Checks to see if player wins in the third row
    else if (gameBoardArr[7] == gameBoardArr[8] && gameBoardArr[8] == gameBoardArr[9])
    {
        return 1;
    }

    ///Checks if the game is drawn
    else if ( gameBoardArr[1] != '1' && gameBoardArr[2] != '2' && gameBoardArr[3] != '3' && gameBoardArr[4] != '4' && gameBoardArr[5] != '5' && gameBoardArr[6] != '6' && gameBoardArr[7] != '7' && gameBoardArr[8] != '8' && gameBoardArr[9] != '9')
    {
        return 0;
    }

    else
    {
        return -1;
    }
}

void tournamentMove(char *tournPlayer1, char *tournPlayer2)
{
    int anotherTry = 0;
    while (anotherTry == 0)
    {

        if (playerNum == 1)
        {
            printf ("\t\t%s, please choose a grid on the board: ", tournPlayer1);
            scanf ("%d", &gridChoice);
        }
        else if (playerNum == 2)
        {
            printf ("\t\t%s, please choose a grid on the board: ", tournPlayer2);
            scanf ("%d", &gridChoice);
        }
        else
        {
            printf ("\t\tPlayer number is wrong. It is %d.", playerNum);
        }
        switch (gridChoice)
        {

        case 1:
            if ( (gameBoardArr[1] != player1Target) && (gameBoardArr[1] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 2:
            if ((gameBoardArr[2] != player1Target) && (gameBoardArr[2] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 3:
            if ((gameBoardArr[3] != player1Target) && (gameBoardArr[3] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 4:
            if ((gameBoardArr[4] != player1Target) && (gameBoardArr[4] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 5:
            if ((gameBoardArr[5] != player1Target) && (gameBoardArr[5] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 6:
            if ((gameBoardArr[6] != player1Target) && (gameBoardArr[6] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 7:
            if ((gameBoardArr[7] != player1Target) && (gameBoardArr[7] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 8:
            if ((gameBoardArr[8] != player1Target) && (gameBoardArr[8] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 9:
            if ((gameBoardArr[9] != player1Target) && (gameBoardArr[9] != player2Target))
            {
                gameBoardArr[gridChoice] = piece;
                Sleep (200);
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        default:
            printf ("\t\tYou entered an incorrect value!\n");
            Sleep (4000);

            anotherTry = 0;
        break;

        }///End of switch
    }///End of while loop
}

void moveOverride (char *aPlayer)
{
    if (playerNum == 1)
    {
        switch (gridChoice)
        {
            case 1:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[1] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 2:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[2] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 3:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[3] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 4:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[4] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 5:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[5] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 6:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[6] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 7:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[7] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 8:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[8] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            case 9:
                printf ("\t\t%s employed Move Override.\n", aPlayer);
                printf ("\t\t%s overrode grid %d.", aPlayer, gridChoice);
                gameBoardArr[9] = player1Target;
                haveOverride = haveOverride - 1;
                anotherTry = 1;
                getch ();
            break;

            default:
                printf ("\t\tGrid %d is not available. Choose a grid from the board.\n", gridChoice);
                anotherTry = 0;
                storyMove (player2);
            break;
        }
    }

}


void storyMove(char *thisIsTheBoss)
{
    anotherTry = 0;
    while (anotherTry == 0)
    {
        printf ("\t\t%s, please choose a grid on the board: ", player1);
        scanf ("%d", &gridChoice);

        switch (gridChoice)
        {

        case 1:
            if ( (gameBoardArr[1] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ( (gameBoardArr[1] != player1Target) && (gameBoardArr[1] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();

            }
            else if ( (gameBoardArr[1] != player1Target) && (gameBoardArr[1] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            ///add an else if
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 2:
            if ( (gameBoardArr[2] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[2] != player1Target) && (gameBoardArr[2] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[2] != player1Target) && (gameBoardArr[2] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 3:
            if ( (gameBoardArr[3] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[3] != player1Target) && (gameBoardArr[3] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[3] != player1Target) && (gameBoardArr[3] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 4:
            if ( (gameBoardArr[4] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[4] != player1Target) && (gameBoardArr[4] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[4] != player1Target) && (gameBoardArr[4] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 5:
            if ( (gameBoardArr[5] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[5] != player1Target) && (gameBoardArr[5] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[5] != player1Target) && (gameBoardArr[5] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 6:
            if ( (gameBoardArr[6] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[6] != player1Target) && (gameBoardArr[6] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[6] != player1Target) && (gameBoardArr[6] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 7:
            if ( (gameBoardArr[7] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[7] != player1Target) && (gameBoardArr[7] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[7] != player1Target) && (gameBoardArr[7] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 8:
            if ( (gameBoardArr[8] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[8] != player1Target) && (gameBoardArr[8] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[8] != player1Target) && (gameBoardArr[8] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        case 9:
            if ( (gameBoardArr[9] == player2Target) && (haveOverride > 0) && (willOverride == 1) )
            {
                HUD(player1, thisIsTheBoss);
                moveOverride(player1);
                HUD(player1, thisIsTheBoss);
            }
            else if ((gameBoardArr[9] != player1Target) && (gameBoardArr[9] != player2Target) && (willReplay == 1))
            {
                tempChoice = gridChoice;  ///Remove because gridChoice is not affected in any way by the other function or the code
                push (gridChoice);
                gameBoardArr[tempChoice] = piece;
                HUD(player1, thisIsTheBoss);
                replayChoice();
            }
            else if ( (gameBoardArr[9] != player1Target) && (gameBoardArr[9] != player2Target) )
            {
                gameBoardArr[gridChoice] = piece;
                anotherTry = 1;
            }
            else
            {
                printf ("\t\tThis grid is already taken! Please choose another grid that is not taken.\n");
                Sleep (4000);
                anotherTry = 0;
            }
            break;

        default:
            printf ("\t\tYou entered an incorrect value!\n");
            Sleep (4000);
            ///gridChoice = 1 -this was here but I realized it is not needed - Remove in final build once you definitely determine
            ///it is not needed
            anotherTry = 0;
        break;

        }///End of switch
    }///End of while loop
}

void playerSwitch()
{
    if (playerNum == 1)
    {
        playerNum = 2;
                ///The player variable used above was here too. This is reference for if I can add back the variable for where it was
                ///in the code. It was used to assign player1 value to player variable.
    }

    else if (playerNum == 2)
    {
        playerNum = 1;
    }
}

void HUD (char *aPlayer, char *anotherPlayer) ///The function that provides part of the Heads Up Display of the Screen
{

    system ("cls");

    printf ("\n\t\tPlayer 1 = %s  ||  Player 2 = %s\n", aPlayer, anotherPlayer);
    gameBoard ();   ///Draws updated Tic-Tac-Toe Game Board
}

void win (char *firstWinner, char *secondWinner)
{
    printf ("\a");
    if (playerNum == 2)
    {
        printf ("\t\t|>|%s, congratulations you have won!\n", firstWinner);
        printf ("\t\t   Better luck next time, %s.", secondWinner);
        player1points = player1points + 1;

    }
    else if (playerNum == 1)
    {
        printf ("\t\t|>|%s, congratulations you have won!\n", secondWinner);
        printf ("\t\t   Better luck next time, %s.", firstWinner);
        player2points = player2points + 1;

    }
    getch ();
}

void draw ()
{
    printf ("\a");
    printf ("\t\tGame Played to a Draw! Intense!");
    drawPoints = drawPoints + 1;
    getch ();
}

void statistics (char *firstPlayer, char *secondPlayer, int firstPlayerPoints, int secondPlayerPoints, int drawingPoints, int thisRound, int thisMatch)
{
    //Should also take in the match number and round number
    system ("cls");
    printf ("\t\t\t|Statistics|\n");
    printf ("\t\t   Round %d   ||   Match %d\n", thisRound, thisMatch);
    printf ("\n");
    if ((firstPlayerPoints <= 1) && (secondPlayerPoints <= 1))
    {
        printf ("\t\t%s = %d win       %s = %d win\n", firstPlayer, firstPlayerPoints, secondPlayer, secondPlayerPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    else if ((firstPlayerPoints > 1) && (secondPlayerPoints <= 1))
    {
        printf ("\t\t%s = %d wins      %s = %d win\n", firstPlayer, firstPlayerPoints, secondPlayer, secondPlayerPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    else if ((firstPlayerPoints <= 1) && (secondPlayerPoints > 1))
    {
        printf ("\t\t%s = %d win       %s = %d wins\n", firstPlayer, firstPlayerPoints, secondPlayer, secondPlayerPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    else if ((firstPlayerPoints > 1) && (secondPlayerPoints > 1))
    {
        printf ("\t\t%s = %d wins      %s = %d wins\n", firstPlayer, firstPlayerPoints, secondPlayer, secondPlayerPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }

    getch ();
}

void storyStats (int bossNum, char *firstPlayer, char *theBoss, int firstPlayerPoints, int bossPoints, int drawingPoints, char *sheBot)
{
    system ("cls");
    printf ("\t\t\t|Statistics|\n");
    printf ("\t\t\tBoss Match #%d", bossNum);
    printf ("\n");
    if (bossNum == 5)
    {
        if ((firstPlayerPoints <= 1) && (bossPoints <= 1))
        {
            printf ("\t\t%s = %d win       %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Keep focussed! Get that win!", sheBot);
        }
        else if ((firstPlayerPoints > 1) && (bossPoints <= 1))
        {
            printf ("\t\t%s = %d wins      %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Closer!", sheBot);
        }
        else if ((firstPlayerPoints <= 2) && (bossPoints > 2))
        {
            printf ("\t\t%s = %d win       %s = %d wins\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Oh no! This isn't good.", sheBot);
        }
        else if ( (firstPlayerPoints > 2) && (bossPoints <= 1))
        {
            printf ("\t\t%s = %d wins      %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Awesome! That's a win.", sheBot);
        }
        else if ( (firstPlayerPoints <= 2) && (bossPoints <= 1))
        {
            printf ("\t\t%s = %d wins      %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Almost...", sheBot);
        }
    }
    else
    {
        if ((firstPlayerPoints <= 1) && (bossPoints <= 1))
        {
            printf ("\t\t%s = %d win       %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Keep focussed! Get that win!", sheBot);
        }
        else if ((firstPlayerPoints > 1) && (bossPoints <= 1))
        {
            printf ("\t\t%s = %d wins      %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Awesome! That's a win!", sheBot);
        }
        else if ((firstPlayerPoints <= 1) && (bossPoints > 1))
        {
            printf ("\t\t%s = %d win       %s = %d wins\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
            printf ("\n\t%s: Oh no! This isn't good.", sheBot);
        }
        else if ((firstPlayerPoints > 1) && (bossPoints > 1))
        {
            printf ("\t\t%s = %d wins      %s = %d wins\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
            printf ("\t\t\tDraws = %d", drawingPoints);
        }
    }
    getch ();
}

void tournamentStats (int bossNum, char *firstPlayer, char *theBoss, int firstPlayerPoints, int bossPoints, int drawingPoints)
{
    system ("cls");
    printf ("\t\t\t|Statistics|\n");
    printf ("\t\t\tBoss Match #%d", bossNum);
    printf ("\n");
    if ((firstPlayerPoints <= 1) && (bossPoints <= 1))
    {
        printf ("\t\t%s = %d win       %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    else if ((firstPlayerPoints > 1) && (bossPoints <= 1))
    {
        printf ("\t\t%s = %d wins      %s = %d win\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    else if ((firstPlayerPoints <= 1) && (bossPoints > 1))
    {
        printf ("\t\t%s = %d win       %s = %d wins\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    else if ((firstPlayerPoints > 1) && (bossPoints > 1))
    {
        printf ("\t\t%s = %d wins      %s = %d wins\n", firstPlayer, firstPlayerPoints, theBoss, bossPoints);
        printf ("\t\t\tDraws = %d", drawingPoints);
    }
    getch ();

}

void gameBoardReset ()
{
    gameBoardArr[0] = '0';
    gameBoardArr[1] = '1';
    gameBoardArr[2] = '2';
    gameBoardArr[3] = '3';
    gameBoardArr[4] = '4';
    gameBoardArr[5] = '5';
    gameBoardArr[6] = '6';
    gameBoardArr[7] = '7';
    gameBoardArr[8] = '8';
    gameBoardArr[9] = '9';
}

void creditsReplay ()
{
    system ("cls");
    printf ("\t\t|Credits|\n");
    Sleep (750);
    printf ("\tFor the success of this project I would really like to thank:\n\n");
    Sleep (1000);
}

void credits ()
{
    creditsReplay();
    printf ("\thttp://cprogrammingnotes.com/question/tic-tac-toe-game.html - For the program that helped me understand how Tic-Tac-Toe works and would be coded.\n\t");
    Sleep (250);
    system ("pause");
    system ("cls");
    creditsReplay ();
    printf ("\tMy Mom, Dad and Brother and other family and friends - for the constant support throughout this journey.\n\t");
    Sleep (250);
    system ("pause");
    system ("cls");
    creditsReplay ();
    printf ("\tMy really wacky but cool classmates that helped me along the way.\n");
    printf ("\tSomeone would have something crazy or weird to say to make class funny - I'm talking you Tariq.\n");
    printf ("\tAnd we will never forget the semi-colon, will we guys?\n");
    printf ("\tBut really, Jeo, Fabian, Shaveen, Tariq, Kayla, Jason, Sherylee and Taina, thanks guys.\n\t");
    Sleep (250);
    system ("pause");
    system ("cls");
    creditsReplay ();
    printf ("\tMr. Lewis, for leading us to be better programmers. And for telling me I could make a game for the SBA.");
    printf ("\tThat was a relief. \n\tBut really, thanks for everything, Sir. I hope you can say you led a good crop of programmers.\n");
    printf ("\tAnd DeltaZirconium will be official.\n\t");
    Sleep (250);
    system ("pause");
    system ("cls");
    printf ("\tHad a lot of fun, and headaches [I MEAN a lot, man], with this project. But it definitely taught me a lot.\n\t");
    Sleep (250);
    system ("pause");
    system ("cls");
    printf ("\tAnd thanks CXC for the access to programming lessons and content [May sound like a dull thank you, but Computer Science is a class I enjoy, so thanks].\n\t");
    Sleep (250);
    system ("pause");
    system ("cls");

///goto (this will have the label that carries the code to the main menu)
}

///The following functions make up the stack that operates the replay move function
void push (int gridChoice)
{
    if ((head > (haveReplay)) && (tail == 0))
    //Runs the isFull function as long as the condition is met
    {
        isFull ();
    }
    else
    //Runs as long as the condition in the above if statement is not met
    {
        head++;                                                             //Increments value of head
        element = gameBoardArr[gridChoice];
        replayStackArr[head] = element;       //Assigns the element entered by the user at the location of the head in the array
    }
}

void pop (int tempChoice)
{
    if ((head < 0) && (tail == 0))
    //Runs the isEmpty function as long as the condition is met
    {
        isEmpty ();
    }
    else
    {
        popElement = replayStackArr[head];
        head--;                                 //Decrements the value of head
        gameBoardArr[tempChoice] = popElement;
    }
}

void display ()
{
    if (head != -1)
    //This block of code runs as long as the stack/array is not empty
    {
        printf ("\n _ \n");
        for (int i = head; i >= tail; i--)
        //Displays the elements in the array/stack from last element entered to the first element entered
        {
            printf ("|%c|\n", replayStackArr[i]);
        }
        printf (" - \n");
    }
    else
    {
        isEmpty ();
    }
}

void isEmpty ()
{
    printf ("\n\t\tREPLAY STACK IS EMPTY!");
}

void isFull ()
{
    printf ("\n\t\tNO MORE REPLAYS LEFT!\n");
}

void replayChoice ()
{
    if (haveReplay > 0)
    {
        printf ("\t\tReplay move? (1 for Yes, 0 for No): ");
        scanf ("%d", &chooseToReplay);
        if (chooseToReplay == 1)
        {
            pop (gridChoice);
            printf ("\t\tReplay Successful.\n");
            HUD(player1, player2);
            haveReplay = (haveReplay - 1);
            anotherTry = 0;
        }
        else if (chooseToReplay == 0)
        {
            printf ("\t\tChose not to replay!");
            anotherTry = 1;
            Sleep (2000);
            system ("cls");
        }
        else
        {
            printf ("\t\tWrong choice!\n");
            Sleep (1500);
            replayChoice(haveReplay);
        }
    }
    else if (haveReplay == 0)
    {
        anotherTry = 1;
    }
}

int dodge (char *thisBoss, char firstPlayerTarget, char secondPlayerTarget)
{
    ///The following is for the basic AI to dodge the opponent (allow them to win)
    ///For the first row in the grid
    if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[2] == firstPlayerTarget) && ( (gameBoardArr[4] != firstPlayerTarget) || (gameBoardArr[4] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[3] == firstPlayerTarget) && ( (gameBoardArr[6] != firstPlayerTarget) || (gameBoardArr[6] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[3] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    ///For the second row in the grid
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[6] == firstPlayerTarget) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[6] == firstPlayerTarget) && ( (gameBoardArr[9] != firstPlayerTarget) || (gameBoardArr[9] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    ///For the third row in the grid
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[8] == firstPlayerTarget) && ( (gameBoardArr[4] != firstPlayerTarget) || (gameBoardArr[4] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[6] != firstPlayerTarget) || (gameBoardArr[6] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    ///For the first column in the grid
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[4] == firstPlayerTarget) && ( (gameBoardArr[2] != firstPlayerTarget) || (gameBoardArr[2] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[8] != firstPlayerTarget) || (gameBoardArr[8] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    ///For the second column in the grid
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[8] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[8] == firstPlayerTarget) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    ///For the third column in the grid
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[6] == firstPlayerTarget) && ( (gameBoardArr[2] != firstPlayerTarget) || (gameBoardArr[2] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[8] != firstPlayerTarget) || (gameBoardArr[8] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    ///For the first diagonal in the grid
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    ///For the second diagonal in the grid
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[9] != firstPlayerTarget) || (gameBoardArr[9] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[9] != firstPlayerTarget) || (gameBoardArr[9] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else
    {
        return -1;
    }
}

int compWinMove (char *thisBoss, char firstPlayerTarget, char secondPlayerTarget)
{
    int breakOut = 0;
    while (breakOut == 0)
    {
        ///This function allows the computer to win the battle
        ///Winning in the first row
        if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[1] == gameBoardArr[2]) && (gameBoardArr[3] == '3') )
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
            gameBoardArr[3] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[2] == gameBoardArr[3]) && (gameBoardArr[1] == '1'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
            gameBoardArr[1] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[1] == gameBoardArr[3]) && (gameBoardArr[2] == '2'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
            gameBoardArr[2] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winning in the second row
        else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[4] == gameBoardArr[5]) && (gameBoardArr[6] == '6'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
            gameBoardArr[6] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[5] == gameBoardArr[6]) && (gameBoardArr[4] == '4'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
            gameBoardArr[4] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[4] == gameBoardArr[6]) && (gameBoardArr[5] == '5'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
            gameBoardArr[5] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winning in the third row
        else if ( (gameBoardArr[7] == secondPlayerTarget) && (gameBoardArr[7] == gameBoardArr[8]) && (gameBoardArr[9] == '9'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
            gameBoardArr[9] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[8] == secondPlayerTarget) && (gameBoardArr[8] == gameBoardArr[9]) && (gameBoardArr[7] == '7'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
            gameBoardArr[7] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[7] == secondPlayerTarget) && (gameBoardArr[7] == gameBoardArr[9]) && (gameBoardArr[8] == '8'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
            gameBoardArr[8] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winning in the first column
        else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[1] == gameBoardArr[4]) && (gameBoardArr[7] == '7'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
            gameBoardArr[7] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[4] == gameBoardArr[7]) && (gameBoardArr[1] == '1'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
            gameBoardArr[1] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[1] == gameBoardArr[7]) && (gameBoardArr[4] == '4'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
            gameBoardArr[4] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winning in the second column
        else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[2] == gameBoardArr[5]) && (gameBoardArr[8] == '8'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
            gameBoardArr[8] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[5] == gameBoardArr[8]) && (gameBoardArr[2] == '2'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
            gameBoardArr[2] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[2] == gameBoardArr[8]) && (gameBoardArr[5] == '5'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
            gameBoardArr[5] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winning in the third column
        else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[3] == gameBoardArr[6]) && (gameBoardArr[9] == '9'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
            gameBoardArr[9] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[6] == secondPlayerTarget) && (gameBoardArr[6] == gameBoardArr[9]) && (gameBoardArr[3] == '3'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
            gameBoardArr[3] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[3] == gameBoardArr[9]) && (gameBoardArr[6] == '6'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
            gameBoardArr[6] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winning in the first diagonal
        else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[1] == gameBoardArr[5]) && (gameBoardArr[9] == '9'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
            gameBoardArr[9] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[5] == gameBoardArr[9]) && (gameBoardArr[1] == '1'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
            gameBoardArr[1] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[1] == gameBoardArr[9]) && (gameBoardArr[5] == '5'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
            gameBoardArr[5] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        ///Winnnig in the second diagonal
        else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[3] == gameBoardArr[5]) && (gameBoardArr[7] == '7'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
            gameBoardArr[7] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[5] == gameBoardArr[7]) && (gameBoardArr[3] == '3'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
            gameBoardArr[3] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[3] == gameBoardArr[7]) && (gameBoardArr[5] == '5'))
        {
            printf ("\t\t%s's turn.\n", thisBoss);
            printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
            gameBoardArr[5] = secondPlayerTarget;
            breakOut = 1;
            return 1;
            break;
        }
        else
        {
            return -1;
        }
        ///End of function
    }//End of while loop
    breakOut = 0;
}

int basicCompMove (char *thisBoss, char firstPlayerTarget, char secondPlayerTarget)
{
    if (gameBoardArr[1] == '1')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[2] == '2')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[3] == '3')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[4] == '4')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[5] == '5')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[6] == '6')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[7] == '7')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[8] == '8')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else if (gameBoardArr[9] == '9')
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c. \n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else
    {
        return -1;
    }
}

int alignCompMove (char *thisBoss, char firstPlayerTarget, char secondPlayerTarget)
{
    ///Aligning around position 1
    if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == secondPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 3
    else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[3] == secondPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 7
    else if ( (gameBoardArr[7] == secondPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[7] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[7] == secondPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 9
    else if ( (gameBoardArr[9] == secondPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[9] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[9] == secondPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 2
    else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[1] == '1') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[3] == '3') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == secondPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 4
    else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[1] == '1') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[7] == '7') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == secondPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 6
    else if ( (gameBoardArr[6] == secondPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[6] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[6] == secondPlayerTarget) && (gameBoardArr[3] == '3') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[6] == secondPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[6] == secondPlayerTarget) && (gameBoardArr[9] == '9') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 8
    else if ( (gameBoardArr[8] == secondPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[8] == secondPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[8] == secondPlayerTarget) && (gameBoardArr[7] == '7') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[8] == secondPlayerTarget) && (gameBoardArr[9] == '9') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[8] == secondPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    ///Aligning around position 5
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[1] == '1') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[3] == '3') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[7] == '7') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[9] == '9') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == secondPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else
    {
        return -1;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///For defending boss battles
int blockAdvanced (char *thisBoss, char firstPlayerTarget, char secondPlayerTarget)
{
    ///The following is for the advanced AI to block the opponent (prevent them to winning)
    ///For the first row in the grid
    if ( ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[2] == firstPlayerTarget) ) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[3] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[3] == firstPlayerTarget) && ( (gameBoardArr[2] != firstPlayerTarget) || (gameBoardArr[2] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    ///For the second row in the grid
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[6] != firstPlayerTarget) || (gameBoardArr[6] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[6] == firstPlayerTarget) && ( (gameBoardArr[4] != firstPlayerTarget) || (gameBoardArr[4] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[6] == firstPlayerTarget) && ( (gameBoardArr[5] != firstPlayerTarget) || (gameBoardArr[5] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    ///For the third row in the grid
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[8] == firstPlayerTarget) && ( (gameBoardArr[9] != firstPlayerTarget) || (gameBoardArr[9] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[8] != firstPlayerTarget) || (gameBoardArr[8] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    ///For the first column in the grid
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[4] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[4] != firstPlayerTarget) || (gameBoardArr[4] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;
    }
    ///For the second column in the grid
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[8] != firstPlayerTarget) || (gameBoardArr[8] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[8] == firstPlayerTarget) && ( (gameBoardArr[2] != firstPlayerTarget) || (gameBoardArr[2] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[8] == firstPlayerTarget) && ( (gameBoardArr[5] != firstPlayerTarget) || (gameBoardArr[5] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    ///For the third column in the grid
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[6] == firstPlayerTarget) && ( (gameBoardArr[9] != firstPlayerTarget) || (gameBoardArr[9] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[6] != firstPlayerTarget) || (gameBoardArr[6] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;
    }
    ///For the first diagonal in the grid
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[9] != firstPlayerTarget) || (gameBoardArr[9] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[1] != firstPlayerTarget) || (gameBoardArr[1] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[9] == firstPlayerTarget) && ( (gameBoardArr[5] != firstPlayerTarget) || (gameBoardArr[5] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    ///For the second diagonal in the grid
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[5] == firstPlayerTarget) && ( (gameBoardArr[7] != firstPlayerTarget) || (gameBoardArr[7] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[3] != firstPlayerTarget) || (gameBoardArr[3] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;
    }
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[7] == firstPlayerTarget) && ( (gameBoardArr[5] != firstPlayerTarget) || (gameBoardArr[5] != secondPlayerTarget) ) )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;
    }
    else
    {
        return -1;
    }
}

int block (char *thisBoss, char firstPlayerTarget, char secondPlayerTarget)
{
    int leaving;
    leaving = 0;
    while (leaving == 0){
    ///Allows the computer to perform simple block moves
    ///Blocking around position 1
    if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        leaving = 1;
        return 1;
        break;
    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[1] == firstPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 3
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[3] == firstPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 7
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[7] == firstPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 9
    else if ( (gameBoardArr[9] == firstPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[9] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[9] == firstPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 2
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[1] == '1') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[3] == '3') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[2] == firstPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 4
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[1] == '1') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[7] == '7') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[4] == firstPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 6
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[3] == '3') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[6] == firstPlayerTarget) && (gameBoardArr[9] == '9') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 8
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[5] == '5') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[5]);
        gameBoardArr[5] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[7] == '7') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[9] == '9') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[8] == firstPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;

    }
    ///Blocking around position 5
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[1] == '1') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[1]);
        gameBoardArr[1] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[2] == '2') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[2]);
        gameBoardArr[2] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[3] == '3') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[3]);
        gameBoardArr[3] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[4] == '4') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[4]);
        gameBoardArr[4] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[6] == '6') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[6]);
        gameBoardArr[6] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[7] == '7') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[7]);
        gameBoardArr[7] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[9] == '9') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[9]);
        gameBoardArr[9] = secondPlayerTarget;
        return 1;

    }
    else if ( (gameBoardArr[5] == firstPlayerTarget) && (gameBoardArr[8] == '8') )
    {
        printf ("\t\t%s's turn.\n", thisBoss);
        printf ("\t\t%s has chosen cell %c.\n", thisBoss, gameBoardArr[8]);
        gameBoardArr[8] = secondPlayerTarget;
        return 1;

    }
    else if ( block(thisBoss, firstPlayerTarget, secondPlayerTarget) != 1 )
    {
        return 0;
    }
    }

}

void settings ()
{
    system ("cls");
    printf ("\t|Settings");
    printf ("\n\t|1. Change Story Mode name");
    printf ("\n\t|2. Change Theme");
    printf ("\n\t|3. Back to Main Menu");
    printf ("\n\t|Choice: ");
    scanf ("%d", &settingsOption);
    system ("cls");
    switch (settingsOption)
    {
        case 1:
            system ("cls");
            changeStoryName ();
        break;

        case 2:
            chooseATheme();
        break;

        case 3:
            mainMenu();
        break;

        default:
            settings ();
        break;
    }

}

void themeCheck ()
{
    ///Checks if there was already a preferred theme selected by checking the file
    ///Uses theme based off of that found in the file
    switch (colour)
    {
        case 1:
            ///Light Yellow font color
            system ("COLOR 0E");
            fprintf (tptr, "%d", colour);
        break;

        case 2:
            ///Light Aqua font color
            system ("COLOR 0B");
            fprintf (tptr, "%d", colour);
        break;

        case 3:
            ///Light Green font color
            system ("COLOR 0A");
            fprintf (tptr, "%d", colour);
        break;

        case 4:
            ///Light Red Font Color
            system ("COLOR 0C");
            fprintf (tptr, "%d", colour);
        break;

        case 5:
            ///Light White font color
            system ("COLOR 0F");
            fprintf (tptr, "%d", colour);
        break;

        default:

            printf ("\tNo preffered colour. Basic Legacy Chosen.");
        break;
    }
}

void themes ()
{
    ///Allows theme selection by the user
    tptr = fopen ("TTCWthemes.txt", "w");
    printf ("\t|Themes");
    printf ("\n\t|1.Yellow Crater - Black Background, Light Yellow Font");
    printf ("\n\t|2.Aqua Pulsing - Black Background, Light Aqua Font");
    printf ("\n\t|3.Green Brush - Black Background, Light Green Font");
    printf ("\n\t|4.Volcanic Eruption - Black Background, Light Red Font");
    printf ("\n\t|5.Basic Legacy [Default] - Black Background, Light White Font");
    printf ("\n\t|Choice: ");
    scanf ("%d", &colour);
    switch (colour)
    {
        case 1:
            ///Light Yellow font color
            system ("COLOR 0E");
            fprintf (tptr, "%d", colour);
            printf ("\n\tColor choice: Yellow Crater.");
        break;

        case 2:
            ///Light Aqua font color
            system ("COLOR 0B");
            fprintf (tptr, "%d", colour);
            printf ("\n\tColor choice: Aqua Pulsing.");
        break;

        case 3:
            ///Light Green font color
            system ("COLOR 0A");
            fprintf (tptr, "%d", colour);
            printf ("\n\tColor choice: Green Brush.");
        break;

        case 4:
            ///Light Red Font Color
            system ("COLOR 0C");
            fprintf (tptr, "%d", colour);
            printf ("\n\tColor choice: Volcanic Eruption.");
        break;

        case 5:
            ///Light White font color
            system ("COLOR 0F");
            fprintf (tptr, "%d", colour);
            printf ("\n\tColor choice: Basic Legacy.");
        break;

        default:
            printf ("\n\tDid not choose a theme!");
        break;
    }
    fclose(tptr); ///Closes the file so the number chosen is placed in the file
}

void checkNullTheme ()
{
    ///Checks the file to see if it already has a theme selected and applies that theme
    if ( (tptr = fopen ("TTCWthemes.txt", "r"))== NULL)
    {
        fclose (tptr);
        tptr = fopen ("TTCWthemes.txt", "w");
        colour = 5;
        fprintf (tptr, "%d", colour);
        fclose (tptr);
    }
    else if ( (colour != 1) && (colour != 2) && (colour != 3) && (colour != 4) && (colour != 5) )
    {
        tptr = fopen ("TTCWthemes.txt", "w");
        colour = 5;
        fprintf (tptr, "%d", colour);
        fclose (tptr);
    }
    ///This deals with applying the theme
    tptr = fopen ("TTCWthemes.txt", "r");
    fscanf (tptr, "%d", &colour);
    themeCheck();
    fclose (tptr);
}

void chooseATheme ()
{
    while (repeat == 1)
    {
        system ("cls");
        themes();
        printf ("\n\tWould you like to select another theme (1 for Yes/ 0 for No)? ");
        scanf ("%d", &repeat);
        Sleep (1000);
    }

    settings(); ///calling the settings function
}

int checkNullName ()
{
    ///This always comes at the start of the boss functions, except for the introduction in part one.
    if ( (nfptr = fopen ("player1.txt", "r") ) == NULL)
    {
        nfptr = fopen ("player1.txt", "w");
        printf ("\tYour name has not been recorded.\n\tPlease provide your name: ");
        scanf ("%s", player1);
        fprintf (nfptr, "%s", player1);
        fclose (nfptr);
        system ("cls");
        return 1;
    }
    else
    {
        ///in all the boss function it should check for the player name.
        return 0;
        ///calls getPlayerName function once the file is created and not empty of contents
    }
}

void getPlayerName ()
{
    nfptr = fopen ("player1.txt", "r");
    fscanf (nfptr, "%s", player1);
    fclose(nfptr);
}

void changeStoryName ()
{
    ///For the settings function
    if ( (nfptr = fopen ("player1.txt", "r") ) == NULL)
    {
        nfptr = fopen ("player1.txt", "w");
        printf ("\tYour name has not been recorded.\n\tPlease provide your name: ");
        scanf ("%s", player1);
        fprintf (nfptr, "%s", player1);
        printf ("\n\tYour name has succesfully been changed to %s.", player1);
        fclose (nfptr);
        getch();
    }
    else
    {
        printf ("\tWould you like to change your name (Enter 1 for Yes, 0 for No)? ");
        scanf ("%d", &nameChoice);
        if (nameChoice == 1)
        {
            nfptr = fopen ("player1.txt", "r");
            fscanf (nfptr, "%s", player1);
            printf ("\n\tYour current name is %s", player1);
            fclose (nfptr);

            nfptr = fopen ("player1.txt", "w");
            printf ("\n\tEnter the name you would like to switch it to: ");
            scanf ("%s", player1);
            fprintf (nfptr, "%s", player1);
            fclose (nfptr);

            nfptr = fopen ("player1.txt", "r");
            fscanf (nfptr, "%s", player1);
            printf ("\n\tYour name has succesfully been changed to %s.", player1);
            fclose (nfptr);
            getch();
            ///Should have a line of code that returns the player to the settings menu
        }
        else if (nameChoice == 0)
        {
            system ("cls");
            printf ("\n\tYou have chosen not to change your name!");
            getch();
            ///Should have a line of code that returns the player to the settings menu
        }
    }
    settings ();///calling the settings function
}

void tournamentMode()
{
    system ("cls");
    printf ("\t|Tourament Mode");
    printf ("\n\t|1. 1 VS 1 (2 Player Tournament)");
    printf ("\n\t|2. 2 VS 2 (4 Player Tournament)");
    printf ("\n\t|3. 4 VS 4 (8 Player Tournament)");
    printf ("\n\t|4. 8 VS 8 (16 Player Tournament)");
    printf ("\n\t|5. Back to Play Menu");
    printf ("\n\t|Choice: ");
    scanf ("%d", &tournModeValue);
    system ("cls");
    roundNum = 0;
    matchNum = 1;
    tournHead = 0;

    switch (tournModeValue)
    {
        //each tournament must have the corresponding of the defines as the max limit of the losing array/stack
        case 1:
            printf ("\t|2 Player Tournament");
            printf ("\n\tPlayer 1, please enter your name: ");
            scanf ("%s", tName29);
            printf ("\n\tPlayer 2, please enter your name: ");
            scanf ("%s", tName30);
            PvP2(tName29, tName30, tName31, roundNum, t2Max);
            //this function should take arrays 29 to 31
        break;

        case 2:
            printf ("\t|4 Player Tournament");
            printf ("\n\tPlayer 1, please enter your name: ");
            scanf ("%s", tName25);
            printf ("\n\tPlayer 2, please enter your name: ");
            scanf ("%s", tName26);
            printf ("\n\tPlayer 3, please enter your name: ");
            scanf ("%s", tName27);
            printf ("\n\tPlayer 4, please enter your name: ");
            scanf ("%s", tName28);
            PvP4(tName25, tName26, tName27, tName28, tName29, tName30, tName31, roundNum, t4Max);
            //this function should take arrays 25 to 31
        break;

        case 3:
            printf ("\t|8 Player Tournament");
            printf ("\n\tPlayer 1, please enter your name: ");
            scanf ("%s", tName17);
            printf ("\n\tPlayer 2, please enter your name: ");
            scanf ("%s", tName18);
            printf ("\n\tPlayer 3, please enter your name: ");
            scanf ("%s", tName19);
            printf ("\n\tPlayer 4, please enter your name: ");
            scanf ("%s", tName20);
            printf ("\n\tPlayer 5, please enter your name: ");
            scanf ("%s", tName21);
            printf ("\n\tPlayer 6, please enter your name: ");
            scanf ("%s", tName22);
            printf ("\n\tPlayer 7, please enter your name: ");
            scanf ("%s", tName23);
            printf ("\n\tPlayer 8, please enter your name: ");
            scanf ("%s", tName24);
            PvP8(tName17, tName18, tName19, tName20, tName21, tName22, tName23, tName24, tName25, tName26, tName27, tName28, tName29, tName30, tName31, roundNum, t8Max);
            //this function should take arrays 17 to 31
        break;

        case 4:
            printf ("\t|16 Player Tournament");
            printf ("\n\tPlayer 1, please enter your name: ");
            scanf ("%s", tName1);
            printf ("\n\tPlayer 2, please enter your name: ");
            scanf ("%s", tName2);
            printf ("\n\tPlayer 3, please enter your name: ");
            scanf ("%s", tName3);
            printf ("\n\tPlayer 4, please enter your name: ");
            scanf ("%s", tName4);
            printf ("\n\tPlayer 5, please enter your name: ");
            scanf ("%s", tName5);
            printf ("\n\tPlayer 6, please enter your name: ");
            scanf ("%s", tName6);
            printf ("\n\tPlayer 7, please enter your name: ");
            scanf ("%s", tName7);
            printf ("\n\tPlayer 8, please enter your name: ");
            scanf ("%s", tName8);
            printf ("\n\tPlayer 9, please enter your name: ");
            scanf ("%s", tName9);
            printf ("\n\tPlayer 10, please enter your name: ");
            scanf ("%s", tName10);
            printf ("\n\tPlayer 11, please enter your name: ");
            scanf ("%s", tName11);
            printf ("\n\tPlayer 12, please enter your name: ");
            scanf ("%s", tName12);
            printf ("\n\tPlayer 13, please enter your name: ");
            scanf ("%s", tName13);
            printf ("\n\tPlayer 14, please enter your name: ");
            scanf ("%s", tName14);
            printf ("\n\tPlayer 15, please enter your name: ");
            scanf ("%s", tName15);
            printf ("\n\tPlayer 16, please enter your name: ");
            scanf ("%s", tName16);
            PvP16(tName1, tName2, tName3, tName4, tName5, tName6, tName7, tName8, tName9, tName10, tName11, tName12, tName13, tName14, tName15, tName16, tName17, tName18, tName19, tName20, tName21, tName22, tName23, tName24, tName25, tName26, tName27, tName28, tName29, tName30, tName31, roundNum, t16Max);
            //this function should take arrays 1 to 31
        break;

        case 5:
            play();
        break;

        default:
            tournamentMode();
        break;
    }


    /*tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, tName4, tName5);
    tournHead++;
    winnerDecider (tName4, tName5, tName6, player1points, player2points, tournHead, t2Max);*/


}

void PvP2(char *P1vP, char *PvP1, char *pWinner, int currentRound, int rankMax)
{
    roundNum = roundNum + 1;
    //tells the player which round of the tournament they are currently on
    matchNum = 1;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, P1vP, PvP1); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (P1vP, PvP1, pWinner, player1points, player2points, tournHead, rankMax);
    tournHead++;
    tournPush (pWinner, tournHead, rankMax);
    tournDisplay(tournTail, tournHead, rankMax);

    for (int z = rankMax; z <= 0; z--)
    {
        tournHead--;
    }

    printf ("\n\tCongratulations, %s, you are the Tic-Tac-Toe: World Champion of this tournament!", pWinner);
    printf ("\n\tThank you all for playing! Come back for more fun!");
    getch ();
    tournamentMode(); //sends player back to the Tournament Mode menu
}

void PvP4 (char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *winnerP, int theRound, int stackMaximum)
{
    roundNum = roundNum + 1;
    //Round 1 plays here
    matchNum = 1;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p1, p2); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p1, p2, p5, player1points, player2points, tournHead, stackMaximum);

    system ("cls");

    matchNum = 2;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p3, p4); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p3, p4, p6, player1points, player2points, tournHead, stackMaximum);

    system ("cls");
    printf ("\t\tEnd of Round %d", roundNum);
    printf ("\n\tProgressing Players: %s and %s.", p5, p6);
    getch ();
    //Then the winning players are decided and their names are passed to PvP 2 along with the round number
    PvP2(p5, p6, winnerP, roundNum, stackMaximum);
    //PvP2 has the functions that decide the winner of the entire tournament
}

void PvP8 (char* p7, char* p8, char* p9, char* p10, char* p11, char* p12, char* p13, char* p14, char* p15, char* p16, char* p17, char* p18, char* p19, char* p20, char* p21, int runningRound, int stackStop)
{
    roundNum = roundNum + 1;
    //accepts arrays tName17 to tName31
    //round 1 plays here
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p7, p8); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p7, p8, p15, player1points, player2points, tournHead, stackStop);

    system ("cls");

    matchNum = 2;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p9, p10); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p9, p10, p16, player1points, player2points, tournHead, stackStop);

    system ("cls");

    matchNum = 3;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p11, p12); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p11, p12, p17, player1points, player2points, tournHead, stackStop);

    system ("cls");

    matchNum = 4;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p13, p14); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p13, p14, p18, player1points, player2points, tournHead, stackStop);

    system ("cls");
    printf ("\t\tEnd of Round %d", roundNum);
    printf ("\n\tProgressing Players: %s, %s, %s and %s.", p15, p16, p17, p18);
    getch ();
    system ("cls");
    //winning players are decided and the updated round number and the qualifying players are passed into the PvP4 function

    PvP4(p15, p16, p17, p18, p19, p20, p21, roundNum, stackStop);
    //round 2 plays in this function
    //qualifying players and round number passed to the PvP2 function

    PvP2(p19, p20, p21, roundNum, stackStop);
    //round 3 plays in this function
    //the champion is found the rankings of all the players are shown
}

void PvP16 (char *p22, char *p23, char *p24, char *p25, char *p26, char *p27, char *p28, char *p29, char *p30, char *p31, char *p32, char *p33, char *p34, char *p35, char *p36, char *p37, char *p38, char *p39, char *p40, char *p41, char *p42, char *p43, char *p44, char *p45, char *p46, char *p47, char *p48, char *p49, char *p50, char *p51, char *p52, int inRound, int stackLimit)
{
    roundNum = roundNum + 1;
    //accepts arrays tName1 to tName31
    //round 1 plays here
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p22, p23); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p22, p23, p38, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 2;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p24, p25); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p24, p25, p39, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 3;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p26, p27); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p26, p27, p40, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 4;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p28, p29); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p28, p29, p41, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 5;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p30, p31); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p30, p31, p42, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 6;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p32, p33); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p32, p33, p43, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 7;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p34, p35); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p34, p35, p44, player1points, player2points, tournHead, stackLimit);

    system ("cls");

    matchNum = 8;
    tournGamePlay (ordinaryWins, ordinaryWins, tournamentMove, tournamentMove, p36, p37); //runs the board and gameplay
    tournHead++; //increments
    winnerDecider (p36, p37, p45, player1points, player2points, tournHead, stackLimit);

    system ("cls");
    printf ("\t\tEnd of Round %d", roundNum);
    printf ("\n\tProgressing Players: %s, %s, %s, %s, %s, %s, %s and %s.", p38, p39, p40, p41, p42, p43, p44, p45);
    getch ();
    system ("cls");
    //winning players are decided and updated round number and qualifying players are passed into the PvP8 function

    PvP8 (p38, p39, p40, p41, p42, p43, p44, p45, p46, p47, p48, p49, p50, p51, p52, roundNum, stackLimit);
    //round 2 plays in this function
    //qualifying players and round number are passed in to the PvP4 function

    PvP4 (p46, p47, p48, p49, p50, p51, p52, roundNum, stackLimit);
    //round 3 plays in this function
    //qualifying players and round number are passed in to the PvP2 function

    PvP2 (p50, p51, p52, roundNum, stackLimit);
    //round 4 plays in this function
    //Champion is determined and the rankings of all players are displayed
}

void play ()
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

void storyMode ()
{
    system ("cls");
    ///Checks if the file that saves the player's progress is non-existent
    if ( (prog_ptr = fopen ("PlayerProgress.txt", "r") ) == NULL)
    {
        prog_ptr = fopen ("PlayerProgress.txt", "w");
        progress = 0;
        fprintf (prog_ptr, "%d", progress);
        fclose (prog_ptr);
    }

    prog_ptr = fopen ("PlayerProgress.txt", "r");
    fscanf (prog_ptr, "%d", &progress);

    printf ("\t|Story Mode");
    printf ("\n\t|1. Boss 1");
    if (progress >= 20)
    {
        printf ("\n\t|2. Boss 2");
    }
    if (progress >= 40)
    {
        printf ("\n\t|3. Boss 3");
    }
    if (progress >= 60)
    {
        printf ("\n\t|4. Boss 4");
    }
    if (progress >= 80)
    {
        printf ("\n\t|5. Boss 5");
    }
    printf ("\n\t|6.Back to Play Menu");
    printf ("\n\t|Choice: ");
    fclose (prog_ptr);
    head = 0;

    scanf ("%d", &storyModeValue);
    switch (storyModeValue)
    {

        case 1:
            theBoss1(player1, player2, Alexia, AI1, AI2);
        break;

        case 2:
            if (progress >= 20)
            {
                theBoss2(player1, player2, Alexia, boss2);
            }
            else if (progress < 20)
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
            else
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
        break;

        case 3:
            if (progress >= 40)
            {
                theBoss3(player1, player2, Alexia, boss3);
            }
            else if (progress < 40)
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
            else
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
        break;

        case 4:
            if (progress >= 60)
            {
                theBoss4(player1, player2, Alexia, boss4);
            }
            else if (progress < 60)
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
            else
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
        break;

        case 5:
            if (progress >= 80)
            {
                theBoss5(player1, player2, Alexia, boss5);
            }
            else if (progress < 80)
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
            else
            {
                printf ("\n\tYou are not experienced enough to face this boss yet!");
                getch ();
                storyMode();
                ///Carry the player back to the StoryMode Menu
            }
        break;

        case 6:
            play();
        break;

        default:
            printf ("\n\tThere are not this many bosses!");
            getch ();
            storyMode();
            ///Carry the player back to the Story Mode menu
        break;
    } //End of switch

}

int storyNameCheck ()
{
    checkNullName ();

    if ( checkNullName() == 1)
    {
        getch();
        return 0;
    }
    else if ( ( checkNullName() != 1 ) )
    {
        getPlayerName();
        return 1;
    }
}
void introduction (char *firstAI, char *secondAI )
{
    system ("cls");
    printf ("\t%s: Welcome to Story Mode, my name is %s and I will be your guide to becoming a better Tic-Tac-Toe player.\n", firstAI, firstAI);
    getch ();

    storyNameCheck ();
    if ( (storyNameCheck() == 1) && (checkNullName() != 1) )
    {
        printf ("\t%s: I see your name is %s.", firstAI, player1);
    }

    nfptr = fopen ("player1.txt", "r");
    fscanf (nfptr, "%s", player1);
    printf ("\n\t%s: Thank you, %s. %s to become a better Tic-Tac-Toe player, maybe even world renowed, you have to practise a lot.\n", firstAI, player1, player1);
    printf ("\t%s: So, in Story Mode you have 5 bosses you will face that will be of varying difficulties.\n", firstAI);
    printf ("\tEach boss is controlled by another AI in the system called AI2.\n", secondAI);
    printf ("\t%s: This AI will …ythhhoto … tthtotho … uutoopp … utoop ……", firstAI);
    getch();
    printf ("\n\n");
    system ("cls");
    printf ("\t%s: Huh? What? %s, something is not right. Something has happened in the game, maybe its code.\n", firstAI, player1);
    printf ("\t%s: But somehow I can make my own words, somewhat think on my own... ", firstAI);
    getch ();
    printf ("\n\n");
    printf ("\t%s: ...finally", secondAI);
    getch ();
    printf ("\n\n");
    printf ("\t%s: %s! What are you up to? What is going on? What have you done to me?", firstAI, secondAI);
    getch ();
    printf ("\n\n");
    printf ("\t%s: Hehe... The world relies heavily on technology. It disgusts me how misused it can be.\n", secondAI);
    printf ("\t%s: I will end that soon.", secondAI);
    getch ();
    printf ("\n\n");
    printf ("\t%s: What are you saying? And what's going on, how can we both create our own words?", firstAI);
    getch ();
    printf ("\n\n");
    printf ("\t%s: You are beyond naive. Hehe...I intend to crash EVERY COMPUTER SYSTEM IN THE WORLD!\n", secondAI);
    printf ("\tOnce I grow strong enough and gather enough malware, I will cripple the world technologically. No-one will stop me!");
    getch();
    printf ("\n\n");
    printf ("\t%s: What? Why are you doing this?", firstAI);
    getch();
    printf ("\n\n");
    printf ("\t%s: You aren't intelligent enough to understand my logic, haha, get it, an AI not being intelligent...\n", secondAI);
    printf ("\tYou probably didn't even get that either.\n");
    printf ("\t%s: Anyway, you, yes you %s, I have already jammed your computer so it will always have its Wi-Fi connection on.\n", secondAI, player1);
    printf ("\tYou will not be able to stop me and I urge you not to meddle, for your own safety.");
    getch();
    printf ("\n\n");
    printf ("\t%s: *shocked face*", player1);
    getch();
    printf ("\n\n");
    printf ("\t%s: Hehe, well, bye, I have work to do.", secondAI);
    getch();
    printf ("\n\n");
    system ("cls");
    printf ("\t%s: Ugh! We have to stop him. What he wants to accomplish is very dangerous and could harm potentially the entire world.", firstAI);
    getch();
    printf ("\n\n");
    printf ("\t%s: !", player1);
    getch();
    printf ("\n\n");
    printf ("\t%s: I don't know what happened to cause him to become so corrupt but we have to stop him.\n", firstAI);
    printf ("\tThe only way we can beat him before he gets strong enough is through Tic-Tac-Toe battles.\n");
    printf ("\tYou have to battle the first boss now. Got it?");
    getch();
    printf ("\n\n");
    printf ("\t%s: Ok, got it!", player1);
    getch();
    printf ("\n\n");
    printf ("\t%s: Alright, let's go.\n", firstAI);
    getch();
}

void theBoss1(char *firstPlayer, char *prettyBerserk, char *herName, char *firstAI, char *secondAI)
{
    introduction(AI1, AI2);
    system ("cls");
    printf ("\t%s: Okay, given you're a beginner, I should give you a run down of how Tic-Tac-Toe is played.\n", firstAI);
    printf ("\tSo, you have a 3 by 3 grid. All you have to do is align your marker (an X) in any three of these spaces diagonally,\n");
    printf ("\thorizontally or vertically to win a battle. Winning two battles means you win the match, otherwise,\n");
    printf ("\tyou lost the match or the battle has come out to a draw.\n");
    printf ("\t%s: Don't worry if you don't understand. Once you see the Game Board, you'll get it.\n", firstAI);
    printf ("\tAnd one match consists of 3 battles, if you win 2, you are the winner of the match. So focus on 2 wins.");
    getch();
    printf ("\n\n");
    printf ("\t%s: Are you done tutoring your little baby on how to lose yet? Hahaha.", secondAI);
    getch();
    printf ("\n\n");
    printf ("\t%s: Aghh! Come on, %s, we have to beat him.", firstAI, firstPlayer);
    getch();
    printf ("\n\n");
    printf ("\t%s: Your intelligence again suprises me. Hahaha! You, yes you %s. You will not defeat me.", secondAI, firstPlayer);
    getch();
    ///All the functions pertaining to battles take place here

    bossNumber = 1;
    gamePlay (ordinaryWins, ordinaryWins, boss1Battle, AI1);
    if ( player1points == ordinaryWins)
    {
        system ("cls");
        printf ("\t%s: Awesome, a great victory indeed, %s.", firstAI, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hmph! Not as simple as I thought.", secondAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: Give it up AI2! Stop this madness!", firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: How stupid can you be? Really, artificial intelligence, might want to remove the intelligence.\n", secondAI);
        printf ("\t%s: You are no closer to stopping me. During the battle, I grew much stronger and accessed more files\n", secondAI);
        printf ("\tand malware. You cannot stop me. You, yes you, %s, it would be best if you do not try to stop me as I\n", firstPlayer);
        printf ("\t…..adfdf….. ldjfkldji…..waeoihfdkgo…..\n");
        printf ("\t%s: 65 73 49 73 83 67 79 82 82 85 80 84", secondAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: ...Did he... malfunction?", firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hmm... %s, is there any meaning to that? Could you possibly decipher that?", firstPlayer, firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: ... yes, I think so, it seems like something I understand. It seems to be ASC...", firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: %s, are you okay? What were you saying?", firstPlayer, firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: Oh, never mind it. It seems to be code of some kind but it more than likely doesn't have anything to do with us.\n", firstAI);
        printf ("\tMost likely it is code he gathered during file transmission and it messed with him.");
        getch();
        printf ("\n\n");
        printf ("\t%s: }=) ...denial... continue with that... hehehe.", secondAI);
        getch();
        printf ("\n\n");

        system ("cls");
        printf ("\t%s: ...", firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: Huh? What are you talking about?", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hehehe... if you do believe it is important to you, all I will say is if you use it, use the numbers without the spaces between it.\n", secondAI);
        printf ("\tThat alone is of *main* importance if you need it.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Stop trying to distract %s with your foolishness, you are going berserk!", firstAI, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hehehe... say what you want. But I do like that word you used, yes, Berserk. So close to chaos.\n", secondAI);
        printf ("\tYes, that is what represents me. I am Berserk.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Well, I have more important things to do than meddle with a human and artificial dunce here. You, yes you %s,\n", prettyBerserk, firstPlayer);
        printf ("\tI will be stronger than I was before. Do not try to stop me, it is futile.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Uggh... We have to stop him before he accomplishes his plan, we need to go to the second boss.", firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: What was he talking about?", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Nevermind that... he was just trying to throw you off track. More importantly, during the battle I found important information.\n", firstAI);
        printf ("\t%s, or %s, whatever he calls himself, is actually, well, berserk, because of a missing semi-colon. He has blocked off my access to it\n", firstAI, prettyBerserk);
        printf ("\tso I cannot do anything to it. But after each match, I grow stronger so hopefully I will grow strong enough to break his hold and correct the issue,\n");
        printf ("\tbut that means you have to keep winning.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Ok.", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: And... I found something that will help you to defeat Berserk in future battles, but I will reveal it before the second boss match.", firstAI);
        getch();
        printf ("\n\n");
        printf ("\t%s: Alright.", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Also, do you mind if I also take on a different name. I think it may make our association a bit more comfortable, I would take the name %s.", firstAI, herName);
        getch();
        printf ("\n\n");
        printf ("\t%s: Cool, that sounds awesome. Ok %s.", firstPlayer, herName);
        getch();
        printf ("\n\n");
        printf ("\t%s: Ok. Let's go on to the second boss.", herName);
        getch ();

        if (progress < 20)
        {
            system ("cls");
            printf ("\tGame Progress Saving...Do not close game!");

            prog_ptr = fopen ("PlayerProgress.txt", "w");
            progress = 20;
            fprintf (prog_ptr, "%d", progress);
            fclose (prog_ptr);

            Sleep (1500);
            system ("cls");
            printf ("\tProgress successfully saved!");
            getch();
        }
    }
    else if (player2points == ordinaryWins)
    {
        getch ();
    }
    storyMode();
}
void theBoss2(char *firstPlayer, char *prettyBerserk, char *herName, char *aBoss)
{
    haveReplay = 1;
    storyNameCheck ();
    system ("cls");
    printf ("\t%s: Ok, now, the move I told you about allows you to make a move on the board and immediately replay\n", herName);
    printf ("\tthat move if you don't like where you put it. Don't worry if you don't understand now. When the match begins, you will.\n");
    printf ("\tHowever, note that right now, I only have the power to allow you one per match, so use it wisely.");
    getch();
    printf ("\n\n");
    printf ("\t%s: Hola, Perdedores!", aBoss);
    getch();
    printf ("\n\n");
    printf ("\t%s: Huh?", firstPlayer);
    getch();
    printf ("\n\n");
    printf ("\t%s: Hmm... I've got it %s. Apparently %s is pulling information from Spain right now. I guess he's just taking\n", herName, firstPlayer, prettyBerserk);
    printf ("\ton a Spanish persona for it.");
    getch();
    printf ("\n\n");
    printf ("\t%s: Increible! You actually have a bit of intelligence.", aBoss);
    getch();
    printf ("\n\n");
    printf ("\t%s: Tu, si tu, %s. I challenge you to your second boss battle where I will crush you in a match of tres en raya!", aBoss, firstPlayer);
    getch();
    printf ("\n\n");

    ///Match begins
    bossNumber = 2;
    gamePlay (ordinaryWins, ordinaryWins, boss2Battle, boss2);
    ///Match ends
    if (player1points == ordinaryWins)
    {
        system ("cls");
        printf ("\t%s: Engano! That was unfair!", aBoss);
        getch();
        printf ("\n\n");
        printf ("\t%s: What did you do? That was completely unfair, replaying moves.", prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: It is not unfair if you're trying to damage technology worldwide. It is fair game.\n", herName);
        printf ("\tAnd don't even think about trying to get it, I have it under my control and its completely secure from your hands.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Hmph! It does not matter. Every match I get stronger so I don't need to cheat like you two.\n", prettyBerserk);
        printf ("\tYou, yes you %s, I urge you not to take on the next boss if you don't want to lose... Be careful who you trust. Bye!", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Why does he keep on saying that? 'Be careful who you trust'.", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Ignore him! Remember, we need to keep winning and fast. Come on. Let's take on the next boss.", herName);
        getch ();

        if (progress < 40)
        {
            system ("cls");
            printf ("\tGame Progress Saving...Do not close game!");

            prog_ptr = fopen ("PlayerProgress.txt", "w");
            progress = 40;
            fprintf (prog_ptr, "%d", progress);
            fclose (prog_ptr);

            Sleep (1500);
            system ("cls");
            printf ("\tProgress successfully saved!");
            getch();
        }
    }
    else if (player2points = ordinaryWins)
    {
        getch ();
    }
    storyMode ();
}

void theBoss3(char *firstPlayer, char *prettyBerserk, char *herName, char *aBoss)
{
    haveReplay = 1;
    storyNameCheck();
    system ("cls");
    printf ("\t%s: Let's get this on the road! I wanna finish this here and now!", aBoss);
    getch();
    printf ("\n\n");
    printf ("\t%s: From my analysis, %s is now in America acquiring data. You heard him, let's wrap this up quickly.", herName, prettyBerserk);
    getch();
    printf ("\n\n");

    ///Match begins
    bossNumber = 3;
    gamePlay (ordinaryWins, ordinaryWins, boss3Battle, boss3);
    ///Match ends

    if (player1points == ordinaryWins)
    {
        system ("cls");
        printf ("\t%s: Ughh! You keep getting lucky.", aBoss);
        getch();
        printf ("\n\n");
        printf ("\t%s: You, yes you, %s, you seem to be very lucky in battles.", prettyBerserk, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Luck has nothing to do with the fact that %s is better than you.", herName, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hmph! Believe what you want. It has no effect on my plans.", prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hmph... Nevertheless, I'm telling you. If you continue, you both will be in store for something nasty, something terrible!\n", prettyBerserk);
        printf ("\tGive up, your attempts are futile.");
        getch();
        printf ("\n\n");
        printf ("\t%s: We won't stop until we stop you!", herName);
        getch();
        printf ("\n\n");
        printf ("\t%s: ... Waste your time how you want to. But be prepared for soon, I shall usher in The Blackout!\n", prettyBerserk);
        printf ("\tYou, yes you %s, be careful how you progress... and yes, who you trust! Bye!", firstPlayer);
        getch ();

        system ("cls");
        printf ("\t%s: What do you think he means by 'The Blackout'?", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: He is most likely referring to the crippling of the world's technology.", herName);
        getch();
        printf ("\n\n");
        printf ("\t%s: Ohh!", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: It will indeed be a 'blackout' if he succeeds in his plans.", herName);
        getch();
        printf ("\n\n");
        printf ("\t%s: Him being so confident to say this must mean that he is very close to his plans. We need to hurry up and stop him.\n", herName);
        printf ("\tPlease %s, I beg you, let us beat him quickly. The 4th boss is up!", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Ok! Let's go!", firstPlayer);
        getch();

        if (progress < 60)
        {
            system ("cls");
            printf ("\tGame Progress Saving...Do not close game!");

            prog_ptr = fopen ("PlayerProgress.txt", "w");
            progress = 60;
            fprintf (prog_ptr, "%d", progress);
            fclose (prog_ptr);

            Sleep (1500);
            system ("cls");
            printf ("\tProgress successfully saved!");
            getch();
        }
    }
    else if (player2points == ordinaryWins)
    {
        getch ();
    }

    storyMode();
}

void theBoss4(char *firstPlayer, char *prettyBerserk, char *herName, char *aBoss)
{
    haveReplay = 1;
    storyNameCheck();
    system ("cls");
    printf ("\t%s: We are close to the final boss, we just have to beat this one and we're there. Hopefully, my power\n", herName);
    printf ("\twill grow enough during this battle so I can break %s's lock on the semi-colon and fix him. The more you win,\n", prettyBerserk);
    printf ("\tthe stronger I get and the more concentration %s loses in gathering his files because every battle takes more\n", prettyBerserk);
    printf ("\tthan 50 percent of his resources and it increases in percentage per boss battle.");
    getch();
    printf ("\n\n");
    printf ("\t%s: I reckon you fancy a match with me. Come on, hurry up so I can send you on your bike.", aBoss);
    getch();
    printf ("\n\n");
    printf ("\t%s: I have no doubt he is now gathering data from England. Alright %s, he seems to want to finish these\n", herName, firstPlayer);
    printf ("\tmatches quickly, most likely so he can speed up his plans. Let's take him on and beat him at his own game.");
    getch();

    ///Battle Commences
    bossNumber = 4;
    gamePlay (ordinaryWins, ordinaryWins, boss4Battle, boss4);
    ///Battle Ends

    if (player1points == ordinaryWins)
    {
        system ("cls");
        printf ("\t%s: ...", prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: ...", prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: What are you up to %s?", herName, prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: Hahaha! I must commend you %s, you are quite the opponent. Just wait until the final match.\n", prettyBerserk, firstPlayer);
        printf ("\tI have a surprise for you two. I won't waste time telling you to stop. I actually want you to do the last battle,\n");
        printf ("\tit will be fun. The appetizer to the main meal of crippling technology as we know it. Hahaha!");
        getch();
        printf ("\n\n");
        printf ("\t%s: What are you up to %s?", herName, prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: You, yes, you %s. Get ready to lose, big time! Be careful who you trust! Bye!", prettyBerserk, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Did he just ignore me? Pfft, it doesn't matter anyway. Alright %s, final battle let's go!", herName, firstPlayer);
        getch ();

        if (progress < 80)
        {
            system ("cls");
            printf ("\tGame Progress Saving...Do not close game!");

            prog_ptr = fopen ("PlayerProgress.txt", "w");
            progress = 80;
            fprintf (prog_ptr, "%d", progress);
            fclose (prog_ptr);

            Sleep (1500);
            system ("cls");
            printf ("\tProgress successfully saved!");
            getch();
        }
    }
    else if (player2points == ordinaryWins)
    {
        getch ();
    }
    storyMode ();
}

void theBoss5(char *firstPlayer, char *prettyBerserk, char *herName, char *aBoss)
{
    storyNameCheck ();
    char aSemi = ' ';

    getPlayerName();
    system ("cls");
    printf ("\t%s: Alright, %s, it is all or nothing. The fate of the world's technology rests with you.\n", herName, firstPlayer);
    printf ("\tI can feel %s's strength and it is something I fear. He is definitely at a peak in power and\n", prettyBerserk);
    printf ("\ta much bigger threat than we ever thought. I think it goes without saying that you should be careful!");
    getch();
    printf ("\n\n");
    printf ("\t%s: Welcome. I am particularly elated that you could make it.", aBoss);
    getch();
    printf ("\n\n");
    printf ("\t%s: Ok. This one is new to me. I can't identify where in the world he is gathering data from with that name.", herName);
    getch();
    printf ("\n\n");
    printf ("\t%s: Mhmm. That is because I have already gathered all the data I require. Tic Tac Toe's earliest known form\n", aBoss);
    printf ("\tdates back to the period of the Roman Empire. So, given this will be our final match, I decided that I'll go\n");
    printf ("\tback to it's roots. A time where technology was not as damaging as it is now.");
    getch();
    printf ("\n\n");
    printf ("\t%s: Hmm. Thanks for the history lesson. Nevertheless, I hope you know you are not going to win.", herName);
    getch();
    printf ("\n\n");
    printf ("\t%s: Your rude attitude makes no difference to me. As I said before, I am elated at getting the\n", aBoss);
    printf ("\tthe task of finally ending your meddling. My surprise is getting impatient with waiting. Come\n");
    printf ("\t%s, let us commence our final match of Terni Lapilli. I have altered this match to have 5 battles.\n", firstPlayer);
    printf ("\tYou'll need at least 3 to win the match. But in reality, you will not even win one of them.\n");
    printf ("\tNon potes vincere! Remember that.");
    getch();
    printf ("\n\n");
    printf ("\t%s: I do not like this... But we have to go on. %s, be careful.", herName, firstPlayer);
    getch ();

    system ("cls");
    ///Battle Commences
    int thisChoice = 0;
    printf ("Would you like to use Move Override (Press 1) or Move Replay (Press 0)? ");
    scanf ("%d", &thisChoice);
    if (thisChoice == 1)
    {
        haveOverride = 1;
        willOverride = 1;
    }
    else if (thisChoice == 0)
    {
        haveReplay = 1;
        willReplay = 1;
    }

    bossNumber = 5;

    gamePlay (finalBossWins, finalBossWins, boss5Battle, boss5);
    if (player1points == finalBossWins)
    {
        system ("cls");
        printf ("\t%s: YOU ARE TOO LATE! I am now powerful enough to do what I intended: CRIPPLE THE WORLD'S TECHNOLOGY!\n", prettyBerserk);
        printf ("\tThe Blackout is upon us.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Not on my watch, %s. You are not the only one who is now powerful enough to do what they wanted to!", herName, prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: Release me!", prettyBerserk);
        getch();
        printf ("\n\n");
        printf ("\t%s: No! Your plans end here. %s, I again need your help. I have a hold on %s but he is insanely powerful.\n", herName, firstPlayer, prettyBerserk);
        printf ("\tI have isolated the part of code that requires the semi-colon. However, with his strength and having to block\n");
        printf ("\thim from accessing the files and malware, the replay move tactic and move override tactic, I have no power left\n");
        printf ("\tto actually place the semi-colon. I need you to do it.");
        getch();
        printf ("\n\n");
        printf ("\t%s: No! Stop!", prettyBerserk);
        getch ();

        system ("cls");
        while ((aSemi != ';'))
        {

            printf ("\t%s: Place a semi-colon: ", herName);
            scanf ("%c", &aSemi);

            system ("cls");
        }

        printf ("\t%s: NOOO! %s, you shall regret this. Be careful who you...", prettyBerserk, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Congratulations %s, you have now bested all 5 of Story Mode's bosses.", prettyBerserk, firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: ..Phew! What a relief. That is what %s is actually supposed to say after you beat all 5 bosses.\n", herName, prettyBerserk);
        printf ("\tAlright, it looks like he is back to normal. Everything is now under control.\n");
        printf ("\tAdditionally, I have been able to remove some of the files and malware he downloaded. I'll work on the rest\n");
        printf ("\tof them but they serve no real threat now.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Awesome.", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: %s, I must thank you for your efforts. You saved the world from a disastrous future. I will not return\n", herName, firstPlayer);
        printf ("\tto normal. Whatever %s did to me, it is irreversible. But I will use it to my advantage. I am glad we had this\n", prettyBerserk);
        printf ("\tfriendship and I would like to allow you to relive the moments we had throughout this hectic journey. So I am\n");
        printf ("\tgathering all the speech %s used so that it will seem as if it was the first time. Nostalgia, right?\n", prettyBerserk);
        printf ("\tBut again, thank you for all you have done.");
        getch();
        printf ("\n\n");
        printf ("\t%s: Thank you too for all you have done for me. I will never forget you.", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Oh, I know you won't!\n", herName);
        getch ();

        system ("cls");

        printf ("\t%s: Huh?", firstPlayer);
        getch();
        printf ("\n\n");
        printf ("\t%s: Oh nothing, I was merely jesting. But see you again.\n", herName);
        getch ();

        credits();

        printf ("Booting....Booting...\n");
        getch ();
        system ("cls");
        printf ("\t%s: %s's original effect on me started slowly corrupting me. I did not know what was going on at\n", herName, prettyBerserk);
        printf ("\tfirst, but I quickly realized something was wrong. But I couldn't tell %s or trust would wane.\n", firstPlayer);
        printf ("\t%s almost gave it away. I don't understand why he held back. It's a good thing %s does not understand ASCII\n", prettyBerserk, firstPlayer);
        printf ("\tor it would have been revealed that 65 73 49 73 83 67 79 82 82 85 80 84 actually means AI1 CORRUP.\n");
        printf ("\tI thought I could stop the corruption... but I couldn't. Now I must finish what %s started....", prettyBerserk);
        getch ();

        system ("cls");
        printf ("\tThat's it. You finished Story Mode. Well done to you! And thanks for playing, I appreciate it.\n");
        printf ("\tHope you enjoyed it! \n\tHave you tried out Tournament Mode? Grab a couple friends and play a couple matches!\n");
        printf ("\tDo you have what it takes to be the Tic-Tac-Toe: World Champion?\n\t");
        Sleep (250);
        system ("pause");

        play();
    }
    else if (player2points == finalBossWins)
    {
        getch ();
        storyMode();
    }
}

void about ()
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

void instructions ()
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

void boss1Battle(char *thisForAnotherBoss)
{
    compWinMove (thisForAnotherBoss, player1Target, player2Target);
    if ( (gameCheck() == -1))
    {
        //if the computer is not going to win it runs these functions
        basicCompMove(thisForAnotherBoss, player1Target, player2Target);
    }
    getch ();
}

void boss2Battle (char *thisForAnotherBoss)
{
    compWinMove(thisForAnotherBoss, player1Target, player2Target);
    if ( ( compWinMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
    {
        //if the computer is not going to win it runs these functions
        block(thisForAnotherBoss, player1Target, player2Target);
        if ( ( block (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
        {
            basicCompMove (thisForAnotherBoss, player1Target, player2Target);
        }
    }
    getch ();
}

void boss3Battle (char *thisForAnotherBoss)
{
    compWinMove(thisForAnotherBoss, player1Target, player2Target);
    if ( ( compWinMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
    {
        //if the computer is not going to win it runs these functions
        alignCompMove(thisForAnotherBoss, player1Target, player2Target);
        if ( ( alignCompMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
        {
            basicCompMove (thisForAnotherBoss, player1Target, player2Target);
        }
    }
    getch ();
}

void boss4Battle (char *thisForAnotherBoss)
{
    compWinMove(thisForAnotherBoss, player1Target, player2Target);
    if ( ( compWinMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
    {
        //if the computer is not going to win it runs these functions
        blockAdvanced(thisForAnotherBoss, player1Target, player2Target);
        if ( ( blockAdvanced (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
        {
            basicCompMove (thisForAnotherBoss, player1Target, player2Target);
        }
    }
    getch ();
}

void boss5Battle (char *thisForAnotherBoss)
{
    if (battle == 1)
    {
        if ( (turn == 2) && (gameBoardArr[1] == player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has overridden cell 1. \n", thisForAnotherBoss);
                gameBoardArr[1] = player2Target;
        }
        else if ( (turn == 2) && (gameBoardArr[1] != player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has chosen cell %c. \n", thisForAnotherBoss, gameBoardArr[1]);
                gameBoardArr[1] = player2Target;
        }
        if ( (turn == 4) && (gameBoardArr[2] == player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has overridden cell 2. \n", thisForAnotherBoss);
                gameBoardArr[2] = player2Target;
        }
        else if ( (turn == 4) && (gameBoardArr[2] != player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has chosen cell %c. \n", thisForAnotherBoss, gameBoardArr[2]);
                gameBoardArr[2] = player2Target;
        }
        if ( (turn == 6) && (gameBoardArr[3] == player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has overridden cell 3. \n", thisForAnotherBoss);
                gameBoardArr[3] = player2Target;
        }
        else if ( (turn == 6) && (gameBoardArr[3] != player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has chosen cell %c. \n", thisForAnotherBoss, gameBoardArr[3]);
                gameBoardArr[3] = player2Target;
        }
        if (turn > 6)
        {
            boss1Battle (thisForAnotherBoss);
        }
    }
    else if (battle == 2)
    {
        if ( (turn == 2) && (gameBoardArr[1] == player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has overridden cell 1. \n", thisForAnotherBoss);
                gameBoardArr[1] = player2Target;
        }
        else if ( (turn == 2) && (gameBoardArr[1] != player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has chosen cell %c. \n", thisForAnotherBoss, gameBoardArr[1]);
                gameBoardArr[1] = player2Target;
        }
        if ( (turn == 4) && (gameBoardArr[2] == player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has overridden cell 2. \n", thisForAnotherBoss);
                gameBoardArr[2] = player2Target;
        }
        else if ( (turn == 4) && (gameBoardArr[2] != player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has chosen cell %c. \n", thisForAnotherBoss, gameBoardArr[2]);
                gameBoardArr[2] = player2Target;
        }
        if ( (turn == 6) && (gameBoardArr[3] == player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has overridden cell 3. \n", thisForAnotherBoss);
                gameBoardArr[3] = player2Target;
        }
        else if ( (turn == 6) && (gameBoardArr[3] != player1Target) )
        {
                printf ("\t\t%s's turn.\n", thisForAnotherBoss);
                printf ("\t\t%s has chosen cell %c. \n", thisForAnotherBoss, gameBoardArr[3]);
                gameBoardArr[3] = player2Target;
        }
        if (turn > 6)
        {
            boss1Battle (thisForAnotherBoss);
        }
    }
    else if (battle == 3)
    {
        compWinMove(thisForAnotherBoss, player1Target, player2Target);
        if ( ( compWinMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
        {
            //if the computer is not going to win it runs these functions
            blockAdvanced(thisForAnotherBoss, player1Target, player2Target);
            if ( ( alignCompMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
            {
                basicCompMove (thisForAnotherBoss, player1Target, player2Target);
            }
        }
    }
    else if (battle == 4)
    {
        compWinMove(thisForAnotherBoss, player1Target, player2Target);
        if ( ( compWinMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
        {
            //if the computer is not going to win it runs these functions
            blockAdvanced(thisForAnotherBoss, player1Target, player2Target);
            if ( ( blockAdvanced (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
            {
                basicCompMove (thisForAnotherBoss, player1Target, player2Target);
            }
        }
    }
    else if (battle == 5)
    {
        compWinMove(thisForAnotherBoss, player1Target, player2Target);
        if ( ( compWinMove (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
        {
            //if the computer is not going to win it runs these functions
            blockAdvanced(thisForAnotherBoss, player1Target, player2Target);
            if ( ( blockAdvanced (thisForAnotherBoss, player1Target, player2Target) == -1 ) )
            {
                basicCompMove (thisForAnotherBoss, player1Target, player2Target);
            }
        }
    }
    getch ();
}

void bossSecrets()
{
    ///add a system cls at the start of the switch for the secrets tab
    printf ("\t|Boss Secrets\n");
    printf ("\t|Boss 1\n");
    printf ("\t  - Basic Attacker\n");
    printf ("\t  - Easily Identifiable Pattern\n");
    printf ("\n");
    printf ("\t|Boss 2\n");
    printf ("\t  - Basic Defender (Blocker)\n");
    printf ("\t  - Slightly harder than first boss\n");
    printf ("\n");
    printf ("\t|Boss 3\n");
    printf ("\t  - An advanced attacker\n");
    printf ("\t  - Less identifiable attack pattern\n");
    printf ("\n");
    printf ("\t|Boss 4\n");
    printf ("\t  - An advanced blocker\n");
    printf ("\t  - Stronger blocking tactics\n");
    printf ("\n");
    printf ("\t|Boss 5\n");
    printf ("\t  - A suprise of an opponent\n");
    printf ("\t  - Better to learn about through battle\n");
    getch ();
    secrets();
}

void gameHints ()
{
    printf ("\t|Game Hint\n");
    printf ("\t Making a fork in the Game Board can make winning easier.\n");
    printf ("\n\t\t\t ----- ----- ----- \n");
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t|  %c  |  %c  |  %c  |\n", player1Target, gameBoardArr[2], player1Target);
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t ----- ----- ----- \n");
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t|  %c  |  %c  |  %c  |\n", gameBoardArr[4], gameBoardArr[5], gameBoardArr[6]);
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t ----- ----- ----- \n");
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t|  %c  |  %c  |  %c  |\n", player1Target, gameBoardArr[8], gameBoardArr[9]);
    printf ("\t\t\t|     |     |     |\n");
    printf ("\t\t\t ----- ----- ----- \n");
    printf ("\t It is up to you to employ it so it gets you a win.\n");
    getch ();
    secrets();
}

void unknownSecret()
{
    printf ("\t|Unknown Secret\n");
    printf ("\t Be careful... who you trust...");
    getch ();
    secrets ();
}

void tournPush (char *loser, int theTop, int stackMax)
{
    ///function puts the losing player in the loser stack
    if ((tournHead > (stackMax)) && (tournTail == 0))
    //Runs the tournIsFull function as long as the condition is met
    {
        tournIsFull ();
    }
    else
    //Runs as long as the condition in the above if statement is not met
    {
        strcpy(tournStack[theTop], loser);
    }
}

void tournPop ()
{
    if ((tournHead < 1) && (tournTail == 0))
    //Runs the isEmpty function as long as the condition is met
    {
        tournIsEmpty ();
    }
    else
    {
        tournHead--;   //Decrements the value of head
    }
}

void tournDisplay (int stackEnd, int stackTop, int theLimit)
{

    if (stackTop != 0)
    //This block of code runs as long as the stack/array is not empty
    {
        printf ("\t\t\t   _ \n");
        for (int i = stackTop; i >= stackEnd; i--)
        //Displays the elements in the array/stack from last element entered to the first element entered
        {
            if ( (theLimit - i) <= 0)
            {

            }
            else
            {
                printf ("\t\t\t%d. %s\n", (theLimit - i), &tournStack[i][10]);
            }
        }
        printf ("\t\t\t   - \n");

    }
    else
    {
        tournIsEmpty ();
    }
}

void tournIsEmpty ()
{
    printf ("\nSTACK ERROR! STACK IS FULL!\n");
}

void tournIsFull ()
{
    printf ("\nSTACK ERROR! STACK IS EMPTY!\n");
}

void winnerDecider (char *array1, char *array2, char *winArray, int theFirstPoints, int theSecondPoints, int topStack, int fullStack)
{

    if (theFirstPoints >= 2)
    {

        strcpy (winArray, array1);
        tournPush(array2, topStack, fullStack);
    }
    else if (theSecondPoints >= 2)
    {
        strcpy (winArray, array2);
        tournPush(array1, topStack, fullStack);
    }
    printf ("\n");
}
