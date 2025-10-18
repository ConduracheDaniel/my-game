#include "collisionDetection.h"


std::unique_ptr<Gdiplus::Graphics> globalGraphics;

std::unordered_map<std::string, std::unique_ptr<Gdiplus::Image>> backgrounds;
std::unordered_map<std::string, std::unique_ptr<Gdiplus::Image>> characters;


std::unique_ptr<Gdiplus::Image> LoadImage(const std::wstring& path) {
    auto image = std::make_unique<Gdiplus::Image>(path.c_str());
    
    return image;
}

void InitializeGraphics(HDC backBufferDC) {
    globalGraphics = std::make_unique<Gdiplus::Graphics>(backBufferDC);
    if (!globalGraphics || globalGraphics->GetLastStatus() != Gdiplus::Ok) {
        globalGraphics.reset(); 
    }
}

void LoadImagesIntoMap(std::vector<std::unique_ptr<Gdiplus::Image>>& vec, std::initializer_list<std::wstring> paths) {
    for (const auto& path : paths) {
        auto image = LoadImage(path);
        if (image) {
            vec.push_back(std::move(image));  // Only move valid images into the vector
        }
    }
}


void LoadAnimations(Character character, CharacterAnimations& animation) {

    
    switch (character) {
    case wizard: {
        // wizard animations
        LoadImagesIntoMap(animation.stayRight, {
            L"wizard\\wizard walking right1.png",
            L"wizard\\wizard walking right1.png",
            L"wizard\\wizard walking right2.png",
            L"wizard\\wizard walking right2.png"
            });

        LoadImagesIntoMap(animation.stayLeft, {
            L"wizard\\wizard walking left1.png",
            L"wizard\\wizard walking left1.png",
            L"wizard\\wizard walking left2.png",
            L"wizard\\wizard walking left2.png"
            });

        LoadImagesIntoMap(animation.walkRight, {
            L"wizard\\wizard walking right1.png",
            L"wizard\\wizard walking right1.png",
            L"wizard\\wizard walking right2.png",
            L"wizard\\wizard walking right2.png",
            L"wizard\\wizard walking right1.png",
            L"wizard\\wizard walking right1.png",
            L"wizard\\wizard walking right2.png",
            L"wizard\\wizard walking right2.png"
            });

        LoadImagesIntoMap(animation.walkLeft, {
            L"wizard\\wizard walking left1.png",
            L"wizard\\wizard walking left1.png",
            L"wizard\\wizard walking left2.png",
            L"wizard\\wizard walking left2.png",
            L"wizard\\wizard walking left1.png",
            L"wizard\\wizard walking left1.png",
            L"wizard\\wizard walking left2.png",
            L"wizard\\wizard walking left2.png"
            });

        LoadImagesIntoMap(animation.attack1Right, { L"wizard\\wizard sword attack right1.png",
                                                    L"wizard\\wizard sword attack right2.png",
                                                    L"wizard\\wizard sword attack right3.png",
                                                    L"wizard\\wizard sword attack right3.png"

            });

        LoadImagesIntoMap(animation.attack1Left, {  L"wizard\\wizard sword attack left1.png",
                                                    L"wizard\\wizard sword attack left2.png",
                                                    L"wizard\\wizard sword attack left3.png",
                                                    L"wizard\\wizard sword attack left3.png"

            });

        LoadImagesIntoMap(animation.attack2Right, { L"wizard\\wizard throwing fire right1.png",
                                                    L"wizard\\wizard throwing fire right1.png",
                                                    L"wizard\\wizard throwing fire right2.png",
                                                    L"wizard\\wizard throwing fire right2.png",
                                                    L"wizard\\wizard throwing fire right3.png",
                                                    L"wizard\\wizard throwing fire right3.png"

            });

        LoadImagesIntoMap(animation.attack2Left, { L"wizard\\wizard throwing fire left1.png",
                                                   L"wizard\\wizard throwing fire left1.png",
                                                   L"wizard\\wizard throwing fire left2.png",
                                                   L"wizard\\wizard throwing fire left2.png",
                                                   L"wizard\\wizard throwing fire left3.png",
                                                   L"wizard\\wizard throwing fire left3.png"

            });
   
        LoadImagesIntoMap(animation.dodgeOrBlockRight, {  L"wizard\\wizard dodge right1.png",
                                                          L"wizard\\wizard dodge right2.png",
                                                          L"wizard\\wizard dodge right3.png",
                                                          L"wizard\\wizard dodge right4.png",
                                                          L"wizard\\wizard dodge right5.png",
                                                          L"wizard\\wizard dodge right6.png"

            });

        LoadImagesIntoMap(animation.dodgeOrBlockLeft  , { L"wizard\\wizard dodge left1.png",
                                                          L"wizard\\wizard dodge left2.png",
                                                          L"wizard\\wizard dodge left3.png",
                                                          L"wizard\\wizard dodge left4.png",
                                                          L"wizard\\wizard dodge left5.png",
                                                          L"wizard\\wizard dodge left6.png"

            });

        LoadImagesIntoMap(animation.healing, { L"healing\\healing1.png",
                                               L"healing\\healing1.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing4.png",
                                               L"healing\\healing4.png"

            });

        LoadImagesIntoMap(animation.throwing2_right, { L"wizard\\fire right1.png",
                                                      L"wizard\\fire right2.png",
                                                      L"wizard\\fire right3.png"

        });

        LoadImagesIntoMap(animation.throwing2_left, {  L"wizard\\fire left1.png",
                                                      L"wizard\\fire left2.png",
                                                      L"wizard\\fire left3.png"

            });

        LoadImagesIntoMap(animation.takeDamage, {  L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png",
                                                   L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png"
            });

    }
               break;

    case knight: {
        // knight animations
        LoadImagesIntoMap(animation.stayRight, {
            L"knight\\knight-up-down-right1.png",
            L"knight\\knight-up-down-right1.png",
            L"knight\\knight-up-down-right2.png",
            L"knight\\knight-up-down-right2.png"
            });

        LoadImagesIntoMap(animation.stayLeft, {
            L"knight\\knight-up-down-left1.png",
            L"knight\\knight-up-down-left1.png",
            L"knight\\knight-up-down-left2.png",
            L"knight\\knight-up-down-left2.png"
            });

        LoadImagesIntoMap(animation.walkRight, {
            L"knight\\knight walk to right contact1.png",
            L"knight\\knight walk to right down1.png",
            L"knight\\knight walk to right passing1.png",
            L"knight\\knight walk to right up1.png",
            L"knight\\knight walk to right contact2.png",
            L"knight\\knight walk to right down2.png",
            L"knight\\knight walk to right passing2.png",
            L"knight\\knight walk to right up2.png"
            });

        LoadImagesIntoMap(animation.walkLeft, {
            L"knight\\knight walk to left contact1.png",
            L"knight\\knight walk to left down1.png",
            L"knight\\knight walk to left passing1.png",
            L"knight\\knight walk to left up1.png",
            L"knight\\knight walk to left contact2.png",
            L"knight\\knight walk to left down2.png",
            L"knight\\knight walk to left passing2.png",
            L"knight\\knight walk to left up2.png"
            });

        LoadImagesIntoMap(animation.attack1Right, {  L"knight\\knight attack1 right1.png",
                                                     L"knight\\knight attack1 right1.png",
                                                     L"knight\\knight attack1 right2.png",
                                                     L"knight\\knight attack1 right3.png",
                                                     L"knight\\knight attack1 right4.png",
                                                     L"knight\\knight attack1 right4.png"


        });

        LoadImagesIntoMap(animation.attack1Left, { L"knight\\knight attack1 left1.png",
                                                   L"knight\\knight attack1 left1.png",
                                                   L"knight\\knight attack1 left2.png",
                                                   L"knight\\knight attack1 left3.png",
                                                   L"knight\\knight attack1 left4.png",
                                                   L"knight\\knight attack1 left4.png"


        });

        LoadImagesIntoMap(animation.attack2Right, { L"knight\\knight ground attack right1.png",
                                                    L"knight\\knight ground attack right1.png",
                                                    L"knight\\knight ground attack right2.png",
                                                    L"knight\\knight ground attack right2.png",
                                                    L"knight\\knight ground attack right2.png",
                                                    L"knight\\knight ground attack right2.png",
                                                    L"knight\\knight ground attack right2.png"
                                                   


        });

        LoadImagesIntoMap(animation.attack2Left, { L"knight\\knight ground attack left1.png",
                                                   L"knight\\knight ground attack left1.png",
                                                   L"knight\\knight ground attack left2.png",
                                                   L"knight\\knight ground attack left2.png",
                                                   L"knight\\knight ground attack left2.png",
                                                   L"knight\\knight ground attack left2.png",
                                                   L"knight\\knight ground attack left2.png"



            });

        LoadImagesIntoMap(animation.dodgeOrBlockRight, { L"knight\\knight block attack right1.png",
                                                         L"knight\\knight block attack right1.png",
                                                         L"knight\\knight block attack right2.png",
                                                         L"knight\\knight block attack right2.png",
                                                         L"knight\\knight block attack right3.png",
                                                         L"knight\\knight block attack right3.png",
                                                         L"knight\\knight block attack right3.png"



        });

        LoadImagesIntoMap(animation.dodgeOrBlockLeft, {  L"knight\\knight block attack left1.png",
                                                         L"knight\\knight block attack left1.png",
                                                         L"knight\\knight block attack left2.png",
                                                         L"knight\\knight block attack left2.png",
                                                         L"knight\\knight block attack left3.png",
                                                         L"knight\\knight block attack left3.png",
                                                         L"knight\\knight block attack left3.png"


            });

        LoadImagesIntoMap(animation.healing, { L"healing\\healing1.png",
                                               L"healing\\healing1.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing4.png",
                                               L"healing\\healing4.png"

            });

        LoadImagesIntoMap(animation.throwing2_right, { L"knight\\spikes1.png",
                                                      L"knight\\spikes2.png",
                                                      L"knight\\spikes3.png",
                                                      L"knight\\spikes4.png",
                                                      L"knight\\spikes5.png",
                                                      L"knight\\spikes6.png",
                                                      L"knight\\spikes7.png",
                                                      L"knight\\spikes8.png"
            });

        LoadImagesIntoMap(animation.throwing2_left, {  L"knight\\spikes8.png",
                                                      L"knight\\spikes7.png",
                                                      L"knight\\spikes6.png",
                                                      L"knight\\spikes5.png",
                                                      L"knight\\spikes4.png",
                                                      L"knight\\spikes3.png",
                                                      L"knight\\spikes2.png",
                                                      L"knight\\spikes1.png"
            });

        LoadImagesIntoMap(animation.takeDamage, { L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png",
                                                   L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png"
            });


    }
               break;

    case archer: {
        // archer animations
        LoadImagesIntoMap(animation.stayRight, {
            L"archer\\archer-up-down-right1.png",
            L"archer\\archer-up-down-right1.png",
            L"archer\\archer-up-down-right2.png", 
            L"archer\\archer-up-down-right2.png"
            });

        LoadImagesIntoMap(animation.stayLeft, {
            L"archer\\archer-up-down-left1.png",
            L"archer\\archer-up-down-left1.png",
            L"archer\\archer-up-down-left2.png",
            L"archer\\archer-up-down-left2.png"
            });

        LoadImagesIntoMap(animation.walkRight, {
            L"archer\\archer contact1.png",
            L"archer\\archer down.png",
            L"archer\\archer passing.png",
            L"archer\\archer up.png",
            L"archer\\archer contact2.png",
            L"archer\\archer down2.png",
            L"archer\\archer passing2.png",
            L"archer\\archer up2.png"
            });

        LoadImagesIntoMap(animation.walkLeft, {
            L"archer\\archer walk left contact1.png",
            L"archer\\archer walk left down1.png",
            L"archer\\archer walk left passing1.png",
            L"archer\\archer walk left up1.png",
            L"archer\\archer walk left contact2.png",
            L"archer\\archer walk left down2.png",
            L"archer\\archer walk left passing2.png",
            L"archer\\archer walk left up2.png"
            });

        LoadImagesIntoMap(animation.attack1Right, {
         
            L"archer\\archer shooting right1.png",
            L"archer\\archer shooting right1.png",
            L"archer\\archer shooting right2.png",
            L"archer\\archer shooting right2.png",
            L"archer\\archer shooting right3.png",
            L"archer\\archer shooting right3.png",
            L"archer\\archer shooting right4.png",
            L"archer\\archer shooting right4.png"
            });

        LoadImagesIntoMap(animation.attack1Left, {
      
            L"archer\\archer shooting left1.png",
            L"archer\\archer shooting left1.png",
            L"archer\\archer shooting left2.png",
            L"archer\\archer shooting left2.png",
            L"archer\\archer shooting left3.png",
            L"archer\\archer shooting left3.png",
            L"archer\\archer shooting left4.png",
            L"archer\\archer shooting left4.png"
            });

        LoadImagesIntoMap(animation.attack2Right, {
            L"archer\\archer shooting rocket right1.png",
            L"archer\\archer shooting rocket right1.png",
            L"archer\\archer shooting rocket right2.png",
            L"archer\\archer shooting rocket right2.png",
            L"archer\\archer shooting rocket right3.png",
            L"archer\\archer shooting rocket right3.png",
            L"archer\\archer shooting rocket right4.png",
            L"archer\\archer shooting rocket right4.png"
            });

        LoadImagesIntoMap(animation.attack2Left, {
            L"archer\\archer shooting rocket left1.png",
            L"archer\\archer shooting rocket left1.png",
            L"archer\\archer shooting rocket left2.png",
            L"archer\\archer shooting rocket left2.png",
            L"archer\\archer shooting rocket left3.png",
            L"archer\\archer shooting rocket left3.png",
            L"archer\\archer shooting rocket left4.png",
            L"archer\\archer shooting rocket left4.png"
            });

        LoadImagesIntoMap(animation.dodgeOrBlockRight, {  
                                                          L"archer\\archer rolling right2.png",
                                                          L"archer\\archer rolling right3.png",
                                                          L"archer\\archer rolling right4.png",
                                                          L"archer\\archer rolling right5.png",
                                                          L"archer\\archer rolling right6.png",
                                                          L"archer\\archer rolling right7.png"

            });

        LoadImagesIntoMap(animation.dodgeOrBlockLeft , { 
                                                         L"archer\\archer rolling left2.png",
                                                         L"archer\\archer rolling left3.png",
                                                         L"archer\\archer rolling left4.png",
                                                         L"archer\\archer rolling left5.png",
                                                         L"archer\\archer rolling left6.png",
                                                         L"archer\\archer rolling left7.png"

            });

        LoadImagesIntoMap(animation.healing, { L"healing\\healing1.png",
                                               L"healing\\healing1.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing4.png",
                                               L"healing\\healing4.png"

            });

        LoadImagesIntoMap(animation.throwing_right, {
                      L"archer\\arrow right.png"
            });

        LoadImagesIntoMap(animation.throwing_left, {
                     L"archer\\arrow left.png"
            });

        LoadImagesIntoMap(animation.throwing2_right, {
                     L"archer\\rocket right.png"
            });

        LoadImagesIntoMap(animation.throwing2_left, {
                     L"archer\\rocket left.png"
            });

        LoadImagesIntoMap(animation.takeDamage, { L"take damage\\take damage1.png",
                                                  L"take damage\\take damage2.png",
                                                  L"take damage\\take damage3.png",
                                                  L"take damage\\take damage1.png",
                                                  L"take damage\\take damage2.png",
                                                  L"take damage\\take damage3.png"
            });

   
    }
               break;

    case thief: {
        // thief animations
        LoadImagesIntoMap(animation.stayRight, {
            L"thief\\thief-up-down-right1.png",
            L"thief\\thief-up-down-right1.png",
            L"thief\\thief-up-down-right2.png",
            L"thief\\thief-up-down-right2.png",
            L"thief\\thief-up-down-right3.png",
            L"thief\\thief-up-down-right3.png"
            });

        LoadImagesIntoMap(animation.stayLeft, {
            L"thief\\thief-up-down-left1.png",
            L"thief\\thief-up-down-left1.png",
            L"thief\\thief-up-down-left2.png",
            L"thief\\thief-up-down-left2.png",
            L"thief\\thief-up-down-left3.png",
            L"thief\\thief-up-down-left3.png"
            });

        LoadImagesIntoMap(animation.walkRight, {
            L"thief\\thief walk to right contact1.png",
            L"thief\\thief walk to right down1.png",
            L"thief\\thief walk to right passing1.png",
            L"thief\\thief walk to right up1.png",
            L"thief\\thief walk to right contact2.png",
            L"thief\\thief walk to right down2.png",
            L"thief\\thief walk to right passing2.png",
            L"thief\\thief walk to right up2.png"
            });

        LoadImagesIntoMap(animation.walkLeft, {
            L"thief\\thief walk to left contact1.png",
            L"thief\\thief walk to left down1.png",
            L"thief\\thief walk to left passing1.png",
            L"thief\\thief walk to left up1.png",
            L"thief\\thief walk to left contact2.png",
            L"thief\\thief walk to left down2.png",
            L"thief\\thief walk to left passing2.png",
            L"thief\\thief walk to left up2.png"
            });

        LoadImagesIntoMap(animation.attack1Right, { L"thief\\thief sword attack right1.png",
                                                    L"thief\\thief sword attack right2.png",
                                                    L"thief\\thief sword attack right3.png",
                                                    L"thief\\thief sword attack right3.png"

        });

        LoadImagesIntoMap(animation.attack1Left, {  L"thief\\thief sword attack left1.png",
                                                    L"thief\\thief sword attack left2.png",
                                                    L"thief\\thief sword attack left3.png",
                                                    L"thief\\thief sword attack left3.png"

            });

        LoadImagesIntoMap(animation.attack2Right, { L"thief\\throwing suriken right1.png",
                                                    L"thief\\throwing suriken right1.png",
                                                    L"thief\\throwing suriken right2.png",
                                                    L"thief\\throwing suriken right2.png", 
                                                    L"thief\\throwing suriken right3.png",
                                                    L"thief\\throwing suriken right3.png",
                                                    L"thief\\throwing suriken right3.png"
            });  

        LoadImagesIntoMap(animation.attack2Left, {  L"thief\\throwing suriken left1.png",
                                                    L"thief\\throwing suriken left1.png",
                                                    L"thief\\throwing suriken left2.png",
                                                    L"thief\\throwing suriken left2.png",
                                                    L"thief\\throwing suriken left3.png",
                                                    L"thief\\throwing suriken left3.png",
                                                    L"thief\\throwing suriken left3.png"

            });

        LoadImagesIntoMap(animation.dodgeOrBlockRight, {  L"thief\\thief rolling right1.png",
                                                          L"thief\\thief rolling right2.png",
                                                          L"thief\\thief rolling right3.png",
                                                          L"thief\\thief rolling right4.png",
                                                          L"thief\\thief rolling right5.png",
                                                          L"thief\\thief rolling right6.png",
                                                          L"thief\\thief rolling right7.png"

            });

        LoadImagesIntoMap(animation.dodgeOrBlockLeft , { L"thief\\thief rolling left1.png",
                                                         L"thief\\thief rolling left2.png",
                                                         L"thief\\thief rolling left3.png",
                                                         L"thief\\thief rolling left4.png",
                                                         L"thief\\thief rolling left5.png",
                                                         L"thief\\thief rolling left6.png",
                                                         L"thief\\thief rolling left7.png"

            });

        LoadImagesIntoMap(animation.healing, { L"healing\\healing1.png",
                                               L"healing\\healing1.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing4.png",
                                               L"healing\\healing4.png"

            });

        LoadImagesIntoMap(animation.throwing2_right, { L"thief\\shuriken right1.png",
                                                      L"thief\\shuriken right2.png",
                                                      L"thief\\shuriken right3.png"

            });

        LoadImagesIntoMap(animation.throwing2_left, {  L"thief\\shuriken left1.png",
                                                      L"thief\\shuriken left2.png",
                                                      L"thief\\shuriken left3.png"

            });

        LoadImagesIntoMap(animation.takeDamage, { L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png",
                                                   L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png"
            });

    }
              break;

    case vampire: {
        // vampire animations
        LoadImagesIntoMap(animation.stayRight, {
            L"vampire\\vampire-up-down-right1.png",
            L"vampire\\vampire-up-down-right1.png",
            L"vampire\\vampire-up-down-right2.png",
            L"vampire\\vampire-up-down-right2.png",
            L"vampire\\vampire-up-down-right3.png",
            L"vampire\\vampire-up-down-right3.png"
            });

        LoadImagesIntoMap(animation.stayLeft, {
            L"vampire\\vampire-up-down-left1.png",
            L"vampire\\vampire-up-down-left1.png",
            L"vampire\\vampire-up-down-left2.png",
            L"vampire\\vampire-up-down-left2.png",
            L"vampire\\vampire-up-down-left3.png",
            L"vampire\\vampire-up-down-left3.png"
            });

        LoadImagesIntoMap(animation.walkRight, {
            L"vampire\\vampire walk to right contact1.png",
            L"vampire\\vampire walk to right down1.png",
            L"vampire\\vampire walk to right passing1.png",
            L"vampire\\vampire walk to right up1.png",
            L"vampire\\vampire walk to right contact2.png",
            L"vampire\\vampire walk to right down2.png",
            L"vampire\\vampire walk to right passing2.png",
            L"vampire\\vampire walk to right up2.png"
            });

        LoadImagesIntoMap(animation.walkLeft, {
            L"vampire\\vampire walk to left contact1.png",
            L"vampire\\vampire walk to left down1.png",
            L"vampire\\vampire walk to left passing1.png",
            L"vampire\\vampire walk to left up1.png",
            L"vampire\\vampire walk to left contact2.png",
            L"vampire\\vampire walk to left down2.png",
            L"vampire\\vampire walk to left passing2.png",
            L"vampire\\vampire walk to left up2.png"
            });

        LoadImagesIntoMap(animation.attack1Right, { L"vampire\\vampire magic attack right1.png",
                                                    L"vampire\\vampire magic attack right2.png",
                                                    L"vampire\\vampire magic attack right3.png",
                                                    L"vampire\\vampire magic attack right4.png",
                                                    L"vampire\\vampire magic attack right4.png"

            });

        LoadImagesIntoMap(animation.attack1Left, { L"vampire\\vampire magic attack left1.png",
                                                   L"vampire\\vampire magic attack left2.png",
                                                   L"vampire\\vampire magic attack left3.png",
                                                   L"vampire\\vampire magic attack left4.png",
                                                   L"vampire\\vampire magic attack left4.png"
            });

        LoadImagesIntoMap(animation.attack2Right, { L"vampire\\vampire bite right1.png",
                                                    L"vampire\\vampire bite right2.png",
                                                    L"vampire\\vampire bite right3.png",
                                                    L"vampire\\vampire bite right3.png"

            });

        LoadImagesIntoMap(animation.attack2Left, {  L"vampire\\vampire bite left1.png",
                                                    L"vampire\\vampire bite left2.png",
                                                    L"vampire\\vampire bite left3.png",
                                                    L"vampire\\vampire bite left3.png"

            });
        
        LoadImagesIntoMap(animation.dodgeOrBlockRight, {  L"vampire\\vampire rolling right1.png",
                                                          L"vampire\\vampire rolling right2.png",
                                                          L"vampire\\vampire rolling right3.png",
                                                          L"vampire\\vampire rolling right4.png",
                                                          L"vampire\\vampire rolling right5.png",
                                                          L"vampire\\vampire rolling right6.png",
                                                          L"vampire\\vampire rolling right7.png"

            });

        LoadImagesIntoMap(animation.dodgeOrBlockLeft, {  L"vampire\\vampire rolling left1.png",
                                                         L"vampire\\vampire rolling left2.png",
                                                         L"vampire\\vampire rolling left3.png",
                                                         L"vampire\\vampire rolling left4.png",
                                                         L"vampire\\vampire rolling left5.png",
                                                         L"vampire\\vampire rolling left6.png",
                                                         L"vampire\\vampire rolling left7.png"

            });

        LoadImagesIntoMap(animation.healing, { L"healing\\healing1.png",
                                               L"healing\\healing1.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing2.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing3.png",
                                               L"healing\\healing4.png",
                                               L"healing\\healing4.png"

            });

        LoadImagesIntoMap(animation.throwing_right, { L"vampire\\blue magic right1.png",
                                                      L"vampire\\blue magic right2.png"
            });

        LoadImagesIntoMap(animation.throwing_left, {  L"vampire\\blue magic left1.png",
                                                      L"vampire\\blue magic left2.png"
            });

        LoadImagesIntoMap(animation.takeDamage, { L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png",
                                                   L"take damage\\take damage1.png",
                                                   L"take damage\\take damage2.png",
                                                   L"take damage\\take damage3.png"
            });

    }
                break;
    }

}

