/* this file was generated by the MCOP idl compiler - DO NOT EDIT */

#include "amarokarts.h"
//#include "artsflow.h"
//#include "common.h"

// Implementation
Amarok::Synth_STEREO_XFADE_base *Amarok::Synth_STEREO_XFADE_base::_create(const std::string& subClass)
{
	Arts::Object_skel *skel = Arts::ObjectManager::the()->create(subClass);
	assert(skel);
	Amarok::Synth_STEREO_XFADE_base *castedObject = (Amarok::Synth_STEREO_XFADE_base *)skel->_cast(Amarok::Synth_STEREO_XFADE_base::_IID);
	assert(castedObject);
	return castedObject;
}

Amarok::Synth_STEREO_XFADE_base *Amarok::Synth_STEREO_XFADE_base::_fromString(const std::string& objectref)
{
	Arts::ObjectReference r;

	if(Arts::Dispatcher::the()->stringToObjectReference(r,objectref))
		return Amarok::Synth_STEREO_XFADE_base::_fromReference(r,true);
	return 0;
}

Amarok::Synth_STEREO_XFADE_base *Amarok::Synth_STEREO_XFADE_base::_fromDynamicCast(const Arts::Object& object)
{
	if(object.isNull()) return 0;

	Amarok::Synth_STEREO_XFADE_base *castedObject = (Amarok::Synth_STEREO_XFADE_base *)object._base()->_cast(Amarok::Synth_STEREO_XFADE_base::_IID);
	if(castedObject) return castedObject->_copy();

	return _fromString(object._toString());
}

Amarok::Synth_STEREO_XFADE_base *Amarok::Synth_STEREO_XFADE_base::_fromReference(Arts::ObjectReference r, bool needcopy)
{
	Amarok::Synth_STEREO_XFADE_base *result;
	result = (Amarok::Synth_STEREO_XFADE_base *)Arts::Dispatcher::the()->connectObjectLocal(r,"Amarok::Synth_STEREO_XFADE");
	if(result)
	{
		if(!needcopy)
			result->_cancelCopyRemote();
	}
	else
	{
		Arts::Connection *conn = Arts::Dispatcher::the()->connectObjectRemote(r);
		if(conn)
		{
			result = new Amarok::Synth_STEREO_XFADE_stub(conn,r.objectID);
			if(needcopy) result->_copyRemote();
			result->_useRemote();
			if (!result->_isCompatibleWith("Amarok::Synth_STEREO_XFADE")) {
				result->_release();
				return 0;
			}
		}
	}
	return result;
}

std::vector<std::string> Amarok::Synth_STEREO_XFADE_base::_defaultPortsIn() const {
	std::vector<std::string> ret;
	return ret;
}
std::vector<std::string> Amarok::Synth_STEREO_XFADE_base::_defaultPortsOut() const {
	std::vector<std::string> ret;
	return ret;
}

void *Amarok::Synth_STEREO_XFADE_base::_cast(unsigned long iid)
{
	if(iid == Amarok::Synth_STEREO_XFADE_base::_IID) return (Amarok::Synth_STEREO_XFADE_base *)this;
	if(iid == Arts::SynthModule_base::_IID) return (Arts::SynthModule_base *)this;
	if(iid == Arts::Object_base::_IID) return (Arts::Object_base *)this;
	return 0;
}

Amarok::Synth_STEREO_XFADE_stub::Synth_STEREO_XFADE_stub()
{
	// constructor for subclasses (don't use directly)
}

Amarok::Synth_STEREO_XFADE_stub::Synth_STEREO_XFADE_stub(Arts::Connection *connection, long objectID)
	: Arts::Object_stub(connection, objectID)
{
	// constructor to create a stub for an object
}

float Amarok::Synth_STEREO_XFADE_stub::percentage()
{
	long methodID = _lookupMethodFast("method:000000105f6765745f70657263656e746167650000000006666c6f617400000000020000000000000000");
	long requestID;
	Arts::Buffer *request, *result;
	request = Arts::Dispatcher::the()->createRequest(requestID,_objectID,methodID);
	request->patchLength();
	_connection->qSendBuffer(request);

	result = Arts::Dispatcher::the()->waitForResult(requestID,_connection);
	if(!result) return 0.0; // error occurred
	float returnCode = result->readFloat();
	delete result;
	return returnCode;
}

