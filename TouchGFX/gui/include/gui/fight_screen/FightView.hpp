#ifndef FIGHTVIEW_HPP
#define FIGHTVIEW_HPP

#include <gui_generated/fight_screen/FightViewBase.hpp>
#include <gui/fight_screen/FightPresenter.hpp>

class FightView : public FightViewBase
{
public:
    FightView();
    virtual ~FightView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
    void Fight();
    void FireBlast();
    void DragonRage();
    void Protect();
    void checkHP();
    void updateHP();
    void updateState();
    void BossToggle();
    void hideActionButton();
    int Random(int min,int max);
    void ShowFire();
    void shieldToggle();
    void shieldToggle2();
    void StunToggle();
    void FearToggle();
    void Thunder();
    void DragonFear();
    void Heal();
    void PlayerToggle();
    void BossAttack();
    void Delay();
    void SwapPointer();
    void CheckEnd();
    void ShowBag();
    void HideBag();
    void useBom();
    void useFullHeal();
    void usePotion();
    void BomEffect();
    void ThunderEffect();
    void DragonRageEffect();
    void DragonFearEffect();
    void HealEffect();
    void PlayerHealEffect();
    void FullHealEffect();
    void Level1();
    void Level2();
    void Level3();
    void CheckBossState();
	void onCursorClicked();
	void hideBagDelay();
	void showBagDelay();
	void useBomDelay();
	void usePotionDelay();
	void useFullHealDelay();
protected:
    int playerHP;
    int BossHP;
    bool PlayerIsProtected;
    bool PlayerState;
    bool BossState;
    int turn;
    int tickcount;
    uint32_t randomseed;
    bool bossFlashing;
    int bossFlashCounter;
    int bossFlashState;
    bool fireFlashing;
    int fireFlashCounter;
    int fireFlashState;
    bool shieldFlashing;
    int shieldFlashCounter;
    int shieldFlashState;
    bool shieldFlashing2;
    int shieldFlashCounter2;
    int shieldFlashState2;
    bool stunFlashing;
    int stunFlashCounter;
    int stunFlashState;
    bool fearFlashing;
    int fearFlashCounter;
    int fearFlashState;
    bool playerFlashing;
    int playerFlashCounter;
    int playerFlashState;
    bool delay;
    int delayCounter;
    int PotionNum;
    int FullHealNum;
    int BomNum;
    bool bomFlashing;
    int bomFlashCounter;
    int bomFlashState;
    bool thunderFlashing;
    int thunderFlashCounter;
    int thunderFlashState;
    bool beamFlashing;
    int beamFlashCounter;
    bool eyeFlashing;
    int eyeFlashCounter;
    bool healFlashing;
    int healFlashCounter;
    int healFlashState;
    bool playerhealFlashing;
    int playerhealFlashCounter;
    int playerhealFlashState;
    bool fullhealFlashing;
    int fullhealFlashCounter;
    int fullhealFlashState;
    int level;
    bool setHP;
    bool hideFlashing;
    int hideFlashCounter;
	bool showFlashing;
	int showFlashCounter;
	bool useBomFlashing;
	int useBomFlashCounter;
	bool usePotionFlashing;
	int usePotionFlashCounter;
	bool useFullHealFlashing;
	int useFullHealFlashCounter;
    Unicode::UnicodeChar value[10];
    int startX;
    int startY;
    float arcAngle;     // Góc hiện tại
    float arcStep;      // Góc thay đổi mỗi tick
    int arcDirection;   // 1: đi, -1: quay về
    int centerX, centerY; // Tâm quỹ đạo
    int radius;           // Bán kính quỹ đạo
};

#endif // FIGHTVIEW_HPP
