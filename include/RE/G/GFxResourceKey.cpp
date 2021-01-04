#include "RE/G/GFxResourceKey.h"

namespace RE
{
	GFxResourceKey::KeyInterface::~KeyInterface()
	{}

	GFxResourceKey::GFxResourceKey() :
		_keyInterface(0),
		_keyData(0)
	{}

	GFxResourceKey::GFxResourceKey(KeyInterface* a_keyIntfc, KeyHandle a_keyHandle) :
		_keyInterface(a_keyIntfc),
		_keyData(a_keyHandle)
	{}

	GFxResourceKey::GFxResourceKey(const GFxResourceKey& a_rhs) :
		_keyInterface(a_rhs._keyInterface),
		_keyData(a_rhs._keyData)
	{}

	GFxResourceKey::~GFxResourceKey()
	{
		if (_keyInterface) {
			_keyInterface->Release(_keyData);
		}
	}

	GFxResourceKey& GFxResourceKey::operator=(const GFxResourceKey& a_rhs)
	{
		_keyInterface = a_rhs._keyInterface;
		_keyData = a_rhs._keyData;
		return *this;
	}

	bool GFxResourceKey::operator==(const GFxResourceKey& a_other) const
	{
		if (_keyInterface && a_other._keyInterface) {
			return _keyInterface->KeyEquals(_keyData, a_other);
		}
		return 0;
	}

	GFxResourceKey::KeyType GFxResourceKey::GetKeyType() const
	{
		return _keyInterface ? _keyInterface->GetKeyType(_keyData) : KeyType::kNone;
	}

	const char* GFxResourceKey::GetFileURL() const
	{
		return _keyInterface ? _keyInterface->GetFileURL(_keyData) : 0;
	}

	GFxResourceKey::KeyInterface* GFxResourceKey::GetKeyInterface() const
	{
		return _keyInterface;
	}

	GFxResourceKey::KeyHandle GFxResourceKey::GetKeyData() const
	{
		return _keyData;
	}
}