void Amarok::Synth_STEREO_XFADE_stub::percentage(float newValue)
{
	long methodID = _lookupMethodFast("method:000000105f7365745f70657263656e746167650000000005766f696400000000020000000100000006666c6f617400000000096e657756616c7565000000000000000000");
	long requestID;
	Arts::Buffer *request, *result;
	request = Arts::Dispatcher::the()->createRequest(requestID,_objectID,methodID);
	request->writeFloat(newValue);
	request->patchLength();
	_connection->qSendBuffer(request);

	result = Arts::Dispatcher::the()->waitForResult(requestID,_connection);
	if(result) delete result;
}

std::string Amarok::Synth_STEREO_XFADE_skel::_interfaceName()
{
	return "Amarok::Synth_STEREO_XFADE";
}

bool Amarok::Synth_STEREO_XFADE_skel::_isCompatibleWith(const std::string& interfacename)
{
	if (interfacename == "Amarok::Synth_STEREO_XFADE") return true;
	if (interfacename == "Arts::SynthModule") return true;
	if (interfacename == "Arts::Object") return true;
	return false;
}

std::string Amarok::Synth_STEREO_XFADE_skel::_interfaceNameSkel()
{
	return "Amarok::Synth_STEREO_XFADE";
}

// _get_percentage
static void _dispatch_Amarok_Synth_STEREO_XFADE_00(void *object, Arts::Buffer *, Arts::Buffer *result)
{
	result->writeFloat(((Amarok::Synth_STEREO_XFADE_skel *)object)->percentage());
}

// _set_percentage
static void _dispatch_Amarok_Synth_STEREO_XFADE_01(void *object, Arts::Buffer *request, Arts::Buffer *)
{
	float newValue = request->readFloat();
	((Amarok::Synth_STEREO_XFADE_skel *)object)->percentage(newValue);
}

void Amarok::Synth_STEREO_XFADE_skel::_buildMethodTable()
{
	Arts::Buffer m;
	m.fromString(
        "MethodTable:000000105f6765745f70657263656e746167650000000006666c6f"
        "617400000000020000000000000000000000105f7365745f70657263656e746167"
        "650000000005766f696400000000020000000100000006666c6f61740000000009"
        "6e657756616c7565000000000000000000",
		"MethodTable"
	);
	_addMethod(_dispatch_Amarok_Synth_STEREO_XFADE_00,this,Arts::MethodDef(m));
	_addMethod(_dispatch_Amarok_Synth_STEREO_XFADE_01,this,Arts::MethodDef(m));
	Arts::SynthModule_skel::_buildMethodTable();
}

Amarok::Synth_STEREO_XFADE_skel::Synth_STEREO_XFADE_skel()
{
	_initStream("invalue1_l",&invalue1_l,9);
	_initStream("invalue1_r",&invalue1_r,9);
	_initStream("invalue2_l",&invalue2_l,9);
	_initStream("invalue2_r",&invalue2_r,9);
	_initStream("outvalue_l",&outvalue_l,10);
	_initStream("outvalue_r",&outvalue_r,10);
}

Arts::Object_base* Amarok::Synth_STEREO_XFADE::_Creator() {
	return Amarok::Synth_STEREO_XFADE_base::_create();
}

unsigned long Amarok::Synth_STEREO_XFADE_base::_IID = Arts::MCOPUtils::makeIID("Amarok::Synth_STEREO_XFADE");

Amarok::RawScope_base *Amarok::RawScope_base::_create(const std::string& subClass)
{
	Arts::Object_skel *skel = Arts::ObjectManager::the()->create(subClass);
	assert(skel);
	Amarok::RawScope_base *castedObject = (Amarok::RawScope_base *)skel->_cast(Amarok::RawScope_base::_IID);
	assert(castedObject);
	return castedObject;
}

