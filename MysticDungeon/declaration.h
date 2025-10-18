#include <windows.h>
#include <string>
#include <chrono>
#include <thread>
#include <memory>
#include <vector>
#include <unordered_map>
#include <gdiplus.h>
//#include <cmath>
//#include <cwchar>
//#include <array>
//#include <stdint.h>



HINSTANCE hInstance;
#define IDC_BUTTON1 1101
HWND button1;
#define IDC_BUTTON2 1102
HWND button2;
#define IDC_BUTTON3 1103
HWND button3;
#define IDC_BUTTON4 1104
HWND button4;
#define IDC_BUTTON5 1108
HWND button5;
#define IDC_BUTTON6 1109
HWND button6;
#define IDC_BUTTON7 1110
HWND button7;
#define IDC_BUTTON8 1111
HWND button8;
#define IDC_BUTTON9 1112
HWND button9;
#define IDC_BUTTON10 1113
HWND button10;




bool running = true;
bool gameStarted = true;
int currentTab = 0; // menu tab = 0 , rules tab = 1, cose character tab = 2, game = 3

bool isClicked = false;
bool isDeleted = false;

std::wstring player1Choice;
std::wstring player2Choice;
std::wstring displayHealth1;
std::wstring displayHealth2;


struct Button_State {
    bool is_down;
    bool changed;
    bool is_released;
    bool is_pressed;
    bool was_down;
};

enum BUTTON{
    BUTTON_A,
    BUTTON_S,
    BUTTON_D,
    BUTTON_W,
    BUTTON_X,
    BUTTON_Z,
    BUTTON_C,
    BUTTON_I,
    BUTTON_J,
    BUTTON_K,
    BUTTON_L,
    BUTTON_B,
    BUTTON_N,
    BUTTON_M,

    BUTTON_COUNT,
};

struct Input {
    Button_State buttons[BUTTON_COUNT];
};
Input input = {};

struct Vector {

    Vector() : x(0), y(0) {}
    Vector(float X, float Y) : x(X), y(Y) {}
  

    float Length() const {
        return std::sqrt(x * x + y * y);
    }

    float LengthSquared()const {
        return x * x + y * y;
    }

    Vector Normalize() const {
        float length = Length();
        if (length!=0) {
            return Vector(x / length, y / length);
        }
        return Vector(0, 0);
    }

    Vector operator*(float s) const {
        return Vector(x * s, y * s);  
    }

    Vector operator/(float s) const {
        return Vector(x / s, y / s);
    }

    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }
    Vector operator-(const Vector& v) const {
        return Vector(x - v.x, y - v.y);
    }

    float x, y;
};

struct Point {
    float x, y;

    Point() : x(0), y(0) {}
    Point(float X, float Y) : x(X), y(Y) {}

    Point AddVector(const Vector& v) const {
        return Point(x + v.x, y + v.y);
    }

    Point SubtractVector(const Vector& v) const {
        return Point(x - v.x, y - v.y);
    }

    float DistanceTo(const Point& p) const {
        return std::sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

  
};


Vector velocityPlayer1(0.0f, 0.0f);
Vector velocityPlayer2(0.0f, 0.0f);
Vector gravity(0, 1670.0f);
float playerSpeed = 450.0f;         
float jumpForce = -1000.0f;         
float friction = 0.9f;            



enum Character
{
    wizard = 0,
    knight = 1,
    thief = 2,
    vampire = 3,
    archer = 4
};


std::chrono::steady_clock::time_point lastFrameTime;
int frameDelay = 100;


struct Limits {
    int min;
    int max;
};

struct CollisionBox {
    Limits width;
    Limits hight;
};

enum AnimationType {
    Idle,
    Walk,
    DodgeOrBlock,
    Attack1,
    Attack2,
    Healing,
    Throwing1,
    Throwing2,
    Take_damage

};

struct CharacterAnimations {

