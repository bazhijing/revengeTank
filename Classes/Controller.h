#ifndef __Controller_H__ 
#define __Controller_H__ 

#include "cocos2d.h" 
#include "ControllerListener.h"
USING_NS_CC; 


class Controller : public Node{ 
public:
	void setControllerListener(ControllerListener* controllerListener);
protected:
	ControllerListener* m_controllerListener;
}; 


#endif // __Controller_H__ 
