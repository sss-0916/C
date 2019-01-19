/*
**	���ܺ���
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
	printf("1. ����\n");
	printf("2. ɾ��\n");
	printf("3. �޸�\n");
	printf("4. ����\n");
	printf("5. ��ʾȫ��\n");
	printf("6. ���ȫ��\n");
	printf("0. �˳�\n");
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
		printf("��ǰͨѶ¼����, ��������! \n");
		capacityEnlargement(addr_book);
	}
	printf("����һ����ϵ��! \n");
	PersonInfo* p = &addr_book->infos[addr_book->size];
	printf("�������û�����: \n");
	scanf("%s", p->name);
	printf("������绰: \n");
	scanf("%s", p->phone);
	++addr_book->size;
	printf("�û���ӳɹ�!\n");
}

void delPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("ɾ����ϵ��! \n");
	printf("������Ҫɾ������ϵ�˵����: \n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size)
	{
		printf("�����±�����, ɾ��ʧ��! \n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id];
	printf("��Ҫɾ������ϵ�����Ϊ: [%d] %s, ȷ��ɾ��������y?\n",
		id, p->name);
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "y") != 0)
	{
		printf("ɾ��������ȡ��! \n");
		return;
	}
	PersonInfo* from = &addr_book->infos[addr_book->size - 1];
	PersonInfo* to = p;
	*to = *from;
	--addr_book->size;
	printf("ɾ����ϰ�˳ɹ�! \n");
}

void modifyPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("�޸���ϵ��! \n");
	printf("������Ҫ�޸ĵ���ϵ�˵����: \n");
	int id = 0;
	scanf("%d", &id);
	if (id < 0 || id >= addr_book->size)
	{
		printf("���벻�Ϸ�! \n");
		return;
	}
	PersonInfo* p = &addr_book->infos[id];
	char input[1024] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ�˵�����: \n");
	scanf("%s", input);
	if (strcmp(input, "#") != 0)
	{
		strcpy(p->name, input);
	}
	printf("������Ҫ�޸ĵĵ绰: \n");
	scanf("%s", input);
	if (strcmp(input, "#") != 0)
	{
		strcpy(p->phone, input);
	}
	printf("�޸ĳɹ�! \n");
}

void findPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("��ʼ������ϵ��! \n");
	printf("������Ҫ���ҵ���ϵ������: \n");
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
	printf("�������, ��%d����Ϣ\n", count);
}

void displayAllPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("��ʾ������ϵ��! \n");
	for (int i = 0; i < addr_book->size; ++i)
	{
		PersonInfo* p = &addr_book->infos[i];
		printf("[%d] %s\t%s\n", i, p->name, p->phone);
	}
	printf("����ʾ��%d����Ϣ! \n", addr_book->size);
}

void clearAllPersonInfo(AddressBook* addr_book)
{
	assert(addr_book != NULL);
	printf("�����������!\n");
	printf("��ȷ��Ҫ������м�¼��? ����yȷ��!\n");
	char cmd[1024] = { 0 };
	scanf("%s", cmd);
	if (strcmp(cmd, "y") != 0)
	{
		printf("��ղ�����ȡ��! \n");
		return;
	}
	addr_book->size = 0;
	printf("���������! \n");
}