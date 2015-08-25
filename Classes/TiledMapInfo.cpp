#include "TiledMapInfo.h" 

enumTileType TiledMapInfo::gidToTileType[] = {
	grass
};

TiledMapInfo* TiledMapInfo::createMapInfoWithFile(const char* tmxFile){
	auto tiledMapInfo = new TiledMapInfo();
	if (tiledMapInfo && tiledMapInfo->initMapInfoWithFile(tmxFile)){
		tiledMapInfo->autorelease();
	}
	else{
		CC_SAFE_DELETE(tiledMapInfo);
	}
	return tiledMapInfo;
}

bool TiledMapInfo::initMapInfoWithFile(const char* tmxFile){
	m_tiledMap = TMXTiledMap::create(tmxFile);

	m_tmxLayer[0] = m_tiledMap->getLayer("meta");



	return true;
}