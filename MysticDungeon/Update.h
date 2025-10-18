#include "ProcessKeyEvent.h"

void AdjustWeaponPosition(Player& player, bool isAttack1) {
    player.attack1Weapon_position.width.min = player.position.x - 10;
    player.attack1Weapon_position.width.max = player.position.x + 10;
    player.attack1Weapon_position.hight.min = player.position.y - 10;
    player.attack1Weapon_position.hight.max = player.position.y + 10;

    if (isAttack1) {
       
        switch (player.character) {
        case knight:
            player.attack1Weapon_position.hight.min += 30;
            player.attack1Weapon_position.hight.max += 50;

            player.isLookingRight ? (player.attack1Weapon_position.width.max += 170 , 
                                     player.attack1Weapon_position.width.min -= 80) :
                                    (player.attack1Weapon_position.width.max += 150,
                                     player.attack1Weapon_position.width.min -= 100);
        

            break;
        case wizard:
            player.attack1Weapon_position.hight.min -= 50;
            player.attack1Weapon_position.hight.max += 40;

            player.isLookingRight ? (player.attack1Weapon_position.width.max += 217,
                                     player.attack1Weapon_position.width.min += 117) :
                                    (player.attack1Weapon_position.width.max -= 30,
                                     player.attack1Weapon_position.width.min -= 120);

            break;
        case thief:
            player.attack1Weapon_position.hight.min -= 45;
            player.attack1Weapon_position.hight.max += 17;

            player.isLookingRight ? (player.attack1Weapon_position.width.max += 110,
                                     player.attack1Weapon_position.width.min += 90) :
                                    (player.attack1Weapon_position.width.max -= 40,
                                     player.attack1Weapon_position.width.min -= 60);
             
            break;
        }


    }
    else {
        switch (player.character) {
        case vampire:
            player.attack1Weapon_position.hight.min -= 45;
            player.attack1Weapon_position.hight.max += 17;

            player.isLookingRight ? (player.attack1Weapon_position.width.max += 120,
                                     player.attack1Weapon_position.width.min += 100) :
                                    (player.attack1Weapon_position.width.max -= 50,
                                     player.attack1Weapon_position.width.min -= 70);

            break;
        }
    }


}

void UpdateThrowable(Player& player, float deltaTime, const CollisionBox& arena) {
    float throwableSpeed = 300.0f; // Example speed value for throwable

    // Update throwable 1 movement
    if (player.isThrowingSomething) {
        // Update position based on its velocity
        player.throwable1_position.width.min += player.throwable1_velocity.x * deltaTime;
        player.throwable1_position.width.max += player.throwable1_velocity.x * deltaTime;
        player.throwable1_position.hight.min += player.throwable1_velocity.y * deltaTime;
        player.throwable1_position.hight.max += player.throwable1_velocity.y * deltaTime;

        // Check if the throwable 1 is out of bounds
        if (player.throwable1_position.width.max < arena.width.min ||
            player.throwable1_position.width.min > arena.width.max) {
            // Reset throwable position to the character
            player.throwable1_position.width.min = player.position.x - 10.0f; // Adjust for character's size
            player.throwable1_position.width.max = player.position.x + 10.0f;
            player.throwable1_position.hight.min = player.position.y - 10.0f;
            player.throwable1_position.hight.max = player.position.y + 10.0f;

            // Stop throwing
            player.isThrowingSomething = false;
            player.throwable1_velocity = { 0.0f, 0.0f }; // Reset velocity
            player.throwable1_hasHit = false;
        }
    }

    // Update throwable 2 movement
    if (player.isThrowingSomething2) {
        // Update position based on its velocity
        player.throwable2_position.width.min += player.throwable2_velocity.x * deltaTime;
        player.throwable2_position.width.max += player.throwable2_velocity.x * deltaTime;
        player.throwable2_position.hight.min += player.throwable2_velocity.y * deltaTime;
        player.throwable2_position.hight.max += player.throwable2_velocity.y * deltaTime;

        // Check if the throwable 2 is out of bounds
        if (player.throwable2_position.width.max < arena.width.min ||
            player.throwable2_position.width.min > arena.width.max) {
            // Reset throwable position to the character
            player.throwable2_position.width.min = player.position.x - 10.0f;
            player.throwable2_position.width.max = player.position.x + 10.0f;
            player.throwable2_position.hight.min = player.position.y - 10.0f;
            player.throwable2_position.hight.max = player.position.y + 10.0f;

            // Stop throwing
            player.isThrowingSomething2 = false;
            player.throwable2_velocity = { 0.0f, 0.0f }; // Reset velocity
            player.throwable2_hasHit = false;
        }
    }
}

