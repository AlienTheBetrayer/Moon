// Renderer.hpp
//
// A helper class that can help manage UI elements and their rendering

#pragma once

#include <vector>

#include "../../../Macros.hpp"
#include "../RectangleVirtualBase.hpp"

namespace Moon {
	namespace Console {
		class Renderer
		{
		public:
			Renderer(void) noexcept = default;
			~Renderer(void) noexcept = default;

			void Reserve(const std::size_t n) noexcept;

			void PushSingle(RectangleVirtualBase* base) noexcept;
#ifdef CPP17GRT
			template<typename... Ts>
			void Push(Ts*... bases) noexcept {
				Reserve(sizeof...(Ts));
				(PushSingle(bases), ...);
			}
#endif
			
			void PopSingle(void) noexcept;
			void Pop(const std::size_t n) noexcept;

			void RenderAll(void) const noexcept;
		private:
			std::vector<RectangleVirtualBase*> m_Rectangles;
		};
	}
}