#pragma once

#include "precompiled.h"
#include "util.h"
#include "TextureCache.h"

struct GpuScope {
	GpuScope(string name) {
		glPushDebugGroup(GL_DEBUG_SOURCE_APPLICATION, 0, -1, name.c_str());
	}
	~GpuScope() {
		glPopDebugGroup();
	}
};

#define GPU_SCOPE(name) GpuScope gpuScope_ ## __LINE__  (name);

void beginRTT(gl::TextureRef fbotex);
void endRTT();

struct Str {
	string s;
	Str& operator<<(string s2) {
		s += s2 + "\n";
		return *this;
	}
	Str& operator<<(Str s2) {
		s += s2.s + "\n";
		return *this;
	}
	operator std::string() {
		return s;
	}
};

extern std::map<string, float> globaldict;
void globaldict_default(string s, float f);
template<class T>
struct optional {
	T val;
	bool exists;
	optional(T const& t) { val=t; exists=true; }
	optional() { exists=false; }
};
struct ShadeOpts
{
	ShadeOpts(){
		//_ifmt=GL_RGBA16F;
		_scaleX = _scaleY = 1.0f;
	}
	ShadeOpts& ifmt(GLenum val) { _ifmt=val; return *this; }
	ShadeOpts& scale(float val) { _scaleX=val; _scaleY=val; return *this; }
	ShadeOpts& scale(float valX, float valY) { _scaleX=valX; _scaleY=valY; return *this; }
	ShadeOpts& texCache(TextureCache* val) { _texCache = val; return *this; }
	ShadeOpts& scope(std::string name) { _scopeName = name; return *this; }
	optional<GLenum> _ifmt;
	float _scaleX, _scaleY;
	TextureCache* _texCache = nullptr;
	std::string _scopeName;
};

gl::TextureRef shade(vector<gl::TextureRef> const& texv, const char* fshader_constChar, ShadeOpts const& opts=ShadeOpts());
inline gl::TextureRef shade(vector<gl::TextureRef> const& texv, const char* fshader_constChar, float resScale)
{
	return shade(texv, fshader_constChar, ShadeOpts().scale(resScale));
}
