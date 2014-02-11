/* 
 * File:   Size.h
 * Author: jappie
 *
 * Created on January 31, 2014, 7:26 PM
 */

#ifndef SIZE_H
#define	SIZE_H
namespace isgp {
	class Size {
	public:
		Size();
		Size(unsigned  width,unsigned  height);
		void SetHeight(unsigned  _height);
		unsigned  GetHeight() const;
		void SetWidth(unsigned  _width);
		unsigned  GetWidth() const;
	private:
		unsigned  _width;
		unsigned  _height;
	};
}
#endif	/* SIZE_H */

