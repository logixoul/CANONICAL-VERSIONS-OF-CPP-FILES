#define BOOST_RESULT_OF_USE_DECLTYPE 
#include <cmath>
#include <iostream>
#include <string>
#include <cinder/ip/Resize.h>
#include <complex>
// these two are from Windows.h
#undef min
#undef max
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <cinder/gl/GlslProg.h>
#include <cinder/gl/Texture.h>
#include <cinder/gl/Fbo.h>
#include <cinder/gl/gl.h>
#include <cinder/ImageIo.h>
#include <cinder/Vector.h>


#include <float.h>
#include <fftw3.h>

#include <tuple>
#include <opencv2/imgproc.hpp>
#include <thread>
#define foreach BOOST_FOREACH
using namespace ci;
using namespace std;
using namespace ci::app;
