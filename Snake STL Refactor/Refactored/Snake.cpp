
#include "stdafx.h"
#include "Snake.h"

Snake::Snake(int aNumberOfBlocks, int aGridSize)
: mMovementDirection(MovementDirection::Right), mGridSize(aGridSize)
{
  // initialize snake blocks
  SnakeBlock currentUnit(aNumberOfBlocks, 0);

  mBlocks.reserve(aNumberOfBlocks);

  std::generate_n(back_inserter(mBlocks), aNumberOfBlocks, [&currentUnit]()
  {
    SnakeBlock unit = currentUnit; 
    currentUnit = SnakeBlock(currentUnit.GetX() - 1, currentUnit.GetY());    
    return unit;
  });
}

void Snake::Move()
{
  if (!IsAlive())
    cout << " << Cannot move. The snake is dead >>> ";

  // #STL Implement this block logic this using STL
  {
    // we must shift to left all blocks except the head
	  mBlocks.insert(mBlocks.begin(), *mBlocks.begin());
	  mBlocks.pop_back();
    // now move the head
    MoveHead();
  }
}

void Snake::SetDirection(MovementDirection aDirection)
{
  mMovementDirection = aDirection;
}

MovementDirection Snake::GetDirection() const
{
  return mMovementDirection;
}

void Snake::Reverse()
{
  // #STL Implement this block logic this using STL
  {
    /*// reverse blocks. head becomes tail, tail becomes head
    for (size_t i = 0; i < mBlocks.size() / 2; ++i)
    {
      const int swapIndex = mBlocks.size() - i - 1;

      auto tmp = mBlocks[i];
      mBlocks[i] = mBlocks[swapIndex];
      mBlocks[swapIndex] = tmp;
    }
	*/
	reverse(mBlocks.begin(), mBlocks.end());
  }

  


  // now let's reverse the movement direction
  switch (mMovementDirection)
  {
  case MovementDirection::Up:
    mMovementDirection = MovementDirection::Down;
    break;
  case MovementDirection::Down:
    mMovementDirection = MovementDirection::Up;
    break;
  case MovementDirection::Left:
    mMovementDirection = MovementDirection::Right;
    break;
  case MovementDirection::Right:
    mMovementDirection = MovementDirection::Left;
    break;
  }
}

const SnakeBlock & Snake::GetHead() const
{
  return *mBlocks.begin();
}

bool Snake::IsPartOfSnake(int aX, int aY) const
{
  // #STL Implement this block logic this using STL
  /*{
    for (size_t i = 0; i < mBlocks.size(); ++i)
      if (mBlocks[i].GetX() == aX && mBlocks[i].GetY() == aY)
        return true;
    return false;
  }*/
  return mBlocks.end() != find_if(mBlocks.begin(), mBlocks.end(), [&aX, &aY](const SnakeBlock &x) { return x.GetX() == aX && x.GetY() == aY; });

}

bool Snake::IsHeadOfSnake(int aX, int aY) const
{
  const SnakeBlock & head = GetHead();
  return head.GetX() == aX && head.GetY() == aY;
}

bool Snake::IsAlive() const
{
  // check if we are out of the grid
  const SnakeBlock & snakeHead = GetHead();
  if (snakeHead.GetX() < 0 || snakeHead.GetY() < 0)
    return false;
  if (snakeHead.GetX() >= mGridSize || snakeHead.GetY() >= mGridSize)
    return false;
  /*
  // #STL Implement this block logic this using STL
  {
    // mBlocks[0] is the snake head. We need to check if mBlocks[1]...mBlocks[n] intersects with the head
    for (size_t i = 1; i < mBlocks.size(); ++i)
      if (mBlocks[i] == snakeHead)
        return false;
  }
  return true;
  */
  return mBlocks.end() == find(mBlocks.begin() + 1, mBlocks.end(),snakeHead);
}

SnakeBlock & Snake::GetHead()
{    
  return *mBlocks.begin();
}

void Snake::MoveHead()
{
  SnakeBlock & snakeHead = GetHead();

  switch (mMovementDirection)
  {
  case MovementDirection::Up:
    snakeHead.SetY(snakeHead.GetY() - 1);
    break;
  case MovementDirection::Down:
    snakeHead.SetY(snakeHead.GetY() + 1);
    break;
  case MovementDirection::Left:
    snakeHead.SetX(snakeHead.GetX() - 1);
    break;
  case MovementDirection::Right:
    snakeHead.SetX(snakeHead.GetX() + 1);
    break;
  }
}