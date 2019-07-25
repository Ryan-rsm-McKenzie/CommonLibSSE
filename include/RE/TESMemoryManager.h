#pragma once

#include <new>  // operator new, operator delete
#include <type_traits>  // remove_extent_t, extent


namespace RE
{
	class BSSmallBlockAllocator;
	class IMemoryHeap;
	class MemoryHeap;
	class ScrapHeap;
	class ZeroOverheadHeap;


	class TESMemoryManager
	{
	public:
		struct Heaps
		{
			IMemoryHeap*	defaultHeap;	// 00
			IMemoryHeap*	staticHeap;		// 08
			IMemoryHeap*	fileHeap;		// 10
		};
		STATIC_ASSERT(sizeof(Heaps) == 0x18);


		static TESMemoryManager* GetSingleton();

		void*	Malloc(std::size_t a_size, std::size_t a_alignment, bool a_aligned);
		void	Free(void* a_ptr, bool a_aligned);


		// members
		UInt16					unk000;			// 000
		UInt16					unk002;			// 002
		UInt16					unk004;			// 004
		UInt16					unk006;			// 006
		Heaps*					heaps;			// 008
		UInt64					unk010;			// 010
		UInt64					unk018;			// 018
		ZeroOverheadHeap*		unk020;			// 020
		MemoryHeap*				defaultHeap;	// 028
		ZeroOverheadHeap*		unk030;			// 030
		UInt64					unk038;			// 038
		UInt64					unk040;			// 040
		UInt64					unk048;			// 048
		UInt64					unk050;			// 050
		MemoryHeap*				unk058;			// 058
		MemoryHeap*				unk060;			// 060
		UInt64					unk068;			// 068
		UInt64					unk070;			// 070
		MemoryHeap*				unk078;			// 078
		MemoryHeap*				unk080;			// 080
		UInt64					unk088;			// 088
		UInt64					unk090;			// 090
		UInt64					unk098;			// 098
		UInt64					unk0A0;			// 0A0
		UInt64					unk0A8;			// 0A8
		UInt64					unk0B0;			// 0B0
		UInt64					unk0B8;			// 0B8
		UInt64					unk0C0;			// 0C0
		UInt64					unk0C8;			// 0C8
		UInt64					unk0D0;			// 0D0
		UInt64					unk0D8;			// 0D8
		UInt64					unk0E0;			// 0E0
		UInt64					unk0E8;			// 0E8
		UInt64					unk0F0;			// 0F0
		UInt64					unk0F8;			// 0F8

		UInt64					unk100;			// 100
		UInt64					unk108;			// 108
		UInt64					unk110;			// 110
		UInt64					unk118;			// 118
		UInt64					unk120;			// 120
		UInt64					unk128;			// 128
		UInt64					unk130;			// 130
		UInt64					unk138;			// 138
		UInt64					unk140;			// 140
		UInt64					unk148;			// 148
		UInt64					unk150;			// 150
		UInt64					unk158;			// 158
		UInt64					unk160;			// 160
		UInt64					unk168;			// 168
		UInt64					unk170;			// 170
		UInt64					unk178;			// 178
		UInt64					unk180;			// 180
		UInt64					unk188;			// 188
		UInt64					unk190;			// 190
		UInt64					unk198;			// 198
		UInt64					unk1A0;			// 1A0
		UInt64					unk1A8;			// 1A8
		UInt64					unk1B0;			// 1B0
		UInt64					unk1B8;			// 1B8
		UInt64					unk1C0;			// 1C0
		UInt64					unk1C8;			// 1C8
		UInt64					unk1D0;			// 1D0
		UInt64					unk1D8;			// 1D8
		UInt64					unk1E0;			// 1E0
		MemoryHeap*				unk1E8;			// 1E8
		UInt64					unk1F0;			// 1F0
		UInt64					unk1F8;			// 1F8

		UInt64					unk200;			// 200
		UInt64					unk208;			// 208
		UInt64					unk210;			// 210
		UInt64					unk218;			// 218
		UInt64					unk220;			// 220
		UInt64					unk228;			// 228
		UInt64					unk230;			// 230
		UInt64					unk238;			// 238
		UInt64					unk240;			// 240
		UInt64					unk248;			// 248
		MemoryHeap*				unk250;			// 250
		MemoryHeap*				unk258;			// 258
		MemoryHeap*				unk260;			// 260
		UInt64					unk268;			// 268
		MemoryHeap*				unk270;			// 270
		MemoryHeap*				unk278;			// 278
		MemoryHeap*				unk280;			// 280
		UInt64					unk288;			// 288
		MemoryHeap*				unk290;			// 290
		UInt64					unk298;			// 298
		MemoryHeap*				unk2A0;			// 2A0
		MemoryHeap*				unk2A8;			// 2A8
		MemoryHeap*				unk2B0;			// 2B0
		MemoryHeap*				unk2B8;			// 2B8
		MemoryHeap*				unk2C0;			// 2C0
		MemoryHeap*				unk2C8;			// 2C8
		UInt64					unk2D0;			// 2D0
		UInt64					unk2D8;			// 2D8
		UInt64					unk2E0;			// 2E0
		UInt64					unk2E8;			// 2E8
		MemoryHeap*				unk2F0;			// 2F0
		UInt64					unk2F8;			// 2F8

