#include "TollgateScene.h"
#include "TiledMapInfo.h"
#include "FourDirectionMoveController.h"

Scene* TollgateScene::createScene(){
	auto scene = Scene::create();
	
	auto layer = TollgateScene::create();

	scene->addChild(layer);
	return scene;
}

bool TollgateScene::init(){
	if (!Layer::init()){
		return false;
	}
	std::string path = "map.tmx";
	auto* map = TiledMapInfo::createMapInfoWithFile(path.c_str());
	this->addChild(map->getTiledMap());

	addPlayer(map->getTiledMap());

	return true;
}

void TollgateScene::addPlayer(TMXTiledMap* map){
	TMXObjectGroup* objGroup = map->getObjectGroup("objects");

	ValueMap playerPointMap = objGroup->getObject("PlayerPoint");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();

	auto player = Player::create(Tank::createWithNum(1, 2 , 3));
	player->setTiledMap(map);
	map->addChild(player);

	auto moveController = FourDirectionMoveController::create();
	this->addChild(moveController);

	player->setController(moveController);
	player->setTagPosition(playerX, playerY);
}