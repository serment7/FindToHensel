#include "FindToHensel\Skill\Skill.h"

void CSkill::setPos(float _x, float _y)
{
	x = _x;
	y = _y;
}

void CSkill::setImg(int _obj, int _img)
{
	objectcode = _obj;
	imagecode = _img;
}

const float& CSkill::getX() const
{
	return x;
}

const float& CSkill::getY() const
{
	return y;
}

const int& CSkill::getImg() const
{
	return imagecode;
}

const int& CSkill::getObj() const
{
	return objectcode;
}
