#include <iostream>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mSize(0)
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
		: mSize(other.mSize)
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			mPoints[i] = other.mPoints[i];
		}
	}

	PolyLine::~PolyLine()
	{
		for (size_t i = 0; i < mSize; ++i)
		{
			delete mPoints[i];
		}
	}
	
	bool PolyLine::AddPoint(float x, float y)
	{
		if (mSize >= POINTS_CAPACITY)
		{
			return false;
		}

		mPoints[mSize++] = new Point(x, y);

		return true;
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mSize >= POINTS_CAPACITY)
		{
			return false;
		}

		mPoints[mSize++] = point;

		return true;
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (i > mSize)
		{
			return false;
		}

		mPoints[i] = nullptr;
		--mSize;

		return true;
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mSize <= 1)
		{
			return false;
		}

		int minX = std::numeric_limits<int>::max();
		int minY = std::numeric_limits<int>::max();

		int maxX = std::numeric_limits<int>::min();
		int maxY = std::numeric_limits<int>::min();

		for (size_t i = 0; i < mSize; ++i)
		{
			const int POINT_X = mPoints[i]->GetX();
			const int POINT_Y = mPoints[i]->GetY();

			maxX = POINT_X > maxX ? POINT_X : maxX;
			maxY = POINT_Y > maxY ? POINT_Y : maxY;

			minX = POINT_X < minX ? POINT_X : minX;
			minY = POINT_Y < minY ? POINT_Y : minY;
		}

		if (minX == maxX || minY == maxY)
		{
			return false;
		}

		const Point minPoint(minX, minY);
		const Point maxPoint(maxX, maxY);

		*outMin = *outMin + minPoint;
		*outMax = *outMax + maxPoint;
	}
}