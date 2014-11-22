/* this file was generated by the MCOP idl compiler - DO NOT EDIT */

#ifndef AMAROKARTS_H
#define AMAROKARTS_H

#include <arts/common.h>

// includes of other idl definitions
#include <arts/artsflow.h>

namespace Amarok {
class Synth_STEREO_XFADE;
class RawScope;

class Synth_STEREO_XFADE_base : virtual public Arts::SynthModule_base {
public:
	static unsigned long _IID; // interface ID

	static Synth_STEREO_XFADE_base *_create(const std::string& subClass = "Amarok::Synth_STEREO_XFADE");
	static Synth_STEREO_XFADE_base *_fromString(const std::string& objectref);
	static Synth_STEREO_XFADE_base *_fromReference(Arts::ObjectReference ref, bool needcopy);

	static Synth_STEREO_XFADE_base *_fromDynamicCast(const Arts::Object& object);
	inline Synth_STEREO_XFADE_base *_copy() {
		assert(_refCnt > 0);
		_refCnt++;
		return this;
	}

	virtual std::vector<std::string> _defaultPortsIn() const;
	virtual std::vector<std::string> _defaultPortsOut() const;

	void *_cast(unsigned long iid);

	virtual float percentage() = 0;
	virtual void percentage(float newValue) = 0;
};

class Synth_STEREO_XFADE_stub : virtual public Synth_STEREO_XFADE_base, virtual public Arts::SynthModule_stub {
protected:
	Synth_STEREO_XFADE_stub();

public:
	Synth_STEREO_XFADE_stub(Arts::Connection *connection, long objectID);

	float percentage();
	void percentage(float newValue);
};

class Synth_STEREO_XFADE_skel : virtual public Synth_STEREO_XFADE_base, virtual public Arts::SynthModule_skel {
protected:
	// variables for streams
	float *invalue1_l;                        // incoming stream
	float *invalue1_r;                        // incoming stream
	float *invalue2_l;                        // incoming stream
	float *invalue2_r;                        // incoming stream
	float *outvalue_l;                        // outgoing stream
	float *outvalue_r;                        // outgoing stream

protected:
	// emitters for change notifications
	inline void percentage_changed(float newValue) {
		_emit_changed("percentage_changed",newValue);
	}

public:
	Synth_STEREO_XFADE_skel();

	static std::string _interfaceNameSkel();
	std::string _interfaceName();
	bool _isCompatibleWith(const std::string& interfacename);
	void _buildMethodTable();
	void dispatch(Arts::Buffer *request, Arts::Buffer *result,long methodID);
};

}
#include <arts/reference.h>
namespace Amarok {
class Synth_STEREO_XFADE : public Arts::Object {
private:
	static Arts::Object_base* _Creator();
	Synth_STEREO_XFADE_base *_cache;
	inline Synth_STEREO_XFADE_base *_method_call() {
		_pool->checkcreate();
		if(_pool->base) {
			_cache=(Synth_STEREO_XFADE_base *)_pool->base->_cast(Synth_STEREO_XFADE_base::_IID);
			assert(_cache);
		}
		return _cache;
	}

protected:
	inline Synth_STEREO_XFADE(Synth_STEREO_XFADE_base* b) : Arts::Object(b), _cache(0) {}


public:
	typedef Synth_STEREO_XFADE_base _base_class;

	inline Synth_STEREO_XFADE() : Arts::Object(_Creator), _cache(0) {}
	inline Synth_STEREO_XFADE(const Arts::SubClass& s) :
		Arts::Object(Synth_STEREO_XFADE_base::_create(s.string())), _cache(0) {}
	inline Synth_STEREO_XFADE(const Arts::Reference &r) :
		Arts::Object(r.isString()?(Synth_STEREO_XFADE_base::_fromString(r.string())):(Synth_STEREO_XFADE_base::_fromReference(r.reference(),true))), _cache(0) {}
	inline Synth_STEREO_XFADE(const Arts::DynamicCast& c) : Arts::Object(Synth_STEREO_XFADE_base::_fromDynamicCast(c.object())), _cache(0) {}
	inline Synth_STEREO_XFADE(const Synth_STEREO_XFADE& target) : Arts::Object(target._pool), _cache(target._cache) {}
	inline Synth_STEREO_XFADE(Arts::Object::Pool& p) : Arts::Object(p), _cache(0) {}
	inline static Synth_STEREO_XFADE null() {return Synth_STEREO_XFADE((Synth_STEREO_XFADE_base*)0);}
	inline static Synth_STEREO_XFADE _from_base(Synth_STEREO_XFADE_base* b) {return Synth_STEREO_XFADE(b);}
	inline Synth_STEREO_XFADE& operator=(const Synth_STEREO_XFADE& target) {
		if (_pool == target._pool) return *this;
		_pool->Dec();
		_pool = target._pool;
		_cache = target._cache;
		_pool->Inc();
		return *this;
	}
	inline operator Arts::SynthModule() const { return Arts::SynthModule(*_pool); }
	inline Synth_STEREO_XFADE_base* _base() {return _cache?_cache:_method_call();}