void Throw(Player& player, bool isThrowable1) {
    
    float throwableSpeed = 400;// Example speed value for throwable

    if (isThrowable1) {
        // Initialize the throwable 1's position and velocity

        player.throwable1_position.width.min = player.position.x - 10.0f;
        player.throwable1_position.width.max = player.position.x + 10.0f;
        player.throwable1_position.hight.min = player.position.y - 10.0f;
        player.throwable1_position.hight.max = player.position.y + 10.0f;

        switch (player.character) {
        case archer: 
            player.throwable1_position.width.max += 60.0f;
            break;
        case vampire:
            player.throwable1_position.hight.min -= 20.0f;
            player.throwable1_position.hight.max += 20.0f;
            player.throwable1_position.width.max += 60.0f;
            break;
        }
       
        player.throwable1_isMovingRight = player.isLookingRight;
        player.throwable1_velocity = player.isLookingRight ? Vector{ throwableSpeed, 0.0f } : Vector{ -throwableSpeed, 0.0f };
        player.isThrowingSomething = true;
    }
    else {
        // Initialize the throwable 2's position and velocity
        player.throwable2_position.width.min = player.position.x - 10.0f;
        player.throwable2_position.width.max = player.position.x + 10.0f;
        player.throwable2_position.hight.min = player.position.y - 10.0f;
        player.throwable2_position.hight.max = player.position.y + 10.0f;

        switch (player.character) {
        case archer:
            player.throwable2_position.width.max += 50.0f;
            break;
        case thief:
            player.throwable2_position.hight.min += 40.0f;
            player.throwable2_position.hight.max += 40.0f;
            break;
        case wizard:
            player.throwable2_position.hight.min += 40.0f;
            player.throwable2_position.hight.max += 60.0f;
            player.throwable2_position.width.max += 50.0f;
            break;
        case knight:
            player.throwable2_position.hight.min += 75.0f;
            player.throwable2_position.hight.max += 75.0f;
            player.throwable2_position.width.max += 140.0f;
      
            break;
        }

        player.throwable2_isMovingRight = player.isLookingRight;
        player.throwable2_velocity = player.isLookingRight ? Vector{ throwableSpeed, 0.0f } : Vector{ -throwableSpeed, 0.0f };
        player.isThrowingSomething2 = true;
    }
}
void TakeDamage1(Player& attacker, Player& defender, bool& isThrowing, bool& hasHit, const CollisionBox& attackPosition, int(*attackFunction)(Character, int&)) {
    if (isThrowing && !hasHit) {
        if (collisionWithPlayer_Attack(defender.hitBox, attackPosition) && !defender.isDodgingOrBlocking) {
            defender.isHit = true;
            hasHit = true;
            attackFunction(attacker.character, defender.health);
            defender.isHit = false;
        }
    }
}
void TakeDamage(Player& player1, Player& player2) {
    TakeDamage1(player1, player2, player1.isThrowingSomething, player1.throwable1_hasHit, player1.throwable1_position, attack);
    TakeDamage1(player1, player2, player1.isThrowingSomething2, player1.throwable2_hasHit, player1.throwable2_position, secondAttack);
    TakeDamage1(player2, player1, player2.isThrowingSomething, player2.throwable1_hasHit, player2.throwable1_position, attack);
    TakeDamage1(player2, player1, player2.isThrowingSomething2, player2.throwable2_hasHit, player2.throwable2_position, secondAttack);
    TakeDamage1(player1, player2, player1.isAttacking1, player1.meleeAttack1_hasHit, player1.attack1Weapon_position, attack);
    TakeDamage1(player1, player2, player1.isAttacking2, player1.meleeAttack2_hasHit, player1.attack1Weapon_position, secondAttack);
    TakeDamage1(player2, player1, player2.isAttacking1, player2.meleeAttack1_hasHit, player2.attack1Weapon_position, attack);
    TakeDamage1(player2, player1, player2.isAttacking2, player2.meleeAttack2_hasHit, player2.attack1Weapon_position, secondAttack);
}

void UpdatePlayerFrame(Player& player, const std::unordered_map<Character, std::unordered_map<AnimationType, int>>& animationFrameCounts) {
    static int takeDamageTimer = 0;
    if (player.isHit) {
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Take_damage);

    }
    else if (player.isAttacking1) {
        // Update the frame for the attack animation
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Attack1);
    }
    else if (player.isAttacking2) {
        // Update the frame for the attack animation
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Attack2);
    }
    else if (player.isHealing) {
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Healing);
    }
    else if (player.isDodgingOrBlocking) {
        // Update the frame for the dodge/block animation
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(DodgeOrBlock);
    }
    else if (player.isThrowingSomething) {
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Throwing1);
    }
    else if (player.isThrowingSomething2) {
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Throwing2);
    }
    else if (player.isMoving) {
        // Update the frame for the walking animation
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Walk);
    }
    else {
        // Update the frame for the idle animation
        player.currentFrame = (player.currentFrame + 1) % animationFrameCounts.at(player.character).at(Idle);
    }
}

