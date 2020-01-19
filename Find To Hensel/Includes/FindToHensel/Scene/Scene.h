#pragma once

class CDirectInput;
class ImageManager;

class Scene
{
protected:
	ImageManager* imageManager = nullptr;
	CDirectInput * directInput = nullptr;
public:
	virtual void start() = 0;
	virtual Scene* update(const float&) = 0;
	virtual void stop() = 0;
};
