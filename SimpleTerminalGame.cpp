#include <iostream>
#include <time.h>

int main()
{
    int koordinat[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    int row, col;
    int lives = 3;
    srand(time(0));
    int colRandom = rand() % 5, rowRandom = rand() % 5;
    koordinat[rowRandom][colRandom] = 1;

    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "You have " << lives << " lives." << std::endl;

    while (lives >= 0)
    {
        std::cout << "Tebak lokasi musuh!" << std::endl;
        std::cout << "Masukkan koordinat row (0-4): ";
        std::cin >> row;
        std::cout << "Masukkan koordinat col (0-4): ";
        std::cin >> col;

        if (koordinat[row][col] == true)
        {
            koordinat[row][col] = 3;
            std::cout << "You hit the enemy!" << std::endl;
            lives -= lives;
        }
        else if (koordinat[row][col] == false)
        {
            koordinat[row][col] = 2;
            std::cout << "You missed the enemy!" << std::endl;
            lives--;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << koordinat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "2 adalah lokasi yang kamu tebak, 1 adalah lokasi musuh dan 3 adalah lokasi musuh yang sudah ketebak" << std::endl;
    return 0;
}