#ifndef __ControllerListener_H__ 
#define __ControllerListener_H__ 

#include "cocos2d.h" 
USING_NS_CC; 


class ControllerListener{ 
public:
	virtual void setTagPosition(int x, int y) = 0;
	virtual Vec2 getTagPosition() = 0;
	virtual float getTagRotation() = 0;
	virtual void setTagRotation(float rota) = 0;
}; 


#endif // __ControllerListener_H__ 
