#include "FourDirectionMoveController.h" 
#include <math.h>
bool FourDirectionMoveController::init(){
	m_moveSpeed = 4;
	m_rotaSpeed = 9;
	registeKeyBoardEvent();
	for (int i = 0; i <= 3; i++){
		press[i] = false;
	}
	this->scheduleUpdate();
	return true;
}

void FourDirectionMoveController::update(float dt){
	if (m_controllerListener == NULL){
		return;
	}
	if (!isPress()){
		return;
	}

	Vec2 pos = m_controllerListener->getTagPosition();
	int rota = m_controllerListener->getTagRotation();
	CCLOG("rota%d", rota);
	pos += Vec2(m_moveSpeed*sin(CC_DEGREES_TO_RADIANS(rota)), m_moveSpeed*cos(CC_DEGREES_TO_RADIANS(rota)));
	m_controllerListener->setTagPosition(pos.x, pos.y);

	

	if (rota < m_direction){
		if (abs(m_direction - rota) <= abs(rota + 360 - m_direction)){
			m_controllerListener->setTagRotation(rota + m_rotaSpeed);
		}
		else{
			if (rota - m_rotaSpeed < 0){
				m_controllerListener->setTagRotation(360 + rota - m_rotaSpeed);
			}
			else{
				m_controllerListener->setTagRotation(rota - m_rotaSpeed);
			}
		}
		
		
	}
	else if (rota > m_direction){
		if (abs(rota - m_direction) <= abs(360 - rota + m_direction)){
			m_controllerListener->setTagRotation(rota - m_rotaSpeed);
		}
		else{
			if (rota + m_rotaSpeed >= 360){
				m_controllerListener->setTagRotation(rota + m_rotaSpeed - 360);
			}
			else{
				m_controllerListener->setTagRotation(rota + m_rotaSpeed);
			}
		}
		
	}

	if (abs(rota - m_direction) < m_rotaSpeed){
		m_controllerListener->setTagRotation(m_direction);
	}
}

void FourDirectionMoveController::registeKeyBoardEvent(){
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = [&](EventKeyboard::KeyCode code, Event* event){
		switch (code)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			press[0] = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			press[1] = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			press[2] = true;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			press[3] = true;
			break;
		default:
			break;
		}
		checkDirection();
	};

	listener->onKeyReleased = [&](EventKeyboard::KeyCode code, Event* event){
		switch (code)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_W:
			press[0] = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_D:
			press[1] = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_S:
			press[2] = false;
			break;
		case cocos2d::EventKeyboard::KeyCode::KEY_A:
			press[3] = false;
			break;
		default:
			break;
		}
		checkDirection();
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void FourDirectionMoveController::checkDirection(){
	int up = press[0] * 1;
	int right = press[1] * 2;
	int down = press[2] * 4;
	int left = press[3] * 8;
	if (press[0] && press[2]){
		up = 0;
		down = 0;
	}
	if (press[1] && press[3]){
		right = 0;
		left = 0;
	}
	switch (up+right+down+left)
	{
	case 1:
		m_direction = EightDirection::UP;
		break;
	case 2:
		m_direction = EightDirection::RIGHT;
		break;
	case 4:
		m_direction = EightDirection::DOWN;
		break;
	case 8:
		m_direction = EightDirection::LEFT;
		break;
	case 3:
		m_direction = EightDirection::UP_RIGHT;
		break;
	case 9:
		m_direction = EightDirection::UP_LEFT;
		break;
	case 6:
		m_direction = EightDirection::DOWN_RIGHT;
		break;
	case 12:
		m_direction = EightDirection::DOWN_LEFT;
		break;
	default:
		break;
	}
}

bool FourDirectionMoveController::isPress(){
	if (press[0] && press[2] && !press[1] && !press[3]){
		return false;
	}
	if (press[1] && press[3] && !press[0] && !press[2]){
		return false;
	}
	if (!(press[1] || press[2] || press[0] || press[3])){
		return false;
	}
	CCLOG("true");
	return true;
}