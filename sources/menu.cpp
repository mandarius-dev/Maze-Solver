/*******************************************************
 *  Authors: Man N. Darius                             *
 *  Description: Prints on the screen every thing that *
 *               IS PRESET.                            *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "../headers/menu.h"
#include "../headers/printing.h"

/********************************************************
*  Description: Enum for all the setting of the text    *
*********************************************************/
enum font_settings
{
    //Font sizes
    font_size_small=2,
    font_size_int_med=3,
    font_size_medium=4,
    font_size_large=6,

    //Sans Serif
    font_style=SANS_SERIF_FONT,

    direction=0
};

/********************************************************
*  Description: Initializes the windows where to draw   *
*               and write.                              *
*********************************************************/
void init_window()
{
    initwindow(750,550,"Maze Solver");
}


/********************************************************
*  Description: Prints the MAIN MENU of the project     *
*********************************************************/
void main_menu()
{
    cleardevice();

    settextstyle(font_style,direction,font_size_large);
    outtextxy(200,50,"Maze solver");

    settextstyle(font_style,direction,font_size_medium);
    outtextxy(280,120,"Can you solve it?");

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(150,240,"1. Solve it");

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(190,280,"2. Instructions");

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(230,320,"3. Credits");

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(270,360,"b. Exit");

    printf("menu_select\n");
    char choise;
    selection:
        choise=getch();
        printf("%c\n",choise);
        switch(choise)
        {
            case '1': start_menu(); break;
            case '2': instruction_menu(); break;
            case '3': credits_menu(); break;
            case 'b': return; break;

            // THIS CASE IS TEMPORERY remind me to delete it
            case ' ': return; break;
            default : goto selection;
        }

    main_menu();
}

/*****************************************************
*  Description: Prints the INSTRUCTION MENU of the   *
*               project                              *
******************************************************/
void instruction_menu()
{
    /// WORK IN PROGRESS
    cleardevice();

    settextstyle(font_style,direction,font_size_medium);
    outtextxy(80,50,"Instrction (Work in progress)");

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(130,130,"Use the keys 'W', 'A', 'S', 'D' to move the player.");

    rectangle(220,180,270,230);
    outtextxy(234,190,"W");

    rectangle(175,235,225,285);
    outtextxy(191,245,"A");
    rectangle(230,235,280,285);
    outtextxy(248,245,"S");
    rectangle(285,235,335,285);
    outtextxy(300,245,"D");

    outtextxy(130,380,"Your goal is to reach the bottom right of the maze.");

    settextstyle(font_style,direction,font_size_small);
    outtextxy(80,440,"Press 'B' to go back.");

    selection:
        if(getch()=='b')
            return;
        else
            goto selection;
}

/*****************************************************
*  Description: Prints the CREDITS MENU of the       *
*               project                              *
******************************************************/
void credits_menu()
{
    cleardevice();

    settextstyle(font_style,direction,font_size_medium);
    outtextxy(80,50,"Credits (Work in progress)");

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(130,130,"Project realized by:");

    outtextxy(170,160,"Man N. Darius,");
    outtextxy(170,190,"Pacuraru L. Fabin Virgil,");
    outtextxy(170,220,"Zah D. Elena");

    outtextxy(130,280,"Technical University of Cluj-Napoca.");

    settextstyle(font_style,direction,font_size_small);
    outtextxy(80,340,"Press 'B' to go back.");

    selection:
        if(getch()=='b')
            return;
        else
            goto selection;
}