void UpdatePlayerState(Player& player, Vector& velocity, const Input& input, const CollisionBox& arena, float deltaTime, float jumpForce, float playerSpeed, float friction, const Vector& gravity, int upKey, int leftKey, int downKey, int rightKey, int attack1Key, int attack2Key, int healingKey, std::unordered_map<Character, CharacterConfig> characterConfigs) {
    if (!(input.buttons[leftKey].changed || input.buttons[rightKey].changed || input.buttons[downKey].changed || input.buttons[upKey].changed)) {
        player.isMoving = false;
    }
    if (player.attack1CooldownTimer > 0.0f) {
        player.attack1CooldownTimer -= deltaTime;
        if (player.attack1CooldownTimer < 0.0f) player.attack1CooldownTimer = 0.0f;
    }

    if (player.attack2CooldownTimer > 0.0f) {
        player.attack2CooldownTimer -= deltaTime;
        if (player.attack2CooldownTimer < 0.0f) player.attack2CooldownTimer = 0.0f;
    }

    if (player.healingCooldownTimer > 0.0f) {
        player.healingCooldownTimer -= deltaTime;
        if (player.healingCooldownTimer < 0.0f) player.healingCooldownTimer = 0.0f;
    }

    // Healing logic
    if (input.buttons[healingKey].is_pressed && player.healingCooldownTimer == 0.0f && !player.hasHealingStarted) {
        player.isHealing = true;
        player.hasHealingStarted = true;
        player.healingCooldownTimer = player.healingCooldownDuration; // Reset healing cooldown

        gainHealth(player.character, player.health);
    }

    if (player.isHealing) {
        if (player.currentFrame == 0) {
            player.isHealing = false;
            player.hasHealingStarted = false;
        }
    }

  

    // Attack 1 logic
 
    if (input.buttons[attack1Key].is_pressed) {
        player.attackBufferTimer = 0.1f; // Store attack input briefly (100ms)
    }

    if (player.attackBufferTimer > 0) {
        player.attackBufferTimer -= deltaTime; // Reduce buffer timer over time
    }

    // Start attack only if key was just pressed and not during cooldown
    if (player.attackBufferTimer > 0 && player.attack1CooldownTimer == 0.0f && !player.hasAttack1Started && player.isOnGround) {
        player.isAttacking1 = true;
        player.hasAttack1Started = true;
        player.attack1CooldownTimer = player.attack1CooldownDuration;
        player.currentFrame = 0;  // Ensure animation starts at frame 0
        player.attackBufferTimer = 0; // Clear buffer to avoid repeated attacks
    }

    if (player.isAttacking1) {
        AdjustWeaponPosition(player, true);
        int lastAttackFrame = animationFrameCounts.at(player.character).at(Attack1) - 1;
        if (player.currentFrame >= lastAttackFrame) {
            player.isAttacking1 = false;
            player.hasAttack1Started = false;
            player.meleeAttack1_hasHit = false;
     
            if (characterConfigs[player.character].attack1IsThrowable) {
                Throw(player, true);
            }
            
        }
        return;
    }
   

    // Attack 2 logic

    if (input.buttons[attack2Key].is_pressed) {
        player.attackBufferTimer = 0.1f; // Store attack input briefly (100ms)
    }

    if (player.attackBufferTimer > 0) {
        player.attackBufferTimer -= deltaTime; // Reduce buffer timer over time
    }

    if (player.attackBufferTimer > 0 && player.attack2CooldownTimer == 0.0f && !player.hasAttack2Started && player.isOnGround) {
        player.isAttacking2 = true;
        player.hasAttack2Started = true;
        player.attack2CooldownTimer = player.attack2CooldownDuration;
        player.currentFrame = 0;
        player.attackBufferTimer = 0;
    }


    if (player.isAttacking2) {
        AdjustWeaponPosition(player, false);
        int lastAttackFrame = animationFrameCounts.at(player.character).at(Attack2) - 1;
        if (player.currentFrame >= lastAttackFrame) {
            player.isAttacking2 = false;
            player.hasAttack2Started = false;
            player.meleeAttack2_hasHit = false;
            if (characterConfigs[player.character].attack2IsThrowable) {
                
                Throw(player, false); // Use throwable for attack2
            }
        }
        return;
    }

    
    if (!collisionWithArenaTop(arena, player.hitBox) && input.buttons[downKey].is_pressed && player.isOnGround && !player.hasDodgeOrBlockStarted) {
        player.isDodgingOrBlocking = true;
        player.hasDodgeOrBlockStarted = true;  // Prevent re-triggering the dodge/block
        player.isMoving = false;

        // Set the dodge/block velocity based on the direction the character is looking
        if (player.isLookingRight) {
            if (player.character != knight) {
                if (!collisionWithArenaRightWall(arena, player.hitBox)) {
                    velocity.x = playerSpeed + 170;  // Enhanced speed for dodge/block
                }
                else {
                    velocity.x = 0;
                }
            }
            else {
                velocity.x = 0;
            }
        }
        else {
            if (player.character != knight) {
                if (!collisionWithArenaLeftWall(arena, player.hitBox)) {
                    velocity.x = -(playerSpeed + 170);  // Enhanced speed for dodge/block
                }
                else {
                    velocity.x = 0;
                }
            }
            else {
                velocity.x = 0;
            }
        }
    }
    // Complete dodge/block animation and reset state
    if (player.isDodgingOrBlocking) {
        player.position = player.position.AddVector(velocity * deltaTime);

        // Prevent the player from going out of bounds during dodge
        if (player.position.x < arena.width.min) {
            player.position.x = arena.width.min; // Set to left boundary
            velocity.x = 0; // Stop dodge movement
        }
        else if (player.position.x > arena.width.max) {
            player.position.x = arena.width.max; // Set to right boundary
            velocity.x = 0; // Stop dodge movement
        }

        if (player.currentFrame == 0) { // Assuming the animation resets to frame 0 after completion
            player.isDodgingOrBlocking = false;
            player.hasDodgeOrBlockStarted = false; // Allow new dodge/block actions
            velocity.x = 0; // Stop dodge movement after animation ends
        }
        return;
    }



    // Movement and jump logic
    if (input.buttons[upKey].is_down && player.isOnGround) {
        velocity.y = jumpForce;
        player.isOnGround = false;
        player.isMoving = true;
    }

    if (input.buttons[leftKey].is_down) {
        if (!collisionWithArenaLeftWall(arena, player.hitBox)) {
            velocity.x = -playerSpeed;
            player.isMoving = true;
            player.isLookingRight = false;
        }
        else {
            velocity.x = 0;
        }
    }

    if (input.buttons[rightKey].is_down) {
        if (!collisionWithArenaRightWall(arena, player.hitBox)) {
            velocity.x = playerSpeed;
            player.isMoving = true;
            player.isLookingRight = true;
        }
        else {
            velocity.x = 0;
        }
    }

    velocity = velocity + gravity * deltaTime;

    if (!input.buttons[leftKey].is_down && !input.buttons[rightKey].is_down) {
        velocity.x *= friction;
        if (std::abs(velocity.x) < 0.01f) {
            velocity.x = 0.0f;
        }
    }

    player.position = player.position.AddVector(velocity * deltaTime);

    if (collisionWithArenaFloor(arena, player.hitBox)) {
        player.isOnGround = true;
        if (velocity.y > 0) {
            velocity.y = 0;
            velocity.x = 0.2;
            player.position.y = arena.hight.max - 50; //-(player.hitBox.hight.max - player.position.y);
        }
    }
    else {
        player.isOnGround = false;
    }

}



