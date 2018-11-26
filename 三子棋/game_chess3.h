#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

/*---棋盘---*/
char g_borad[ROW][COL];

/*---冠军---*/
char winner;

/*---游戏初始化---*/
void game_chess3_init();

/*---棋盘打印---*/
void print_board();

/*---玩家落子---*/
void player_move();

/*---电脑落子---*/
void computer_move();

/*---冠军检测---*/
char check_winner();

/*---游戏结果打印---*/
void print_result();