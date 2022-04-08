#include "FlipBook.h"

FlipBook::FlipBook()
{
}

FlipBook::~FlipBook()
{
	for (auto frame : frames)
	{
		delete frame;
	}
}

void FlipBook::OnDrawn()
{
	NextFrame();
}

const Vec2 FlipBook::getSize()
{
	return size;
}

const int FlipBook::getZOrder()
{
	return Z;
}

Texture* FlipBook::getTexture()
{
	return frames.at(currentFrame);
}

const int FlipBook::getCurrentFrame() const
{
	return currentFrame;
}

const Vec2 FlipBook::getDrawLoacation()
{
	return GetWorldLocation();
}

const bool FlipBook::isVisible()
{
	return visible;
}

void FlipBook::setZOrder(int newValue)
{
	Z = newValue;
}

void FlipBook::setSize(Vec2 sz)
{
	size = sz;
	for (int i = 0; i < frames.size(); i++)
	{
		if (frames[i] == NULL) frames[i] = new Texture(sz, {L' ', 7});
		else frames[i]->setSize(sz);
	}
}

void FlipBook::setSize(int x, int y)
{
	size = Vec2(x, y);
	for (int i = 0; i < frames.size(); i++)
	{
		if (frames[i] == NULL) frames[i] = new Texture(Vec2(x, y), { L' ', 7 });
		else frames[i]->setSize(Vec2(x, y));
	}
}

void FlipBook::setVisibility(bool visibility)
{
	visible = visibility;
}

void FlipBook::setCurrentFrame(int newFrame)
{
	if (newFrame < frames.size() && newFrame >= 0) currentFrame = newFrame;
}

void FlipBook::NextFrame()
{
	if (currentFrame < frames.size() - 1) currentFrame = 0;
	else currentFrame++;
}

void FlipBook::ResizeFlipBook(int newSize)
{
	if (newSize > 0)
	{
		frames.resize(newSize, NULL);
		if (currentFrame >= frames.size()) currentFrame = frames.size() - 1;
	}	
}

void FlipBook::LoadFrame(std::string path, int frameIndex)
{
	if (frameIndex > 0 && frameIndex < frames.size())
	{
		TextureReader::ReadFile(path, frames.at(frameIndex));
	}
}

void FlipBook::SaveFrame(std::string path, int frameIndex)
{
	if (frameIndex > 0 && frameIndex < frames.size() && frames.at(frameIndex) != NULL)
	{
		TextureWriter::WriteFile(path, frames.at(frameIndex));
	}
}

void FlipBook::LoadFlipbook(std::string pathes[], int framesAmount)
{
	if (framesAmount > 0)
	{
		frames.resize(framesAmount, nullptr);
		for (int i = 0; i < framesAmount; i++)
		{
			LoadFrame(pathes[i], i);
		}
	}
}

void FlipBook::LoadFlipBook(std::string pathes[], int begin, int end)
{
	if (begin >= 0 && end > begin)
	{
		if (frames.size() - 1 < end) ResizeFlipBook(end + 1);
		for (int i = begin; i < end; i++)
		{
			LoadFrame(pathes[i], i);
		}
	}
}