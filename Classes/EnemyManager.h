#ifndef __EnemyManager_H__ 
#define __EnemyManager_H__ 

#include "cocos2d.h" 
USING_NS_CC; 


class EnemyManager : public Node{ 
public:
	EnemyManager();
	~EnemyManager();

	static EnemyManager* createWithLevel(int level);
	bool initWithLevel(int level);

private:
	

}; 


#endif // __EnemyManager_H__ 
