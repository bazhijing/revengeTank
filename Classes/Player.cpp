#include "Player.h"

Player::Player(){

}

Player::~Player(){

}

Player* Player::create(Node* node){
	auto player = new Player();
	if (player && player->init(node)){
		player->autorelease();
		return player;
	}
	else{
		CC_SAFE_DELETE(player);
	}
	return player;
}

void Player::setTagPosition(int x, int y){
	auto spriteSize = m_node->getContentSize();
	Vec2 dstPos = Vec2(x + spriteSize.width / 2, y);

	Vec2 tiledPos = tileCoorForPosition(Vec2(dstPos.x, dstPos.y));

	int tiledGid = meta->getTileGIDAt(tiledPos);

	if (tiledGid != 0){
		Value properties = m_map->getPropertiesForGID(tiledGid);
		ValueMap propertiesMap = properties.asValueMap();

		if (propertiesMap.find("Collidable") != propertiesMap.end()){
			Value prop = propertiesMap.at("Collidable");
			if (prop.asString().compare("true") == 0){
				return;
			}
		}

		if (propertiesMap.find("food") != propertiesMap.end()){
			Value prop = propertiesMap.at("food");
			if (prop.asString().compare("true") == 0){
				TMXLayer* barrier = m_map->getLayer("barrier");
				barrier->removeTileAt(tiledPos);
			}
		}
	}
	
	Entity::setTagPosition(x, y);
	setViewPointByPlayer();
}

bool Player::init(Node* node){
	bool bRet = false;
	do{
		CC_BREAK_IF(!node);
		this->bindNode(node);
		bRet = true;
	} while (0);
	return true;
}

void Player::setViewPointByPlayer(){
	if (NULL == m_node){
		return;
	}

	Layer* parent = (Layer*)getParent();
	Size tileSize = m_map->getTileSize();
	Size mapTileNum = m_map->getMapSize();
	Size mapSize = Size(tileSize.width*mapTileNum.width, tileSize.height*mapTileNum.height);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	Vec2 spritePos = this->getPosition();

	float x = std::max(spritePos.x, visibleSize.width / 2);
	float y = std::max(spritePos.y, visibleSize.height / 2);

	x = std::min(x, mapSize.width - visibleSize.width / 2);
	y = std::min(y, mapSize.height - visibleSize.height / 2);

	Vec2 destPos = Vec2(x, y);
	Vec2 centerPos = Vec2(visibleSize.width / 2, visibleSize.height / 2);

	Vec2 viewPos = centerPos - destPos;
	parent->setPosition(viewPos);
}

Vec2 Player::tileCoorForPosition(Vec2 pos){
	auto mapTiledNum = m_map->getMapSize();
	auto tiledSize = m_map->getTileSize();

	int x = pos.x / tiledSize.width;
	int y = (mapTiledNum.height*tiledSize.height - pos.y) / tiledSize.height;
	return Vec2(x, y);

}