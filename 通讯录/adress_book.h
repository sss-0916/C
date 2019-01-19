#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"

/*---�û���Ϣ---*/
typedef struct PersonInfo
{
	char name[1024];
	char phone[1024];
} PersonInfo;

/*---ͨѶ¼---*/
typedef struct AddressBook 
{
	PersonInfo* infos;
	int capacity;
	int size;
} AddressBook;

/*---ͨѶ¼---*/
AddressBook g_address_book;

/*---ͨѶ¼��ʼ��---*/
void Init(AddressBook* addr_book);

/*---����---*/
void capacityEnlargement(AddressBook* addr_book);

/*---����---*/
int menu();

/*---�����û�---*/
void addPersonInfo(AddressBook* addr_book);

/*---ɾ���û�---*/
void delPersonInfo(AddressBook* addr_book);

/*---�޸��û�---*/
void modifyPersonInfo(AddressBook* addr_book);

/*---�����û�---*/
void findPersonInfo(AddressBook* addr_book);

/*---��ʾ�����û�---*/
void displayAllPersonInfo(AddressBook* addr_book);

/*---��������û�---*/
void clearAllPersonInfo(AddressBook* addr_book);