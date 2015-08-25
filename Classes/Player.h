#ifndef __Player_H__ 
#define __Player_H__ 

#include "cocos2d.h" 
#include "Entity.h"
USING_NS_CC; 


class Player : public Entity{ 
public:
	Player();
	~Player();

	static Player* create(Node* node);
	bool init(Node* node);

	virtual void setTagPosition(int x, int y);
	void setViewPointByPlayer();
	static Player* createFromCsvFileByID(int iPlayerID);
	bool initFromCsvFileByID(int iPlayerID);
	Vec2 tileCoorForPosition(Vec2 pos);
	/*
		Some attri of Player
	*/

	void upgrade();

}; 


#endif // __Player_H__ 