Amarok::RawScope_base *Amarok::RawScope_base::_fromString(const std::string& objectref)
{
	Arts::ObjectReference r;

	if(Arts::Dispatcher::the()->stringToObjectReference(r,objectref))
		return Amarok::RawScope_base::_fromReference(r,true);
	return 0;
}

Amarok::RawScope_base *Amarok::RawScope_base::_fromDynamicCast(const Arts::Object& object)
{
	if(object.isNull()) return 0;

	Amarok::RawScope_base *castedObject = (Amarok::RawScope_base *)object._base()->_cast(Amarok::RawScope_base::_IID);
	if(castedObject) return castedObject->_copy();

	return _fromString(object._toString());
}

Amarok::RawScope_base *Amarok::RawScope_base::_fromReference(Arts::ObjectReference r, bool needcopy)
{
	Amarok::RawScope_base *result;
	result = (Amarok::RawScope_base *)Arts::Dispatcher::the()->connectObjectLocal(r,"Amarok::RawScope");
	if(result)
	{
		if(!needcopy)
			result->_cancelCopyRemote();
	}
	else
	{
		Arts::Connection *conn = Arts::Dispatcher::the()->connectObjectRemote(r);
		if(conn)
		{
			result = new Amarok::RawScope_stub(conn,r.objectID);
			if(needcopy) result->_copyRemote();
			result->_useRemote();
			if (!result->_isCompatibleWith("Amarok::RawScope")) {
				result->_release();
				return 0;
			}
		}
	}
	return result;
}

std::vector<std::string> Amarok::RawScope_base::_defaultPortsIn() const {
	std::vector<std::string> ret;
	ret.push_back("inleft");
	ret.push_back("inright");
	return ret;
}
std::vector<std::string> Amarok::RawScope_base::_defaultPortsOut() const {
	std::vector<std::string> ret;
	ret.push_back("outleft");
	ret.push_back("outright");
	return ret;
}

void *Amarok::RawScope_base::_cast(unsigned long iid)
{
	if(iid == Amarok::RawScope_base::_IID) return (Amarok::RawScope_base *)this;
	if(iid == Arts::StereoEffect_base::_IID) return (Arts::StereoEffect_base *)this;
	if(iid == Arts::SynthModule_base::_IID) return (Arts::SynthModule_base *)this;
	if(iid == Arts::Object_base::_IID) return (Arts::Object_base *)this;
	return 0;
}

Amarok::RawScope_stub::RawScope_stub()
{
	// constructor for subclasses (don't use directly)
}

Amarok::RawScope_stub::RawScope_stub(Arts::Connection *connection, long objectID)
	: Arts::Object_stub(connection, objectID)
{
	// constructor to create a stub for an object
}

std::vector<float> * Amarok::RawScope_stub::scope()
{
	long methodID = _lookupMethodFast("method:0000000673636f706500000000072a666c6f617400000000020000000000000000");
	long requestID;
	Arts::Buffer *request, *result;
	request = Arts::Dispatcher::the()->createRequest(requestID,_objectID,methodID);
	request->patchLength();
	_connection->qSendBuffer(request);

	result = Arts::Dispatcher::the()->waitForResult(requestID,_connection);
	std::vector<float> *_returnCode = new std::vector<float>;
	if(!result) return _returnCode; // error occurred
	result->readFloatSeq(*_returnCode);
	delete result;
	return _returnCode;
}

long Amarok::RawScope_stub::buffer()
{
	long methodID = _lookupMethodFast("method:0000000c5f6765745f62756666657200000000056c6f6e6700000000020000000000000000");
	long requestID;
	Arts::Buffer *request, *result;
	request = Arts::Dispatcher::the()->createRequest(requestID,_objectID,methodID);
	request->patchLength();
	_connection->qSendBuffer(request);

	result = Arts::Dispatcher::the()->waitForResult(requestID,_connection);
	if(!result) return 0; // error occurred
	long returnCode = result->readLong();
	delete result;
	return returnCode;
}

