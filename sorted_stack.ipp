#pragma once

template <typename T>
void sorted_stack<T>::push(T& value) noexcept
{
	stack<T>::push(value);
	sort();
}

template <typename T>
void sorted_stack<T>::sort()
{
	// O(n^2)
	// Stack bazl� insertion sort

	stack<T> tmp_stack;
	for(int i = 0; i < sorted_stack<T>::size(); i++)
	{
		T tmp = sorted_stack<T>::pop();
		while (!tmp_stack.is_empty() && compare(tmp_stack.peek(), tmp) < 0) {
			push(tmp_stack.pop());
		}

		tmp_stack.push(tmp);
	}

	for(int i = 0; i < tmp_stack.size(); i++)
	{
		push(tmp_stack.pop());
	}
}
