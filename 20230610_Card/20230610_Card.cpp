// 20230610_Card.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void game();

int main()
{
    game();
}

void game()
{
    char trump[4][8] = { "Diamond", "Clover", "Heart", "Spade" };
    char trump1[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };

    int numbers[52] = { 0 };
    for (int i = 0; i < 52; i++)
    {
        numbers[i] = i + 1;
    }

    srand(time(NULL));

    int random1 = (rand() % 52) + 1;
    int randomCard1 = numbers[random1];
    int trumpCard1 = randomCard1 / 13;
    int trumpCardNumber1 = randomCard1 % 13;

    int random2 = (rand() % 52) + 1;
    int randomCard2 = numbers[random2];
    int trumpCard2 = randomCard2 / 13;
    int trumpCardNumber2 = randomCard2 % 13;

    printf("Computer Cards: %s %c, %s %c\n", trump[trumpCard1], trump1[trumpCardNumber1], trump[trumpCard2], trump1[trumpCardNumber2]);

    printf("배팅 점수를 입력하십시오: ");
    int bet;
    scanf_s("%d", &bet);

    int playerCardNumber = (rand() % 52) + 1;
    int playerTrumpCard = playerCardNumber / 13;
    int playerTrumpCardNumber = playerCardNumber % 13;

    printf("내 카드: %s %c\n", trump[playerTrumpCard], trump1[playerTrumpCardNumber]);

    bool playerWins = false;
    if ((trumpCardNumber1 < playerTrumpCardNumber && playerTrumpCardNumber < trumpCardNumber2) ||
        (trumpCardNumber2 < playerTrumpCardNumber && playerTrumpCardNumber < trumpCardNumber1))
    {
        playerWins = true;
    }

    if (playerWins)
    {
        printf("승리 입니다\n");
        int winnings = bet * 2;
        printf("You earned %d points.\n", winnings);
        
    }
    else
    {
        printf("패배 입니다\n");
        printf("You lost %d points.\n", bet);
       
    }
}