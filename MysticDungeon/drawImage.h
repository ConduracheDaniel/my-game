#include "initializeImages.h"

void DrawWinImage(Player& player1, Player& player2) {
    Gdiplus::StringFormat menuStringForamt;
    menuStringForamt.SetAlignment(Gdiplus::StringAlignmentCenter);
    menuStringForamt.SetLineAlignment(Gdiplus::StringAlignmentCenter);
    Gdiplus::SolidBrush cyan(Gdiplus::Color(22, 189, 222));
    Gdiplus::RectF winLocation(362, 512, 400, 200);
    Gdiplus::Font font(L"Castellar", 40, Gdiplus::FontStyleBold);

    if(player1.health <= 0) {
        globalGraphics->DrawImage(backgrounds["mov"].get(), 0, 0, 1096, 1096);
        globalGraphics->DrawString((stringPlayerChoice(player2.character) + L" Win!").c_str(), -1, &font, winLocation, &menuStringForamt, &cyan);
 
    }
    else if (player2.health <= 0) {
        globalGraphics->DrawImage(backgrounds["mov"].get(), 0, 0, 1096, 1096);
        globalGraphics->DrawString((stringPlayerChoice(player1.character) + L" Win!").c_str(), -1, &font, winLocation, &menuStringForamt, &cyan);

    }

}

