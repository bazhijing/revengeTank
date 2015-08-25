#include "Tank.h" 

Tank::Tank(){
	m_head = NULL;
	m_body = NULL;
	m_wheel = NULL;
}

Tank::~Tank(){

}

Tank* Tank::createWithNum(int wheelNum, int bodyNum, int headNum){
	auto tank = new Tank();
	if (tank && tank->initWithNum(wheelNum, bodyNum, headNum)){
		tank->autorelease();
	}
	else{
		CC_SAFE_DELETE(tank);
		tank = NULL;
	}
	return tank;
}

bool Tank::initWithNum(int wheelNum, int bodyNum, int headNum){
	Size visibleSize = this->getContentSize();
	m_head = Sprite::create(StringUtils::format("tank/head%d.png", headNum).c_str());
	m_body = Sprite::create(StringUtils::format("tank/body%d.png", bodyNum).c_str());
	m_wheel = Sprite::create(StringUtils::format("tank/trackwheel%d.png", wheelNum).c_str());

	this->setContentSize(Size(84, 110));
	this->addChild(m_head, 3);
	this->addChild(m_body, 2);
	this->addChild(m_wheel, 1);
	m_head->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	m_body->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	m_wheel->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	return true;
}