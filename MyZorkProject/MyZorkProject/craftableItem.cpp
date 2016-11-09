#include "craftableItem.h"



CraftableItem::CraftableItem(const string name, const string description, const ItemType iType, const list<string> receipe) : Item(name, description, iType), receipe(receipe)
{
}


CraftableItem::~CraftableItem()
{
}
