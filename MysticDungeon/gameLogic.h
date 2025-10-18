#include "declaration.h"
#include <ctime>


static int randomZeroToThree() {
    static bool srandInitialized = false;
    if (!srandInitialized) {
        srand(time(0));
        srandInitialized = true;
    }
    return rand() % 4;
}
int zeroToThree = randomZeroToThree();


static bool randomDayNight() {
    if (zeroToThree % 2 == 0) {
        return false;
    }
    else {
      return true;
    }
}
bool isNight = randomDayNight();


Character getPlayerChoice(std::wstring character)
{
    Character playerChoice{};
    if (character == L"wizard") {
        playerChoice = wizard;
    }
    else if (character == L"knight") {
        playerChoice = knight;
    }
    else if (character == L"thief") {
        playerChoice = thief;
    }
    else if (character == L"vampire") {
        playerChoice = vampire;
    }
    else if (character == L"archer") {
        playerChoice = archer;
    }
    return playerChoice;
}
static std::wstring stringPlayerChoice(Character character)
{
    std::wstring playerChoice;

    switch (character)
    {
    case wizard: playerChoice = L"Wizard";
        break;
    case knight: playerChoice = L"Knight";
        break;
    case thief: playerChoice = L"Thief";
        break;
    case vampire: playerChoice = L"Vampire";
        break;
    case archer: playerChoice = L"Archer";
        break;
    }
    return playerChoice;
}
static int characterHealt(int character)
{
    int health = 0;
    switch (character)
    {
    case wizard: health = isNight ? 24 : 20;
        break;
    case knight: health = isNight ? 110 : 100;
        break;
    case thief: health = isNight ? 52 : 40;
        break;
    case vampire: health = isNight ? 120 : 80;
        break;
    case archer: health = isNight ? 84 : 60;
        break;
    }
    return health;
}
static int gainHealth(Character character, int& playerHealth)
{

    srand(time(0));
    int random = rand() % 10 + 1;

    switch (character) {
    case wizard: playerHealth = playerHealth + (random + 20);//20-30
        break;
    case knight: playerHealth = playerHealth + (random + 10);//10-20
        break;
    case thief: playerHealth = playerHealth + (random + 30);//30-40
        break;
    case vampire: playerHealth = playerHealth + random;//1-10
        break;
    case archer: playerHealth = playerHealth + (random + 40);//40-50
        break;
    }
    if (playerHealth >= 120) {
        playerHealth = 120;
    }
    return playerHealth;
}
static int attack(Character character, int& playerHealth) {

    srand(time(0));
    int randAttack = rand() % 10 + 1;

    switch (character) {
    case wizard: playerHealth = playerHealth - (randAttack + 30);//30-40
        break;
    case knight: playerHealth = playerHealth - (randAttack + 20);//20-30
        break;
    case thief: playerHealth = playerHealth - (randAttack + 40);//40-50
        break;
    case vampire: playerHealth = playerHealth - (randAttack + 10);//10-20
        break;
    case archer: playerHealth = playerHealth - randAttack;//1-10
        break;
    }
    return playerHealth;
}
static int secondAttack(Character character, int& playerHealth) {

    srand(time(0));
    int randAttack = rand() % 5 + 1;

    switch (character) {
    case wizard: playerHealth = playerHealth - (randAttack + 40);
        break;
    case knight: playerHealth = playerHealth - (randAttack + 30);
        break;
    case thief: playerHealth = playerHealth - randAttack;
        break;
    case vampire: playerHealth = playerHealth - (randAttack + 20);
        break;
    case archer: playerHealth = playerHealth - (randAttack + 10);
        break;
    }
    return playerHealth;
}
void handleButtonClick(HWND button, Character character) {
    if (!isClicked) {

        player1.character = character;
        player1.health = characterHealt(player1.character);
        player1Choice = stringPlayerChoice(character);
        DestroyWindow(button);
    }
    else {
        player2.character = character;
        player2Choice = stringPlayerChoice(character);
        player2.health = characterHealt(player2.character);
        if (!isDeleted) {
            DestroyWindow(button5);
            DestroyWindow(button6);
            DestroyWindow(button7);
            DestroyWindow(button8);
            DestroyWindow(button9);
            isDeleted = true;
        }
    }
    isClicked = true;
}

