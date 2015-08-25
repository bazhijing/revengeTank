#include "Entity.h"

Entity::Entity(){
	m_node = NULL;
	m_isDead = false;
	m_HP = 0;
	m_rotation = 0;
	meta = NULL;
	m_map = NULL;
}

Entity::~Entity(){

}

Node* Entity::getNode(){
	return m_node;
}

void Entity::setController(Controller* controller){
	m_controller = controller;
	m_controller->setControllerListener(this);
}

void Entity::setTagPosition(int x, int y){
	this->setPosition(Vec2(x, y));
}

Vec2 Entity::getTagPosition(){
	return this->getPosition();
}

void Entity::hurt(int hurtValue){
	m_HP -= hurtValue;
	if (m_HP <= 0){
		m_isDead = true;
	}
}

bool Entity::isDead(){
	return m_isDead;
}

float Entity::getTagRotation(){
	return m_rotation;
}

void Entity::setTagRotation(float rota){
	this->setRotation(rota);
	m_rotation = rota;
}

void Entity::bindNode(Node* node){
	if (this->m_node != NULL){
		m_node->removeFromParentAndCleanup(true);
	}

	this->m_node = node;
	this->addChild(m_node);

	Size size = m_node->getContentSize();
	this->setContentSize(size);
}

void Entity::setTiledMap(TMXTiledMap* map){
	m_map = map;

	meta = m_map->getLayer("meta");
	meta->setVisible(false);
}

void Entity::onDead(){

}