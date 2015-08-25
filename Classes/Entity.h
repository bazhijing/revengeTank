#ifndef __Entity_H__ 
#define __Entity_H__ 

#include "cocos2d.h" 
#include "ControllerListener.h"
#include "FourDirectionMoveController.h"
USING_NS_CC; 


class Entity : public Node, public ControllerListener{ 
public:
	Entity();
	~Entity();

	void bindNode(Node* node);
	Node* getNode();
	void setController(Controller* controller);
	void setTiledMap(TMXTiledMap* map);

	virtual void setTagPosition(int x, int y);
	virtual Vec2 getTagPosition();
	virtual float getTagRotation();
	virtual void setTagRotation(float rota);


	void hurt(int hurtValue);
	bool isDead();

	

protected:
	virtual void onDead();

protected:
	TMXTiledMap* m_map;
	TMXLayer* meta;
	Node* m_node;
	int m_rotation;
	bool m_isDead;
	Controller* m_controller;
	
	/*
		Some Attri Here
	*/
	CC_SYNTHESIZE(int, m_HP, HP);

}; 


#endif // __Entity_H__ 
