#ifndef GIFBASE_H
#define GIFBASE_H
#include "cocos2d.h"
#include "Bitmap.h"

class GifBase : public cocos2d::Sprite
{
public:
	virtual void updateGif(uint32_t delta) = 0;
	virtual cocos2d::Texture2D* createTexture(Bitmap* bm, int index, bool getCache);

	virtual void update(float delta)
	{
        //if delta>1, generally speaking  the reason is the device is stuck
        if(delta > 1)
        {
            return;
        }
		uint32_t ldelta = (uint32_t)(delta * 1000);
		updateGif(ldelta);
	};
    
	virtual std::string getGifFrameName(int index)
	{
		return m_gif_fullpath;
	};
	
	bool fileEndWithGif( const char* filename )
	{
		//int nLen = strlen(filename);
		//if (nLen < 4) return false;
		//if (filename[nLen - 4] != '.') return false;
		//if (filename[nLen - 3] != 'g' && filename[nLen - 3] != 'G') return false;
		//if (filename[nLen - 2] != 'i' && filename[nLen - 3] != 'I') return false;
		//if (filename[nLen - 1] != 'f' && filename[nLen - 3] != 'F') return false;
		return true;
	}
protected:
	std::string m_gif_fullpath;;
};
#endif//GIFBASE_H

