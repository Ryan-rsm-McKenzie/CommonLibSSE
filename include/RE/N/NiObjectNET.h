#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiExtraData;
	class NiTimeController;

	class NiObjectNET : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiObjectNET;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiObjectNET;

		virtual ~NiObjectNET();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							   // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			   // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			   // 19
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	   // 1A
		virtual void		  SaveBinary(NiStream& a_stream) override;			   // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				   // 1C
		virtual void		  ProcessClone(NiCloningProcess& a_cloning) override;  // 1D
		virtual void		  PostLinkObject(NiStream& a_stream) override;		   // 1E

		bool			  AddExtraData(const BSFixedString& a_key, NiExtraData* a_extra);
		bool			  AddExtraData(NiExtraData* a_extra);
		void			  DeleteExtraData(std::uint16_t a_extraDataIndex);
		NiTimeController* GetControllers() const;
		NiTimeController* GetController(const NiRTTI* a_rtti) const;
		NiExtraData*	  GetExtraData(const BSFixedString& a_key) const;
		NiExtraData*	  GetExtraDataAt(std::uint16_t a_extraDataIndex) const;
		std::uint16_t	  GetExtraDataSize() const;
		bool			  InsertExtraData(NiExtraData* a_extra);
		void			  RemoveAllExtraData();
		bool			  RemoveExtraData(const BSFixedString& a_key);
		bool			  RemoveExtraDataAt(std::uint16_t a_extraDataIndex);
		bool			  SetExtraDataSize(std::uint16_t a_size);

		// members
		BSFixedString				name;			// 10
		NiPointer<NiTimeController> controllers;	// 18
		NiExtraData**				extra;			// 20
		std::uint16_t				extraDataSize;	// 28
		std::uint16_t				maxSize;		// 2A
		std::uint32_t				pad2C;			// 2C
	};
	static_assert(sizeof(NiObjectNET) == 0x30);
}
