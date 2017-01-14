#ifndef MAINFUNC_IMPL_H
#define MAINFUNC_IMPL_H

namespace cinder {
	namespace app {
		class AppBasic;
	}
}

// usage:
// int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR,int) {
// 		mainFuncImpl(new SApp());
// }
void mainFuncImpl(cinder::app::AppBasic* app);

#endif