#include "StartScene.h" 
#include "cocostudio/CocoStudio.h"
#include "TollgateScene.h"


using namespace cocos2d::ui;
using namespace cocostudio::timeline;

Scene* StartScene::createScene(){
	auto scene = Scene::create();

	auto layer = StartScene::create();

	scene->addChild(layer);

	return scene;
}

bool StartScene::init(){
	if (!Layer::init()){
		return false;
	}

	auto rootNode = CSLoader::createNode("StartScene.csb");
	this->addChild(rootNode, 10);
	auto UI = (Widget*)rootNode;
	auto bMBtn = (Button*)Helper::seekWidgetByName(UI, "BarrierModelButton");
	auto cMBtn = (Button*)Helper::seekWidgetByName(UI, "ChallangeModelButton");
	auto eBtn = (Button*)Helper::seekWidgetByName(UI, "ExitButton");
	auto listener = EventListenerMouse::create();

	bMBtn->addTouchEventListener(this, toucheventselector(StartScene::onClickBMBtn));
	cMBtn->addTouchEventListener(this, toucheventselector(StartScene::onClickCMBtn));
	eBtn->addTouchEventListener(this, toucheventselector(StartScene::onClickEBtn));
	return true;
}

void StartScene::onClickBMBtn(Ref*, TouchEventType type){
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		Director::getInstance()->replaceScene(TollgateScene::createScene());
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	default:
		break;
	}
}

void StartScene::onClickCMBtn(Ref*, TouchEventType type){
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	default:
		break;
	}
}

void StartScene::onClickEBtn(Ref*, TouchEventType type){
	switch (type)
	{
	case TouchEventType::TOUCH_EVENT_BEGAN:
		break;
	case TouchEventType::TOUCH_EVENT_MOVED:
		break;
	case TouchEventType::TOUCH_EVENT_ENDED:
		Director::getInstance()->end();
		break;
	case TouchEventType::TOUCH_EVENT_CANCELED:
		break;
	default:
		break;
	}
}