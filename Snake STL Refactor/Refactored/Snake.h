#pragma once

#include "stdafx.h"
#include "SnakeBlock.h"

/**
* Class that defines a snake. It is able to move one step at a time
* in a given 2D direction. It is clever and makes use of elegant and efficient STL algorithms.
*/
class Snake
{
public:

  /**
  * Constructs a snake. It will have aNumberOfBlocks unit blocks by default
  * and a direction of movement to the right.
  */
  Snake(int aNumberOfBlocks, int aGridSize);

  /**
  * Perform one step of snake movement in its move direction
  */
  void Move();

  /**
  * Set a direction of movement for the snake. You have to call Move() for movement
  * to actually happen.
  */
  void SetDirection(MovementDirection aDirection);

  /**
   * Get movement direction of snake.
   */
  MovementDirection GetDirection() const;

  /**
  * Reverse the snake, tail becomes head, head becomes tail
  */
  void Reverse();

  /**
   * Detects if a given coordinate pair is part of the snake
   */
  bool IsPartOfSnake(int aX, int aY) const;

  /**
  * Detects if a given coordinate pair is the snake head
  */
  bool IsHeadOfSnake(int aX, int aY) const;

  /**
  * Detects if the snake intersects with itself (two of its blocks share the same location in space)
  */
  bool IsAlive() const;

private:

  /**
  * Get reference to snake head.
  */
  SnakeBlock & GetHead();

  /**
  * Get const reference to snake head.
  */
  const SnakeBlock & GetHead() const;

  /**
  * Moves the head of the snake one unit in its direction of movement.
  */
  void MoveHead();

  // block units that make up the snake, the first is the snake's head, the last its tail
  vector<SnakeBlock> mBlocks;

  // direction of movement for the snake
  MovementDirection mMovementDirection;

  // size of grid in which the snake moves
  int mGridSize;
};