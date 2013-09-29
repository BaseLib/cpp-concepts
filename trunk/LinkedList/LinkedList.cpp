// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Node
{
	int iData;
	struct Node *pNext;
	Node()
	{
		iData= 0;
		pNext = NULL;
	}
};

static  Node* pHead= NULL;

bool AddNode(Node** pHead,int iData)
{
	Node *pNode = new Node;
	pNode->iData = iData;

	if(pHead && *pHead == NULL)
	{
		*pHead = pNode;
		return true;
	}
	else if (pHead)
	{
		Node *pTempNode = *pHead;
		while(pTempNode && pTempNode->pNext)
		{
			pTempNode = pTempNode->pNext;
		}

		pTempNode->pNext = pNode;
		return true;
	}
	else
	{
		//assert(false);
	}
	return false;
}
void DisplayList(Node* pHead)
{
	printf("\nList : ");
	while(pHead)
	{
		printf(" %2d -> ",pHead->iData);
		pHead = pHead->pNext;
	}
	if(!pHead)
		printf("NULL");
}

Node *ReverseList(Node* pHead)
{
	Node *pNode = pHead;
	Node *pPrev = NULL;

	while(pNode)
	{
		Node *pTemp = pNode->pNext;
		pNode->pNext = pPrev;
		pPrev = pNode;
		pNode = pTemp;
	}
	return pPrev;
}

int _tmain(int argc, _TCHAR* argv[])
{
	AddNode(&pHead, 10);
	AddNode(&pHead, 20);
	AddNode(&pHead, 30);
	AddNode(&pHead, 40);
	AddNode(&pHead, 50);
	
	DisplayList(pHead);

	DisplayList(ReverseList(pHead));
	return 0;
}

