#pragma once

namespace RE
{
	class GAcquireInterface
	{
	public:
		virtual ~GAcquireInterface() = default;  // 00

		virtual bool CanAcquire();        // 01
		virtual bool TryAcquire();        // 02
		virtual bool TryAcquireCommit();  // 03
		virtual bool TryAcquireCancel();  // 04
	};
	static_assert(sizeof(GAcquireInterface) == 0x8);
}
