#ifndef __TollgateScene_H__ 
#define __TollgateScene_H__ 

#include "cocos2d.h" 
#include "Tank.h"
#include "Player.h"
USING_NS_CC; 


class TollgateScene : Layer{ 
public:
	static Scene* createScene();
	CREATE_FUNC(TollgateScene);
	bool init();

	void addPlayer(TMXTiledMap* map);

	CC_SYNTHESIZE(int, m_Level, Level);
}; 


#endif // __TollgateScene_H__ 