void Update(float deltaTime, HDC hdc) {
    float acceleration = 0;
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime = now - lastFrameTime;
    
    
    if (elapsedTime.count() >= frameDelay) {
        // Update the frame for animations
        UpdatePlayerFrame(player1, animationFrameCounts);
        UpdatePlayerFrame(player2, animationFrameCounts);
    
        lastFrameTime = now; // Reset the last frame time
    }

    
    if (currentTab == 3) {
    
        player1.hitBox.hight.max = player1.position.y + 100;
        player1.hitBox.hight.min = player1.position.y - 50;
        player1.hitBox.width.max = player1.position.x + 50;
        player1.hitBox.width.min = player1.position.x - 10;
    
        player2.hitBox.hight.max = player2.position.y + 100;
        player2.hitBox.hight.min = player2.position.y - 50;
        player2.hitBox.width.max = player2.position.x + 50;
        player2.hitBox.width.min = player2.position.x - 10;
    
        
        UpdatePlayerState(player1, velocityPlayer1, input, arena, deltaTime, jumpForce, playerSpeed, friction, gravity, BUTTON_W, BUTTON_A, BUTTON_S, BUTTON_D, BUTTON_Z, BUTTON_C, BUTTON_X, characterConfigs);
        UpdatePlayerState(player2, velocityPlayer2, input, arena, deltaTime, jumpForce, playerSpeed, friction, gravity, BUTTON_I, BUTTON_J, BUTTON_K, BUTTON_L, BUTTON_B, BUTTON_M, BUTTON_N, characterConfigs);

        UpdateThrowable(player1, deltaTime, arena);
        UpdateThrowable(player2, deltaTime, arena);
        TakeDamage(player1, player2);


    }

}
