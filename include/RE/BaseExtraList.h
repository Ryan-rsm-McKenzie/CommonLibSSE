#pragma once

#include "RE/BSExtraData.h"  // BSExtraData
#include "RE/BSLock.h"  // BSReadWriteLock
#include "RE/ExtraFlags.h"  // ExtraFlags::Flag
#include "RE/ExtraDataTypes.h"  // ExtraDataType
#include "RE/FormTypes.h"
#include "RE/TESMemoryManager.h"  // TES_HEAP_REDEFINE_NEW


namespace RE
{
	class InventoryChanges;


	class BaseExtraList
	{
	public:
		class const_iterator
		{
		public:
			typedef const_iterator		_iter;
			typedef const BSExtraData&	reference;
			typedef const BSExtraData*	pointer;


			const_iterator(const BSExtraData* a_extra);

			operator pointer() const;
			operator bool() const;
			reference	operator*() const;
			pointer		operator->() const;
			_iter&		operator++();
			_iter		operator++(int);
			bool		operator==(const _iter& a_rhs) const;
			bool		operator!=(const _iter& a_rhs) const;
			bool		empty() const;

		protected:
			BSExtraData* _cur;
		};


		class iterator : public const_iterator
		{
		public:
			typedef iterator		_iter;
			typedef BSExtraData&	reference;
			typedef BSExtraData*	pointer;


			iterator(BSExtraData* a_extra);

			operator pointer() const;
			pointer		operator*() const;
			pointer		operator->() const;
			_iter&		operator++();
			_iter		operator++(int);
		};


		BaseExtraList();
		~BaseExtraList();

		TES_HEAP_REDEFINE_NEW();

		iterator		begin();
		const_iterator	cbegin() const;
		const_iterator	begin() const;
		iterator		end();
		const_iterator	cend() const;
		const_iterator	end() const;


		bool		HasType(UInt32 a_type) const;
		bool		HasType(ExtraDataType a_type) const;
		template <class T>
		inline bool	HasType() const
		{
			return HasType(T::kExtraTypeID);
		}

		BSExtraData*	GetByType(UInt32 a_type) const;
		BSExtraData*	GetByType(ExtraDataType a_type) const;
		template <class T>
		inline T*		GetByType() const
		{
			return static_cast<T*>(GetByType(T::kExtraTypeID));
		}

		bool		Remove(UInt8 a_type, BSExtraData* a_toRemove);
		bool		Remove(ExtraDataType a_type, BSExtraData* a_toRemove);
		template <class T>
		inline bool	Remove(T* a_toRemove)
		{
			return Remove(T::kExtraTypeID, a_toRemove);
		}

		BSExtraData*			Add(BSExtraData* a_toAdd);
		const char*				GetDisplayName(TESForm* a_type);
		bool					GetAshPileRefHandle(RefHandle& a_refHandle);
		void					SetInventoryChanges(InventoryChanges* a_changes);
		void					SetExtraFlags(ExtraFlags::Flag a_flags, bool a_enable);
		TESObjectREFR*			GetLinkedRef(BGSKeyword* a_keyword);

	protected:
		struct PresenceBitfield
		{
			bool	HasType(UInt32 a_type) const;
			void	MarkType(UInt32 a_type, bool a_cleared);


			// members
			UInt8 bits[0x18];	// 00
		};
		STATIC_ASSERT(offsetof(PresenceBitfield, bits) == 0x00);
		STATIC_ASSERT(sizeof(PresenceBitfield) == 0x18);


		void	MarkType(UInt32 a_type, bool a_cleared);
		void	MarkType(ExtraDataType a_type, bool a_cleared);


		// members
		BSExtraData*			_data;		// 00
		PresenceBitfield*		_presence;	// 08
		mutable BSReadWriteLock	_lock;		// 10
	};
	STATIC_ASSERT(sizeof(BaseExtraList) == 0x18);
}