    std::vector<std::unique_ptr<Gdiplus::Image>> stayRight;
    std::vector<std::unique_ptr<Gdiplus::Image>> stayLeft;
    std::vector<std::unique_ptr<Gdiplus::Image>> walkRight;
    std::vector<std::unique_ptr<Gdiplus::Image>> walkLeft;
    std::vector<std::unique_ptr<Gdiplus::Image>> attack1Right;
    std::vector<std::unique_ptr<Gdiplus::Image>> attack1Left;
    std::vector<std::unique_ptr<Gdiplus::Image>> attack2Right;
    std::vector<std::unique_ptr<Gdiplus::Image>> attack2Left;
    std::vector<std::unique_ptr<Gdiplus::Image>> dodgeOrBlockRight;
    std::vector<std::unique_ptr<Gdiplus::Image>> dodgeOrBlockLeft;
    std::vector<std::unique_ptr<Gdiplus::Image>> healing;
    std::vector<std::unique_ptr<Gdiplus::Image>> throwing_right;
    std::vector<std::unique_ptr<Gdiplus::Image>> throwing_left;
    std::vector<std::unique_ptr<Gdiplus::Image>> throwing2_right;
    std::vector<std::unique_ptr<Gdiplus::Image>> throwing2_left;
    std::vector<std::unique_ptr<Gdiplus::Image>> takeDamage;

};

struct Player {
    Point position;
    Vector velocity;
    Vector throwable1_velocity;
    Vector throwable2_velocity;
    int health;
    bool isMoving = false;
    bool isOnGround = false;
    bool isLookingRight = true;
    bool isAttacking1 = false;
    bool isAttacking2 = false;
    bool isHealing = false;
    int currentFrame = 0;
    bool isDodgingOrBlocking = false; 
    bool isThrowingSomething = false;
    bool isThrowingSomething2 = false;
    bool throwable1_isMovingRight = true;
    bool throwable2_isMovingRight = true;
    bool isHit = false;
    bool throwable1_hasHit = false;
    bool throwable2_hasHit = false;

    bool hasDodgeOrBlockStarted = false;
    bool hasAttack1Started = false;
    bool hasAttack2Started = false;
    bool hasHealingStarted = false;
    bool hasAttack1Ended = false;
    bool meleeAttack1_hasHit = false;
    bool meleeAttack2_hasHit = false;
    
    float attack1CooldownDuration = 1.0f;
    float attack2CooldownDuration = 2.0f; 
    float healingCooldownDuration = 4.0f; 

    // Cooldown timers
    float attack1CooldownTimer = 0.0f;
    float attack2CooldownTimer = 0.0f;
    float healingCooldownTimer = 0.0f;

    float attackBufferTimer = 0.0f;

    Character character;
    CharacterAnimations animations;
    CollisionBox hitBox;
    CollisionBox throwable1_position;
    CollisionBox throwable2_position;
    CollisionBox attack1Weapon_position;
};

Player player1, player2;
CollisionBox arena;



const std::unordered_map<Character, std::unordered_map<AnimationType, int>> animationFrameCounts = {
    {knight, {
        {Idle, 4}, {Walk, 8}, {DodgeOrBlock, 7}, {Attack1, 6}, {Attack2, 7}, {Healing, 8}, {Throwing1, 8}, {Throwing2, 8},{Take_damage,6}
    }},
    {thief, {
        {Idle, 6}, {Walk, 8}, {DodgeOrBlock, 7}, {Attack1, 4}, {Attack2, 7}, {Healing, 8}, {Throwing1, 3}, {Throwing2, 3},{Take_damage,6}
    }},
    {vampire, {
        {Idle, 6}, {Walk, 8}, {DodgeOrBlock, 7}, {Attack1, 5}, {Attack2, 4}, {Healing, 8}, {Throwing1, 2}, {Throwing2, 2},{Take_damage,6}
    }},
    {wizard, {
        {Idle, 4}, {Walk, 8}, {DodgeOrBlock, 6}, {Attack1, 4}, {Attack2, 6}, {Healing, 8}, {Throwing1, 3}, {Throwing2, 3},{Take_damage,6}
    }},
    {archer, {
        {Idle, 4}, {Walk, 8}, {DodgeOrBlock, 6}, {Attack1, 8}, {Attack2, 8}, {Healing, 8}, {Throwing1, 1}, {Throwing2, 1},{Take_damage,6}
    }}
};


struct CharacterConfig {
    bool attack1IsThrowable;
    bool attack2IsThrowable;
};

std::unordered_map<Character, CharacterConfig> characterConfigs = {
    {Character::archer,{true, true}},
    {Character::knight,{false, true}},
    {Character::thief,{false, true}},
    {Character::vampire,{true, false}},
    {Character::wizard,{false, true}},

};