		UInt64					unk300;			// 300
		UInt64					unk308;			// 308
		UInt64					unk310;			// 310
		UInt64					unk318;			// 318
		UInt64					unk320;			// 320
		MemoryHeap*				unk328;			// 328
		UInt64					unk330;			// 330
		MemoryHeap*				unk338;			// 338
		MemoryHeap*				unk340;			// 340
		ZeroOverheadHeap*		unk348;			// 348
		MemoryHeap*				unk350;			// 350
		UInt64					unk358;			// 358
		UInt64					unk360;			// 360
		MemoryHeap*				unk368;			// 368
		MemoryHeap*				unk370;			// 370
		MemoryHeap*				unk378;			// 378
		UInt64					unk380;			// 380
		UInt64					unk388;			// 388
		MemoryHeap*				unk390;			// 390
		UInt64					unk398;			// 398
		UInt64					unk3A0;			// 3A0
		UInt64					unk3A8;			// 3A8
		UInt64					unk3B0;			// 3B0
		UInt64					unk3B8;			// 3B8
		UInt64					unk3C0;			// 3C0
		UInt64					unk3C8;			// 3C8
		UInt64					unk3D0;			// 3D0
		UInt64					unk3D8;			// 3D8
		UInt64					unk3E0;			// 3E0
		UInt64					unk3E8;			// 3E8
		UInt64					unk3F0;			// 3F0
		UInt64					unk3F8;			// 3F8

		UInt64					unk400;			// 400
		UInt64					unk408;			// 408
		ScrapHeap*				unk410;			// 410
		UInt64					unk418;			// 418
		UInt64					unk420;			// 420
		UInt64					unk428;			// 428
		BSSmallBlockAllocator*	unk430;			// 430
		UInt64					unk438;			// 438
		IMemoryHeap*			havokHeap;		// 440
		UInt64					unk448;			// 448
		UInt64					unk450;			// 450
		UInt64					unk458;			// 458
		UInt64					unk460;			// 460
		UInt64					unk468;			// 468
		UInt64					unk470;			// 470
		UInt64					unk478;			// 478
		UInt64					unk480;			// 480
	};
	STATIC_ASSERT(sizeof(TESMemoryManager) == 0x488);


	inline void* malloc(std::size_t a_size)
	{
		auto heap = TESMemoryManager::GetSingleton();
		return heap->Malloc(a_size, 0, false);
	}


	template <class T>
	inline T* malloc(std::size_t a_size)
	{
		return static_cast<T*>(malloc(a_size));
	}


	template <class T>
	inline T* malloc()
	{
		return malloc<T>(sizeof(T));
	}


	inline void* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		auto heap = TESMemoryManager::GetSingleton();
		return heap->Malloc(a_size, a_alignment, true);
	}


	template <class T>
	inline T* aligned_alloc(std::size_t a_alignment, std::size_t a_size)
	{
		return static_cast<T*>(aligned_alloc(a_alignment, a_size));
	}


	template <class T>
	inline T* aligned_alloc()
	{
		return aligned_alloc<T>(alignof(T), sizeof(T));
	}


	inline void* calloc(std::size_t a_num, std::size_t a_size)
	{
		return malloc(a_num * a_size);
	}


	template <class T>
	inline T* calloc(std::size_t a_num, std::size_t a_size)
	{
		return static_cast<T*>(calloc(a_num, a_size));
	}


	template <class T>
	inline T* calloc(std::size_t a_num)
	{
		return calloc<T>(a_num, sizeof(T));
	}


	inline void free(void* a_ptr)
	{
		auto heap = TESMemoryManager::GetSingleton();
		heap->Free(a_ptr, false);
	}


	inline void aligned_free(void* a_ptr)
	{
		auto heap = TESMemoryManager::GetSingleton();
		heap->Free(a_ptr, true);
	}
}


#define TES_HEAP_REDEFINE_NEW()																												\
	inline void*	operator new(std::size_t a_count)													{ return RE::malloc(a_count); }		\
	inline void*	operator new[](std::size_t a_count)													{ return RE::malloc(a_count); }		\
	inline void*	operator new([[maybe_unused]] std::size_t a_count, void* a_plcmnt)					{ return a_plcmnt; }				\
	inline void*	operator new[]([[maybe_unused]] std::size_t a_count, void* a_plcmnt)				{ return a_plcmnt; }				\
	inline void		operator delete(void* a_ptr)														{ if (a_ptr) { RE::free(a_ptr); } }	\
	inline void		operator delete[](void* a_ptr)														{ if (a_ptr) { RE::free(a_ptr); } }	\
	inline void		operator delete([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt)		{ return; }							\
	inline void		operator delete[]([[maybe_unused]] void* a_ptr, [[maybe_unused]] void* a_plcmnt)	{ return; }
