#include <gui/fight_screen/FightView.hpp>
#include "math.h"
#include "cmsis_os.h"
#include <cstdio>
#include "main.h"         // Khai báo hadc1, hadc2, GPIOA,...
#include <algorithm>      // Cho std::min, std::max

static constexpr int16_t STEP = 5;

FightView::FightView()
{

}

void FightView::setupScreen()
{
    FightViewBase::setupScreen();
    //Khởi tạo HP
    playerHP = 150;
    BossHP = 150;
    //Khởi tạo trạng thái
    PlayerState = false;
    BossState = false;
    PlayerIsProtected = false;
    turn = 0;
    tickcount =0;
    updateState();
    PotionNum = 1;
    FullHealNum = 1;
    level = 1;
    BomNum = 1;
    Unicode::snprintf(value, 10, "%d", 150);
    HP.setWildcard(value);
    HP.invalidate();
}

void FightView::tearDownScreen()
{
    FightViewBase::tearDownScreen();
}
void FightView::hideActionButton()
{
	Skill_3.setVisible(false);
	Skill3Button.setVisible(false);
	Skill_2.setVisible(false);
	Skill2Button.setVisible(false);
	Skill_1.setVisible(false);
	Skill1Button.setVisible(false);
	boxWithBorder2.setVisible(false);

	Skill_3.invalidate();
	Skill3Button.invalidate();
	Skill_2.invalidate();
	Skill2Button.invalidate();
	Skill_1.invalidate();
	Skill1Button.invalidate();
	boxWithBorder2.invalidate();

}
void FightView::Level1(){
	level = 1;
	selectLevel.setVisible(false);
	level1.setVisible(false);
	level2.setVisible(false);
	level3.setVisible(false);

	selectLevel.invalidate();
	level1.invalidate();
	level2.invalidate();
	level3.invalidate();
}
void FightView::Level2(){
	level = 2;
	selectLevel.setVisible(false);
	level1.setVisible(false);
	level2.setVisible(false);
	level3.setVisible(false);

	selectLevel.invalidate();
	level1.invalidate();
	level2.invalidate();
	level3.invalidate();
}
void FightView::Level3(){
	level = 3;
	selectLevel.setVisible(false);
	level1.setVisible(false);
	level2.setVisible(false);
	level3.setVisible(false);

	selectLevel.invalidate();
	level1.invalidate();
	level2.invalidate();
	level3.invalidate();
}
//Hiện bảng skill
void FightView::Fight()
{
	Skill_3.setVisible(true);
	Skill3Button.setVisible(true);
	Skill_2.setVisible(true);
	Skill2Button.setVisible(true);
	Skill_1.setVisible(true);
	Skill1Button.setVisible(true);
	boxWithBorder2.setVisible(true);

	Skill_3.invalidate();
	Skill3Button.invalidate();
	Skill_2.invalidate();
	Skill2Button.invalidate();
	Skill_1.invalidate();
	Skill1Button.invalidate();
	boxWithBorder2.invalidate();
}
void FightView::handleTickEvent()
{
	FightViewBase::handleTickEvent();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 10);
	uint16_t xADC = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 10);
	uint16_t yADC = HAL_ADC_GetValue(&hadc2);
	HAL_ADC_Stop(&hadc2);

	// Tính độ lệch và cập nhật vị trí con trỏ
	int deltaX = xADC - 128;
	int deltaY = 128 - yADC;

	int x = mouse.getX();
	int y = mouse.getY();

	x += deltaX / 12;
	y += deltaY / 12;

	x = std::max(0, std::min(x, 225));
	y = std::max(0, std::min(y, 300));

	mouse.invalidate();
	mouse.setXY(x, y);
	mouse.invalidate();

	    // Nếu người dùng nhấn nút (VD: nút USER trên board)
	    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET) {
	        onCursorClicked(); // Gọi luôn xử lý click
	    }
		if (setHP){
			Unicode::snprintf(value, 10, "%d", playerHP);
			invalidate();
			setHP = false;
		}
	    if (useFullHealFlashing)
	    {
	    	useFullHealFlashCounter++;
	        if (useFullHealFlashCounter >= 12)
	        {

	        	FightButton.setVisible(false);
	        	runButton.setVisible(false);
	        	BagButton.setVisible(false);
	        	FightButton.invalidate();
	        	runButton.invalidate();
	        	BagButton.invalidate();
	        	HideBag();
	        	hideActionButton();
	        	PlayerState = false;
	        	useFullHealText.setVisible(true);
	        	textArea1.setVisible(false);
	        	textArea1.invalidate();
	        	useFullHealText.invalidate();
	        	turn++;
	        	FullHealEffect();
	        	useFullHealFlashing = false;

	        }
	    }
	    if (usePotionFlashing)
	    {
	    	usePotionFlashCounter++;
	        if (usePotionFlashCounter >= 12)
	        {

	        	FightButton.setVisible(false);
	        	runButton.setVisible(false);
	        	BagButton.setVisible(false);
	        	FightButton.invalidate();
	        	runButton.invalidate();
	        	BagButton.invalidate();
	        	HideBag();
	        	hideActionButton();
	        	playerHP = playerHP + 50;
	        	if(playerHP > 150){playerHP = 150;}
	        	usePotionText.setVisible(true);
	        	textArea1.setVisible(false);
	        	textArea1.invalidate();
	        	usePotionText.invalidate();
	        	turn++;
	        	PlayerHealEffect();
	        	usePotionFlashing = false;

	        }
	    }
	    if (useBomFlashing)
	    {
	    	useBomFlashCounter++;
	        if (useBomFlashCounter >= 12)
	        {

	        	FightButton.setVisible(false);
	        	runButton.setVisible(false);
	        	BagButton.setVisible(false);
	        	FightButton.invalidate();
	        	runButton.invalidate();
	        	BagButton.invalidate();
	        	HideBag();
	        	hideActionButton();
	        	BossHP = BossHP - 40;
	        	BossState = true;
	        	useBomText.setVisible(true);
	        	textArea1.setVisible(false);
	        	textArea1.invalidate();
	        	useBomText.invalidate();
	        	turn++;
	        	BomEffect();
	        	useBomFlashing = false;

	        }
	    }
	    if (showFlashing)
	    {
	    	showFlashCounter++;
	        if (showFlashCounter >= 5)
	        {
	        	FightButton.setVisible(false);
	        	runButton.setVisible(false);
	        	BagButton.setVisible(false);
	        	FightButton.invalidate();
	        	runButton.invalidate();
	        	BagButton.invalidate();
	        	hideActionButton();
	        	if(PotionNum > 0){
	        		PotionText.setVisible(true);
	        		PotionButton.setVisible(true);
	        		Potion.setVisible(true);

	        		PotionText.invalidate();
	        		PotionButton.invalidate();
	        		Potion.invalidate();
	        	}
	        	if(FullHealNum > 0){
	        		FullHealText.setVisible(true);
	        		FullHealButton.setVisible(true);
	        		FullHeal.setVisible(true);

	        		FullHealText.invalidate();
	        		FullHealButton.invalidate();
	        		FullHeal.invalidate();
	        	}
	        	if(BomNum > 0){
	        		Bom.setVisible(true);
	        		BomText.setVisible(true);
	        		BomButton.setVisible(true);

	        		BomText.invalidate();
	        		BomButton.invalidate();
	        		Bom.invalidate();
	        	}
	        	Bag.setVisible(true);
	        	Bag.invalidate();
	        	HideBagButton.setVisible(true);
	        	HideBagButton.invalidate();
	        	HideBagText.setVisible(true);
	        	HideBagText.invalidate();
	        	showFlashing = false;
	        }
	    }
	    if (hideFlashing)
	    {
	    	hideFlashCounter++;
	        if (hideFlashCounter >= 5)
	        {
	        	BomText.setVisible(false);
	        	BomButton.setVisible(false);
	        	Bom.setVisible(false);
	        	FullHealText.setVisible(false);
	        	FullHealButton.setVisible(false);
	        	PotionText.setVisible(false);
	        	PotionButton.setVisible(false);
	        	Potion.setVisible(false);
	        	FullHeal.setVisible(false);
	        	Bag.setVisible(false);
	        	HideBagText.setVisible(false);
	        	HideBagButton.setVisible(false);
	        	FightButton.setVisible(true);
	        	runButton.setVisible(true);
	        	BagButton.setVisible(true);
	        	FightButton.invalidate();
	        	runButton.invalidate();
	        	BagButton.invalidate();
	        	BomText.invalidate();
	        	BomButton.invalidate();
	        	Bom.invalidate();
	        	FullHealText.invalidate();
	        	FullHealButton.invalidate();
	        	PotionText.invalidate();
	        	PotionButton.invalidate();
	        	Potion.invalidate();
	        	FullHeal.invalidate();
	        	Bag.invalidate();
	        	HideBagText.invalidate();
	        	HideBagButton.invalidate();
	        	hideFlashing = false;
	        }
	    }
	    if (bossFlashing)
	    {
	        bossFlashCounter++;

	        if (bossFlashCounter % 5 == 0 && bossFlashState < 6)  // Nhấp nháy 3 lần
	        {
	            bool visible = pokemon2.isVisible();
	            pokemon2.setVisible(!visible);
	            pokemon2.invalidate();
	            bossFlashState++;
	        }

	        if (bossFlashState >= 6)
	        {
	            bossFlashing = false;
	            updateHP();
	            updateState();
	            CheckEnd();
	            Delay();
	            SwapPointer();
	        }
	    }
	    if (playerFlashing)
	    	    {
	    	        playerFlashCounter++;

	    	        if (playerFlashCounter % 5 == 0 && playerFlashState < 6)  // Nhấp nháy 3 lần
	    	        {
	    	            bool visible_player = pokemon1.isVisible();
	    	            pokemon1.setVisible(!visible_player);
	    	            pokemon1.invalidate();
	    	            playerFlashState++;
	    	        }

	    	        if (playerFlashState >= 6)
	    	        {
	    	            playerFlashing = false;
	    	            if(BossHP > 0){
	    	            	CheckEnd();
	    	            	updateHP();
	    	            	updateState();
	    	            	SwapPointer();
	    	            }
	    	        	FightButton.setVisible(true);
	    	        	runButton.setVisible(true);
	    	        	BagButton.setVisible(true);
	    	        	FightButton.invalidate();
	    	        	runButton.invalidate();
	    	        	BagButton.invalidate();
	    	        }
	    	    }
	    if (delay)
	    	    {
	    	        delayCounter++;
	    	        if (delayCounter >= 15)
	    	        {
	    	            delay = false;
	    	            BossAttack();
	    	        }
	    	    }
	    if (fireFlashing)
	    {
	        fireFlashCounter++;

	        if (fireFlashCounter % 10 == 0 && fireFlashState < 4)  // Nhấp nháy 2 lần
	        {
	            bool visible1 = fire1.isVisible();
	            bool visible2 = fire2.isVisible();
	            bool visible3 = fire3.isVisible();
	            fire1.setVisible(!visible1);
	            fire2.setVisible(!visible2);
	            fire3.setVisible(!visible3);
	            fire1.invalidate();
	            fire2.invalidate();
	            fire3.invalidate();
	            fireFlashState++;
	        }
	        if (fireFlashCounter >= 60)  // Sau khi nhấp nháy xong
	        {
	            fireFlashing = false;
	        	textArea1.setVisible(true);
	        	Skill1Text.setVisible(false);
	        	Skill1Text.invalidate();
	        	textArea1.invalidate();
	        	BossToggle();
	        }
	    }
	    if (shieldFlashing)
	    	    {

	    	        shieldFlashCounter++;

	    	        if (shieldFlashCounter % 15 == 0 && shieldFlashState < 4)
	    	        {
	    	            bool visible4 = shiled.isVisible();
	    	            shiled.setVisible(!visible4);
	    	            shiled.invalidate();
	    	            shieldFlashState++;
	    	        }

	    	        if (shieldFlashCounter >= 60)
	    	        {
	    	            shieldFlashing = false;
	    	        	textArea1.setVisible(true);
	    	        	Skill3Text.setVisible(false);
	    	        	Skill3Text.invalidate();
	    	        	textArea1.invalidate();
	    	        	Delay();
	    	        	SwapPointer();
	    	        }
	    }
	    if (shieldFlashing2)
	    	    {

	    	        shieldFlashCounter2++;

	    	        if (shieldFlashCounter2 % 15 == 0 && shieldFlashState2 < 4)
	    	        {
	    	            bool visible_shield = shieldBreak.isVisible();
	    	            shieldBreak.setVisible(!visible_shield);
	    	            shieldBreak.invalidate();
	    	            shieldFlashState2++;
	    	        }

	    	        if (shieldFlashCounter2 >= 60)
	    	        {
	    	            shieldFlashing2 = false;
	    	            ProtectText.setVisible(false);
	    	        	textArea1.setVisible(true);
	    	        	textArea1.invalidate();
	    	        	ProtectText.invalidate();
	    	        	SwapPointer();
	    	        	FightButton.setVisible(true);
	    	        	runButton.setVisible(true);
	    	        	BagButton.setVisible(true);
	    	        	FightButton.invalidate();
	    	        	runButton.invalidate();
	    	        	BagButton.invalidate();
	    	        }
	    }
	    if (stunFlashing)
	    	    	    {
	    	    	        stunFlashCounter++;

	    	    	        if (stunFlashCounter % 15 == 0 && stunFlashState < 6)  // Nhấp nháy 3 lần
	    	    	        {
	    	    	            bool visible5 = stun.isVisible();
	    	    	            stun.setVisible(!visible5);
	    	    	            stun.invalidate();
	    	    	            stunFlashState++;
	    	    	        }

	    	    	        if (stunFlashCounter >= 120)
	    	    	        {
	    	    	            stunFlashing = false;
	    	    	        	textArea1.setVisible(true);
	    	    	        	StunText.setVisible(false);
	    	    	        	StunText.invalidate();
	    	    	        	textArea1.invalidate();
	    	    	        	SwapPointer();
	    	    	        	FightButton.setVisible(true);
	    	    	        	runButton.setVisible(true);
	    	    	        	BagButton.setVisible(true);
	    	    	        	FightButton.invalidate();
	    	    	        	runButton.invalidate();
	    	    	        	BagButton.invalidate();
	    	    	        }
	    }
	    if (fearFlashing)
	    	    	    {
	    	    	        fearFlashCounter++;

	    	    	        if (fearFlashCounter % 15 == 0 && fearFlashState < 6)  // Nhấp nháy 3 lần
	    	    	        {
	    	    	            bool visible6 = fear.isVisible();
	    	    	            fear.setVisible(!visible6);
	    	    	            fear.invalidate();
	    	    	            fearFlashState++;
	    	    	        }

	    	    	        if (fearFlashCounter >= 120)
	    	    	        {
	    	    	            fearFlashing = false;
	    	    	        	textArea1.setVisible(true);
	    	    	        	FearText.setVisible(false);
	    	    	        	FearText.invalidate();
	    	    	        	textArea1.invalidate();
	    	    	            Delay();
	    	    	            SwapPointer();
	    	    	        }
	    }
	    if (bomFlashing)
	    	{
	    		bomFlashCounter++;

	    	    if (bomFlashCounter % 1 == 0 && bomFlashState == 0 )
	    	    	{
	    	            // Cập nhật góc
	    	            arcAngle = arcAngle+arcStep;
	    	            if (arcAngle >= 3.1415f*3/2)
	    	            {
	    	                // Sau khi di chuyển xong, set về vị trí ban đầu
	    	                bom.moveTo(startX, startY);
	    	                bom.invalidate();
	    	                bomFlashState++;
	    	            }

	    	            // Tính toạ độ mới
	    	            int newX = centerX + radius * cos(arcAngle);
	    	            int newY = centerY + radius * sin(arcAngle);

	    	            bom.moveTo(newX, newY);
	    	    	    bom.setVisible(true);
	    	            bom.invalidate();

	    	    	}
	    	    if ( bomFlashCounter % 45 == 0 && bomFlashState == 1 )
	    	    	{
    	    	    	phatNo.setVisible(true);
    	    	    	phatNo.invalidate();
    	    	    	bomFlashState++;
	    	        }
	    	    if(bomFlashCounter % 35 ==0 && bomFlashState == 2){
	    	    	bomFlashing = false;
    	    	    bom.setVisible(false);
    	    	    bom.invalidate();
	    	    	phatNo.setVisible(false);
	    	    	phatNo.invalidate();
	    	    	useBomText.setVisible(false);
	    	    	textArea1.setVisible(true);
	    	    	textArea1.invalidate();
	    	    	useBomText.invalidate();
	    	    	BossToggle();
	    	    }
	    }
	    if (thunderFlashing)
	    	    {

	    	        thunderFlashCounter++;
                    cloud.setVisible(true);
                    cloud.invalidate();
	    	        if (thunderFlashCounter % 5 == 0 && thunderFlashState < 6)
	    	        {
	    	            bool visibleThunder = thunder.isVisible();
	    	            thunder.setVisible(!visibleThunder);
	    	            thunder.invalidate();
	    	            thunderFlashState++;
	    	        }

	    	        if (thunderFlashCounter >= 60)
	    	        {
	    	            thunderFlashing = false;
	                    cloud.setVisible(false);
	                    cloud.invalidate();
	    	        	textArea1.setVisible(true);
	    	        	ThunderText.setVisible(false);
	    	        	ThunderText.invalidate();
	    	        	textArea1.invalidate();
	    	        	PlayerToggle();
	    	        }
	    }
	    if (beamFlashing)
	    	    {

	    	        beamFlashCounter++;
                    DragonBeam.setVisible(true);
                    DragonBeam.invalidate();
	    	        if (beamFlashCounter % 15 == 0 )
	    	        {
	    	            vaCham.setVisible(true);
	    	            vaCham.invalidate();
	    	        }

	    	        if (beamFlashCounter >= 60)
	    	        {
	    	            beamFlashing = false;
	    	            DragonBeam.setVisible(false);
	    	            DragonBeam.invalidate();
	    	            vaCham.setVisible(false);
	    	            vaCham.invalidate();
	    	        	textArea1.setVisible(true);
	    	        	Skill2Text.setVisible(false);
	    	        	Skill2Text.invalidate();
	    	        	textArea1.invalidate();
	    	        	BossToggle();
	    	        }
	    }
	    if (eyeFlashing)
	    	    {

	    	        eyeFlashCounter++;
                    DragonEye2.setVisible(true);
                    DragonEye2.invalidate();
	    	        if (eyeFlashCounter == 30 )
	    	        {
	    	        	DragonEye.setVisible(true);
	    	        	DragonEye.invalidate();
	    	        }

	    	        if (eyeFlashCounter >= 60)
	    	        {
	    	            eyeFlashing = false;
	    	            DragonEye.setVisible(false);
	    	            DragonEye.invalidate();
	    	            DragonEye2.setVisible(false);
	    	            DragonEye2.invalidate();
	    	        	textArea1.setVisible(true);
	    	        	DragonFearText.setVisible(false);
	    	        	DragonFearText.invalidate();
	    	        	textArea1.invalidate();
	    	        	PlayerToggle();
	    	        }
	    }
	    if (healFlashing)
	    	    {

	    	        healFlashCounter++;

	    	        if (healFlashCounter % 10 == 0 && healFlashState < 6)
	    	        {
	    	            bool visible_heal = heal.isVisible();
	    	            heal.setVisible(!visible_heal);
	    	            heal.invalidate();
	    	            healFlashState++;
	    	        }

	    	        if (healFlashCounter >= 60)
	    	        {
	    	            healFlashing = false;
	    	            HealText.setVisible(false);
	    	        	textArea1.setVisible(true);
	    	        	textArea1.invalidate();
	    	        	HealText.invalidate();
	    	        	updateHP();
	    	        	SwapPointer();
	    	        	FightButton.setVisible(true);
	    	        	runButton.setVisible(true);
	    	        	BagButton.setVisible(true);
	    	        	FightButton.invalidate();
	    	        	runButton.invalidate();
	    	        	BagButton.invalidate();
	    	        }
	    }
	    if (playerhealFlashing)
	    	    {

	    	        playerhealFlashCounter++;

	    	        if (playerhealFlashCounter % 10 == 0 && playerhealFlashState < 6)
	    	        {
	    	            bool visible_playerheal = playerHeal.isVisible();
	    	            playerHeal.setVisible(!visible_playerheal);
	    	            playerHeal.invalidate();
	    	            playerhealFlashState++;
	    	        }

	    	        if (playerhealFlashCounter >= 60)
	    	        {
	    	            playerhealFlashing = false;
	    	            usePotionText.setVisible(false);
	    	        	textArea1.setVisible(true);
	    	        	textArea1.invalidate();
	    	        	usePotionText.invalidate();
	    	        	updateHP();
	    	        	Delay();
	    	        	SwapPointer();
	    	        }
	    }
	    if (fullhealFlashing)
	    	    {
	    	        fullhealFlashCounter++;

	    	        if (fullhealFlashCounter % 10 == 0 && fullhealFlashState < 6)
	    	        {
	    	            bool visible_fullheal = purification.isVisible();
	    	            purification.setVisible(!visible_fullheal);
	    	            purification.invalidate();
	    	            fullhealFlashState++;
	    	        }

	    	        if (fullhealFlashCounter >= 60)
	    	        {
	    	            fullhealFlashing = false;
	    	            useFullHealText.setVisible(false);
	    	        	textArea1.setVisible(true);
	    	        	textArea1.invalidate();
	    	        	useFullHealText.invalidate();
	    	        	updateState();
	    	        	Delay();
	    	        	SwapPointer();
	    	        }
	    }

}
void FightView::CheckEnd(){
	if(playerHP <= 0){

		Defeat.setVisible(true);
		home.setVisible(true);
		Defeat.invalidate();
		home.invalidate();
		return;
	}else if(BossHP <= 0){
		Victory.setVisible(true);
		home.setVisible(true);
		Victory.invalidate();
		home.invalidate();
		return;
	}
}
void FightView::SwapPointer(){
	PlayerPointer.setVisible(BossPointer.isVisible());
	BossPointer.setVisible(!BossPointer.isVisible());
	PlayerPointer.invalidate();
	BossPointer.invalidate();
}
void FightView::Delay(){
    delay = true;
    delayCounter = 0;
}
void FightView::BossToggle()
{
    bossFlashing = true;
    bossFlashCounter = 0;
    bossFlashState = 0;
}
void FightView::PlayerToggle()
{
    playerFlashing = true;
    playerFlashCounter = 0;
    playerFlashState = 0;
}
void FightView::ShowFire(){
    fireFlashing = true;
    fireFlashCounter = 0;
    fireFlashState = 0;
}
void FightView::DragonRageEffect(){
    beamFlashing = true;
    beamFlashCounter = 0;
}
void FightView::StunToggle(){
    stunFlashing = true;
    stunFlashCounter = 0;
    stunFlashState = 0;
}
void FightView::FearToggle(){
    fearFlashing = true;
    fearFlashCounter = 0;
    fearFlashState = 0;
}
void FightView::FireBlast()
{
	FightButton.setVisible(false);
	runButton.setVisible(false);
	BagButton.setVisible(false);
	FightButton.invalidate();
	runButton.invalidate();
	BagButton.invalidate();
	if(PlayerState == true){
		int x = Random(1,10);
		if(x<=4){
		hideActionButton();
		FearText.setVisible(true);
		textArea1.setVisible(false);
		FearText.invalidate();
	    textArea1.invalidate();
		FearToggle();
		PlayerState = false;
		updateState();
		turn++;
		return;
		}else{
			hideActionButton();
			FearText.setVisible(true);
			textArea1.setVisible(false);
			FearText.invalidate();
		    textArea1.invalidate();
			FearToggle();
			turn++;
			return;
		}
	}else
	hideActionButton();
	textArea1.setVisible(false);
	Skill1Text.setVisible(true);
	Skill1Text.invalidate();
	textArea1.invalidate();
	ShowFire();
	BossHP = BossHP - 30;
	//BossToggle();
	turn++;
}
void FightView::DragonRage()
{
	FightButton.setVisible(false);
	runButton.setVisible(false);
	BagButton.setVisible(false);
	FightButton.invalidate();
	runButton.invalidate();
	BagButton.invalidate();
	if(PlayerState == true){
		hideActionButton();
		FearText.setVisible(true);
		textArea1.setVisible(false);
		FearText.invalidate();
	    textArea1.invalidate();
		FearToggle();
		PlayerState = false;
		updateState();
		turn++;
		return;
	}else
	hideActionButton();
	textArea1.setVisible(false);
	Skill2Text.setVisible(true);
	Skill2Text.invalidate();
	textArea1.invalidate();
	BossHP = BossHP - 20;
	DragonRageEffect();
	int x = Random(1,10);
	if(x<=5){
		BossState = true;
	}
	turn++;
}
void FightView::updateHP()
{
	boxProgress1.setValue(BossHP);
	boxProgress1_2.setValue(playerHP);
	setHP = true;
}
void FightView::updateState()
{
    stun.setVisible(BossState);
    fear.setVisible(PlayerState);
    shiled.setVisible(PlayerIsProtected);
    stun.invalidate();
    fear.invalidate();
    shiled.invalidate();
}
int FightView::Random(int min,int max){
	randomseed = (randomseed * 1103515245 + 12345) & 0x7fffffff;
	return min + (randomseed % (max - min + 1));
}
void FightView::shieldToggle(){
    shieldFlashing = true;
    shieldFlashCounter = 0;
    shieldFlashState = 0;
}
void FightView::shieldToggle2(){
    shieldFlashing2 = true;
    shieldFlashCounter2 = 0;
    shieldFlashState2 = 0;
}
void FightView::BomEffect(){
    bomFlashing = true;
    bomFlashCounter = 0;
    bomFlashState = 0;
    // Lưu vị trí ban đầu
    startX = bom.getX();
    startY = bom.getY();

    // Thiết lập tham số quỹ đạo
    centerX = 140;
    centerY = 190;
    radius  = 120;

    arcAngle = 3.1415f;         // Bắt đầu từ góc 0 rad
    arcStep  = 0.05f;           // Góc thay đổi mỗi tick
}
void FightView::PlayerHealEffect(){
    playerhealFlashing = true;
    playerhealFlashCounter = 0;
    playerhealFlashState = 0;
}
void FightView::FullHealEffect(){
    fullhealFlashing = true;
    fullhealFlashCounter = 0;
    fullhealFlashState = 0;
}
void FightView::ThunderEffect(){
    thunderFlashing = true;
    thunderFlashCounter = 0;
    thunderFlashState = 0;
}
void FightView::DragonFearEffect(){
    eyeFlashing = true;
    eyeFlashCounter = 0;
}
void FightView::HealEffect(){
    healFlashing = true;
    healFlashCounter = 0;
    healFlashState = 0;
}
void FightView::hideBagDelay(){
	hideFlashing = true;
	hideFlashCounter = 0;
}
void FightView::showBagDelay(){
	showFlashing = true;
	showFlashCounter = 0;
}
void FightView::useBomDelay(){
	useBomFlashing = true;
	useBomFlashCounter = 0;
}
void FightView::usePotionDelay(){
	usePotionFlashing = true;
	usePotionFlashCounter = 0;
}
void FightView::useFullHealDelay(){
	useFullHealFlashing = true;
	useFullHealFlashCounter = 0;
}
void FightView::Protect()
{
	FightButton.setVisible(false);
	runButton.setVisible(false);
	BagButton.setVisible(false);
	FightButton.invalidate();
	runButton.invalidate();
	BagButton.invalidate();
	if(PlayerState == true){
		hideActionButton();
		FearText.setVisible(true);
		textArea1.setVisible(false);
		FearText.invalidate();
	    textArea1.invalidate();
		FearToggle();
		PlayerState = false;
		updateState();
		turn++;
		return;
	}else
	hideActionButton();
	textArea1.setVisible(false);
	Skill3Text.setVisible(true);
	Skill3Text.invalidate();
	textArea1.invalidate();
	shieldToggle();
	PlayerIsProtected = true;
	shiled.setVisible(true);
	shiled.invalidate();
	turn++;
}
void FightView::BossAttack(){
 if(level != 3){
	if(BossState == true ){
	 		StunText.setVisible(true);
	 		textArea1.setVisible(false);
	 		StunText.invalidate();
	 	    textArea1.invalidate();
	 		StunToggle();
	 		BossState = false;
	 		updateState();
	 		return ;
	 	}else if(level == 1){
		Thunder();
	 	}else if(level == 2){
		int x = Random(1,10);
		if(x<=3){
			DragonFear();
		}
		else if (BossHP <= 40){
			Heal();
		}else{
		Thunder();
		}
	}
 	}else{
	 if(BossState == true && turn != 1 && !(BossHP >= 40 && BossHP <= 75) && playerHP >= 30){
	 		StunText.setVisible(true);
	 		textArea1.setVisible(false);
	 		StunText.invalidate();
	 	    textArea1.invalidate();
	 		StunToggle();
	 		BossState = false;
	 		updateState();
	 		return;
	 	}else if(turn == 1){
	 			BossState = false;
	 			updateState();
	 			DragonFear();
	 		}
	 		else if(BossHP <= 75 && BossHP >= 40){
	 			int x = Random(1,10);
	 			if(x<=4){
	 				if(BossState == true ){
	 				 		StunText.setVisible(true);
	 				 		textArea1.setVisible(false);
	 				 		StunText.invalidate();
	 				 	    textArea1.invalidate();
	 				 		StunToggle();
	 				 		BossState = false;
	 				 		updateState();
	 				 		return ;
	 				 	}else{
	 				 		Heal();
	 				 	}
	 			}else if(x>4 && x<=6){
	 				if(BossState == true ){
	 				 		StunText.setVisible(true);
	 				 		textArea1.setVisible(false);
	 				 		StunText.invalidate();
	 				 	    textArea1.invalidate();
	 				 		StunToggle();
	 				 		BossState = false;
	 				 		updateState();
	 				 		return ;
	 				 	}else{
	 				 		Thunder();
	 				 	}
	 			}else{
	 			BossState = false;
	 			updateState();
	 			DragonFear();
	 			}
	 		}
	 		else if(playerHP <= 30 ){
	 			BossState = false;
	 			updateState();
	 			Thunder();
	 		}
	 		else if(BossHP < 40 && playerHP >= 30){
	 			Heal();
	 		}else{
	 			int y = Random(1,10);
	 			if(y<=7){
	 			Thunder();
	 			}else{
	 				DragonFear();
	 			}
	 		}

 }

}
void FightView::Thunder()
{
	if(PlayerIsProtected == true){
		ProtectText.setVisible(true);
		textArea1.setVisible(false);
		ProtectText.invalidate();
	    textArea1.invalidate();
	    shieldToggle2();
	    PlayerIsProtected = false;
		updateState();
		return;
	}else
	playerHP = playerHP - 30;
	textArea1.setVisible(false);
	ThunderText.setVisible(true);
	ThunderText.invalidate();
	textArea1.invalidate();
	ThunderEffect();
}
void FightView::DragonFear(){
	if(PlayerIsProtected == true){
		ProtectText.setVisible(true);
		textArea1.setVisible(false);
		ProtectText.invalidate();
	    textArea1.invalidate();
	    shieldToggle2();
	    PlayerIsProtected = false;
		updateState();
		return;
	}else
	playerHP = playerHP - 10;
	PlayerState = true;
	textArea1.setVisible(false);
	DragonFearText.setVisible(true);
	DragonFearText.invalidate();
	textArea1.invalidate();
	DragonFearEffect();
}
void FightView::Heal(){
	BossHP = BossHP + 50;
	if(BossHP > 150){BossHP = 150;}
	textArea1.setVisible(false);
	HealText.setVisible(true);
	HealText.invalidate();
	textArea1.invalidate();
	HealEffect();
}
void FightView::ShowBag(){
	showBagDelay();
}
void FightView::HideBag(){
	hideBagDelay();
}
void FightView::useBom(){
	BomNum = BomNum -1;
	if(BomNum == 0){
	useBomDelay();
	}
}
void FightView::usePotion(){
	PotionNum = PotionNum - 1;
	if(PotionNum == 0){
	usePotionDelay();
	}
}
void FightView::useFullHeal(){
	FullHealNum = FullHealNum - 1;
	if(FullHealNum == 0){
	useFullHealDelay();
	}
}
void FightView::onCursorClicked()
{
    // Lấy tọa độ con trỏ
    int cx = mouse.getX();
    int cy = mouse.getY();

    // Kiểm tra va chạm với button FIGHT
    if (FightButton.isVisible() && FightButton.getAbsoluteRect().intersect(cx, cy))
    {
        // Gọi hàm xử lý fight
        Fight();
        return;
    }

    // Kiểm tra va chạm với button BAG
    if (BagButton.isVisible() && BagButton.getAbsoluteRect().intersect(cx, cy))
    {
    	ShowBag();
        return;
    }

    // Kiểm tra va chạm với button RUN
    if (runButton.isVisible() && runButton.getAbsoluteRect().intersect(cx, cy))
    {
        application().gotoStartGameScreenNoTransition();
        return;
    }
    if (level1.isVisible() && level1.getAbsoluteRect().intersect(cx, cy))
    {
    	Level1();
        return;
    }
    if (level2.isVisible() && level2.getAbsoluteRect().intersect(cx, cy))
    {
    	Level2();
        return;
    }
    if (level3.isVisible() && level3.getAbsoluteRect().intersect(cx, cy))
    {
    	Level3();
        return;
    }
    if (Skill1Button.isVisible() && Skill1Button.getAbsoluteRect().intersect(cx, cy))
    {
    	FireBlast();
        return;
    }
    if (Skill2Button.isVisible() && Skill2Button.getAbsoluteRect().intersect(cx, cy))
    {
    	DragonRage();
        return;
    }
    if (Skill3Button.isVisible() && Skill3Button.getAbsoluteRect().intersect(cx, cy))
    {
    	Protect();
        return;
    }
    if (FullHealButton.isVisible() && FullHealButton.getAbsoluteRect().intersect(cx, cy))
    {
    	useFullHeal();
        return;
    }
    if (BomButton.isVisible() && BomButton.getAbsoluteRect().intersect(cx, cy))
    {
    	useBom();
        return;
    }
    if (HideBagButton.isVisible() && HideBagButton.getAbsoluteRect().intersect(cx, cy))
    {
    	HideBag();
        return;
    }
    if (PotionButton.isVisible() && PotionButton.getAbsoluteRect().intersect(cx, cy))
    {
    	usePotion();
        return;
    }
    if (home.isVisible() && home.getAbsoluteRect().intersect(cx, cy))
    {
        application().gotoStartGameScreenNoTransition();
        return;
    }

    // Nếu không trúng gì
}
