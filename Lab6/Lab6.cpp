#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int sum = 0;

		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		{
			sum += *it;
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		int result = MAX;

		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		{
			if (*it < result)
			{
				result = *it;
			}
		}

		return result;
	}

	int Max(const std::vector<int>& v)
	{
		int result = MIN;

		for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		{
			if (*it > result)
			{
				result = *it;
			}
		}

		return result;
	}

	float Average(const std::vector<int>& v)
	{
		return static_cast<float>(Sum(v)) / v.size();
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		// ��� �� vector�� ���� ���̸� ��� �迭�� �������� �Ҵ� �� ���̸� ���� �迭�� ���鼭 ���� �� ���� Ȯ��
		return 0;
	}

	void SortDescending(std::vector<int>& v)
	{

	}

	void QuickSortRecursive(std::vector<int>& v)
	{

	}
}