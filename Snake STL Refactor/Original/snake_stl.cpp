// snake_stl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Snake.h"

// ----------------------------------------------------------------------------

namespace GameDefaults
{
  const int kGridSize = 22;
  const int kSnakeLength = 12;
  const int kFoodCount = 5;
}

using SnakeFood = set<SnakeBlock>;

/**
 * Hide or show cursor on console
 */
void ShowConsoleCursor(bool showFlag)
{
  HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

  CONSOLE_CURSOR_INFO     cursorInfo;

  GetConsoleCursorInfo(out, &cursorInfo);
  cursorInfo.bVisible = showFlag;
  SetConsoleCursorInfo(out, &cursorInfo);
}

SnakeFood GenerateFood()
{
  SnakeFood food;
  random_device r;
  // Choose a random mean between 1 and 6
  default_random_engine e1(r());
  uniform_int_distribution<int> uniform_dist(0, GameDefaults::kGridSize - 1);

  for (int i = 0; i < GameDefaults::kFoodCount; ++i)
  {
    int xFood = uniform_dist(e1);
    int yFood = uniform_dist(e1);

    food.insert(SnakeBlock{ xFood, yFood });
  }

  return food;
}

bool IsFood(const SnakeFood & aFood, int aX, int aY)
{
  SnakeBlock potentialFood(aX, aY);

  // #STL Implement this block logic this using STL
  {
    // check if we can find the given coordinates in the snake food
    for (auto it = aFood.begin(), itEnd = aFood.end(); it != itEnd; ++it)
      if (*it == potentialFood)
        return true;
    return false;
  }
}

/**
* Print snake and map to the console.
*/
void PrintSnake(const Snake & aSnake, const SnakeFood & aSnakeFood)
{
  for (int yRow = 0; yRow < GameDefaults::kGridSize; ++yRow)
  {
    for (int xCol = 0; xCol < GameDefaults::kGridSize; ++xCol)
    {
      if (aSnake.IsPartOfSnake(xCol, yRow))
      {
        if (aSnake.IsHeadOfSnake(xCol, yRow))
          cout << "H ";
        else
          cout << "x ";
      }
      else if (IsFood(aSnakeFood, xCol, yRow))
      {
        cout << "f ";
      }
      else // just empty map space
      {
        cout << ". ";
      }
    }

    cout << endl;
  }
}

int main()
{
  Snake snake(GameDefaults::kSnakeLength, GameDefaults::kGridSize);
  SnakeFood snakeFood = GenerateFood();
  int gamePoints = 0;

  ShowConsoleCursor(false);

  // the main game loop
  while (true)
  {
    system("cls");
    cout << "\n         S T L  S N A K E \n";
    cout << "         " << gamePoints << " POINTS" << endl;
    cout << "You can use arrows to move the snake around. \nPress shift to go reverse." << endl << endl;
    
    PrintSnake(snake, snakeFood);

    const MovementDirection currentSnakeMovement = snake.GetDirection();

    if (GetAsyncKeyState(VK_LEFT) && currentSnakeMovement != MovementDirection::Right)
      snake.SetDirection(MovementDirection::Left);
    if (GetAsyncKeyState(VK_RIGHT) && currentSnakeMovement != MovementDirection::Left)
      snake.SetDirection(MovementDirection::Right);
    if (GetAsyncKeyState(VK_DOWN) && currentSnakeMovement != MovementDirection::Up)
      snake.SetDirection(MovementDirection::Down);
    if (GetAsyncKeyState(VK_UP) && currentSnakeMovement != MovementDirection::Down)
      snake.SetDirection(MovementDirection::Up);
    if (GetAsyncKeyState(VK_SHIFT))
      snake.Reverse();

    if (GetAsyncKeyState(VK_ESCAPE))
    {
      cout << "Goodbye" << endl;
      break; // ESC pressed. break loop
    }

    if (!snake.IsAlive())
    {
      cout << "Snake has died" << endl;
      break; // loop ends
    }

    // check if we have got any new points
    {
      // #STL Implement this block logic this using STL
      {
        // see if we can find a snake block with equal coordinates with snake head
        for (auto it = snakeFood.begin(), endIt = snakeFood.end(); it != endIt; ++it)
        {
          if (snake.IsHeadOfSnake(it->GetX(), it->GetY()))
          {
            // we found a block equal to the head, increase points and consume (erase) food
            gamePoints++;
            snakeFood.erase(it);
            break;
          }
        }
      }

      if (snakeFood.empty())
      {
        cout << "You WON. Congratulations!" << endl;
        break; // loop ends
      }
    }

    snake.Move();
    Sleep(400);
  }
  cout << "Press any key to exit";
  cin.get();
}