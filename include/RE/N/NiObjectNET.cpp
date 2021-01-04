#include "RE/N/NiObjectNET.h"

#include "RE/N/NiExtraData.h"
#include "RE/N/NiRTTI.h"
#include "RE/N/NiSystem.h"
#include "RE/N/NiTCollection.h"
#include "RE/N/NiTimeController.h"

namespace RE
{
	bool NiObjectNET::AddExtraData(const BSFixedString& a_key, NiExtraData* a_extra)
	{
		if (!a_key.empty()) {
			return false;
		}

		if (!a_extra) {
			return false;
		}

		if (!a_extra->GetName().empty()) {
			a_extra->SetName(a_key);
		} else if (a_key != a_extra->GetName()) {
			return false;
		}

		return InsertExtraData(a_extra);
	}

	bool NiObjectNET::AddExtraData(NiExtraData* a_extra)
	{
		if (!a_extra) {
			return false;
		}

		if (a_extra->GetName().empty()) {
			auto rtti = a_extra->GetRTTI()->GetName();

			if (rtti && (std::strlen(rtti) > 0)) {
				assert(extraDataSize < 1000);
				char suffix[6];
				NiSprintf(suffix, 6, "ED%03d", extraDataSize);

				auto		  substr = std::strstr(rtti, "ExtraData");
				std::uint32_t strLength = 0;
				if (substr > rtti) {
					strLength = static_cast<std::uint32_t>(substr - rtti);
				}

				std::uint32_t len = strLength + static_cast<std::uint32_t>(std::strlen(suffix)) + 1;
				auto		  generatedKey = NiAlloc<char>(len);

				NiStrncpy(generatedKey, len, rtti, strLength);
				NiStrcat(generatedKey, len, suffix);

				a_extra->SetName(generatedKey);

				NiFree(generatedKey);
			} else {
				assert(false);
			}
		}

		return InsertExtraData(a_extra);
	}

	void NiObjectNET::DeleteExtraData(std::uint16_t a_extraDataIndex)
	{
		if (a_extraDataIndex >= extraDataSize) {
			return;
		}

		if (extra[a_extraDataIndex]) {
			extra[a_extraDataIndex]->DecRefCount();
		}

		for (std::uint16_t i = a_extraDataIndex; i < (extraDataSize - 1); ++i) {
			extra[i] = extra[i + 1];
		}

		extraDataSize--;
		extra[extraDataSize] = nullptr;
	}

	NiTimeController* NiObjectNET::GetControllers() const
	{
		return controllers.get();
	}

	NiTimeController* NiObjectNET::GetController(const NiRTTI* a_rtti) const
	{
		for (auto iter = GetControllers(); iter; iter = iter->GetNext()) {
			if (iter->GetRTTI()->IsKindOf(a_rtti)) {
				return iter;
			}
		}
		return nullptr;
	}

	NiExtraData* NiObjectNET::GetExtraData(const BSFixedString& a_key) const
	{
		if (a_key.empty()) {
			return nullptr;
		}

		assert(extraDataSize < std::numeric_limits<std::int16_t>::max());

		std::int16_t bottom = 0;
		std::int16_t top = static_cast<std::int16_t>(extraDataSize - 1);
		std::int16_t middle = 0;

		while (bottom <= top) {
			middle = (top + bottom) >> 1;

			std::ptrdiff_t compare = a_key.c_str() - extra[middle]->GetName().c_str();

			if (compare == 0) {
				return extra[middle];
			} else if (compare > 0) {
				bottom = middle + 1;
			} else {
				top = middle - 1;
			}
		}

		return nullptr;
	}

	NiExtraData* NiObjectNET::GetExtraDataAt(std::uint16_t a_extraDataIndex) const
	{
		assert(a_extraDataIndex < extraDataSize);
		return extra[a_extraDataIndex];
	}

	std::uint16_t NiObjectNET::GetExtraDataSize() const
	{
		return extraDataSize;
	}

	bool NiObjectNET::InsertExtraData(NiExtraData* a_extra)
	{
		if (!a_extra) {
			return false;
		}

		a_extra->IncRefCount();

		if (maxSize < 1) {
			extraDataSize = maxSize = 1;
			extra = NiAlloc<NiExtraData*>(maxSize);
			extra[0] = a_extra;
			return true;
		} else if (extraDataSize == maxSize) {
			maxSize = (maxSize * 2) + 1;
			auto newExtra = NiAlloc<NiExtraData*>(maxSize);

			std::uint32_t destSize = maxSize * sizeof(NiExtraData*);
			NiMemcpy(newExtra, destSize, extra, extraDataSize * sizeof(NiExtraData*));

			NiFree(extra);
			extra = newExtra;
		}

		std::uint16_t i = 0;

		extra[extraDataSize] = a_extra;
		++extraDataSize;

		for (i = extraDataSize; i < maxSize; ++i) {
			extra[i] = nullptr;
		}

		for (i = (extraDataSize - 1); i > 0; --i) {
			std::ptrdiff_t compare = extra[i - 1]->GetName().c_str() - extra[i]->GetName().c_str();

			if (compare == 0) {
				DeleteExtraData(i);
				return false;
			} else if (compare > 0) {
				auto tmp = extra[i - 1];
				extra[i - 1] = extra[i];
				extra[i] = tmp;
			} else {
				break;
			}
		}

		return true;
	}

	void NiObjectNET::RemoveAllExtraData()
	{
		for (std::int16_t i = (static_cast<std::int16_t>(extraDataSize) - 1); i >= 0; --i) {
			DeleteExtraData(static_cast<std::uint16_t>(i));
		}

		NiFree(extra);
		extra = nullptr;
		extraDataSize = 0;
		maxSize = 0;
	}

	bool NiObjectNET::RemoveExtraData(const BSFixedString& a_key)
	{
		if (extraDataSize == 0) {
			return false;
		}

		if (a_key.empty()) {
			return false;
		}

		assert(extraDataSize < std::numeric_limits<std::int16_t>::max());

		std::int16_t bottom = 0;
		std::int16_t top = static_cast<std::int16_t>(extraDataSize - 1);
		std::int16_t middle = 0;

		while (bottom <= top) {
			middle = (top + bottom) >> 1;

			std::ptrdiff_t compare = a_key.c_str() - extra[middle]->GetName().c_str();

			if (compare == 0) {
				DeleteExtraData(middle);
				return true;
			} else if (compare > 0) {
				bottom = middle + 1;
			} else {
				top = middle - 1;
			}
		}

		return false;
	}

	bool NiObjectNET::RemoveExtraDataAt(std::uint16_t a_extraDataIndex)
	{
		if (a_extraDataIndex < extraDataSize) {
			DeleteExtraData(a_extraDataIndex);
			return true;
		}

		return false;
	}

	bool NiObjectNET::SetExtraDataSize(std::uint16_t a_size)
	{
		if (a_size == 0) {
			return false;
		}

		assert(a_size < 1000);

		if (maxSize == 0) {
			maxSize = a_size;
			extra = NiAlloc<NiExtraData*>(maxSize);

			extraDataSize = 0;
		} else {
			maxSize = a_size;

			auto newExtra = NiAlloc<NiExtraData*>(maxSize);

			std::uint32_t destSize = maxSize * sizeof(NiExtraData*);
			NiMemcpy(newExtra, destSize, extra, extraDataSize * sizeof(NiExtraData*));

			NiFree(extra);
			extra = newExtra;
		}

		return true;
	}
}
