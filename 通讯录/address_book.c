/*
**	功能函数
*/

#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include "adress_book.h"

void Init(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	addr_book->size = 0;
	addr_book->capacity = 1;
	addr_book->infos = (PersonInfo*)malloc(sizeof(PersonInfo) 
		* addr_book->capacity);
}

void capacityEnlargement(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	PersonInfo* old_infos = addr_book->infos;
	addr_book->capacity *= 2;
	addr_book->infos = (PersonInfo*)malloc(addr_book->capacity
		* sizeof(PersonInfo));
	for (int i = 0; i < addr_book->size; ++i)
	{
		*(addr_book->infos + i) = *(old_infos + i);
	}
	free(old_infos);
}

int menu()
{
	printf("============\n");
	printf("1. 新增\n");
	printf("2. 删除\n");
	printf("3. 修改\n");
	printf("4. 查找\n");
	printf("5. 显示全部\n");
	printf("6. 清空全部\n");
	printf("0. 退出\n");
	printf("============\n");
	int ret = 0;
	scanf("%d", &ret);
	return ret;
}

void addPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	if (addr_book->size >= addr_book->capacity)
	{
		printf("当前通讯录已满, 进行扩容! \n");
		capacityEnlargement(addr_book);
	}
	printf("插入一个联系人! \n");
	PersonInfo* p = &addr_book->infos[addr_book->size];
	printf("请输入用户姓名: \n");
	scanf("%s", p->name);
	printf("请输入电话: \n");
	scanf("%s", p->phone);
	++addr_book->size;
	printf("用户添加成功!\n");
}

void delPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("删除联系人! \n");
	printf("请输入要删除的联系人的序号: \n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size)
	{
		printf("输入下表有误, 删除失败! \n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id];
	printf("您要删除的联系人序号为: [%d] %s, 确认删除请输入y?\n",
		id, p->name);
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "y") != 0)
	{
		printf("删除操作已取消! \n");
		return;
	}
	PersonInfo* from = &addr_book->infos[addr_book->size - 1];
	PersonInfo* to = p;
	*to = *from;
	--addr_book->size;
	printf("删除练习人成功! \n");
}

void modifyPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("修改联系人! \n");
	printf("请输入要修改的联系人的序号: \n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size)
	{
		printf("输入不合法! \n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id];
	char input[1024] = { 0 };
	printf("请输入要修改的联系人的姓名: \n");
	scanf("%s", input);
	if (strcmp(input, "#") != 0)
	{
		strcpy(p->name, input);
	}
	printf("请输入要修改的电话: \n");
	scanf("%s", input);
	if (strcmp(input, "#") != 0)
	{
		strcpy(p->phone, input);
	}
	printf("修改成功! \n");
}

void findPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("开始查找联系人! \n");
	printf("请输入要查找的联系人姓名: \n");
	char name[1024] = { 0 };
	scanf("%s", name);
	int count = 0;
	for (int i = 0; i < addr_book->size; ++i)
	{
		PersonInfo* p = &addr_book->infos[i];
		if (strcmp(p->name, name) == 0)
		{
			printf("[%d] %s\t%s\n",
				i, p->name, p->phone);
			++count;
		}
	}
	printf("查找完毕, 共%d条信息\n", count);
}

void displayAllPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("显示所有联系人! \n");
	for (int i = 0; i < addr_book->size; ++i)
	{
		PersonInfo* p = &addr_book->infos[i];
		printf("[%d] %s\t%s\n", i, p->name, p->phone);
	}
	printf("共显示了%d条信息! \n", addr_book->size);
}

void clearAllPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("清空所有数据!\n");
	printf("您确定要清空所有记录吗? 输入y确认!\n");
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "y") != 0)
	{
		printf("清空操作已取消! \n");
		return;
	}
	addr_book->size = 0;
	printf("数据已清空! \n");
}