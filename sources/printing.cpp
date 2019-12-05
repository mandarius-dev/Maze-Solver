/*******************************************************
 *  Authors: Man N. Darius                             *
 *  Description: Prints on the screen every thing that *
 *               IS NOT PRESET.                        *
 *******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "../graphics.h"
#include "../headers/menu.h"
#include "../headers/printing.h"
#include "../headers/memoryalloc.h"
#include "../headers/mat_gen.h"
#include "../headers/player.h"

/********************************************************
*  Description: Enum for maze elements                  *
*********************************************************/
enum maze
{
    wall=1,
    start_x=60,
    start_y=120,
    dim_cel=30,
    show_cel_no_x=43,
    show_cel_no_y=95

};

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

    //Direction of the text
    direction=0
};

struct player_stats player;

/********************************************************
*  Description: Prints the START MENU of the project    *
*               AND prints the leader board AND gets    *
*               the player name                         *
*********************************************************/
void start_menu()
{
    cleardevice();

    settextstyle(font_style,direction,font_size_medium);
    outtextxy(80,50,"Solv it (WIP)");

    settextstyle(font_style,direction,font_size_int_med);
    rectangle(470,100,670,490);
    outtextxy(520,110,"LEADER");
    outtextxy(525,140,"BOARD");

    settextstyle(font_style,direction,font_size_small);
    /// TEMPORARY
    outtextxy(490,180,"1. elena");
    outtextxy(490,210,"2. fabian");
    outtextxy(490,240,"3. ");
    outtextxy(490,270,"4. ");
    outtextxy(490,300,"5. ");
    outtextxy(490,330,"6. ");
    outtextxy(490,360,"7. ");
    outtextxy(490,390,"8. ");
    outtextxy(490,420,"9. ");
    outtextxy(490,450,"10.");
    ///

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(130,130,"Remember you only have");
    outtextxy(100,160,"a limited amount of lives.");

    outtextxy(130,200,"If you get stuck press");
    outtextxy(100,230,"'H' to use a hint.");

    outtextxy(130,270,"Type 'back' and press");
    outtextxy(100,300,"'TAB' if you want to go");
    outtextxy(100,330,"back. Or type your name");
    outtextxy(100,360,"and press 'TAB'.");

    outtextxy(130,400,"Please input a name,");
    outtextxy(160,430,"NAME: ");

    char c;
    char name[11]={'\0'};
    c=getch();
    while(c!=9)
    {
        if(strlen(name)<9)
        {
            if(c!=8)
            {
                name[strlen(name)]=c;
                name[strlen(name)]='\0';
            }
            else
                name[strlen(name)-1]='\0';
            outtextxy(240,430,"                    ");
            outtextxy(240,430,name);
        }
        else
            if(c==8)
            {
                name[strlen(name)-1]='\0';
                outtextxy(240,430,"                      ");
                outtextxy(240,430,name);
            }
        c=getch();
    }

    strcpy(player.name,name);

    if(strcmp(name,"back")==0)
        return;
    else
        game_menu();
}

/// TEMPORARY
void temp2(int *matrix,long n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",get_matrix_element(matrix,n,i,j));
        printf("\n");
    }
}
///

/********************************************************
*  Description: Compares the dimension of the matrix    *
*               with the number of cells to show on the *
*               x and y axes to know how to call the    *
*               draw function for the maze              *
*********************************************************/
int dim_comparation(int n)
{
    if(n<=show_cel_no_x&&n<=show_cel_no_y)
        return 0;
    if(n<=show_cel_no_x&&n>show_cel_no_y)
        return 1;
    if(n>show_cel_no_x&&n<=show_cel_no_y)
        return 2;
    if(n>show_cel_no_x&&n>show_cel_no_y)
        return 3;
}

/********************************************************
*  Description: Prints the information about the player *
*********************************************************/
void print_header()
{
    cleardevice();

    settextstyle(font_style,direction,font_size_int_med);
    outtextxy(80,50,"LIVES");
    outtextxy(80,80,"0");

    outtextxy(220,50,"LEVEL");
    char no[3];
    sprintf(no,"%d",player.score);
    outtextxy(220,80,no);

    outtextxy(360,50,"MOVES");
    outtextxy(360,80,"0");

    outtextxy(500,50,"NAME");
    outtextxy(500,80,player.name);
}

