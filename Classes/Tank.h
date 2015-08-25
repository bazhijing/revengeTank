#ifndef __Tank_H__ 
#define __Tank_H__ 

#include "cocos2d.h" 
USING_NS_CC; 


class Tank : public Node{ 
public:
	Tank();
	~Tank();

	static Tank* createWithNum(int wheelNum, int bodyNum, int headNum);
	bool initWithNum(int wheelNum, int bodyNum, int headNum);
	void changeHead(int headNum);
	void changeBody(int bodyNum);
	void changeWheel(int wheelNum);
	void setHeadRatation(float degree);
	void setBodyRatation(float degree);
	void setWheelRatation(float degree);
private:
	Sprite* m_head;
	Sprite* m_body;
	Sprite* m_wheel;
}; 


#endif // __Tank_H__ 