void InitializeImages() {

    backgrounds.clear();
    characters.clear();

    // Load background images
    backgrounds["menuImage"] = std::move(LoadImage(L"tab images\\menu background.jpg"));
    backgrounds["rulesTabImage"] = std::move(LoadImage(L"tab images\\rules tab.jpg"));
    backgrounds["mov"] = std::move(LoadImage(L"tab images\\mov.png"));
    backgrounds["swamp"] = std::move(LoadImage(L"background images\\swamp.jpg"));
    backgrounds["japanTemple"] = std::move(LoadImage(L"background images\\japan temple bridge.jpg"));
    backgrounds["castle"] = std::move(LoadImage(L"background images\\castle.jpg"));
    backgrounds["vulcan"] = std::move(LoadImage(L"background images\\vulcan.jpg"));

    // Load character images
    characters["wizardImage"] = std::move(LoadImage(L"CharacterGame Images\\Wizard 2.jpg"));
    characters["knightImage"] = std::move(LoadImage(L"CharacterGame Images\\knight.jpg"));
    characters["thiefImage"] = std::move(LoadImage(L"CharacterGame Images\\thief.jpg"));
    characters["vampireImage"] = std::move(LoadImage(L"CharacterGame Images\\Vampire.jpg"));
    characters["archerImage"] = std::move(LoadImage(L"CharacterGame Images\\Archer background.jpg"));

    LoadAnimations(player1.character, player1.animations);
    LoadAnimations(player2.character, player2.animations);
}


void CleanupImages() {
    backgrounds.clear();
    characters.clear();

    player1.animations = {};
    player2.animations = {};

}

void CleanupGraphics() {
    globalGraphics.reset();
}