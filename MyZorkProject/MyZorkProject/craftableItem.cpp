#include "craftableItem.h"



CraftableItem::CraftableItem(const string name, const string description, const ItemType iType, const list<string> neededItems) : Item(name, description, iType), neededItems(neededItems)
{
}


CraftableItem::~CraftableItem()
{
}
