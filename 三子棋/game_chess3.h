#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

/*---����---*/
char g_borad[ROW][COL];

/*---�ھ�---*/
char winner;

/*---��Ϸ��ʼ��---*/
void game_chess3_init();

/*---���̴�ӡ---*/
void print_board();

/*---�������---*/
void player_move();

/*---��������---*/
void computer_move();

/*---�ھ����---*/
char check_winner();

/*---��Ϸ�����ӡ---*/
void print_result();