#include "Theme.h"
// putting it here prevents the include loop
#include "Theme1.h"
#include "Theme2.h"
#include "Theme3.h"
#include "Theme4.h"
#include "Theme5.h"
namespace isgp{

	Theme* Theme::CreateTheme(int nr){
		return new Theme4();
		switch(nr) {
		case 1:
			return new Theme1();
			break;
		case 2:
			return new Theme2();
			break;
		case 3:
			return new Theme3();
			break;
		case 4:
			return new Theme4();
			break;
		case 5:
			return new Theme5();
			break;
		}
		return new Theme1();
	}

}