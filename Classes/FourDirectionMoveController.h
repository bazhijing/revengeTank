#ifndef __FourDirectionMoveController_H__ 
#define __FourDirectionMoveController_H__ 

#include "cocos2d.h" 
#include "Controller.h"
USING_NS_CC; 

enum EightDirection{
	UP = 0,
	UP_RIGHT = 45,
	RIGHT = 90,
	DOWN_RIGHT = 135,
	DOWN = 180,
	DOWN_LEFT = 225,
	LEFT = 270,
	UP_LEFT = 315,
};

class FourDirectionMoveController : public Controller{ 
public:
	CREATE_FUNC(FourDirectionMoveController);
	bool init();
	void update(float dt);
	void setMoveSpeed(int moveSpeed);
	void setRotaSpeed(int rotaSpeed);
	void checkDirection();
	bool isPress();
private:
	bool press[4];
	EightDirection m_direction;
	int m_moveSpeed;
	int m_rotaSpeed;
	void registeKeyBoardEvent();
}; 


#endif // __FourDirectionMoveController_H__ 
