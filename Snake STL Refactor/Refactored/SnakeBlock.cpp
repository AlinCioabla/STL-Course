#include "stdafx.h"
#include "SnakeBlock.h"


SnakeBlock::SnakeBlock()
: mX(0), mY(0)
{
}

SnakeBlock::SnakeBlock(int aX, int aY)
  : mX(aX), mY(aY)
{
}

SnakeBlock::SnakeBlock(const SnakeBlock & aOther)
  : mX(aOther.mX), mY(aOther.mY)
{
}

SnakeBlock & SnakeBlock::operator =(const SnakeBlock & aOther)
{
  mX = aOther.mX;
  mY = aOther.mY;
  return *this;
}

int SnakeBlock::GetX() const
{
  return mX;
}

int SnakeBlock::GetY() const
{
  return mY;
}

void SnakeBlock::SetX(int aValue)
{
  mX = aValue;
}

void SnakeBlock::SetY(int aValue)
{
  mY = aValue;
}

bool SnakeBlock::operator < (const SnakeBlock & aOther) const
{
  if (this->mX < aOther.mX)
    return true;

  if (this->mX > aOther.mX)
    return false;

  return this->mY < aOther.mY;
}

// ----------------------------------------------------------------------------

bool operator == (const SnakeBlock & aFirst, const SnakeBlock & aSecond)
{
  return aFirst.GetX() == aSecond.GetX() && aFirst.GetY() == aSecond.GetY();
}