void Amarok::RawScope_stub::buffer(long newValue)
{
	long methodID = _lookupMethodFast("method:0000000c5f7365745f6275666665720000000005766f6964000000000200000001000000056c6f6e6700000000096e657756616c7565000000000000000000");
	long requestID;
	Arts::Buffer *request, *result;
	request = Arts::Dispatcher::the()->createRequest(requestID,_objectID,methodID);
	request->writeLong(newValue);
	request->patchLength();
	_connection->qSendBuffer(request);

	result = Arts::Dispatcher::the()->waitForResult(requestID,_connection);
	if(result) delete result;
}

std::string Amarok::RawScope_skel::_interfaceName()
{
	return "Amarok::RawScope";
}

bool Amarok::RawScope_skel::_isCompatibleWith(const std::string& interfacename)
{
	if (interfacename == "Amarok::RawScope") return true;
	if (interfacename == "Arts::StereoEffect") return true;
	if (interfacename == "Arts::SynthModule") return true;
	if (interfacename == "Arts::Object") return true;
	return false;
}

std::string Amarok::RawScope_skel::_interfaceNameSkel()
{
	return "Amarok::RawScope";
}

// scope
static void _dispatch_Amarok_RawScope_00(void *object, Arts::Buffer *, Arts::Buffer *result)
{
	std::vector<float> *_returnCode = ((Amarok::RawScope_skel *)object)->scope();
	result->writeFloatSeq(*_returnCode);
	delete _returnCode;
}

// _get_buffer
static void _dispatch_Amarok_RawScope_01(void *object, Arts::Buffer *, Arts::Buffer *result)
{
	result->writeLong(((Amarok::RawScope_skel *)object)->buffer());
}

// _set_buffer
static void _dispatch_Amarok_RawScope_02(void *object, Arts::Buffer *request, Arts::Buffer *)
{
	long newValue = request->readLong();
	((Amarok::RawScope_skel *)object)->buffer(newValue);
}

void Amarok::RawScope_skel::_buildMethodTable()
{
	Arts::Buffer m;
	m.fromString(
        "MethodTable:0000000673636f706500000000072a666c6f617400000000020000"
        "0000000000000000000c5f6765745f62756666657200000000056c6f6e67000000"
        "000200000000000000000000000c5f7365745f6275666665720000000005766f69"
        "64000000000200000001000000056c6f6e6700000000096e657756616c75650000"
        "00000000000000",
		"MethodTable"
	);
	_addMethod(_dispatch_Amarok_RawScope_00,this,Arts::MethodDef(m));
	_addMethod(_dispatch_Amarok_RawScope_01,this,Arts::MethodDef(m));
	_addMethod(_dispatch_Amarok_RawScope_02,this,Arts::MethodDef(m));
	Arts::StereoEffect_skel::_buildMethodTable();
}

Amarok::RawScope_skel::RawScope_skel()
{
}

Arts::Object_base* Amarok::RawScope::_Creator() {
	return Amarok::RawScope_base::_create();
}

unsigned long Amarok::RawScope_base::_IID = Arts::MCOPUtils::makeIID("Amarok::RawScope");

static Arts::IDLFileReg IDLFileReg_amarokarts("amarokarts",
    "IDLFile:00000001000000000000000000000000020000001b416d61726f6b3a3a5379"
    "6e74685f53544552454f5f5846414445000000000100000012417274733a3a53796e74"
    "684d6f64756c650000000000000000070000000b70657263656e746167650000000006"
    "666c6f61740000000013000000000000000b696e76616c7565315f6c0000000006666c"
    "6f61740000000009000000000000000b696e76616c7565315f720000000006666c6f61"
    "740000000009000000000000000b696e76616c7565325f6c0000000006666c6f617400"
    "00000009000000000000000b696e76616c7565325f720000000006666c6f6174000000"
    "0009000000000000000b6f757476616c75655f6c0000000006666c6f6174000000000a"
    "000000000000000b6f757476616c75655f720000000006666c6f6174000000000a0000"
    "0000000000000000000000000011416d61726f6b3a3a52617753636f70650000000001"
    "00000013417274733a3a53746572656f45666665637400000000010000000673636f70"
    "6500000000072a666c6f61740000000002000000000000000000000001000000076275"
    "6666657200000000056c6f6e67000000001300000000000000000000000000000000"
);
