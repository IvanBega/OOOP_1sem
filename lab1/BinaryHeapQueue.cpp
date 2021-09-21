#include "Queue.cpp"
#include <vector>
template<class T>
class BinaryHeapQueue : Queue<T>
{
public:

	void push(T data, int priority)
	{
		size = size + 1;
		elem temp(data, priority);
		arr.push_back(temp);

		heapify(size);
	}
	T lookup_elem()
	{
		return arr[0].data;
	}
	T pop()
	{
		T data = arr[0].data;
		std::swap(arr[0], arr[size]);
		arr.pop_back();
		size--;

		moveDown(0);
		return data;
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
	int size = -1;
	int parentIndex(int i)
	{
		return (i - 1) / 2;
	}
	int leftChildIndex(int i)
	{

		return 2 * i + 1;
	}
	int rightChildIndex(int i)
	{
		return 2 * i + 2;
	}
	void heapify(int i)
	{
		while (i > 0 && arr[parentIndex(i)].priority > arr[i].priority)
		{
			std::swap(arr[parentIndex(i)], arr[i]);
			i = parentIndex(i);
		}
	}
	void moveDown(int i)
	{
		int max = i;
		int l = leftChildIndex(i);
		if (l <= size && arr[l].priority < arr[max].priority)
		{
			max = l;
		}

		int r = rightChildIndex(i);
		if (r <= size && arr[r].priority < arr[max].priority)
		{
			max = r;
		}

		if (i != max)
		{
			std::swap(arr[i], arr[max]);
			moveDown(max);
		}
	}
};