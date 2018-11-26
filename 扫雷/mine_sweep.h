#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define MAX_ROW 10
#define MAX_COL 10
#define MINE_COUNT 10

/*---翻开计数---*/
int blank_count;

/*---游戏开始菜单打印---*/
void game_menu();

/*---显示地图和地雷地图的初始化---*/
void map_init(char show_map[MAX_ROW + 2][MAX_COL + 2],
			  char mine_map[MAX_ROW + 2][MAX_COL + 2]);

/*---地图打印---*/
void map_display(char map[MAX_ROW + 2][MAX_COL + 2]);

/*---地图更新---*/
void map_update(char show_map[MAX_ROW + 2][MAX_COL + 2],
				char mine_map[MAX_ROW + 2][MAX_COL + 2],
				int row, int col);

/*---游戏运行---*/
void game_run();

/*---胜利判断---*/
int win_check(char show_map[MAX_ROW + 2][MAX_COL + 2]);
