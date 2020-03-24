#pragma once

#include "RE/BSAtomic.h"
#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"
#include "RE/ExtraFlags.h"
#include "RE/FormTypes.h"
#include "RE/MemoryManager.h"
#include "RE/SoulLevels.h"


namespace RE
{
	class InventoryChanges;
	class TESBoundObject;


	class ExtraDataList
	{
	public:
		template <class T>
		class iterator_base
		{
		public:
			using difference_type = std::ptrdiff_t;
			using value_type = T;
			using pointer = T*;
			using reference = T&;
			using iterator_category = std::forward_iterator_tag;


			iterator_base() :
				_cur(0)
			{}


			iterator_base(T* a_node) :
				_cur(a_node)
			{}


			iterator_base(const iterator_base& a_rhs) :
				_cur(a_rhs._cur)
			{}


			iterator_base(iterator_base&& a_rhs) :
				_cur(std::move(a_rhs._cur))
			{
				a_rhs._cur = 0;
			}


			~iterator_base() = default;


			iterator_base& operator=(const iterator_base& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				_cur = a_rhs._cur;

				return *this;
			}


			iterator_base& operator=(iterator_base&& a_rhs)
			{
				if (this == &a_rhs) {
					return *this;
				}

				_cur = std::move(a_rhs._cur);
				a_rhs._cur = 0;

				return *this;
			}


			[[nodiscard]] reference operator*() const
			{
				return *_cur;
			}


			[[nodiscard]] pointer operator->() const
			{
				return _cur;
			}


			[[nodiscard]] bool operator==(const iterator_base& a_rhs) const
			{
				return _cur == a_rhs._cur;
			}


			[[nodiscard]] bool operator!=(const iterator_base& a_rhs) const
			{
				return !operator==(a_rhs);
			}


			// prefix
			iterator_base& operator++()
			{
				assert(_cur);
				_cur = _cur->next;
				return *this;
			}


			// postfix
			iterator_base operator++(int)
			{
				iterator_base tmp(*this);
				operator++();
				return tmp;
			}

		protected:
			T* _cur;
		};


		using iterator = iterator_base<BSExtraData>;
		using const_iterator = iterator_base<const BSExtraData>;


		ExtraDataList();
		~ExtraDataList();

		TES_HEAP_REDEFINE_NEW();

		iterator	   begin();
		const_iterator cbegin() const;
		const_iterator begin() const;
		iterator	   end();
		const_iterator cend() const;
		const_iterator end() const;

		BSExtraData*	   GetByType(ExtraDataType a_type);
		const BSExtraData* GetByType(ExtraDataType a_type) const;
		template <class T>
		T* GetByType();
		template <class T>
		const T* GetByType() const;

		bool HasType(ExtraDataType a_type) const;
		template <class T>
		bool HasType() const;

		bool Remove(ExtraDataType a_type, BSExtraData* a_toRemove);
		template <class T>
		bool Remove(T* a_toRemove);

		bool RemoveByType(ExtraDataType a_type);

		BSExtraData*		  Add(BSExtraData* a_toAdd);
		ObjectRefHandle		  GetAshPileRefHandle();
		SInt32				  GetCount() const;
		const char*			  GetDisplayName(TESBoundObject* a_baseObject);
		BGSEncounterZone*	  GetEncounterZone();
		ExtraTextDisplayData* GetExtraTextDisplayData();
		TESObjectREFR*		  GetLinkedRef(BGSKeyword* a_keyword);
		TESForm*			  GetOwner();
		SOUL_LEVEL			  GetSoulLevel() const;
		void				  SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable);
		void				  SetInventoryChanges(InventoryChanges* a_changes);
		void				  SetOwner(TESForm* a_owner);

	protected:
		struct PresenceBitfield
		{
		public:
			bool HasType(UInt32 a_type) const;
			void MarkType(UInt32 a_type, bool a_cleared);


			// members
			UInt8 bits[0x18];  // 00
		};
		STATIC_ASSERT(sizeof(PresenceBitfield) == 0x18);


		void MarkType(UInt32 a_type, bool a_cleared);
		void MarkType(ExtraDataType a_type, bool a_cleared);


		// members
		BSExtraData*			_data;		// 00
		PresenceBitfield*		_presence;	// 08
		mutable BSReadWriteLock _lock;		// 10

	private:
		BSExtraData* GetByTypeImpl(ExtraDataType a_type) const;
	};
	STATIC_ASSERT(sizeof(ExtraDataList) == 0x18);


	template <class T>
	inline T* ExtraDataList::GetByType()
	{
		return static_cast<T*>(GetByType(T::EXTRADATATYPE));
	}


	template <class T>
	inline const T* ExtraDataList::GetByType() const
	{
		return static_cast<const T*>(GetByType(T::EXTRADATATYPE));
	}


	template <class T>
	inline bool ExtraDataList::HasType() const
	{
		return HasType(T::EXTRADATATYPE);
	}


	template <class T>
	inline bool ExtraDataList::Remove(T* a_toRemove)
	{
		return Remove(T::EXTRADATATYPE, a_toRemove);
	}
}
