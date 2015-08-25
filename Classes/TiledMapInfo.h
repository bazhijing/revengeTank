#ifndef __TiledMapInfo_H__ 
#define __TiledMapInfo_H__ 

#include "cocos2d.h" 
USING_NS_CC; 

enum enumTileType{
	grass,
};

class TiledMapInfo : public Node{ 
public:
	static TiledMapInfo* createMapInfoWithFile(const char* tmxFile);
	bool initMapInfoWithFile(const char* tmxFile);

	bool collisionTest(Rect rect);

	CC_SYNTHESIZE(TMXTiledMap*, m_tiledMap, TiledMap);

	static enumTileType gidToTileType[];

private:
	TMXLayer* m_tmxLayer[4];
}; 


#endif // __TiledMapInfo_H__ 
