#include "Object.h"
#include <algorithm>

Object::Object()
{
	AllObjects.push_back(this);
}

Object::Object(Vec2 Location, Object* owner)
{
	setLocation(Location);
	AllObjects.push_back(this);
	if (owner != NULL) Attach(owner, this);
}

Object::~Object()
{
	for(size_t i = 0 ; i < AllObjects.size();i++)
		if (this == AllObjects[i])
		{
			AllObjects.erase(AllObjects.begin() + i);
			break;
		}
}

const Vec2 Object::getWorldLocation()
{
	if (Owner == NULL) return Location;
	else return Vec2(Location.x + getOwner()->getWorldLocation().x, Location.y + getOwner()->getWorldLocation().y);
}

const Vec2 Object::getRelativeLocation()
{
	return Location;
}

Vec2 Object::setLocation(Vec2 vector)
{
	Location = vector;
	return Location;
}

Vec2 Object::addLocation(Vec2 vector)
{
	Location.Add(vector);
	return Location;
}

Vec2 Object::addLocation(int x, int y)
{
	Location.Add(x, y);
	return Location;
}

void Object::setOwner(Object* owner)
{
	Owner = owner;
}

Object* Object::getOwner() const
{
	return Owner;
}

void Object::AttachChild(Object* child)
{
	if (child->getOwner() != NULL)
	{
		if (child->getOwner() == this) return;
		Deattach(child->getOwner(), child);
	}
	ChildrenList.push_back(child);
	child->setOwner(this);
}

void Object::DeattachChild(Object* child)
{
	if (child->getOwner() == NULL || child->getOwner() != this) return;

	for (size_t i = 0; i < ChildrenList.size(); i++)
		if (child == ChildrenList[i])
		{
			ChildrenList.erase(ChildrenList.begin() + i);
			break;
		}
	child->setOwner(NULL);
}

void  Object::Attach(Object* owner, Object* child)
{
	if (child->getOwner() != NULL)
	{
		if (child->getOwner() == owner) return;
		Deattach(child->getOwner(), child);
	}
	owner->ChildrenList.push_back(child);
	child->setOwner(owner);
}

void Object::Deattach(Object* owner, Object* child)
{
	if (child->getOwner() == NULL || child->getOwner() != owner) return;

	for (size_t i = 0; i < owner->ChildrenList.size(); i++)
		if (child == owner->ChildrenList[i])
		{
			owner->ChildrenList.erase(owner->ChildrenList.begin() + i);
			break;
		}
	child->setOwner(NULL);
}

void Object::Destroy()
{
	if (std::find(DestroyedObjects.begin(), DestroyedObjects.end(), this) == DestroyedObjects.end())
		DestroyedObjects.push_back(this);
}

std::vector<Object*> Object::getAllChilds()
{
	return ChildrenList;
}

std::vector<Object*> Object::getAllObjects()
{
	return AllObjects;
}

std::vector<Object*>& Object::getDestroyedObjects()
{
	return DestroyedObjects;
}

std::vector<Object*> Object::AllObjects;
std::vector<Object*> Object::DestroyedObjects;