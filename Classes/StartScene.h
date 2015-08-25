#ifndef __StartScene_H__ 
#define __StartScene_H__ 

#include "cocos2d.h" 
#include "ui/CocosGUI.h"
USING_NS_CC; 
using namespace cocos2d::ui;

class StartScene : public Layer{ 
public:
	static Scene* createScene();
	CREATE_FUNC(StartScene);
	bool init();

private:
	void onClickBMBtn(Ref*, TouchEventType type);
	void onClickCMBtn(Ref*, TouchEventType type);
	void onClickEBtn(Ref*, TouchEventType type);
}; 


#endif // __StartScene_H__ 