/********************************************************
*  Description: Prints the GAME MENU of the project     *
*               AND deals with the movement of the maze *
*********************************************************/
void game_menu()
{
    cleardevice();

    /// TEMPORARY
    int n=15;
    int *matrix;

    /*int a;
    FILE *f=fopen("maze_tmp.txt","r");
    fscanf(f,"%d",&n);
    matrix=allocate_matrix(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            fscanf(f,"%d",&a);
            element_change_matrix(matrix,n,i,j,a);
        }*/



    ///

    player.score=11;
    n=player.score;
    matrix=gen_mat(n);
    element_change_matrix(matrix,n,3,3,3);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",get_matrix_element(matrix,n,i,j));
        }
        printf("\n");
    }

    char choise;
    int dim_comp;
    int cel_start_x=3,cel_start_y=3,player_poz_x=3,player_poz_y=3;


    while(player_poz_x!=n-2||player_poz_y!=n-2)
    {
        dim_comp=dim_comparation(n);
        switch(dim_comp)
        {
            case 0:
                {
                    print_header();
                    draw_maze(matrix,n,start_x,start_y,dim_cel,n,n,cel_start_x,cel_start_y);
                } break;
            case 1:
                {
                    print_header();
                    draw_maze(matrix,n,start_x,start_y,dim_cel,n,show_cel_no_y,cel_start_x,cel_start_y);
                } break;
            case 2:
                {
                    print_header();
                    draw_maze(matrix,n,start_x,start_y,dim_cel,show_cel_no_x,n,cel_start_x,cel_start_y);
                } break;
            case 3:
                {
                    print_header();
                    draw_maze(matrix,n,start_x,start_y,dim_cel,show_cel_no_x,show_cel_no_y,cel_start_x,cel_start_y);
                } break;
        }
        /*printf("\n\n");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",get_matrix_element(matrix,n,i,j));
            }
            printf("\n");
        }
        printf("%d %d\n",player_poz_x,player_poz_y);*/
        choise=getch();
        switch(choise)
        {
            /// Maze movement
            case 'j':
                    if(cel_start_y>3&&(dim_comp==0||dim_comp==2||dim_comp==3))
                        cel_start_y-=2;
                    break;
            case 'i':
                    if(cel_start_x>3&&(dim_comp==1||dim_comp==2||dim_comp==3))
                        cel_start_x-=2;
                    break;
            case 'l':
                    if(cel_start_y<(n-show_cel_no_y)&&(dim_comp==0||dim_comp==2||dim_comp==3))
                        cel_start_y+=2;
                    break;
            case 'k':
                    if(cel_start_x<(n-show_cel_no_x)&&(dim_comp==1||dim_comp==2||dim_comp==3))
                        cel_start_x+=2;
                    break;

            /// Player movement
            case 'a':
                {
                    if(move_left(matrix,n,player_poz_x,player_poz_y))
                    {
                        tray(matrix,n,player_poz_x,player_poz_y-2,player_poz_x,player_poz_y);
                        player_poz_y-=2;
                    }

                } break;
            case 'd':
                {
                    if(move_right(matrix,n,player_poz_x,player_poz_y))
                    {
                        tray(matrix,n,player_poz_x,player_poz_y+2,player_poz_x,player_poz_y);
                        player_poz_y+=2;
                    }
                } break;
            case 's':
                {
                    if(move_down(matrix,n,player_poz_x,player_poz_y))
                    {
                        tray(matrix,n,player_poz_x+2,player_poz_y,player_poz_x,player_poz_y);
                        player_poz_x+=2;
                    }
                } break;
            case 'w':
                {
                    if(move_up(matrix,n,player_poz_x,player_poz_y))
                    {
                        tray(matrix,n,player_poz_x-2,player_poz_y,player_poz_x,player_poz_y);
                        player_poz_x-=2;
                    }
                } break;


            case 'b':
                {
                    free(matrix);
                    break;
                } break;
        }
        if(player_poz_x==n-2&&player_poz_y==n-2)
        {
            player.score+=2;
            n=player.score;
            dealoc_matrix(matrix);
            matrix=gen_mat(n);
            element_change_matrix(matrix,n,3,3,3);
            player_poz_x=3;
            player_poz_y=3;
        }
    }
}

