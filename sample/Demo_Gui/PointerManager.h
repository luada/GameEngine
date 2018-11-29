#ifndef __DX_POINTER_MANAGER_H__
#define __DX_POINTER_MANAGER_H__

namespace input
{

	class PointerManager
	{
	public:
		PointerManager();
		virtual ~PointerManager();

		void CreatePointerManager(size_t handle);
		void DestroyPointerManager();

		void SetPointerVisible(bool value);
		void SetPointerName(const std::string& name);

	};

} // namespace input

#endif // __DX_POINTER_MANAGER_H__
