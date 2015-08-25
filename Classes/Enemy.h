#ifndef __Enemy_H__ 
#define __Enemy_H__ 

#include "cocos2d.h" 
#include "Entity.h"
USING_NS_CC; 


class Enemy : public Entity{ 
public:
	Enemy();
	~Enemy();

	static Enemy* create(Sprite* sprite);
	bool init(Sprite* sprite);

	static Enemy* createFromCsvFileByID(int iPlayerID);
	bool initFromCsvFileByID(int iEnemy);
	
	/*
	Some attri of Player
	*/

	void upgrade();

}; 


#endif // __Enemy_H__ 
