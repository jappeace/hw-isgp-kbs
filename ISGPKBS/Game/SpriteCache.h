#pragma once
#include <map>
#include "Sprite.h"
using namespace std;
namespace isgp{
	// a wraper around the map class for easy acces, especialy targeted at strings and sprites
	template<typename keyType>
	class SpriteCache
	{
	public:
		SpriteCache(void){
			_spriteCache = new map<keyType, Sprite*>();
		}
		~SpriteCache(void){
			_spriteCache->clear();
			delete _spriteCache;
		}
		Sprite*& GetAt(keyType key) const{
			return (*_spriteCache)[key];
		}
		bool IsAt(keyType key) const{
			return _spriteCache->count(key) != 0;
		}
		void SetAt(keyType key, Sprite* sprite){
			(_spriteCache*)[key] = sprite;
		}
		Sprite*& operator[](keyType key){
			return GetAt(key);
		}
	private:
		map<keyType, Sprite*>* _spriteCache;
	};
}