#pragma once

/**
* Class that encodes a point in a two-dimensional Cartesian space.
*/
class SnakeBlock
{
public:
  SnakeBlock();

  SnakeBlock(int aX, int aY);

  SnakeBlock(const SnakeBlock & aOther);

  SnakeBlock & operator =(const SnakeBlock & aOther);

  int GetX() const;

  int GetY() const;

  void SetX(int aValue);

  void SetY(int aValue);

  bool operator < (const SnakeBlock & aOther) const;

protected:
  int mX, mY;
};

// ----------------------------------------------------------------------------

enum class MovementDirection
{
  Up,
  Right,
  Down,
  Left
};

// ----------------------------------------------------------------------------

/**
 * Equality operator between two points.
 */
bool operator == (const SnakeBlock & aFirst, const SnakeBlock & aSecond);