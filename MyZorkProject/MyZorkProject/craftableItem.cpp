#include "craftableItem.h"



CraftableItem::CraftableItem(const string name, const string description, Entity* parent,const ItemType iType, const list<string> receipe) : Item(name, description, parent, iType), receipe(receipe)
{
}


CraftableItem::~CraftableItem()
{
}
