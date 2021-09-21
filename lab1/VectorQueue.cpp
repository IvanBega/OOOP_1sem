#include "Queue.cpp"
#include <vector>
template <class T>
class VectorQueue : Queue<T>
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
		int i = 0;
		while ( i < arr.size() && priority < arr[i].priority)
		{
			i++;
		}
		auto it = arr.begin() + i;
		arr.insert(it, temp);
	}
	T pop()
	{
		if (arr.empty())
			return NULL;
		elem temp = arr.back();
		arr.pop_back();
		return temp.data;
	}
	T lookup_elem()
	{
		elem last = arr.back();
		arr.pop_back();
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