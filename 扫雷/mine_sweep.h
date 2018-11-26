#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX_ROW 10
#define MAX_COL 10
#define MINE_COUNT 10

/*---��������---*/
int blank_count;

/*---��Ϸ��ʼ�˵���ӡ---*/
void game_menu();

/*---��ʾ��ͼ�͵��׵�ͼ�ĳ�ʼ��---*/
void map_init(char show_map[MAX_ROW + 2][MAX_COL + 2],
			  char mine_map[MAX_ROW + 2][MAX_COL + 2]);

/*---��ͼ��ӡ---*/
void map_display(char map[MAX_ROW + 2][MAX_COL + 2]);

/*---��ͼ����---*/
void map_update(char show_map[MAX_ROW + 2][MAX_COL + 2],
				char mine_map[MAX_ROW + 2][MAX_COL + 2],
				int row, int col);

/*---��Ϸ����---*/
void game_run();

/*---ʤ���ж�---*/
int win_check(char show_map[MAX_ROW + 2][MAX_COL + 2]);
