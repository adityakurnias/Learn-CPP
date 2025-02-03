#include <iostream>
#include <time.h>

int main()
{
    // Set up the field by using Multidimensional Array
    int koordinat[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    // Place the enemy in a random location
    int row, col;
    int lives = 3;
    srand(time(0));
    int colRandom = rand() % 5, rowRandom = rand() % 5;
    koordinat[rowRandom][colRandom] = 1;

    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "You have " << lives << " lives." << std::endl;

    // Game loop
    while (lives != 0)
    {
        std::cout << "Guess enemy location!" << std::endl;
        std::cout << "Row Coordinate (0-4): ";
        std::cin >> row;
        std::cout << "Column Coordinate (0-4): ";
        std::cin >> col;

        // Update the field based on the user's guess
        if (koordinat[row][col] == true)
        {
            koordinat[row][col] = 3;
            std::cout << "You hit the enemy!" << std::endl;
            lives -= lives;
        }
        else if (koordinat[row][col] == false)
        {
            koordinat[row][col] = 2;
            std::cout << "You missed the enemy! \n";
            lives--;
        }
    }

    // Print the field if the game is over
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << koordinat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "2 is the location you guessed, 1 is the enemy location and 3 is the enemy location that has been guessed" << std::endl;
    return 0;
}