	inline Arts::AutoSuspendState autoSuspend();
	inline void start();
	inline void stop();
	inline void streamInit();
	inline void streamStart();
	inline void streamEnd();
	inline float percentage();
	inline void percentage(float _newValue);
};

class RawScope_base : virtual public Arts::StereoEffect_base {
public:
	static unsigned long _IID; // interface ID

	static RawScope_base *_create(const std::string& subClass = "Amarok::RawScope");
	static RawScope_base *_fromString(const std::string& objectref);
	static RawScope_base *_fromReference(Arts::ObjectReference ref, bool needcopy);

	static RawScope_base *_fromDynamicCast(const Arts::Object& object);
	inline RawScope_base *_copy() {
		assert(_refCnt > 0);
		_refCnt++;
		return this;
	}

	virtual std::vector<std::string> _defaultPortsIn() const;
	virtual std::vector<std::string> _defaultPortsOut() const;

	void *_cast(unsigned long iid);

	virtual long buffer() = 0;
	virtual void buffer(long newValue) = 0;
	virtual std::vector<float> * scope() = 0;
};

class RawScope_stub : virtual public RawScope_base, virtual public Arts::StereoEffect_stub {
protected:
	RawScope_stub();

public:
	RawScope_stub(Arts::Connection *connection, long objectID);

	long buffer();
	void buffer(long newValue);
	std::vector<float> * scope();
};

class RawScope_skel : virtual public RawScope_base, virtual public Arts::StereoEffect_skel {
protected:
	// emitters for change notifications
	inline void buffer_changed(long newValue) {
		_emit_changed("buffer_changed",newValue);
	}

public:
	RawScope_skel();

	static std::string _interfaceNameSkel();
	std::string _interfaceName();
	bool _isCompatibleWith(const std::string& interfacename);
	void _buildMethodTable();
	void dispatch(Arts::Buffer *request, Arts::Buffer *result,long methodID);
};

}
#include <arts/reference.h>
namespace Amarok {
class RawScope : public Arts::Object {
private:
	static Arts::Object_base* _Creator();
	RawScope_base *_cache;
	inline RawScope_base *_method_call() {
		_pool->checkcreate();
		if(_pool->base) {
			_cache=(RawScope_base *)_pool->base->_cast(RawScope_base::_IID);
			assert(_cache);
		}
		return _cache;
	}

protected:
	inline RawScope(RawScope_base* b) : Arts::Object(b), _cache(0) {}


public:
	typedef RawScope_base _base_class;

	inline RawScope() : Arts::Object(_Creator), _cache(0) {}
	inline RawScope(const Arts::SubClass& s) :
		Arts::Object(RawScope_base::_create(s.string())), _cache(0) {}
	inline RawScope(const Arts::Reference &r) :
		Arts::Object(r.isString()?(RawScope_base::_fromString(r.string())):(RawScope_base::_fromReference(r.reference(),true))), _cache(0) {}
	inline RawScope(const Arts::DynamicCast& c) : Arts::Object(RawScope_base::_fromDynamicCast(c.object())), _cache(0) {}
	inline RawScope(const RawScope& target) : Arts::Object(target._pool), _cache(target._cache) {}
	inline RawScope(Arts::Object::Pool& p) : Arts::Object(p), _cache(0) {}
	inline static RawScope null() {return RawScope((RawScope_base*)0);}
	inline static RawScope _from_base(RawScope_base* b) {return RawScope(b);}
	inline RawScope& operator=(const RawScope& target) {
		if (_pool == target._pool) return *this;
		_pool->Dec();
		_pool = target._pool;
		_cache = target._cache;
		_pool->Inc();
		return *this;
	}
	inline operator Arts::StereoEffect() const { return Arts::StereoEffect(*_pool); }
	inline operator Arts::SynthModule() const { return Arts::SynthModule(*_pool); }
	inline RawScope_base* _base() {return _cache?_cache:_method_call();}

