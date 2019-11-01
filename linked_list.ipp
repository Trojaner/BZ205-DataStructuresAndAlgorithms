﻿#pragma once
#include <iostream>
#include "linked_list.h"

using namespace std;

template <typename T>
linked_list<T>::linked_list() noexcept
{
	head_ = nullptr;
}

template <typename T>
linked_list<T>::~linked_list() noexcept
{
	node<T>* currnode = head_;

	while (currnode != nullptr)
	{
		node<T>* nextnode = currnode->next;
		delete currnode;
		currnode = nextnode;
	}
}

template <typename T>
bool linked_list<T>::is_empty() noexcept
{
	return head_ == nullptr;
}

template <typename T>
int linked_list<T>::find(T& value) noexcept
{
	node<T>* currnode = head_;
	int currIndex = 1;

	while (currnode && currnode->data != value)
	{
		currnode = currnode->next;
		currIndex++;
	}

	if (currnode)
	{
		return currIndex;
	}

	return 0;
}

template <typename T>
node<T>* linked_list<T>::insert(int index, T& value) noexcept
{
	if (index < 0)
	{
		return nullptr;
	}

	int currIndex = 1;
	node<T>* currnode = head_;

	while (currnode && index > currIndex)
	{
		currnode = currnode->next;
		currIndex++;
	}

	if (index > 0 && currnode == nullptr)
	{
		return nullptr;
	}

	auto newnode = new node<T>();
	newnode->data = value;

	if (index == 0)
	{
		newnode->next = head_;
		head_ = newnode;
	}
	else
	{
		newnode->next = currnode->next;
		currnode->next = newnode;
	}

	return newnode;
}

template <typename T>
int linked_list<T>::remove(T& value) noexcept
{
	node<T>* prevnode = nullptr;
	node<T>* currnode = head_;

	int currIndex = 1;
	while (currnode && currnode->data != value)
	{
		prevnode = currnode;
		currnode = currnode->next;
		currIndex++;
	}

	if (currnode)
	{
		if (prevnode)
		{
			prevnode->next = currnode->next;
			delete currnode;
		}
		else
		{
			head_ = currnode->next;
			delete currnode;
		}
		return currIndex;
	}

	return 0;
}

template <typename T>
void linked_list<T>::print() noexcept
{
	int num = 0;
	node<T>* currnode = head_;
	while (currnode != nullptr)
	{
		cout << currnode->data << endl;
		currnode = currnode->next;
		num++;
	}

	cout << "Number of nodes in the list: " << num << endl;
}