void DrawPlayer(Player& player) {
    // Calculate the center position for the image
    auto calculateCenteredPosition = [](Gdiplus::Image* image, int x, int y) -> Gdiplus::PointF {
        int width = image->GetWidth();
        int height = image->GetHeight();
        // Calculate the top-left corner to center the image
        int drawX = x - width / 2;
        int drawY = y - height / 2;
        return Gdiplus::PointF(drawX, drawY);
        };

    // Handle dodging or blocking animation
    if (player.isDodgingOrBlocking && !player.isMoving) {
        if (player.isLookingRight) {
            if (!player.animations.dodgeOrBlockRight.empty()) {
                auto& image = player.animations.dodgeOrBlockRight[player.currentFrame % player.animations.dodgeOrBlockRight.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
        else {
            if (!player.animations.dodgeOrBlockLeft.empty()) {
                auto& image = player.animations.dodgeOrBlockLeft[player.currentFrame % player.animations.dodgeOrBlockLeft.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
        return;
    }


    // Handle attacking animation 1
    if (player.isAttacking1) {

        if (player.isLookingRight) {
            if (!player.animations.attack1Right.empty()) {
                auto& image = player.animations.attack1Right[player.currentFrame % player.animations.attack1Right.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
        else {
            if (!player.animations.attack1Left.empty()) {
                auto& image = player.animations.attack1Left[player.currentFrame % player.animations.attack1Left.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
     
        return;
    }

    // Handle attacking animation 2
    if (player.isAttacking2) {
        
        if (player.isLookingRight) {
            if (!player.animations.attack2Right.empty()) {
                auto& image = player.animations.attack2Right[player.currentFrame % player.animations.attack2Right.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
        else {
            if (!player.animations.attack2Left.empty()) {
                auto& image = player.animations.attack2Left[player.currentFrame % player.animations.attack2Left.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
       
        return;
    }


    // Handle movement animation
    if (player.isMoving) {
        if (player.isLookingRight) {
            if (!player.animations.walkRight.empty()) {
                auto& image = player.animations.walkRight[player.currentFrame % player.animations.walkRight.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
        else {
            if (!player.animations.walkLeft.empty()) {
                auto& image = player.animations.walkLeft[player.currentFrame % player.animations.walkLeft.size()];
                Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
                globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
            }
        }
        return;
    }

    // Handle idle animation
    if (player.isLookingRight) {
        if (!player.animations.stayRight.empty()) {
            auto& image = player.animations.stayRight[player.currentFrame % player.animations.stayRight.size()];
            Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
            globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
        }
    }
    else {
        if (!player.animations.stayLeft.empty()) {
            auto& image = player.animations.stayLeft[player.currentFrame % player.animations.stayLeft.size()];
            Gdiplus::PointF centeredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
            globalGraphics->DrawImage(image.get(), centeredPos.X, centeredPos.Y);
        }
    }
    // Heandle healing animation
    if (player.isHealing) {
        if (!player.animations.healing.empty()) {
            auto& image = player.animations.healing[player.currentFrame % player.animations.healing.size()];
            Gdiplus::PointF centredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
            globalGraphics->DrawImage(image.get(), centredPos.X, centredPos.Y);
        }
    }
    if (player.isHit) {
        if (!player.animations.takeDamage.empty()) {
            auto& image = player.animations.takeDamage[player.currentFrame % player.animations.takeDamage.size()];
            Gdiplus::PointF centredPos = calculateCenteredPosition(image.get(), player.position.x, player.position.y);
            globalGraphics->DrawImage(image.get(), centredPos.X, centredPos.Y);
        }
       
    }

}

void DrawThrowable(Player& player) {
    Gdiplus::SolidBrush electricViolet(Gdiplus::Color(207, 38, 232));
    if (player.isThrowingSomething && !player.throwable1_hasHit) {

        // temporally red box using to see the collision visually
        //globalGraphics->FillRectangle(&electricViolet,
        //    player.throwable1_position.width.min,
        //    player.throwable1_position.hight.min,
        //    player.throwable1_position.width.max - player.throwable1_position.width.min,
        //    player.throwable1_position.hight.max - player.throwable1_position.hight.min
        //    
        //);
        if (player.throwable1_isMovingRight) {

            auto& image = player.animations.throwing_right[player.currentFrame % player.animations.throwing_right.size()];
            globalGraphics->DrawImage(image.get(), player.throwable1_position.width.min, player.throwable1_position.hight.min);
         
        }
        else {
            auto& image = player.animations.throwing_left[player.currentFrame % player.animations.throwing_left.size()];
            globalGraphics->DrawImage(image.get(), player.throwable1_position.width.min, player.throwable1_position.hight.min);
        }
    }

    if (player.isThrowingSomething2 && !player.throwable2_hasHit) {
        //globalGraphics->FillRectangle(&electricViolet,
        //    player.throwable2_position.width.min,
        //    player.throwable2_position.hight.min,
        //    player.throwable2_position.width.max - player.throwable2_position.width.min,
        //    player.throwable2_position.hight.max - player.throwable2_position.hight.min
        //
        //);
        if (player.throwable2_isMovingRight) {

            auto& image = player.animations.throwing2_right[player.currentFrame % player.animations.throwing2_right.size()];
            globalGraphics->DrawImage(image.get(), player.throwable2_position.width.min , player.throwable2_position.hight.min);
        }
        else {

            auto& image = player.animations.throwing2_left[player.currentFrame % player.animations.throwing2_left.size()];
            globalGraphics->DrawImage(image.get(), player.throwable2_position.width.min, player.throwable2_position.hight.min);
        }
    }
    
}




static void Draw(HDC backBufferDC)
{
    if (!globalGraphics) {
        InitializeGraphics(backBufferDC);
    }

    InitializeImages();


    Gdiplus::SolidBrush red1(Gdiplus::Color(255, 205, 26, 26));
    Gdiplus::SolidBrush darkRed(Gdiplus::Color(255, 107, 15, 15));
    Gdiplus::SolidBrush darkOrange(Gdiplus::Color(255, 243, 156, 18));
    Gdiplus::SolidBrush aquaBlue(Gdiplus::Color(255, 37, 208, 222));
    Gdiplus::SolidBrush grassGreen(Gdiplus::Color(255, 63, 202, 69));
    Gdiplus::SolidBrush cyan(Gdiplus::Color(255, 41, 162, 173));
    Gdiplus::SolidBrush darkCyan(Gdiplus::Color(255, 21, 141, 173));
    Gdiplus::SolidBrush darkPurple(Gdiplus::Color(255, 42, 9, 38));
    Gdiplus::SolidBrush pureWhite(Gdiplus::Color(255, 255, 255, 255));
    Gdiplus::SolidBrush purple2(Gdiplus::Color(255, 77, 20, 70));


    Gdiplus::Font sFCollegeiate15(L"SF Collegeiate", 15, Gdiplus::FontStyleBold);
    Gdiplus::Font sFCollegeiate35(L"SF Collegeiate", 23);
    Gdiplus::Font CopperplateGothic(L"Copperplate Gothic", 14);
  

    Gdiplus::RectF backToMenuLocation(35, 35, 60, 30);
    Gdiplus::RectF purpleBarLocation(95, 35, 90, 30);

    Gdiplus::StringFormat menuStringForamt;
    menuStringForamt.SetAlignment(Gdiplus::StringAlignmentCenter);
    menuStringForamt.SetLineAlignment(Gdiplus::StringAlignmentCenter);
    std::wstring backToMenu = L"☰";

    std::wstring textIsPlayer1Choice = L"Player1: " + player1Choice;
    Gdiplus::RectF player1ChoicetextLocation(219, 900, 300, 35);


    std::wstring textIsPlayer2Choice = L"Player2: " + player2Choice;
    Gdiplus::RectF player2ChoicetextLocation(585, 900, 300, 35);


    switch (currentTab) {
    case 0: {

        globalGraphics->DrawImage(backgrounds["menuImage"].get(), 0, 0, 1096, 1096);


        Gdiplus::RectF playButtonDesign(451, 563, 210, 60);
        Gdiplus::RectF playButtonLocation(456, 568, 200, 50);
        Gdiplus::RectF exitButtonDesign(451, 663, 210, 60);
        Gdiplus::RectF exitButtonLocation(456, 668, 200, 50);
        Gdiplus::RectF rulesButtonDesign(451, 763, 210, 60);
        Gdiplus::RectF rulesButtonLocation(456, 768, 200, 50);

        globalGraphics->FillRectangle(&darkCyan, playButtonDesign);
        globalGraphics->FillRectangle(&cyan, playButtonLocation);
        globalGraphics->FillRectangle(&darkCyan, exitButtonDesign);
        globalGraphics->FillRectangle(&cyan, exitButtonLocation);
        globalGraphics->FillRectangle(&darkCyan, rulesButtonDesign);
        globalGraphics->FillRectangle(&cyan, rulesButtonLocation);

        std::wstring play = L"PLAY";
        std::wstring exitGame = L"EXIT GAME";
        std::wstring rules = L"RULES";

        globalGraphics->DrawString(play.c_str(), -1, &sFCollegeiate15, playButtonLocation, &menuStringForamt, &darkPurple);
        globalGraphics->DrawString(exitGame.c_str(), -1, &sFCollegeiate15, exitButtonLocation, &menuStringForamt, &darkPurple);
        globalGraphics->DrawString(rules.c_str(), -1, &sFCollegeiate15, rulesButtonLocation, &menuStringForamt, &darkPurple);

        ShowWindow(button4, SW_HIDE);
        ShowWindow(button5, SW_HIDE);
        ShowWindow(button6, SW_HIDE);
        ShowWindow(button7, SW_HIDE);
        ShowWindow(button8, SW_HIDE);
        ShowWindow(button9, SW_HIDE);
        ShowWindow(button10, SW_HIDE);
    }
          break;

    case 1: {

        ShowWindow(button4, SW_SHOW);


        globalGraphics->DrawImage(backgrounds["rulesTabImage"].get(), 0, 0, 1096, 1096);


        globalGraphics->FillRectangle(&purple2, backToMenuLocation);
        globalGraphics->DrawString(backToMenu.c_str(), -1, &sFCollegeiate15, backToMenuLocation, &menuStringForamt, &pureWhite);
    }
          break;

    case 2:
    {
        ShowWindow(button4, SW_SHOW);
        ShowWindow(button5, SW_SHOW);
        ShowWindow(button6, SW_SHOW);
        ShowWindow(button7, SW_SHOW);
        ShowWindow(button8, SW_SHOW);
        ShowWindow(button9, SW_SHOW);

        globalGraphics->DrawImage(backgrounds["mov"].get(), 0, 0, 1096, 1096);

        if (isDeleted == true) {
            ShowWindow(button10, SW_SHOW);
            Gdiplus::RectF nextButtonLocation(905, 900, 150, 50);
            std::wstring next_ = L"NEXT ➜";
            globalGraphics->FillRectangle(&purple2, nextButtonLocation);
            globalGraphics->DrawString(next_.c_str(), -1, &sFCollegeiate15, nextButtonLocation, &menuStringForamt, &pureWhite);
        }

        Gdiplus::RectF wizardImageLocation(142, 230, 200, 200);
        Gdiplus::RectF box_wizard(142, 430, 200, 30);
        if (characters["wizardImage"]) {
            globalGraphics->DrawImage(characters["wizardImage"].get(), wizardImageLocation);
        }

        std::wstring wizard = L"WIZARD";

        Gdiplus::RectF knightImageLocation(448, 230, 200, 200);
        Gdiplus::RectF box_knight(448, 430, 200, 30);
        if (characters["knightImage"]) {
            globalGraphics->DrawImage(characters["knightImage"].get(), knightImageLocation);
        }

        std::wstring knight = L"KNIGHT";

        Gdiplus::RectF thiefImageLocation(754, 230, 200, 200);
        Gdiplus::RectF box_thief(754, 430, 200, 30);
        if (characters["thiefImage"]) {
            globalGraphics->DrawImage(characters["thiefImage"].get(), thiefImageLocation);
        }

        std::wstring thief = L"THIEF";

        Gdiplus::RectF vampireImageLocation(277, 500, 200, 200);
        Gdiplus::RectF box_vampire(277, 700, 200, 30);
        if (characters["vampireImage"]) {
            globalGraphics->DrawImage(characters["vampireImage"].get(), vampireImageLocation);
        }

        std::wstring vampire = L"VAMPIRE";

        Gdiplus::RectF archerImageLocation(619, 500, 200, 200);
        Gdiplus::RectF box_archer(619, 700, 200, 30);
        if (characters["archerImage"]) {
            globalGraphics->DrawImage(characters["archerImage"].get(), archerImageLocation);
        }

        std::wstring archer = L"ARCHER";

        globalGraphics->FillRectangle(&purple2, backToMenuLocation);
        Gdiplus::RectF boxes[5] = { box_archer,box_knight,box_thief,box_vampire,box_wizard };
        globalGraphics->FillRectangles(&purple2, boxes, 5);

        globalGraphics->DrawString(wizard.c_str(), -1, &sFCollegeiate15, box_wizard, &menuStringForamt, &pureWhite);
        globalGraphics->DrawString(knight.c_str(), -1, &sFCollegeiate15, box_knight, &menuStringForamt, &pureWhite);
        globalGraphics->DrawString(thief.c_str(), -1, &sFCollegeiate15, box_thief, &menuStringForamt, &pureWhite);
        globalGraphics->DrawString(vampire.c_str(), -1, &sFCollegeiate15, box_vampire, &menuStringForamt, &pureWhite);
        globalGraphics->DrawString(archer.c_str(), -1, &sFCollegeiate15, box_archer, &menuStringForamt, &pureWhite);
        globalGraphics->DrawString(backToMenu.c_str(), -1, &sFCollegeiate15, backToMenuLocation, &menuStringForamt, &pureWhite);

        Gdiplus::RectF characterChoseBox(288, 100, 512, 35);
        std::wstring textChoseCharacter = L"Chose the character for each player:";
        globalGraphics->DrawString(textChoseCharacter.c_str(), -1, &sFCollegeiate35, characterChoseBox, &menuStringForamt, &pureWhite);


        globalGraphics->DrawString(textIsPlayer1Choice.c_str(), -1, &sFCollegeiate15, player1ChoicetextLocation, &menuStringForamt, &pureWhite);
        globalGraphics->DrawString(textIsPlayer2Choice.c_str(), -1, &sFCollegeiate15, player2ChoicetextLocation, &menuStringForamt, &pureWhite);


    }
    break;
    case 3: {
        float arena_half_zixe_x = 1024, arena_half_zixe_y = 1024;

        globalGraphics->DrawImage(backgrounds["mov"].get(), 0, 0, 1096, 1096);
        ShowWindow(button4, SW_SHOW);
        ShowWindow(button10, SW_HIDE);

        Gdiplus::RectF inGameBackgroundLocation(36, 36, arena_half_zixe_x, arena_half_zixe_y);

        switch (zeroToThree) {
        case 0:globalGraphics->DrawImage(backgrounds["castle"].get(), inGameBackgroundLocation);
            break;
        case 1:globalGraphics->DrawImage(backgrounds["japanTemple"].get(), inGameBackgroundLocation);
            break;
        case 2:globalGraphics->DrawImage(backgrounds["vulcan"].get(), inGameBackgroundLocation);
            break;
        case 3:globalGraphics->DrawImage(backgrounds["swamp"].get(), inGameBackgroundLocation);
            break;
        }


        std::wstring day = L"Day";
        std::wstring night = L"Night";
        globalGraphics->FillRectangle(&purple2, backToMenuLocation);
        globalGraphics->FillRectangle(&purple2, purpleBarLocation);

        globalGraphics->DrawString(backToMenu.c_str(), -1, &sFCollegeiate15, backToMenuLocation, &menuStringForamt, &pureWhite);

        if (isNight == false) {
            globalGraphics->DrawString(day.c_str(), -1, &CopperplateGothic, purpleBarLocation, &menuStringForamt, &pureWhite);
        }
        else {
            globalGraphics->DrawString(night.c_str(), -1, &CopperplateGothic, purpleBarLocation, &menuStringForamt, &pureWhite);
        }


        Gdiplus::Point player1HealthBar[4] = { {76, 71}, {536, 71}, {506, 101}, {51, 101} };
        Gdiplus::Point player2HealthBar[4] = { {562, 71}, {1021, 71}, {1047, 101}, {592, 101} };

        Gdiplus::Point underPlayer1HealthBar[4] = { {76, 71}, {536, 71}, {506, 101}, {51, 101} };
        Gdiplus::Point underPlayer2HealthBar[4] = { {562, 71}, {1022, 71}, {1047, 101}, {592, 101} };

        Gdiplus::Point player1AttackBar[4] = { {51, 104}, {201, 104}, {186, 124}, {36, 124} };
        Gdiplus::Point player2AttackBar[4] = { {897, 104}, {1047, 104}, {1062, 124}, {912, 124} };

        Gdiplus::Point player1CharacterNameBar[4] = { {35, 127}, {223, 127}, {193, 157}, {35, 157} };
        Gdiplus::Point player2CahracterNameBar[4] = { {874, 127}, {1062, 127}, {1062, 157}, {901, 157} };

        Gdiplus::Point player1SecondAttackBar[4] = { {351, 104}, {501, 104}, {486, 124}, {336, 124} };
        Gdiplus::Point player2SecondAttackBar[4] = { {597, 104}, {747, 104}, {762, 124}, {612, 124} };

        Gdiplus::Point player1RegenHealthBar[4] = { {201, 104}, {351, 104}, {336, 124}, {186, 124} };
        Gdiplus::Point player2RegenHealthBar[4] = { {747, 104}, {897, 104}, {912, 124}, {762, 124} };

        int fullHealth1 = 120;
        // Calculate full length of the health bar
        int fullLength1 = player1HealthBar[1].X - player1HealthBar[0].X;
        // Calculate current length based on health
        int currentLength1 = (player1.health * fullLength1) / fullHealth1;
        // Adjust the second and third points of the parallelogram
        player1HealthBar[1].X = player1HealthBar[0].X + currentLength1;
        player1HealthBar[2].X = player1HealthBar[3].X + currentLength1;


        int fullHealth2 = 120;
        // Calculate full length of the health bar
        int fullLength2 = player2HealthBar[1].X - player2HealthBar[0].X;
        // Calculate current length based on health
        int currentLength2 = (player2.health * fullLength2) / fullHealth2;
        // Adjust the first and fourth points of the parallelogram
        player2HealthBar[0].X = player2HealthBar[1].X - currentLength2;
        player2HealthBar[3].X = player2HealthBar[2].X - currentLength2;

        // Cooldown calculation for Player 1 and Player 2
        float attack1CooldownProgressPlayer1 = player1.attack1CooldownTimer / player1.attack1CooldownDuration;
        float attack2CooldownProgressPlayer2 = player2.attack1CooldownTimer / player2.attack1CooldownDuration;
        float attack1CooldownProgressPlayer2 = player2.attack1CooldownTimer / player2.attack1CooldownDuration;


        float healingCooldownProgressPlayer1 = player1.healingCooldownTimer / player1.healingCooldownDuration;
        float healingCooldownProgressPlayer2 = player2.healingCooldownTimer / player2.healingCooldownDuration;

        // Player 1 - Second Attack Cooldown Bar (Green)
        float secondAttackCooldownProgressPlayer1 = player1.attack2CooldownTimer / player1.attack2CooldownDuration;
        int secondAttackBarFullLengthPlayer1 = player1SecondAttackBar[1].X - player1SecondAttackBar[0].X;
        int secondAttackBarCurrentLengthPlayer1 = (1 - secondAttackCooldownProgressPlayer1) * secondAttackBarFullLengthPlayer1; // Full bar when cooldown is 0
        player1SecondAttackBar[1].X = player1SecondAttackBar[0].X + secondAttackBarCurrentLengthPlayer1; // Update the right end
        player1SecondAttackBar[2].X = player1SecondAttackBar[3].X + secondAttackBarCurrentLengthPlayer1; // Update the right end for the other point

        // Player 2 - Second Attack Cooldown Bar (Green) - Inverse Progress (Shrinking from right to left)
        float secondAttackCooldownProgressPlayer2 = player2.attack2CooldownTimer / player2.attack2CooldownDuration;
        int secondAttackBarFullLengthPlayer2 = player2SecondAttackBar[1].X - player2SecondAttackBar[0].X;
        int secondAttackBarCurrentLengthPlayer2 = (1 - secondAttackCooldownProgressPlayer2) * secondAttackBarFullLengthPlayer2; // Full bar when cooldown is 0
        player2SecondAttackBar[0].X = player2SecondAttackBar[1].X - secondAttackBarCurrentLengthPlayer2; // Shrink from the right
        player2SecondAttackBar[3].X = player2SecondAttackBar[2].X - secondAttackBarCurrentLengthPlayer2; // Shrink from the right

        // Player 1 - Attack 1 Cooldown Bar (Orange)
        int attack1BarFullLength = player1AttackBar[1].X - player1AttackBar[0].X;
        int attack1BarCurrentLength = (1 - attack1CooldownProgressPlayer1) * attack1BarFullLength;  // Full bar when cooldown is 0
        player1AttackBar[1].X = player1AttackBar[0].X + attack1BarCurrentLength;
        player1AttackBar[2].X = player1AttackBar[3].X + attack1BarCurrentLength;

        // Player 2 - Attack 1 Cooldown Bar (Orange) - Inverse Progress (Shrinking from right to left)
        int attack1BarFullLengthPlayer2 = player2AttackBar[1].X - player2AttackBar[0].X;
        int attack1BarCurrentLengthPlayer2 = (1 - attack1CooldownProgressPlayer2) * attack1BarFullLengthPlayer2;  // Full bar when cooldown is 0
        player2AttackBar[0].X = player2AttackBar[1].X - attack1BarCurrentLengthPlayer2; // Shrink from the right
        player2AttackBar[3].X = player2AttackBar[2].X - attack1BarCurrentLengthPlayer2; // Shrink from the right

        // Player 1 - Healing Cooldown Bar (Blue)
        int healingBarFullLengthPlayer1 = player1RegenHealthBar[1].X - player1RegenHealthBar[0].X;
        int healingBarCurrentLengthPlayer1 = (1 - healingCooldownProgressPlayer1) * healingBarFullLengthPlayer1;  // Full bar when cooldown is 0
        player1RegenHealthBar[1].X = player1RegenHealthBar[0].X + healingBarCurrentLengthPlayer1;
        player1RegenHealthBar[2].X = player1RegenHealthBar[3].X + healingBarCurrentLengthPlayer1;

        // Player 2 - Healing Cooldown Bar (Blue)
        int healingBarFullLengthPlayer2 = player2RegenHealthBar[1].X - player2RegenHealthBar[0].X;
        int healingBarCurrentLengthPlayer2 = (1 - healingCooldownProgressPlayer2) * healingBarFullLengthPlayer2;  // Full bar when cooldown is 0
        player2RegenHealthBar[0].X = player2RegenHealthBar[1].X - healingBarCurrentLengthPlayer2;
        player2RegenHealthBar[3].X = player2RegenHealthBar[2].X - healingBarCurrentLengthPlayer2;



        globalGraphics->FillPolygon(&darkRed, underPlayer1HealthBar, 4);
        globalGraphics->FillPolygon(&darkRed, underPlayer2HealthBar, 4);

        globalGraphics->FillPolygon(&red1, player1HealthBar, 4);
        globalGraphics->FillPolygon(&red1, player2HealthBar, 4);

        globalGraphics->FillPolygon(&darkOrange, player1AttackBar, 4);
        globalGraphics->FillPolygon(&darkOrange, player2AttackBar, 4);

        globalGraphics->FillPolygon(&aquaBlue, player1RegenHealthBar, 4);
        globalGraphics->FillPolygon(&aquaBlue, player2RegenHealthBar, 4);

        globalGraphics->FillPolygon(&grassGreen, player1SecondAttackBar, 4);
        globalGraphics->FillPolygon(&grassGreen, player2SecondAttackBar, 4);

        displayHealth1 = std::to_wstring(player1.health);
        std::wstring inGameInformationPlayer1 = player1Choice + L" Hp:" + displayHealth1;
        Gdiplus::RectF player1ChoicetextLocationInGame(40, 71, 200, 30);
        WCHAR* wcharInGameInformationPlayer1 = new WCHAR[inGameInformationPlayer1.length() + 1];
        std::fill(wcharInGameInformationPlayer1, wcharInGameInformationPlayer1 + inGameInformationPlayer1.length() + 1, 0);
        wcsncpy_s(wcharInGameInformationPlayer1, inGameInformationPlayer1.length() + 1, inGameInformationPlayer1.c_str(), inGameInformationPlayer1.length());

        globalGraphics->DrawString(wcharInGameInformationPlayer1, -1, &sFCollegeiate15, player1ChoicetextLocationInGame, &menuStringForamt, &pureWhite);

        displayHealth2 = std::to_wstring(player2.health);
        std::wstring inGameInformationPlayer2 = player2Choice + L" Hp:" + displayHealth2;
        Gdiplus::RectF player2ChoicetextLocationInGame(560, 71, 200, 30);
        WCHAR* wcharInGameInformationPlayer2 = new WCHAR[inGameInformationPlayer2.length() + 1];
        std::fill(wcharInGameInformationPlayer2, wcharInGameInformationPlayer2 + inGameInformationPlayer2.length() + 1, 0);
        wcsncpy_s(wcharInGameInformationPlayer2, inGameInformationPlayer2.length() + 1, inGameInformationPlayer2.c_str(), inGameInformationPlayer2.length());



        globalGraphics->DrawString(wcharInGameInformationPlayer2, -1, &sFCollegeiate15, player2ChoicetextLocationInGame, &menuStringForamt, &pureWhite);
        delete[] wcharInGameInformationPlayer1;
        delete[] wcharInGameInformationPlayer2;


        DrawPlayer(player1);
        DrawPlayer(player2);
        DrawThrowable(player1);
        DrawThrowable(player2);
      
        DrawWinImage(player1, player2);

        
        
        
        //Gdiplus::Point test[4] = { {player1.hitBox.width.min,player1.hitBox.hight.min},{player1.hitBox.width.max,player1.hitBox.hight.min},{player1.hitBox.width.max, player1.hitBox.hight.max},{player1.hitBox.width.min, player1.hitBox.hight.max} };
        //globalGraphics->FillPolygon(&darkRed, test, 4);
        //Gdiplus::Point test2[4] = { {player2.hitBox.width.min, player2.hitBox.hight.min},{player2.hitBox.width.max, player2.hitBox.hight.min},{player2.hitBox.width.max, player2.hitBox.hight.max},{player2.hitBox.width.min, player2.hitBox.hight.max} };
        //globalGraphics->FillPolygon(&red1, test2, 4);
        
        
    }
          break;
    }

    CleanupImages();
    CleanupGraphics();
}