void draw_path(int *matrix,int n,int x,int y,int cel_l,int cel_c)
{
    /// TO DO GENERALIZE
    int left=start_x+(dim_cel)*(cel_c-1)+20;
    int top=start_y+(dim_cel)*(cel_l-1)+20;
    int right=start_x+(dim_cel)*(cel_c-1)+dim_cel/3;
    int bottom=start_y+(dim_cel)*(cel_l-1)+dim_cel/3;
    if(get_matrix_element(matrix,n,x,y)==2)
    {
        setfillstyle(SOLID_FILL,LIGHTGRAY);
        bar(left,top,right,bottom);
    }
    if(get_matrix_element(matrix,n,x,y)==3)
    {
        setfillstyle(SOLID_FILL,LIGHTCYAN);
        circle(left-5,top-5,dim_cel/3-2);
        floodfill(left-4,top-4,WHITE);
    }
}

/********************************************************
*  Description: Draws the maze                          *
*  Parameters: int *matrix - The matrix of the maze     *
*                            with 1 as wall and 0 as    *
*                            path                       *
*              int n - The dimension of the matrix      *
*              int start_x - The coordinates on the     *
*              int start_y   SCREEN from witch to start *
*                            drawing                    *
*              int dim_cel - The dimension of the line  *
*                            in pixels (how long should *
*                            the cell be)               *
*              int show_cel_no_x - How many cells to    *
*                                  show at once         *
*                                  HORIZONTALLY         *
*              int show_cel_no_Y - How many cells to    *
*                                  show at once         *
*                                  VERTICALLY           *
*              int cel_start_x - The coordinates in the *
*              int cel_start_y   MATRIX form which to   *
*                                start drawing          *
*********************************************************/
void draw_maze(int *matrix,long n,int start_x,int start_y,int dim_cel,int show_cel_no_x,int show_cel_no_y,int cel_start_x,int cel_start_y)
{
    int no_zero=0,cel_l=1,cel_c=1;

    if(cel_start_x==3)
        if(show_cel_no_x==n)
            line(start_x,start_y,(show_cel_no_y/2-1)*dim_cel+start_x,start_y);
        else
            line(start_x,start_y,(show_cel_no_y/2)*dim_cel+start_x,start_y);

    if(cel_start_y==3)
        if(show_cel_no_y==n)
            line(start_x,start_y,start_x,(show_cel_no_x/2+1)*dim_cel+start_x);
        else
            line(start_x,start_y,start_x,(show_cel_no_x/2+2)*dim_cel+start_x);

    int i=cel_start_x;
    int j=cel_start_y;

    int horizontal,vertical;

    show_cel_no_x==n?vertical=n/2:vertical=show_cel_no_x/2+1;
    show_cel_no_y==n?horizontal=n/2:horizontal=show_cel_no_y/2+1;

    while(cel_l<vertical)
    {
        cel_c=1;
        j=cel_start_y;
        while(cel_c<horizontal)
        {
            no_zero=0;
            get_matrix_element(matrix,n,i,j+1)==1?no_zero++:no_zero;
            get_matrix_element(matrix,n,i+1,j)==1?no_zero++:no_zero;
            get_matrix_element(matrix,n,i+1,j+1)==1?no_zero++:no_zero;
            if(no_zero==wall)
            {
                draw_path(matrix,n,i,j,cel_l,cel_c);
                cel_c++;
                j+=2;
                continue;
            }
            else
            {
                if(no_zero==2)
                    if(get_matrix_element(matrix,n,i,j+1)==wall)
                        line(start_x+cel_c*dim_cel,start_y+(cel_l-1)*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                    else
                        line(start_x+(cel_c-1)*dim_cel,start_y+cel_l*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                else
                {
                    line(start_x+cel_c*dim_cel,start_y+(cel_l-1)*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                    line(start_x+(cel_c-1)*dim_cel,start_y+cel_l*dim_cel,start_x+cel_c*dim_cel,start_y+cel_l*dim_cel);
                }
            }
            draw_path(matrix,n,i,j,cel_l,cel_c);
            cel_c++;
            j+=2;
        }
        cel_l++;
        i+=2;
    }
}