	inline Arts::AutoSuspendState autoSuspend();
	inline void start();
	inline void stop();
	inline void streamInit();
	inline void streamStart();
	inline void streamEnd();
	inline long buffer();
	inline void buffer(long _newValue);
	inline std::vector<float> * scope();
};

}
// Forward wrapper calls to _base classes:

inline Arts::AutoSuspendState Amarok::Synth_STEREO_XFADE::autoSuspend()
{
	return _cache?static_cast<Arts::SynthModule_base*>(_cache)->autoSuspend():static_cast<Arts::SynthModule_base*>(_method_call())->autoSuspend();
}

inline void Amarok::Synth_STEREO_XFADE::start()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->start():static_cast<Arts::SynthModule_base*>(_method_call())->start();
}

inline void Amarok::Synth_STEREO_XFADE::stop()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->stop():static_cast<Arts::SynthModule_base*>(_method_call())->stop();
}

inline void Amarok::Synth_STEREO_XFADE::streamInit()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->streamInit():static_cast<Arts::SynthModule_base*>(_method_call())->streamInit();
}

inline void Amarok::Synth_STEREO_XFADE::streamStart()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->streamStart():static_cast<Arts::SynthModule_base*>(_method_call())->streamStart();
}

inline void Amarok::Synth_STEREO_XFADE::streamEnd()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->streamEnd():static_cast<Arts::SynthModule_base*>(_method_call())->streamEnd();
}

inline float Amarok::Synth_STEREO_XFADE::percentage()
{
	return _cache?static_cast<Amarok::Synth_STEREO_XFADE_base*>(_cache)->percentage():static_cast<Amarok::Synth_STEREO_XFADE_base*>(_method_call())->percentage();
}

inline void Amarok::Synth_STEREO_XFADE::percentage(float _newValue)
{
	 _cache?static_cast<Amarok::Synth_STEREO_XFADE_base*>(_cache)->percentage(_newValue):static_cast<Amarok::Synth_STEREO_XFADE_base*>(_method_call())->percentage(_newValue);
}

inline Arts::AutoSuspendState Amarok::RawScope::autoSuspend()
{
	return _cache?static_cast<Arts::SynthModule_base*>(_cache)->autoSuspend():static_cast<Arts::SynthModule_base*>(_method_call())->autoSuspend();
}

inline void Amarok::RawScope::start()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->start():static_cast<Arts::SynthModule_base*>(_method_call())->start();
}

inline void Amarok::RawScope::stop()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->stop():static_cast<Arts::SynthModule_base*>(_method_call())->stop();
}

inline void Amarok::RawScope::streamInit()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->streamInit():static_cast<Arts::SynthModule_base*>(_method_call())->streamInit();
}

inline void Amarok::RawScope::streamStart()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->streamStart():static_cast<Arts::SynthModule_base*>(_method_call())->streamStart();
}

inline void Amarok::RawScope::streamEnd()
{
	 _cache?static_cast<Arts::SynthModule_base*>(_cache)->streamEnd():static_cast<Arts::SynthModule_base*>(_method_call())->streamEnd();
}

inline long Amarok::RawScope::buffer()
{
	return _cache?static_cast<Amarok::RawScope_base*>(_cache)->buffer():static_cast<Amarok::RawScope_base*>(_method_call())->buffer();
}

inline void Amarok::RawScope::buffer(long _newValue)
{
	 _cache?static_cast<Amarok::RawScope_base*>(_cache)->buffer(_newValue):static_cast<Amarok::RawScope_base*>(_method_call())->buffer(_newValue);
}

inline std::vector<float> * Amarok::RawScope::scope()
{
	return _cache?static_cast<Amarok::RawScope_base*>(_cache)->scope():static_cast<Amarok::RawScope_base*>(_method_call())->scope();
}

#endif /* AMAROKARTS_H */