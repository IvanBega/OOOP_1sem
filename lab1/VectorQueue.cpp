#pragma once
#include "Queue.cpp"
#include <vector>

template <class T>
class VectorQueue : public Queue<T>
{
public:
	void push(T data, int priority)
	{
		elem temp(data, priority);
		if (arr.empty())
		{
			arr.push_back(temp);
			return;
		}
		int low = 0, high = arr.size() - 1, mid = (low + high) / 2;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (priority < arr[mid].priority)
			{
				low = mid + 1;
				mid = low;
			}
			else
			{
				high = mid - 1;
				mid = high + 1;
			}
		}
		auto it = arr.begin() + mid;
		arr.insert(it, temp);
	}
	T pop()
	{
		elem temp = arr.back();
		arr.pop_back();
		return temp.data;
	}
	T lookup_elem()
	{
		elem last = arr.back();
		return last.data;
	}

private:
	struct elem
	{
		T data;
		int priority;
		elem(T Data, int Priority)
		{
			data = Data; priority = Priority;
		}
	};
	std::vector<elem> arr;
};